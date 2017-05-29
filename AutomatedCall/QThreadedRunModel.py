# -*- coding: utf-8 -*-
"""
Iron python code for command line interaction with TORNADO.net for operating WEST (MIKE DHI) water quality simulators.

The script includes the possibility of setting parameter values in an automated way and setting time of simulation

Run in cmd:  ipy RunModel.py 'L@River_2=1000' 'n=0.035' 'W_b=10' 'StartTime:0' 'StopTime:2'
To change the values of lenght, manning and width in a given WEST model.

A parameter followed by @<submodel> will address only the selected submodel, without acting on the rest of them.

Dependencies:
- Iron python installation. Setting environemnt variables for ipy.
- DHI.Tornado.NET.dll (supplied with WEST 2016, add reference to file path in the script for the Tornado location)
- WEST DHI license

Created on Thu May 26 15:24:28 2016 $author: Antonio Moreno, Delft
"""
import clr
import System
import sys
import csv
from datetime import datetime
import os
import random


#%% SET ENVIRONMENT
os.environ['INCLUDE'] = r"%INCLUDE%;C:\Program Files (x86)\DHI\2016\WEST\include"
os.environ['LIB'] = r"%LIB%;C:\Program Files (x86)\DHI\2016\WEST\lib\win32-msvc"
os.environ['PATH'] = r"C:\Program Files (x86)\DHI\2016\bin;C:\Program Files (x86)\DHI\2016\WEST\third_party\bcc5.5\Bin;%PATH%"
os.environ['TORNADO_CC_PATH'] = r"C:\Program Files (x86)\DHI\2016\WEST\third_party\bcc5.5"
os.environ['TORNADO_DATA_PATH'] = r"C:\Users\Public\Documents\DHI\WEST"
os.environ['TORNADO_ROOT_PATH'] = r"C:\Program Files (x86)\DHI\2016\WEST"
os.environ['OPENMODELICAHOME'] = r"C:\Program Files (x86)\DHI\2016\WEST\third_party\omc"

clr.AddReferenceToFileAndPath(r"C:\Program Files (x86)\DHI\2016\bin\DHI.Tornado.NET.dll")
import TornadoNET


##########


TornadoLocationArg = [i for i in sys.argv if 'Tornado_path:' in i][0]
ExperimentLocationArg = [i for i in sys.argv if 'Experiment_path:' in i][0]
TornadoLocation = TornadoLocationArg[TornadoLocationArg.index(':')+1:len(TornadoLocationArg)-1]
ExperimentLocation = ExperimentLocationArg[ExperimentLocationArg.index(':')+1:len(ExperimentLocationArg)-1] + '|.Tornado'

#TornadoLocation = "C:\Users\localadmin.TUD278183\Desktop\GitProjects\pyWEST\Model_dummy_1\Tornado.Main.xml"    #TornadoLocationArg[TornadoLocationArg.index(':')+1:len(TornadoLocationArg)-1]
#ExperimentLocation =  "C:\Users\localadmin.TUD278183\Desktop\GitProjects\pyWEST\Model_dummy_1\Model_dummy_1.Dynamic.ObjEval.Exp.xml"           #xperimentLocationArg[ExperimentLocationArg.index(':')+1:len(ExperimentLocationArg)-1] + '|.Tornado'

def SetMessage(Type, Message):
	if Type == 0:
		print "I |", Message
	elif Type == 1:
		print "W |", Message
	elif Type == 2:
		print "E |", Message
	else:
		print "? |", Message

def SetTime(Time): # Will print the progress 0.05% of the iterations (it shows, but not too much!) 
    if random.random()<0.005:
        print "Time =", round(Time,1)

 
#Change parameter Values
def ChangeGlobalParameter(ExpSS, Parameter, Value, show='FALSE', Reference=None):
    """    
    This function changes the value of the selected parameter in all submodels that are affected by it.
    Furthermore the Reference argument can be used to define a common string in the targeted submodel, this is used when several submodels share the same parameter but you want to change only 1.
    
    :Arguments:
    
        :ExpSS: [Tornado Element]. Simulation file
        :Parameter: [string]. Name of the parameter to change, e.g. 'L'
        :Value: [Float]. Parameter value
        :Reference: [string]. Helps further locating the desired parameters, in case the same parameter affects different submodels, but only 1 should change, by default is desactivated. 
        	If 'Multiplier' the value acts as a multiplier factor for the current parameter value.
        	If 'Manipulated' allows to change values of inputs which are not defined by timeseries. With a constant value.
        	If 'Manipulated_Reference' will change a manipulated value at the reference submodel.
        :show: [TRUE,FALSE]. If TRUE the changed parameters will appear in the command line. Desactivated by default.
        
    :Example:
    
        ChangeGlobalParameter(ExpSimulation, 'n', 0.004, Reference="River")
    """
    if Reference is None:
        SubModelNames = ExpSS.ModelEnumerateModels("")
        Parametros = ExpSS.ModelEnumerateParams("")
        if Parameter in Parametros:
            ExpSS.ModelSetInitialValue("." + Parameter, Value)
            print 'Setting Top-level Parameter ' + Parameter + " to = " + str(Value)
        else:
            for submodel in SubModelNames:
                Parametros = ExpSS.ModelEnumerateParams("." + submodel)
                if Parameter in Parametros:
                    ExpSS.ModelSetInitialValue("." + submodel + "." + Parameter, Value)
                    if show=='TRUE':
                        print "Setting " + "." + submodel + "." + Parameter + " to = " + str(Value)

    elif Reference == 'Multiplier':
        SubModelNames = ExpSS.ModelEnumerateModels("")
        Parametros = ExpSS.ModelEnumerateParams("")
        if Parameter in Parametros:
            LocalValue = ExpSS.ExpGetInitialValue("." + Parameter)
            ExpSS.ModelSetInitialValue("." + Parameter, LocalValue*Value)
            print 'Setting Top-level Parameter ' + Parameter + " to = " + str(LocalValue*Value) + ' multiplied by ' + str(Value)
        else:
            for submodel in SubModelNames:
                Parametros = ExpSS.ModelEnumerateParams("." + submodel)
                if Parameter in Parametros:
                    LocalValue = ExpSS.ExpGetInitialValue("." + submodel + "." + Parameter)
                    ExpSS.ModelSetInitialValue("." + submodel + "." + Parameter, LocalValue*Value)
                    if show=='TRUE':
                        print "Setting " + "." + submodel + "." + Parameter + " to = " + str(LocalValue*Value) + ' multiplied by ' + str(Value)

    elif 'Manipulated' in Reference:
        if '_' in Reference:
            SubmodelPlacer = Reference[Reference.index('_')+1:]
            SubModelNames = ExpSS.ModelEnumerateModels("")
            for submodel in SubModelNames:
                Inputs = ExpSS.ModelEnumerateInputVars("." + submodel)            
                if Parameter in Inputs and SubmodelPlacer in submodel:
                    ExpSS.ModelSetInitialValue("." + submodel + "." + Parameter, Value)
                    if show=='TRUE':
                        print "Setting " + "." + submodel + "." + Parameter + " to = " + str(Value)

        else:
            SubModelNames = ExpSS.ModelEnumerateModels("")
            for submodel in SubModelNames:
                Inputs = ExpSS.ModelEnumerateInputVars("." + submodel)
                if Parameter in Inputs:
                    ExpSS.ModelSetInitialValue("." + submodel + "." + Parameter, Value)
                    if show=='TRUE':
                        print "Setting " + "." + submodel + "." + Parameter + " to = " + str(Value) 

    else:
        SubModelNames = ExpSS.ModelEnumerateModels("")
        for submodel in SubModelNames:
            Parametros = ExpSS.ModelEnumerateParams("." + submodel)
            if Parameter in Parametros and Reference in submodel:
                ExpSS.ModelSetInitialValue("." + submodel + "." + Parameter, Value)
                if show=='TRUE':
                    print "Setting " + "." + submodel + "." + Parameter + " to = " + str(Value)
                
def GETParametersChanged(ExpSS, show='FALSE', Reference = None):
    """
    This function reads the arguments provided to the script and defines them as new parameter values:
    This functions uses ChangeGlobalParameter()
    If the argument supplied has Parameter@submodelkey: Value, key is used as a Reference for changing only the parameters at those blocks where the key is contained.
    If the argument supplied has Parameter@Multiplier: Value, the current value of the parameter is globally multiplied by a factor.
    :Example: 
        command line
        
        ipy RunModel.py 'L=1200' 'n=0.004' 'L@River_2=1200'
    
    """
    Parameters = {}
    lista = [i for i in sys.argv if '=' in i]
    
    for n in lista:
        
        Parameters[str(n[0:n.index('=')])]=n[n.index('=')+1:len(n)-1]
        
    for n in Parameters.keys():
        if '@' in n:
            ChangeGlobalParameter(ExpSS, n[1:n.index('@')], float(Parameters[n]), show, Reference=n[n.index('@')+1:])           
        else:
            ChangeGlobalParameter(ExpSS, n[1:], float(Parameters[n]), show, Reference=None)    


def CopyStatefromfile(ExpSS, filename):
	with open(filename) as f:
		reader = csv.reader(f, delimiter = "\t")
		d = list(reader)			
		for s in d:
			ExpSS.ExpSetInitialValue("." + s[0], float(s[1]))
			print "Setting " + "." + s[0] + " to " + s[1]

def DeformInitialVolume(ExpSS, ModelName, coeff):
    """
    This code gets the Initial Value of Volume and modifies it with a constant parameter coeff.
    This is a way of inforcing the initial state of the reality as a correlated parameter of the river geometry.
    """
    SubModelNames = ExpSS.ModelEnumerateModels(ModelName)
    for Model in SubModelNames:
        DerVarNames = ExpSS.ModelEnumerateDerVars('.' +Model)
        
        for Var in DerVarNames:
            if 'M(rH2O)' in Var:
                Value = ExpSS.ExpGetInitialValue('.' + Model + '.' + Var)
                ExpSS.ExpSetInitialValue('.' + Model + '.' + Var,Value*coeff)
                print '.' + Model + '.' + Var + ' = ' + str(Value) + ' to ' + str(Value*coeff)
                

    
def copyInternalParametersoutput(ExpSS, idnum = ""):
    '''
    This function saves all internal parameter values to a txt file located in the model folder and called InternalParameters.out.txt
    '''
    f = open(TornadoLocationArg[TornadoLocationArg.index(':')+1:len(TornadoLocationArg)-18] + '\InternalParameters.' + idnum + '.out.txt','w') #Create file if not present and open it
    print TornadoLocationArg[TornadoLocationArg.index(':')+1:len(TornadoLocationArg)-18] + '\InternalParameters.' + idnum + '.out.txt'
    # iterate on submodels and paramters and write its value
    SubModelNames = ExpSS.ModelEnumerateModels("")
    for submodel in SubModelNames:
        Parametros = ExpSS.ModelEnumerateParams("." + submodel)
        Inputs = ExpSS.ModelEnumerateInputVars("." + submodel)
        for Parameter in Parametros:
            Value = ExpSS.ExpGetValue("." + submodel + "." + Parameter)
            f.write('{0}.{1},{2} \n'.format(submodel, Parameter, Value))

        for Input in Inputs:
            Value = ExpSS.ExpGetValue("." + submodel + "." + Input)
            f.write('Input_{0}.{1},{2} \n'.format(submodel, Input, Value))

    f.close()

import threading
import Queue
import json

WEST_lock = threading.Lock()


ThreadingArg = [i for i in sys.argv if 'Threading:' in i]
num_worker_threads = int(ThreadingArg[0][ThreadingArg[0].index(':')+1:])

# LOAD Parameters database
ParamDatabase = [i for i in sys.argv if 'ParamDatabase:' in i]
ParamDatabase = json.loads(ParamDatabase[0][ParamDatabase[0].index(':')+1:])


try:

    Tornado = TornadoNET.CTornado()
    Tornado.Initialize(TornadoLocation, True)
    Tornado.EventSetMessage += SetMessage

    if ThreadingArg:  #RUN THREADED SIMULATION
        #%% Generate Queue for threads
        #ParameterDatabase = json.loads()

        def Threadedcall(par):
            global ParamDatabase
            try:
                with WEST_lock:
                    Exp = Tornado.ExpLoad(ExperimentLocation)
                
                #Exp.EventSetTime += SetTime

                ExpSimul = Exp.ExpGetSimul()

                # Define output names with code from the database
                for name in ExpSimul.OutputFileEnumerate():
                    ExpSimul.ExpSetInitialValue("#Output#File$#*This*#" + name + "$FileName", int(par)) #// Make sure that each run generates unique output file
                        
                print 'Simulation id {}'.format(par)
        
                # Change Selected static parameters
                GETParametersChanged(ExpSimul, show='False')

                # Change Parameters in the Database
                for n in ParamDatabase.keys():
                    if '@' in n:
                        ChangeGlobalParameter(ExpSimul, n[0:n.index('@')], float(ParamDatabase[n][par]), show= 'TRUE', Reference=n[n.index('@')+1:])           
                    else:
                        ChangeGlobalParameter(ExpSimul, n[0:], float(ParamDatabase[n][par]), show = 'TRUE', Reference=None) 



                Starting = [i for i in sys.argv if 'StartTime:' in i][0]
                Ending = [i for i in sys.argv if 'StopTime:' in i][0]

                ExpSimul.TimeSetProp("StartTime", Starting[Starting.index(':')+1:len(Starting)-1])
                ExpSimul.TimeSetProp("StopTime", Ending[Ending.index(':')+1:len(Ending)-1])

                #print Exp.ExpGetOutputs(0)

                Exp.Initialize()
                Exp.Run()

                copyInternalParametersoutput(ExpSimul, idnum = str(par))

                Exp.Dispose()

            except System.Exception as Ex:
                print Ex.ToString()

        def worker():
            while True:
                item = q.get()
                Threadedcall(item)
                q.task_done()


        q = Queue.Queue()
        for i in range(num_worker_threads):
             t = threading.Thread(target=worker)
             t.daemon = True
             t.start()

        #%% Iteration for parameter list
        for item in range(len(ParamDatabase[ParamDatabase.keys()[0]])):
            q.put(item)

        q.join()

    else:           #RUN SINGLE SIMULATION

        Exp = Tornado.ExpLoad(ExperimentLocation)
        Exp.EventSetTime += SetTime
        
        ExpSimul = Exp.ExpGetSimul()
        #Set Simulation time window
        Starting = [i for i in sys.argv if 'StartTime:' in i][0]
        Ending = [i for i in sys.argv if 'StopTime:' in i][0]

        ExpSimul.TimeSetProp("StartTime", Starting[Starting.index(':')+1:len(Starting)-1])
        ExpSimul.TimeSetProp("StopTime", Ending[Ending.index(':')+1:len(Ending)-1])

        #Change Selected Parameters
        GETParametersChanged(ExpSimul, show='TRUE')
        
        Exp.Initialize()
        Exp.Run()

        #Save Internal Parameter Values to file InternalParameters.out.txt
        copyInternalParametersoutput(ExpSimul)
        #Clean the model instance for refreshing the license
        Exp.Dispose()

    #Clean the model instance for refreshing the license
    
    Tornado.Dispose()

except System.Exception as Ex:
    print Ex.ToString()

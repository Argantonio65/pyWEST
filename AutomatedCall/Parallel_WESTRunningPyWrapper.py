# -*- coding: utf-8 -*-
"""
Python Wrapper to operate RunModel.py from iron python.
This scripts allows to instanciate parallel automated simulations from WEST (MIKE DHI).

The class ModelInstances() allows for generating n instances of separate model folders, which can be called from an iterative inference, calibration or montecarlo analysis. 
The script manages automatically the cue of available instances and accept new runs a command line simulation when an instance becomes available.
The number of instances is limited to the number of WEST licenses available (standard license allows for 4)

Dependencies:
- WEST 2016

Created on Thu Mar 07 12:50:20 2017 $author: Antonio Moreno, Delft
"""
import numpy as np
import threading
import os
import time
import shutil
import json
import csv
import subprocess

class ModelInstances:
    '''
    This is a class for model instance for WEST.
    It requires a particular folder organization:
     
    pathtoModelInstanceLocation
    $dir
                Model_1\n
                Model_2\n
                ...\n
                Model_n\n
                
    pathtoModelInstanceLocation/Model_i
    $dir
                AllWESTModelFiles \n
                Tornado.main.xml
        Note: Inside Tornado.main.xml you should change the value of:  <Prop Name="CalcVarPrefix" Value="Model_i"/> This is to avoid memory sharing issues.  
                
                
    :Arguments:
        
            InstanceNames: [List] List of model names ['Mod1', 'Mod2', ...]
            
            modelPath: [string] Example, r"C:/Users/localadmin/Desktop/QUICS/EWRA_PAPER/Dommel_IUWS"

    :Usage example:

        ModelInstance = ModelInstances(['Model_1', 'Model_2'], modelPath = "C:\Users\localadmin\Desktop\QUICS\WestModelInference")

        Timelist = {'StartTime':0,'StopTime':10} 
        Parameterlist = {'Niter':5 , 'n' : 0.6, 'slope@Multiplier' : 0.6, 'Q_initial':5}   
        
        ModelInstance.model_run(Parameterlist, Timelist)

    # Antonio Moreno, Zurich 24 jan 2017
    '''
    global ExecuteModel
    
    def ExecuteModel(ModelName, Parameterlist, Timelist, PathsArg, RunnerPath):
        """
        Generates the parameter and time arguments and runs the ironpython script for Parameterchange.
        Will generate an intermediate file RUNWEST.bat in the cwd used for the model setup.
        
        
        :Arguments:
        
            Parameterlist: [dictionary] {'L':1200, 'n':0.004, 'L@River_2':1100}
            
            Timelist: [dictionary] {'StartTime':0,'StopTime':5}

            RunnerPath: [string] path where the ipy RunModel.py is located
        """
        ParseParams = ""    
        ParseTime = ""
        ParsePathsArg = ""
        
        for n in Parameterlist.keys():
            new= ' ' +"'"+ n +'=' + str(Parameterlist[n])+"'"
            ParseParams+=new
        for n in Timelist.keys():
            new= ' '+"'" + n +':' + str(Timelist[n])+"'"
            ParseTime+=new
        for n in PathsArg.keys():
            new= ' '+"'" + n +':' + str(PathsArg[n])+"'"
            ParsePathsArg+=new
                  
        WESTCALL = 'ipy ' + RunnerPath + r'\AutomatedCall\RunModel.py' + ParseParams + ParseTime + ParsePathsArg   #NOTE: THE ipy module must be located in a folder called Inference on the same location as the model instance.
            
        # Change if other version of WEST is used (in this case 2016)
        WESTENVIRONMENT = [r'SET INCLUDE=%INCLUDE%;C:\Program Files (x86)\DHI\2016\WEST\include',
                            r'SET LIB=%LIB%;C:\Program Files (x86)\DHI\2016\WEST\lib\win32-msvc',
                            r'SET PATH=C:\Program Files (x86)\DHI\2016\bin;C:\Program Files (x86)\DHI\2016\WEST\third_party\bcc5.5\Bin;%PATH%',
                            r'SET TORNADO_CC_PLATFORM=win32-bcc5.5',
                            r'SET TORNADO_CC_PATH=C:\Program Files (x86)\DHI\2016\WEST\third_party\bcc5.5',
                            r'SET TORNADO_DATA_PATH=C:\Users\Public\Documents\DHI\WEST',
                            r'SET TORNADO_ROOT_PATH=C:\Program Files (x86)\DHI\2016\WEST',
                            r'SET OPENMODELICAHOME=C:\Program Files (x86)\DHI\2016\WEST\third_party\omc']
    
        f = open(r'{}_RUNWEST.bat'.format(ModelName), 'w')
        for n in WESTENVIRONMENT:
            f.write(n + '\n')
        f.write(WESTCALL)
        f.close()
        
        #os.system('{}_RUNWEST.bat'.format(ModelName))  #### NOTE: check that this doesnt instanciate a double core one for threading and other for the os.system call
    
        # Initialize a parallel call with a minimized terminal. Wait until finish and liberate.
        def startProgram():
            SW_MINIMIZE = 6
            info = subprocess.STARTUPINFO()
            info.dwFlags = subprocess.STARTF_USESHOWWINDOW
            info.wShowWindow = SW_MINIMIZE
            return subprocess.Popen('{}_RUNWEST.bat'.format(ModelName), startupinfo=info)
        p = startProgram()    
        p.communicate()
     
    def __init__(self, InstanceNames, modelPath):
        
        self.InstanceNames = InstanceNames
        self.OccupationList = np.zeros(len(InstanceNames))
        self.NumberofInstances = len(InstanceNames)
        self.Paths = modelPath
        self.threads_active = list()
        
    def occupy(self, indexAvailable):
        # Change status of Instance to occupied.
        if self.OccupationList[indexAvailable] == 0:
            self.OccupationList[indexAvailable] = 1

    def release(self, indexAvailable):
        # Release model instance
        if self.OccupationList[indexAvailable] == 1:
            self.OccupationList[indexAvailable] = 0
            self.threads_active = self.threads_active[:-1]

    def get_nextAvailable(self):
        # Search for an available instance
        try:
            indexAvailable = next(i for i, val in enumerate(self.OccupationList) if val==0)
            self.occupy(indexAvailable)
            return self.InstanceNames[indexAvailable]
        except:
            return None # this indicates that no more models are available.

    def storeModelOutput(self, ModelName, Parameterlist, Timelist, PathsArg):
        # Save all model output files for later reuse. 
        # Storage as csv files in a simulation_i folder under Model Ouputs

        def merge_dicts(*dict_args):
	    """
		    Given any number of dicts, shallow copy and merge into a new dict,
		    precedence goes to key value pairs in latter dicts.
            """
            result = {}
            for dictionary in dict_args:
                result.update(dictionary)
            return result

        directory = os.path.join(self.Paths, 'SimulationOutput', ModelName)
        if not os.path.exists(directory):
            os.makedirs(directory)

        counter = len(os.listdir(directory))
        os.makedirs(os.path.join(directory, 'Sim_' + str(counter))) # create directory where outputs are to be saved.

        # go to model library and copy all files belonging to .out
        for fileout in [s for s in os.listdir(os.path.join(self.Paths, ModelName)) if '.out' in s]:
            shutil.copy2(os.path.join(self.Paths, ModelName, fileout), os.path.join(directory, 'Sim_' + str(counter)))

        #Store config External (parameters used in the simulation)
        with open(os.path.join(directory, 'Sim_' + str(counter), 'ExternalParameters.csv'), 'wb') as csv_file:
            writer = csv.writer(csv_file)
            for key, value in Parameterlist.items():
               writer.writerow([key, value])



    def model_run(self, Parameterlist, Timelist):
        
        ModelName = self.get_nextAvailable()
        
        #self.model_activateParallel(Parameterlist, Timelist, ModelName)

        if ModelName is not None:
            t = threading.Thread(target=self.model_activateParallel, args = (Parameterlist, Timelist, ModelName, ) )
            self.threads_active.append(t)
            t.start()

            while self.NumberofInstances==self.OccupationList.sum(): #wait for a model to be available
                time.sleep(.01)
            
        else:
            while self.NumberofInstances==self.OccupationList.sum(): #wait for a model to be available
                time.sleep(.01)
            else:
                ModelName = self.get_nextAvailable()
                t = threading.Thread(target=self.model_activateParallel, args = (Parameterlist, Timelist, ModelName, ) )
                self.threads_active.append(t)
                t.start()


    


                                            
                    

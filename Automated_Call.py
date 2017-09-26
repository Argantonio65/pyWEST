# -*- coding: utf-8 -*-
"""
Created on Wed Feb 22 15:49:18 2017

Process setting a new automatic inference process:
    1- Create a n model folder replicates eg. \Model_1 \Model_2 ... \Modeln
    2- Copy an instance of Tornado.Main inside each model folder. Change inside this file Prop Name="CalcVarPrefix" Value="Model1"
    3- Create a folder called \inference  where Parallel_WESTRunningPyWrapper.py and ModelRun.py are located
    4- Inside Parallel_WESTRunningPyWrapper.py change the model experiment name to the one chosen in the WEST model.
    5- Instanciate n models and run them
    
Automated call
    
    
@author: A. Moreno Rodenas, TUDelft
"""
#%% set modelrepository path
repPath = 'C:\Users\localadmin.TUD278183\Desktop\GitProjects\pyWest'


#%%General Libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os
plt.style.use('ggplot')

import sys
import timeit
sys.path.insert(0, repPath + '\AutomatedCall')
from Parallel_WESTRunningPyWrapper import ModelInstances


#%% DEFINE SIMULATION TIME
Dateseries = '01-jan-2012_31-Dec-2012'
TimeWindow =  '01-Jan-2012_30-Aug-2012'
Initial = TimeWindow[:11]
Final = TimeWindow[12:]


#%% Auxilliary functions
def ReadOutput(fileouputname, ModelNAME, TimeWindowStart = None, variable = None):
    Output = pd.read_csv(repPath + '\\' + ModelNAME +'\\' + fileouputname , sep = '\t', skiprows=[1], index_col=[0])
    if TimeWindowStart is not None:
        
        Ind = Output.index.tolist()
        TimefreqOutput = int(round((Ind[1]-Ind[0])*3600*24)) # frequency of communication output in seconds. NOTE: The communication in the WEST output should be a fraction of day and interpolated (with as many decimals as possible to avoid problems with drifting of the timeseries) e.g. hourly should be: 0.041666666666666664, avoid rounding to 0.041667          
        TimeEnlapsed = pd.date_range(pd.to_datetime(TimeWindowStart) ,periods = len(Output), freq = '{}S'.format(TimefreqOutput))
        Output.set_index(TimeEnlapsed, inplace = True)
    
    if variable is None:
        return Output
    else: 
        return Output[variable]

def MeanHydraulicDepth(d, W_b, z):
    return (W_b*d + z*d**2)/(W_b + 2*z*d)
    
def NS(s,o):
    """
    Nash Sutcliffe efficiency coefficient
    input:
        s: simulated
        o: observed
    output:
        ns: Nash Sutcliffe efficient coefficient
    """
    o = o[s.index.tolist()].copy()
    o = o[o>=0].copy()
    s = s[o.index.tolist()].copy()
    return 1 - sum((s-o)**2)/sum((o-np.mean(o))**2)
    
    

#%% MODEL instance
ModelInstance = ModelInstances(['Model_dummy_1'], modelPath = repPath, modelInternalName = 'Model_dummy_1.Dynamic.ObjEval.Exp')


#%%                          
# Parameters
Timelist = {'StartTime':float((pd.to_datetime(Initial) - pd.to_datetime(Dateseries[:11])).days),'StopTime':float((pd.to_datetime(Final) - pd.to_datetime(Dateseries[:11])).days)}
Parameterlist = {'n':0.07, 'KBODs':0.55, 'KLmin':0.1, 'KO2':1.6, 'SOD':1} 


#%% Model Run

start_timer = timeit.default_timer()   
ModelInstance.model_run(Parameterlist, Timelist)


print 'Simulation time : {} seconds'.format(timeit.default_timer() - start_timer)

'''
#%% Output Load
output = ReadOutput('Model_dummy_1.Dynamic_water_quality.Simul.1.out.txt', ModelInstance.InstanceNames[0], TimeWindowStart = Initial, variable = '.River_5.DO')
               
#%%Plot
plt.figure(figsize = (15,5))
plt.plot(output)

'''






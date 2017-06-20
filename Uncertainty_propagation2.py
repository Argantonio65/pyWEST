# -*- coding: utf-8 -*-
"""
Created on Wed Feb 22 15:49:18 2017

Process setting a new automatic inference process:
    1- Create a n model folder replicates eg. \Model_1 \Model_2 ... \Modeln
    2- Copy an instance of Tornado.Main inside each model folder. Change inside this file Prop Name="CalcVarPrefix" Value="Model1"
    3- Create a folder called \inference  where Parallel_WESTRunningPyWrapper.py and ModelRun.py are located
    4- Inside Parallel_WESTRunningPyWrapper.py change the model experiment name to the one chosen in the WEST model.
    5- Instanciate n models and run them

Forward uncertainty propagation scheme (parallel)
    
    
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
import json
sys.path.insert(0, repPath + '\AutomatedCall')
from Parallel_WESTRunningPyWrapper import ModelInstances


#%% DEFINE SA TIME
Dateseries = '01-jan-2012_31-Dec-2012'
TimeWindow =  '01-May-2012_30-Aug-2012'
Initial = TimeWindow[:11]
Final = TimeWindow[12:]


#%% Load parameter sampling scheme
SamplingLayout = pd.read_csv('C:\\Users\\localadmin.TUD278183\\Desktop\\GitProjects\\pyWEST\\500SamplesUP.txt', index_col = [0])

#%% CREATE Model instance with n replicates
ModelInstance = ModelInstances(['Model_dummy_1'], modelPath = repPath)

#%%                          
# Parameters
Timelist = {'StartTime':float((pd.to_datetime(Initial) - pd.to_datetime(Dateseries[:11])).days),'StopTime':float((pd.to_datetime(Final) - pd.to_datetime(Dateseries[:11])).days)}
Parameterlist = {'n':0.07, 'KBODs':0.55, 'KLmin':0.1, 'KO2':1.6, 'SOD':1} 


#%% Model Run

start_timer = timeit.default_timer()   
ModelInstance.model_run(Parameterlist, Timelist, ThreadingPool = 8, ParamDatabase = os.path.join(repPath, '500SamplesUP.txt'))


print 'Simulation time : {} seconds'.format(timeit.default_timer() - start_timer)


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
ModelInstance = ModelInstances(['Model_dummy_1', 'Model_dummy_2', 'Model_dummy_3', 'Model_dummy_4'], modelPath = repPath, modelInternalName = 'Model_dummy_1.Dynamic.ObjEval.Exp')


#%% n Core SA Parallel
# Parameters
for i in range(len(SamplingLayout)):
    Timelist = {'StartTime':float((pd.to_datetime(Initial) - pd.to_datetime(Dateseries[:11])).days),'StopTime':float((pd.to_datetime(Final) - pd.to_datetime(Dateseries[:11])).days)}
    Parameterlist = {'id_simulation': i}
    CalibratedParams = {'n':0.07, 'KBODs':0.55, 'KLmin':0.1, 'KO2':1.6, 'KNO2':0.5, 'KSO2':1.05, 'SOD':0.5, 'TSOD':1.05, 'TKd': 1.00, 'Vs1':0.73, 'Vs2':9.36, 'MB': 0, 'Kd1':0.6, 'Kd2':0.16, 'Knit':0.16, 'TKL': 0.96, 'VKL': 5.5}
    
    Parameterlist.update(CalibratedParams)   
    
    # Set the parameterlist for the sample i
    for variable in SamplingLayout.columns.tolist():
        Parameterlist[variable] = SamplingLayout[variable].ix[i]
    # Run the model
    ModelInstance.model_run(Parameterlist, Timelist)

# check that every Instance is finished, and if yes continue
while True:
    if not any(ModelInstance.OccupationList):
        break


#%% ReadingOuput


def Read_SA_outputVariable(Outputfilename, variable, Instances, Outputdir, Initial):
    
    OutDataframe = pd.DataFrame()

    for instance in Instances:
        for simulation in os.listdir(os.path.join(Outputdir, 'SimulationOutput', instance)):  
            
            #read id number                
            with open(os.path.join(Outputdir, 'SimulationOutput', instance, simulation, 'ExternalParameters.csv')) as f:
                content = f.readlines()
            content = [x.strip() for x in content]

            id_simul = [s[s.index(',')+1:] for s in content if 'id_simulation' in s][0]
            print id_simul           
            Output = pd.read_csv(os.path.join(Outputdir, 'SimulationOutput', instance, simulation, Outputfilename), sep = '\t', skiprows=[1], index_col=[0])[variable]
            Output = Output.rename('Sim_'+ id_simul + variable)
            OutDataframe = pd.concat([OutDataframe, Output], axis = 1)
    
    OutDataframe = OutDataframe.sort_index(axis=1)
    
    Ind = OutDataframe.index.tolist()
    TimefreqOutput = int(round((Ind[1]-Ind[0])*3600*24)) # frequency of communication output in seconds. NOTE: The communication in the WEST output should be a fraction of day and interpolated (with as many decimals as possible to avoid problems with drifting of the timeseries) e.g. hourly should be: 0.041666666666666664, avoid rounding to 0.041667 
    
    TimeEnlapsed = pd.date_range(pd.to_datetime(Initial), periods = len(OutDataframe), freq = '{}S'.format(TimefreqOutput)) 
    OutDataframe.set_index(TimeEnlapsed, inplace = True)

    return  OutDataframe
    
    
SAoutput = Read_SA_outputVariable('Model_dummy_1.Dynamic_water_quality.Simul.1.out.txt', '.River_5.DO', ModelInstance.InstanceNames, ModelInstance.Paths, Initial) #attention output should be provided in hourly step
    

#%% Get Statistics

#SAoutput.dropna(inplace = True)
mean =  SAoutput.mean(axis = 1)
Q95_up = SAoutput.quantile(0.975, axis = 1)
Q95_down = SAoutput.quantile(0.025, axis = 1)

#%% plot statistics

fig = plt.figure()
plt.plot(mean, 'b', alpha = 0.6, label = 'Mean simulator')
plt.fill_between(mean.index.tolist(), Q95_down, Q95_up, color='blue', alpha='0.3')

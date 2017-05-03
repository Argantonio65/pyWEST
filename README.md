# pyWEST
Python scripts for water quality simulators in WEST (MIKE DHI). 

- Sensitivity analysis
- Model Inference/Calibration
- Automated simulation with control over inputs and model parameters

## Dependencies 
- Ironpython
- Python 2.7
- TornadoNet

## Set-up

- Install Ironpython and set environment variable (ipy). 
- Install python 2.7 with the following libraries:
    numpy, pandas, os, time, timeit, json, shutil and sys

- Download Parallel_WESTRunningPyWrapper.py and RunModel.py and set them in a project folder under \AutomatedCall\
- Create n model replicate folders in the main directory. Name the replicates eg. \Model_1 \Model_2 ... \Modeln
- Copy an instance of Tornado.Main.xml inside each model folder. Change inside this file: Prop Name="CalcVarPrefix" Value="Model1"

## Operation Automated Call

- Instanciate n models with:
  ```python
  ModelInstance = ModelInstances(['Model_1', 'Model_2', 'Model_n'], modelPath = "<ProjectFolder>")
  ```
- Set Parameter values:
  e.g
  ```python
  Timelist = {'StartTime':0,'StopTime':15}
  Parameterlist = {'n':0.07, 'KBODs':0.55, 'KLmin':0.1, 'KO2':1.6, 'SOD':1} 
  ```
- Run Model:
  ```python
  ModelInstance.model_run(Parameterlist, Timelist)
  ```
  Note: each call to model_run will initiate a call to the next available Model instance. This will open a call in the background. The execution of the program will be halted until all runs are finished.
- Reads outputs:
  ```python
  output = ReadOutput('Model_dummy_1.Dynamic_water_quality.Simul.1.out.txt', ModelInstance.InstanceNames[0], TimeWindowStart = '01-01-2012 00:00:00', variable = '.River_5.DO')
  ```

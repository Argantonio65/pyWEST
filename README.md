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

## Description

- **RunModel.py** Is an IronPython script which interfaces with Tornado.net in order to call a WEST experiment. 
- **Parallel_WESTRunningPyWrapper.py** Python class which calls RunModel.py in parallel. Management of model resources.
        - Atributes:
        
                - self.InstanceNames = List the Model names
                - self.OccupationList = boolean list, 1 for occupied node, 0 for free
                - self.NumberofInstances = Number of total Model sessions (should not be higher than the number of local licenses or computer cores)
                - self.Paths = Project directory Path
                - self.threads_active = Number of threads initiated


## Operation Automated_Call.py

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
  A Parameterlist is formed by a dictionary of parameter values.
  An entry of the form:
    -  ```'param' ```:value will set all parameters sharing the same name (even if it has been declared as a Top-level parameter) to the value specified.
    -  ```'param@submodel' ```:value will set the parameter 'param' only in the block model 'submodel'. This allows for local specifications.
    - ```'param@Manipulated':value``` sets a manipulated variable value which doesn't carry any declared input. There is the option                   ```'param@Manipulated#submodel':value``` to make the change only at submodel level.
    - ```'param@Multiplier'```:value works by ofsetting its current saved value by a multiplyier value.

- Run Model:
  ```python
  ModelInstance.model_run(Parameterlist, Timelist)
  ```
  **Note:** each call to model_run will use the next available Model instance in an availability basis. This will open a call in the background. The execution of the program will be halted until all simulations are finished.
- Read outputs:
  ```python
  output = ReadOutput('Model_dummy_1.Dynamic_water_quality.Simul.1.out.txt', ModelInstance.InstanceNames[0], TimeWindowStart = '01-01-2012 00:00:00', variable = '.River_5.DO')
  ```
  
  **Note:** Simulations produced by calling .model_run(Parameterlist, Timelist) store all output files in a new folder \SimulationOutput\ModelName\Sim_i\. Each Sim_i contains: All output files from the WEST experiment which has .out. in their names. A txt file containing all iternal parameter values in the model <Internal_parameters.out.txt> and a file containing all changed parameter values from the Parameterlist in <External_parameters.txt>.
  
## Operation Uncertainty_propagation.py

This script automatizes a parameter sampling scheme provided by:

  ```python
 SamplingLayout = pd.read_csv('\pyWEST\500SamplesUP.txt', index_col = [0])
  ```
An example for the format is found at pyWEST\500SamplesUP.txt

The script performs a simulation for each row in the layout. It will call in parallel as many simulations as model instances provided. Limited by the available slots in the license file (academic license x4).

The function Read_SA_outputVariable loads the selected variable from the output folder.


## Extra:
### Notebooks
Included two jupyter notebooks containing:

- **Bayesian_Inference_Example.ipynb** : Examples and tutorial to perform bayesian parameter inference to a West model.
- **Calibration_Example.ipynb** : A tutorial for perform model calibration with scipy.minimize

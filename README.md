# Timewalk measurements in the VeloPix ASIC
This repository holds the project developed during the Reproducibility in Research course at Unicamp. The main purpose was to create an Executable Paper by providing all the necessary elements to reproduce this research. The study of this effect in VeloPix is reported in this work.

## Repository Structure

The files are organized as follow:

- /data - Dataset (original and pre-processed)
- /deliver - Executable paper 
- /code - Codes and notebooks used during the experiment
- /results - Outputs of the analysis 
- /utils - Best Practices 
- /workflow - Communication flow between the components that involves the entire project
- /environment - Dependencies and environment variables

## Paper Draft
The paper is currently available in the notebook [code/twinterpolation.ipynb](https://github.com/larissahmendes/timewalk/blob/master/code/twinterpolation.ipynb)

OBs.: This is not the final versions of the codes nor of the paper text.

## Workflow
See a workflow chart with with the aproach plan for the analysis at workflow/workflow_planning.png ![workflow/workflow_planning.png](https://github.com/larissahmendes/timewalk/blob/master/workflow/workflow_planning.png)

## Data
Input data size is 2.1GB, therefore it can't be storeg on github. A data storage tool will be used.

## Environement
A Dockerfile with the with the software and libraries will be available at environement folder.

- [Jupyter](https://jupyter.org/install.html) notebook: 

  The minimal version of Jupyter required is 4.0.
  
  `pip install jupyterlab`

- [ROOT](https://root.cern.ch/downloading-root) 6.07 or newer:

  #TODO: instructions to download root  

- Libraries: 

  `sudo pip install metakernel zmq`
  
 ** This analysis will not be available for Windows.


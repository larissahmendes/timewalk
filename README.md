# Timewalk measurements in the VeloPix ASIC
This repository holds the project developed during the Reproducibility in Research course at Unicamp. The main purpose was to create an Executable Paper by providing all the necessary elements to reproduce this research. The study of this effect in VeloPix is reported in this work.

## Repository Structure

The files are organized as follow:

- /data - Dataset (original and pre-processed)
- /deliver - Executable paper and its images
- /code - Codes and notebooks used during the experiment
- /results - Outputs of the analysis 
- /utils - Best Practices  for reproducible research
- /workflow - Communication flow between the components that involve the entire project
- /environment - Dependencies and environment variables

## Data
The input data size is 2.1GB, therefore it can't be stored on GitHub. A data storage tool will be used.

## Environment

The analysis steps will run in a ROOT analysis in a Jupyter notebook environment. It is possible to install all the necessary libraries in your local environment or run the docker container available the [environment](https://github.com/larissahmendes/timewalk/tree/master/environment) folder.

## Paper Draft
The paper is currently available in the notebook [code/twinterpolation.ipynb](https://github.com/larissahmendes/timewalk/blob/master/code/twinterpolation.ipynb)

OBs.: This is not the final version of the codes nor of the paper text.

## Workflow
See a workflow chart with the approach plan for the analysis at workflow/workflow_planning.png ![workflow/workflow_planning.png](https://github.com/larissahmendes/timewalk/blob/master/workflow/workflow_planning.png)

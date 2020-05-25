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
- /environement - Dependencies and environment variables

## Paper Draft
This will not be the final format of the paper. Also, this version of the paper has all possible histograms outputs, not all of them will be on the final paper, but they will be saved as intermediate results. 

Link for paper draft:
https://www.overleaf.com/read/kztvzqvvtbxb

## Workflow
See a workflow chart with with the aproach plan for the analysis at workflow/workflow_planning.png ![workflow/workflow_planning.png](https://github.com/larissahmendes/timewalk/blob/master/workflow/workflow_planning.png)

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


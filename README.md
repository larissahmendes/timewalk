# Timewalk measurements in the VeloPix ASIC
This repository holds the project developed during the Reproducibility in Research course at Unicamp. The main purpose was to create an Executable Paper by providing all the necessary elements to reproduce this research. The study of this effect in VeloPix is reported in this work.

## Repository Structure

The files are organized as follow:

/data - Dataset (original and pre-processed)
/deliver - The executable paper
/code - Codes and notebooks used during the experiment
/figures - Figures used on the paper
/results - Outputs of the analysis 
/utils - Best Practices 
/workflow - Communication flow between the components that involves the entire project
/environement - Dependencies and environment variables

Link for paper:
https://www.overleaf.com/read/kztvzqvvtbxb

** This will not be the final format of the paper. Also, this version of the paper has all possible histograms outputs, not all of them will be on the final paper, but they will be saved as intermediate results. 


## Workflow
See a workflow chart with with the aproach plan for the analysis at workflow/workflow_planning.png

## Environement
A Dockerfile will be available for the user with the following softwares and libraries:
This analysis will not be available for Windows.

- Jupyter notebook:
  The minimal version of Jupyter required in this case is 4.0.
  sudo pip install

- ROOT 6.07 or newer:
  https://root.cern.ch/downloading-root

- Libraries: metakernel zmq
  sudo pip install jupyter metakernel zmq
  
 ** To run the notebook do: root --notebook

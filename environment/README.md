# Environment

The analysis steps will run in a ROOT analysis in a Jupyter notebook environment. In order to run it, it is possible to install all the necessary libraries locally or run the docker container available below.

### OPTION 1) Executing the analysis on your local environment

The following steps are the basic instructions for **UNIX systems**, check the instructions for your system version on the following links. The operation of the software package and the analysis presented on this repository is not guaranteed on the Windows operating system. 

**1)** Install ROOT 

   a) Check the prerequisites for the list of packages needed for your setup before starting the build on this [link](https://root.cern.ch/build-prerequisites)
         
   b) Follow the _Quick Start_ installation instruction on this [link](https://root.cern.ch/building-root). It is recommended to use version 6.07.06 or later. 

**2)** Install Python 3
    
   It is recommended to use version 3.6.5 or later. If you don't have it on your machine, you can use the instruction on this [link](https://realpython.com/installing-python/).

**2)** [Install](https://root.cern.ch/how/how-create-rootbook) Jupyter notebook and the necessary dependencies to run the ROOT kernel 

   The minimal version of Jupyter required, in this case, is 4.0. 
   
   `sudo pip install jupyter metakernel zmq`

**3)** Open the notebook on the desired directory

    `root --notebook`
    
   This will open the notebook interface in your browser

### OPTION 2) Executing the analysis on a containerized environment
If necessary follow the instructions in https://docs.docker.com/engine/install/ubuntu/ to install docker. It is recommended to use version 19.03.8 or later. In order to run Docker, you need to manage Docker as a non-root user. Follow the first instructions at https://docs.docker.com/engine/install/linux-postinstall/, otherwise, you need to run the following commands with sudo.

The repository is available in [Docker Hub](https://hub.docker.com/r/larissahmendes/jupyter-notebook-pyroot).

This docker image includes the software framework `CERN ROOT` with `Python 3` in order to use Jupyter notebooks on both `PyROOT` and `ROOT C++` kernels. It is built from `rootproject/root-fedora` image.

**1)** Pull the image from the Docker Hub repository 

`docker pull larissahmendes/jupyter-notebook-pyroot:1.1.0`

**2)** Start the Jupyter server with

   To run the image, do

    `docker run -p 8888:8080 -v <host-path>:/work larissahmendes/jupyter-notebook-pyroot:1.1.0`

   Where:
   ` -p 8888:8080`: Maps the Docker container port 8080 to the host port 8888 .
   
   `<host-path>:/work`: Mounts the local folder `< host-path >` to `/work` in the container. Substitute `< host-path >` by your local path with the dataset and/or pre-existing notebooks, for example `/home/user:/work`. **In this case, `< host-path >` will be the path were the repository of this analysis is on your computer**
  
**3)** Open the notebook on the desired directory

To access the notebook, copy and paste `localhost:8888` to a browser.

When accessing the notebook a **token** authentication is called. When you start the notebook server, a token is generated to use for authentication. This token is logged to the **terminal** after you run the container so that you can copy/paste the token into your browser. For example:

`[I 02:40:21.942 NotebookApp] The Jupyter Notebook is running at:
http://localhost:8888/?token=c8de56fa4deed24899803e93c227592aef6538f93025fe01`

In this **example**, you would just copy the token `c8de56fa4deed24899803e93c227592aef6538f93025fe01` to the authentication field on your browser. Copy the token that is shown on your terminal.




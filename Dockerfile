FROM rootproject/root-fedora

ARG notebook_path
WORKDIR workdir_path=$notebook_path 

RUN python3 -m pip install jupyter # install jupyter
RUN python3 -m pip install prompt-toolkit==1.0.15
RUN python3 -m pip install metakernel zmq

# Run jupyter
CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--port=8080", "--allow-root"]

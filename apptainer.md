In order to use apptainer to run the EzPC library, copy the ezpc.def file outside
of the EzPC directory and run: `apptainer build --sandbox ezpc.sif ezpc.def`

This will create a directory version of the container. You can remove `--sandbox`
if that is unnecessary.

To run the apptainer: `apptainer run ezpc.sif`

To open an apptainer shell: `apptainer shell --writable ezpc.sif`

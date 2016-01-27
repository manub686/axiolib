Atomix I/O library
------------------
Depends on: atomix, orilib

## Build ##

```
axiolib $ autoreconf --install #do once
axiolib $ mkdir build; cd build; ../_configure; make
```

## Use ##
To use the library, add something like this to your .bashrc:

```
export AXIOLIB_INC_DIR=/home/manub/workspace/axiolib
export AXIOLIB_INSTALL_DIR=/home/manub/workspace/axiolib/build
```


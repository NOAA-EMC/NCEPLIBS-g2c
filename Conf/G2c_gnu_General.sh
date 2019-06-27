# *** manually set environments (for gnu compiler) of g2c ***

 : ${USERMODE:=false}  # user mode (USERMODE) is closed by default
                       # set env var USERMODE to "true" to active it
 ${USERMODE} && {
    echo "Environment set by user"
# On theia/cray, user can load environment
#   module load gcc/6.2.0
# Or set environment on specific platform
    gcc_version=6.2.0
    gcc_topdir=/apps/gcc/$gcc_version
    export PATH=$gcc_topdir/bin:$PATH
    export LIBRARY_PATH=$gcc_topdir/lib64:$LIBRARY_PATH
    export LD_LIBRARY_PATH=$gcc_topdir/lib64:$LD_LIBRARY_PATH
    export INCLUDE=$gcc_topdir/include:$INCLUDE
    export MANPATH=$gcc_topdir/share/man:$MANPATH
 }

 ANCHORDIR=..
 export COMP=gnu
 export G2C_VER=v1.6.0
 export G2C_SRC=
 export G2C_LIB4=$ANCHORDIR/libg2c_${G2C_VER}_4.a

#  JASPER, PNG and Z LIB in default system include *
#  *** set nothing ***
 
#  WCOSS WCOSS WCOSS WCOSS WCOSS WCOSS WCOSS WCOSS *
#JPZlib=/nwprod2/lib
#JASPER_VER=v1.900.1
#PNG_VER=v1.2.44
#Z_VER=v1.2.6
#JASPER_INC=$JPZlib/jasper/v1.900.1/include
#PNG_INC=$JPZlib/png/v1.2.44/include
#Z_INC=$JPZlib/z/v1.2.6/include

#  THEIA THEIA THEIA THEIA THEIA THEIA THEIA THEIA *
#JPZlib=/scratch3/NCEPDEV/nwprod/lib
#JASPER_VER=v1.900.1
#PNG_VER=v1.2.44
#Z_VER=v1.2.6
#JASPER_INC=$JPZlib/jasper/v1.900.1/include
#PNG_INC=$JPZlib/png/v1.2.44/src/include
#Z_INC=$JPZlib/z/v1.2.6/include

 export CC=gcc
 export FC=gfortran
 export CPP=cpp
 export OMPCC="$CC -fopenmp"
 export OMPFC="$FC -fopenmp"
 export MPICC=mpigcc
 export MPIFC=mpigfortran

 export DEBUG="-g -O0"
 export CFLAGS="-g -O3 -fPIC"
 export FFLAGS="-g -fbacktrace -O3 -fPIC"
 export FREEFORM="-ffree-form"
 export FPPCPP="-cpp"
 export CPPFLAGS="-P -traditional-cpp"
 export MPICFLAGS="-g -O3 -fPIC"
 export MPIFFLAGS="-g -fbacktrace -O3 -fPIC"
 export MODPATH="-J"
 export I4R4=""
 export I4R8="-fdefault-real-8"
 export I8R8="-fdefault-integer-8 -fdefault-real-8"

 export CPPDEFS=""
 [[ -z "${PNG_INC-}" ]] && { IPNG= ; } || { IPNG=-I$PNG_INC; }
 [[ -z "${JASPER_INC-}" ]] && { IJASPER= ; } || { IJASPER=-I$JASPER_INC; }
 [[ -z "${Z_INC-}" ]] && { IZ= ; } || { IZ=-I$Z_INC; }
 export CFLAGSDEFS="$IPNG $IJASPER $IZ -DUNDERSCORE -DLINUX -DUSE_JPEG2000 -DUSE_PNG -D__64BIT__"
 export FFLAGSDEFS="-fno-range-check"

 export USECC="YES"
 export USEFC=""
 export DEPS="JASPER ${JASPER_VER-}, LIBPNG ${PNG_VER-}, ZLIB ${Z_VER-}"

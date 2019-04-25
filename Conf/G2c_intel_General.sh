# *** manually set environments (for intel compiler) of g2c ***

# !!! module environment (*THEIA*) !!!
 module load intel/18.1.163
#module load ics/17.0.3

 ANCHORDIR=..
 export COMP=ips
 export G2C_VER=v1.6.0
 export G2C_SRC=
 export G2C_LIB4=$ANCHORDIR/libg2c_${G2C_VER}_4.a

#JPZlib=/nwprod2/lib                                #WCOSS
 JPZlib=/scratch3/NCEPDEV/nwprod/lib                #THEIA
 export JASPER_VER=v1.900.1
 export JASPER_INC=$JPZlib/jasper/v1.900.1/include
 export PNG_VER=v1.2.44
#export PNG_INC=$JPZlib/png/v1.2.44/include         #WCOSS
 export PNG_INC=$JPZlib/png/v1.2.44/src/include     #THEIA
 export Z_VER=v1.2.6
 export Z_INC=$JPZlib/z/v1.2.6/include

 export CC=icc
 export FC=ifort
 export CPP=cpp
 export OMPCC="$CC -qopenmp"
 export OMPFC="$FC -qopenmp"
 export MPICC=mpiicc
 export MPIFC=mpiifort

 INCS="-I${PNG_INC} -I${JASPER_INC} -I${Z_INC}"

 export DEBUG="-g -O0"
 export CFLAGS="-O3 -DUNDERSCORE -DLINUX ${INCS} -DUSE_JPEG2000 -DUSE_PNG -D__64BIT__ -fPIC"
 export FFLAGS="-O3 -xHOST -traceback -fPIC"
 export CPPFLAGS="-P -traditional-cpp"
 export MPICFLAGS="-O3 -DUNDERSCORE -DLINUX -fPIC"
 export MPIFFLAGS="-O3 -xHOST -traceback -fPIC"
 export MODPATH="-module "
 export I4R4="-integer-size 32 -real-size 32"
 export I4R8="-integer-size 32 -real-size 64"
 export I8R8="-integer-size 64 -real-size 64"

 export CPPDEFS=""
 export CFLAGSDEFS=""
 export FFLAGSDEFS=""

 export USECC="YES"
 export USEFC=""
 export DEPS="JASPER $JASPER_VER, LIBPNG $PNG_VER, ZLIB $Z_VER"

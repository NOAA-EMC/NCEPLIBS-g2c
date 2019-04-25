# *** for Theia (intel) ***
 module load intel/18.1.163
 module load dev/g2/v3.1.0
 module load dev/jasper/v1.900.1
 module load dev/libpng/v1.2.44
 module load dev/zlib/v1.2.11

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

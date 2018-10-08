#!/bin/sh
set -eux
#-----------------------------------------------------
cwd=`pwd`
source ../../../machine-setup.sh > /dev/null 2>&1
module use ../../modulefiles
module load jasper/v1.900.1

export LIBNAME=g2c
export VER=v1.5.0

if [ $target = wcoss_cray ]; then
  export FCMP=ftn
  module load PrgEnv-intel
  module load craype-sandybridge
elif [ $target = "wcoss" ]; then
  module load ics/12.1
elif [ $target = "theia" ]; then
  module load intel/14.0.2
elif [ $target = "gaea" ]; then
  :
elif [ $target = "jet" ]; then
  module load intel/12.1.4
fi

#
#     Build g2c library
#
rm -f *.o ../../libs/${LIBNAME}_${VER}/libg2c_${VER}_4.a
make
mkdir -p ../../libs/${LIBNAME}_${VER}
mv ../../libg2c_${VER}_4.a ../../libs/${LIBNAME}_${VER}/libg2c_${VER}_4.a

#
#     Create modulefile
#
cd ../../
lwd=`pwd`
cd $cwd
mkdir -p $lwd/modulefiles/$LIBNAME
cat modulefile.template | sed s:_CWD_:$lwd:g > $lwd/modulefiles/$LIBNAME/$VER

exit

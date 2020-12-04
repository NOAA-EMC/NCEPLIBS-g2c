#!/bin/sh

######################################################################
#
# Build unit_test for G2C library
#
######################################################################

. $MODULESHOME/init/bash
mac=$(hostname | cut -c1-1)
mac2=$(hostname | cut -c1-2)

if [ $mac = v -o $mac = m  ] ; then            # For Dell (i.e. Mars and Venus)
   export machine=wcoss_dell_p3
   module load ips/18.0.1.163
   module load impi/18.0.1
   module load cmake/3.16.2
   module load git/2.14.3
   module load jasper/1.900.29
   module load libpng/1.2.59
   module load zlib/1.2.11
   ###   Load tesing g2c v1.6.2
   module use module use /usrx/local/nceplibs/dev/NCEPLIBS/modulefiles
   module load  g2c/1.6.2
elif [ $mac = l -o $mac = s ] ; then             #    wcoss_c (i.e. luna and surge)
  export machine=cray-intel
  module unload craype-haswell
  module load craype-sandybridge
  module unload PrgEnv-cray
  module load PrgEnv-intel/5.2.82
  module unload intel
  module load intel/18.1.163
  module load jasper-gnu-sandybridge/1.900.29
  module load png-intel-sandybridge/1.2.49
  module load zlib-intel-sandybridge/1.2.7
fi

makefile=makefile_${machine}

echo " "
echo " You are on WCOSS:  $machine "
echo " "

export CC=icc
export CXX=icpc
make 
make clean

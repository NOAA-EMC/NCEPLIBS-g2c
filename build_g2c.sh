#!/bin/bash

 source ./Conf/Analyse_args.sh
 source ./Conf/Collect_info.sh
 source ./Conf/Gen_cfunction.sh
 source ./Conf/Reset_version.sh

 if [[ ${sys} == "intel_general" ]]; then
   sys6=${sys:6}
   source ./Conf/G2c_${sys:0:5}_${sys6^}.sh
 elif [[ ${sys} == "gnu_general" ]]; then
   sys4=${sys:4}
   source ./Conf/G2c_${sys:0:3}_${sys4^}.sh
 else
   source ./Conf/G2c_intel_${sys^}.sh
 fi
 $CC --version &> /dev/null || {
   echo "??? G2C: compilers not set." >&2
   exit 1
 }
 [[ -z $G2C_VER || -z $G2C_LIB4 ]] && {
   echo "??? G2C: module/environment not set." >&2
   exit 1
 }

set -x
 g2cLib4=$(basename $G2C_LIB4)

#################
 cd src
#################

 $skip || {
#-------------------------------------------------------------------
# Start building libraries
#
 echo
 echo "   ... build (i4/r4) g2c library ..."
 echo
   make clean LIB=$g2cLib4
   collect_info g2c 4 OneLine4 LibInfo4
   g2cInfo4=g2c_info_and_log4.txt
   $debg && make debug LIB=$g2cLib4 &> $g2cInfo4 \
         || make build LIB=$g2cLib4 &> $g2cInfo4
   make message MSGSRC="$(gen_cfunction $g2cInfo4 OneLine4 LibInfo4)" LIB=$g2cLib4
 }

 $inst && {
#
#     Install libraries and source files
#
   $local && {
     instloc=..
     LIB_DIR4=$instloc
     SRC_DIR=
   } || {
     [[ $instloc == --- ]] && {
       LIB_DIR4=$(dirname ${G2C_LIB4})
       SRC_DIR=$G2C_SRC
     } || {
       LIB_DIR4=$instloc
       SRC_DIR=$instloc/src
       [[ $instloc == .. ]] && SRC_DIR=
     }
     [ -d $LIB_DIR4 ] || mkdir -p $LIB_DIR4
     [ -z $SRC_DIR ] || { [ -d $SRC_DIR ] || mkdir -p $SRC_DIR; }
   }

   make clean LIB=
   make install LIB=$g2cLib4 LIB_DIR=$LIB_DIR4 SRC_DIR=$SRC_DIR
 }

#!/bin/bash

 (( $# == 0 )) && {
   echo "*** Usage: $0 wcoss|dell|cray|theia|intel_general|gnu_general [debug|build] [[local]install[only]]"
   exit 1
 }

 sys=${1,,}
 [[ $sys == wcoss || $sys == dell || $sys == cray ||\
    $sys == theia || $sys == intel_general || $sys == gnu_general ]] || {
   echo "*** Usage: $0 wcoss|dell|cray|theia|intel_general|gnu_general [debug|build] [[local]install[only]]"
   exit 1
 }
 debg=false
 inst=false
 skip=false
 local=false
 (( $# > 1 )) && {
   [[ ${2,,} == build ]] && debg=false
   [[ ${2,,} == debug ]] && debg=true
   [[ ${2,,} == install ]] && inst=true
   [[ ${2,,} == localinstall ]] && { local=true; inst=true; }
   [[ ${2,,} == installonly ]] && { inst=true; skip=true; }
   [[ ${2,,} == localinstallonly ]] && { local=true; inst=true; skip=true; }
 }
 (( $# > 2 )) && {
   [[ ${3,,} == build ]] && debg=false
   [[ ${3,,} == debug ]] && debg=true
   [[ ${3,,} == install ]] && inst=true
   [[ ${3,,} == localinstall ]] && { local=true; inst=true; }
   [[ ${3,,} == installonly ]] && { inst=true; skip=true; }
   [[ ${3,,} == localinstallonly ]] && { local=true; inst=true; skip=true; }
 }

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
 [[ -z $G2C_VER || -z $G2C_LIB4 ]] && {
   echo "??? G2C: module/environment not set."
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
              LIB_DIR4=..
              SRC_DIR=
             } || {
              LIB_DIR4=$(dirname ${G2C_LIB4})
              SRC_DIR=$G2C_SRC
              [ -d $LIB_DIR4 ] || mkdir -p $LIB_DIR4
              [ -z $SRC_DIR ] || { [ -d $SRC_DIR ] || mkdir -p $SRC_DIR; }
             }

   make clean LIB=
   make install LIB=$g2cLib4 LIB_DIR=$LIB_DIR4 SRC_DIR=$SRC_DIR
 }

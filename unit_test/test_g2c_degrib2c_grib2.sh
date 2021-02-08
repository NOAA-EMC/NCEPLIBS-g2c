#!/bin/sh
#            Test G2C Library 
#    This script uses to test G2C library with following routines:
#    - seekgb.c ; fseek; fread; g2_info; g2_getfld; g2_free;
#      g2_unpack1; g2_unpack2; g2_unpack3, g2_unpack4, g2_unpack5;
#      g2_unpack6; g2_unpack7

set +x

echo " "
echo "###################################################"
echo " Testing G2C Library "
echo "###################################################"
echo " "

export dir=` pwd `

. $MODULESHOME/init/bash
mac=$(hostname | cut -c1-1)
mac2=$(hostname | cut -c1-2)

if [ $mac = v -o $mac = m  ] ; then            # For Dell (i.e. Mars and Venus)
   echo ""
   export machine=wcoss_dell_p3
   echo ""
elif [ $mac = l -o $mac = s ] ; then             #    wcoss_c (i.e. luna and surge)
   echo ""
   export machine=cray-intel
   echo ""
fi

echo " "
echo " You are on WCOSS:  $machine "
echo " "

sleep 2

export cyc=00
export cycle=t${cyc}z
export exec=$dir

#
#  Setup working directories
#
# If you want to use temporary directories,
# you can change variable dir to temporary
#
export data=/gpfs/dell2/stmp/${LOGNAME}/data
export output=/gpfs/dell2/stmp/${LOGNAME}/output
mkdir -p $data $output

#
#  Clean up temp directory before test starts
#
if [ "$(ls -A $output)" ]; then
   echo "Cleaning $output"
   rm $output/*
fi
if [ "$(ls -A $data)" ]; then
   echo "Cleaning $data"
   rm $data/*
fi
if [ ! -x $exec/degrib2c ]; then
   echo ""
   echo " File executable: $exec/degrib2c is not exist"
   echo ""
   echo " Please build executable by Running script: "
   echo ""
   echo "   build_unit_test_g2c.sh "
   echo ""
   exit
fi

cp /gpfs/sss/emc/global/shared/nceplibs/fix/gfs_grib2/*  $data
cd $data

export file=gfs.t00z.pgrb2.0p25.f012

set +x
echo " "
echo "###################################################"
echo "         Testing G2C library                         "
echo "###################################################"
echo " "

# THIS SCRIPT READS A GRIB2 FILE AND WRITE OUT AN INVENTORY OF GRIB2 FILE
# OF GRIB2 FILE WITH THE FOLLOWING INFORMATION:
# -SECTION 0, 1
# -Grid Definition in section 3 (GDS)
# -Product Definition Templates (PDT) used in Section 4
# -Data Representation Section (DRS) in Section 5
# -Data Values in Data section

$exec/degrib2c  $file
set +x
$exec/degrib2c   $file  > $output/$file.inv
if [ $? -eq 0 ]; then echo ""; echo " Testing G2C library :  PASS ! "; echo ""; else echo ""; echo " Testing G2C library :  FAIL !" ;echo ""; err=1; fi
sleep 2

echo " "
echo " The output file is following: $output "
ls -l $output
echo " "

#!/bin/sh
# This is a test script for the NCEPLIBS-g2c project.
#
# This script tests the g2c_index utility with files downloaded via FTP.
#
# Ed Hartnett, 6/25/24

set -e
echo ""
echo "*** Running g2c_index test on FTP files"

ftp_files="blend.t19z.core.f001.co.grib2 \
aqm.t12z.max_8hr_o3.227.grib2 \
GLOBAL.grib2.2022103000.0000 \
hiresw.t00z.arw_5km.f00.hi.grib2 \
naefs_ge10pt.t12z.pgrb2a.0p50_bcf003 \
rap.t00z.awp130pgrbf00.grib2 \
seaice.t00z.grb.grib2 \
sgx_nwps_CG3_20221117_1200.grib2 \
cmc_geavg.t12z.pgrb2a.0p50.f000 \
WW3_Regional_US_West_Coast_20220718_0000.grib2 \
WW3_Regional_US_East_Coast_20220717_0600.grib2 \
gdas.t12z.pgrb2.1p00.anl.grib2 \
flxf2022111712.01.2022111712.grb2 \
"

for f in $ftp_files
do
    ls -l data/$f
    echo "Using g2c_index to create index for file $f"
    ../utils/g2c_index -v -o ${f}.idx ../tests/data/$f

    echo "Using g2c_degrib2 to create summary for file $f using index ${f}.idx."
    ../utils/g2c_degrib2 -v -o ${f}.degrib2 ../tests/data/$f ${f}.idx

    #diff -w ${f}.degrib2 data/ref_${f}.degrib2
done

echo "*** SUCCESS!"
exit 0


# # Create an index for a GRIB2 file.
# ../utils/g2c_index -v -o gdaswave.t00z.wcoast.0p16.f000.grib2.idx data/gdaswave.t00z.wcoast.0p16.f000.grib2 

# # Summarize the index data.
# ../utils/g2c_degrib2 -v -o gdaswave.t00z.wcoast.0p16.f000.grib2.idx.degrib2 data/gdaswave.t00z.wcoast.0p16.f000.grib2 gdaswave.t00z.wcoast.0p16.f000.grib2.idx 

# # Check against expected output.
# diff -w gdaswave.t00z.wcoast.0p16.f000.grib2.idx.degrib2 data/ref_gdaswave.t00z.wcoast.0p16.f000.grib2.degrib2

echo "*** SUCCESS!"
exit 0

#!/bin/sh
# This is a test script for the NCEPLIBS-g2c project.
#
# This script tests the g2c_index utility.
#
# Ed Hartnett, 9/10/23

set -e
echo ""
echo "*** Running g2c_index test"

# Create an index for a GRIB2 file.
../utils/g2c_index -v data/gdaswave.t00z.wcoast.0p16.f000.grib2 gdaswave.t00z.wcoast.0p16.f000.grib2.idx

# Summarize the index data.
../utils/g2c_degrib2 -v gdaswave.t00z.wcoast.0p16.f000.grib2.idx gdaswave.t00z.wcoast.0p16.f000.grib2.idx.degrib2

# Check against expected output.
diff -w g2c_degrib2_gdaswave.t00z.wcoast.0p16.f000.grib2.degrib2 data/ref_gdaswave.degrib2.txt

echo "*** SUCCESS!"
exit 0

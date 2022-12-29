#!/bin/sh
# This is a test script for the NCEPLIBS-g2c project.
#
# This script tests the g2c_degrib2 utility.
#
# Ed Hartnett, 12/29/22

set -e
echo ""
echo "*** Running g2c_degrib2 test"

# Generate degrib2 output for our test GRIB2 file.
../utils/g2c_degrib2 -v data/gdaswave.t00z.wcoast.0p16.f000.grib2 g2c_degrib2_gdaswave.t00z.wcoast.0p16.f000.grib2.degrib2 

# Check against expected output.
#diff -w g2c_degrib2_gdaswave.t00z.wcoast.0p16.f000.grib2.degrib2 data/ref_gdaswave.degrib2.txt

echo "*** SUCCESS!"
exit 0

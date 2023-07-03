#!/bin/sh
# This is a test script for the NCEPLIBS-g2c project.
#
# This script tests the g2c_compare utility.
#
# Ed Hartnett, 12/29/22

set -e
echo ""
echo "*** Running g2c_convert test"

# Compare file to itself.
../utils/g2c_compare -v data/gdaswave.t00z.wcoast.0p16.f000.grib2 data/gdaswave.t00z.wcoast.0p16.f000.grib2

echo "*** SUCCESS!"
exit 0

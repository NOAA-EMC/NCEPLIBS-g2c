#!/bin/sh
# This is a test script for the NCEPLIBS-g2c project.
#
# This script tests the g2c_index utility on very large files, which
# are only fetch from FTP if the CMake build includes the
# FTP_EXTRA_TEST_FILES option ON.
#
# Ed Hartnett, 2/22/24

set -e
echo ""
echo "*** Running g2c_index extra file test"

# rrfs.t18z.prslev.f000.grib2
# Create an index for a GRIB2 file.
../utils/g2c_index -o GFSPRS.GrbF06.idx -l -v data/GFSPRS.GrbF06

# Summarize the index data.
#../utils/g2c_degrib2 -v -o fv3lam.t00z.prslev.f000.grib2.idx.degrib2 data/fv3lam.t00z.prslev.f000.grib2 fv3lam.t00z.prslev.f000.grib2.idx

# Check against expected output.
#diff -w fv3lam.t00z.prslev.f000.grib2.idx.degrib2 data/ref_fv3lam.t00z.prslev.f000.grib2.degrib2

echo "*** SUCCESS!"
exit 0

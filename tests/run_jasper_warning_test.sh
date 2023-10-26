#!/bin/sh
# This is a test script for the NCEPLIBS-g2c project.
#
# This script runs a simple program that uses the jasper library, and
# then compares the output to expected output, to ensure that jasper
# is not writing any warning messages to stdout.
#
# Ed Hartnett, 10/26/23

set -e
echo ""
echo "*** Running jasper warning test"
set -x
pwd
./tst_jasper_warning &> tst_jasper_warning.txt

# Check against expected output.
diff -w tst_jasper_warning.txt data/ref_tst_jasper_warning.txt

echo "*** SUCCESS!"
exit 0

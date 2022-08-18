/* This is a test for the NCEPLIBS-g2c project. This test is for the
 * g2c file functions, working on the GRIB2 sample file (optionally)
 * downloaded from the NOAA EMC FTP site.
 *
 * Ed Hartnett 8/18/22
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define FILE_NAME "WW3_Regional_US_West_Coast_20220718_0000.grib2"

int
main()
{
    printf("Testing g2c file functions with test files downloaded from NOAA EMC FTP site.\n");
    printf("Testing g2c_open()/g2c_close() calls...");
    {
	int g2cid;
	int ret;
	
	if ((ret = g2c_open(FILE_NAME, 0, &g2cid)))
	    return ret;
	if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

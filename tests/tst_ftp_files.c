/* This is a test for the NCEPLIBS-g2c project. This test is for the
 * g2c file functions, working on the GRIB2 sample file (optionally)
 * downloaded from the NOAA EMC FTP site.
 *
 * Ed Hartnett 8/18/22
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

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
    printf("Testing G2C_MAX_FILES...");
    {
	int g2cid[G2C_MAX_FILES], g2cid2;
	int i;
	int ret;

	/* Open max number of files. */
	for (i = 0; i < G2C_MAX_FILES; i++)
	    if ((ret = g2c_open(FILE_NAME, 0, &g2cid[i])))
		return ret;

	/* Try to open one more. */
	if (g2c_open(FILE_NAME, 0, &g2cid2) != G2C_ETOOMANYFILES)
	    return G2C_ERROR;

    	/* Close all open files. */
	for (i = 0; i < G2C_MAX_FILES; i++)
	    if ((ret = g2c_close(g2cid[i])))
		return ret;
    }
    printf("ok!\n");
    printf("Testing g2c_find_msg on file %s...", FILE_NAME);
    {
	int g2cid;
	size_t bytes_to_msg, bytes_in_msg;
	int ret;

	g2c_set_log_level(4);
	if ((ret = g2c_open(FILE_NAME, 0, &g2cid)))
	    return ret;
	if ((ret = g2c_find_msg(g2cid, 0, 1024, &bytes_to_msg, &bytes_in_msg)))
	    return ret;
	printf("bytes_to_msg %ld bytes_in_msg %ld\n", bytes_to_msg, bytes_in_msg);
	/* if (bytes_to_msg != 202 || bytes_in_msg != 267) */
	/*     return G2C_ERROR; */
	if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

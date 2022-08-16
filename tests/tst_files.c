/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c file functions.
 *
 * Ed Hartnett 8/16/22
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define FILE_NAME "tst_files.grib2"

int
main()
{
    printf("Testing g2c file functions.\n");
    printf("Testing g2c_create()/g2c_open()/g2c_close() calls...");
    {
	int g2cid;
	int ret;
	
	if ((ret = g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid)))
	    return ret;
	if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

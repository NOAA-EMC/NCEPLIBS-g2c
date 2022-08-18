/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c file functions.
 *
 * Ed Hartnett 8/16/22
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define FILE_NAME "tst_files.grib2"

int
main()
{
    printf("Testing g2c file functions.\n");
    printf("Testing g2c_create()/g2c_close() calls...");
    {
	int g2cid;
	int ret;
	
	if ((ret = g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid)))
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

	/* Create max number of files. */
	for (i = 0; i < G2C_MAX_FILES; i++)
	    if ((ret = g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid[i])))
		return ret;

	/* Try to create one more. */
	if (g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid2) != G2C_ETOOMANYFILES)
	    return G2C_ERROR;

    	/* Close all open files. */
	for (i = 0; i < G2C_MAX_FILES; i++)
	    if ((ret = g2c_close(g2cid[i])))
		return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

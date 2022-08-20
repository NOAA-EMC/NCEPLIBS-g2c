/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c file functions.
 *
 * Ed Hartnett 8/16/22
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define FILE_NAME "tst_files.grib2"
#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"
#define NUM_BUF_SIZE_TESTS 6

int
main()
{
    printf("Testing g2c file functions.\n");
    printf("Testing g2c_create()/g2c_close() calls...");
    {
	int g2cid;
	int ret;

	/* Create a file and close it. */
	if ((ret = g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid)))
	    return ret;
	if ((ret = g2c_close(g2cid)))
	    return ret;

	/* Now try to re-create with NOCLOBBER. It will fail. */
	if (g2c_create(FILE_NAME, G2C_NOCLOBBER, &g2cid) != G2C_EFILE)
	    return G2C_ERROR;
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
    printf("Testing g2c_get_msg on file %s...", WAVE_FILE);
    {
	int g2cid;
	size_t bytes_to_msg, bytes_in_msg;
	size_t test_buf_size[NUM_BUF_SIZE_TESTS] = {100, 200, 1024, 2000, 3000, 4000};
	unsigned char *cbuf = NULL;
	int i;
	int ret;

	/* g2c_set_log_level(4); */
	if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
	    return ret;
	for (i = 0; i < NUM_BUF_SIZE_TESTS; i++)
	{
	    /* g2int listsec0[3], listsec1[13], numfields, numlocal; */
	    
	    if ((ret = g2c_get_msg(g2cid, 0, test_buf_size[i], &bytes_to_msg, &bytes_in_msg,
				   &cbuf)))
		return ret;
	    /* printf("bytes_to_msg %ld bytes_in_msg %ld\n", bytes_to_msg, bytes_in_msg); */
	    if (bytes_to_msg != 0 || bytes_in_msg != 15254)
		return G2C_ERROR;

	    /* Learn about this message. */
	    /* if ((ret = g2_info(cbuf, listsec0, listsec1, &numfields, &numlocal))) */
	    /* 	return G2C_EMSG; */
	    
	    
	    free(cbuf);
	}
	if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("Testing g2c_find_msg2 on file %s...", WAVE_FILE);
    {
	int g2cid;
	size_t bytes_to_msg, bytes_in_msg;
	size_t test_buf_size[NUM_BUF_SIZE_TESTS] = {100, 200, 1024, 2000, 3000, 4000};
	int i;
	int ret;

	/* g2c_set_log_level(4); */
	if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
	    return ret;
	for (i = 0; i < NUM_BUF_SIZE_TESTS; i++)
	{
	    if ((ret = g2c_find_msg2(g2cid, 0, test_buf_size[i], &bytes_to_msg, &bytes_in_msg)))
		return ret;
	    /* printf("bytes_to_msg %ld bytes_in_msg %ld\n", bytes_to_msg, bytes_in_msg); */
	    if (bytes_to_msg != 0 || bytes_in_msg != 15254)
		return G2C_ERROR;
	}
	if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

/* This is a test for the NCEPLIBS-g2c project. 
 *
 * This test is for the g2c_write_index()/g2c_read_index() functions,
 * which write and read and index file that contians the byte offsets
 * to various parts of a GRIB2 file.
 *
 * Ed Hartnett 10/13/22
 */
#include "grib2_int.h"

#define FILE_NAME "tst_index.txt"
#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"
#define REF_FILE "ref_gdaswave.t00z.wcoast.0p16.f000.grb2index"
#define DEGRIB2_FILE "gdaswave.t00z.wcoast.0p16.f000.degrib2"

int
main()
{
    printf("Testing g2c index functions.\n");
#ifdef JPEG
    printf("Testing g2c_read_index() on file %s...", WAVE_FILE);
    {
	int g2cid;
        int num_msg;
	int ret;

	/* Will not work. */
	if (g2c_read_index(NULL, NULL, 0, &g2cid) != G2C_EINVAL)
	    return G2C_ERROR;
	if (g2c_read_index("bad", NULL, 0, &g2cid) != G2C_EINVAL)
	    return G2C_ERROR;
	if (g2c_read_index("bad", "bad", 0, &g2cid) != G2C_EFILE)
	    return G2C_ERROR;

	g2c_set_log_level(10);
	/* Open the data file using the index file. */
	if ((ret = g2c_read_index(WAVE_FILE, REF_FILE, 0, &g2cid)))
	    return ret;

        /* Check some stuff. */
	/* This will work. */
	g2c_set_log_level(10);
	if ((ret = g2c_read_index(WAVE_FILE, REF_FILE, 0, &g2cid)))
	    return ret;
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;

        /* Output a degrib2 file. See tst_index.c for a version of
         * this test that also checks the degrib2 output for
         * correctness. For this test, we just ensure it runs without
         * error. */
        if ((ret = g2c_degrib2(g2cid, DEGRIB2_FILE)))
            return ret;

        /* Close the file. */
	if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
#endif
    printf("SUCCESS!\n");
    return 0;
}


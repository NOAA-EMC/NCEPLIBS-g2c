/* This is a test for the NCEPLIBS-g2c project.
 *
 * This test is for the g2c_degrib2() function, which prints a summary
 * of the GRIB2 file.
 *
 * Ed Hartnett 9/17/22
 */
#include "g2ctest.h"
#include "grib2_int.h"
#include <libgen.h>

#define FILE_NAME "tst_degrib2.txt"
#define WAVE_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2"
#define REF_FILE "data/ref_gdaswave.degrib2.txt"
#define DEGRIB2_FILE "gdaswave.t00z.wcoast.0p16.f000.degrib2"
#define REF_INDEX_FILE "data/ref_gdaswave.t00z.wcoast.0p16.f000.grb2index"
#define TEST_INDEX_FILE "tst_gdaswave.t00z.wcoast.0p16.f000.grb2index"

int
main()
{
    printf("Testing g2c degrib2 function.\n");
#ifdef JPEG
    printf("Testing g2c_degrib2() on file %s...", WAVE_FILE);
    {
        int g2cid;
        int ret;

        if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
            return ret;
        if ((ret = g2c_degrib2(g2cid, FILE_NAME)))
            return ret;
        if ((ret = g2c_close(g2cid)))
            return ret;

        if ((ret = compare_degrib2_files2(FILE_NAME, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
    printf("Testing g2c_open_index() to make a degrib2 file...");
    {
        int g2cid;
        int num_msg;
        int ret;

        /* g2c_set_log_level(10); */
        /* Open the data file using the index file. */
        if ((ret = g2c_open_index(WAVE_FILE, REF_INDEX_FILE, 0, &g2cid)))
            return ret;

        /* Check some stuff. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;

        /* Output a degrib2 file. */
        if ((ret = g2c_degrib2(g2cid, DEGRIB2_FILE)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Compare the degrib2 output to our reference file. */
        if ((ret = compare_degrib2_files2(DEGRIB2_FILE, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
    printf("Testing g2c_write_index() make an index and then to make a degrib2 file from it...");
    {
        int g2cid;
        int num_msg;
        int ret;

        /* g2c_set_log_level(10); */
        /* Open the data file using the index file. */
        if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
            return ret;

        /* Check some stuff. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;

        /* Write an index file. */
        if ((ret = g2c_write_index(g2cid, G2C_CLOBBER, TEST_INDEX_FILE)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Reopen the data file, using the index we just generated. */
        if ((ret = g2c_open_index(WAVE_FILE, TEST_INDEX_FILE, 0, &g2cid)))
            return ret;

        /* Output a degrib2 file. */
        if ((ret = g2c_degrib2(g2cid, DEGRIB2_FILE)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Compare the degrib2 output to our reference file. */
        if ((ret = compare_degrib2_files2(DEGRIB2_FILE, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
#endif /* JPEG */
    printf("SUCCESS!\n");
    return 0;
}

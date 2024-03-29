/* This is a test for the NCEPLIBS-g2c project.
 *
 * This test is for the GRIB1 index functionality.
 *
 * Ed Hartnett 9/10/23
 */
#include "grib2_int.h"

#define GRIB1_INDEX_FILE "data/ref_gdaswave_2.grib1.idx"

int
main()
{
    printf("Testing g2c GRIB1 index functions.\n");
    printf("Testing g2c_open_index1() on file %s...", GRIB1_INDEX_FILE);
    {
        int ret;

        /* Will not work. */
        if (g2c_open_index1(NULL) != G2C_EINVAL)
            return G2C_ERROR;

        /* Open the index file. */
        /* g2c_set_log_level(10); */
        if ((ret = g2c_open_index1(GRIB1_INDEX_FILE)))
            return ret;

        /* /\* Check some stuff. *\/ */
        /* if ((ret = g2c_inq(g2cid, &num_msg))) */
        /*     return ret; */
        /* if (num_msg != 19) */
        /*     return G2C_ERROR; */

        /* /\* Output a degrib2 file. See tst_degrib2.c for a version of */
        /*  * this test that also checks the degrib2 output for */
        /*  * correctness. For this test, we just ensure it runs without */
        /*  * error. *\/ */
        /* if ((ret = g2c_degrib2(g2cid, DEGRIB2_FILE))) */
        /*     return ret; */

        /* /\* Close the file. *\/ */
        /* if ((ret = g2c_close(g2cid))) */
        /*     return ret; */
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

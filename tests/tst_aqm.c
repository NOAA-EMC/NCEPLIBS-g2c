/* This is a test for the NCEPLIBS-g2c project. This test is for the
 * g2c file functions using test file gdas.t12z.pgrb2.1p00.anl.grib2
 * from FTP.
 *
 * Ed Hartnett 11/19/22
 */

#include "grib2_int.h"

#define AQM_DEGRIB2 "aqm.t12z.max_8hr_o3.227.degrib2"
#define AQM_FILE "data/aqm.t12z.max_8hr_o3.227.grib2"

int
main()
{
    printf("Testing g2c file functions.\n");
    printf("Testing g2c_open() on file %s...", AQM_FILE);
    {
        int g2cid;
        int ret;

        /* Open the data file. */
        if ((ret = g2c_open(AQM_FILE, 0, &g2cid)))
            return ret;

        /* Produce degrib2 output. */
        if ((ret = g2c_degrib2(g2cid, AQM_DEGRIB2)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

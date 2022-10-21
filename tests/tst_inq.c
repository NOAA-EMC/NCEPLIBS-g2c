/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c inquiry functions.
 *
 * Ed Hartnett 10/21/22
 */

#include "grib2_int.h"

#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"

int
main()
{
    printf("Testing g2c inquiry functions.\n");
    printf("Testing g2c_inq()/g2c_inq_msg() calls...");
    {
        int g2cid;
        int num_msg;
        int m;
        int ret;

        /* Open our test file. */
	if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
	    return ret;

        /* Check values. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;

        for (m = 0; m < num_msg; m++)
        {
            int num_fields, num_local;
            unsigned char discipline;
            
            if ((ret = g2c_inq_msg(g2cid, m, &discipline, &num_fields, &num_local)))
                return ret;
            printf("msg %d discipline %d num_fields %d num_local %d\n", m, discipline, num_fields, num_local);
            if (num_local || num_fields != 1 || discipline != (m < 4 ? 0 : 10))
                return G2C_ERROR;
        }

        /* Close the file. */
        if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

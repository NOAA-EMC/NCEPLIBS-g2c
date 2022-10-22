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
    printf("Testing g2c_inq()/g2c_inq_msg()/g2c_inq_prod() calls...");
    {
        int g2cid;
        int num_msg;
        int m;
        int ret;

        /* Open our test file. */
	if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
	    return ret;

        /* This works but does nothing. */
        if ((ret = g2c_inq(g2cid, NULL)))
            return ret;
        
        /* Check values. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;

        /* This works but does nothing. */
        if ((ret = g2c_inq_msg(g2cid, 0, NULL, NULL, NULL)))
            return ret;
        
        for (m = 0; m < num_msg; m++)
        {
            int num_fields, num_local;
            unsigned char discipline;

            /* Inquire about this message. */
            if ((ret = g2c_inq_msg(g2cid, m, &discipline, &num_fields, &num_local)))
                return ret;
            printf("msg %d discipline %d num_fields %d num_local %d\n", m, discipline, num_fields, num_local);
            /* Check results. */
            if (num_local || num_fields != 1 || discipline != (m < 4 ? 0 : 10))
                return G2C_ERROR;

            {
                int pds_template_len, gds_template_len, drs_template_len;
                int pds_template[G2C_MAX_PDS_TEMPLATE_MAPLEN];
                int gds_template[G2C_MAX_GDS_TEMPLATE_MAPLEN];
                int drs_template[G2C_MAX_DRS_TEMPLATE_MAPLEN];
                
                /* Each message in the test file has one product. Inqure
                 * about it. */
                if ((ret = g2c_inq_prod(g2cid, m, 0, &pds_template_len, pds_template,
                                        &gds_template_len, gds_template, &drs_template_len,
                                        drs_template)))
                    return ret;
            }
        }

        /* Close the file. */
        if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

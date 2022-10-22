/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c inquiry functions.
 *
 * Ed Hartnett 10/21/22
 */

#include "grib2_int.h"

#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"
#define NUM_MSG 19

int
main()
{
    printf("Testing g2c inquiry functions.\n");
    printf("Testing g2c_inq()/g2c_inq_msg()/g2c_inq_prod() calls...\n");
    {
        int g2cid;
        int num_msg;
        int m;
        int ret;

        /* Open our test file. */
	if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
	    return ret;

        /* These won't work - bad file ID. */
        if (g2c_inq(-1, NULL) != G2C_EBADID)
            return G2C_ERROR;
        if (g2c_inq(G2C_MAX_FILES + 1, NULL) != G2C_EBADID)
            return G2C_ERROR;
        if (g2c_inq(10, NULL) != G2C_EBADID)
            return G2C_ERROR;

        /* This works but does nothing. */
        if ((ret = g2c_inq(g2cid, NULL)))
            return ret;
        
        /* Check values. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != NUM_MSG)
            return G2C_ERROR;

        /* These won't work - bad file ID. */
        if (g2c_inq_msg(-1, 0, NULL, NULL, NULL) != G2C_EBADID)
            return G2C_ERROR;
        if (g2c_inq_msg(10, 0, NULL, NULL, NULL) != G2C_EBADID)
            return G2C_ERROR;
        if (g2c_inq_msg(G2C_MAX_FILES + 1, 0, NULL, NULL, NULL) != G2C_EBADID)
            return G2C_ERROR;

        /* This won't work - bad msg number. */
        if (g2c_inq_msg(g2cid, NUM_MSG, NULL, NULL, NULL) != G2C_ENOMSG)
            return G2C_ERROR;

        /* This works but does nothing. */
        if ((ret = g2c_inq_msg(g2cid, 0, NULL, NULL, NULL)))
            return ret;

        /* These won't work - bad file number. */
        if (g2c_inq_prod(-1, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
            return G2C_ERROR;
        if (g2c_inq_prod(10, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
            return G2C_ERROR;
        if (g2c_inq_prod(G2C_MAX_FILES + 1, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
            return G2C_ERROR;

        /* This won't work - bad msg number. */
        if (g2c_inq_prod(g2cid, NUM_MSG, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_ENOMSG)
            return G2C_ERROR;
        
        /* This won't work - bad prod number. */
        if (g2c_inq_prod(g2cid, 0, 1, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_ENOPRODUCT)
            return G2C_ERROR;

        /* This works but does nothing. */
        if ((ret = g2c_inq_prod(g2cid, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL)))
            return ret;

        /* Check each message. */
        for (m = 0; m < num_msg; m++)
        {
            int num_fields, num_local;
            unsigned char discipline;
            int pds_template_len, gds_template_len, drs_template_len;
            int pds_template[G2C_MAX_PDS_TEMPLATE_MAPLEN];
            int gds_template[G2C_MAX_GDS_TEMPLATE_MAPLEN];
            int drs_template[G2C_MAX_DRS_TEMPLATE_MAPLEN];
            int expected_pds_template[NUM_MSG][G2C_MAX_PDS_TEMPLATE_MAPLEN] = {
                {2, 1, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},
                {2, 0, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},  
                {2, 2, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},  
                {2, 3, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},  
                {0, 3, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},  
                {0, 11, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0}, 
                {0, 10, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0}, 
                {0, 5, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},  
                {0, 8, 2, 0, 11, 0, 0, 1, 0, 241, 0, 1, 255, 0, 0},
                {0, 8, 2, 0, 11, 0, 0, 1, 0, 241, 0, 2, 255, 0, 0},
                {0, 8, 2, 0, 11, 0, 0, 1, 0, 241, 0, 3, 255, 0, 0},
                {0, 6, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},  
                {0, 9, 2, 0, 11, 0, 0, 1, 0, 241, 0, 1, 255, 0, 0},
                {0, 9, 2, 0, 11, 0, 0, 1, 0, 241, 0, 2, 255, 0, 0},
                {0, 9, 2, 0, 11, 0, 0, 1, 0, 241, 0, 3, 255, 0, 0},
                {0, 4, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},  
                {0, 7, 2, 0, 11, 0, 0, 1, 0, 241, 0, 1, 255, 0, 0},
                {0, 7, 2, 0, 11, 0, 0, 1, 0, 241, 0, 2, 255, 0, 0},
                {0, 7, 2, 0, 11, 0, 0, 1, 0, 241, 0, 3, 255, 0, 0}
            };
            int p;

            /* Inquire about this message. */
            if ((ret = g2c_inq_msg(g2cid, m, &discipline, &num_fields, &num_local)))
                return ret;

            /* Check results. */
            if (num_local || num_fields != 1 || discipline != (m < 4 ? 0 : 10))
                return G2C_ERROR;

            /* Each message in the test file has one product. Inqure
             * about it. */
            if ((ret = g2c_inq_prod(g2cid, m, 0, &pds_template_len, pds_template,
                                    &gds_template_len, gds_template, &drs_template_len,
                                    drs_template)))
                return ret;
            printf("pds_template_len %d pds_template {", pds_template_len);
            for (p = 0; p < pds_template_len; p++)
                printf("%d%s", pds_template[p], (p < pds_template_len - 1) ? ", " : "");
            printf("}\n");
            
            /* Check results. */
            if (pds_template_len != 15)
                return G2C_ERROR;
            for (p = 0; p < pds_template_len; p++)
                if (pds_template[p] != expected_pds_template[m][p])
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

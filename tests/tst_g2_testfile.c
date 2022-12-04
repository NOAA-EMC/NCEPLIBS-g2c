/* This is a test for the NCEPLIBS-g2c project. This test reads a test
 * file produced by the tests of the NCEPLIBS-g2 library.
 *
 * Ed Hartnett 12/2/22
 */

#include "g2ctest.h"
#include "grib2_int.h"

#define FILENAME "data/testgrib2.grb2"
#define DEGRIB2_FILENAME "testgrib2.grb2.degrib2"
#define REF_FILENAME "data/ref_testgrib2.grb2.degrib2"
#define PDSLEN 15
#define GDSLEN 19
#define DRSLEN 5

int
main()
{
    printf("Testing with file created in NCEPLIBS-g2.\n");
    printf("testing opening of the file...");
    {
        int g2cid;
        int num_msg;
        unsigned char discipline;
        int num_fields, num_local;
        short center, subcenter;
        unsigned char master_version, local_version;
        unsigned char sig_ref_time;
        short year;
        unsigned char month, day, hour, minute, second;
        int pds_template_len, pds_template[PDSLEN], gds_template_len, gds_template[GDSLEN];
        int drs_template_len, drs_template[DRSLEN];
        int expected_pds[PDSLEN] = {0, 0, 0, 0, 0, 12, 59, 0, 0, 1, 1, 1, 2, 1, 1};
        int expected_gds[GDSLEN] = {0, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 45, 91, 0, 55, 101, 5, 5, 0};
        int expected_drs[DRSLEN] = {1093664768, 1, 1, 8, 0};
        int i;
        int ret;

        /* g2c_set_log_level(20); */
        
        /* Open test file. */
        if ((ret = g2c_open(FILENAME, 0, &g2cid)))
            return ret;

        /* Check results. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 1)
            return G2C_ERROR;
        if ((ret = g2c_inq_msg(g2cid, 0, &discipline, &num_fields, &num_local, &center,
                               &subcenter, &master_version, &local_version)))
            return ret;
        if (discipline != 0 || num_fields != 1 || num_local != 1 || center != 7 ||
            subcenter != 4 || master_version != 2 || local_version != 24)
            return G2C_ERROR;
        /* printf("%d %d %d %d %d %d %d\n", discipline, num_fields, num_local, center, */
        /*        subcenter, master_version, local_version); */
        if ((ret = g2c_inq_msg_time(g2cid, 0, &sig_ref_time, &year,
                                    &month, &day, &hour, &minute, &second)))
            return ret;
        /* printf("%d %d %d %d %d %d %d\n", sig_ref_time, year, */
        /*         month, day, hour, minute, second); */
        if (sig_ref_time != 0 || year != 2021 || month != 11 || day != 13 || hour != 15 ||
            minute != 59 || second != 59)
            return G2C_ERROR;
        if ((ret = g2c_inq_prod(g2cid, 0, 0, &pds_template_len, pds_template,
                                &gds_template_len, gds_template, &drs_template_len,
                                drs_template)))
            return ret;
        if (pds_template_len != PDSLEN || gds_template_len != 19 || drs_template_len != 5)
            return G2C_ERROR;
        for (i = 0; i < PDSLEN; i++)
            if (pds_template[i] != expected_pds[i])
                return G2C_ERROR;
        for (i = 0; i < GDSLEN; i++)
            if (gds_template[i] != expected_gds[i])
                return G2C_ERROR;
        for (i = 0; i < DRSLEN; i++)
            if (drs_template[i] != expected_drs[i])
                return G2C_ERROR;

        /* Close test file. */
        if ((ret = g2c_close(g2cid)))
            return ret;
    }
    printf("ok!\n");
    printf("testing opening of the file...");
    {
        int g2cid;
        int ret;

        /* g2c_set_log_level(20); */
        
        /* Open test file. */
        if ((ret = g2c_open(FILENAME, 0, &g2cid)))
            return ret;

        /* Write degrib2 output. */
        if ((ret = g2c_degrib2(g2cid, DEGRIB2_FILENAME)))
            return ret;

        /* Check results. */
        if ((ret = compare_degrib2_files2(DEGRIB2_FILENAME, REF_FILENAME)))
            return ret;
        
        /* Close test file. */
        if ((ret = g2c_close(g2cid)))
            return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

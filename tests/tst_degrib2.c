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
#define FTP_FILE "data/WW3_Regional_US_West_Coast_20220718_0000.grib2"
#define REF_FTP_INDEX_FILE "data/ref_WW3_Regional_US_West_Coast_20220718_0000.grb2index"
#define FTP_DEGRIB2_FILE "WW3_Regional_US_West_Coast_20220718_0000.degrib2"
#define REF_FTP_DEGRIB2_FILE "data/ref_WW3_Regional_US_West_Coast_20220718_0000.degrib2"

#define GDAS_FILE "data/gdas.t12z.pgrb2.1p00.anl.grib2"
#define GDAS_DEGRIB2_FILE "gdas.t12z.pgrb2.1p00.anl.degrib2"
#define REF_GDAS_DEGRIB2_FILE "data/ref_gdas.t12z.pgrb2.1p00.anl.degrib2"
#define REF_GDAS_INDEX_FILE "gdas.t12z.pgrb2.1p00.anl.grb2index"
#define GDAS_NUM_MSG 2

#define FTP_NUM_MSG 688
#define MAX_FILENAME_LEN 256
#define NUM_TESTS 2

int
main()
{
    printf("Testing g2c degrib2 function.\n");
#ifdef JPEG
#ifdef FTP_TEST_FILES
    printf("Testing degrib2 on file %s downloaded via FTP...\n", FTP_FILE);
    {
        int g2cid;
        int num_msg;
        unsigned char sig_ref_time, month, day, hour, minute, second;
        short year;
        short center, subcenter;
        unsigned char master_version, local_version;
        int num_fields, num_local;
        unsigned char discipline;
        unsigned char expected_discipline[FTP_NUM_MSG] =
            {10, 10, 10, 10, 0, 10, 10, 10, 0, 10, 10, 10, 10, 0, 10, 0, 10, 10,
             10, 0, 0, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 0, 0, 10, 10, 10,
             10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 0,
             0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 10, 10, 0, 0, 0, 0, 10, 10,
             10, 10, 10, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 0, 10, 10, 10,
             10, 10, 0, 10, 0, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10, 10, 0,
             10, 10, 10, 10, 0, 0, 0, 10, 0, 10, 10, 10, 10, 0, 10, 0, 10, 10,
             10, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 0, 10, 0, 10, 10, 10,
             0, 10, 10, 10, 0, 10, 0, 0, 10, 0, 10, 10, 10, 10, 10, 10, 10, 10,
             10, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10, 0, 10, 10, 0, 0, 10, 0,
             10, 10, 10, 0, 10, 10, 10, 10, 0, 10, 0, 10, 10, 10, 10, 0, 0, 10,
             10, 10, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 10,
             0, 0, 10, 10, 10, 0, 10, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10,
             10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 0, 10, 10, 10, 10, 10, 0,
             10, 10, 10, 0, 10, 10, 10, 0, 10, 10, 10, 0, 10, 10, 10, 0, 0, 0,
             10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 10, 0, 0, 10, 10, 10, 10,
             10, 10, 10, 0, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 0, 10,
             10, 10, 10, 0, 10, 0, 10, 10, 10, 10, 10, 10, 10, 0, 10, 10, 10,
             10, 10, 0, 0, 0, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10, 0, 10, 0,
             10, 10, 0, 10, 10, 0, 0, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10, 10,
             10, 0, 10, 10, 0, 0, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10, 10, 10,
             10, 0, 10, 10, 10, 0, 10, 0, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10,
             10, 10, 10, 0, 10, 0, 10, 10, 10, 0, 10, 10, 0, 10, 10, 0, 10, 0,
             10, 0, 10, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 10, 10, 0, 10, 10,
             0, 0, 10, 10, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10, 10, 0,
             10, 10, 10, 0, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 10, 10, 10,
             10, 10, 0, 10, 10, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 10,
             10, 10, 10, 0, 10, 0, 10, 10, 10, 0, 0, 10, 10, 10, 10, 0, 0, 10,
             10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10,
             10, 10, 0, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10,
             10, 10, 0, 10, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
             10, 10, 0, 0, 0, 10, 10, 0, 10, 0, 0, 10, 0, 10, 10, 10, 10, 0, 10,
             10, 10, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 10, 0, 10, 10, 10, 0,
             10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10,
             0, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 0, 10, 10, 0, 0, 0, 10,
             10, 10, 10, 0, 10, 10, 10, 0, 10, 0, 0, 0, 10, 0, 10, 10, 10, 10,
             10, 10, 10, 10, 0, 10, 0, 10, 0, 10, 10, 10, 10, 10, 10, 0, 10, 0,
             10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 0, 10, 10,
             10, 0, 10, 10, 10, 0, 10, 10, 10, 0, 10, 10, 10, 10};
        int t, m;
        int ret;

        for (t = 0; t < NUM_TESTS; t++)
        {
            /* g2c_set_log_level(11); */
            /* Open the data file with and without the index file. */
            if (t)
            {
                printf("\ttesting degrib2 on file %s downloaded via FTP using index...", FTP_FILE);
                if ((ret = g2c_open_index(FTP_FILE, REF_FTP_INDEX_FILE, 0, &g2cid)))
                    return ret;
            }
            else
            {
                printf("\ttesting degrib2 on file %s downloaded via FTP without using index...", FTP_FILE);
                if ((ret = g2c_open(FTP_FILE, 0, &g2cid)))
                    return ret;
            }

            /* Check some stuff. */
            if ((ret = g2c_inq(g2cid, &num_msg)))
                return ret;
            if (num_msg != FTP_NUM_MSG)
                return G2C_ERROR;

            /* Check some stuff in all messages. */
            for (m = 0; m < num_msg; m++)
            {
                if ((ret = g2c_inq_msg(g2cid, m, &discipline, &num_fields, &num_local,
                                       &center, &subcenter, &master_version, &local_version)))
                    return ret;
                if (center != 7 || subcenter != 0 || master_version != 2 || local_version != 1)
                    return G2C_ERROR;
                if (num_fields != 1 || num_local)
                    return G2C_ERROR;
                if (discipline != expected_discipline[m])
                    return G2C_ERROR;
            }

            /* Check some stuff about the last message. */
            if ((ret = g2c_inq_msg(g2cid, 687, &discipline, &num_fields, &num_local,
                                   &center, &subcenter, &master_version, &local_version)))
                return ret;
            if (center != 7 || subcenter != 0 || master_version != 2 || local_version != 1)
                return G2C_ERROR;
            if (num_local || num_fields != 1 || discipline != 10)
                return G2C_ERROR;

            /* Inquire about the date/time. */
            if ((ret = g2c_inq_msg_time(g2cid, 687, &sig_ref_time, &year, &month, &day, &hour,
                                        &minute, &second)))
                return ret;

            /* Check date/time. */
            if (sig_ref_time != 1 || year != 2022 || month != 7 || day != 18 ||
                hour != 0 || minute != 0 || second != 0)
                return G2C_ERROR;

            /* Output a degrib2 file. */
            if ((ret = g2c_degrib2(g2cid, FTP_DEGRIB2_FILE)))
                return ret;

            /* Close the file. */
            if ((ret = g2c_close(g2cid)))
                return ret;

            /* Compare the degrib2 output to our reference file. */
            if ((ret = compare_degrib2_files2(FTP_DEGRIB2_FILE, REF_FTP_DEGRIB2_FILE)))
                return ret;

            printf("\tok!\n");
        }
    }
    printf("ok!\n");
    printf("Testing degrib2 on file %s downloaded via FTP...\n", GDAS_FILE);
    {
        int g2cid;
        int num_msg;
        int t;
        int ret;

        /* for (t = 0; t < NUM_TESTS; t++) */
        for (t = 0; t < 1; t++)
        {
            /* Open the data file with and without the index file. */
            if (t)
            {
                printf("\ttesting degrib2 on file %s downloaded via FTP using index...", GDAS_FILE);
                if ((ret = g2c_open_index(GDAS_FILE, REF_GDAS_INDEX_FILE, 0, &g2cid)))
                    return ret;
            }
            else
            {
                printf("\ttesting degrib2 on file %s downloaded via FTP without using index...", GDAS_FILE);
                if ((ret = g2c_open(GDAS_FILE, 0, &g2cid)))
                    return ret;
            }

            /* Check some stuff. */
            if ((ret = g2c_inq(g2cid, &num_msg)))
                return ret;
            if (num_msg != GDAS_NUM_MSG)
                return G2C_ERROR;

            /* Output a degrib2 file. */
            if ((ret = g2c_degrib2(g2cid, GDAS_DEGRIB2_FILE)))
                return ret;

            /* Close the file. */
            if ((ret = g2c_close(g2cid)))
                return ret;

            /* Compare the degrib2 output to our reference file. */
            if ((ret = compare_degrib2_files2(GDAS_DEGRIB2_FILE, REF_GDAS_DEGRIB2_FILE)))
                return ret;

            printf("\tok!\n");
        }
    }
    printf("ok!\n");
#endif /* FTP_TEST_FILES */
#endif /* JPEG */
    printf("SUCCESS!\n");
    return 0;
}

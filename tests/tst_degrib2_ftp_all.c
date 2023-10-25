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

#define NUM_TESTS 2

int
main()
{
    printf("Testing g2c degrib2 function.\n");
#ifdef JPEG
#ifdef FTP_TEST_FILES
    printf("Testing degrib2 on files downloaded via FTP...\n");
    {
#define NUM_FILES 10
        char file[NUM_FILES][MAX_FILENAME_LEN + 1] = {
            "data/blend.t19z.core.f001.co.grib2", "data/cmc_geavg.t12z.pgrb2a.0p50.f000",
            "data/flxf2022111712.01.2022111712.grb2", "data/GLOBAL.grib2.2022103000.0000",
            "data/hiresw.t00z.arw_5km.f00.hi.grib2", "data/naefs_ge10pt.t12z.pgrb2a.0p50_bcf003",
            "data/rap.t00z.awp130pgrbf00.grib2", "data/seaice.t00z.grb.grib2",
            "data/sgx_nwps_CG3_20221117_1200.grib2", "data/aqm.t12z.max_8hr_o3.227.grib2"
        };
        int g2cid;
        int num_msg;
        int f;
        int t;
        int ret;

        /* for (f = 0; f < NUM_FILES; f++) */
        for (f = 0; f < 9; f++)
        {
            for (t = 0; t < 1; t++)
            {
                char degrib2_file[MAX_FILENAME_LEN + 9];
                char ref_degrib2_file[MAX_FILENAME_LEN + 20];
                
                /* Open the data file with and without the index file. */
                if (t)
                {
                    /* printf("\ttesting degrib2 on file %s downloaded via FTP using index...", file[f]); */
                    /* if ((ret = g2c_open_index(file[f], REF_GDAS_INDEX_FILE, 0, &g2cid))) */
                    /*     return ret; */
                }
                else
                {
                    printf("\ttesting degrib2 on file %s downloaded via FTP without using index...", file[f]);
                    if ((ret = g2c_open(file[f], 0, &g2cid)))
                        return ret;
                }
                
                /* Check some stuff. */
                if ((ret = g2c_inq(g2cid, &num_msg)))
                    return ret;
                printf("num_msg %d\n", num_msg);
                
                /* Output a degrib2 file. */
                /* g2c_set_log_level(15); */
                sprintf(degrib2_file, "%s.degrib2", basename(file[f]));
                if ((ret = g2c_degrib2(g2cid, degrib2_file)))
                    return ret;
                
                /* Close the file. */
                if ((ret = g2c_close(g2cid)))
                    return ret;
                
                /* Compare the degrib2 output to our reference file. */
                sprintf(ref_degrib2_file, "data/ref_%s.degrib2", basename(file[f]));
                if ((ret = compare_degrib2_files2(degrib2_file, ref_degrib2_file)))
		{
		    printf("compare failed!\n");
		    return ret;
		}
            }
            printf("\tok!\n");
        }
    }
    printf("ok!\n");
#ifdef LARGE_FTP_TESTS
    printf("Testing degrib2 on very large files downloaded via FTP...\n");
    {
#define NUM_LARGE_FILES 1
        char file[NUM_LARGE_FILES][MAX_FILENAME_LEN + 1] = {
            "data/fv3lam.t00z.prslev.f000.grib2"
        };
        int g2cid;
        int num_msg;
        int f;
        int t;
        int ret;

        /* g2c_set_log_level(10); */
        for (f = 0; f < NUM_LARGE_FILES; f++)
        {
            /* for (t = 0; t < 2; t++) */
            for (t = 0; t < 1; t++)
            {
                char degrib2_file[MAX_FILENAME_LEN + 9];
                char ref_degrib2_file[MAX_FILENAME_LEN + 20];
                
                /* Open the data file with and without the index file. */
                if (t)
                {
                    printf("\ttesting degrib2 on file %s downloaded via FTP using index...", file[f]);
                    /* if ((ret = g2c_open_index(file[f], REF_GDAS_INDEX_FILE, 0, &g2cid))) */
                    /*     return ret; */
                }
                else
                {
                    printf("\ttesting degrib2 on file %s downloaded via FTP without using index...", file[f]);
                    if ((ret = g2c_open(file[f], 0, &g2cid)))
                        return ret;
                }
                
                /* Check some stuff. */
                if ((ret = g2c_inq(g2cid, &num_msg)))
                    return ret;
                printf("num_msg %d\n", num_msg);
                /* if (num_msg != GDAS_NUM_MSG) */
                /*     return G2C_ERROR; */
                
                /* Output a degrib2 file. */
                /* g2c_set_log_level(15); */
                sprintf(degrib2_file, "%s.degrib2", basename(file[f]));
                if ((ret = g2c_degrib2(g2cid, degrib2_file)))
                    return ret;
                
                /* Close the file. */
                if ((ret = g2c_close(g2cid)))
                    return ret;
                
                /* Compare the degrib2 output to our reference file. */
                sprintf(ref_degrib2_file, "data/ref_%s.degrib2", basename(file[f]));
                if ((ret = compare_degrib2_files2(degrib2_file, ref_degrib2_file)))
                    return ret;
            }
            printf("\tok!\n");
        }
    }
    printf("ok!\n");
#endif /* LARGE_FTP_TESTS */
#endif /* FTP_TEST_FILES */
#endif /* JPEG */
    printf("SUCCESS!\n");
    return 0;
}

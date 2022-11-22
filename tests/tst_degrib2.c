/* This is a test for the NCEPLIBS-g2c project.
 *
 * This test is for the g2c_degrib2() function, which prints a summary
 * of the GRIB2 file.
 *
 * Ed Hartnett 9/17/22
 */
#include "grib2_int.h"

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

#define MAX_LINE_LEN 256
#define MAX_VALUE_LEN 25
#define NUM_MATCHING 5
#define FTP_NUM_MSG 688

/* Return 0 if two lines of the DEGRIB2 output are euqal.
 *
 * For most lines this means they must be exactly equal. Lines that
 * show the min, avg, and max values may be slightly different from
 * the reference file, because the intel compiler produces slight
 * different results.
 *
 * Ed Hartnett 10/6/22
 */
int
degrib2_lines_not_equal(char *l1, char *l2)
{
    char abbrev1[G2C_MAX_NOAA_ABBREV_LEN + 1];
    char abbrev2[G2C_MAX_NOAA_ABBREV_LEN + 1];
    char cmin1[MAX_VALUE_LEN + 1], cavg1[MAX_VALUE_LEN + 1], cmax1[MAX_VALUE_LEN + 1];
    char cmin2[MAX_VALUE_LEN + 1], cavg2[MAX_VALUE_LEN + 1], cmax2[MAX_VALUE_LEN + 1];

    /* If the lines are the same, we're done. */
    if (!strcmp(l1, l2))
        return 0;

    /* If the lines are different, is it a line like this:
       ( PARM= WIND ) :  MIN=               0.09999998 AVE=               5.64625024 MAX=              16.43000032
    */
    if (sscanf(l1, "( PARM= %s ) :  MIN=               %s AVE=               %s MAX=              %s", abbrev1, cmin1, cavg1, cmax1) == 4)
    {
        if (sscanf(l2, "( PARM= %s ) :  MIN=               %s AVE=               %s MAX=              %s", abbrev2, cmin2, cavg2, cmax2) != 4)
            return G2C_ERROR;
        printf("\nabbrev1 %s min1 %s avg1 %s max1 %s\n", abbrev1, cmin1, cavg1, cmax1);
        printf("abbrev2 %s min2 %s avg2 %s max2 %s\n", abbrev2, cmin2, cavg2, cmax2);
        if (strcmp(abbrev1, abbrev2))
            return G2C_ERROR;
        if (strncmp(cmin1, cmin2, NUM_MATCHING))
            return G2C_ERROR;
        if (strncmp(cavg1, cavg2, NUM_MATCHING))
            return G2C_ERROR;
        if (strncmp(cmax1, cmax2, NUM_MATCHING))
            return G2C_ERROR;
    }
    else
    {
        printf("\n%s\n", l1);
        printf("expected:\n%s\n", l2);
        return G2C_ERROR;
    }

    return G2C_NOERROR;
}

/* Return 0 if two files are the same.
 *
 * Ed Hartnett 10/6/22
 */
int
compare_files2(char *fname1, char *fname2)
{
    FILE *fp1, *fp2;
    char l1[MAX_LINE_LEN], l2[MAX_LINE_LEN];

    /* Open the two files. */
    if (!(fp1 = fopen(fname1, "r")))
        return G2C_ERROR;
    if (!(fp2 = fopen(fname2, "r")))
        return G2C_ERROR;

    /* Check each line in the file. */
    while (fgets(l1, MAX_LINE_LEN, fp1))
    {
        if (!fgets(l2, MAX_LINE_LEN, fp2))
            return G2C_ERROR;
        /* printf("l1: %s\n", l1); */
        /* printf("l2: %s\n", l2); */
        if (degrib2_lines_not_equal(l1, l2))
            return G2C_ERROR;
    }

    /* Close files. */
    fclose(fp1);
    fclose(fp2);

    return G2C_NOERROR;
}

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

        if ((ret = compare_files2(FILE_NAME, REF_FILE)))
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
        if ((ret = compare_files2(DEGRIB2_FILE, REF_FILE)))
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
        if ((ret = compare_files2(DEGRIB2_FILE, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
#ifdef FTP_TEST_FILES
#define NUM_TESTS 2
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
            if ((ret = compare_files2(FTP_DEGRIB2_FILE, REF_FTP_DEGRIB2_FILE)))
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
            if ((ret = compare_files2(GDAS_DEGRIB2_FILE, REF_GDAS_DEGRIB2_FILE)))
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

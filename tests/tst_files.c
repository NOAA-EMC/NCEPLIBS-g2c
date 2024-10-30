/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c file functions.
 *
 * Ed Hartnett 8/16/22
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "tst_files.grib2"
#define WAVE_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2"
#define GDAS_FILE "data/gdas.t12z.pgrb2.1p00.anl.grib2"
#define NUM_BUF_SIZE_TESTS 6
#define EPSILON (.1)

/* Test opening and closing the same file twice. */
void *
tst_g2c_open_twice(void *t)
{
    int g2cid;
    int ret = G2C_NOERROR;

    /* if (t) */
    /*     printf("runnning thread %d\n", *(int *)t); */

    /* g2c_set_log_level(10); */
    ret = g2c_open(WAVE_FILE, 0, &g2cid);
    if (!ret)
        ret = g2c_close(g2cid);

    /* Try it again. */
    if (!ret)
        ret = g2c_open(WAVE_FILE, 0, &g2cid);
    if (!ret)
        ret = g2c_close(g2cid);

#ifdef PTHREADS
    /* printf("ret %d\n", ret); */
    pthread_exit(&ret);
#endif

    return ret ? (void *)1 : NULL;
}

int
main()
{
    printf("Testing g2c file functions.\n");
    printf("Testing g2c_open() on file %s (twice)...", WAVE_FILE);
    {
#ifdef PTHREADS
        /* If we built with pthreads, run this test as two threads. */
        pthread_t thread1, thread2;
        int t0 = 0, t1 = 1;
        int ret = G2C_NOERROR;
        int *pret = &ret;

        /* Create independent threads each of which will execute function */
        if (pthread_create(&thread1, NULL, tst_g2c_open_twice, (void *)&t0))
            return G2C_ERROR;
        if (pthread_create(&thread2, NULL, tst_g2c_open_twice, (void *)&t1))
            return G2C_ERROR;

        /* Wait till threads are complete before main continues. Unless we  */
        /* wait we run the risk of executing an exit which will terminate   */
        /* the process and all threads before the threads have completed.   */
        if (pthread_join(thread1, (void **)&pret))
            return G2C_ERROR;
        if (pthread_join(thread2, (void **)&pret))
            return G2C_ERROR;
        if (ret)
            return G2C_ERROR;

#else
        /* No threads, run the test once. */
        if (tst_g2c_open_twice(NULL))
            return G2C_ERROR;
#endif
    }
    printf("ok!\n");
    /* printf("Testing g2c_create()/g2c_close() calls..."); */
    /* { */
    /*     int g2cid; */
    /*     int ret; */

    /*     /\* Create a file and close it. *\/ */
    /*     if ((ret = g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid))) */
    /*         return ret; */
    /*     if ((ret = g2c_close(g2cid))) */
    /*         return ret; */

    /*     /\* Now try to re-create with NOCLOBBER. It will fail. *\/ */
    /*     if (g2c_create(FILE_NAME, G2C_NOCLOBBER, &g2cid) != G2C_EFILE) */
    /*         return G2C_ERROR; */
    /* } */
    /* printf("ok!\n"); */
    /* printf("Testing G2C_MAX_FILES..."); */
    /* { */
    /*     int g2cid[G2C_MAX_FILES], g2cid2; */
    /*     int i; */
    /*     int ret; */

    /*     /\* Create max number of files. *\/ */
    /*     for (i = 0; i < G2C_MAX_FILES; i++) */
    /*         if ((ret = g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid[i]))) */
    /*          return ret; */

    /*     /\* Try to create one more. *\/ */
    /*     if (g2c_create(FILE_NAME, G2C_CLOBBER, &g2cid2) != G2C_ETOOMANYFILES) */
    /*         return G2C_ERROR; */

    /*  /\* Close all open files. *\/ */
    /*     for (i = 0; i < G2C_MAX_FILES; i++) */
    /*         if ((ret = g2c_close(g2cid[i]))) */
    /*          return ret; */
    /* } */
    /* printf("ok!\n"); */
    printf("Testing g2c_find_msg2 on file %s...", WAVE_FILE);
    {
        int g2cid;
        size_t bytes_to_msg, bytes_in_msg;
        size_t test_buf_size[NUM_BUF_SIZE_TESTS] = {100, 200, 1024, 2000, 3000, 4000};
        int i;
        int ret;

        /* g2c_set_log_level(4); */
        if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
            return ret;
        for (i = 0; i < NUM_BUF_SIZE_TESTS; i++)
        {
            if ((ret = g2c_find_msg2(g2cid, 0, test_buf_size[i], &bytes_to_msg, &bytes_in_msg)))
                return ret;
            /* printf("bytes_to_msg %ld bytes_in_msg %ld\n", bytes_to_msg, bytes_in_msg); */
            if (bytes_to_msg != 0 || bytes_in_msg != 15254)
                return G2C_ERROR;
        }
        if ((ret = g2c_close(g2cid)))
            return ret;
    }
    printf("ok!\n");
    printf("Testing g2c_get_msg on file %s...", WAVE_FILE);
    {
        int g2cid;
        size_t bytes_to_msg, bytes_in_msg;
        size_t test_buf_size[NUM_BUF_SIZE_TESTS] = {100, 200, 1024, 2000, 3000, 4000};
        unsigned char *cbuf = NULL;
        int i;
        int num_msg;
        int ret;

        if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
            return ret;
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;
        for (i = 0; i < NUM_BUF_SIZE_TESTS; i++)
        {

            if ((ret = g2c_get_msg(g2cid, 0, test_buf_size[i], &bytes_to_msg, &bytes_in_msg,
                                   &cbuf)))
                return ret;
            /* for (i = 0; i < 10; i++) */
            /*     printf("cbuf[%d] = %2x\n", i, cbuf[i]); */
            /* printf("bytes_to_msg %ld bytes_in_msg %ld\n", bytes_to_msg, bytes_in_msg); */
            if (bytes_to_msg != 0 || bytes_in_msg != 15254)
                return G2C_ERROR;

            /* Learn about this message. */
            {
                g2int listsec0[3], listsec1[13], numfields, numlocal;
                if ((ret = g2_info(cbuf, listsec0, listsec1, &numfields, &numlocal)))
                    return G2C_EMSG;
            }

            free(cbuf);
        }
        if ((ret = g2c_close(g2cid)))
            return ret;
    }
    printf("ok!\n");
#ifdef JPEG
    printf("Testing g2c_get_prod() on file %s...", WAVE_FILE);
    {
        int g2cid;
        int num_data_points;
        float *data;
        float expected_data[100] = {/* The first 100 values. */
                                    14.76, 14.76, 14.51, 14.2, 13.92, 13.89, 13.95, 14.1, 14.27, 14.31,
                                    14.24, 14.11, 13.91, 13.61, 13.2, 12.98, 12.95, 12.73, 12.2, 11.58,
                                    11.18, 11.13, 11.21, 11.26, 11.32, 11.36, 11.5, 11.72, 11.87, 11.96,
                                    11.97, 11.95, 11.99, 12.01, 11.75, 11.42, 11.23, 11.07, 10.83, 10.52,
                                    10.22, 10.03, 10.22, 8.7, 9.25, 8.2, 13.83, 14.07, 14.2, 14.12,
                                    13.86, 13.55, 13.46, 13.46, 13.61, 13.72, 13.94, 13.92, 13.8, 13.68,
                                    13.47, 13.01, 12.54, 12.47, 12.48, 12.25, 11.72, 11.09, 10.71, 10.68,
                                    10.87, 11.02, 11.08, 11.19, 11.4, 11.69, 11.85, 11.92, 12.03, 12.03,
                                    11.78, 11.34, 10.95, 10.62, 10.33, 10.13, 9.99, 9.84, 9.67, 9.49,
                                    9.44, 9.02, 8.93, 8.03, 7.66, 14.63, 14.47, 14.38, 14.31, 14.33};
        int i;
        int ret;

        /* Open GRIB2 file. */
        if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
            return ret;

        /* Get the size of the data from message 0, product 0. */
        if ((ret = g2c_get_prod(g2cid, 0, 0, &num_data_points, NULL)))
            return ret;

        /* Allocate storage for the data. */
        if (!(data = malloc(num_data_points * sizeof(float))))
            return G2C_ERROR;

        /* Get the data from message 0, product 0. */
        if ((ret = g2c_get_prod(g2cid, 0, 0, NULL, data)))
            return ret;

        /* Close the file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Check the first 100 values of the data. */
        for (i = 0; i < 100; i++)
            if (abs(data[i] - expected_data[i]) > EPSILON)
                return G2C_ERROR;

        /* Free the memory allocated to hold the data. */
        free(data);
    }
    printf("ok!\n");
#ifdef FTP_TEST_FILES
    printf("Testing g2c_open() on file %s...\n", GDAS_FILE);
    {
        int g2cid;
        int num_msg;
        int m;
        int ret;

        /* Open GRIB2 file. */
        g2c_set_log_level(10);
        if ((ret = g2c_open(GDAS_FILE, 0, &g2cid)))
            return ret;

        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 2)
            return ret;

        for (m = 0; m < num_msg; m++)
        {
            unsigned char discipline;
            int num_fields, num_local;
            short center, subcenter;
            unsigned char master_version, local_version;

            if ((ret = g2c_inq_msg(g2cid, m, &discipline, &num_fields, &num_local, &center,
                                   &subcenter, &master_version, &local_version)))
                return ret;
            if (discipline != (m < 4 ? 0 : 10) || num_fields != 1 || num_local != 0 ||
                center != 7 || subcenter != 0 || master_version != 2 || local_version != 1)
                return G2C_ERROR;
            /* printf("discipline %d num_fields %d num_local %d center %d subcenter %d " */
            /*        "master_version %d local_version %d\n", discipline, num_fields, num_local, */
            /*        center, subcenter, master_version, local_version); */

            {
                unsigned char sig_ref_time;
                short year;
                unsigned char month, day, hour, minute, second;

                if ((ret = g2c_inq_msg_time(g2cid, m, &sig_ref_time, &year,
                                            &month, &day, &hour, &minute, &second)))
                    return ret;
                /* printf("sig_ref_time %d year %d month %d day %d hour %d minute %d second %d\n", */
                /*        sig_ref_time, year, month, day, hour, minute, second); */
                if (sig_ref_time != 0 || year != 2022 || month != 11 ||
                    day != 6 || hour != 12 || minute != 0 || second != 0)
                    return G2C_ERROR;
            }

            {
                int pds_template_len, gds_template_len, drs_template_len;
                long long int pds_template[G2C_MAX_PDS_TEMPLATE_MAPLEN];
                long long int gds_template[G2C_MAX_GDS_TEMPLATE_MAPLEN];
                long long int drs_template[G2C_MAX_DRS_TEMPLATE_MAPLEN];
                int t;

                if ((ret = g2c_inq_prod(g2cid, m, 0, &pds_template_len, pds_template,
                                        &gds_template_len, gds_template, &drs_template_len,
                                        drs_template)))
                    return ret;
                printf("pds_template_len %d gds_template_len %d drs_template_len %d\n",
                       pds_template_len, gds_template_len, drs_template_len);
                if (pds_template_len != 15 || gds_template_len != 19 || drs_template_len != 18)
                    return G2C_ERROR;
                printf("pds_template {");
                for (t = 0; t < pds_template_len; t++)
                    printf("%lld, ", pds_template[t]);
                printf("}\n");
                printf("gds_template {");
                for (t = 0; t < gds_template_len; t++)
                    printf("%lld, ", gds_template[t]);
                printf("}\n");
                printf("drs_template {");
                for (t = 0; t < drs_template_len; t++)
                    printf("%lld, ", drs_template[t]);
                printf("}\n");
            }
        }

        /* Close the file. */
        if ((ret = g2c_close(g2cid)))
            return ret;
    }
    printf("ok!\n");
#endif /* FTP_TEST_FILES */
#endif /* JPEG */
    printf("SUCCESS!\n");
    return 0;
}

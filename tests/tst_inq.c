/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c inquiry functions.
 *
 * Ed Hartnett 10/21/22
 */

#include "grib2_int.h"

#define WAVE_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2"
#define REF_FILE "data/ref_gdaswave.t00z.wcoast.0p16.f000.grb2index"
#define NUM_MSG 19
#define NUM_OPEN 2

int
main()
{
    printf("Testing g2c inquiry functions.\n");
    printf("Testing g2c_inq()/g2c_inq_msg()/g2c_inq_prod() calls...\n");
    {
        int op;
        size_t dimlen;
        char dimname[G2C_MAX_NAME];

        for (op = 0; op < NUM_OPEN; op++)
        {
            int g2cid;
            int num_msg;
            int m;
            int ret;

            printf("\ttesting open of %s %s an index file...\n", WAVE_FILE,
                   op ? "with" : "without");

            /* Open our test file, with or without an index file. */
            if (op)
            {
                if ((ret = g2c_open_index(WAVE_FILE, REF_FILE, 0, &g2cid)))
                    return ret;
            }
            else
            {
                if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
                    return ret;
            }

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
            if (g2c_inq_msg(-1, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
                return G2C_ERROR;
            if (g2c_inq_msg(10, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
                return G2C_ERROR;
            if (g2c_inq_msg(G2C_MAX_FILES + 1, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
                return G2C_ERROR;

            /* This won't work - bad msg number. */
            if (g2c_inq_msg(g2cid, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EINVAL)
                return G2C_ERROR;
            /* This won't work - msg number won't be found. */
            if (g2c_inq_msg(g2cid, NUM_MSG, NULL, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_ENOMSG)
                return G2C_ERROR;

            /* This works but does nothing. */
            if ((ret = g2c_inq_msg(g2cid, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL)))
                return ret;

            /* These won't work - bad file number. */
            if (g2c_inq_prod(-1, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
                return G2C_ERROR;
            if (g2c_inq_prod(10, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
                return G2C_ERROR;
            if (g2c_inq_prod(G2C_MAX_FILES + 1, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EBADID)
                return G2C_ERROR;

            /* This won't work - bad msg number. */
            if (g2c_inq_prod(g2cid, -1, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EINVAL)
                return G2C_ERROR;
            if (g2c_inq_prod(g2cid, NUM_MSG, 0, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_ENOMSG)
                return G2C_ERROR;

            /* These won't work - bad prod number. */
            if (g2c_inq_prod(g2cid, 0, 1, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_ENOPRODUCT)
                return G2C_ERROR;
            if (g2c_inq_prod(g2cid, 0, -1, NULL, NULL, NULL, NULL, NULL, NULL) != G2C_EINVAL)
                return G2C_ERROR;

            /* This works but does nothing. */
            if ((ret = g2c_inq_prod(g2cid, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL)))
                return ret;

            /* Won't work, bad IDs. */
            if ((ret = g2c_inq_dim(-1, 0, 0, 0, &dimlen, dimname, NULL)) != G2C_EBADID)
                return G2C_ERROR;
            if ((ret = g2c_inq_dim(G2C_MAX_FILES + 1, 0, 0, 0, &dimlen, dimname, NULL)) != G2C_EBADID)
                return G2C_ERROR;
            if ((ret = g2c_inq_dim(10, 0, 0, 0, &dimlen, dimname, NULL)) != G2C_EBADID)
                return G2C_ERROR;
            if ((ret = g2c_inq_dim(g2cid, -1, 0, 0, &dimlen, dimname, NULL)) != G2C_EINVAL)
                return G2C_ERROR;
            if ((ret = g2c_inq_dim(g2cid, 0, -1, 0, &dimlen, dimname, NULL)) != G2C_EINVAL)
                return G2C_ERROR;
            if ((ret = g2c_inq_dim(g2cid, 0, 0, -1, &dimlen, dimname, NULL)) != G2C_EINVAL)
                return G2C_ERROR;

            /* Check each message. */
            for (m = 0; m < num_msg; m++)
            {
                int num_fields, num_local;
                unsigned char discipline;
                int pds_template_len, gds_template_len, drs_template_len;
                long long int pds_template[G2C_MAX_PDS_TEMPLATE_MAPLEN];
                long long int gds_template[G2C_MAX_GDS_TEMPLATE_MAPLEN];
                long long int drs_template[G2C_MAX_DRS_TEMPLATE_MAPLEN];
                long long int expected_pds_template[NUM_MSG][G2C_MAX_PDS_TEMPLATE_MAPLEN] = {
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
                    {0, 7, 2, 0, 11, 0, 0, 1, 0, 241, 0, 3, 255, 0, 0}};
                long long int expected_gds_template[G2C_MAX_GDS_TEMPLATE_MAPLEN] =
                    {6, 0, 0, 0, 0, 0, 0, 241, 151, 0, 0, 50000000, 210000000, 48, 25000000, 250000000, 166667, 166667, 0};
                long long int expected_drs_template[NUM_MSG][G2C_MAX_DRS_TEMPLATE_MAPLEN] = {
                    {1092616192, 0, 2, 11, 0, 0, 255},
                    {1065353216, 0, 2, 16, 0, 0, 255},
                    {3288563712, 0, 2, 11, 0, 0, 255},
                    {3298189312, 0, 2, 12, 0, 0, 255},
                    {1102053376, 0, 2, 9, 0, 0, 255},
                    {1144815616, 0, 2, 10, 0, 0, 255},
                    {1185159680, 0, 2, 14, 0, 0, 255},
                    {1086324736, 0, 2, 9, 0, 0, 255},
                    {1095761920, 0, 2, 9, 0, 0, 255},
                    {1086324736, 0, 2, 8, 0, 0, 255},
                    {1084227584, 0, 2, 7, 0, 0, 255},
                    {1125908480, 0, 2, 11, 0, 0, 255},
                    {1136328704, 0, 2, 11, 0, 0, 255},
                    {1135411200, 0, 2, 11, 0, 0, 255},
                    {1133510656, 0, 2, 11, 0, 0, 255},
                    {0, 0, 2, 16, 0, 0, 255},
                    {1183603200, 0, 2, 14, 0, 0, 255},
                    {1140424704, 0, 2, 16, 0, 0, 255},
                    {1092616192, 0, 2, 16, 0, 0, 255}};
                unsigned char sig_ref_time, month, day, hour, minute, second;
                short year;
                short center, subcenter;
                unsigned char master_version, local_version;
                int p;

                printf("\t\tinquiring about message %d...\n", m);

                /* Inquire about this message. */
                if ((ret = g2c_inq_msg(g2cid, m, &discipline, &num_fields, &num_local,
                                       &center, &subcenter, &master_version, &local_version)))
                    return ret;
                if (center != 7 || subcenter != 0 || master_version != 2 || local_version != 1)
                    return G2C_ERROR;

                /* Check results. */
                if (num_local || num_fields != 1 || discipline != (m < 4 ? 0 : 10))
                    return G2C_ERROR;

                /* These will all fail due to bad inputs. */
                if ((ret = g2c_inq_msg_time(-1, m, &sig_ref_time, &year, &month, &day, &hour,
                                            &minute, &second)) != G2C_EBADID)
                    return G2C_ERROR;
                if ((ret = g2c_inq_msg_time(10, m, &sig_ref_time, &year, &month, &day, &hour,
                                            &minute, &second)) != G2C_EBADID)
                    return G2C_ERROR;
                if ((ret = g2c_inq_msg_time(G2C_MAX_FILES + 1, m, &sig_ref_time, &year, &month, &day, &hour,
                                            &minute, &second)) != G2C_EBADID)
                    return G2C_ERROR;
                if ((ret = g2c_inq_msg_time(g2cid, -1, &sig_ref_time, &year, &month, &day, &hour,
                                            &minute, &second)) != G2C_EINVAL)
                    return G2C_ERROR;
                if ((ret = g2c_inq_msg_time(g2cid, 20, &sig_ref_time, &year, &month, &day, &hour,
                                            &minute, &second)) != G2C_ENOMSG)
                    return G2C_ERROR;

                /* This will work, but do nothing. */
                if ((ret = g2c_inq_msg_time(g2cid, m, NULL, NULL, NULL, NULL, NULL, NULL, NULL)))
                    return ret;

                /* Inquire about the date/time. */
                if ((ret = g2c_inq_msg_time(g2cid, m, &sig_ref_time, &year, &month, &day, &hour,
                                            &minute, &second)))
                    return ret;

                /* Check date/time. All messages in this file have the
                 * same date/time. */
                if (sig_ref_time != 1 || year != 2021 || month != 11 || day != 30 ||
                    hour != 0 || minute != 0 || second != 0)
                    return G2C_ERROR;

                /* Each message in the test file has one product. Inqure
                 * about it. */
                if ((ret = g2c_inq_prod(g2cid, m, 0, &pds_template_len, pds_template,
                                        &gds_template_len, gds_template, &drs_template_len,
                                        drs_template)))
                    return ret;

                /* Check results. */
                if (pds_template_len != 15)
                    return G2C_ERROR;
                for (p = 0; p < pds_template_len; p++)
                    if (pds_template[p] != expected_pds_template[m][p])
                        return G2C_ERROR;
                if (gds_template_len != 19)
                    return G2C_ERROR;
                for (p = 0; p < gds_template_len; p++)
                    if (gds_template[p] != expected_gds_template[p])
                        return G2C_ERROR;
                if (drs_template_len != 7)
                    return G2C_ERROR;
                for (p = 0; p < drs_template_len; p++)
                {
                    /* printf("drs_template[%d] %lld\n", p, drs_template[p]); */
                    if (drs_template[p] != expected_drs_template[m][p])
                        return G2C_ERROR;
                }

                if ((ret = g2c_inq_dim_info(g2cid, m, 0, 0, &dimlen, dimname)))
                    return ret;
                /* printf("dimlen = %ld, dimname = %s\n", dimlen, dimname); */
                if (dimlen != 151 || strcmp(dimname, "Latitude"))
                    return G2C_ERROR;
                if ((ret = g2c_inq_dim(g2cid, m, 0, 0, &dimlen, dimname, NULL)))
                    return ret;
                /* printf("dimlen = %ld, dimname = %s\n", dimlen, dimname); */
                if (dimlen != 151 || strcmp(dimname, "Latitude"))
                    return G2C_ERROR;
            }

            /* Close the file. */
            if ((ret = g2c_close(g2cid)))
                return ret;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

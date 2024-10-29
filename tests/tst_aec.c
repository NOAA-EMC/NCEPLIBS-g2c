/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the AEC compression functions.
 *
 * Eric Engle 10/18/23
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>

#define DATA_LEN 4
#define PACKED_LEN 80
#define EPSILON .0001

/* The following is determined from summing the libaec constants
 *     AEC_DATA_SIGNED | AEC_DATA_PREPROCESS | AEC_DATA_MSB
 * Here we use the value so we don't have to include libaec.h. */
#define CCSDS_FLAGS 13

int
main()
{
    printf("Testing AEC Compression functions...\n");
    printf("Testing enc_aec() and dec_aec() calls...");
    {
        unsigned char data[4] = {1, 2, 3, 4};
        unsigned char cout[200];
        g2int nbits = 32;
        g2int datalen;
        g2int *aeclen;
        g2int ccsds_flags;
        g2int ccsds_block_size;
        g2int ccsds_rsi;
        unsigned char *databuf;
        unsigned char *aecbuf;

        int i, ret;

        databuf = data;
        aecbuf = cout;

        datalen = sizeof(data) / sizeof(data[0]);
        aeclen = (g2int *)(sizeof(cout) / sizeof(cout[0]));

        /* Set AEC parameters. */
        ccsds_flags = CCSDS_FLAGS;
        ccsds_block_size = 16;
        ccsds_rsi = 128;

        /* Encode some data. */
        ret = enc_aec(databuf, datalen, nbits, ccsds_flags, ccsds_block_size,
                      ccsds_rsi, aecbuf, aeclen);
        if (ret < 0)
            return G2C_ERROR;

        /* Now decode it. */
        ret = dec_aec(aecbuf, (g2int)aeclen, nbits, ccsds_flags, ccsds_block_size,
                      ccsds_rsi, cout, datalen);
        if (ret < 0)
        {
            return G2C_ERROR;
        }

        for (i = 0; i < datalen; i++)
            //printf("%g %g\n",cout[i], data[i]);
            if (cout[i] != data[i])
                return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing aecpack()/aecunpack() calls...");
    {
        g2int width = 2, height = 2;
        g2int ndpts = DATA_LEN, len = PACKED_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 4.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack;
        g2int idrstmpl[8] = {0, 1, 1, 0, 0, 0, 16, 128};
        int i, ret;

        idrstmpl[5] = CCSDS_FLAGS;

        /* Pack the data. */
        aecpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        ret = aecunpack(cpack, len, idrstmpl, ndpts, fld_in);
        if (ret < 0)
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            //printf("%g %g\n",fld[i], fld_in[i]);
            if (abs(fld[i] - fld_in[i]) >= EPSILON)
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing g2c_aecpackd()/g2c_aecunpackd() calls with constant data...");
    {
        size_t height = 2, width = 2;
        size_t ndpts = DATA_LEN, len = PACKED_LEN;
        double fld[DATA_LEN] = {1.0, 1.0, 1.0, 1.0};
        double fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        size_t lcpack;
        g2int idrstmpl[8] = {0, 1, 1, 0, 0, 0, 16, 128};
        int i, ret;

        idrstmpl[5] = CCSDS_FLAGS;

        /* Pack the data. */
        g2c_aecpackd(fld, width, height, (int *)idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        ret = g2c_aecunpackd(cpack, len, (int *)idrstmpl, ndpts, fld_in);
        if (ret < 0)
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (abs(fld[i] - fld_in[i]) >= EPSILON)
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing g2c_aecpackd()/g2c_aecunpackd() calls with data...");
    {
        size_t height = 2, width = 2;
        size_t ndpts = DATA_LEN, len = PACKED_LEN;
        double fld[DATA_LEN] = {1.0, 2.0, 3.0, 4.0};
        double fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        size_t lcpack;
        g2int idrstmpl[8] = {0, 1, 1, 0, 0, 0, 16, 128};
        int i, ret;

        idrstmpl[5] = CCSDS_FLAGS;

        /* Pack the data. */
        g2c_aecpackd(fld, width, height, (int *)idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        ret = g2c_aecunpackd(cpack, len, (int *)idrstmpl, ndpts, fld_in);
        if (ret < 0)
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (abs(fld[i] - fld_in[i]) >= EPSILON)
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

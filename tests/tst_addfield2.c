/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_addfield.
 *
 * Ed Hartnett 11/4/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"
#include "grib2_int.h"

#define SEC0_LEN 16
#define SEC1_LEN 21
#define MSG_LEN 109
#define MOST_MSG_LEN 237
#define FULL_MSG_LEN 241

void g2_miss(gribfield *gfld, float *rmiss, int *nmiss);

int
main()
{
    printf("Testing g2_addfield() some more.\n");
    printf("Testing full message creation (expect and ignore error messages)...\n");
    {
        unsigned char cgrib[FULL_MSG_LEN];
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {0, 4, 0, 0, 0};
        g2int igdstmpl[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
        unsigned char expected_cgrib[FULL_MSG_LEN] = {0x47, 0x52, 0x49, 0x42, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0xf1, 0x00, 0x00, 0x00, 0x15, 0x01, 0x00, 0x07, 0x00, 0x04, 0x18, 0x00, 0x00, 0x07, 0xe5, 0x0a,
            0x18, 0x06, 0x36, 0x3b, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x48, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
            0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00,
            0x00, 0x00, 0x0c, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x11, 0x12, 0x00, 0x00, 0x00, 0x19, 0x04, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x29,
            0x42, 0xc8, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x08, 0x00, 0x00, 0x00, 0x00, 0x07, 0x06, 0x00, 0xf0, 0x00, 0x00,
            0x00, 0x4b, 0x07, 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
            0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x57, 0x50, 0x11, 0x00, 0x00,
            0x00, 0x0d, 0x49, 0x44, 0x41, 0x54, 0x08, 0x99, 0x63, 0x64, 0x30, 0x32, 0x32, 0x02, 0x00, 0x01, 0x36, 0x00, 0x98,
            0x05, 0xdb, 0x15, 0xba, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82, 0x37, 0x37, 0x37, 0x37};
        unsigned char old_val;
        /* Analysis or forecast at a horizontal level or in a
         * horizontal layer at a point in time. */
        g2int ipdsnum = 31;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp4-31.shtml. */
        g2int ipdstmpl[10] = {
            0, /* Parameter category (see Code Table 4.1) */
            0, /* Parameter number (see Code Table 4.2) */
            0, /* Type of generating process (see Code Table 4.3) */
            0, /* Observation generating process identifier (defined by originating centres) */
            1, /* Number of contributing spectral bands (NB) */
            0,
            0,
            0,
            0,
            0
        };
        float coordlist[1] = {1};
        g2int numcoord = 0;
        g2int idrsnum = 41; /* Grid Point Data - PNG Compression (see Template 5.41) */
        g2int idrstmpl[5] = {
            0, /* Reference value (R) (IEEE 32-bit floating-point value) */
            1, /* Binary scale factor (E) */
            2, /* Decimal scale factor (D) */
            3, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            4, /* Type of original field values (see Code Table 5.1) */
        };
        float fld[4] = {1, 2, 3, 4};
        g2int ngrdpts = 4;
        g2int ibmap = 0;
        g2int bmap[4] = {1, 1, 1, 1};
        g2int listsec0_in[3], listsec1_in[13];
        g2int numfields, numlocal;
        g2int ifldnum = 1, unpack = 1, expand = 0;
        gribfield *gfld;
        int i;
        int ret;

        /* Create the message, filling in sections 0 and 1. */
        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        /* Try to add sections 4, 5, 6, and 7. Won't work, we haven't added section 3 yet. */
        if ((ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                               idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap)) != -4)
            return G2C_ERROR;

        /* Add section 3. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 109)
            return G2C_ERROR;

        /* Mess up section length and try to add section 4, 5, 6. Won't work. */
        old_val = cgrib[15];
        cgrib[15] = 5;
        if ((ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                               idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap)) != -3)
            return G2C_ERROR;
        cgrib[15] = old_val;

        /* Mess up ipdsnum and try to add section 4, 5, 6. Won't work. */
        old_val = ipdsnum;
        ipdsnum = 9999;
        if ((ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                               idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap)) != G2_ADDFIELD_BAD_PDT)
            return G2C_ERROR;
        ipdsnum = old_val;

        /* Add sections 4, 5, 6, and 7. */
        if ((ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                               idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap)) != MOST_MSG_LEN)
            return G2C_ERROR;

        /* Add section 8. */
        if ((ret = g2_gribend(cgrib)) != FULL_MSG_LEN)
            return G2C_ERROR;

        /* Check the contents of the message for correctness. */
        for (i = 0; i < FULL_MSG_LEN; i++)
        {
            /* printf("0x%2.2x, ", cgrib[i]); */
            if (cgrib[i] != expected_cgrib[i])
                return G2C_ERROR;
        }

        /* Use g2_info() to learn about our messaage. */
        if ((ret = g2_info(cgrib, listsec0_in, listsec1_in, &numfields, &numlocal)))
            return G2C_ERROR;

        /* Check results. */
        if (numlocal || numfields != 1 || listsec0_in[0] != 1 || listsec0_in[1] != 2 ||
            listsec0_in[2] != FULL_MSG_LEN)
            return G2C_ERROR;
        for (i = 0; i < 13; i++)
            if (listsec1_in[i] != listsec1[i])
                return G2C_ERROR;

        /* Try g2_getfld() for field 1. */
        if ((ret = g2_getfld(cgrib, ifldnum, unpack, expand, &gfld)))
            return G2C_ERROR;

        /* Check some stuff. */
        if (gfld->version != 2 || gfld->discipline != 1 || gfld->idsectlen != 13)
            return G2C_ERROR;
        if (gfld->local || gfld->locallen || gfld->ifldnum != 1 || gfld->griddef)
            return G2C_ERROR;
        if (gfld->ngrdpts != 4 || gfld->numoct_opt || gfld->coord_list || gfld->ndpts != 4)
            return G2C_ERROR;
        if (gfld->idrtnum != 41 || gfld->idrtlen != 5 || gfld->unpacked != 1 || gfld->expanded)
            return G2C_ERROR;
        if (gfld->ibmap)
            return G2C_ERROR;
        for (i = 0; i < 13; i++)
            if (gfld->idsect[i] != listsec1[i])
                return G2C_ERROR;
        for (i = 0; i < 19; i++)
            if (gfld->igdtmpl[i] != igdstmpl[i])
                return G2C_ERROR;
        for (i = 0; i < 5; i++)
            if (gfld->ipdtmpl[i] != ipdstmpl[i])
                return G2C_ERROR;

	/* Try the g2_miss() function. */
	float rmiss[1];
	int nmiss;
	g2_miss(gfld, rmiss, &nmiss);
	if (nmiss)
	    return G2C_ERROR;

        /* Free the memory. */
        g2_free(gfld);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

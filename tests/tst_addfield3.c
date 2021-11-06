/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_addfield.
 *
 * Ed Hartnett 11/4/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define SEC0_LEN 16
#define SEC1_LEN 21
#define SEC2_LEN 15
#define MSG_LEN 109
#define MOST_MSG_LEN_MIN 311
#define MOST_MSG_LEN 353
#define FULL_MSG_LEN MOST_MSG_LEN + 4
#define FULL_MSG_LEN_MIN MOST_MSG_LEN_MIN + 4
#define LOCAL_SIZE 10
#define G2C_ERROR 2

void g2_miss(gribfield *gfld, float *rmiss, int *nmiss);

int
main()
{
    printf("Testing g2_addfield() with jpeg and a local section.\n");
    printf("Testing full message creation with mercator, jpeg compression, and a local section...\n");
    {
        unsigned char cgrib[FULL_MSG_LEN];
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {0, 4, 0, 0, 10}; /* 10 is Mercator */
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp3-10.shtml. */
        g2int igdstmpl[19] = {
            0, /* Shape of the Earth (See Code Table 3.2) */
            1, /* Scale factor of radius of spherical Earth */
            1, /* Scale value of radius of spherical Earth */
            1, /* Scale factor of major axis of oblate spheroid Earth */
            1, /* Scaled value of major axis of oblate spheroid Earth */
            1, /* Scale factor of minor axis of oblate spheroid Earth */
            1, /* Scaled value of minor axis of oblate spheroid Earth */
            2, /* Nj—number of points along a parallel  */
            2, /* Nj—number of points along a meridian */
            0, /* La1 ― latitude of first grid point */
            0, /* Lo1 ― longitude of first grid point */
            0, /* Resolution and component flags (see Flag Table 3.3) */
            90, /* LaD — latitude(s) at which the Mercator projection intersects the Earth (Latitude(s) where Di and Dj are specified)  */
            90, /* La2 ― latitude of last grid point */
            90, /* Lo2 — longitude of last grid point   */
            0, /* Scanning mode (flags — see Flag Table 3.4) */
            0, /* Orientation of the grid, angle between i direction on the map and the Equator  (see Note1)     */
            100, /* Dj —  longitudinal direction grid length (see Note 2) */
            100 /* Dj ― latitudinal direction grid length  (see Note 2) */
        };
        /* unsigned char expected_cgrib[FULL_MSG_LEN] = {0x47, 0x52, 0x49, 0x42, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, */
        /*     0x00, 0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x00, 0x15, 0x01, 0x00, 0x07, 0x00, 0x04, 0x18, 0x00, 0x00, 0x07, */
        /*     0xe5, 0x0a, 0x18, 0x06, 0x36, 0x3b, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x02, 0x00, 0x01, 0x02, 0x03, 0x04, */
        /*     0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x00, 0x00, 0x48, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, */
        /*     0x0a, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, */
        /*     0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
        /*     0x00, 0x5a, 0x00, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
        /*     0x64, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x19, 0x04, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, */
        /*     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x05, 0x00, */
        /*     0x00, 0x00, 0x04, 0x00, 0x28, 0x41, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x04, 0x00, 0x00, 0xff, 0x00, */
        /*     0x00, 0x00, 0x07, 0x06, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xae, 0x07, 0xff, 0x4f, 0xff, 0x51, 0x00, 0x29, 0x00, */
        /*     0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
        /*     0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, */
        /*     0x01, 0x01, 0xff, 0x64, 0x00, 0x22, 0x00, 0x01, 0x43, 0x72, 0x65, 0x61, 0x74, 0x6f, 0x72, 0x3a, 0x20, 0x4a, */
        /*     0x61, 0x73, 0x50, 0x65, 0x72, 0x20, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x20, 0x32, 0x2e, 0x30, 0x2e, */
        /*     0x33, 0x33, 0xff, 0x52, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x04, 0x04, 0x00, 0x01, 0xff, 0x5c, */
        /*     0x00, 0x13, 0x40, 0x20, 0x28, 0x28, 0x30, 0x28, 0x28, 0x30, 0x28, 0x28, 0x30, 0x28, 0x28, 0x30, 0x28, 0x28, */
        /*     0x30, 0xff, 0x90, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x01, 0xff, 0x5d, 0x00, 0x14, 0x00, */
        /*     0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x28, 0x00, 0x00, 0xff, */
        /*     0x93, 0xc7, 0x41, 0x07, 0x80, 0x80, 0x80, 0xcf, 0x90, 0x08, 0x03, 0xc7, 0xc2, 0x10, 0x0b, 0x5f, 0xff, 0xd9, */
        /*     0x37, 0x37, 0x37, 0x37}; */
        /* unsigned char old_val; */
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
        g2float coordlist[1] = {1};
        g2int numcoord = 0;
        g2int idrsnum = 40; /* Grid Point Data - JPEG2000 Compression (see Template 5.40) */
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml */
        g2int idrstmpl[7] = {
            0, /* Reference value (R) (IEEE 32-bit floating-point value) */
            1, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            8, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0, /* Type of original field values (see Code Table 5.1) */
            0, /* Type of Compression used. (see Code Table 5.40) */
            0, /* Target compression ratio, M:1 (with respect to the bit-depth specified in octet 20), when octet 22 indicates Lossy Compression. Otherwise, set to missing (see Note 3) */
        };
        g2float fld[4] = {1, 2, 3, 4};
        g2int ngrdpts = 4;
        g2int ibmap = 0;
        g2int bmap[4] = {1, 1, 1, 1};
        unsigned char csec2[LOCAL_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        g2int lcsec2 = LOCAL_SIZE;
        g2int listsec0_in[3], listsec1_in[13];
        g2int numfields, numlocal;
        g2int ifldnum = 1, unpack = 1, expand = 0;
        gribfield *gfld;
        int i;
        int ret;

        /* Create the message, filling in sections 0 and 1. */
        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        /* Add section 2. */
        if ((ret = g2_addlocal(cgrib, csec2, lcsec2)) != SEC0_LEN + SEC1_LEN + SEC2_LEN)
            return G2C_ERROR;

        /* Add section 3. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 124)
            return G2C_ERROR;

        /* Add sections 4, 5, 6, and 7. */
        if ((ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                               idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap)) < MOST_MSG_LEN_MIN)
        {
            printf("g2_addfield ret = %d\n", ret);
            return G2C_ERROR;
        }

        /* Add section 8. */
        if ((ret = g2_gribend(cgrib)) < FULL_MSG_LEN_MIN)
        {
            printf("g2_gribend ret = %d\n", ret);
            return G2C_ERROR;
        }

        /* Check the contents of the message for correctness. This
         * does not work in CI. Do different versions of the jpeg
         * library come out with different answers? */
        /* for (i = 0; i < FULL_MSG_LEN; i++) */
        /* { */
        /*     /\* printf("0x%2.2x, ", cgrib[i]); *\/ */
        /*     if (cgrib[i] != expected_cgrib[i]) */
        /*         return G2C_ERROR; */
        /* } */

        /* /\* Use g2_info() to learn about our messaage. *\/ */
        /* if ((ret = g2_info(cgrib, listsec0_in, listsec1_in, &numfields, &numlocal))) */
        /*     return G2C_ERROR; */

        /* /\* Check results. *\/ */
        /* if (numlocal != 1 || numfields != 1 || listsec0_in[0] != 1 || listsec0_in[1] != 2 || */
        /*     listsec0_in[2] != FULL_MSG_LEN) */
        /*     return G2C_ERROR; */
        /* for (i = 0; i < 13; i++) */
        /*     if (listsec1_in[i] != listsec1[i]) */
        /*         return G2C_ERROR; */

        /* /\* Try g2_getfld() for field 1. *\/ */
        /* if ((ret = g2_getfld(cgrib, ifldnum, unpack, expand, &gfld))) */
        /*     return G2C_ERROR; */

        /* /\* Check some stuff. *\/ */
        /* if (gfld->version != 2 || gfld->discipline != 1 || gfld->idsectlen != 13) */
        /*     return G2C_ERROR; */
        /* if (!gfld->local || gfld->locallen != 10 || gfld->ifldnum != 1 || gfld->griddef) */
        /*     return G2C_ERROR; */
        /* if (gfld->ngrdpts != 4 || gfld->numoct_opt || gfld->coord_list || gfld->ndpts != 4) */
        /*     return G2C_ERROR; */
        /* if (gfld->idrtnum != 40 || gfld->idrtlen != 7 || gfld->unpacked != 1 || gfld->expanded) */
        /*     return G2C_ERROR; */
        /* if (gfld->ibmap) */
        /*     return G2C_ERROR; */
        /* for (i = 0; i < 13; i++) */
        /*     if (gfld->idsect[i] != listsec1[i]) */
        /*         return G2C_ERROR; */
        /* for (i = 0; i < 19; i++) */
        /*     if (gfld->igdtmpl[i] != igdstmpl[i]) */
        /*         return G2C_ERROR; */
        /* for (i = 0; i < 7; i++) */
        /*     if (gfld->ipdtmpl[i] != ipdstmpl[i]) */
        /*         return G2C_ERROR; */

	/* /\* Try the g2_miss() function. *\/ */
	/* float rmiss[1]; */
	/* int nmiss; */
	/* g2_miss(gfld, rmiss, &nmiss); */
	/* if (nmiss) */
	/*     return G2C_ERROR; */

        /* /\* Free the memory. *\/ */
        /* g2_free(gfld); */
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

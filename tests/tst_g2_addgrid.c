/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_addgrid.
 *
 * Ed Hartnett 10/25/21
 */

#include "grib2_int.h"
#include <stdio.h>

#define SEC0_LEN 16
#define SEC1_LEN 21
#define SEC3_LEN 34
#define MSG_LEN 109

int
main()
{
    printf("Testing g2_addgrid().\n");
    printf("Testing g2_addgrid() call that fails (expect and ignore error messages)...\n");
    {
        unsigned char cgrib[MSG_LEN];
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {0, 4, 0, 0, 0};
        g2int igdstmpl[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
        int ret;

        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;
        cgrib[0] = 0;

        /* Won't work, first char is not 'G'. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != -1)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing g2_addgrid() call...");
    {
        unsigned char cgrib[MSG_LEN];
        g2int lencurr;
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {0, 4, 0, 0, 0};
        g2int igdstmpl[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
        unsigned char expected_cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0,
                                                 109, 0, 0, 0, 21, 1, 0, 7, 0, 4, 24, 0, 0, 7, 229, 10, 24, 6, 54, 59, 7, 192, 0, 0, 0,
                                                 72, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0, 4, 5, 0, 0, 0, 6, 0, 0,
                                                 0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 13, 0, 0, 0, 14,
                                                 0, 0, 0, 15, 0, 0, 0, 16, 0, 0, 0, 17, 18};
        unsigned char old_val;
        int i;
        int ret;

        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        /* Mess up section length. */
        old_val = cgrib[19];
        cgrib[19] = 99;

        /* Try to add the grid. Won't work, bad section length. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != -3)
            return G2C_ERROR;

        /* Fix the section length. */
        cgrib[19] = old_val;

        /* Add the grid. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 109)
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < MSG_LEN; i++)
        {
            /* printf("%d %d %d\n", i, cgrib[i], expected_cgrib[i]);  */
            if (cgrib[i] != expected_cgrib[i])
                return G2C_ERROR;
        }

        gbit(cgrib, &lencurr, 96, 32);
        if (lencurr != MSG_LEN)
            return G2C_ERROR;

        /* Try to add section 3 again. Won't work. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != -4)
            return G2C_ERROR;
    }
    printf("ok!\n");

    /* This test can't work because of the memory leak described in
     * https://github.com/NOAA-EMC/NCEPLIBS-g2c/issues/150. */
    /* printf("Testing g2_addgrid() call with grid def template number 5..."); */
    /* { */
    /*     unsigned char cgrib[MSG_LEN]; */
    /*     g2int lencurr; */
    /*     g2int listsec0[2] = {1, 2}; */
    /*     g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192}; */
    /*     g2int igds[5] = { */
    /*         0, /\* Source of grid definition (see Code Table 3.0). *\/ */
    /*         4, /\* Number of grid points in the defined grid. *\/ */
    /*         0, /\* Number of octets needed for each additional grid points definition. Used to define number of points in each row (or column) for non-regular grids. = 0, if using regular grid. *\/ */
    /*         0, /\* Interpretation of list for optional points definition. (See Code Table 3.11). *\/ */
    /*         5  /\* Grid Definition Template Number (See Code Table 3.1). 5 = Variable resolution rotate Latitude/Longitude*\/ */
    /*     }; */
    /*     /\* See */
    /*      * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp3-5.shtml. *\/ */
    /*     g2int igdstmpl[16] = { */
    /*         0, /\* Shape of the Earth (See Code Table 3.2) *\/ */
    /*         1, /\* Scale Factor of radius of spherical Earth *\/ */
    /*         1, /\* Scale value of radius of spherical Earth *\/ */
    /*         1, /\* Scale factor of major axis of oblate spheroid Earth *\/ */
    /*         1, /\* Scaled value of major axis of oblate spheroid Earth *\/ */
    /*         1, /\* Scale factor of minor axis of oblate spheroid Earth *\/ */
    /*         1, /\* Scaled value of minor axis of oblate spheroid Earth *\/ */
    /*         2, /\* Ni—number of points along a parallel     *\/ */
    /*         2, /\* Nj—number of points along a meridian *\/ */
    /*         0, /\* Basic angle of the initial production domain (see Note 1) *\/ */
    /*         0, /\* Subdivisions of basic angle used to define extreme longitudes and latitudes, and direction increments (see Note 1) *\/ */
    /*         0, /\* Resolution and component flags (see Flag Table 3.3 and Note 2) *\/ */
    /*         0, /\* Scanning mode (flags — see Flag Table 3.4) *\/ */
    /*         90, /\* Latitude of the Southern pole of projection (see Note 4) *\/ */
    /*         45, /\* Longitude of the Southern pole of projection (see Note 4) *\/ */
    /*         0 /\* Angle of rotation of projection (see Note 4) *\/ */
    /*     }; */
    /*     /\* unsigned char expected_cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, *\/ */
    /*     /\*     109, 0, 0, 0, 21, 1, 0, 7, 0, 4, 24, 0, 0, 7, 229, 10, 24, 6, 54, 59, 7, 192, 0, 0, 0, *\/ */
    /*     /\*     72, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0, 4, 5, 0, 0, 0, 6, 0, 0, *\/ */
    /*     /\*     0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 13, 0, 0, 0, 14, *\/ */
    /*     /\*     0, 0, 0, 15, 0, 0, 0, 16, 0, 0, 0, 17, 18}; *\/ */
    /*     /\* unsigned char old_val; *\/ */
    /*     int i; */
    /*     int ret; */

    /*     if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN) */
    /*         return G2C_ERROR; */

    /*     /\* Add the grid. *\/ */
    /*     if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 109) */
    /*         printf("%d\n", ret); */
    /*     return G2C_ERROR; */

    /*     /\* Check results. *\/ */
    /*     for (i = 0; i < MSG_LEN; i++) */
    /*     { */
    /*         printf("%d\n", cgrib[i]); */
    /*         /\* if (cgrib[i] != expected_cgrib[i]) *\/ */
    /*         /\*     return G2C_ERROR; *\/ */
    /*     } */

    /*     gbit(cgrib, &lencurr, 96, 32); */
    /*     printf("lencurr = %ld\n", lencurr); */
    /*     /\* if (lencurr != MSG_LEN) *\/ */
    /*     /\*     return G2C_ERROR; *\/ */
    /* } */
    /* printf("ok!\n"); */
    printf("Testing g2_addgrid() call with grid def template number 120...");
    {
#define MSG_LEN_120 84
        unsigned char cgrib[MSG_LEN_120 + 50];
        g2int lencurr;
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {
            0,  /* Source of grid definition (see Code Table 3.0). */
            4,  /* Number of grid points in the defined grid. */
            0,  /* Number of octets needed for each additional grid points definition. Used to define number of points in each row (or column) for non-regular grids. = 0, if using regular grid. */
            0,  /* Interpretation of list for optional points definition. (See Code Table 3.11). */
            120 /* Grid Definition Template Number (See Code Table 3.1). 120 = Azimuth-range projection */
        };
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp3-120.shtml. */
        g2int igdstmpl[11] = {
            1, /* Nb ― number of data bins along radials (see Note) */
            2, /* Nr ― number of radials */
            0, /* La1 ― latitude of centre point */
            0, /* Lo1 ― longitude of centre point */
            1, /* Dx ― spacing of bins along radials */
            0, /* Dstart ― offset from origin to inner bound */
            0, /* Scanning mode (see Flag Table 3.4) */
            0, 0, 0, 0};
        unsigned char expected_cgrib[MSG_LEN_120] = {71, 82, 73, 66, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0,
                                                     84, 0, 0, 0, 21, 1, 0, 7, 0, 4, 24, 0, 0, 7, 229, 10, 24, 6, 54, 59, 7, 192, 0, 0, 0, 47,
                                                     3, 0, 0, 0, 0, 4, 0, 0, 0, 120, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        /* unsigned char old_val; */
        int i;
        int ret;

        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        /* Add the grid. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 84)
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < MSG_LEN_120; i++)
        {
            /* printf("%d, ", cgrib[i]); */
            if (cgrib[i] != expected_cgrib[i])
                return G2C_ERROR;
        }

        gbit(cgrib, &lencurr, 96, 32);
        if (lencurr != MSG_LEN_120)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

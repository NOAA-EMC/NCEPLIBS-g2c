/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cparams.c.
 *
 * Ed Hartnett 9/21/22
 */
#include "grib2_int.h"

int
main()
{
    printf("Testing params handling for all g2c_param_g2tog1() calls.\n");

    printf("Testing all values with g2c_param_g2tog1()...");
    {
        int g1num, g1ver;
        int ret;

        /* g2c_set_log_level(5); */
        /* This will work. */
        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;

        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 2 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 3 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 14, &g1num, &g1ver)))
            return ret;
        if (g1num != 4 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 5 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 6 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 7 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 8 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 9 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 10 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 11 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 12 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 13 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 14 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 15 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 16 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 17 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 18 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 19 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 20 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 15, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 21 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 15, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 22 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 15, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 23 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 24 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 9, &g1num, &g1ver)))
            return ret;
        if (g1num != 25 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 26 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 9, &g1num, &g1ver)))
            return ret;
        if (g1num != 27 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 28 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 29 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 30 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 31 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 32 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 33 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 34 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 35 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 36 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 37 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 38 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 39 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 9, &g1num, &g1ver)))
            return ret;
        if (g1num != 40 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 10, &g1num, &g1ver)))
            return ret;
        if (g1num != 41 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 11, &g1num, &g1ver)))
            return ret;
        if (g1num != 42 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 12, &g1num, &g1ver)))
            return ret;
        if (g1num != 43 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 13, &g1num, &g1ver)))
            return ret;
        if (g1num != 44 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 15, &g1num, &g1ver)))
            return ret;
        if (g1num != 45 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 16, &g1num, &g1ver)))
            return ret;
        if (g1num != 46 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 47 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 48 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 49 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 50 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 51 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 52 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 53 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 54 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 55 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 56 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 57 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 58 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 59 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 60 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 61 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 9, &g1num, &g1ver)))
            return ret;
        if (g1num != 62 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 10, &g1num, &g1ver)))
            return ret;
        if (g1num != 63 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 12, &g1num, &g1ver)))
            return ret;
        if (g1num != 64 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 13, &g1num, &g1ver)))
            return ret;
        if (g1num != 65 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 11, &g1num, &g1ver)))
            return ret;
        if (g1num != 66 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 67 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 68 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 69 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 70 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 71 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 72 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 73 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 74 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 75 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 76 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 77 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 14, &g1num, &g1ver)))
            return ret;
        if (g1num != 78 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 15, &g1num, &g1ver)))
            return ret;
        if (g1num != 79 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 80 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 81 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 82 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 83 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 84 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 85 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 86 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 87 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 88 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 10, &g1num, &g1ver)))
            return ret;
        if (g1num != 89 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 90 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 91 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 92 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 93 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 94 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 95 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 96 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 97 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 2, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 98 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 16, &g1num, &g1ver)))
            return ret;
        if (g1num != 99 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 100 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 101 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 102 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 103 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 104 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 105 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 9, &g1num, &g1ver)))
            return ret;
        if (g1num != 106 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 10, &g1num, &g1ver)))
            return ret;
        if (g1num != 107 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 11, &g1num, &g1ver)))
            return ret;
        if (g1num != 108 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 12, &g1num, &g1ver)))
            return ret;
        if (g1num != 109 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 0, 13, &g1num, &g1ver)))
            return ret;
        if (g1num != 110 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 111 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 112 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 113 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 114 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 115 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 116 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 117 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 118 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 119 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 120 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 10, &g1num, &g1ver)))
            return ret;
        if (g1num != 121 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 11, &g1num, &g1ver)))
            return ret;
        if (g1num != 122 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 20, &g1num, &g1ver)))
            return ret;
        if (g1num != 123 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 17, &g1num, &g1ver)))
            return ret;
        if (g1num != 124 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 18, &g1num, &g1ver)))
            return ret;
        if (g1num != 125 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 19, &g1num, &g1ver)))
            return ret;
        if (g1num != 126 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver)))
            return ret;
        if (g1num != 127 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 229 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 22, &g1num, &g1ver)))
            return ret;
        if (g1num != 153 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 140 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 141 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 142 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 143 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 214 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 135 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(1, 1, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 194 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 228 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 136 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 172 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 196 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 197 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 252 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 253 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 130 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 204 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 211 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 205 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 212 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 213 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 132 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 157 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 156 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 190 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 131 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 11, &g1num, &g1ver)))
            return ret;
        if (g1num != 158 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 191, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 176 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 191, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 177 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(1, 0, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 234 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(1, 0, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 235 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 144 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 155 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 207 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 208 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 223 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 226 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 154 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 222 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 145 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 146 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 147 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 148 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 221 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 230 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 160 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 171 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 201, &g1num, &g1ver)))
            return ret;
        if (g1num != 219 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 222 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 224 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 225 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 230 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 231 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 201, &g1num, &g1ver)))
            return ret;
        if (g1num != 238 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 240 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 202, &g1num, &g1ver)))
            return ret;
        if (g1num != 131 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 132 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 203, &g1num, &g1ver)))
            return ret;
        if (g1num != 133 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 134 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 135 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 136 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 137 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 204, &g1num, &g1ver)))
            return ret;
        if (g1num != 138 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 205, &g1num, &g1ver)))
            return ret;
        if (g1num != 139 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 140 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 159 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 170 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 24, &g1num, &g1ver)))
            return ret;
        if (g1num != 170 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 25, &g1num, &g1ver)))
            return ret;
        if (g1num != 171 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 181 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 203 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 202, &g1num, &g1ver)))
            return ret;
        if (g1num != 246 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 203, &g1num, &g1ver)))
            return ret;
        if (g1num != 247 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 204, &g1num, &g1ver)))
            return ret;
        if (g1num != 248 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 205, &g1num, &g1ver)))
            return ret;
        if (g1num != 249 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 254 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(3, 1, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 190 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(3, 1, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 191 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 191, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 171 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 180 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 181 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(1, 1, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 193 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(1, 1, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 195 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 22, &g1num, &g1ver)))
            return ret;
        if (g1num != 180 || g1ver != 2)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 2, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 31 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 32 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 33 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 34 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 100 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 101 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 103 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 107 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 108 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 109 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 110 || g1ver != 0) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 13, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 156 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 13, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 157 || g1ver != 129)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 0, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 11 || g1ver != 3) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 3, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 129 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 13, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 163 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 13, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 164 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 23, &g1num, &g1ver)))
            return ret;
        if (g1num != 178 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 32, &g1num, &g1ver)))
            return ret;
        if (g1num != 179 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 206, &g1num, &g1ver)))
            return ret;
        if (g1num != 186 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 17, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 187 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 206, &g1num, &g1ver)))
            return ret;
        if (g1num != 188 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 15, &g1num, &g1ver)))
            return ret;
        if (g1num != 189 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 207, &g1num, &g1ver)))
            return ret;
        if (g1num != 198 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 208, &g1num, &g1ver)))
            return ret;
        if (g1num != 239 || g1ver != 2)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 3, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 128 || g1ver != 2) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 3, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 137 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 141 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 200 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 201 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 207, &g1num, &g1ver)))
            return ret;
        if (g1num != 201 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 204, &g1num, &g1ver)))
            return ret;
        if (g1num != 209 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 216 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 16, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 211 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 16, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 212 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 161 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 209, &g1num, &g1ver)))
            return ret;
        if (g1num != 168 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 210, &g1num, &g1ver)))
            return ret;
        if (g1num != 169 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 201, &g1num, &g1ver)))
            return ret;
        if (g1num != 181 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 202, &g1num, &g1ver)))
            return ret;
        if (g1num != 182 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 203, &g1num, &g1ver)))
            return ret;
        if (g1num != 183 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 204, &g1num, &g1ver)))
            return ret;
        if (g1num != 184 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 254 || g1ver != 128)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(10, 2, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 91 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 49 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 50 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 80 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 82 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 88 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 49 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 50 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 80 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 88 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 40 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 67 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 2 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 7 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 130 || g1ver != 128) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 1, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 217 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 27, &g1num, &g1ver)))
            return ret;
        if (g1num != 218 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 29, &g1num, &g1ver)))
            return ret;
        if (g1num != 161 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 16, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 165 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 16, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 166 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 16, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 167 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 192 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 193 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 188 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 201, &g1num, &g1ver)))
            return ret;
        if (g1num != 189 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 202, &g1num, &g1ver)))
            return ret;
        if (g1num != 207 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 203, &g1num, &g1ver)))
            return ret;
        if (g1num != 208 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 198 || g1ver != 129)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 2, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 33 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 34 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 2 || g1ver != 1) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 7 || g1ver != 1) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(10, 4, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 186 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 187 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 177 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 178 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 179 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 183 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 1, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 184 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 205, &g1num, &g1ver)))
            return ret;
        if (g1num != 179 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 206, &g1num, &g1ver)))
            return ret;
        if (g1num != 185 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 207, &g1num, &g1ver)))
            return ret;
        if (g1num != 186 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 208, &g1num, &g1ver)))
            return ret;
        if (g1num != 187 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 209, &g1num, &g1ver)))
            return ret;
        if (g1num != 177 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 210, &g1num, &g1ver)))
            return ret;
        if (g1num != 178 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 211, &g1num, &g1ver)))
            return ret;
        if (g1num != 189 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 212, &g1num, &g1ver)))
            return ret;
        if (g1num != 190 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 213, &g1num, &g1ver)))
            return ret;
        if (g1num != 191 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 214, &g1num, &g1ver)))
            return ret;
        if (g1num != 192 || g1ver != 130)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(10, 0, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 149 || g1ver != 129) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 1, 211, &g1num, &g1ver)))
            return ret;
        if (g1num != 188 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 205, &g1num, &g1ver)))
            return ret;
        if (g1num != 192 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 13, &g1num, &g1ver)))
            return ret;
        if (g1num != 219 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 12, &g1num, &g1ver)))
            return ret;
        if (g1num != 220 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 228, &g1num, &g1ver)))
            return ret;
        if (g1num != 179 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 212, &g1num, &g1ver)))
            return ret;
        if (g1num != 198 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 199 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 229, &g1num, &g1ver)))
            return ret;
        if (g1num != 200 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 230, &g1num, &g1ver)))
            return ret;
        if (g1num != 210 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 204, &g1num, &g1ver)))
            return ret;
        if (g1num != 182 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 241 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 242 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 20, &g1num, &g1ver)))
            return ret;
        if (g1num != 168 || g1ver != 140)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 19, 20, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 169 || g1ver != 140) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 19, 21, &g1num, &g1ver)))
            return ret;
        if (g1num != 170 || g1ver != 140)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 19, 21, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 171 || g1ver != 140) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 19, 22, &g1num, &g1ver)))
            return ret;
        if (g1num != 172 || g1ver != 140)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 19, 22, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 173 || g1ver != 140) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 6, 25, &g1num, &g1ver)))
            return ret;
        if (g1num != 174 || g1ver != 140)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 175 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 176 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 177 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 178 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 179 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 180 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 181 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 182 || g1ver != 140) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 76 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 104 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 105 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 106 || g1ver != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 102 || g1ver != 0) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(3, 192, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 213 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(3, 192, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 214 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(3, 192, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 215 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(3, 192, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 216 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(3, 192, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 221 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(3, 192, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 222 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 192, &g1num, &g1ver)))
            return ret;
        if (g1num != 228 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 193, &g1num, &g1ver)))
            return ret;
        if (g1num != 229 || g1ver != 129)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 2, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 149 || g1ver != 2) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 192, 1, &g1num, &g1ver)))
            return ret;
        if (g1num != 150 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 2, &g1num, &g1ver)))
            return ret;
        if (g1num != 151 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 3, &g1num, &g1ver)))
            return ret;
        if (g1num != 152 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 202 || g1ver != 129)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 2, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 33 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 34 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 40 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 17, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 124 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 18, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 125 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 8 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 13 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 88 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 49 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 50 || g1ver != 3) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 0, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 215 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 217 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 3, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 154 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 250 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 251 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 160 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 162 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 163 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 164 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 5, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 165 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 166 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 201, &g1num, &g1ver)))
            return ret;
        if (g1num != 167 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 202, &g1num, &g1ver)))
            return ret;
        if (g1num != 168 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 203, &g1num, &g1ver)))
            return ret;
        if (g1num != 169 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 206 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 219 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 206, &g1num, &g1ver)))
            return ret;
        if (g1num != 220 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 201, &g1num, &g1ver)))
            return ret;
        if (g1num != 244 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 202, &g1num, &g1ver)))
            return ret;
        if (g1num != 246 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 213, &g1num, &g1ver)))
            return ret;
        if (g1num != 243 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 214, &g1num, &g1ver)))
            return ret;
        if (g1num != 245 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 215, &g1num, &g1ver)))
            return ret;
        if (g1num != 249 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 208, &g1num, &g1ver)))
            return ret;
        if (g1num != 247 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 209, &g1num, &g1ver)))
            return ret;
        if (g1num != 248 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 202 || g1ver != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 204, &g1num, &g1ver)))
            return ret;
        if (g1num != 232 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 4, 205, &g1num, &g1ver)))
            return ret;
        if (g1num != 233 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 6, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 231 || g1ver != 2)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 7, 195, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 202 || g1ver != 2) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 19, 232, &g1num, &g1ver)))
            return ret;
        if (g1num != 203 || g1ver != 2)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 1, 201, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 238 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 66 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 133 || g1ver != 2) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 134 || g1ver != 2) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(10, 4, 194, &g1num, &g1ver)))
            return ret;
        if (g1num != 191 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 195 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 171 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 180 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 193 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 200, &g1num, &g1ver)))
            return ret;
        if (g1num != 194 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 201, &g1num, &g1ver)))
            return ret;
        if (g1num != 190 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 185 || g1ver != 128)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 3, 202, &g1num, &g1ver)))
            return ret;
        if (g1num != 199 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(10, 4, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 197 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 216, &g1num, &g1ver)))
            return ret;
        if (g1num != 159 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 191, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 175 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 65, &g1num, &g1ver)))
            return ret;
        if (g1num != 223 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 66, &g1num, &g1ver)))
            return ret;
        if (g1num != 224 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 67, &g1num, &g1ver)))
            return ret;
        if (g1num != 225 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 68, &g1num, &g1ver)))
            return ret;
        if (g1num != 226 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 227 || g1ver != 129)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(2, 0, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 87 || g1ver != 3) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(1, 1, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 130 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 4, &g1num, &g1ver)))
            return ret;
        if (g1num != 240 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 5, &g1num, &g1ver)))
            return ret;
        if (g1num != 164 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 6, &g1num, &g1ver)))
            return ret;
        if (g1num != 165 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 7, &g1num, &g1ver)))
            return ret;
        if (g1num != 166 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 8, &g1num, &g1ver)))
            return ret;
        if (g1num != 167 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 9, &g1num, &g1ver)))
            return ret;
        if (g1num != 168 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 10, &g1num, &g1ver)))
            return ret;
        if (g1num != 169 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 11, &g1num, &g1ver)))
            return ret;
        if (g1num != 203 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 12, &g1num, &g1ver)))
            return ret;
        if (g1num != 206 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 13, &g1num, &g1ver)))
            return ret;
        if (g1num != 220 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 192, 14, &g1num, &g1ver)))
            return ret;
        if (g1num != 234 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 0, 203, &g1num, &g1ver)))
            return ret;
        if (g1num != 201 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 218, &g1num, &g1ver)))
            return ret;
        if (g1num != 195 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 219, &g1num, &g1ver)))
            return ret;
        if (g1num != 204 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 220, &g1num, &g1ver)))
            return ret;
        if (g1num != 205 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 210, &g1num, &g1ver)))
            return ret;
        if (g1num != 181 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 211, &g1num, &g1ver)))
            return ret;
        if (g1num != 182 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 212, &g1num, &g1ver)))
            return ret;
        if (g1num != 183 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 213, &g1num, &g1ver)))
            return ret;
        if (g1num != 184 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 214, &g1num, &g1ver)))
            return ret;
        if (g1num != 236 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 215, &g1num, &g1ver)))
            return ret;
        if (g1num != 154 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 216, &g1num, &g1ver)))
            return ret;
        if (g1num != 196 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 217, &g1num, &g1ver)))
            return ret;
        if (g1num != 197 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 207, &g1num, &g1ver)))
            return ret;
        if (g1num != 202 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 208, &g1num, &g1ver)))
            return ret;
        if (g1num != 209 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 209, &g1num, &g1ver)))
            return ret;
        if (g1num != 219 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 1, 217, &g1num, &g1ver)))
            return ret;
        if (g1num != 173 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 195, &g1num, &g1ver)))
            return ret;
        if (g1num != 174 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 196, &g1num, &g1ver)))
            return ret;
        if (g1num != 175 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 197, &g1num, &g1ver)))
            return ret;
        if (g1num != 188 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 139 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 14, 199, &g1num, &g1ver)))
            return ret;
        if (g1num != 239 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 208, &g1num, &g1ver)))
            return ret;
        if (g1num != 185 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(2, 0, 209, &g1num, &g1ver)))
            return ret;
        if (g1num != 186 || g1ver != 133)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 218, &g1num, &g1ver)))
            return ret;
        if (g1num != 193 || g1ver != 133)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 0, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 229 || g1ver != 130) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g2tog1(0, 0, 204, &g1num, &g1ver)))
            return ret;
        if (g1num != 194 || g1ver != 129)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 19, 219, &g1num, &g1ver)))
            return ret;
        if (g1num != 185 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 7, 198, &g1num, &g1ver)))
            return ret;
        if (g1num != 182 || g1ver != 130)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 3, 210, &g1num, &g1ver)))
            return ret;
        if (g1num != 173 || g1ver != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g2tog1(0, 2, 218, &g1num, &g1ver)))
            return ret;
        if (g1num != 174 || g1ver != 2)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 1 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 2 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 3 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 4 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 5 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 6 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 7 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 8 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 9 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 14, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 10 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 11 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 12 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 13 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 14 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 15 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 16 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 17 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 18 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 19 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 20 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 21 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 22 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 23 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 24 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 25 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 26 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 27 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 28 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 29 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 30 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 31 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 32 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 33 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 34 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 35 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 36 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 37 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 38 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 39 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 40 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 41 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 42 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 43 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 44 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 15, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 45 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 16, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 46 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 47 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 48 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 49 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 50 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 51 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 52 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 53 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 54 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 55 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 56 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 57 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 58 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 59 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 60 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 61 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 62 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 63 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 64 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 65 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 66 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 67 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 68 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 69 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 70 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 71 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 72 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 73 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 74 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 75 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 76 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 77 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 78 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 15, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 79 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 80 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 81 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 82 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 83 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 84 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 85 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 86 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 87 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 88 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 89 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 90 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 91 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 92 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 93 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 94 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 95 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 96 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 97 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 98 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 16, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 99 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 100 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 101 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 102 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 103 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 104 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 105 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 106 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 107 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 108 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 109 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 110 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 111 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 112 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 113 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 114 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 115 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 116 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 117 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 118 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 119 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 120 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 121 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 122 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 20, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 123 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 17, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 124 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 18, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 125 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 19, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 126 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* /\* if ((ret = g2c_param_g2tog1(255, 255, 255, &g1num, &g1ver))) *\/ */
        /* /\*     return ret; *\/ */
        /* /\* if (g1num != 127 || g1ver != 131) *\/ */
        /* /\*     return G2C_ERROR; *\/ */
        /* if ((ret = g2c_param_g2tog1(0, 3, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 128 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 130 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 131 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 132 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 212, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 134 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 197, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 135 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 136 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 219, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 137 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 140 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 141 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 142 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 195, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 143 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 144 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 200, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 145 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 210, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 146 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 200, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 147 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 201, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 148 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 202, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 149 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 211, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 150 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 212, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 151 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 213, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 152 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 22, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 153 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 155 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 156 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 157 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 158 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 159 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 160 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 29, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 161 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 221, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 162 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 214, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 163 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 215, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 164 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 222, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 165 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 200, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 166 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 201, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 167 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 202, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 168 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 203, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 169 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 170 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 171 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 172 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 210, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 173 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 218, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 174 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 191, 195, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 175 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 191, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 176 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 191, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 177 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 178 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 228, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 179 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 17, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 180 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 199, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 181 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 198, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 182 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 216, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 183 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 19, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 184 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 217, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 187 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 206, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 188 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 218, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 189 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 190 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 191, 196, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 191 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 191, 197, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 192 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 1, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 194 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 196 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 195, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 197 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 212, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 198 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 198, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 199 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 229, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 200 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 223, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 202 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 200, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 203 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 204 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 205 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 224, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 206 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 207 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 195, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 208 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 230, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 210 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 211 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 212 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 213 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 196, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 214 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 216 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 211, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 218 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 201, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 219 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 203, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 220 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 196, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 221 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 222 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 196, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 223 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 224 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 198, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 225 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 197, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 226 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 219, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 227 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 199, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 228 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* /\* if ((ret = g2c_param_g2tog1(0, 0, 192, &g1num, &g1ver))) *\/ */
        /* /\*     return ret; *\/ */
        /* /\* if (g1num != 229 || g1ver != 131) *\/ */
        /* /\*     return G2C_ERROR; *\/ */
        /* if ((ret = g2c_param_g2tog1(2, 3, 195, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 230 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 196, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 231 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 220, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 232 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 221, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 233 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 234 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 193, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 235 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 222, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 237 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 201, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 238 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 208, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 239 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 197, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 240 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 223, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 241 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 224, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 242 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 225, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 243 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 226, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 244 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 227, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 245 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 202, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 246 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 203, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 247 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 204, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 248 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 205, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 249 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 197, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 250 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 251 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 196, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 252 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 197, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 253 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 254 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 62 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 63 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 203, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 220 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 14, 200, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 231 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 14, 201, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 232 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 16, 197, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 240 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 201, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 191 || g1ver != 133) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 14, 202, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 233 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 14, 203, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 234 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 242, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 242 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 243, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 243 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 244, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 244 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 245, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 245 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 246, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 246 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 247, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 247 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 248, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 248 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 249, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 249 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 1 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 52 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 63 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 61 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 41 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 100 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 101 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 103 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 104 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 105 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 107 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 108 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 109 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 110 || g1ver != 3) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 191, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 192 || g1ver != 133) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 225, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 193 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 227, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 194 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 241, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 195 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 196 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 195 || g1ver != 128) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 196 || g1ver != 128) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 197 || g1ver != 128) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 64 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 241 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 242 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 243 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 244 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 16, 198, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 235 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 199, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 236 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 220, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 237 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 221, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 238 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 222, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 253 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 223, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 254 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 224, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 241 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 250 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 234, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 175 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 233, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 176 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 217, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 236 || g1ver != 2) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 242, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 230 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 206 || g1ver != 130) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 255, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 102, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 103, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 104, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 105, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 106, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 107, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 108, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 109, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 110, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 59, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 21, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 193 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 17, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 137 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 39, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 194 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 203, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 144 || g1ver != 128) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 20, 101, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 37, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 214 || g1ver != 131) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 28, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 0, 29, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 129, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 130, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 131, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 132, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 133, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 134, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 135, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 136, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 137, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 138, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 139, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 140, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 141, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 142, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 231, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 232, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 233, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 234, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 1, 235, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 231, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 232, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 2, 36, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 20, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 21, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 22, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 24, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 25, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 26, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 27, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 28, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 29, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 30, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 3, 31, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 50, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 52, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 4, 53, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 5, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 34, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 35, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 36, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 37, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 38, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 39, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 40, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 47, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 48, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 6, 49, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 19, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 203, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 204, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 205, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 206, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 7, 206, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 15, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 15, 16, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 17, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 17, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 17, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 17, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 18, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 18, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 18, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 28, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 29, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 30, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 31, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 32, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 33, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 34, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 35, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 36, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 37, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 19, 238, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 15, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 16, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 2, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 35, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 36, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 37, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 38, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 0, 39, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 1, 192, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 18, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 19, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 20, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 21, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 22, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 4, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 5, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 1, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 7, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 8, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 0, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 1, 194, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 2, 0, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 53, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 54, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 55, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 56, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 57, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 58, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 59, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 60, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(3, 192, 61, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 15, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 16, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 17, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 18, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 19, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 20, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 21, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 22, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 23, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 24, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 25, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 26, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 27, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 28, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 29, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 30, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 31, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 32, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 33, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 34, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 35, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 36, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 37, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 38, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 39, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 40, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 41, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 42, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 43, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 44, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 45, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 46, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 47, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 48, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 49, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 50, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 51, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 52, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 53, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 54, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 55, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 56, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 57, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 58, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 59, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 60, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 61, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 62, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 63, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 0, 64, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 1, 4, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 9, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 10, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 11, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 2, 12, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 2, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 204, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 13, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 205, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 206, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 207, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 208, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 209, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 210, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 250, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 251, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 252, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 3, 253, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 14, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 15, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 16, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 17, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 18, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 19, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 20, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(10, 4, 21, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 255 || g1ver != 255) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(0, 16, 3, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 240 || g1ver != 129) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 234 || g1ver != 2) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(1, 0, 6, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 235 || g1ver != 2) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g2tog1(2, 3, 5, &g1num, &g1ver))) */
        /*     return ret; */
        /* if (g1num != 160 || g1ver != 130) */
        /*     return G2C_ERROR; */
    }
    printf("ok!\n");
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

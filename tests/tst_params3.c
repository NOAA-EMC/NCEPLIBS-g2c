/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cparams.c.
 *
 * Ed Hartnett 9/21/22
 */
#include "grib2_int.h"

int
main()
{
    printf("Testing params handling for all g2c_param_g1tog2() calls.\n");

    printf("Testing all values with g2c_param_g1tog2()...");
    {
        int g2disc, g2cat, g2num;
        int ret;
        
        /* This will work. */
        if ((ret = g2c_param_g1tog2(1, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;

        if ((ret = g2c_param_g1tog2(1, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(1, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;


        if ((ret = g2c_param_g1tog2(2, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(3, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(4, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 14)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(5, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(6, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(7, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(8, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(9, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(10, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(11, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(12, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(13, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(14, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(15, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(16, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(17, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(18, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(19, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(20, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(21, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 15 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(22, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 15 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(23, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 15 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(24, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(25, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(26, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(27, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(28, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(29, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(30, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(31, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(32, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(33, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(34, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(35, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(36, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(37, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(38, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(39, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(40, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(41, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(42, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(43, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(44, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(45, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 15)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(46, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 16)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(47, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(48, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(49, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(50, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(51, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(52, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(53, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(54, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(55, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(56, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(57, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(58, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(59, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(60, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(61, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(62, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(63, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(64, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(65, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(66, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(67, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(68, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(69, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(70, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(71, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(72, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(73, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(74, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(75, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(76, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(77, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(78, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 14)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(79, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 15)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(80, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(81, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(82, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(83, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(84, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(85, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(86, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(87, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(88, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(89, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(90, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(91, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(92, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(93, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(94, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(95, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(96, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(97, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(98, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(99, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 16)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(100, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(101, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(102, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(103, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(104, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(105, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(106, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(107, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(108, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(109, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(110, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(111, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(112, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(113, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(114, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(115, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(116, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(117, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(118, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(119, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(120, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(121, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(122, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(123, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 20)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(124, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 17)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(125, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 18)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(126, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 19)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(127, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(229, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(153, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 22)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(140, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(141, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(142, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(143, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(214, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(135, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(194, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 1 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(228, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(136, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(172, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(196, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(197, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(252, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(253, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(130, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(204, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(211, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(205, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(212, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(213, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(132, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(157, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(156, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(190, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(131, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(158, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(176, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(177, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(234, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(235, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 0 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(144, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(155, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(207, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(208, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(223, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(226, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(154, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(222, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(145, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(146, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(147, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(148, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(221, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(230, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(160, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(171, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(219, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(222, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(224, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(225, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(230, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(231, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(238, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(240, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(131, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(132, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(133, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(134, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(135, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(136, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(137, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(138, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(139, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 205)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(140, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(159, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(170, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(170, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 24)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(171, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 25)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(181, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(203, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(246, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(247, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(248, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(249, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 205)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(254, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(190, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 1 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(191, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 1 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(171, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(180, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(181, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(193, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(195, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 1 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(180, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 22)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(31, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(32, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(33, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(34, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(100, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(101, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(103, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(107, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(108, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(109, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(110, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(156, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 13 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(157, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 13 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(11, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(129, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(163, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 13 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(164, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 13 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(178, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 23)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(179, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 32)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(186, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 206)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(187, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 17 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(188, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 206)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(189, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 15)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(198, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 207)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(239, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 208)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(128, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(137, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(141, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(200, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(201, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(201, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 207)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(209, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(216, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(211, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 16 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(212, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 16 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(161, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(168, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 209)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(169, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 210)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(181, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(182, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(183, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(184, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(254, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(91, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(49, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(50, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(80, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(82, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(88, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(49, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(50, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(80, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(88, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(40, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(67, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(2, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(7, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(130, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(217, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(218, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 27)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(161, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 29)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(165, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 16 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(166, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 16 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(167, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 16 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(192, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(193, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(188, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(189, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(207, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(208, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(198, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(33, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(34, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(2, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(7, 1, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(186, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(187, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(177, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(178, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(179, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(183, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(184, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(179, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 205)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(185, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 206)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(186, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 207)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(187, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 208)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(177, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 209)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(178, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 210)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(189, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 211)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(190, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 212)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(191, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 213)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(192, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 214)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(149, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(188, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 211)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(192, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 205)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(219, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(220, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(179, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 228)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(198, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 212)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(199, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(200, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 229)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(210, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 230)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(182, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(241, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(242, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(168, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 20)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(169, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 20)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(170, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 21)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(171, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 21)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(172, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 22)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(173, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 22)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(174, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 25)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(175, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(176, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(177, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(178, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(179, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(180, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(181, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(182, 140, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(76, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(104, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(105, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(106, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(102, 0, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(213, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(214, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(215, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(216, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(221, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(222, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(228, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(229, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(149, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 14)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(150, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(151, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(152, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(202, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(33, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(34, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(40, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(124, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 17)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(125, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 18)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(8, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(13, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(88, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(49, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(50, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(215, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(217, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(154, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(250, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(251, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(160, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(162, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(163, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(164, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(165, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(166, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(167, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(168, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(169, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(206, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(219, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(220, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 206)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(244, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(246, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(243, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 213)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(245, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 214)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(249, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 215)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(247, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 208)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(248, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 209)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(202, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(232, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(233, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 205)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(231, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(202, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(203, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 232)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(238, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(66, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(133, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(134, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(191, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(195, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(171, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(180, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(193, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(194, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(190, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(185, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(199, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(197, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(159, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 216)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(175, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(223, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 65)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(224, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 66)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(225, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 67)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(226, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 68)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(227, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(87, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(130, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 1 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(240, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(164, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(165, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(166, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(167, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(168, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(169, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(203, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(206, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(220, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(234, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 192 || g2num != 14)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(201, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(195, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 218)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(204, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 219)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(205, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 220)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(181, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 210)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(182, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 211)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(183, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 212)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(184, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 213)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(236, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 214)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(154, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 215)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(196, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 216)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(197, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 217)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(202, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 207)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(209, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 208)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(219, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 209)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(173, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 217)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(174, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(175, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(188, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(139, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(239, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(185, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 208)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(186, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 209)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(193, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 218)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(229, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(194, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(185, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 219)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(182, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(173, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 210)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(174, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 218)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(1, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(2, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(3, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(4, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 14)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(5, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(6, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(7, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(8, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(9, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(10, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(11, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(12, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(13, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(14, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(15, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(16, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(17, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(18, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(19, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(20, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(21, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 15 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(22, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 15 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(23, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 15 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(24, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(25, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(26, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(27, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(28, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(29, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(30, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(31, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(32, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(33, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(34, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(35, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(36, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(37, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(38, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(39, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(40, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(41, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(42, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(43, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(44, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(45, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 15)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(46, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 16)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(47, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(48, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(49, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(50, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 1 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(51, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(52, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(53, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(54, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(55, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(56, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(57, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(58, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(59, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(60, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(61, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(62, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(63, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(64, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(65, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(66, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(67, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(68, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(69, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(70, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(71, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(72, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(73, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(74, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(75, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(76, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(77, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(78, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 14)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(79, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 15)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(80, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(81, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(82, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(83, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(84, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(85, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(86, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(87, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(88, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(89, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(90, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(91, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(92, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(93, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(94, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(95, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(96, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(97, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(98, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 2 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(99, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 16)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(100, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(101, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(102, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(103, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(104, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(105, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(106, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(107, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(108, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(109, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(110, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(111, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(112, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(113, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(114, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(115, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(116, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(117, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(118, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(119, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(120, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(121, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(122, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(123, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 20)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(124, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 17)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(125, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 18)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(126, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 19)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(127, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 255 || g2cat != 255 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(128, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(130, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(131, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(132, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(134, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 212)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(135, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(136, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(137, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 219)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(140, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(141, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(142, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(143, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(144, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(145, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(146, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 210)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(147, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(148, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(149, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(150, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 211)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(151, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 212)
            return G2C_ERROR;
/*  606,   152,   131,     2,     0,   213, EWATR    */
/*  607,   153,   131,     0,     1,    22, CLWMR    */
/*  608,   155,   131,     2,     0,   193, GFLUX    */
/*  609,   156,   131,     0,     7,     7, CIN      */
/*  610,   157,   131,     0,     7,     6, CAPE     */
/*  611,   158,   131,     0,    19,    11, TKE      */
/*  612,   159,   131,     0,    19,   192, MXSALB   */
/*  613,   160,   131,     2,     3,   192, SOILL    */
/*  614,   161,   131,     0,     1,    29, ASNOW    */
/*  615,   162,   131,     0,     1,   221, ARAIN    */
/*  616,   163,   131,     2,     0,   214, GWREC    */
/*  617,   164,   131,     2,     0,   215, QREC     */
/*  618,   165,   131,     0,     1,   222, SNOWT    */
/*  619,   166,   131,     0,     4,   200, VBDSF    */
/*  620,   167,   131,     0,     4,   201, VDDSF    */
/*  621,   168,   131,     0,     4,   202, NBDSF    */
/*  622,   169,   131,     0,     4,   203, NDDSF    */
/*  623,   170,   131,     0,    19,   193, SNFALB   */
/*  624,   171,   131,     2,     3,   193, RLYRS    */
/*  625,   172,   131,     0,     2,   193, MFLX     */
/*  626,   173,   131,     0,     3,   210, LMH      */
/*  627,   174,   131,     0,     2,   218, LMV      */
/*  628,   175,   131,     0,   191,   195, MLYNO    */
/*  629,   176,   131,     0,   191,   192, NLAT     */
/*  630,   177,   131,     0,   191,   193, ELON     */
/*  631,   178,   131,     0,     1,    23, ICMR     */
/*  632,   179,   131,     2,     0,   228, ACOND    */
/*  633,   180,   131,     0,     1,    17, SNOAG    */
/*  634,   181,   131,     2,     0,   199, CCOND    */
/*  635,   182,   131,     0,     7,   198, LAI      */
/*  636,   183,   131,     2,     0,   216, SFCRH    */
/*  637,   184,   131,     0,    19,    19, SALBD    */
/*  638,   187,   131,     2,     0,   217, NDVI     */
/*  639,   188,   131,     2,     0,   206, RDRIP    */
/*  640,   189,   131,     2,     0,   218, LANDN    */
/*  641,   190,   131,     0,     7,     8, HLCY     */
/*  642,   191,   131,     0,   191,   196, NLATN    */
/*  643,   192,   131,     0,   191,   197, ELONN    */
/*  644,   194,   131,     1,     1,   193, CPOFP    */
/*  645,   196,   131,     0,     2,   194, USTM     */
/*  646,   197,   131,     0,     2,   195, VSTM     */
/*  647,   198,   131,     0,     1,   212, SBSNO    */
/*  648,   199,   131,     2,     3,   198, EVBS     */
/*  649,   200,   131,     2,     0,   229, EVCW     */
/*  650,   202,   131,     0,     1,   223, APCPN    */
/*  651,   203,   131,     2,     0,   200, RSMIN    */
/*  652,   204,   131,     0,     4,   192, DSWRF    */
/*  653,   205,   131,     0,     5,   192, DLWRF    */
/*  654,   206,   131,     0,     1,   224, ACPCPN   */
/*  655,   207,   131,     2,     0,   194, MSTAV    */
/*  656,   208,   131,     2,     0,   195, SFEXC    */
/*  657,   210,   131,     2,     0,   230, TRANS    */
/*  658,   211,   131,     0,     4,   193, USWRF    */
/*  659,   212,   131,     0,     5,   193, ULWRF    */
/*  660,   213,   131,     0,     6,   192, CDLYR    */
/*  661,   214,   131,     0,     1,   196, CPRAT    */
/*  662,   216,   131,     0,     0,   193, TTRAD    */
/*  663,   218,   131,     0,     3,   211, HGTN     */
/*  664,   219,   131,     2,     0,   201, WILT     */
/*  665,   220,   130,     2,     3,   203, FLDCP    */
/*  666,   221,   131,     0,     3,   196, HPBL     */
/*  667,   222,   131,     2,     3,   194, SLTYP    */
/*  668,   223,   131,     2,     0,   196, CNWAT    */
/*  669,   224,   131,     2,     3,     0, SOTYP    */
/*  670,   225,   131,     2,     0,   198, VGTYP    */
/*  671,   226,   131,     2,     0,   197, BMIXL    */
/*  672,   227,   131,     2,     0,   219, AMIXL    */
/*  673,   228,   131,     0,     1,   199, PEVAP    */
/*  674,   229,   131,     0,     0,   192, SNOHF    */
/*  675,   230,   131,     2,     3,   195, SMREF    */
/*  676,   231,   131,     2,     3,   196, SMDRY    */
/*  677,   232,   131,     2,     0,   220, WVINC    */
/*  678,   233,   131,     2,     0,   221, WCINC    */
/*  679,   234,   131,     1,     0,   192, BGRUN    */
/*  680,   235,   131,     1,     0,   193, SSRUN    */
/*  681,   237,   131,     2,     0,   222, WVCONV   */
/*  682,   238,   131,     0,     1,   201, SNOWC    */
/*  683,   239,   131,     0,     1,   208, SNOT     */
/*  684,   240,   131,     2,     3,   197, POROS    */
/*  685,   241,   131,     2,     0,   223, WCCONV   */
/*  686,   242,   131,     2,     0,   224, WVUFLX   */
/*  687,   243,   131,     2,     0,   225, WVVFLX   */
/*  688,   244,   131,     2,     0,   226, WCUFLX   */
/*  689,   245,   131,     2,     0,   227, WCVFLX   */
/*  690,   246,   131,     2,     0,   202, RCS      */
/*  691,   247,   131,     2,     0,   203, RCT      */
/*  692,   248,   131,     2,     0,   204, RCQ      */
/*  693,   249,   131,     2,     0,   205, RCSOL    */
/*  694,   250,   131,     0,     4,   197, SWHR     */
/*  695,   251,   131,     0,     5,   194, LWHR     */
/*  696,   252,   131,     0,     2,   196, CD       */
/*  697,   253,   131,     0,     2,   197, FRICV    */
/*  698,   254,   131,     0,     7,   194, RI       */
/*  699,    62,   129,     0,     1,     9, NCPCP    */
/*  700,    63,   129,     0,     1,    10, ACPCP    */
/*  701,   220,   131,     2,     3,   203, FLDCP    */
/*  702,   231,   129,     0,    14,   200, OZMAX1   */
/*  703,   232,   129,     0,    14,   201, OZMAX8   */
/*  704,   240,   129,     0,    16,   197, RETOP    */
/*  705,   191,   133,     0,     6,   201, SUNSD    */
/*  706,   233,   129,     0,    14,   202, PDMAX1   */
/*  707,   234,   129,     0,    14,   203, PDMAX24  */
/*  708,   242,   129,    10,     3,   242, TCSRG20  */
/*  709,   243,   129,    10,     3,   243, TCSRG30  */
/*  710,   244,   129,    10,     3,   244, TCSRG40  */
/*  711,   245,   129,    10,     3,   245, TCSRG50  */
/*  712,   246,   129,    10,     3,   246, TCSRG60  */
/*  713,   247,   129,    10,     3,   247, TCSRG70  */
/*  714,   248,   129,    10,     3,   248, TCSRG80  */
/*  715,   249,   129,    10,     3,   249, TCSRG90  */
/*  716,     1,     3,     0,     3,     0, PRES     */
/*  717,    52,     3,     0,     1,     1, RH       */
/*  718,    63,     3,     0,     1,    10, ACPCP    */
/*  719,    61,     3,     0,     1,     8, APCP     */
/*  720,    41,     3,     0,     2,    10, ABSV     */
/*  721,   100,     3,    10,     0,     3, HTSGW    */
/*  722,   101,     3,    10,     0,     4, WVDIR    */
/*  723,   103,     3,    10,     0,     6, WVPER    */
/*  724,   104,     3,    10,     0,     7, SWDIR    */
/*  725,   105,     3,    10,     0,     8, SWELL    */
/*  726,   107,     3,    10,     0,    10, DIRPW    */
/*  727,   108,     3,    10,     0,    11, PERPW    */
/*  728,   109,     3,    10,     0,    12, DIRSW    */
/*  729,   110,     3,    10,     0,    13, PERSW    */
/*  730,   192,   133,    10,   191,     1, MOSF     */
/*  731,   193,   130,     0,     1,   225, FRZR     */
/*  732,   194,   130,     0,     1,   227, FROZR    */
/*  733,   195,   130,     0,     1,   241, TSNOW    */
/*  734,   196,   130,     2,     0,     7, MTERH    */
/*  735,   195,   128,    10,     4,     4, OVHD     */
/*  736,   196,   128,    10,     4,     5, OVSD     */
/*  737,   197,   128,    10,     4,     6, OVMD     */
/*  738,    64,   130,     0,     1,    12, SRWEQ    */
/*  739,   241,   130,     3,   192,     6, SBT112   */
/*  740,   242,   130,     3,   192,     7, SBT113   */
/*  741,   243,   130,     3,   192,     8, SBT114   */
/*  742,   244,   130,     3,   192,     9, SBT115   */
/*  743,   235,   129,     0,    16,   198, MAXREF   */
/*  744,   236,   129,     0,     7,   199, MXUPHL   */
/*  745,   237,   129,     0,     2,   220, MAXUVV   */
/*  746,   238,   129,     0,     2,   221, MAXDVV   */
/*  747,   253,   129,     0,     2,   222, MAXUW    */
/*  748,   254,   129,     0,     2,   223, MAXVW    */
/*  749,   241,   129,     0,     2,   224, VRATE    */
/*  750,   250,   129,     2,     4,     2, HINDEX   */
/*  751,   175,   129,     0,    19,   234, ICSEV    */
/*  752,   176,   129,     0,    19,   233, ICPRB    */
/*  753,   236,     2,     0,    19,   217, SIPD     */
/*  754,   230,   129,     0,     1,   242, RHPW     */
/*  755,   206,   130,     0,    15,     3, VIL      */
/*  756,   255,   255,     0,     0,   255, MISSING  */
/*  757,   255,   255,     0,    20,   102, AOTK     */
/*  758,   255,   255,     0,    20,   103, SSALBK   */
/*  759,   255,   255,     0,    20,   104, ASYSFK   */
/*  760,   255,   255,     0,    20,   105, AECOEF   */
/*  761,   255,   255,     0,    20,   106, AACOEF   */
/*  762,   255,   255,     0,    20,   107, ALBSAT   */
/*  763,   255,   255,     0,    20,   108, ALBGRD   */
/*  764,   255,   255,     0,    20,   109, ALESAT   */
/*  765,   255,   255,     0,    20,   110, ALEGRD   */
/*  766,   255,   255,     0,    20,     9, WLSMFLX  */
/*  767,   255,   255,     0,    20,    10, WDCPMFLX */
/*  768,   255,   255,     0,    20,    11, SEDMFLX  */
/*  769,   255,   255,     0,    20,    12, DDMFLX   */
/*  770,   255,   255,     0,    20,    13, TRANHH   */
/*  771,   255,   255,     0,    20,    14, TRSDS    */
/*  772,   255,   255,     0,    20,    59, ANCON    */
/*  773,   193,   131,     0,     0,    21, APTMP    */
/*  774,   137,   131,     0,    17,     0, LTNGSD   */
/*  775,   194,   131,     0,     1,    39, CPOFP    */
/*  776,   144,   128,    10,     3,   203, LCH      */
/*  777,   255,   255,     0,    20,   101, ATMTK    */
/*  778,   214,   131,     0,     1,    37, CPRAT    */
/*  779,   255,   255,    10,     2,     8, ICETMP   */
/*  780,   255,   255,     0,     0,    28, UCTMP    */
/*  781,   255,   255,     0,     0,    29, TMPADV   */
/*  782,   255,   255,     0,     1,   129, EFRCWAT  */
/*  783,   255,   255,     0,     1,   130, EFRRAIN  */
/*  784,   255,   255,     0,     1,   131, EFRCICE  */
/*  785,   255,   255,     0,     1,   132, EFRSNOW  */
/*  786,   255,   255,     0,     1,   133, EFRGRL   */
/*  787,   255,   255,     0,     1,   134, EFRHAIL  */
/*  788,   255,   255,     0,     1,   135, EFRSLC   */
/*  789,   255,   255,     0,     1,   136, EFRSICEC */
/*  790,   255,   255,     0,     1,   137, EFARRAIN */
/*  791,   255,   255,     0,     1,   138, EFARCICE */
/*  792,   255,   255,     0,     1,   139, EFARSNOW */
/*  793,   255,   255,     0,     1,   140, EFARGRL  */
/*  794,   255,   255,     0,     1,   141, EFARHAIL */
/*  795,   255,   255,     0,     1,   142, EFARSIC  */
/*  796,   255,   255,     0,     1,   231, PPINDX   */
/*  797,   255,   255,     0,     1,   232, PROBCIP  */
/*  798,   255,   255,     0,     1,   233, SNOWLR   */
/*  799,   255,   255,     0,     1,   234, PCPDUR   */
/*  800,   255,   255,     0,     1,   235, CLLMR    */
/*  801,   255,   255,     0,     2,   231, TPWDIR   */
/*  802,   255,   255,     0,     2,   232, TPWSPD   */
/*  803,   255,   255,     0,     2,    36, AFRWE    */
/*  804,   255,   255,     0,     3,    20, SDSGSO   */
/*  805,   255,   255,     0,     3,    21, AOSGSO   */
/*  806,   255,   255,     0,     3,    22, SSGSO    */
/*  807,   255,   255,     0,     3,    23, GWD      */
/*  808,   255,   255,     0,     3,    24, ASGSO    */
/*  809,   255,   255,     0,     3,    25, NLPRES   */
/*  810,   255,   255,     0,     3,    26, EXPRES   */
/*  811,   255,   255,     0,     3,    27, UMFLX    */
/*  812,   255,   255,     0,     3,    28, DMFLX    */
/*  813,   255,   255,     0,     3,    29, UDRATE   */
/*  814,   255,   255,     0,     3,    30, DDRATE   */
/*  815,   255,   255,     0,     3,    31, UCLSPRS  */
/*  816,   255,   255,     0,     4,    50, UVIUCS   */
/*  817,   255,   255,     0,     4,    52, DSWRFCS  */
/*  818,   255,   255,     0,     4,    53, USWRFCS  */
/*  819,   255,   255,     0,     5,     5, NLWRF    */
/*  820,   255,   255,     0,     5,     6, NLWRCS   */
/*  821,   255,   255,     0,     5,     7, BRTEMP   */
/*  822,   255,   255,     0,     5,     8, DLWRFCS  */
/*  823,   255,   255,     0,     6,    34, SLWTC    */
/*  824,   255,   255,     0,     6,    35, SSWTC    */
/*  825,   255,   255,     0,     6,    36, FSTRPC   */
/*  826,   255,   255,     0,     6,    37, FCONPC   */
/*  827,   255,   255,     0,     6,    38, MASSDCD  */
/*  828,   255,   255,     0,     6,    39, MASSDCI  */
/*  829,   255,   255,     0,     6,    40, MDCCWD   */
/*  830,   255,   255,     0,     6,    47, VFRCWD   */
/*  831,   255,   255,     0,     6,    48, VFRCICE  */
/*  832,   255,   255,     0,     6,    49, VFRCIW   */
/*  833,   255,   255,     0,     7,    19, CONAPES  */
/*  834,   255,   255,     0,     7,   203, DCAPE    */
/*  835,   255,   255,     0,     7,   204, EFHL     */
/*  836,   255,   255,     0,     7,   205, ESP      */
/*  837,   255,   255,     0,     7,   206, CANGLE   */
/*  838,   255,   255,     0,     7,   206, CANGLE   */
/*  839,   255,   255,     0,    15,     9, RFCD     */
/*  840,   255,   255,     0,    15,    10, RFCI     */
/*  841,   255,   255,     0,    15,    11, RFSNOW   */
/*  842,   255,   255,     0,    15,    12, RFRAIN   */
/*  843,   255,   255,     0,    15,    13, RFGRPL   */
/*  844,   255,   255,     0,    15,    14, RFHAIL   */
/*  845,   255,   255,     0,    15,    15, HSR      */
/*  846,   255,   255,     0,    15,    16, HSRHT    */
/*  847,   255,   255,     0,    17,     1, LTPINX   */
/*  848,   255,   255,     0,    17,     2, CDGDLTFD */
/*  849,   255,   255,     0,    17,     3, CDCDLTFD */
/*  850,   255,   255,     0,    17,     4, TLGTFD   */
/*  851,   255,   255,     0,    18,     0, ACCES    */
/*  852,   255,   255,     0,    18,     1, ACIOD    */
/*  853,   255,   255,     0,    18,     2, ACRADP   */
/*  854,   255,   255,     0,    19,    28, MWTURB   */
/*  855,   255,   255,     0,    19,    29, CATEDR   */
/*  856,   255,   255,     0,    19,    30, EDPARM   */
/*  857,   255,   255,     0,    19,    31, MXEDPRM  */
/*  858,   255,   255,     0,    19,    32, HIFREL   */
/*  859,   255,   255,     0,    19,    33, VISLFOG  */
/*  860,   255,   255,     0,    19,    34, VISIFOG  */
/*  861,   255,   255,     0,    19,    35, VISBSN   */
/*  862,   255,   255,     0,    19,    36, PSNOWS   */
/*  863,   255,   255,     0,    19,    37, ICESEV   */
/*  864,   255,   255,     0,    19,   238, ELLINX   */
/*  865,   255,   255,     1,     0,     7, DISRS    */
/*  866,   255,   255,     1,     0,     8, GWUPS    */
/*  867,   255,   255,     1,     0,     9, GWLOWS   */
/*  868,   255,   255,     1,     0,    10, SFLORC   */
/*  869,   255,   255,     1,     0,    11, RVERSW   */
/*  870,   255,   255,     1,     0,    12, FLDPSW   */
/*  871,   255,   255,     1,     0,    13, DEPWSS   */
/*  872,   255,   255,     1,     0,    14, UPAPCP   */
/*  873,   255,   255,     1,     0,    15, UPASM    */
/*  874,   255,   255,     1,     0,    16, PERRATE  */
/*  875,   255,   255,     1,     2,     0, WDPTHIL  */
/*  876,   255,   255,     1,     2,     1, WTMPIL   */
/*  877,   255,   255,     1,     2,     2, WFRACT   */
/*  878,   255,   255,     1,     2,     3, SEDTK    */
/*  879,   255,   255,     1,     2,     4, SEDTMP   */
/*  880,   255,   255,     1,     2,     5, ICTKIL   */
/*  881,   255,   255,     1,     2,     6, ICETIL   */
/*  882,   255,   255,     1,     2,     7, ICECIL   */
/*  883,   255,   255,     1,     2,     8, LANDIL   */
/*  884,   255,   255,     1,     2,     9, SFSAL    */
/*  885,   255,   255,     1,     2,    10, SFTMP    */
/*  886,   255,   255,     1,     2,    11, ACWSR    */
/*  887,   255,   255,     1,     2,    12, SALTIL   */
/*  888,   255,   255,     1,     2,    13, CSAFC    */
/*  889,   255,   255,     2,     0,    35, TCLASS   */
/*  890,   255,   255,     2,     0,    36, TFRCT    */
/*  891,   255,   255,     2,     0,    37, TPERCT   */
/*  892,   255,   255,     2,     0,    38, SOILVIC  */
/*  893,   255,   255,     2,     0,    39, EVAPTRAT */
/*  894,   255,   255,     2,     1,   192, CANL     */
/*  895,   255,   255,     2,     3,    18, SOILTMP  */
/*  896,   255,   255,     2,     3,    19, SOILMOI  */
/*  897,   255,   255,     2,     3,    20, CISOILM  */
/*  898,   255,   255,     2,     3,    21, SOILICE  */
/*  899,   255,   255,     2,     3,    22, CISICE   */
/*  900,   255,   255,     2,     3,    23, LWSNWP   */
/*  901,   255,   255,     2,     3,    23, FRSTINX  */
/*  902,   255,   255,     2,     3,    23, SNWDEB   */
/*  903,   255,   255,     2,     3,    23, SHFLX    */
/*  904,   255,   255,     2,     3,    23, SOILDEP  */
/*  905,   255,   255,     2,     4,     0, FIREOLK  */
/*  906,   255,   255,     2,     4,     1, FIREODT  */
/*  907,   255,   255,     2,     4,     3, FBAREA   */
/*  908,   255,   255,     2,     4,     4, FOSINDX  */
/*  909,   255,   255,     2,     4,     5, FWINX    */
/*  910,   255,   255,     2,     4,     6, FFMCODE  */
/*  911,   255,   255,     2,     4,     7, DUFMCODE */
/*  912,   255,   255,     2,     4,     8, DRTCODE  */
/*  913,   255,   255,     2,     4,     9, INFSINX  */
/*  914,   255,   255,     2,     4,    10, FBUPINX  */
/*  915,   255,   255,     2,     4,    11, FDSRTE   */
/*  916,   255,   255,     2,     5,     1, GLACTMP  */
/*  917,   255,   255,     3,     0,     0, SRAD     */
/*  918,   255,   255,     3,     0,     1, SALBEDO  */
/*  919,   255,   255,     3,     0,     2, SBTMP    */
/*  920,   255,   255,     3,     0,     3, SPWAT    */
/*  921,   255,   255,     3,     0,     4, SLFTI    */
/*  922,   255,   255,     3,     0,     5, SCTPRES  */
/*  923,   255,   255,     3,     0,     6, SSTMP    */
/*  924,   255,   255,     3,     0,     7, CLOUDM   */
/*  925,   255,   255,     3,     0,     8, PIXST    */
/*  926,   255,   255,     3,     0,     9, FIREDI   */
/*  927,   255,   255,     3,     1,   194, SWQI     */
/*  928,   255,   255,     3,     2,     0, CSKPROB  */
/*  929,   255,   255,     3,   192,    53, SBTAGR8  */
/*  930,   255,   255,     3,   192,    54, SBTAGR9  */
/*  931,   255,   255,     3,   192,    55, SBTAGR10 */
/*  932,   255,   255,     3,   192,    56, SBTAGR11 */
/*  933,   255,   255,     3,   192,    57, SBTAGR12 */
/*  934,   255,   255,     3,   192,    58, SBTAGR13 */
/*  935,   255,   255,     3,   192,    59, SBTAGR14 */
/*  936,   255,   255,     3,   192,    60, SBTAGR15 */
/*  937,   255,   255,     3,   192,    61, SBTAGR16 */
/*  938,   255,   255,    10,     0,    14, WWSDIR   */
/*  939,   255,   255,    10,     0,    15, MWSPER   */
/*  940,   255,   255,    10,     0,    16, CDWW     */
/*  941,   255,   255,    10,     0,    17, FRICV    */
/*  942,   255,   255,    10,     0,    18, WSTR     */
/*  943,   255,   255,    10,     0,    19, NWSTR    */
/*  944,   255,   255,    10,     0,    20, MSSW     */
/*  945,   255,   255,    10,     0,    21, USSD     */
/*  946,   255,   255,    10,     0,    22, VSSD     */
/*  947,   255,   255,    10,     0,    23, PMAXWH   */
/*  948,   255,   255,    10,     0,    24, MAXWH    */
/*  949,   255,   255,    10,     0,    25, IMWF     */
/*  950,   255,   255,    10,     0,    26, IMFWW    */
/*  951,   255,   255,    10,     0,    27, IMFTSW   */
/*  952,   255,   255,    10,     0,    28, MZWPER   */
/*  953,   255,   255,    10,     0,    29, MZPWW    */
/*  954,   255,   255,    10,     0,    30, MZPTSW   */
/*  955,   255,   255,    10,     0,    31, WDIRW    */
/*  956,   255,   255,    10,     0,    32, DIRWWW   */
/*  957,   255,   255,    10,     0,    33, DIRWTS   */
/*  958,   255,   255,    10,     0,    34, PWPER    */
/*  959,   255,   255,    10,     0,    35, PPERWW   */
/*  960,   255,   255,    10,     0,    36, PPERTS   */
/*  961,   255,   255,    10,     0,    37, ALTWH    */
/*  962,   255,   255,    10,     0,    38, ALCWH    */
/*  963,   255,   255,    10,     0,    39, ALRRC    */
/*  964,   255,   255,    10,     0,    40, MNWSOW   */
/*  965,   255,   255,    10,     0,    41, MWDIRW   */
/*  966,   255,   255,    10,     0,    42, WESP     */
/*  967,   255,   255,    10,     0,    43, KSSEW    */
/*  968,   255,   255,    10,     0,    44, BENINX   */
/*  969,   255,   255,    10,     0,    45, SPFTR    */
/*  970,   255,   255,    10,     0,    46, PWAVEDIR */
/*  971,   255,   255,    10,     0,    47, SWHFSWEL */
/*  972,   255,   255,    10,     0,    48, SWHSSWEL */
/*  973,   255,   255,    10,     0,    49, SWHTSWEL */
/*  974,   255,   255,    10,     0,    50, MWPFSWEL */
/*  975,   255,   255,    10,     0,    51, MWPSSWEL */
/*  976,   255,   255,    10,     0,    52, MWPTSWEL */
/*  977,   255,   255,    10,     0,    53, MWDFSWEL */
/*  978,   255,   255,    10,     0,    54, MWDSSWEL */
/*  979,   255,   255,    10,     0,    55, MWDTSWEL */
/*  980,   255,   255,    10,     0,    56, WDWFSWEL */
/*  981,   255,   255,    10,     0,    57, WDWSSWEL */
/*  982,   255,   255,    10,     0,    58, WDWTSWEL */
/*  983,   255,   255,    10,     0,    59, WFWFSWEL */
/*  984,   255,   255,    10,     0,    60, WFWSSWEL */
/*  985,   255,   255,    10,     0,    61, WFWTSWEL */
/*  986,   255,   255,    10,     0,    62, WAVEFREW */
/*  987,   255,   255,    10,     0,    63, FREWWW   */
/*  988,   255,   255,    10,     0,    64, FREWTSW  */
/*  989,   255,   255,    10,     1,     4, RIPCOP   */
/*  990,   255,   255,    10,     2,     9, ICEPRS   */
/*  991,   255,   255,    10,     2,    10, ZVCICEP  */
/*  992,   255,   255,    10,     2,    11, MVCICEP  */
/*  993,   255,   255,    10,     2,    12, CICES    */
/*  994,   255,   255,    10,     3,     2, CH       */
/*  995,   255,   255,    10,     3,     3, PRACTSAL */
/*  996,   255,   255,    10,     3,   204, FRZSPR   */
/*  997,   255,   255,    10,     4,    13, ACWSRD   */
/*  998,   255,   255,    10,     3,   205, TWLWAV   */
/*  999,   255,   255,    10,     3,   206, RUNUP    */
/* 1000,   255,   255,    10,     3,   207, SETUP    */
/* 1001,   255,   255,    10,     3,   208, SWASH    */
/* 1002,   255,   255,    10,     3,   209, TWLDT    */
/* 1003,   255,   255,    10,     3,   210, TWLDC    */
/* 1004,   255,   255,    10,     3,   250, ETCWL    */
/* 1005,   255,   255,    10,     3,   251, TIDE     */
/* 1006,   255,   255,    10,     3,   252, EROSNP   */
/* 1007,   255,   255,    10,     3,   253, OWASHP   */
/* 1008,   255,   255,    10,     4,    14, WDEPTH   */
/* 1009,   255,   255,    10,     4,    15, WTMPSS   */
/* 1010,   255,   255,    10,     4,    16, WATERDEN */
/* 1011,   255,   255,    10,     4,    17, WATDENA  */
/* 1012,   255,   255,    10,     4,    18, WATPTEMP */
/* 1013,   255,   255,    10,     4,    19, WATPDEN  */
/* 1014,   255,   255,    10,     4,    20, WATPDENA */
/* 1015,   255,   255,    10,     4,    21, PRTSAL   */
/* 1016,   240,   129,     0,    16,     3, RETOP    */
/* 1017,   234,     2,     1,     0,     5, BGRUN    */
/* 1018,   235,     2,     1,     0,     6, SSRUN    */
/* 1019,   160,   130,     2,     3,     5, SOILL    */

    }
    printf("ok!\n");
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}


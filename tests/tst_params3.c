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
        if ((ret = g2c_param_g1tog2(152, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 213)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(153, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 22)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(155, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(156, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(157, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(158, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(159, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(160, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(161, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 29)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(162, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 221)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(163, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 214)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(164, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 215)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(165, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 222)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(166, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(167, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(168, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(169, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(170, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(171, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(172, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(173, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 210)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(174, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 218)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(175, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(176, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(177, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(178, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 23)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(179, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 228)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(180, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 17)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(181, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(182, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(183, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 216)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(184, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 19)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(187, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 217)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(188, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 206)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(189, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 218)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(190, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(191, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(192, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 191 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(194, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 1 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(196, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(197, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(198, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 212)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(199, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(200, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 229)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(202, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 223)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(203, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(204, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(205, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(206, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 224)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(207, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(208, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(210, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 230)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(211, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(212, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(213, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(214, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(216, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(218, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 211)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(219, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(220, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(221, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(222, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(223, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(224, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(225, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(226, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(227, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 219)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(228, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(229, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(230, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 195)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(231, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(232, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 220)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(233, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 221)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(234, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 0 || g2num != 192)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(235, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 1 || g2cat != 0 || g2num != 193)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(237, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 222)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(238, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(239, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 208)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(240, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(241, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 223)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(242, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 224)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(243, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 225)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(244, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 226)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(245, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 227)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(246, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(247, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(248, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 204)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(249, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 205)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(250, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 4 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(251, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 5 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(252, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 196)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(253, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(254, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 194)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(62, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(63, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(220, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 3 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(231, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 200)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(232, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(240, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 16 || g2num != 197)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(191, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 6 || g2num != 201)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(233, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 202)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(234, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 14 || g2num != 203)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(242, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 242)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(243, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 243)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(244, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 244)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(245, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 245)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(246, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 246)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(247, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 247)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(248, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 248)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(249, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 249)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(1, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(52, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(63, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(61, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(41, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(100, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(101, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(103, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(104, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(105, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(107, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 10)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(108, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 11)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(109, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(110, 3, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 0 || g2num != 13)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(192, 133, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 191 || g2num != 1)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(193, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 225)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(194, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 227)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(195, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 241)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(196, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 0 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(195, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 4)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(196, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 5)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(197, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 4 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(64, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 12)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(241, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 6)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(242, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 7)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(243, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 8)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(244, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 3 || g2cat != 192 || g2num != 9)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(235, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 16 || g2num != 198)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(236, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 7 || g2num != 199)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(237, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 220)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(238, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 221)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(253, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 222)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(254, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 223)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(241, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 2 || g2num != 224)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(250, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 2 || g2cat != 4 || g2num != 2)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(175, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 234)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(176, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 233)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(236, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 19 || g2num != 217)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(230, 129, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 1 || g2num != 242)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(206, 130, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 15 || g2num != 3)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(255, 255, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 255)
            return G2C_ERROR;
        if ((ret = g2c_param_g1tog2(193, 131, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 0 || g2num != 21)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g1tog2(137, 131, &g2disc, &g2cat, &g2num))) */
        /*     return ret; */
        /* if (g2disc != 0 || g2cat != 17 || g2num != 0) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g1tog2(194, 131, &g2disc, &g2cat, &g2num))) */
        /*     return ret; */
        /* if (g2disc != 0 || g2cat != 1 || g2num != 39) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_g1tog2(144, 128, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 10 || g2cat != 3 || g2num != 203)
            return G2C_ERROR;
        /* if ((ret = g2c_param_g1tog2(255, 255, &g2disc, &g2cat, &g2num))) */
        /*     return ret; */
        /* if (g2disc != 0 || g2cat != 20 || g2num != 101) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g1tog2(214, 131, &g2disc, &g2cat, &g2num))) */
        /*     return ret; */
        /* if (g2disc != 0 || g2cat != 1 || g2num != 37) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g1tog2(255, 255, &g2disc, &g2cat, &g2num))) */
        /*     return ret; */
        /* if (g2disc != 10 || g2cat != 2 || g2num != 8) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g1tog2(235, 2, &g2disc, &g2cat, &g2num))) */
        /*     return ret; */
        /* if (g2disc != 1 || g2cat != 0 || g2num != 6) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_g1tog2(160, 130, &g2disc, &g2cat, &g2num))) */
        /*     return ret; */
        /* if (g2disc != 2 || g2cat != 3 || g2num != 5) */
        /*     return G2C_ERROR; */

    }
    printf("ok!\n");
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}


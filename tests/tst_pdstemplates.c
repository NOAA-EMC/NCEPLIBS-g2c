/* This is a test for the NCEPLIBS-g2c project. This test is for
 * pdstemplates.c.
 *
 * Ed Hartnett 10/25/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

/* Prototypes. */
g2int getpdsindex(g2int number);

int
main()
{

    printf("Testing pdstemplates, expect and ignore error messages.\n");
    printf("Testing simple getpdstemplate() calls...");
    {
        gtemplate *tmpl;

        /* Check for one that's there. */
        tmpl = getpdstemplate(1);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 1 || tmpl->maplen != 18 || tmpl->needext)
            return G2C_ERROR;
        free(tmpl);

        /* Check for one that's not there. */
        tmpl = getpdstemplate(-1);
        if (tmpl)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing simple g2c_get_pds_template() calls...");
    {
        int maplen, needext;
        int map[G2C_MAX_GRID_TEMPLATE_MAPLEN];
        int expected_map[15] = {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4};
        int m, ret;

        /* This won't work. */
        if (g2c_get_pds_template(424242, &maplen, map, &needext) != G2C_ENOTEMPLATE)
            return G2C_ERROR;

        /* This will work. */
        if ((ret = g2c_get_pds_template(0, &maplen, map, &needext)))
            return ret;
        if (maplen != 15 || needext)
            return G2C_ERROR;
        for (m = 0; m < 15; m++)
            if (map[m] != expected_map[m])
                return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing extpdstemplate() calls...");
    {
#define MAX_LIST 40
        gtemplate *tmpl;
        g2int list[MAX_LIST];
        int i;

        for (i = 0; i < MAX_LIST; i++)
            list[i] = 2;

        /* Check for one that's there but does not need an extension. */
        tmpl = extpdstemplate(1, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 1 || tmpl->maplen != 18 || tmpl->needext)
            return G2C_ERROR;
        free(tmpl);

        /* Check for one that's not there. */
        tmpl = extpdstemplate(-1, list);
        if (tmpl)
            return G2C_ERROR;

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(3, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 3 || tmpl->maplen != 31 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(4, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 4 || tmpl->maplen != 30 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(8, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 8 || tmpl->maplen != 29 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(9, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 9 || tmpl->maplen != 36 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(10, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 10 || tmpl->maplen != 30 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(11, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 11 || tmpl->maplen != 32 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(12, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 12 || tmpl->maplen != 31 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(13, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 13 || tmpl->maplen != 45 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(14, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 14 || tmpl->maplen != 44 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(30, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 30 || tmpl->maplen != 5 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(31, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 31 || tmpl->maplen != 5 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(42, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 42 || tmpl->maplen != 30 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(43, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 43 || tmpl->maplen != 33 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(32, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 32 || tmpl->maplen != 10 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(46, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 46 || tmpl->maplen != 35 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(47, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 47 || tmpl->maplen != 38 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(51, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 51 || tmpl->maplen != 16 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(91, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 91 || tmpl->maplen != 36 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(33, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 33 || tmpl->maplen != 18 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(34, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 34 || tmpl->maplen != 32 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(53, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 53 || tmpl->maplen != 19 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(54, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 54 || tmpl->maplen != 22 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(57, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 57 || tmpl->maplen != 7 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(61, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 61 || tmpl->maplen != 38 || !tmpl->needext)
            return G2C_ERROR;
        if (!tmpl->ext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's there but does need an extension. */
        tmpl = extpdstemplate(35, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 35 || tmpl->maplen != 6 || !tmpl->needext)
            return G2C_ERROR;
        /* This should have allocated an extension, but it does
         * not. See
         * https://github.com/NOAA-EMC/NCEPLIBS-g2c/issues/240. */
        /* if (!tmpl->ext) */
        /*     return G2C_ERROR; */
        /* free(tmpl->ext); */
        free(tmpl);
    }
    printf("ok!\n");
    printf("Testing all getpdstemplate() calls with extensions...\n");
    {
#define NUM_TEST 47
        int number[NUM_TEST] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 20, 30, 31, 40, 41, 42, 43, 254, 1000, 1001, 1002, 1100, 1101, 32, 44, 45, 46, 47, 48, 50, 52, 51, 91, 33, 34, 53, 54, 57, 60, 61, 35};
        int expected_maplen[NUM_TEST] = {15, 18, 17, 31, 30, 22, 16, 15, 29, 36, 30, 32, 31, 45, 44, 18, 19, 5, 5, 16, 19, 30, 33, 3, 9, 16, 15, 15, 22, 10, 21, 24, 35, 38, 26, 21, 15, 16, 36, 18, 32, 19, 22, 7, 24, 38, 6};
        int expected_needext[NUM_TEST] = {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1};
        int expected_map[NUM_TEST][48] = {
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}, /* 0 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}, /* 1 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1}, /* 2 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, -4, 4, 4, 1, -1, 4, -1, 4}, /* 3 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, 4, 4, 1, -1, 4, -1, 4}, /* 4 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, -1, -4, -1, -4}, /* 5 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1}, /* 6 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}, /* 7 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 8 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, -1, -4, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 9 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 10 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 11 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 12 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, -4, 4, 4, 1, -1, 4, -1, 4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 13 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, 4, 4, 1, -1, 4, -1, 4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 14 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}, /* 15 */
            {1, 1, 1, 1, 1, -4, 4, 2, 4, 2, 1, 1, 1, 1, 1, 2, 1, 3, 2}, /* 20 */
            {1, 1, 1, 1, 1}, /* 30 */
            {1, 1, 1, 1, 1}, /* 31 */
            {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}, /* 40 */
            {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}, /* 41 */
            {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 42 */
            {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 43 */
            {1, 1, 4}, /* 254 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4}, /* 1000 */
            {1, 1, 1, 1, 1, 2, 1, 1, 4, 4, 1, 1, 1, 4, 1, 4}, /* 1001 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, 1, 1, 4, 4, 2}, /* 1002 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}, /* 1100 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 4, 1, 1, 1, 4, 1, 4}, /* 1101 */
            {1, 1, 1, 1, 1, 2, 1, 1, -2, 1}, /* 32 */            
            {1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -2, 1, -1, -4, 1, -1, -4}, /* 44 */
            {1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}, /* 45 */
            {1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 46 */
            {1, 1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 47 */
            {1, 1, 2, 1, -1, -4, -1, -4, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}, /* 48 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 4, 4, 4, 4}, /* 50 */
            {1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4}, /* 52 */

            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1}, /* 51 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, -1, -4, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 91 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, 2, 2, 2, -1, -4, 1, 1, 1}, /* 33 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, 2, 2, 2, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 34 */
            {1, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}, /* 53 */
            {1, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}, /* 54 */
            {1, 1, 2, 2, 2, 2, 1}, /* 57 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1}, /* 60 */
            {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}, /* 61 */
            {1, 1, 1, 1, 1, 1}, /* 35 */
        };
        int t;
        int ext_t = 0;

        for (t = 0; t < NUM_TEST; t++)
        {
            printf("\tchecking getpdstemplate() with template %d...", number[t]);
            {
                gtemplate *tmpl;
                int m;
                
                /* if (number[t] == 54) */
                /*     printf("here\n"); */
                tmpl = getpdstemplate(number[t]);
                if (!tmpl)
                    return G2C_ERROR;
                if (tmpl->num != number[t] || tmpl->maplen != expected_maplen[t] ||
                    tmpl->needext != expected_needext[t])
                    return G2C_ERROR;
                for (m = 0; m < tmpl->maplen; m++)
                    if (tmpl->map[m] != expected_map[t][m])
                        return G2C_ERROR;
                
                free(tmpl);
            }
            printf("ok!\n");
            printf("\tchecking g2c_get_pds_template() with template %d...", number[t]);
            {
                if (number[t] == 35)
                    printf("here\n");
                int maplen, needext;
                int map[G2C_MAX_GRID_TEMPLATE_MAPLEN];
                int m, ret;
                
                /* This will work. */
                if ((ret = g2c_get_pds_template(number[t], &maplen, map, &needext)))
                    return ret;
                if (maplen != expected_maplen[t] || needext != expected_needext[t])
                    return G2C_ERROR;
                for (m = 0; m < maplen; m++)
                    if (map[m] != expected_map[t][m])
                        return G2C_ERROR;

                /* There's a bug with 35 see https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp4-35.shtml. */
                if (number[t] != 35)
                {
#define NUM_EXT_TEST 24
                    int template[G2C_MAX_GRID_TEMPLATE_MAPLEN];
                    int expected_extlen[NUM_EXT_TEST] = {2, 2, 6, 6, 6, 6, 6, 8, 8, 10, 10, 6, 6, 20, 6, 6, 22, 8, 2, 8, 2, 2, 30, 6};
                    int expected_ext[NUM_EXT_TEST][48] = {
                        {1, 1}, /* 3 */
                        {1, 1}, /* 4 */
                        {1, 1, 1, 4, 1, 4}, /* 8 */
                        {1, 1, 1, 4, 1, 4}, /* 9 */
                        {1, 1, 1, 4, 1, 4}, /* 10 */
                        {1, 1, 1, 4, 1, 4}, /* 11 */
                        {1, 1, 1, 4, 1, 4}, /* 12 */
                        {1, 1, 1, 4, 1, 4, 1, 1}, /* 13 */
                        {1, 1, 1, 4, 1, 4, 1, 1}, /* 14 */
                        {2, 2, 1, 1, 4, 2, 2, 1, 1, 4}, /* 30 */
                        {2, 2, 2, 1, 4, 2, 2, 2, 1, 4}, /* 31 */
                        {1, 1, 1, 4, 1, 4}, /* 42 */
                        {1, 1, 1, 4, 1, 4}, /* 43 */
                        {2, 2, 2, -1, -4, 2, 2, 2, -1, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* 32 */
                        {1, 1, 1, 4, 1, 4}, /* 46 */
                        {1, 1, 1, 4, 1, 4}, /* 47 */
                        {1, 1, -1, -4, -1, -4, 1, 1, -1, -4, -1, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* 51 */
                        {1, 1, 1, 4, 1, 4, 1, 1}, /* 91 */
                        {1, 1}, /* 33 */
                        {1, 1, 1, 4, 1, 4, 1, 1}, /* 34 */
                        {1, 1}, /* 53 */
                        {1, 1}, /* 54 */
                        {1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}, /* 57 */
                        {1, 1, 1, 4, 1, 4}, /* 61 */
                    };
                    
                    if (needext)
                    {
                        int ext[G2C_MAX_GRID_TEMPLATE_MAPLEN];
                        int extlen;
                        int e;
                        int ret;

                        switch (number[t])
                        {
                        case 3:
                            template[26] = 2;
                            break;
                        case 4:
                            template[25] = 2;
                            break;
                        case 8:
                            template[21] = 2;
                            break;
                        case 9:
                            template[28] = 2;
                            break;
                        case 10:
                            template[22] = 2;
                            break;
                        case 11:
                            template[24] = 2;
                            break;
                        case 12:
                            template[23] = 2;
                            break;
                        case 13:
                            template[26] = 2;
                            template[37] = 2;
                            break;
                        case 14:
                            template[25] = 2;
                            template[36] = 2;
                            break;
                        case 30:
                            template[4] = 2;
                            break;
                        case 31:
                            template[4] = 2;
                            break;
                        case 42:
                            template[22] = 2;
                            break;
                        case 43:
                            template[25] = 2;
                            break;
                        case 32:
                            template[9] = 2;
                            break;
                        case 46:
                            template[27] = 2;
                            break;
                        case 47:
                            template[30] = 2;
                            break;
                        case 51:
                            template[15] = 2;
                            break;
                        case 33:
                            template[9] = 2;
                            break;
                        case 34:
                            template[9] = 2;
                            template[24] = 2;
                            break;
                        case 53:
                            template[3] = 2;
                            break;
                        case 54:
                            template[3] = 2;
                            break;
                        case 91:
                            template[15] = 2;
                            template[28] = 2;
                            template[29] = 2;
                            break;
                        case 57:
                            template[6] = 2;
                            break;
                        case 61:
                            template[30] = 2;
                            break;
                        default:
                            return G2C_ERROR;
                        }

                        /* Get extension. */
                        if ((ret = g2c_get_pds_template_extension(number[t], template, &extlen, ext)))
                            return ret;
                        /* printf("extlen %d {", extlen); */
                        /* for (e = 0; e < extlen; e++) */
                        /*     printf("%d%s", ext[e], e < extlen - 1 ? ", " : ""); */
                        /* printf("}\n"); */

                        /* Check results. */
                        if (extlen != expected_extlen[ext_t])
                        {
                            printf("expected_extlen[%d] %d\n", ext_t, expected_extlen[ext_t]);
                            return G2C_ERROR;
                        }
                        for (e = 0; e < extlen; e++)
                        {
                            if (ext[e] != expected_ext[ext_t][e])
                            {
                                printf("expected_ext[%d][%d] %d\n", ext_t, e, expected_ext[ext_t][e]);
                                return G2C_ERROR;
                            }
                        }

                        /* Move to next set of expected results. */
                        ext_t++;
                        
                    }
                }
            }
            printf("ok!\n");
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

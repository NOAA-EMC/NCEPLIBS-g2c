/* This is a test for the NCEPLIBS-g2c project. This test is for
 * gridtemplates.c.
 *
 * Ed Hartnett 10/16/22
 */

#include "grib2_int.h"

/* Number of grid templates to test. */
#define NUM_TESTS 38

/* Number of grid templates with extensions. */
#define NUM_EXT_TESTS 5

int
main()
{
    printf("Testing g2c_get_grid_template()\n");
    printf("Testing simple g2c_get_grid_template() calls...\n");
    {
        int template_number[NUM_TESTS] = {
            0, 1, 2, 3, 4, 5, 12, 101, 140, 10, 20, 30, 31, 40, 41, 42, 43, 50, 51, 52, 53, 90, 100, 110, 120,
            204, 32768, 32769, 1000, 1100, 1200, 13, 23, 33, 61, 62, 63, 150};
        int expected_maplen[NUM_TESTS] = {
            19, 22, 22, 25, 13, 16, 22, 4, 17, 19, 18, 22, 22, 19, 22, 22, 25, 5, 8, 8, 11, 21, 11, 16, 7, 19,
            19, 21, 20, 28, 16, 23, 22, 26, 23, 23, 26, 13};
        int expected_needsext[NUM_TESTS] = {
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0,
            0, 0, 0, 0, 0};
        int expected_extlen[NUM_TESTS] = {
            0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 2, 0, 2, 0, 0,
            0, 0, 0, 0, 0};
        int expected_map[NUM_TESTS][28] = {
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 0, 0, 0},                      /* 0 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, 4, 0, 0, 0},            /* 1 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, -4, 0, 0, 0},           /* 2 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, 4, -4, 4, -4, 0, 0, 0}, /* 3 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, 1, 1},                                                   /* 4 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, 1, 1, -4, 4, 4},                                         /* 5 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, 4, 4, 1, 4, 4, -4, -4, -4, -4, 0, 0, 0},         /* 12 */
            {1, 4, 1, -4},                                                                             /* 101 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 4, 4, 1, 4, 4, 1, 0, 0, 0},                             /* 140 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, -4, 4, 1, 4, 4, 4, 0, 0, 0},                     /* 10 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 1, 0, 0, 0},                         /* 20 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 1, -4, -4, -4, 4, 0, 0, 0, 0, 0, 0}, /* 30 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 1, -4, -4, -4, 4, 0, 0, 0, 0, 0, 0}, /* 31 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},    /* 40 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, 4, 0, 0, 0, 0, 0, 0},   /* 41 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, -4, 0, 0, 0, 0, 0, 0},  /* 42 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, 4, -4, 4, -4, 0, 0, 0}, /* 43 */
            {4, 4, 4, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},      /* 50 */
            {4, 4, 4, 1, 1, -4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     /* 51 */
            {4, 4, 4, 1, 1, -4, 4, -4},                                                                /* 52 */
            {4, 4, 4, 1, 1, -4, 4, 4, -4, 4, -4},                                                      /* 53 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, 4, 4, 4, 4, 1, 4, 4, 4, 4},                          /* 90 */
            {1, 1, 2, 1, -4, 4, 4, 1, 1, 1, 4},                                                        /* 100 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, 4, 4, 1, 1},                                         /* 110 */
            {4, 4, -4, 4, 4, 4, 1},                                                                    /* 120 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1},                               /* 204 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1},                               /* 32768 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 4, 4},                         /* 32769 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, -4, 4, 1, 4, 4, 1, 2, 1, 1, 2},                             /* 1000 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, -4, 4, 1, -4, 4, 1, 4, 1, -4, 1, 1, -4, 2, 1, 1, 1, 1, 1},  /* 1100 */
            {4, 1, -4, 1, 1, -4, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2},                                        /* 1200 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, -4, 4, 1, 4, 4, 4, 4, 4, 4, 4},                  /* 13 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 1, 4, 4, 4, 4},                      /* 23 */
            {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, 1, -4, -4, -4, 4, 4, 4, 4, 4},       /* 33 */
            {1, 4, 4, 1, 8, 8, 8, 8, 8, 8, 1, 1, 4, 1, 4, 1, 4, -4, 4, -4, -4, 4, 4},                  /* 61 */
            {1, 4, 4, 1, 8, 8, 8, 8, 8, 8, 1, 1, 4, 1, 4, 1, 4, -4, 4, 1, -4, 4, 1},                   /* 62 */
            {1, 4, 4, 1, 8, 8, 8, 8, 8, 8, 1, 1, 4, 1, 4, 1, 4, -4, 4, -4, 4, 1, -4, -4, -4, 4},       /* 63 */
            {1, 1, 4, 1, 4, 1, 4, 1, 4, 4, 1, 1, 1},                                                   /* 150 */
        };
        int expected_ext[NUM_EXT_TESTS][8] = {
            {4, 4, -4, -4},
            {4, 4, -4, -4},
            {2, -2, 2, -2},
            {4, 4},
            {4, 4}};
        int maplen, extlen;
        int map[G2C_MAX_GDS_TEMPLATE_MAPLEN];
        int ext[G2C_MAX_GDS_TEMPLATE_MAPLEN];
        int i, t, ext_count = 0;
        int ret;

        /* This won't work. */
        if (g2c_get_grid_template(G2C_MAX_GDS_TEMPLATE + 1, &maplen, map, &extlen) != G2C_ENOTEMPLATE)
            return G2C_ERROR;

        /* Check all templates that don't have extensions. */
        for (t = 0; t < NUM_TESTS; t++)
        {
            int needsext;
            int template[G2C_MAX_GDS_TEMPLATE_MAPLEN];

            printf("\ttesting grid template %d...", template_number[t]);
            if ((ret = g2c_get_grid_template(template_number[t], &maplen, map, &needsext)))
                return ret;
            if (maplen != expected_maplen[t] || needsext != expected_needsext[t])
                return G2C_ERROR;
            for (i = 0; i < maplen; i++)
                if (map[i] != expected_map[t][i])
                    return G2C_ERROR;
            if (template_number[t] == 4)
            {
                template[7] = 2;
                template[8] = 2;
            }
            else if (template_number[t] == 5)
            {
                template[7] = 2;
                template[8] = 2;
            }
            else if (template_number[t] == 120)
            {
                template[1] = 2;
            }
            else if (template_number[t] == 1000)
            {
                template[19] = 2;
            }
            else if (template_number[t] == 1200)
            {
                template[15] = 2;
            }
            if ((ret = g2c_get_grid_template_extension(template_number[t], template, &extlen, ext)))
                return ret;
            if (extlen != expected_extlen[t])
                return G2C_ERROR;
            /* If there's an extension, check that. */
            if (extlen)
            {
                for (i = 0; i < extlen; i++)
                {
                    if (ext[i] != expected_ext[ext_count][i])
                        return G2C_ERROR;
                }
                ext_count++;
            }

            printf("ok!\n");
        }
    }
    printf("ok!\n");
    printf("Testing g2c_get_gdt_len()\n");
    {
        int template_number[NUM_TESTS] = {
            0, 1, 2, 3, 4, 5, 12, 101, 140, 10, 20, 30, 31, 40, 41, 42, 43, 50, 51, 52, 53, 90, 100, 110, 120,
            204, 32768, 32769, 1000, 1100, 1200, 13, 23, 33, 61, 62, 63, 150};
        int expected_maplen[NUM_TESTS] = {
            19, 22, 22, 25, 13, 16, 22, 4, 17, 19, 18, 22, 22, 19, 22, 22, 25, 5, 8, 8, 11, 21, 11, 16, 7, 19,
            19, 21, 20, 28, 16, 23, 22, 26, 23, 23, 26, 13};
        int maplen, t, ret;

        for (t = 0; t < NUM_TESTS; t++)
        {
            if ((ret = g2c_get_gdt_len(template_number[t], &maplen)))
                return ret;
            if (maplen != expected_maplen[t])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

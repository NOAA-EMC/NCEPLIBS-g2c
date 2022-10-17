/* This is a test for the NCEPLIBS-g2c project. This test is for
 * gridtemplates.c.
 *
 * Ed Hartnett 10/16/22
 */

#include "grib2_int.h"

int
main()
{
    printf("Testing g2c_get_grid_template()\n");
    printf("Testing simple g2c_get_grid_template() calls...");
    {
	int maplen, extlen;
	int map[G2C_MAX_GRID_TEMPLATE_MAPLEN];
	int ext[G2C_MAX_GRID_TEMPLATE_MAPLEN];
	int expected_map_0[19] = {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1};
	int expected_map_1[22] = {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, 4};
	int expected_map_2[22] = {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, -4};
	int expected_map_3[25] = {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, -4, 4, 1, -4, 4, 4, 4, 1, -4, 4, 4, -4, 4, -4};
	/* int expected_map_4[13] = {1, 1, 4, 1, 4, 1, 4, 4, 4, 4, 4, 1, 1}; */
	int expected_map_12[22] = {1, 1, 4, 1, 4, 1, 4, 4, 4, -4, 4, 1, -4, 4, 4, 1, 4, 4, -4, -4, -4, -4};
	int expected_map_101[4] = {1, 4, 1, -4};
	int i;
	int ret;

	/* This won't work. */
	if (g2c_get_grid_template(G2C_MAX_GRID_TEMPLATE + 1, &maplen, map, &extlen, ext) != G2C_ENOTEMPLATE)
	    return G2C_ERROR;

	/* Find some templates and check results. */
	/* Get template 0. */
	if ((ret = g2c_get_grid_template(0, &maplen, map, &extlen, ext)))
	    return ret;
	if (maplen != 19 || extlen)
	    return G2C_ERROR;
	for (i = 0; i < maplen; i++)
	    if (map[i] != expected_map_0[i])
		return G2C_ERROR;

	/* Get template 1. */
	if ((ret = g2c_get_grid_template(1, &maplen, map, &extlen, ext)))
	    return ret;
	if (maplen != 22 || extlen)
	    return G2C_ERROR;
	for (i = 0; i < maplen; i++)
	    if (map[i] != expected_map_1[i])
		return G2C_ERROR;
	    
	/* Get template 2. */
	if ((ret = g2c_get_grid_template(2, &maplen, map, &extlen, ext)))
	    return ret;
	if (maplen != 22 || extlen)
	    return G2C_ERROR;
	for (i = 0; i < maplen; i++)
	    if (map[i] != expected_map_2[i])
		return G2C_ERROR;
	    
	/* Get template 3. */
	if ((ret = g2c_get_grid_template(3, &maplen, map, &extlen, ext)))
	    return ret;
	if (maplen != 25 || extlen)
	    return G2C_ERROR;
	for (i = 0; i < maplen; i++)
	    if (map[i] != expected_map_3[i])
		return G2C_ERROR;
	    
	/* Get template 4. This cannot work until this bug is fixed:
	 * https://github.com/NOAA-EMC/NCEPLIBS-g2c/issues/150. */
	/* if ((ret = g2c_get_grid_template(4, &maplen, map, &extlen, ext))) */
	/*     return ret; */
	/* if (maplen != 13 || extlen) */
	/*     return G2C_ERROR; */
	/* for (i = 0; i < maplen; i++) */
	/*     if (map[i] != expected_map_4[i]) */
	/* 	return G2C_ERROR; */
	    
	/* Get template 12. */
	if ((ret = g2c_get_grid_template(12, &maplen, map, &extlen, ext)))
	    return ret;
	if (maplen != 22 || extlen)
	    return G2C_ERROR;
	for (i = 0; i < maplen; i++)
	    if (map[i] != expected_map_12[i])
		return G2C_ERROR;
	    
	/* Get template 101. */
	if ((ret = g2c_get_grid_template(101, &maplen, map, &extlen, ext)))
	    return ret;
	if (maplen != 4 || extlen)
	    return G2C_ERROR;
	for (i = 0; i < maplen; i++)
	    if (map[i] != expected_map_101[i])
		return G2C_ERROR;
	    
        /* /\* Check for one that's there and does need extension. *\/ */
        /* if (!(tmpl = getgridtemplate(4))) */
        /*     return G2C_ERROR; */
        /* if (tmpl->type != 3 || tmpl->num != 4 || tmpl->maplen != 13 || !tmpl->needext) */
        /*     return G2C_ERROR; */
        /* free(tmpl); */

        /* Check for one that's there and does need extension. This
         * code fails CI because of a memory leak in the library, see
         * https://github.com/NOAA-EMC/NCEPLIBS-g2c/issues/150. */
        /* if (!(tmpl = extgridtemplate(4, list))) */
        /*     return G2C_ERROR; */
        /* if (tmpl->type != 3 || tmpl->num != 4 || tmpl->maplen != 13 || !tmpl->needext) */
        /*     return G2C_ERROR; */
        /* free(tmpl->ext); */
        /* free(tmpl); */

        /* if (!(tmpl = extgridtemplate(120, list))) */
        /*     return G2C_ERROR; */
        /* if (tmpl->type != 3 || tmpl->num != 120 || tmpl->maplen != 7 || !tmpl->needext) */
        /*     return G2C_ERROR; */
        /* if (!tmpl->ext) */
        /*     return G2C_ERROR; */
        /* free(tmpl->ext); */
        /* free(tmpl); */

        /* if (!(tmpl = extgridtemplate(1000, list2))) */
        /*     return G2C_ERROR; */
        /* if (tmpl->type != 3 || tmpl->num != 1000 || tmpl->maplen != 20 || !tmpl->needext) */
        /*     return G2C_ERROR; */
        /* if (!tmpl->ext) */
        /*     return G2C_ERROR; */
        /* free(tmpl->ext); */
        /* free(tmpl); */

        /* if (!(tmpl = extgridtemplate(1200, list2))) */
        /*     return G2C_ERROR; */
        /* if (tmpl->type != 3 || tmpl->num != 1200 || tmpl->maplen != 16 || !tmpl->needext) */
        /*     return G2C_ERROR; */
        /* if (!tmpl->ext) */
        /*     return G2C_ERROR; */
        /* free(tmpl->ext); */
        /* free(tmpl); */

        /* /\* Check for one that's not there. *\/ */
        /* if ((tmpl = getgridtemplate(-1))) */
        /*     return G2C_ERROR; */
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

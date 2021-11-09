/* This is a test for the NCEPLIBS-g2c project. This test is for
 * gridtemplates.c.
 *
 * Ed Hartnett 10/24/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define G2C_ERROR 2

/* Prototypes. */
g2int getgridindex(g2int number);


int
main()
{
    
    printf("Testing gridtemplates.\n");
    printf("Testing simple getgridindex() calls...");
    {
        g2int idx;

        /* Check for one that's there. */
        idx = getgridindex(1);
        if (idx != 1)
            return G2C_ERROR;

        /* Check for one that's not there. */
        idx = getgridindex(-1);
        if (idx != -1)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing simple getgridtemplate() calls (expect and ignore error messages)...");
    {
        /* Note that gtemplate is not the same as gribtemplate. */
        gtemplate *tmpl;
        g2int list[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        g2int list2[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
        
        /* Check for one that's there and does not need extension. */
        if (!(tmpl = getgridtemplate(1)))
            return G2C_ERROR;
        if (tmpl->type != 3 || tmpl->num != 1 || tmpl->maplen != 22 || tmpl->needext ||
            tmpl->extlen || tmpl->ext)
            return G2C_ERROR;
        free(tmpl);

        /* Check for one that's there and does need extension. */
        if (!(tmpl = getgridtemplate(4)))
            return G2C_ERROR;
        if (tmpl->type != 3 || tmpl->num != 4 || tmpl->maplen != 13 || !tmpl->needext)
            return G2C_ERROR;
        free(tmpl);

        /* Check for one that's there and does need extension. This
         * code fails CI because of a memory leak in the library, see
         * https://github.com/NOAA-EMC/NCEPLIBS-g2c/issues/150. */
        /* if (!(tmpl = extgridtemplate(4, list))) */
        /*     return G2C_ERROR; */
        /* if (tmpl->type != 3 || tmpl->num != 4 || tmpl->maplen != 13 || !tmpl->needext) */
        /*     return G2C_ERROR; */
        /* free(tmpl->ext); */
        /* free(tmpl); */

        if (!(tmpl = extgridtemplate(120, list)))
            return G2C_ERROR;
        if (tmpl->type != 3 || tmpl->num != 120 || tmpl->maplen != 7 || !tmpl->needext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        if (!(tmpl = extgridtemplate(1000, list2)))
            return G2C_ERROR;
        if (tmpl->type != 3 || tmpl->num != 1000 || tmpl->maplen != 20 || !tmpl->needext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        if (!(tmpl = extgridtemplate(1200, list2)))
            return G2C_ERROR;
        if (tmpl->type != 3 || tmpl->num != 1200 || tmpl->maplen != 16 || !tmpl->needext)
            return G2C_ERROR;
        free(tmpl->ext);
        free(tmpl);

        /* Check for one that's not there. */
        if ((tmpl = getgridtemplate(-1)))
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

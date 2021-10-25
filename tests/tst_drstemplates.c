/* This is a test for the NCEPLIBS-g2c project. This test is for
 * ddrstemplates.c.
 *
 * Ed Hartnett 10/25/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define G2C_ERROR 2

/* Prototypes. */
g2int getdrsindex(g2int number);

int
main()
{
    printf("Testing drstemplates.\n");
    printf("Testing simple getdrsindex() calls...");
    {
        g2int idx;

        /* Check for one that's there. */
        idx = getdrsindex(0);
        if (idx != 0)
            return G2C_ERROR;

        /* Check for one that's not there. */
        idx = getdrsindex(-1);
        if (idx != -1)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing simple getdrstemplate() calls...");
    {
        gtemplate *tmpl;

        /* Check for one that's there. */
        tmpl = getdrstemplate(0);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 0 || tmpl->maplen != 5 || tmpl->needext)
            return G2C_ERROR;
        free(tmpl);

        /* Check for one that's not there. */
        tmpl = getdrstemplate(-1);
        if (tmpl)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing extdrstemplate() calls (expect and ignore error messages)...");
    {
#define MAX_LIST 40
        gtemplate *tmpl;
        g2int list[MAX_LIST];
        int i;

        for (i = 0; i < MAX_LIST; i++)
            list[i] = 2;

        /* Check for one that's there but does not need an extension. */
        tmpl = extdrstemplate(0, list);
        if (!tmpl)
            return G2C_ERROR;
        if (tmpl->num != 0 || tmpl->maplen != 5 || tmpl->needext)
            return G2C_ERROR;
        free(tmpl);

        /* Check for one that's not there. */
        tmpl = extdrstemplate(-1, list);
        if (tmpl)
            return G2C_ERROR;

    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

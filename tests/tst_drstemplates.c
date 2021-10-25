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
    printf("Testing extdrstemplate() calls...");
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

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(3, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 3 || tmpl->maplen != 31 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(4, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 4 || tmpl->maplen != 30 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(8, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 8 || tmpl->maplen != 29 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(9, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 9 || tmpl->maplen != 36 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(10, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 10 || tmpl->maplen != 30 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(11, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 11 || tmpl->maplen != 32 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(12, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 12 || tmpl->maplen != 31 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extdrstemplate(13, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 13 || tmpl->maplen != 45 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}

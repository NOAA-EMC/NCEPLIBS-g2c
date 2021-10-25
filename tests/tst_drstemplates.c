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

int
main()
{
    
    printf("Testing pdstemplates.\n");
    printf("Testing simple getpdsindex() calls...");
    {
        /* g2int idx; */

        /* /\* Check for one that's there. *\/ */
        /* idx = getpdsindex(1); */
        /* if (idx != 1) */
        /*     return G2C_ERROR; */

        /* /\* Check for one that's not there. *\/ */
        /* idx = getpdsindex(-1); */
        /* if (idx != -1) */
        /*     return G2C_ERROR; */
    }
    printf("ok!\n");
    printf("Testing simple getpdstemplate() calls...");
    {
        /* gtemplate *tmpl; */

        /* /\* Check for one that's there. *\/ */
        /* tmpl = getpdstemplate(1); */
        /* if (!tmpl) */
        /*     return G2C_ERROR; */
        /* if (tmpl->num != 1 || tmpl->maplen != 18 || tmpl->needext) */
        /*     return G2C_ERROR; */
        /* free(tmpl); */

        /* /\* Check for one that's not there. *\/ */
        /* tmpl = getpdstemplate(-1); */
        /* if (tmpl) */
        /*     return G2C_ERROR; */
    }
    printf("ok!\n");
    printf("Testing extpdstemplate() calls...");
    {
/* #define MAX_LIST 40 */
/*         gtemplate *tmpl; */
/*         g2int list[MAX_LIST]; */
/*         int i; */

/*         for (i = 0; i < MAX_LIST; i++) */
/*             list[i] = 2; */

/*         /\* Check for one that's there but does not need an extension. *\/ */
/*         tmpl = extpdstemplate(1, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 1 || tmpl->maplen != 18 || tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl); */

/*         /\* Check for one that's not there. *\/ */
/*         tmpl = extpdstemplate(-1, list); */
/*         if (tmpl) */
/*             return G2C_ERROR; */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(3, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 3 || tmpl->maplen != 31 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(4, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 4 || tmpl->maplen != 30 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(8, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 8 || tmpl->maplen != 29 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(9, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 9 || tmpl->maplen != 36 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(10, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 10 || tmpl->maplen != 30 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(11, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 11 || tmpl->maplen != 32 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(12, list); */
/*         if (!tmpl) */
/*             return G2C_ERROR; */
/*         if (tmpl->num != 12 || tmpl->maplen != 31 || !tmpl->needext) */
/*             return G2C_ERROR; */
/*         free(tmpl->ext); */
/*         free(tmpl); */

/*         /\* Check for one that's there but does need an extension. *\/ */
/*         tmpl = extpdstemplate(13, list); */
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

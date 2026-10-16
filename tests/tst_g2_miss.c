/* This is a test for the NCEPLIBS-g2c project. This test covers all
 * branches of g2_miss().
 *
 * Hang Lei 2026-09-04
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototype for function under test. */
void g2_miss(gribfield *gfld, float *rmiss, int *nmiss);

/* Helper: allocate a minimal gribfield with a given idrtnum and idrtmpl. */
static gribfield *
make_gribfield(g2int idrtnum, g2int *idrtmpl, g2int idrtlen)
{
    gribfield *gfld = calloc(1, sizeof(gribfield));
    gfld->idrtnum = idrtnum;
    gfld->idrtlen = idrtlen;
    gfld->idrtmpl = malloc(idrtlen * sizeof(g2int));
    memcpy(gfld->idrtmpl, idrtmpl, idrtlen * sizeof(g2int));
    return gfld;
}

static void
free_gribfield(gribfield *gfld)
{
    if (gfld)
    {
        free(gfld->idrtmpl);
        free(gfld);
    }
}

int
main()
{
    printf("Testing g2_miss().\n");

    /* --- Test 1: idrtnum not 2 or 3 -> nmiss = 0 --- */
    printf("Test 1: idrtnum != 2 or 3 -> nmiss=0...");
    {
        g2int tmpl[10] = {0};
        gribfield *gfld = make_gribfield(0, tmpl, 10);
        float rmiss[2];
        int nmiss = -1;

        g2_miss(gfld, rmiss, &nmiss);
        if (nmiss != 0)
        {
            printf("FAILED: nmiss=%d expected 0\n", nmiss);
            return 1;
        }
        free_gribfield(gfld);
        printf("ok!\n");
    }

    /* --- Test 2: idrtnum=2, idrtmpl[6]=1 (1 missing), itype=0 (IEEE float) --- */
    printf("Test 2: idrtnum=2, 1 missing value, IEEE float...");
    {
        /* idrtmpl[4]=itype=0, idrtmpl[6]=1 (one missing), idrtmpl[7]=IEEE(100.0) */
        g2int tmpl[10] = {0};
        float miss_in = 100.0f;
        tmpl[4] = 0; /* itype = 0 (IEEE) */
        tmpl[6] = 1; /* one missing value */
        /* Store 100.0f as IEEE 32-bit integer in tmpl[7]. */
        g2int ieee_val;
        memcpy(&ieee_val, &miss_in, sizeof(float));
        tmpl[7] = ieee_val;

        gribfield *gfld = make_gribfield(2, tmpl, 10);
        float rmiss[2] = {-9999.0f, -9999.0f};
        int nmiss = -1;

        g2_miss(gfld, rmiss, &nmiss);
        if (nmiss != 1)
        {
            printf("FAILED: nmiss=%d expected 1\n", nmiss);
            return 2;
        }
        if (rmiss[0] != 100.0f)
        {
            printf("FAILED: rmiss[0]=%g expected 100.0\n", rmiss[0]);
            return 3;
        }
        free_gribfield(gfld);
        printf("ok!\n");
    }

    /* --- Test 3: idrtnum=3, idrtmpl[6]=1, itype=1 (integer missing value) --- */
    printf("Test 3: idrtnum=3, 1 missing value, integer type...");
    {
        g2int tmpl[10] = {0};
        tmpl[4] = 1;   /* itype = 1 (integer) */
        tmpl[6] = 1;   /* one missing value */
        tmpl[7] = 255; /* integer missing value */

        gribfield *gfld = make_gribfield(3, tmpl, 10);
        float rmiss[2] = {0.0f, 0.0f};
        int nmiss = -1;

        g2_miss(gfld, rmiss, &nmiss);
        if (nmiss != 1)
        {
            printf("FAILED: nmiss=%d expected 1\n", nmiss);
            return 4;
        }
        if (rmiss[0] != 255.0f)
        {
            printf("FAILED: rmiss[0]=%g expected 255.0\n", rmiss[0]);
            return 5;
        }
        free_gribfield(gfld);
        printf("ok!\n");
    }

    /* --- Test 4: idrtnum=2, idrtmpl[6]=2 (2 missing), itype=0 (IEEE) --- */
    printf("Test 4: idrtnum=2, 2 missing values, IEEE float...");
    {
        g2int tmpl[10] = {0};
        float miss1 = 9999.0f, miss2 = -9999.0f;
        g2int ieee1, ieee2;
        memcpy(&ieee1, &miss1, sizeof(float));
        memcpy(&ieee2, &miss2, sizeof(float));
        tmpl[4] = 0; /* IEEE */
        tmpl[6] = 2; /* two missing values */
        tmpl[7] = ieee1;
        tmpl[8] = ieee2;

        gribfield *gfld = make_gribfield(2, tmpl, 10);
        float rmiss[2] = {0.0f, 0.0f};
        int nmiss = -1;

        g2_miss(gfld, rmiss, &nmiss);
        if (nmiss != 2)
        {
            printf("FAILED: nmiss=%d expected 2\n", nmiss);
            return 6;
        }
        if (rmiss[0] != miss1)
        {
            printf("FAILED: rmiss[0]=%g expected %g\n", rmiss[0], miss1);
            return 7;
        }
        if (rmiss[1] != miss2)
        {
            printf("FAILED: rmiss[1]=%g expected %g\n", rmiss[1], miss2);
            return 8;
        }
        free_gribfield(gfld);
        printf("ok!\n");
    }

    /* --- Test 5: idrtnum=3, idrtmpl[6]=2, itype=1 (2 integer missing values) --- */
    printf("Test 5: idrtnum=3, 2 missing values, integer type...");
    {
        g2int tmpl[10] = {0};
        tmpl[4] = 1;   /* integer */
        tmpl[6] = 2;   /* two missing */
        tmpl[7] = 254; /* first missing */
        tmpl[8] = 255; /* second missing */

        gribfield *gfld = make_gribfield(3, tmpl, 10);
        float rmiss[2] = {0.0f, 0.0f};
        int nmiss = -1;

        g2_miss(gfld, rmiss, &nmiss);
        if (nmiss != 2)
        {
            printf("FAILED: nmiss=%d expected 2\n", nmiss);
            return 9;
        }
        if (rmiss[0] != 254.0f || rmiss[1] != 255.0f)
        {
            printf("FAILED: rmiss={%g,%g} expected {254,255}\n", rmiss[0], rmiss[1]);
            return 10;
        }
        free_gribfield(gfld);
        printf("ok!\n");
    }

    /* --- Test 6: idrtnum=2, idrtmpl[6]=0 (no missing values) -> nmiss=0 --- */
    printf("Test 6: idrtnum=2, idrtmpl[6]=0 -> nmiss=0...");
    {
        g2int tmpl[10] = {0};
        tmpl[4] = 0;
        tmpl[6] = 0; /* no missing */

        gribfield *gfld = make_gribfield(2, tmpl, 10);
        float rmiss[2];
        int nmiss = -1;

        g2_miss(gfld, rmiss, &nmiss);
        if (nmiss != 0)
        {
            printf("FAILED: nmiss=%d expected 0\n", nmiss);
            return 11;
        }
        free_gribfield(gfld);
        printf("ok!\n");
    }

    printf("SUCCESS!\n");
    return 0;
}

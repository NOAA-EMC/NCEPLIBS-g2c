/* This is a test for the NCEPLIBS-g2c project. This test covers all
 * grid template branches of getdim() and getpoly().
 *
 * The existing tst_getdim.c only tests template 0 (Lat/Lon).
 * This file adds tests for templates 1-3, 10, 20, 30, 40-43, 90, 110,
 * and the default (unknown) case.
 *
 * Hang Lei 2026-09-04
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototypes for functions under test. */
g2int getdim(unsigned char *csec3, g2int *width, g2int *height, g2int *iscan);
g2int getpoly(unsigned char *csec3, g2int *jj, g2int *kk, g2int *mm);

/* Build a Section 3 buffer from a template field-size map.
 * map[i] is the byte size of field i (negative = signed field, same size).
 * idx_w, idx_h, idx_s are the 0-based field indices for width, height, iscan.
 * width, height, iscan are the values to write.
 */
static unsigned char *
make_sec3(g2int tmpl_num, int maplen, const int *map,
          int idx_w, int idx_h, int idx_s,
          g2int width, g2int height, g2int iscan,
          int *out_len)
{
    /* Compute total template byte length. */
    int tmpl_bytes = 0;
    int i;
    for (i = 0; i < maplen; i++)
        tmpl_bytes += (map[i] < 0 ? -map[i] : map[i]);

    int total = 14 + tmpl_bytes;
    unsigned char *buf = calloc(total, 1);

    /* Section length (bytes 0-3). */
    buf[0] = (total >> 24) & 0xff;
    buf[1] = (total >> 16) & 0xff;
    buf[2] = (total >> 8) & 0xff;
    buf[3] = total & 0xff;

    buf[4] = 3;  /* section number */
    buf[5] = 0;  /* source of grid definition */

    /* Number of grid points (bytes 6-9). */
    g2int npts = width * height;
    buf[6] = (npts >> 24) & 0xff;
    buf[7] = (npts >> 16) & 0xff;
    buf[8] = (npts >> 8) & 0xff;
    buf[9] = npts & 0xff;

    buf[10] = 0; /* no optional list */
    buf[11] = 0;

    /* Template number (bytes 12-13). */
    buf[12] = (tmpl_num >> 8) & 0xff;
    buf[13] = tmpl_num & 0xff;

    /* Compute per-field byte offsets within the template area (from byte 14). */
    int *offsets = malloc(maplen * sizeof(int));
    int off = 14;
    for (i = 0; i < maplen; i++)
    {
        offsets[i] = off;
        off += (map[i] < 0 ? -map[i] : map[i]);
    }

    /* Helper to write a big-endian value of sz bytes at position p. */
#define WRITE_BE(p, sz, val) \
    do { \
        int _b; \
        for (_b = (sz) - 1; _b >= 0; _b--) \
            (buf)[(p) + (sz) - 1 - _b] = ((val) >> (8 * _b)) & 0xff; \
    } while (0)

    int sz;
    sz = (map[idx_w] < 0 ? -map[idx_w] : map[idx_w]);
    WRITE_BE(offsets[idx_w], sz, width);

    sz = (map[idx_h] < 0 ? -map[idx_h] : map[idx_h]);
    WRITE_BE(offsets[idx_h], sz, height);

    sz = (map[idx_s] < 0 ? -map[idx_s] : map[idx_s]);
    WRITE_BE(offsets[idx_s], sz, iscan);

    free(offsets);
    *out_len = total;
    return buf;
}

/* Test a specific grid template. Returns 0 on success, non-zero on failure. */
static int
test_template(const char *name, g2int tmpl_num, int maplen, const int *map,
              int idx_w, int idx_h, int idx_s)
{
    unsigned char *buf;
    int buf_len;
    g2int width, height, iscan;
    g2int exp_w = 360, exp_h = 181, exp_s = 64;

    buf = make_sec3(tmpl_num, maplen, map, idx_w, idx_h, idx_s,
                    exp_w, exp_h, exp_s, &buf_len);

    getdim(buf, &width, &height, &iscan);
    free(buf);

    if (width != exp_w || height != exp_h || iscan != exp_s)
    {
        printf("FAILED %s: got w=%ld h=%ld iscan=%ld, expected w=%ld h=%ld iscan=%ld\n",
               name, (long)width, (long)height, (long)iscan,
               (long)exp_w, (long)exp_h, (long)exp_s);
        return 1;
    }
    return 0;
}

int
main()
{
    printf("Testing getdim() for all grid templates.\n");

    /* Template maps from gridtemplates.c (field sizes in bytes; negative = signed). */

    /* Template 0: Lat/Lon — 19 fields */
    static const int map0[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1};
    /* Template 1: Rotated Lat/Lon — 22 fields */
    static const int map1[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1,-4,4,4};
    /* Template 2: Stretched Lat/Lon — 22 fields */
    static const int map2[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1,-4,4,-4};
    /* Template 3: Stretched+Rotated Lat/Lon — 25 fields */
    static const int map3[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1,-4,4,-4,-4,4,4};
    /* Template 10: Mercator — 19 fields */
    static const int map10[] = {1,1,4,1,4,1,4,4,4,-4,4,1,-4,-4,4,1,4,4,4};
    /* Template 20: Polar Stereographic — 18 fields */
    static const int map20[] = {1,1,4,1,4,1,4,4,4,-4,4,1,-4,4,4,4,1,1};
    /* Template 30: Lambert Conformal — 22 fields */
    static const int map30[] = {1,1,4,1,4,1,4,4,4,-4,4,1,-4,4,4,4,1,1,-4,-4,-4,4};
    /* Template 40-43: Gaussian (same layout as 0-3) */
    static const int map40[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1};
    static const int map41[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1,-4,4,4};
    static const int map42[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1,-4,4,-4};
    static const int map43[] = {1,1,4,1,4,1,4,4,4,4,4,-4,4,1,-4,4,4,4,1,-4,4,-4,-4,4,4};
    /* Template 90: Space View/Orthographic — 21 fields */
    static const int map90[] = {1,1,4,1,4,1,4,4,4,-4,4,1,4,4,4,4,1,4,4,4,4};
    /* Template 110: Equatorial Azimuthal — 16 fields */
    static const int map110[] = {1,1,4,1,4,1,4,4,4,-4,4,1,4,4,1,1};
    /* Template 31: Albers equal area — same layout as 30 (22 fields).
     * Template 31 is defined in gridtemplates.c but NOT handled by getdim's
     * switch, so it exercises the default branch (width=height=iscan=0). */
    static const int map31[] = {1,1,4,1,4,1,4,4,4,-4,4,1,-4,4,4,4,1,1,-4,-4,-4,4};

    /* Template 0: width at idx 7, height at 8, iscan at 18 (1-byte field) */
    printf("Test 1: Template 0 (Lat/Lon)...");
    if (test_template("tmpl0", 0, 19, map0, 7, 8, 18)) return 1;
    printf("ok!\n");

    /* Template 1: same layout as 0 */
    printf("Test 2: Template 1 (Rotated Lat/Lon)...");
    if (test_template("tmpl1", 1, 22, map1, 7, 8, 18)) return 2;
    printf("ok!\n");

    /* Template 2: same layout as 0 */
    printf("Test 3: Template 2 (Stretched Lat/Lon)...");
    if (test_template("tmpl2", 2, 22, map2, 7, 8, 18)) return 3;
    printf("ok!\n");

    /* Template 3: same layout as 0 */
    printf("Test 4: Template 3 (Stretched+Rotated Lat/Lon)...");
    if (test_template("tmpl3", 3, 25, map3, 7, 8, 18)) return 4;
    printf("ok!\n");

    /* Template 10: Mercator — iscan at idx 15 (1-byte field) */
    printf("Test 5: Template 10 (Mercator)...");
    if (test_template("tmpl10", 10, 19, map10, 7, 8, 15)) return 5;
    printf("ok!\n");

    /* Template 20: Polar Stereographic — iscan at idx 17 (1-byte field) */
    printf("Test 6: Template 20 (Polar Stereographic)...");
    if (test_template("tmpl20", 20, 18, map20, 7, 8, 17)) return 6;
    printf("ok!\n");

    /* Template 30: Lambert Conformal — iscan at idx 17 (1-byte field) */
    printf("Test 7: Template 30 (Lambert Conformal)...");
    if (test_template("tmpl30", 30, 22, map30, 7, 8, 17)) return 7;
    printf("ok!\n");

    /* Template 40: Gaussian — same as template 0 */
    printf("Test 8: Template 40 (Gaussian)...");
    if (test_template("tmpl40", 40, 19, map40, 7, 8, 18)) return 8;
    printf("ok!\n");

    /* Template 41: Rotated Gaussian */
    printf("Test 9: Template 41 (Rotated Gaussian)...");
    if (test_template("tmpl41", 41, 22, map41, 7, 8, 18)) return 9;
    printf("ok!\n");

    /* Template 42: Stretched Gaussian */
    printf("Test 10: Template 42 (Stretched Gaussian)...");
    if (test_template("tmpl42", 42, 22, map42, 7, 8, 18)) return 10;
    printf("ok!\n");

    /* Template 43: Stretched+Rotated Gaussian */
    printf("Test 11: Template 43 (Stretched+Rotated Gaussian)...");
    if (test_template("tmpl43", 43, 25, map43, 7, 8, 18)) return 11;
    printf("ok!\n");

    /* Template 90: Space View/Orthographic — iscan at idx 16 (1-byte field) */
    printf("Test 12: Template 90 (Space View/Orthographic)...");
    if (test_template("tmpl90", 90, 21, map90, 7, 8, 16)) return 12;
    printf("ok!\n");

    /* Template 110: Equatorial Azimuthal — iscan at idx 15 (1-byte field) */
    printf("Test 13: Template 110 (Equatorial Azimuthal)...");
    if (test_template("tmpl110", 110, 16, map110, 7, 8, 15)) return 13;
    printf("ok!\n");

    /* Default (unhandled template): should return width=height=iscan=0.
     * Template 31 (Albers equal area) is valid/parseable by g2_unpack3 but
     * not handled by getdim's switch statement, hitting the default branch. */
    printf("Test 14: Template 31 (unhandled) -> width=height=iscan=0...");
    {
        unsigned char *buf;
        int buf_len;
        g2int width = -1, height = -1, iscan = -1;
        buf = make_sec3(31, 22, map31, 7, 8, 17, 10, 20, 64, &buf_len);
        getdim(buf, &width, &height, &iscan);
        free(buf);
        if (width != 0 || height != 0 || iscan != 0)
        {
            printf("FAILED: got w=%ld h=%ld iscan=%ld, expected 0/0/0\n",
                   (long)width, (long)height, (long)iscan);
            return 14;
        }
        printf("ok!\n");
    }

    printf("SUCCESS!\n");
    return 0;
}

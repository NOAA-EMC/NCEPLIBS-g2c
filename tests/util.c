/* This part of the NCEPLIBS-g2c project.
 *
 * These are utility functions for tests.
 *
 * Ed Hartnett 11/26/22
 */
#include "grib2_int.h"

#define MAX_VALUE_LEN 25
#define NUM_MATCHING 5
#define MAX_LINE_LEN 256

/* Compare two strings, ignoring leading spaces.
 *
 * Ed Hartnett 10/6/22
 */
static int
cmpString(const void *p, const void *q)
{    
    const char *pp = (const char*)p;
    const char *qq = (const char*)q;
    int i, j;
    for (i = 0; isblank(pp[i]); ++i)
        ;
    for (j = 0; isblank(qq[j]); ++j)
        ;
    return strcmp(pp + i, qq + j);
}

/* Return 0 if two lines of the DEGRIB2 output are euqal.
 *
 * For most lines this means they must be exactly equal. Lines that
 * show the min, avg, and max values may be slightly different from
 * the reference file, because the intel compiler produces slight
 * different results.
 *
 * All the sscanf calls cause the code scanner to complain about
 * possible overflow. Hence all the memcpys to convince the scanner
 * that we are not going to overwrite any memory.
 *
 * Ed Hartnett 10/6/22
 */
int
degrib2_lines_not_equal(char *l1, char *l2)
{
    char long_abbrev[MAX_LINE_LEN + 1], long_cmin[MAX_LINE_LEN + 1];
    char long_cavg[MAX_LINE_LEN + 1], long_cmax[MAX_LINE_LEN + 1];
    char abbrev1[G2C_MAX_NOAA_ABBREV_LEN + 1];
    char abbrev2[G2C_MAX_NOAA_ABBREV_LEN + 1];
    char cmin1[MAX_VALUE_LEN + 1], cavg1[MAX_VALUE_LEN + 1], cmax1[MAX_VALUE_LEN + 1];
    char cmin2[MAX_VALUE_LEN + 1], cavg2[MAX_VALUE_LEN + 1], cmax2[MAX_VALUE_LEN + 1];
    char my_line[MAX_LINE_LEN + 1];
    int len;

    /* If the lines are the same, we're done. */
    if (!cmpString(l1, l2))
        return 0;

    /* If the lines are different, is it a line like this:
       ( PARM= WIND ) :  MIN=               0.09999998 AVE=               5.64625024 MAX=              16.43000032
    */

    /* We have to go through some business to convince the code
     * scanner we are not going to overwrite any memory in our sscanf
     * calls. */
    len = strlen(l1) < MAX_LINE_LEN ? strlen(l1) : MAX_LINE_LEN;
    memcpy(my_line, l1, len);
    my_line[len] = 0;
    if (sscanf(my_line, "( PARM= %s ) :  MIN=               %s AVE=               %s MAX=              %s", long_abbrev, long_cmin, long_cavg, long_cmax) == 4)
    {
        memcpy(abbrev1, long_abbrev, G2C_MAX_NOAA_ABBREV_LEN);
        abbrev1[G2C_MAX_NOAA_ABBREV_LEN] = 0;
        memcpy(cmin1, long_cmin, MAX_VALUE_LEN);
        cmin1[MAX_VALUE_LEN] = 0;
        memcpy(cavg1, long_cavg, MAX_VALUE_LEN);
        cavg1[MAX_VALUE_LEN] = 0;
        memcpy(cmax1, long_cmax, MAX_VALUE_LEN);
        cmax1[MAX_VALUE_LEN] = 0;

        /* Wow, that was annoying. And now we have to do it again! */
        len = strlen(l2) < MAX_LINE_LEN ? strlen(l2) : MAX_LINE_LEN;
        memcpy(my_line, l2, len);
        my_line[len] = 0;
        if (sscanf(my_line, "( PARM= %s ) :  MIN=               %s AVE=               %s MAX=              %s", long_abbrev, long_cmin, long_cavg, long_cmax) != 4)
            return G2C_ERROR;
        memcpy(abbrev2, long_abbrev, G2C_MAX_NOAA_ABBREV_LEN);
        abbrev2[G2C_MAX_NOAA_ABBREV_LEN] = 0;
        memcpy(cmin2, long_cmin, MAX_VALUE_LEN);
        cmin2[MAX_VALUE_LEN] = 0;
        memcpy(cavg2, long_cavg, MAX_VALUE_LEN);
        cavg2[MAX_VALUE_LEN] = 0;
        memcpy(cmax2, long_cmax, MAX_VALUE_LEN);
        cmax2[MAX_VALUE_LEN] = 0;

        /* Print results. */
        printf("\nabbrev1 %s min1 %s avg1 %s max1 %s\n", abbrev1, cmin1, cavg1, cmax1);
        printf("abbrev2 %s min2 %s avg2 %s max2 %s\n", abbrev2, cmin2, cavg2, cmax2);

        /* Check that results match. */
        if (strcmp(abbrev1, abbrev2))
            return G2C_ERROR;
        if (strncmp(cmin1, cmin2, NUM_MATCHING))
            return G2C_ERROR;
        if (strncmp(cavg1, cavg2, NUM_MATCHING))
            return G2C_ERROR;
        if (strncmp(cmax1, cmax2, NUM_MATCHING))
            return G2C_ERROR;
    }
    else
    {
        printf("\n%s\n", l1);
        printf("expected:\n%s\n", l2);
        return G2C_ERROR;
    }

    return G2C_NOERROR;
}

/* Return 0 if two degrib2 files are the same.
 *
 * Ed Hartnett 10/6/22
 */
int
compare_degrib2_files2(char *fname1, char *fname2)
{
    FILE *fp1, *fp2;
    char l1[MAX_LINE_LEN + 1], l2[MAX_LINE_LEN + 1];

    /* Open the two files. */
    if (!(fp1 = fopen(fname1, "r")))
        return G2C_ERROR;
    if (!(fp2 = fopen(fname2, "r")))
        return G2C_ERROR;

    /* Check each line in the file. */
    while (fgets(l1, MAX_LINE_LEN, fp1))
    {
        if (!fgets(l2, MAX_LINE_LEN, fp2))
            return G2C_ERROR;
        /* printf("l1: %s\n", l1); */
        /* printf("l2: %s\n", l2); */
        if (degrib2_lines_not_equal(l1, l2))
            return G2C_ERROR;
    }

    /* Close files. */
    fclose(fp1);
    fclose(fp2);

    return G2C_NOERROR;
}


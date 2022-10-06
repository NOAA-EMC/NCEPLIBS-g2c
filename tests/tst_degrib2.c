/* This is a test for the NCEPLIBS-g2c project. 
 *
 * This test is for the g2c_degrib2() function, which prints a summary
 * of the GRIB2 file.
 *
 * Ed Hartnett 9/17/22
 */
#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define FILE_NAME "tst_degrib2.txt"
#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"
#define REF_FILE "ref_gdaswave.degrib2.txt"
#define MAX_LINE_LEN 256
#define MAX_VALUE_LEN 25
#define NUM_MATCHING 7

/* Return 0 if two lines of the DEGRIB2 output are euqal. 
 * 
 * For most lines this means they must be exactly equal. Lines that
 * show the min, avg, and max values may be slightly different from
 * the reference file, because the intel compiler produces slight
 * different results.
 *
 * Ed Hartnett 10/6/22
 */
int
degrib2_lines_not_equal(char *l1, char *l2)
{
    char abbrev1[G2C_MAX_NOAA_ABBREV_LEN + 1];
    char abbrev2[G2C_MAX_NOAA_ABBREV_LEN + 1];
    char cmin1[MAX_VALUE_LEN + 1], cavg1[MAX_VALUE_LEN + 1], cmax1[MAX_VALUE_LEN + 1];
    char cmin2[MAX_VALUE_LEN + 1], cavg2[MAX_VALUE_LEN + 1], cmax2[MAX_VALUE_LEN + 1];
    
    /* If the lines are the same, we're done. */
    if (!strcmp(l1, l2))
        return 0;

    /* If the lines are different, is it a line like this:
       ( PARM= WIND ) :  MIN=               0.09999998 AVE=               5.64625024 MAX=              16.43000032
    */
    if (sscanf(l1, "( PARM= %s ) :  MIN=               %s AVE=               %s MAX=              %s", abbrev1, cmin1, cavg1, cmax1) == 4)
    {
        if (sscanf(l2, "( PARM= %s ) :  MIN=               %s AVE=               %s MAX=              %s", abbrev2, cmin2, cavg2, cmax2) != 4)
            return G2C_ERROR;
        /* printf("abbrev1 %s min1 %s avg1 %s max1 %s\n", abbrev1, cmin1, cavg1, cmax1); */
        /* printf("abbrev2 %s min2 %s avg2 %s max2 %s\n", abbrev2, cmin2, cavg2, cmax2); */
        if (strcmp(abbrev1, abbrev2))
            return G2C_ERROR;
        if (strncmp(cmin1, cmin2, NUM_MATCHING))
            return G2C_ERROR;
        if (strncmp(cavg1, cavg2, NUM_MATCHING))
            return G2C_ERROR;
        if (strncmp(cmax1, cmax2, NUM_MATCHING))
            return G2C_ERROR;
    }

    return G2C_NOERROR;
}

/* Return 0 if two files are the same. 
 *
 * Ed Hartnett 10/6/22
 */
int
compare_files2(char *fname1, char *fname2)
{
   FILE *fp1, *fp2;
   char *l1, *l2;
   size_t len1 = 0, len2 = 0;

   /* Open the two files. */
   if (!(fp1 = fopen(fname1, "r")))
       return G2C_ERROR;
   if (!(fp2 = fopen(fname2, "r")))
       return G2C_ERROR;

   /* Check each line in the file. */
   while ((getline(&l1, &len1, fp1) != -1))
   {
       if (getline(&l2, &len2, fp2) == -1)
           return G2C_ERROR;
       /* printf("l1: %s\n", l1); */
       /* printf("l2: %s\n", l2); */
       if (degrib2_lines_not_equal(l1, l2))
           return G2C_ERROR;
    }

   /* Close files. */
   fclose(fp1);
   fclose(fp2);

   /* Free memory. */
   free(l1);
   free(l2);
   
   return G2C_NOERROR;
}

int
main()
{
    printf("Testing g2c degrib2 function.\n");
#ifdef JPEG
    printf("Testing g2c_degrib2() on file %s...", WAVE_FILE);
    {
	int g2cid;
	int ret;

	if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
	    return ret;
        if ((ret = g2c_write_grib2_index(g2cid, FILE_NAME)))
            return ret;
	if ((ret = g2c_close(g2cid)))
	    return ret;
        
        if ((ret = compare_files2(FILE_NAME, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
#endif
    printf("SUCCESS!\n");
    return 0;
}


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

/* Return 0 if two files are the same. */
int
compare_files(char *fname1, char *fname2)
{
   FILE *fp1, *fp2;
   int ch1, ch2;
   int ret = G2C_NOERROR;
 
   if (!(fp1 = fopen(fname1, "r")))
       return G2C_ERROR;
   if (!(fp2 = fopen(fname2, "r")))
       return G2C_ERROR;
 
   ch1 = getc(fp1);
   ch2 = getc(fp2);
   printf("%d %d %d %d\n", ch1, ch2, (ch1 != EOF), (ch2 != EOF));
   while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
   {
       ch1 = getc(fp1);
       ch2 = getc(fp2);
   }
 
   if (ch1 != ch2)
       ret = G2C_ERROR;

   fclose(fp1);
   fclose(fp2);
   
   return ret;
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
        if ((ret = compare_files(FILE_NAME, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
#endif
    printf("SUCCESS!\n");
    return 0;
}

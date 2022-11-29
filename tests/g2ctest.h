/* This part of the NCEPLIBS-g2c project.
 *
 * This is a header file for tests.
 *
 * Ed Hartnett 11/26/22
 */
#include "grib2_int.h"

#define MAX_FILENAME_LEN 256

/* Utility functions. */
int degrib2_lines_not_equal(char *l1, char *l2);
int compare_degrib2_files2(char *fname1, char *fname2);

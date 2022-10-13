/** 
 * @file
  * @brief Write summary output to an index file, as is done by utility
 * grb2index.
 *
 * @author Ed Hartnett @date 10/12/22
 */
#include "grib2_int.h"
#include <stdarg.h>

/* /\** Global file information. *\/ */
/* extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1]; */

/**
 * Create an index file from a GRIB2 file.
 *
 * @param g2cid File it for an open GRIB2 file, as returned by
 * g2c_open().
 * @param index_file The name that will be given to the index file. An
 * existing file will be overwritten.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/12/22
 */
int
g2c_write_index(int g2cid, char *index_file)
{
    return G2C_NOERROR;
}

/**
 * Read an index file.
 *
 * @param index_file The name that will be given to the index file. An
 * existing file will be overwritten.
 * @param g2cid Pointer that gets the g2cid for this file. Ignored if
 * NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/12/22
 */
int
g2c_read_index(char *index_file, int *g2cid)
{
    return G2C_NOERROR;
}

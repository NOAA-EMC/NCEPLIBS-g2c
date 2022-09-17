/** 
 * @file
 * @brief Write summary output to a file, as is done by utility grb2index.
 *
 * @author Ed Hartnett @date Sep 17, 2022
 */

#include "grib2_int.h"
#include <stdarg.h>

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/** Pointer to the list of code tables. */
extern G2C_CODE_TABLE_T *g2c_table;

/**
 * Write an index file like the grb2index utility.
 *
 * @param g2cid Indentifier for the file, returned by g2c_open() or
 * g2c_create().
 * @param fileout Path of output file.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date Sep 17, 2022
 */
int
g2c_write_grib2_index(int g2cid, const char *fileout)
{
    return G2C_NOERROR;
}

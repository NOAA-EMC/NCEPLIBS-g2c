/** 
 * @file
 * @brief Inquiry functions.
 *
 * @author Ed Hartnett @date 10/21/22
 */
#include "grib2_int.h"
#include <stdarg.h>

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/**
 * Learn about a GRIB2 file.
 *
 * @param g2cid ID of the opened file, as from g2c_open().
 * @param num_msg Pointer that gets the number of messages in the
 * file. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/21/22
 */
int
g2c_inq(int g2cid, int *num_msg)
{
    /* Is this an open GRIB2 file? */
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    /* If the caller wants to know the number of messages, tell
     * them. */
    if (num_msg)
        *num_msg = g2c_file[g2cid].num_messages;
    
    return G2C_NOERROR;
}


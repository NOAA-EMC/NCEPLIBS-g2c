/** 
 * @file
 * @brief File functions for the g2c library.
 * @author Ed Hartnett @date Aug 16, 2022
 */

#include "grib2_int.h"

/** This is the information about each open file. */
typedef struct g2c_file_info_t
{
    int g2cid;
    char path[G2C_MAX_NAME + 1];
    FILE *f;
} G2C_FILE_INFO;

/** Global file information. */
G2C_FILE_INFO g2c_file[G2C_MAX_FILES];

/** Next g2cid file ID - used when opening or creating a file. */
int g2c_next_g2cid = 1;

/** Open an existing GRIB2 file.
 *
 * @param path Path of the file.
 * @param mode Open mode flags.
 * @param g2cid Pointer that gets an indentifier for the file.
 *
 * @return
 * - ::G2C_NO_ERROR - No error.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_open(const char *path, int mode, int *g2cid)
{
    int my_g2cid = g2c_next_g2cid;

    /* Check inputs. */
    if (strlen(path) > G2C_MAX_NAME)
	return G2C_LONG_NAME;
    if (!g2cid)
	return G2C_INVAL;

    /* Open the file. */
    if (!(g2c_file[my_g2cid].f = fopen(path, (mode & G2C_WRITE ? "r+" : "r"))))
	return G2C_FILE;

    /* Read the metadata. */

    /* Copy the path. */
    strncpy(g2c_file[my_g2cid].path, path, G2C_MAX_NAME);

    /* Remember the id and increment for next time. */
    g2c_file[my_g2cid].g2cid = g2c_next_g2cid++;
    
    /* Pass id back to user. */
    *g2cid = my_g2cid;
    
    return G2C_NO_ERROR;
}

/** Create a new GRIB2 file.
 *
 * @param path Path of the file.
 * @param cmode Open mode flags.
 * @param g2cid Pointer that gets an indentifier for the file.
 *
 * @return
 * - ::G2C_NO_ERROR - No error.
 * - ::G2C_FILE - File exsists and NOCLOBBER, or error opening file.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_create(const char *path, int cmode, int *g2cid)
{
    int my_g2cid = g2c_next_g2cid;
    
    /* Check inputs. */
    if (strlen(path) > G2C_MAX_NAME)
	return G2C_LONG_NAME;
    if (!g2cid)
	return G2C_INVAL;

    /* If NOCLOBBER, check if file exists. */
    if (cmode & G2C_NOCLOBBER)
    {
	FILE *f;
	if ((f = fopen(path, "r")))
	{
	    fclose(f);
	    return G2C_FILE;
	}
    }

    /* Create the file. */
    if (!(g2c_file[my_g2cid].f = fopen(path, "w+")))
	return G2C_FILE;

    /* Read the metadata. */

    /* Copy the path. */
    strncpy(g2c_file[my_g2cid].path, path, G2C_MAX_NAME);

    /* Remember the id. */
    g2c_file[my_g2cid].g2cid = g2c_next_g2cid++;

    /* Pass id back to user. */
    *g2cid = my_g2cid;
    
    return G2C_NO_ERROR;
}

/** Close a GRIB2 file, freeing resources.
 *
 * @param g2cid Indentifier for the file.
 *
 * @return
 * - ::G2C_NO_ERROR - No error.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_close(int g2cid)
{
    /* Is this an open file? */
    if (g2cid > G2C_MAX_FILES)
	return G2C_BADID;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_BADID;

    /* Close the file. */
    fclose(g2c_file[g2cid].f);

    /* Reset the file data. */
    g2c_file[g2cid].path[0] = 0;
    g2c_file[g2cid].g2cid = 0;
    g2c_file[g2cid].f = NULL;
    
    return G2C_NO_ERROR;
}



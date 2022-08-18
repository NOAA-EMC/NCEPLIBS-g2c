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
G2C_FILE_INFO g2c_file[G2C_MAX_FILES + 1];

/** Next g2cid file ID - used when opening or creating a file. */
int g2c_next_g2cid = 1;

/** Find a g2cid to use for a newly opened or created file.
 *
 * @param g2cid Pointer that gets the next available g2cid.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EINVAL - Invalid input.
 * - ::G2C_ETOOMANYFILES - Trying to open too many files at the same time.
 * '
 * @author Ed Hartnett 8/18/22
 */
static int
find_available_g2cid(int *g2cid)
{
    int i;
    
    /* Check input. */
    if (!g2cid)
	return G2C_EINVAL;

    /* Find a new g2cid. */
    for (i = 0; i < G2C_MAX_FILES + 1; i++)
    {
	int id = (i + g2c_next_g2cid) % (G2C_MAX_FILES + 1);

	/* Skip id 0. */
	if (!id)
	    continue;
	
	/* Is this ID available? If so, we're done. */
	if (!g2c_file[id].g2cid)
	{
	    *g2cid = id;
	    g2c_next_g2cid = id + 1;
	    return G2C_NOERROR;
	}
    }

    /* If we couldn't find one, they are all open. */
    return G2C_ETOOMANYFILES;
}

/** Open an existing GRIB2 file.
 *
 * @param path Path of the file.
 * @param mode Open mode flags.
 * @param g2cid Pointer that gets an indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EINVAL - Invalid input.
 * - ::G2C_ETOOMANYFILES - Trying to open too many files at the same time.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_open(const char *path, int mode, int *g2cid)
{
    int my_g2cid;
    int ret;

    /* Check inputs. */
    if (strlen(path) > G2C_MAX_NAME)
	return G2C_ENAMETOOLONG;
    if (!g2cid)
	return G2C_EINVAL;

    /* Find a file ID. */
    if ((ret = find_available_g2cid(&my_g2cid)))
	return ret;

    /* Open the file. */
    if (!(g2c_file[my_g2cid].f = fopen(path, (mode & G2C_WRITE ? "r+" : "r"))))
	return G2C_EFILE;

    /* Read the metadata. */

    /* Copy the path. */
    strncpy(g2c_file[my_g2cid].path, path, G2C_MAX_NAME);

    /* Remember the id. */
    g2c_file[my_g2cid].g2cid = my_g2cid;
    
    /* Pass id back to user. */
    *g2cid = my_g2cid;
    
    return G2C_NOERROR;
}

/** Create a new GRIB2 file.
 *
 * @param path Path of the file.
 * @param cmode Open mode flags.
 * @param g2cid Pointer that gets an indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EFILE - File exsists and NOCLOBBER, or error opening file.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_create(const char *path, int cmode, int *g2cid)
{
    int my_g2cid;
    int ret;
    
    /* Check inputs. */
    if (strlen(path) > G2C_MAX_NAME)
	return G2C_ENAMETOOLONG;
    if (!g2cid)
	return G2C_EINVAL;

    /* If NOCLOBBER, check if file exists. */
    if (cmode & G2C_NOCLOBBER)
    {
	FILE *f;
	if ((f = fopen(path, "r")))
	{
	    fclose(f);
	    return G2C_EFILE;
	}
    }

    /* Find a file ID. */
    if ((ret = find_available_g2cid(&my_g2cid)))
	return ret;

    /* Create the file. */
    if (!(g2c_file[my_g2cid].f = fopen(path, "w+")))
	return G2C_EFILE;

    /* Read the metadata. */

    /* Copy the path. */
    strncpy(g2c_file[my_g2cid].path, path, G2C_MAX_NAME);

    /* Remember the id. */
    g2c_file[my_g2cid].g2cid = my_g2cid;

    /* Pass id back to user. */
    *g2cid = my_g2cid;
    
    return G2C_NOERROR;
}

/** Close a GRIB2 file, freeing resources.
 *
 * @param g2cid Indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_close(int g2cid)
{
    /* Check input. */
    if (g2cid > G2C_MAX_FILES)
	return G2C_EBADID;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    /* Close the file. */
    fclose(g2c_file[g2cid].f);

    /* Reset the file data. */
    g2c_file[g2cid].path[0] = 0;
    g2c_file[g2cid].g2cid = 0;
    g2c_file[g2cid].f = NULL;
    
    return G2C_NOERROR;
}



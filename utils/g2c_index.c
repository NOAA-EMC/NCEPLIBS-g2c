/** @file
 *
 * @brief Write a GRIB2 index file.
 *
 * @author Ed Hartnett @date 12/29/22
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grib2.h>

/**
 * Write a GRIB2 index file.
 *
 * @param argc Number of arguments.
 * @param argv Pointer to array of arguments.
 *
 * @return
 * - 0 success
 * - 1 otherwise
 *
 * @author Ed Hartnett @date 9/10/23
 */
int
main(int argc, char **argv)
{
  char *path[2] = {NULL, NULL};
    int verbose = 0;
    int large_file_index = 0;
    int index;
    int write_index_flag = G2C_CLOBBER;
    int c;
    int p = 0;
    int g2cid;
    int ret;

    opterr = 0;

    /* Parse command line arguments. */
    while ((c = getopt(argc, argv, "v")) != -1)
    {
        switch (c)
        {
        case 'v':
            verbose = 1;
            break;
        case 'l':
            large_file_index = 1;
            break;
        case '?':
            if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            return 1;
        default:
            return G2C_ERROR;
        }
    }

    /* Get names of input and output files. */
    for (index = optind; index < argc; index++)
    {
        if (!(path[p] = malloc(sizeof(char) * strlen(argv[index]) + 1)))
            return G2C_ENOMEM;
        strcpy(path[p], argv[index]);
        if (++p == 2)
            break;
    }

    /* Yammer on and on. */
    if (verbose)
        printf("g2c_index %s reading index file %s summarizing into %s.\n", G2C_VERSION, path[0], path[1]);

    /* Open the GRIB2 file. */
    if ((ret = g2c_open(path[0], G2C_NOWRITE, &g2cid)))
        return ret;

    /* Write the index file. */
    if (large_file_index)
	write_index_flag &= G2C_LARGE_FILE_INDEX;
    if ((ret = g2c_write_index(g2cid, write_index_flag, path[1])))
        return ret;

    /* Close the file. */
    if ((ret = g2c_close(g2cid)))
        return ret;

    /* Free memory. */
    if (path[0])
      free(path[0]);
    if (path[1])
      free(path[1]);

    printf("returning 0\n");

    return 0;
}

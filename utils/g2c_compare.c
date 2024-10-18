/** @file
 * @brief This is a utility to compare two GRIB2 files.
 * @author Ed Hartnett @date 12/29/22
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grib2.h>

/**
 * Compare two GRIB2 files.
 *
 * @param argc Number of arguments.
 * @param argv Pointer to array of arguments.
 *
 * @return
 * - 0 if files are identical
 * - 1 otherwise
 *
 * @author Ed Hartnett @date 12/29/22
 */
int
main(int argc, char **argv)
{
    char *path[2];
    int verbose = 0;
    int index;
    int g2cid0, g2cid1;
    int c;
    int p = 0;
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
        printf("g2c_compare %s comparing %s and %s.\n", G2C_VERSION, path[0], path[1]);

    /* Open the two files. */
    g2c_set_log_level(10);
    if ((ret = g2c_open(path[0], G2C_NOWRITE, &g2cid0)))
        return ret;
    if ((ret = g2c_open(path[1], G2C_NOWRITE, &g2cid1)))
        return ret;

    /* Compare the files. */
    if ((ret = g2c_compare(g2cid0, g2cid1)))
        return ret;

    /* Close the files. */
    if ((ret = g2c_close(g2cid0)))
        return ret;
    if ((ret = g2c_close(g2cid1)))
        return ret;

    /* Clean up. */
    free(path[0]);
    free(path[1]);
    
    return 0;
}

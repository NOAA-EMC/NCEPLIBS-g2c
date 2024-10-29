/** @file
 * @brief This is a utility to print a summary of a GRIB2 file.
 * @author Ed Hartnett @date 12/29/22
 */
#include <ctype.h>
#include <grib2.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    int verbose = 0;
    int index;
    int g2cid;
    int c;
    int p = 0;
    char *filein = NULL;
    char *fileidx = NULL;
    char *fileout = NULL;
    int ret;

    opterr = 0;

    /* Parse command line arguments. */
    while ((c = getopt(argc, argv, "vo:")) != -1)
    {
        switch (c)
        {
        case 'v':
            verbose = 1;
            break;
        case 'o':
            if (!(fileout = malloc(sizeof(char) * strlen(optarg) + 1)))
                return G2C_ENOMEM;
            strcpy(fileout, optarg);
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

    /* Get names of input file(s). */
    for (index = optind; index < argc; index++)
    {
        if (!p)
        {
            if (!(filein = malloc(sizeof(char) * strlen(argv[index]) + 1)))
                return G2C_ENOMEM;
            strcpy(filein, argv[index]);
        }
        else
        {
            if (!(fileidx = malloc(sizeof(char) * strlen(argv[index]) + 1)))
                return G2C_ENOMEM;
            strcpy(fileidx, argv[index]);
        }
        if (++p == 2)
            break;
    }

    /* Turn on logging for verbose output. This only has effect if the
     * library was built with LOGGING=ON. */
    if (verbose)
        g2c_set_log_level(4);

    /* If we got one input file, open it. If we got two input files,
     * the second is an index file for the first. */
    if (p == 1)
    {
        if (verbose)
            printf("g2c_degrib2 %s summarizing %s into %s.\n", G2C_VERSION, filein, fileout);

        /* Open the GRIB2 file. */
        if ((ret = g2c_open(filein, G2C_NOWRITE, &g2cid)))
        {
            fprintf(stderr, "Could not read file %s.\n", filein);
            return ret;
        }
    }
    else if (p == 2)
    {
        if (verbose)
            printf("g2c_degrib2 %s summarizing %s, with index %s into %s.\n", G2C_VERSION,
                   filein, fileidx, fileout);

        /* Open the GRIB2 file with index. */
        if ((ret = g2c_open_index(filein, fileidx, G2C_NOWRITE, &g2cid)))
        {
            fprintf(stderr, "Could not read file %s with index %s.\n", filein, fileidx);
            return ret;
        }
    }
    else
    {
        printf("One or two filenames must be provided, for input and (optionally) index.\n");
        return G2C_ERROR;
    }

    /* Write the degrib2 summary. */
    if ((ret = g2c_degrib2(g2cid, fileout)))
    {
        fprintf(stderr, "Could not write degrib2 summary to %s.\n", fileout);
        return ret;
    }

    /* Close the file. */
    if ((ret = g2c_close(g2cid)))
    {
        fprintf(stderr, "Error closing the file.\n");
        return ret;
    }

    /* Free memory. */
    if (filein)
        free(filein);
    if (fileidx)
        free(fileidx);
    if (fileout)
        free(fileout);

    return 0;
}

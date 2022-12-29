/** @file
 * @brief This is a utility to print a summary of a GRIB2 file.
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
    int bflag = 0;
    int sflag = 0;
    int index;
    int c;

    opterr = 0;

    while ((c = getopt(argc, argv, "bs")) != -1)
    {
        switch (c)
        {
        case 'b':
            bflag = 1;
            break;
        case 's':
            sflag = 1;
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

    printf ("bflag = %d, sflag = %d\n", bflag, sflag);

    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    return 0;
}

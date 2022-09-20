/** 
 * @file
 * @brief Functions for serving up NOAA parameter abbreviations and
 * GRIB1/GRIB2 translations.
 *
 * @author Ed Hartnett @date 9/19/22
 */
#include "grib2_int.h"

/** This variable will be non-zero if the library has read the CSV
 * file contianing parameter information. */
static int init_params = 0;

/** The name of the CSV file which contains the NOAA abbreviations. */
#define CSV_FILE "noaa_grib2_params.csv"

/**
 * Read parameter information from the CSV file.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 9/19/22
 */
static int
read_params_csv()
{
    FILE *f;
    
    LOG((4, "read_params_csv()"));

    /* Open the CSV file with NOAA parameters. */
    if (!(f = fopen(CSV_FILE, "r")))
        return G2C_EFILE;

    /* Read the CSV file. */

    /* Close the CSV file. */
    if (fclose(f))
        return G2C_EFILE;        
    
    /* Remember that we have read our CSV file. */
    init_params++;
    
    return G2C_NOERROR;
}

/**
 * Translate GRIB1 parameter to GRIB2 parameter.
 *
 * @param g1val The GRIB1 parameter.
 * @param g1ver The GRIB1 parameter table version number.
 * @param g2disc Pointer that gets the GRIB2 discipline
 * number. Ignored if NULL.
 * @param g2cat Pointer that gets the GRIB2 category
 * number. Ignored if NULL.
 * @param g2num Pointer that gets the GRIB2 parameter
 * number. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_g1tog2(int g1val, int g1ver, int *g2disc, int *g2cat, int *g2num)
{
    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        read_params_csv();
    
    return G2C_NOERROR;
}

/**
 * Get NOAA abbreviation for a GRIB2 parameter.
 *
 * @param g2disc The GRIB2 discipline number.
 * @param g2cat The GRIB2 category number.
 * @param g2num The GRIB2 parameter number.
 * @param abbrev Pointer that gets the abbreviation.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_abbrev(int g2disc, int g2cat, int g2num, char *abbrev)
{
    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        read_params_csv();
    
    return G2C_NOERROR;
}

/**
 * Translate GRIB2 parameter to GRIB1 parameter.
 *
 * @param g2disc The GRIB2 discipline number.
 * @param g2cat The GRIB2 category number.
 * @param g2num The GRIB2 parameter number.
 * @param g1val Pointer that gets the GRIB1 parameter. Ignored if
 * NULL.
 * @param g1ver Pointer that gets the GRIB1 parameter table version
 * number. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_g2tog1(int g2disc, int g2cat, int g2num, int *g1val, int *g1ver)
{
    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        read_params_csv();
    
    return G2C_NOERROR;
}

/**
 * Return all the information about a parameter.
 *
 * @param param_idx Parameter index between 0 and ::G2C_MAX_NOAA_PARAMS.
 * @param g1ver Pointer that gets the GRIB1 parameter table version
 * number. Ignored if NULL.
 * @param g1val Pointer that gets the GRIB1 parameter. Ignored if
 * NULL.
 * @param g2disc Pointer that gets the GRIB2 discipline
 * number. Ignored if NULL.
 * @param g2cat Pointer that gets the GRIB2 category number. Ignored
 * if NULL.
 * @param g2num Pointer that gets the GRIB2 parameter number. Ignored
 * if NULL.
 * @param abbrev Pointer that gets the abbreviation.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_all(int param_idx, int *g1ver, int *g1val, int *g2disc, int *g2cat,
              int *g2num, char *abbrev)
{
    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        read_params_csv();
    
    return G2C_NOERROR;
}



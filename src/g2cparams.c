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

/** An array of parameter information. */
static G2C_PARAM_T param[G2C_MAX_NOAA_PARAMS];

/**
 * Trim whitespace from a string.
 * 
 * @param str String to trim.
 *
 * @return Pointer to the trimmed string.
 *
 * @author Ed Hartnett @date 9/20/22
 */
static char *
trim(char *str)
{
  char *end;

  /* Trim leading space. */
  while(isspace((unsigned char)*str))
      str++;

  /* All spaces? */
  if (*str == 0)  
      return str;

  /* Trim trailing space. */
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end))
      end--;

  /* Write new null terminator character. */
  end[1] = '\0';

  return str;
}

/**
 * Read parameter information from the CSV file.
 *
 * @note Any abbreviation longer than ::G2C_MAX_NOAA_ABBREV_LEN will
 * be truncated to that length.
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
    char *csv_filename = NULL, *csv_filename_test;
    char row[G2C_MAX_NOAA_PARAM_LINE_LEN];
    int p = 0;
    
    LOG((4, "read_params_csv()"));

    /* Determine CSV filename. */
    if (!(csv_filename_test = malloc(sizeof(char) * (strlen(G2C_DATADIR) + strlen(CSV_FILE)) + 2)))
        return G2C_ENOMEM;
    strcpy(csv_filename_test, G2C_DATADIR);
    strcat(csv_filename_test, "/");
    strcat(csv_filename_test, CSV_FILE);
    LOG((4, "opening csv params file %s", csv_filename_test));

    /* Open the CSV file with NOAA parameters. If it doesn't work, try
     * the install/lib directory. */
    if (!(f = fopen(csv_filename_test, "r")))
    {
        /* Determine installed CSV filename. */
        if (!(csv_filename = malloc(sizeof(char) * (strlen(INSTALL_G2C_DATADIR) + strlen(CSV_FILE)) + 2)))
            return G2C_ENOMEM;
        strcpy(csv_filename, INSTALL_G2C_DATADIR);
        strcat(csv_filename, "/");
        strcat(csv_filename, CSV_FILE);
        LOG((4, "test CSV data flle not found, tryping to open installed version %s", csv_filename));
        
        /* Open the CSV file with NOAA parameters in the test direcotory. */
        if (!(f = fopen(csv_filename, "r")))
        {
            free(csv_filename);
            free(csv_filename_test);
            return G2C_EFILE;
        }
    }

    /* Free filenames. */
    free(csv_filename_test);
    if (csv_filename)
        free(csv_filename);

    /* Skip the first line of the CSV file. */
    if (!fgets(row, G2C_MAX_NOAA_PARAM_LINE_LEN, f))
        return G2C_EFILE;
    
    /* Read the CSV file one line at a time. */
    while (fgets(row, G2C_MAX_NOAA_PARAM_LINE_LEN, f))
    {
        char *token;
        int token_num = 0;

        token = strtok(row, ",");
        while (token)
        {
            switch (token_num)
            {
            case 0: /* do nothing */
                break; 
            case 1:
                param[p].g1num = strtol(token, NULL, 10);
                break;
            case 2:
                param[p].g1ver = strtol(token, NULL, 10);
                break;
            case 3:
                param[p].g2disc = strtol(token, NULL, 10);
                break;
            case 4:
                param[p].g2cat = strtol(token, NULL, 10);
                break;
            case 5:
                param[p].g2num = strtol(token, NULL, 10);
                break;
            case 6:
                strncpy(param[p].abbrev, trim(token), G2C_MAX_NOAA_ABBREV_LEN + 1);
                param[p].abbrev[G2C_MAX_NOAA_ABBREV_LEN] = 0; /* ensure null-termination */
                LOG((5, "abbrev %s", param[p].abbrev));
                break;
            }
            token_num++;
            token = strtok(NULL, ",");
        }

        LOG((5, "%d g1num %d g1ver %d g2disc %d g2cat %d g2val %d abbrev %s", p, param[p].g1num,
             param[p].g1ver, param[p].g2disc, param[p].g2cat, param[p].g2num, param[p].abbrev));

        /* Move to the next parameter. */
        p++;
    }    

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
 * @param g1num The GRIB1 parameter.
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
 * - ::G2C_EFILE Error reading CSV file.
 * - ::G2C_ENOPARAM Parameter not found.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_g1tog2(int g1num, int g1ver, int *g2disc, int *g2cat, int *g2num)
{
    int p;
    int ret;
    
    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        if ((ret = read_params_csv()))
            return ret;
    
    /* Loop through array until matching values are found. */
    for (p = 0; p < G2C_MAX_NOAA_PARAMS; p++)
        if (param[p].g1num == g1num && param[p].g1ver == g1ver)
            break;

    /* Did we find the parameter? */
    if (p == G2C_MAX_NOAA_PARAMS)
        return G2C_ENOPARAM;

    /* Does the user want the answers? */
    if (g2disc)
        *g2disc = param[p].g2disc;
    if (g2cat)
        *g2cat = param[p].g2cat;
    if (g2num)
        *g2num = param[p].g2num;

    return G2C_NOERROR;
}

/**
 * Get NOAA abbreviation for a GRIB2 parameter.
 *
 * @param g2disc The GRIB2 discipline number.
 * @param g2cat The GRIB2 category number.
 * @param g2num The GRIB2 parameter number.
 * @param abbrev Pointer that gets the abbreviation. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EFILE Error reading CSV file.
 * - ::G2C_ENOPARAM Parameter not found.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_abbrev(int g2disc, int g2cat, int g2num, char *abbrev)
{
    int p;
    int ret;

    /* If this is NULL, the user doesn't care about the answer, so we're done. */
    if (!abbrev)
        return G2C_NOERROR;

    LOG((1, "g2c_param_abbrev g2disc %d g2cat %d g2num %d", g2disc, g2cat, g2num));

    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        if ((ret = read_params_csv()))
            return ret;

    /* Loop through array until matching values are found. */
    for (p = 0; p < G2C_MAX_NOAA_PARAMS; p++)
        if (param[p].g2disc == g2disc && param[p].g2cat == g2cat && param[p].g2num == g2num)
            break;

    /* Did we find the parameter? */
    if (p == G2C_MAX_NOAA_PARAMS)
        return G2C_ENOPARAM;

    /* Return the abbreviation to the caller. */
    strncpy(abbrev, param[p].abbrev, G2C_MAX_NOAA_ABBREV_LEN + 1);

    LOG((2, "abbrev %s", abbrev));
    
    return G2C_NOERROR;
}

/**
 * Translate GRIB2 parameter to GRIB1 parameter.
 *
 * @param g2disc The GRIB2 discipline number.
 * @param g2cat The GRIB2 category number.
 * @param g2num The GRIB2 parameter number.
 * @param g1num Pointer that gets the GRIB1 parameter. Ignored if
 * NULL.
 * @param g1ver Pointer that gets the GRIB1 parameter table version
 * number. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EFILE Error reading CSV file.
 * - ::G2C_ENOPARAM Parameter not found.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_g2tog1(int g2disc, int g2cat, int g2num, int *g1num, int *g1ver)
{
    int p;
    int ret;

    LOG((2, "g2c_param_g2tog1 g2disc %d g2cat %d g2num %d", g2disc, g2cat, g2num));
    
    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        if ((ret = read_params_csv()))
            return ret;
    
    /* Loop through array until matching values are found. */
    for (p = 0; p < G2C_MAX_NOAA_PARAMS; p++)
        if (param[p].g2disc == g2disc && param[p].g2cat == g2cat && param[p].g2num == g2num)
            break;

    /* Did we find the parameter? */
    if (p == G2C_MAX_NOAA_PARAMS)
        return G2C_ENOPARAM;

    /* Does the user want the answers? */
    if (g1num)
        *g1num = param[p].g1num;
    if (g1ver)
        *g1ver = param[p].g1ver;

    return G2C_NOERROR;
}

/**
 * Return all the information about a parameter.
 *
 * @param param_idx Parameter index between 0 and ::G2C_MAX_NOAA_PARAMS.
 * @param g1num Pointer that gets the GRIB1 parameter. Ignored if
 * NULL.
 * @param g1ver Pointer that gets the GRIB1 parameter table version
 * number. Ignored if NULL.
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
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_EFILE Error reading CSV file.
 * - ::G2C_ENOPARAM Parameter not found.
 *
 * @author Ed Hartnett @date 9/19/22
 */
int
g2c_param_all(int param_idx, int *g1num, int *g1ver, int *g2disc, int *g2cat,
              int *g2num, char *abbrev)
{
    int ret;
    
    /* If needed, ingest the CSV file of parameter information. */
    if (!init_params)
        if ((ret = read_params_csv()))
            return ret;

    /* Check input. */
    if (param_idx < 0 || param_idx >= G2C_MAX_NOAA_PARAMS)
        return G2C_EINVAL;

    /* Return results to caller. */
    if (g1num)
        *g1num = param[param_idx].g1num;
    if (g1ver)
        *g1ver = param[param_idx].g1ver;
    if (g2disc)
        *g2disc = param[param_idx].g2disc;
    if (g2cat)
        *g2cat = param[param_idx].g2cat;
    if (g2num)
        *g2num = param[param_idx].g2num;
    if (abbrev)
        strncpy(abbrev, param[param_idx].abbrev, G2C_MAX_NOAA_ABBREV_LEN);
    
    return G2C_NOERROR;
}



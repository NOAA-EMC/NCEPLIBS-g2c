/**
 * @file
 * @brief Functions for GRIB2 Product Definition Templates used in
 * Section 4 - the Product Definition Section (PDS).
 *
 * Each Template has three parts:
 * 1. The number of entries in the template (mappdslen).
 * 2. A map of the template (mappds), which contains the number of
 * octets in which to pack each of the template values.
 * 3. A logical value (needext) that indicates whether the Template
 * needs to be extended. In some cases the number of entries in a
 * template can vary depending upon values specified in the "static"
 * part of the template. (See Template 4.3 as an example).
 *
 * @note Array mappds contains the number of octets in which the
 * corresponding template values will be stored. A negative value in
 * mappds is used to indicate that the corresponding template entry
 * can contain negative values. This information is used later when
 * packing (or unpacking) the template data values. Negative data
 * values in GRIB are stored with the left most bit set to one, and a
 * negative number of octets value in mappds[] indicates that this
 * possibility should be considered. The number of octets used to
 * store the data value in this case would be the absolute value of
 * the negative value in mappds.
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2001-06-28 | Gilbert | Initial
 * 2009-01-14 | Vuong | Changed structure name template to gtemplate
 * 2009-12-15 | Vuong | Added Product Definition Templates 4.31, 4.15
 * 2010-08-03 | Vuong | Added Product Definition Template 4.42 and 4.43
 * 2010-12-08 | Vuong | Corrected Product Definition Template 4.42 and 4.43
 * 2012-03-29 | Vuong | Added Templates 4.44,4.45,4.46,4.47,4.48,4.50, 4.51,4.91,4.32 and 4.52
 * 2013-08-05 | Vuong | Corrected 4.91 and added Templates 4.33,4.34,4.53,4.54
 * 2015-10-07 | Vuong | Added Templates 4.57, 4.60, 4.61 and allow a forecast time to be negative
 * 2022-10-18 | Hartnett | Added g2c_get_pds_template() and g2c_get_pds_template_extension().
 *
 * @author Stephen Gilbert @date 2001-06-28
 */
#include "grib2_int.h"

/**
 * Struct for PDS template.
 */
struct pdstemplate
{
    g2int template_num;                        /**< Template number. */
    g2int mappdslen;                           /**< The number of entries in the template. */
    g2int needext;                             /**< Does template need extension? */
    g2int mappds[G2C_MAX_PDS_TEMPLATE_MAPLEN]; /**< Number of bytes for each template value. */
};

/**
 * Data for struct for PDS template.
 */
static const struct pdstemplate templatespds[G2C_MAX_PDS_TEMPLATE] =
    {
        /** 4.0: Analysis or Forecast at Horizontal Level/Layer
        at a point in time. */
        {0, 15, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}},
        /** 4.1: Individual Ensemble Forecast at Horizontal Level/Layer
        at a point in time. */
        {1, 18, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}},
        /** 4.2: Derived Fcst based on whole Ensemble at Horiz Level/Layer
        at a point in time. */
        {2, 17, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1}},
        /** 4.3: Derived Fcst based on Ensemble cluster over rectangular
        area at Horiz Level/Layer at a point in time. */
        {3, 31, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, -4, 4, 4, 1, -1, 4, -1, 4}},
        /** 4.4: Derived Fcst based on Ensemble cluster over circular
        area at Horiz Level/Layer at a point in time. */
        {4, 30, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, 4, 4, 1, -1, 4, -1, 4}},
        /** 4.5: Probablility Forecast at Horiz Level/Layer
        at a point in time. */
        {5, 22, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, -1, -4, -1, -4}},
        /** 4.6: Percentile Forecast at Horiz Level/Layer
        at a point in time. */
        {6, 16, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1}},
        /** 4.7: Analysis or Forecast Error at Horizontal Level/Layer
        at a point in time. */
        {7, 15, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}},
        /** 4.8: Ave/Accum/etc... at Horiz Level/Layer
        in a time interval. */
        {8, 29, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.9: Probablility Forecast at Horiz Level/Layer
        in a time interval. */
        {9, 36, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, -1, -4, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.10: Percentile Forecast at Horiz Level/Layer
        in a time interval */
        {10, 30, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.11: Individual Ensemble Forecast at Horizontal Level/Layer
        in a time interval */
        {11, 32, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.12: Derived Fcst based on whole Ensemble at Horiz Level/Layer
        in a time interval */
        {12, 31, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.13: Derived Fcst based on Ensemble cluster over rectangular
        area at Horiz Level/Layer in a time interval */
        {13, 45, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, -4, 4, 4, 1, -1, 4, -1, 4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.14: Derived Fcst based on Ensemble cluster over circular
        area at Horiz Level/Layer in a time interval */
        {14, 44, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 1, 1, 1, 1, -4, 4, 4, 1, -1, 4, -1, 4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.15: Average, accumulation, extreme values or other statistically-processed values over a
        spatial area at a horizontal level or in a horizontal layer at a point in time */
        {15, 18, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}},
        /** 4.20: Radar Product */
        {20, 19, 0, {1, 1, 1, 1, 1, -4, 4, 2, 4, 2, 1, 1, 1, 1, 1, 2, 1, 3, 2}},
        /** 4.30: Satellite Product */
        {30, 5, 1, {1, 1, 1, 1, 1}},
        /** 4.31: Satellite Product */
        {31, 5, 1, {1, 1, 1, 1, 1}},
        /** 4.40: Analysis or forecast at a horizontal level or in a horizontal layer
        at a point in time for atmospheric chemical constituents */
        {40, 16, 0, {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}},
        /** 4.41: Individual ensemble forecast, control and perturbed, at a horizontal level or
        in a horizontal layer at a point in time for atmospheric chemical constituents */
        {41, 19, 0, {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}},
        /** 4.42: Average, accumulation, and/or extreme values or other statistically-processed values
        at a horizontal level or in a horizontal layer in a continuous or non-continuous
        time interval for atmospheric chemical constituents */
        {42, 30, 1, {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.43: Individual ensemble forecast, control and perturbed, at a horizontal level
        or in a horizontal layer in a continuous or non-continuous
        time interval for atmospheric chemical constituents */
        {43, 33, 1, {1, 1, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.254: CCITT IA5 Character String */
        {254, 3, 0, {1, 1, 4}},
        /** 4.1000: Cross section of analysis or forecast
        at a point in time */
        {1000, 9, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4}},
        /** 4.1001: Cross section of Ave/Accum/etc... analysis or forecast
        in a time interval */
        {1001, 16, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.1001: Cross section of Ave/Accum/etc... analysis or forecast
        over latitude or longitude */
        {1002, 15, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, 1, 1, 4, 4, 2}},
        /** 4.1100: Hovmoller-type grid w/ no averaging or other
        statistical processing */
        {1100, 15, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}},
        /** 4.1100: Hovmoller-type grid with averaging or other
        statistical processing */
        {1101, 22, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.32:Simulate (synthetic) Satellite Product */
        {32, 10, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1}},
        /** 4.44: Analysis or forecast at a horizontal level or in a horizontal layer
        at a point in time for Aerosol */
        {44, 21, 0, {1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -2, 1, -1, -4, 1, -1, -4}},
        /** 4.45: Individual ensemble forecast, control and
        perturbed,  at a horizontal level or in a horizontal layer
        at a point in time for Aerosol */
        {45, 24, 0, {1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}},
        /** 4.46: Ave or Accum or Extreme value at level/layer
        at horizontal level or in a horizontal in a continuous or
        non-continuous time interval for Aerosol */
        {46, 35, 1, {1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** 4.47: Individual ensemble forecast, control and
        perturbed, at horizontal level or in a horizontal
        in a continuous or non-continuous time interval for Aerosol. */
        {47, 38, 1, {1, 1, 1, 2, 1, -1, -4, -1, -4, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /**             PDT 4.48
                    4.48: Analysis or forecast at a horizontal level or in a horizontal layer
                    at a point in time for Optical Properties of Aerosol */
        {48, 26, 0, {1, 1, 2, 1, -1, -4, -1, -4, 1, -1, -4, -1, -4, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}},

        /**             VALIDATION --- PDT 4.50
                    4.50: Analysis or forecast of multi component parameter or
                    matrix element at a point in time. */
        {50, 21, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 4, 4, 4, 4}},

        /**             VALIDATION --- PDT 4.52
                    4.52: Analysis or forecast of Wave parameters
                    at the Sea surface at a point in time. */
        {52, 15, 0, {1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4}},

        /** 4.51: Categorical forecasts at a horizontal level or
        in a horizontal layer at a point in time. */
        {51, 16, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1}},

        /** 4.91: Categorical forecasts at a horizontal level or
        in a horizontal layer at a point in time
        in a continuous or non-continuous time interval. */
        {91, 36, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, -1, -4, -1, -4, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** PDT 4.33  (07/29/2013)
    4.33: Individual ensemble forecast, control, perturbed,
    at a horizontal level or in a  horizontal layer
    at a point in time for simulated (synthetic) Satellite data. */
        {33, 18, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, 2, 2, 2, -1, -4, 1, 1, 1}},
        /** PDT 4.34  (07/29/2013)
    4.34: Individual ensemble forecast, control, perturbed,
    at a horizontal level or in a  horizontal layer,in a continuous or
    non-continuous interval for simulated (synthetic) Satellite data. */
        {34, 32, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, 2, 2, 2, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /** PDT 4.53  (07/29/2013)
    4.53:  Partitioned parameters at
    horizontal level or horizontal layer
    at a point in time. */
        {53, 19, 1, {1, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4}},
        /** PDT 4.54  (07/29/2013)
    4.54: Individual ensemble forecast, control, perturbed,
    at a horizontal level or in a  horizontal layer
    at a point in time for partitioned parameters. */
        {54, 22, 1, {1, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1}},
        /** PDT 4.57  (10/07/2015)
    4.57: Analysis or Forecast at a horizontal or in a
    horizontal layer at a point in time for
    atmospheric chemical constituents based on
    a distribution function. */
        {57, 7, 1, {1, 1, 2, 2, 2, 2, 1}},
        /** PDT 4.60  (10/07/2015)
    4.60: Individual ensemble reforecast, control and perturbed,
    at a horizontal level or in a horizontal layer
    at a point in time. */
        {60, 24, 0, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1}},
        /** PDT 4.61  (10/07/2015)
    4.61: Individual ensemble reforecast, control and perturbed,
    at a horizontal level or in a  horizontal layer
    in a continuous or non-continuous time interval. */
        {61, 38, 1, {1, 1, 1, 1, 1, 2, 1, 1, -4, 1, -1, -4, 1, -1, -4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 1, 4}},
        /**             VALIDATION --- PDT 4.35
                PDT 4.35  (10/07/2015)
                4.35: Individual ensemble reforecast, control and perturbed,
                at a horizontal level or in a  horizontal layer
                in a continuous or non-continuous time interval. */
        {35, 6, 1, {1, 1, 1, 1, 1, 1}}

};

/**
 * This function returns the index of specified Product Definition
 * Template in array templates.
 *
 * @param number The number of the Product Definition
 * Template that is being requested.
 *
 * @return Index of PDT in array templates, if template
 * exists. -1, otherwise.
 *
 * @author Stephen Gilbert @date 2001-06-28
 */
static g2int
getpdsindex(g2int number)
{
    g2int j, getpdsindex = -1;

    for (j = 0; j < G2C_MAX_PDS_TEMPLATE; j++)
    {
        if (number == templatespds[j].template_num)
        {
            getpdsindex = j;
            return getpdsindex;
        }
    }

    return getpdsindex;
}

/**
 * This subroutine returns PDS template information for a specified
 * Product Definition Template. The number of entries in the
 * template is returned along with a map of the number of octets
 * occupied by each entry. Also, a flag is returned to indicate
 * whether the template would need to be extended.
 *
 * This function allocates memory for the gtemplate struct, which must
 * be freed by the caller.
 *
 * @param number the number of the Product Definition
 * Template that is being requested.
 *
 * @return Pointer to the returned template struct. Returns NULL
 * pointer if template not found.
 *
 * @author Stephen Gilbert @date 2000-05-11
 */
gtemplate *
getpdstemplate(g2int number)
{
    g2int index;
    gtemplate *new;

    index = getpdsindex(number);

    if (index != -1)
    {
        new = malloc(sizeof(gtemplate));
        new->type = 4;
        new->num = templatespds[index].template_num;
        new->maplen = templatespds[index].mappdslen;
        new->needext = templatespds[index].needext;
        new->map = (g2int *)templatespds[index].mappds;
        new->extlen = 0;
        new->ext = NULL;
        return new;
    }
    else
    {
        printf("getpdstemplate: PDS Template 4.%d not defined.\n", (int)number);
        return NULL;
    }

    return NULL;
}

/**
 * This subroutine generates the remaining octet map for a given
 * Product Definition Template, if required. Some Templates can vary
 * depending on data values given in an earlier part of the Template,
 * and it is necessary to know some of the earlier entry values to
 * generate the full octet map of the Template.
 *
 * This function allocates memory in the ext field of the gtemplate
 * struct. This memory must be freed by the caller.
 *
 * @param number number of the Product Definition Template 4.NN that
 * is being requested.
 * @param list The list of values for each entry in the the Product
 * Definition Template.
 *
 * @return Pointer to the returned template struct. Returns NULL
 * pointer if template not found.
 *
 * @author Stephen Gilbert @date 2000-05-11
 */
gtemplate *
extpdstemplate(g2int number, g2int *list)
{
    gtemplate *new;
    g2int index, i, j, k, l;

    index = getpdsindex(number);
    if (index == -1)
        return NULL;

    new = getpdstemplate(number);

    if (!new->needext)
        return new;

    if (number == 3)
    {
        new->extlen = list[26];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < new->extlen; i++)
        {
            new->ext[i] = 1;
        }
    }
    else if (number == 4)
    {
        new->extlen = list[25];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < new->extlen; i++)
        {
            new->ext[i] = 1;
        }
    }
    else if (number == 8)
    {
        if (list[21] > 1)
        {
            new->extlen = (list[21] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[21]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[23 + k];
                }
            }
        }
    }
    else if (number == 9)
    {
        if (list[28] > 1)
        {
            new->extlen = (list[28] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[28]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[30 + k];
                }
            }
        }
    }
    else if (number == 10)
    {
        if (list[22] > 1)
        {
            new->extlen = (list[22] - 1) * 6;
            new->ext = (g2int *)malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[22]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[24 + k];
                }
            }
        }
    }
    else if (number == 11)
    {
        if (list[24] > 1)
        {
            new->extlen = (list[24] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[24]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[26 + k];
                }
            }
        }
    }
    else if (number == 12)
    {
        if (list[23] > 1)
        {
            new->extlen = (list[23] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[23]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[25 + k];
                }
            }
        }
    }
    else if (number == 13)
    {
        new->extlen = ((list[37] - 1) * 6) + list[26];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        if (list[37] > 1)
        {
            for (j = 2; j <= list[37]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[39 + k];
                }
            }
        }
        l = (list[37] - 1) * 6;
        if (l < 0)
            l = 0;
        for (i = 0; i < list[26]; i++)
        {
            new->ext[l + i] = 1;
        }
    }
    else if (number == 14)
    {
        new->extlen = ((list[36] - 1) * 6) + list[25];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        if (list[36] > 1)
        {
            for (j = 2; j <= list[36]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[38 + k];
                }
            }
        }
        l = (list[36] - 1) * 6;
        if (l < 0)
            l = 0;
        for (i = 0; i < list[25]; i++)
        {
            new->ext[l + i] = 1;
        }
    }
    else if (number == 30)
    {
        new->extlen = list[4] * 5;
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < list[4]; i++)
        {
            l = i * 5;
            new->ext[l] = 2;
            new->ext[l + 1] = 2;
            new->ext[l + 2] = 1;
            new->ext[l + 3] = 1;
            new->ext[l + 4] = 4;
        }
    }
    else if (number == 31)
    {
        new->extlen = list[4] * 5;
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < list[4]; i++)
        {
            l = i * 5;
            new->ext[l] = 2;
            new->ext[l + 1] = 2;
            new->ext[l + 2] = 2;
            new->ext[l + 3] = 1;
            new->ext[l + 4] = 4;
        }
    }
    else if (number == 42)
    {
        if (list[22] > 1)
        {
            new->extlen = (list[22] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[22]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[24 + k];
                }
            }
        }
    }
    else if (number == 43)
    {
        if (list[25] > 1)
        {
            new->extlen = (list[25] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[25]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[27 + k];
                }
            }
        }
    }
    else if (number == 32)
    {
        new->extlen = list[9] * 5;
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < list[9]; i++)
        {
            l = i * 5;
            new->ext[l] = 2;
            new->ext[l + 1] = 2;
            new->ext[l + 2] = 2;
            new->ext[l + 3] = -1;
            new->ext[l + 4] = -4;
        }
    }
    else if (number == 46)
    {
        if (list[27] > 1)
        {
            new->extlen = (list[27] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[27]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[29 + k];
                }
            }
        }
    }
    else if (number == 47)
    {
        if (list[30] > 1)
        {
            new->extlen = (list[30] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[30]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[32 + k];
                }
            }
        }
    }
    else if (number == 51)
    {
        new->extlen = list[15] * 6;
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < list[15]; i++)
        {
            l = i * 6;
            new->ext[l] = 1;
            new->ext[l + 1] = 1;
            new->ext[l + 2] = -1;
            new->ext[l + 3] = -4;
            new->ext[l + 4] = -1;
            new->ext[l + 5] = -4;
        }
    }
    else if (number == 33)
    {
        new->extlen = list[9];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < new->extlen; i++)
        {
            new->ext[i] = 1;
        }
    }
    else if (number == 34)
    {
        new->extlen = ((list[24] - 1) * 6) + list[9];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        if (list[24] > 1)
        {
            for (j = 2; j <= list[24]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[26 + k];
                }
            }
        }
        l = (list[24] - 1) * 6;
        if (l < 0)
            l = 0;
        for (i = 0; i < list[9]; i++)
        {
            new->ext[l + i] = 1;
        }
    }
    else if (number == 53)
    {
        new->extlen = list[3];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < new->extlen; i++)
        {
            new->ext[i] = 1;
        }
    }
    else if (number == 54)
    {
        new->extlen = list[3];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < new->extlen; i++)
        {
            new->ext[i] = 1;
        }
    }
    else if (number == 91)
    {
        new->extlen = ((list[28] - 1) * 6) + list[15];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        if (list[28] > 1)
        {
            for (j = 2; j <= list[28]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[30 + k];
                }
            }
        }
        l = (list[29] - 1) * 6;
        if (l < 0)
            l = 0;
        for (i = 0; i < list[15]; i++)
        {
            new->ext[l + i] = 1;
        }
    }
    /* PDT 4.57  (10/07/2015) */
    else if (number == 57)
    {
        new->extlen = list[6] * 15;
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < list[6]; i++)
        {
            l = i * 15;
            new->ext[l] = 1;
            new->ext[l + 1] = -4;
            new->ext[l + 2] = 1;
            new->ext[l + 3] = 1;
            new->ext[l + 4] = 1;
            new->ext[l + 5] = 2;
            new->ext[l + 6] = 1;
            new->ext[l + 7] = 1;
            new->ext[l + 8] = -4;
            new->ext[l + 9] = 1;
            new->ext[l + 10] = -1;
            new->ext[l + 11] = -4;
            new->ext[l + 12] = 1;
            new->ext[l + 13] = -1;
            new->ext[l + 14] = -4;
        }
    }
    /* PDT 4.61  (10/07/2015) */
    else if (number == 61)
    {
        if (list[30] > 1)
        {
            new->extlen = (list[30] - 1) * 6;
            new->ext = malloc(sizeof(g2int) * new->extlen);
            for (j = 2; j <= list[30]; j++)
            {
                l = (j - 2) * 6;
                for (k = 0; k < 6; k++)
                {
                    new->ext[l + k] = new->map[32 + k];
                }
            }
        }
    }
    /* PDT 4.35  (10/07/2015) */
    else if (number == 35)
    {
        new->extlen = list[5] * 5;
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < list[5]; i++)
        {
            l = i * 5;
            new->ext[l] = 2;
            new->ext[l + 1] = 2;
            new->ext[l + 2] = 2;
            new->ext[l + 3] = 1;
            new->ext[l + 4] = 4;
        }
    }
    return new;
}

/**
 * Get pds template extension information.
 *
 * @param pds_template_num The pds template number.
 * @param template Pointer to array that contains the template values.
 * @param extlen Pointer that gets the length of the extension. Ignored if NULL.
 * @param ext Pointer that gets template extension array, if there is
 * one. Memory must be allocated by the caller. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_ENOTEMPLATE Template not found.
 * - ::G2C_ENOMEM Out of memory.
 *
 * @author Ed Hartnett @date 10/16/22
 */
int
g2c_get_pds_template_extension(int pds_template_num, int *template,
                               int *extlen, int *ext)
{
    int j, t;

    /* Check input. */
    if (!template)
        return G2C_EINVAL;

    /* Look through the array of templates to find a matching one. */
    for (j = 0; j < G2C_MAX_PDS_TEMPLATE; j++)
    {
        if (pds_template_num == templatespds[j].template_num)
        {
            /* Is there an extension to this template? */
            if (templatespds[j].needext)
            {
                gtemplate *gt;
                g2int *template8;
                int e;

                /* Copy template to g2int for extpdstemplate() function. */
                if (!(template8 = malloc(sizeof(g2int) * templatespds[j].mappdslen)))
                    return G2C_ENOMEM;
                for (t = 0; t < templatespds[j].mappdslen; t++)
                    template8[t] = template[t];
                if (!(gt = extpdstemplate(pds_template_num, template8)))
                    return G2C_ENOTEMPLATE;
                free(template8);
                if (extlen)
                    *extlen = gt->extlen;
                if (ext)
                    for (e = 0; e < gt->extlen; e++)
                        ext[e] = gt->ext[e];
                free(gt->ext);
                free(gt);
            }
            else
            {
                if (extlen)
                    *extlen = 0;
            }

            /* Done. */
            return G2C_NOERROR;
        }
    }

    /* If we didn't find a template, return an error. */
    return G2C_ENOTEMPLATE;
}

/**
 * Get PDS template information.
 *
 * The PDS template consists of a template map, its length, and, for
 * some templates, an extra extension map, and its length. If an
 * extension is needed, use g2c_get_pds_template_extension() to get
 * it.
 *
 * @param pds_template_num The PDS template number.
 * @param maplen Pointer that gets the length of the map. Ignored if
 * NULL.
 * @param map Pointer that gets the map as an array of int. Memory
 * must be allocated by caller. Ignored if NULL.
 * @param needext Pointer that a non-zero value if an extension to
 * this template is needed. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_ENOTEMPLATE Template not found.
 *
 * @author Ed Hartnett @date 10/18/22
 */
int
g2c_get_pds_template(int pds_template_num, int *maplen, int *map, int *needext)
{
    int j, m;

    /* Look through the array of templates to find a matching one. */
    for (j = 0; j < G2C_MAX_PDS_TEMPLATE; j++)
    {
        if (pds_template_num == templatespds[j].template_num)
        {
            /* Copy maplen and map if the caller wants them. */
            if (maplen)
                *maplen = templatespds[j].mappdslen;
            if (map)
                for (m = 0; m < templatespds[j].mappdslen; m++)
                    map[m] = templatespds[j].mappds[m];
            if (needext)
                *needext = templatespds[j].needext;

            /* Done. */
            return G2C_NOERROR;
        }
    }

    /* If we didn't find a template, return an error. */
    return G2C_ENOTEMPLATE;
}

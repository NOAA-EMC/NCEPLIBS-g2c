/**
 * @file
 * @brief Compare the metadata of two open GRIB2 files.
 *
 * @author Ed Hartnett @date Dec 28, 2022
 */
#include "grib2_int.h"
#include <stdarg.h>
#include <math.h>

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/**
 * Compare the metadata of two open GRIB2 files.
 *
 * @param g2cid1 Indentifier for one file.
 * @param g2cid2 Indentifier for the other file.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EINVAL Invalid parameters.
 * - ::G2C_EFILE File I/O error.
 *
 * @author Ed Hartnett @date Dec 28, 2022
 */
int
g2c_metadata_cmp(int g2cid1, int g2cid2);
{
    FILE *f;
    G2C_MESSAGE_INFO_T *msg;
    int total_fields = 0;
    int i;
    int ret;

    /* Check inputs. */
    if (g2cid1 < 0 || g2cid1 > G2C_MAX_FILES || g2c_file[g2cid1].g2cid != g2cid1)
        return G2C_EBADID;
    if (g2cid2 < 0 || g2cid2 > G2C_MAX_FILES || g2c_file[g2cid2].g2cid != g2cid2)
        return G2C_EBADID;

    LOG((2, "g2c_metadata_cmp g2cid1 %d g2cid2 %d", g2cid1, g2cid2));

    /* /\* Print a summary for each message in the file. *\/ */
    /* for (msg = g2c_file[g2cid].msg; msg; msg = msg->next) */
    /* { */
    /*     int fld; */

    /*     fprintf(f, "\n"); */
    /*     fprintf(f, " GRIB MESSAGE  %ld  starts at %ld\n", msg->msg_num + 1, msg->bytes_to_msg + 1); */
    /*     fprintf(f, "\n"); */
    /*     fprintf(f, "  SECTION 0:  %d 2 %ld\n", msg->discipline, msg->bytes_in_msg); */
    /*     fprintf(f, "  SECTION 1:  %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg->center, msg->subcenter, */
    /*             msg->master_version, msg->local_version, msg->sig_ref_time, msg->year, msg->month, msg->day, */
    /*             msg->hour, msg->minute, msg->second, msg->status, msg->type); */
    /*     fprintf(f, "  Contains  %d  Local Sections  and  %d  data fields.\n", msg->num_local, msg->num_fields); */
    /*     LOG((5, "  SECTION 1:  %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg->center, msg->subcenter, */
    /*          msg->master_version, msg->local_version, msg->sig_ref_time, msg->year, msg->month, msg->day, */
    /*          msg->hour, msg->minute, msg->second, msg->status, msg->type)); */

    /*     /\* For each field, print info. *\/ */
    /*     for (fld = 0; fld < msg->num_fields; fld++) */
    /*     { */
    /*         G2C_SECTION_INFO_T *sec, *sec2, *sec3, *sec5, *sec6; */
    /*         G2C_SECTION3_INFO_T *sec3_info; */
    /*         G2C_SECTION4_INFO_T *sec4_info; */
    /*         G2C_SECTION5_INFO_T *sec5_info; */
    /*         G2C_SECTION6_INFO_T *sec6_info; */
    /*         char abbrev[G2C_MAX_NOAA_ABBREV_LEN + 1]; */
    /*         char level_desc[G2C_MAX_TYPE_OF_FIXED_SURFACE_LEN + 1]; */
    /*         char date_time[100 + 1]; */
    /*         float *data; */
    /*         float total, max, min; */
    /*         int t; */

    /*         fprintf(f, "\n"); */
    /*         fprintf(f, "  FIELD  %d\n", fld + 1); */
    /*         fprintf(f, "  SECTION 0:  %d 2\n", msg->discipline); */
    /*         fprintf(f, "  SECTION 1:  %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg->center, msg->subcenter, */
    /*                 msg->master_version, msg->local_version, msg->sig_ref_time, msg->year, msg->month, msg->day, */
    /*                 msg->hour, msg->minute, msg->second, msg->status, msg->type); */

    /*         /\* Find this field (a.k.a. product, a.k.a. section 4). *\/ */
    /*         for (sec = msg->sec; sec; sec = sec->next) */
    /*             if (sec->sec_num == 4 && ((G2C_SECTION4_INFO_T *)(sec->sec_info))->field_num == fld) */
    /*                 break; */
    /*         if (!sec) */
    /*             return G2C_ENOSECTION; */

    /*         /\* Is there a local section? *\/ */
    /*         for (sec2 = sec; sec2; sec2 = sec2->prev) */
    /*             if (sec2->sec_num == 2) */
    /*                 break; */
    /*         if (sec2) */
    /*             fprintf(f, "  SECTION 2: %d bytes\n", sec2->sec_len - 5); /\* Subtract 4 byte seclen and 1 byte secnum. *\/ */

    /*         /\* Find the sec3 that applies to this field. *\/ */
    /*         for (sec3 = sec; sec3; sec3 = sec3->prev) */
    /*             if (sec3->sec_num == 3) */
    /*                 break; */
    /*         if (!sec3) */
    /*             return G2C_ENOSECTION; */

    /*         /\* Print the section 3 (grid) info. *\/ */
    /*         sec3_info = (G2C_SECTION3_INFO_T *)sec3->sec_info; */
    /*         fprintf(f, "  SECTION 3:  %d %d %d %d %d\n", sec3_info->source_grid_def, sec3_info->num_data_points, sec3_info->num_opt, */
    /*                 sec3_info->interp_list, sec3_info->grid_def); */
    /*         fprintf(f, "  GRID TEMPLATE 3. %d : ", sec3_info->grid_def); */
    /*         /\* Cast to int to match behavior of  degrib2.F90. *\/ */
    /*         for (t = 0; t < sec3->template_len; t++) */
    /*             fprintf(f, " %d", (int)sec3->template[t]); */
    /*         fprintf(f, "\n"); */
    /*         if (!sec3_info->optional) */
    /*             fprintf(f, "  NO Optional List Defining Number of Data Points.\n"); */

    /*         /\* Print the section 4 (product) info. *\/ */
    /*         sec4_info = (G2C_SECTION4_INFO_T *)sec->sec_info; */
    /*         fprintf(f, "  PRODUCT TEMPLATE 4. %d: ", sec4_info->prod_def); */

    /*         /\* We can look up the parameter abbreviation with the */
    /*          * discipline and the first two elements of the product */
    /*          * template, which will be the category and product */
    /*          * number. *\/ */
    /*         if ((ret = g2c_param_abbrev(msg->discipline, sec->template[0], sec->template[1], abbrev))) */
    /*             return ret; */
    /*         fprintf(f, "( PARAMETER = %-8s %d %lld %lld ) ", abbrev, sec->msg->discipline, sec->template[0], */
    /*                 sec->template[1]); */
    /*         /\* Cast to int to match behavior of  degrib2.F90. *\/ */
    /*         for (t = 0; t < sec->template_len; t++) */
    /*             fprintf(f, " %d", (int)sec->template[t]); */
    /*         fprintf(f, "\n"); */

    /*         /\* Using the product template number, and the template */
    /*          * values, we can figure out a description for the */
    /*          * horizontal level description. *\/ */
    /*         if ((ret = g2c_get_level_desc(sec4_info->prod_def, sec->template, level_desc))) */
    /*             return ret; */

    /*         /\* The Fortran code for level descriptions puts a space in */
    /*          * front of level descriptions that don't start with a */
    /*          * number. It's annoying, but do it here to match the */
    /*          * behavior of Fortran degrib2. *\/ */
    /*         /\* if (!isdigit(level_desc[0])) *\/ */
    /*         /\* { *\/ */
    /*         /\*     char tmp_level_desc[G2C_MAX_TYPE_OF_FIXED_SURFACE_LEN + 2]; *\/ */
    /*         /\*     sprintf(tmp_level_desc, " %s", level_desc); *\/ */
    /*         /\*     strcpy(level_desc, tmp_level_desc); *\/ */
    /*         /\* } *\/ */

    /*         /\* Put the date/time in a formatted string. *\/ */
    /*         if ((ret = g2c_get_datetime(sec4_info->prod_def, sec->template, msg->year, msg->month, msg->day, */
    /*                                     msg->hour, msg->minute, msg->second, date_time))) */
    /*             return ret; */
    /*         fprintf(f, "  FIELD: %-8s%s %s\n", abbrev, level_desc, date_time); */
    /*         if (!sec4_info->num_coord) */
    /*             fprintf(f, "  NO Optional Vertical Coordinate List.\n"); */

    /*         /\* Find the sec5 that applies to this field. *\/ */
    /*         for (sec5 = sec; sec5; sec5 = sec5->next) */
    /*             if (sec5->sec_num == 5) */
    /*                 break; */
    /*         if (!sec5) */
    /*             return G2C_ENOSECTION; */

    /*         /\* Find the sec6 that applies to this field, if any. *\/ */
    /*         for (sec6 = sec; sec6; sec6 = sec6->next) */
    /*             if (sec6->sec_num == 6) */
    /*                 break; */

    /*         /\* Section 5 and 6 info. *\/ */
    /*         sec5_info = (G2C_SECTION5_INFO_T *)sec5->sec_info; */
    /*         sec6_info = (G2C_SECTION6_INFO_T *)sec6->sec_info; */
    /*         if (sec6_info->indicator != 255) */
    /*             fprintf(f, "  Num. of Data Points =  %d    with BIT-MAP  0\n", sec5_info->num_data_points); */
    /*         else */
    /*             fprintf(f, "  Num. of Data Points =  %d     NO BIT-MAP \n", sec5_info->num_data_points); */
    /*         fprintf(f, "  DRS TEMPLATE 5. %d : ", sec5_info->data_def); */
    /*         /\* Cast to int to match behavior of  degrib2.F90. *\/ */
    /*         for (t = 0; t < sec5->template_len; t++) */
    /*             fprintf(f, " %d", (int)sec5->template[t]); */
    /*         fprintf(f, "\n"); */
    /*         fprintf(f, "  Data Values:\n"); */
    /*         fprintf(f, "  Num. of Data Points =  %d   Num. of Data Undefined = 0\n", sec5_info->num_data_points); */

    /*         /\* Now read the data and find the min, max, and average values. *\/ */

    /*         /\* Allocate storage for the data. *\/ */
    /*         if (!(data = malloc(sec5_info->num_data_points * sizeof(float)))) */
    /*             return G2C_ERROR; */

    /*         /\* Get the data from message 0, product 0. *\/ */
    /*         if ((ret = g2c_get_prod(g2cid, msg->msg_num, fld, NULL, data))) */
    /*             return ret; */

    /*         /\* Find min/max/avg. *\/ */
    /*         max = data[0]; */
    /*         min = data[0]; */
    /*         total = data[0]; */
    /*         for (i = 1; i < sec5_info->num_data_points; i++) */
    /*         { */
    /*             total += data[i]; */
    /*             if (data[i] > max) */
    /*                 max = data[i]; */
    /*             if (data[i] < min) */
    /*                 min = data[i]; */
    /*         } */
    /*         fprintf(f, "( PARM= %s ) :  MIN=%25.8f AVE=%25.8f MAX=%25.8f\n", */
    /*                 abbrev, min, total/sec5_info->num_data_points, max); */

    /*         /\* Free the data. *\/ */
    /*         free(data); */

    /*         total_fields++; */
    /*     } */
    /* } */

    /* fprintf(f, "  \n  Total Number of Fields Found =  %d\n", total_fields); */

    return G2C_NOERROR;
}

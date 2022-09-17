/** 
 * @file
 * @brief Write summary output to a file, as is done by utility
 * grb2index.
 *
 * @author Ed Hartnett @date Sep 17, 2022
 */
#include "grib2_int.h"
#include <stdarg.h>

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/** Pointer to the list of code tables. */
extern G2C_CODE_TABLE_T *g2c_table;

/**
 * Write a summary file like the degrib2 utility.
 *
 * @param g2cid Indentifier for the file, returned by g2c_open() or
 * g2c_create().
 * @param fileout Path of output file. Any existing file of this name
 * will be overwritten.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EINVAL Invalid parameters.
 * - ::G2C_EFILE File I/O error.
 *
 * @author Ed Hartnett @date Sep 17, 2022
 */
int
g2c_write_grib2_index(int g2cid, const char *fileout)
{
    FILE *f;
    G2C_MESSAGE_INFO_T *msg;

    /* Check inputs. */
    if (g2cid > G2C_MAX_FILES)
	return G2C_EBADID;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;
    if (!fileout)
        return G2C_EINVAL;
    
    /* Open output file. */
    if (!(f = fopen(fileout, "w")))
        return G2C_EFILE;

    /* Print a summary for each message in the file. */
    for (msg = g2c_file[g2cid].msg; msg; msg = msg->next)
    {
        int fld;
        
        fprintf(f, "\n");
        fprintf(f, " GRIB MESSAGE %ld starts at %ld\n", msg->msg_num + 1, msg->bytes_to_msg + 1);
        fprintf(f, "\n");
        fprintf(f, "  SECTION 0:  %d 2 %ld\n", msg->discipline, msg->bytes_in_msg);
        fprintf(f, "  SECTION 1:  %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg->center, msg->subcenter,
                msg->master_version, msg->local_version, msg->sig_ref_time, msg->year, msg->month, msg->day,
                msg->hour, msg->minute, msg->second, msg->status, msg->type);
        fprintf(f, "  Contains %d Local Sectons  and %d data fields.\n", msg->num_local, msg->num_fields);

        /* For each field, print info. */
        for (fld = 0; fld < msg->num_fields; fld++)
        {
            G2C_SECTION_INFO_T *sec, *sec3;
            G2C_SECTION3_INFO_T *sec3_info;
            G2C_SECTION4_INFO_T *sec4_info;
            int t;
            
            fprintf(f, "\n");
            fprintf(f, "  FIELD  %d\n", fld + 1);
            fprintf(f, "  SECTION 0:  %d 2\n", msg->discipline);
            fprintf(f, "  SECTION 1:  %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg->center, msg->subcenter,
                msg->master_version, msg->local_version, msg->sig_ref_time, msg->year, msg->month, msg->day,
                msg->hour, msg->minute, msg->second, msg->status, msg->type);

            /* Find this field (a.k.a. product, a.k.a. section 4). */
            for (sec = msg->sec; sec; sec = sec->next)
                if (sec->sec_num == 4 && ((G2C_SECTION4_INFO_T *)(sec->sec_info))->field_num == fld)
                    break;
            if (!sec)
                return G2C_ENOSECTION;

            /* Find the sec3 that applies to this field. */
            for (sec3 = sec; sec3; sec3 = sec3->prev)
                if (sec3->sec_num == 3)
                    break;
            if (!sec3)
                return G2C_ENOSECTION;

            /* Print the section 3 (grid) info. */
            sec3_info = (G2C_SECTION3_INFO_T *)sec3->sec_info;
            fprintf(f, "  SECTION 3:  %d %d %d %d %d\n", sec3_info->source_grid_def, sec3_info->num_data_points, sec3_info->num_opt,
                    sec3_info->interp_list, sec3_info->grid_def);
            fprintf(f, "  GRID TEMPLATE 3. %d :", sec3_info->grid_def);
            for (t = 0; t < sec3->template_len; t++)
                fprintf(f, " %d", sec3->template[t]);
            fprintf(f, "\n");
            if (!sec3_info->optional)
                fprintf(f, "  NO Optional List Defining Number of Data Points.\n");

            /* Print the section 4 (product) info. */
            sec4_info = (G2C_SECTION4_INFO_T *)sec->sec_info;
            fprintf(f, "  PRODUCT TEMPLATE 4. %d :", sec4_info->prod_def);
            for (t = 0; t < sec->template_len; t++)
                fprintf(f, " %d", sec->template[t]);
            fprintf(f, "\n");
        }
    }

    /* Close output file. */
    if (fclose(f))
        return G2C_EFILE;
    
    return G2C_NOERROR;
}

/** 
 * @file
 * @brief Product functions for the g2c library.
 * @author Ed Hartnett @date Oct 1, 2022
 */

#include "grib2_int.h"

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/**
 * Read the data for a product.
 *
 * @param g2cid File ID.
 * @param msg_num Message number in file (first message in file is message 0).
 * @param prod_num Product number in message (first product in message is product 0).
 * @param num_data_points Pointer that gets the number of data points
 * in the product. Ignored if NULL.
 * @param data Pointer that gets the data. Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date Sep 28, 2022
 */
int
g2c_get_prod(int g2cid, int msg_num, int prod_num, int *num_data_points, float *data)
{
    G2C_MESSAGE_INFO_T *msg;
    G2C_SECTION_INFO_T *sec4, *sec5, *sec7;
    /* G2C_SECTION4_INFO_T *sec4_info; */
    G2C_SECTION5_INFO_T *sec5_info;
    char *buf;
    size_t bytes_read;
        
    /* Check inputs. */
    if (g2cid < 0 || g2cid > G2C_MAX_FILES)
	return G2C_EBADID;
    if (msg_num < 0 || prod_num < 0)
	return G2C_EINVAL;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    /* Find the message. */
    for (msg = g2c_file[g2cid].msg; msg; msg = msg->next)
	if (msg->msg_num == msg_num)
	    break;
    if (!msg)
	return G2C_ENOMSG;

    /* Find the product. After this, sec will point to the
     * appropropriate section 4 G2C_SECTION_INFO_T. */
    for (sec4 = msg->sec; sec4; sec4 = sec4->next)
	if (sec4->sec_num == 4 && ((G2C_SECTION4_INFO_T *)sec4->sec_info)->field_num == prod_num)
	    break;
    if (!sec4)
	return G2C_ENOPRODUCT;
    /* sec4_info = (G2C_SECTION4_INFO_T *)sec->sec_info; */

    /* Find the section 5, data representation section, to learn how
     * this product is compressed. */
    for (sec5 = sec4; sec5; sec5 = sec5->next)
        if (sec5->sec_num == 5)
            break;
    if (!sec5)
	return G2C_ENOSECTION;
    sec5_info = (G2C_SECTION5_INFO_T *)sec5->sec_info;

    /* Find the section 7, data section. */
    for (sec7 = sec5; sec7; sec7 = sec7->next)
        if (sec7->sec_num == 7)
            break;
    if (!sec7)
	return G2C_ENOSECTION;
    
    /* Give the caller number of data points, if desired. */
    if (num_data_points)
        *num_data_points = sec5_info->num_data_points;

    /* If user doesn't want data, we need go no further. */
    if (!data)
        return G2C_NOERROR;

    /* Allocate a char buffer to hold the packed data. */
    if (!(buf = malloc(sizeof(char) * sec7->sec_len - 5)))
        return G2C_ENOMEM;
    
    /* Jump to this section in the file. */
    if (fseek(g2c_file[g2cid].f, sec7->bytes_to_sec + sec7->msg->bytes_to_msg + 5, SEEK_SET))
	return G2C_ERROR;

    /* Read the product into a char buffer. Skip the first 5 bytes. */
    if ((bytes_read = fread(buf, 1, sec7->sec_len - 5, g2c_file[g2cid].f)) != sec7->sec_len - 5)
	return G2C_EFILE;

    /* Unpack the char buffer into a float array, which must be allocated by the caller. */
    

    /* Free the char buffer. */
    free(buf);

    return G2C_NOERROR;
}

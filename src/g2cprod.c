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
    G2C_SECTION_INFO_T *sec, *s;
    /* G2C_SECTION4_INFO_T *sec4_info; */
    G2C_SECTION5_INFO_T *sec5_info;
    
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
    for (sec = msg->sec; sec; sec = sec->next)
	if (sec->sec_num == 4 && ((G2C_SECTION4_INFO_T *)msg->sec->sec_info)->field_num == prod_num)
	    break;
    if (!sec)
	return G2C_ENOPRODUCT;
    /* sec4_info = (G2C_SECTION4_INFO_T *)sec->sec_info; */

    /* Find the section 5, data representation section, to learn how
     * this product is compressed. */
    for (s = sec; s; s = s->next)
        if (s->sec_num == 5)
            break;
    if (!s)
	return G2C_ENOSECTION;
    sec5_info = (G2C_SECTION5_INFO_T *)s->sec_info;

    /* Give the caller number of data points, if desired. */
    if (num_data_points)
        *num_data_points = sec5_info->num_data_points;

    /* If user doesn't want data, we need go no further. */
    if (!data)
        return G2C_NOERROR;

    /* Read the product. */

    return G2C_NOERROR;
}

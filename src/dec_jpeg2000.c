/** @file
 * @brief Decodes JPEG2000 code stream.
 * @author Stephen Gilbert @date 2002-12-02
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2002-12-02 | Gilbert | Initial
 * 2022-04-15 | Hartnett | Converted to use jas_ instead of jpc_ functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grib2_int.h"
#include "jasper/jasper.h"

/**
 * This Function decodes a JPEG2000 code stream specified in the
 * JPEG2000 Part-1 standard (i.e., ISO/IEC 15444-1) using [JasPer
 * Software](https://github.com/jasper-software/jasper).
 *
 * @param injpc Pointer to buffer that holds the input JPEG2000 code
 * stream.
 * @param bufsize Length (in bytes) of the buffer that holds the input
 * JPEG2000 code stream.
 * @param outfld Pointer to either int or g2int array, already
 * allocated, that gets the unpacked data.
 * @param out_is_g2int Non-zero if the output array is of type g2int
 * (i.e. 64-bit ints), zero if output is an int array (32-bits).
 *
 * @return
 * - 0 Successful decode
 * - ::G2_JASPER_DECODE Error decode jpeg2000 code stream.
 * - ::G2_JASPER_DECODE_COLOR decoded image had multiple color
 *     components. Only grayscale is expected.
 * - ::G2_JASPER_INIT Error inializing Jasper library.
 *
 * @author Stephen Gilbert @date 2002-12-02
 * @author Ed Hartnett
 */
static int
int_dec_jpeg2000(char *injpc, g2int bufsize, void *outfld, int out_is_g2int)
{
    g2int i, j, k;
    jas_image_t *image = NULL;
    jas_stream_t *jpcstream;
    jas_image_cmpt_t *pcmpt;
    char *opts = NULL;
    jas_matrix_t *data;
    int fmt;

    LOG((3, "int_dec_jpeg2000 bufsize %ld out_is_g2int %d", bufsize, out_is_g2int));

    /* Initialize Jasper. */
#ifdef JASPER3
    jas_conf_clear();
    /* static jas_std_allocator_t allocator; */
    /* jas_std_allocator_init(&allocator); */
    /* jas_conf_set_allocator(JAS_CAST(jas_std_allocator_t *, &allocator)); */
    jas_conf_set_max_mem_usage(10000000);
    jas_conf_set_multithread(true);
    if (jas_init_library())
        return G2_JASPER_INIT;
    if (jas_init_thread())
        return G2_JASPER_INIT;
#else
    if (jas_init())
        return G2_JASPER_INIT;
#endif /* JASPER3 */

    /* Create jas_stream_t containing input JPEG200 codestream in
     * memory. */
    jpcstream = jas_stream_memopen(injpc, bufsize);

    /* Get jasper ID of JPEG encoder. */
    fmt = jas_image_strtofmt(G2C_JASPER_JPEG_FORMAT_NAME);

    /* Decode JPEG200 codestream into jas_image_t structure. */
    if (!(image = jas_image_decode(jpcstream, fmt, opts)))
        return G2_JASPER_DECODE;

    pcmpt = image->cmpts_[0];
    /*
      printf(" SAGOUT DECODE:\n");
      printf(" tlx %d \n", image->tlx_);
      printf(" tly %d \n", image->tly_);
      printf(" brx %d \n", image->brx_);
      printf(" bry %d \n", image->bry_);
      printf(" numcmpts %d \n", image->numcmpts_);
      printf(" maxcmpts %d \n", image->maxcmpts_);
      printf(" colorspace %d \n", image->clrspc_);
      printf(" inmem %d \n", image->inmem_);
      printf(" COMPONENT:\n");
      printf(" tlx %d \n", pcmpt->tlx_);
      printf(" tly %d \n", pcmpt->tly_);
      printf(" hstep %d \n", pcmpt->hstep_);
      printf(" vstep %d \n", pcmpt->vstep_);
      printf(" width %d \n", pcmpt->width_);
      printf(" height %d \n", pcmpt->height_);
      printf(" prec %d \n", pcmpt->prec_);
      printf(" sgnd %d \n", pcmpt->sgnd_);
      printf(" cps %d \n", pcmpt->cps_);
      printf(" type %d \n", pcmpt->type_);
    */

    /* Expecting jpeg2000 image to be grayscale only. No color components. */
    if (image->numcmpts_ != 1)
        return G2_JASPER_DECODE_COLOR;

    /* Create a data matrix of grayscale image values decoded from the
     * jpeg2000 codestream. */
    data = jas_matrix_create(jas_image_height(image), jas_image_width(image));
    jas_image_readcmpt(image, 0, 0, 0, jas_image_width(image),
                       jas_image_height(image), data);

    /* Copy data matrix to output integer array. */
    k = 0;
    if (out_is_g2int)
    {
        for (i = 0; i < pcmpt->height_; i++)
            for (j = 0; j < pcmpt->width_; j++)
                ((g2int *)outfld)[k++] = data->rows_[i][j];
    }
    else
    {
        for (i = 0; i < pcmpt->height_; i++)
            for (j = 0; j < pcmpt->width_; j++)
                ((int *)outfld)[k++] = data->rows_[i][j];
    }

    /* Clean up JasPer work structures. */
    jas_matrix_destroy(data);
    jas_stream_close(jpcstream);
    jas_image_destroy(image);

    /* Finalize jasper. */
#ifdef JASPER3
    jas_cleanup_thread();
    jas_cleanup_library();
#else
    jas_cleanup();
#endif /* JASPER3 */

    return 0;
}

/**
 * This Function decodes a JPEG2000 code stream specified in the
 * JPEG2000 Part-1 standard (i.e., ISO/IEC 15444-1) using [JasPer
 * Software](https://github.com/jasper-software/jasper).
 *
 * @param injpc Pointer to buffer that holds the input JPEG2000 code
 * stream.
 * @param bufsize Length (in bytes) of the buffer that holds the input
 * JPEG2000 code stream.
 * @param outfld Pointer to int array, already allocated, that gets
 * the unpacked data.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2_JASPER_DECODE Error decode jpeg2000 code stream.
 * - ::G2_JASPER_DECODE_COLOR decoded image had multiple color
 *     components. Only grayscale is expected.
 * - ::G2_JASPER_INIT Error inializing Jasper library.
 *
 * @author Ed Hartnett @date 9/7/22
 */
int
g2c_dec_jpeg2000(char *injpc, size_t bufsize, int *outfld)
{
    return int_dec_jpeg2000(injpc, bufsize, outfld, 0);
}

/**
 * This Function decodes a JPEG2000 code stream specified in the
 * JPEG2000 Part-1 standard (i.e., ISO/IEC 15444-1) using [JasPer
 * Software](https://github.com/jasper-software/jasper).
 *
 * @param injpc Pointer to buffer that holds the input JPEG2000 code
 * stream.
 * @param bufsize Length (in bytes) of the buffer that holds the input
 * JPEG2000 code stream.
 * @param outfld Pointer to g2int array, already allocated, that gets
 * the unpacked data.
 *
 * @return
 * - 0 Successful decode
 * - ::G2_JASPER_DECODE Error decode jpeg2000 code stream.
 * - ::G2_JASPER_DECODE_COLOR decoded image had multiple color
 *     components. Only grayscale is expected.
 * - ::G2_JASPER_INIT Error inializing Jasper library.
 *
 * @author Stephen Gilbert, Ed Hartnett 
 */
int
dec_jpeg2000(char *injpc, g2int bufsize, g2int *outfld)
{
    return int_dec_jpeg2000(injpc, bufsize, outfld, 1);
}


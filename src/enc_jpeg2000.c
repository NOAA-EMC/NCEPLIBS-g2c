/** @file
 * @brief Encodes JPEG2000 code stream.
 * @author Stephen Gilbert @date 2002-12-02
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"
#include "jasper/jasper.h"

#define MAXOPTSSIZE 1024 /**< Maximum size of options. */

/**
 * This Function encodes a grayscale image into a JPEG2000 code stream
 * specified in the JPEG2000 Part-1 standard (i.e., ISO/IEC 15444-1)
 * using [JasPer Software](https://github.com/jasper-software/jasper).
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2002-12-02 | Gilbert | Initial
 * 2004-12-16 | Gilbert | Added retry argument allowing increased guard bits.
 * 2022-04-15 | Hartnett | Converted to use jas_ instead of jpc_ functions.
 *
 * @param cin Packed matrix of Grayscale image values to encode.
 * @param width width of image.
 * @param height height of image.
 * @param nbits depth (in bits) of image.  i.e number of bits used to
 * hold each data value.
 * @param ltype indicator of lossless or lossy compression.
 * - 1, for lossy compression
 * - != 1, for lossless compression
 * @param ratio target compression ratio. (ratio:1) Used only when
 * ltype == 1.
 * @param retry If 1 try increasing number of guard bits.
 * @param outjpc Output encoded JPEG2000 code stream.
 * @param jpclen Number of bytes allocated for the output JPEG2000
 * code stream in outjpc.
 *
 * @return
 * - > 0 = Length in bytes of encoded JPEG2000 code stream
 * - ::G2_JASPER_INIT Error initializing jasper library.
 * - ::G2_JASPER_ENCODE Error encode jpeg2000 code stream.
 *
 * @note Requires JasPer Software version 1.500.4 or 1.700.2 or later.
 *
 * @author Stephen Gilbert @date 2002-12-02
 * @author Ed Hartnett
 */
int
g2c_enc_jpeg2000(unsigned char *cin, int width, int height, int nbits,
                 int ltype, int ratio, int retry, char *outjpc,
                 size_t jpclen)
{
    g2int width8 = width, height8 = height, nbits8 = nbits, ltype8 = ltype;
    g2int ratio8 = ratio, retry8 = retry, jpclen8 = jpclen;
    
    return enc_jpeg2000(cin, width8, height8, nbits8, ltype8, ratio8, retry8,
                        outjpc, jpclen8);
}

/**
 * This Function encodes a grayscale image into a JPEG2000 code stream
 * specified in the JPEG2000 Part-1 standard (i.e., ISO/IEC 15444-1)
 * using [JasPer Software](https://github.com/jasper-software/jasper).
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2002-12-02 | Gilbert | Initial
 * 2004-12-16 | Gilbert | Added retry argument allowing increased guard bits.
 * 2022-04-15 | Hartnett | Converted to use jas_ instead of jpc_ functions.
 *
 * @param cin Packed matrix of Grayscale image values to encode.
 * @param width width of image.
 * @param height height of image.
 * @param nbits depth (in bits) of image.  i.e number of bits used to
 * hold each data value.
 * @param ltype indicator of lossless or lossy compression.
 * - 1, for lossy compression
 * - != 1, for lossless compression
 * @param ratio target compression ratio. (ratio:1) Used only when
 * ltype == 1.
 * @param retry If 1 try increasing number of guard bits.
 * @param outjpc Output encoded JPEG2000 code stream.
 * @param jpclen Number of bytes allocated for the output JPEG2000
 * code stream in outjpc.
 *
 * @return
 * - > 0 = Length in bytes of encoded JPEG2000 code stream
 * - ::G2_JASPER_INIT Error initializing jasper library.
 * - ::G2_JASPER_ENCODE Error encode jpeg2000 code stream.
 *
 * @note Requires JasPer Software version 1.500.4 or 1.700.2 or later.
 *
 * @author Stephen Gilbert @date 2002-12-02
 * @author Ed Hartnett
 */
int
enc_jpeg2000(unsigned char *cin, g2int width, g2int height, g2int nbits,
             g2int ltype, g2int ratio, g2int retry, char *outjpc,
             g2int jpclen)
{
    int ier, rwcnt;
    jas_image_t image;
    jas_stream_t *jpcstream, *istream;
    jas_image_cmpt_t cmpt, *pcmpt;
    char opts[MAXOPTSSIZE];
    int fmt;

    LOG((3, "enc_jpeg2000 width %ld height %ld nbits %ld ltype %ld ratio %ld retry %ld jpclen %d",
	 width, height, nbits, ltype, ratio, retry, jpclen));

    /* Set lossy compression options, if requested. */
    if (ltype != 1)
        opts[0] = (char)0;
    else
        snprintf(opts,MAXOPTSSIZE,"mode=real\nrate=%f",1.0/(float)ratio);

    if (retry == 1)  /* option to increase number of guard bits */
        strcat(opts,"\nnumgbits=4");

    /* Initialize the JasPer image structure describing the grayscale
     * image to encode into the JPEG2000 code stream. */
    image.tlx_ = 0;
    image.tly_ = 0;
    image.brx_ = (jas_image_coord_t)width;
    image.bry_ = (jas_image_coord_t)height;
    image.numcmpts_ = 1;
    image.maxcmpts_ = 1;
    image.clrspc_ = JAS_CLRSPC_SGRAY;         /* grayscale Image */
    image.cmprof_ = 0;

    cmpt.tlx_ = 0;
    cmpt.tly_ = 0;
    cmpt.hstep_ = 1;
    cmpt.vstep_ = 1;
    cmpt.width_ = (jas_image_coord_t)width;
    cmpt.height_ = (jas_image_coord_t)height;
    cmpt.type_ = JAS_IMAGE_CT_COLOR(JAS_CLRSPC_CHANIND_GRAY_Y);
    cmpt.prec_ = nbits;
    cmpt.sgnd_ = 0;
    cmpt.cps_ = (nbits + 7) / 8;

    pcmpt = &cmpt;
    image.cmpts_ = &pcmpt;

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

    /* Open a JasPer stream containing the input grayscale values. */
    istream = jas_stream_memopen((char *)cin, height * width * cmpt.cps_);
    cmpt.stream_ = istream;

    /* Open an output stream that will contain the encoded jpeg2000
     * code stream. */
    jpcstream = jas_stream_memopen(outjpc, (int)jpclen);

    /* Get jasper ID of JPEG encoder. */
    fmt = jas_image_strtofmt(G2C_JASPER_JPEG_FORMAT_NAME);

    /* Encode image. */
    if ((ier = jas_image_encode(&image, jpcstream, fmt, opts)))
        return G2_JASPER_ENCODE;

    /* Rememeber the length in bytes of the encoded JPEG code
     * stream. */
    rwcnt = jpcstream->rwcnt_;

    /* Clean up JasPer work structures. */
    ier = jas_stream_close(istream);
    ier = jas_stream_close(jpcstream);

    /* Finalize jasper. */
#ifdef JASPER3
    jas_cleanup_thread();
    jas_cleanup_library();
#else
    jas_cleanup();
#endif /* JASPER3 */

    /* Return size of jpeg2000 code stream. */
    return rwcnt;
}

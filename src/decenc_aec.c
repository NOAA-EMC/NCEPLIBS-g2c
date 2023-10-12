#include <stdio.h>
#include <stdint.h>
#include <libaec.h>
#include "grib2_int.h"

int enc_aec(unsigned char *data, int ctemplen, g2int nbits, g2int flags,
            g2int block_size, g2int rsi, unsigned char *aecbuf, g2int *aecbuflen)
{
    struct aec_stream strm;
    int iret;

    iret = 0;

    /* Define bits per sample */
    strm.bits_per_sample = nbits;
    printf("enc_aec: strm.bits_per_sample = %d\n",strm.bits_per_sample);

    /* Define a block size */
    printf("enc_aec: block_size = %d\n",block_size);
    strm.block_size = block_size;

    /* Define the reference sample interval */
    printf("enc_aec: rsi = %d\n",rsi);
    strm.rsi = rsi;

    /* Define the AEC compression flags. */
    strm.flags = flags;
    printf("enc_aec: strm.flags = %d\n",strm.flags);

    /* Pointer to input */
    strm.next_in = data;

    /* Length of input in bytes */
    strm.avail_in = ctemplen;
    printf("enc_aec: strm.avail_in = %d\n",strm.avail_in);

    /* Pointer to output buffer */
    strm.next_out = aecbuf;

    /* Length of output buffer in bytes */
    strm.avail_out = (size_t) aecbuflen;

    /* Encode into AEC. */
    iret = aec_buffer_encode(&strm);
    printf("enc_aec: return from aec_buffer_encode = %d\n", iret);
    if (iret == AEC_OK) iret = strm.total_out;

    return iret;
}

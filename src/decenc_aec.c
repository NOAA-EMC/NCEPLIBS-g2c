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
    LOG((3, "enc_aec: bits_per_sample = %d",strm.bits_per_sample));

    /* Define a block size */
    LOG((3, "enc_aec: block_size = %d",block_size));
    strm.block_size = block_size;

    /* Define the reference sample interval */
    LOG((3, "enc_aec: rsi = %d",rsi));
    strm.rsi = rsi;

    /* Define the AEC compression flags. */
    strm.flags = flags;
    LOG((3, "enc_aec: flags = %d",strm.flags));

    /* Pointer to input */
    strm.next_in = data;

    /* Length of input in bytes */
    strm.avail_in = ctemplen;
    LOG((3, "enc_aec: avail_in = %d",strm.avail_in));

    /* Pointer to output buffer */
    strm.next_out = aecbuf;

    /* Length of output buffer in bytes */
    strm.avail_out = (size_t) aecbuflen;

    /* Encode into AEC. */
    iret = aec_buffer_encode(&strm);
    LOG((3, "enc_aec: return from aec_buffer_encode = %d", iret));
    if (iret == AEC_OK) iret = strm.total_out;

    return iret;
}

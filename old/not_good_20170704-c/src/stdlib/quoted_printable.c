/*
 * ================================
 * eli960@163.com
 * http://www.mailhonor.com/
 * 2015-12-02
 * ================================
 */

#include "zc.h"

/* should check c1 and c2 are hex */
#define ___hex_val(ccc) { ccc = zhex_to_dec_list[ccc];}

#define ___get_next_ch(c0123)    while(1){ \
    if(src_pos >= src_size){ goto over; } \
    c0123 = src_c[src_pos++]; \
    break; \
}

int zqp_decode_2045(const void *src, int src_size, char *dest, int dest_size)
{
    unsigned char *src_c = (unsigned char *)src;
    int src_pos = 0;
    unsigned char c1, c2;
    unsigned char addch;
    int rlen = 0;

    while (1) {
        ___get_next_ch(addch);
        if (addch == '=') {
            ___get_next_ch(c1);
            if (c1 == '\r' || c1 == '\n') {
                ___get_next_ch(c2);
                if (c2 != '\r' && c2 != '\n') {
                    src_pos--;
                }
                continue;
            }
            ___get_next_ch(c2);
            ___hex_val(c1);
            ___hex_val(c2);
            addch = ((c1 << 4) | c2);
        }
        if ((dest_size > 0) && (rlen+1 > dest_size)) {
            break;
        }
        Z_DF_ADD_CHAR(dest_size, dest, rlen, addch);
    }
  over:

    return rlen;
}

int zqp_decode_2047(const void *src, int src_size, char *dest, int dest_size)
{
    unsigned char *src_c = (unsigned char *)src;
    int src_pos = 0;
    unsigned char c0, c1, c2;
    unsigned char addch;
    int rlen = 0;

    while (1) {
        ___get_next_ch(c0);
        if (c0 == '_') {
            addch = ' ';
        } else if (c0 != '=') {
            addch = c0;
        } else {
            ___get_next_ch(c1);
            ___get_next_ch(c2);
            ___hex_val(c1);
            ___hex_val(c2);
            addch = (c1 << 4 | c2);
        }
        if ((dest_size > 0) && (rlen+1 > dest_size)) {
            break;
        }
        Z_DF_ADD_CHAR(dest_size, dest, rlen, addch);
    }
  over:

    return rlen;
}

int zqp_decode_get_valid_len(const void *src, int src_size)
{
    unsigned char *src_c = (unsigned char *)src;
    int i;
    unsigned char ch;

    for (i = 0; i < src_size; i++) {
        ch = src_c[i];
        if ((ch < 33) || (ch > 126)) {
            return i;
        }
    }

    return src_size;
}

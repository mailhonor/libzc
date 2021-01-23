/*
 * ================================
 * eli960@qq.com
 * http://linuxmail.cn/
 * 2015-12-02
 * ================================
 */

#ifndef ___ZC_ZCC_MODE___
#include "zc.h"
#endif

static const char b64enc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

const unsigned char zvar_base64_decode_table[256] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 0-7 */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 8-15 */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 16-23 */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 24-31 */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 32-39 */
    0xff, 0xff, 0xff, 0x3e, 0xff, 0xff, 0xff, 0x3f, /* 40-47 */
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, /* 48-55 */
    0x3c, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 56-63 */
    0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, /* 64-71 */
    0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, /* 72-79 */
    0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, /* 80-87 */
    0x17, 0x18, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff, /* 88-95 */
    0xff, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, /* 96-103 */
    0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, /* 104-111 */
    0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, /* 112-119 */
    0x31, 0x32, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff, /* 120-127 */

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 128-255 */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

#ifndef ___ZC_ZCC_MODE___
void zbase64_encode(const void *src, int src_size, zbuf_t *str, int mime_flag)
#else
void base64_encode(const void *src, int src_size, std::string &str, bool mime_flag)
#endif
{
    unsigned char *src_c = (unsigned char *)src;
    char tmp[5]= {0,0,0,0,0};
    int src_pos;
    int mime_count = 0;
    
    if (src_size < 0) {
        src_size = strlen((const char *)src);
    }

    for (src_pos = 0; src_pos < src_size;) {
        tmp[0] = b64enc[src_c[src_pos] >> 2];
        switch (src_size - src_pos) {
        case 1:
            tmp[1] = b64enc[(src_c[src_pos] & 0x03) << 4];
            tmp[2] = '=';
            tmp[3] = '=';
            src_pos++;
            break;
        case 2:
            tmp[1] = b64enc[((src_c[src_pos] & 0x03) << 4) | (src_c[src_pos + 1] >> 4)];
            tmp[2] = b64enc[((src_c[src_pos + 1] & 0x0f) << 2)];
            tmp[3] = '=';
            src_pos += 2;
            break;
        default:
            tmp[1] = b64enc[((src_c[src_pos] & 0x03) << 4) | (src_c[src_pos + 1] >> 4)];
            tmp[2] = b64enc[((src_c[src_pos + 1] & 0x0f) << 2) | ((src_c[src_pos + 2] & 0xc0) >> 6)];
            tmp[3] = b64enc[src_c[src_pos + 2] & 0x3f];
            src_pos += 3;
            break;
        }

        zbuf_put_cpp(str, tmp[0]);
        zbuf_put_cpp(str, tmp[1]);
        zbuf_put_cpp(str, tmp[2]);
        zbuf_put_cpp(str, tmp[3]);

        if (mime_flag) {
            mime_count++;
            if (mime_count == 19) {
                mime_count = 0;
                zbuf_put_cpp(str, '\r');
                zbuf_put_cpp(str, '\n');
            }
        }
    }
    zbuf_terminate_cpp(str);
}

#ifndef ___ZC_ZCC_MODE___
void zbase64_decode(const void *src, int src_size, zbuf_t *str)
#else
void base64_decode(const void *src, int src_size, std::string &str)
#endif
{
    unsigned char *src_c = (unsigned char *)src;
    int src_pos = 0;
    unsigned char input[4], output[3];
    int ret = -1;
    unsigned char c0, c1, c2, c3;
#if 0
    int illegal = 0;
#endif

    if (src_size < 0) {
        src_size = strlen((const char *)src);
    }

#define ___get_next_ch(c0123, br)    while(1){ \
    if(src_pos >= src_size){ if(br) {c0123='='; break;}  goto over; } \
    c0123 = src_c[src_pos++]; \
    if(c0123==' ' || c0123 =='\r' || c0123 == '\n'){ continue; } \
    break; \
    }

retry:
    ret = -1;
    while (src_pos < src_size) {
        ret = -1;
        ___get_next_ch(c0, 0);
        ___get_next_ch(c1, 0);
        ___get_next_ch(c2, 1);
        ___get_next_ch(c3, 1);
        input[0] = zvar_base64_decode_table[c0];
        if (input[0] == 0xff) {
#if 0
            illegal = 1;
#endif
            break;
        }

        input[1] = zvar_base64_decode_table[c1];
        if (input[1] == 0xff) {
#if 0
            illegal = 1;
#endif
            break;
        }
        output[0] = (input[0] << 2) | (input[1] >> 4);

        input[2] = zvar_base64_decode_table[c2];
        if (input[2] == 0xff) {
            if (c2 != '=' || c3 != '=') {
#if 0
                illegal = 1;
#endif
                break;
            }
            zbuf_put_cpp(str, output[0]);
            ret = 1;
            break;
        }

        output[1] = (input[1] << 4) | (input[2] >> 2);
        input[3] = zvar_base64_decode_table[c3];
        if (input[3] == 0xff) {
            if (c3 != '=') {
#if 0
                illegal = 1;
#endif
                break;
            }
            zbuf_put_cpp(str, output[0]);
            zbuf_put_cpp(str, output[1]);
            ret = 1;
            break;
        }

        output[2] = ((input[2] << 6) & 0xc0) | input[3];
        zbuf_put_cpp(str, output[0]);
        zbuf_put_cpp(str, output[1]);
        zbuf_put_cpp(str, output[2]);
    }

    if (ret == 1) {
        goto retry;
    }
over:
    zbuf_terminate_cpp(str);
#undef ___get_next_ch
}

#ifndef ___ZC_ZCC_MODE___
int zbase64_decode_get_valid_len(const void *src, int src_size)
{
    unsigned char *src_c = (unsigned char *)src, ch;
    int i;

    if (src_size < 0) {
        src_size = strlen((const char *)src);
    }

    for (i = 0; i < src_size; i++) {
        ch = src_c[i];
        if ((ch == '\r') || (ch == '\n') || (ch == '=')) {
            continue;
        }
        if (zvar_base64_decode_table[ch] == 0xff) {
            return i;
        }
    }

    return src_size;
}

int zbase64_encode_get_min_len(int in_len, int mime_flag)
{
    int ret;

    ret = in_len * 4 / 3 + 4;
    if (mime_flag) {
        ret += ((in_len / (76 * 3 / 4)) + 1) * 2 + 2;
    }
    ret += 1;

    return ret;
}
#endif

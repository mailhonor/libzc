/*
 * ================================
 * eli960@qq.com
 * http://www.mailhonor.com/
 * 2015-12-09
 * ================================
 */

#include "zc.h"
#include "mime.h"

void zmime_iconv(const char *from_charset, const char *data, int size, zbuf_t *result)
{
    if (size < 1) {
        return;
    }

    ZSTACK_BUF(f_charset_buf, zvar_charset_name_max_size);
    const char *f_charset;
    int detacted = 0;

    zbuf_reset(result);
    f_charset = from_charset;
    if (ZEMPTY(f_charset)) {
        detacted = 1;
        zbuf_reset(f_charset_buf);
        if (zcharset_detect_cjk(data, size, f_charset_buf)) {
            f_charset = zbuf_data(f_charset_buf);
        } else  {
            f_charset = "GB18030";
        }
    } else {
        f_charset = zcharset_correct_charset(f_charset);
    }

    if (zcharset_iconv(f_charset, data, size,
                "UTF-8", result, 0,
                -1, 0) > 0) {
        zmail_clear_null_inner(zbuf_data(result), zbuf_len(result));
        return;
    }

    if(detacted) {
        zbuf_memcpy(result, data, size);
        zmail_clear_null_inner(zbuf_data(result), zbuf_len(result));
        return;
    }

    zbuf_reset(f_charset_buf);
    if (zcharset_detect_cjk(data, size, f_charset_buf)) {
        f_charset = zbuf_data(f_charset_buf);
    } else  {
        f_charset = "GB18030";
    }
    zbuf_reset(result);
    if (zcharset_iconv(f_charset, data, size,
                "UTF-8", result, 0,
                -1, 0) > 0) {
        zmail_clear_null_inner(zbuf_data(result), zbuf_len(result));
        return;
    }

    zbuf_memcpy(result, data, size);
    zmail_clear_null_inner(zbuf_data(result), zbuf_len(result));
    return;
}

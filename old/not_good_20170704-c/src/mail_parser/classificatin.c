/*
 * ================================
 * eli960@163.com
 * http://www.mailhonor.com/
 * 2015-12-16
 * ================================
 */

#include "zc.h"

#define _ZPMT_MULTIPART        1
#define _ZPMT_ATTACHMENT       2
#define _ZPMT_PLAIN            3
#define _ZPMT_HTML             4
static int ___mime_identify_type(zmime_t * mime)
{
    char *type;

    type = mime->type;
    if (ZEMPTY(type)) {
        return _ZPMT_MULTIPART;
    }
    if (ZSTR_N_EQ(type, "multipart/", 10)) {
        return _ZPMT_MULTIPART;
    }
    if (ZSTR_N_EQ(type, "application/", 12)) {
        if (strstr(type + 12, "tnef")) {
            mime->is_tnef = 1;
        }
        return _ZPMT_ATTACHMENT;
    }
    if ((!ZEMPTY(mime->disposition)) && (ZSTR_N_EQ(mime->disposition, "attachment", 10))) {
        return _ZPMT_ATTACHMENT;
    }
    if (ZSTR_N_EQ(type, "image/", 6)) {
        return _ZPMT_ATTACHMENT;
    }
    if (ZSTR_N_EQ(type, "audio/", 6)) {
        return _ZPMT_ATTACHMENT;
    }
    if (ZSTR_N_EQ(type, "video/", 6)) {
        return _ZPMT_ATTACHMENT;
    }
    if (ZSTR_N_EQ(type, "text/", 5)) {
        if (!strcmp(type + 5, "html")) {
            if (strstr(mime->disposition, "attachment")) {
                return _ZPMT_ATTACHMENT;
            }
            return _ZPMT_HTML;
        }
        if (!strcmp(type + 5, "plain")) {
            if (strstr(mime->disposition, "attachment")) {
                return _ZPMT_ATTACHMENT;
            }
            return _ZPMT_PLAIN;
        }
        return _ZPMT_ATTACHMENT;
    }
    if (ZSTR_N_EQ(type, "message/", 8)) {
        if (strstr(type + 8, "delivery")) {
            return _ZPMT_PLAIN;
        }
        if (strstr(type + 8, "notification")) {
            return _ZPMT_PLAIN;
        }
        return _ZPMT_ATTACHMENT;
    }

    return _ZPMT_ATTACHMENT;
}

/* ################################################################## */
typedef struct {
    zmime_t *alternative;
    zmime_t *self;
} ___view_mime_t;

static int ___mime_identify_view_part(zmime_t * mime, ___view_mime_t * view_list, int *view_len)
{
    char *type;
    int i, mime_type;
    zmime_t *parent;

    type = mime->type;
    mime_type = mime->mime_type;

    if ((mime_type != _ZPMT_PLAIN) && (mime_type != _ZPMT_HTML)) {
        return 0;
    }
    if (ZEMPTY(type)) {
        return 0;
    }

    for (parent = mime->parent; parent; parent = parent->parent) {
        if (ZSTR_EQ(parent->type, "multipart/alternative")) {
            break;
        }
    }
    if (!parent) {
        view_list[*view_len].alternative = 0;
        view_list[*view_len].self = mime;
        *view_len = *view_len + 1;
        return 0;
    }

    for (i = 0; i < *view_len; i++) {
        if (view_list[i].alternative == parent) {
            break;
        }
    }

    if (i == *view_len) {
        view_list[*view_len].alternative = parent;
        view_list[*view_len].self = mime;
        *view_len = *view_len + 1;
        return 0;
    }

    view_list[i].alternative = parent;
    if (ZSTR_EQ(mime->type, "text/html")) {
        view_list[i].self = mime;
    }

    return 0;
}

/* ################################################################## */
void zmail_mime_classify(zmail_t * parser)
{
    zmime_t *m;
    int i;

    if (parser->classify_flag) {
        return;
    }
    parser->classify_flag = 1;

    {
        /* classify */
        int type;
        zmime_t *text_mime[10240];
        int text_len = 0;
        zmime_t *att_mime[10240];
        int att_len = 0;

        ZVECTOR_WALK_BEGIN(parser->all_mimes, m) {
            type = ___mime_identify_type(m);
            m->mime_type = type;
            if ((type == _ZPMT_PLAIN) || (type == _ZPMT_HTML)) {
                if (text_len < 10000) {
                    text_mime[text_len++] = m;
                }
            } else if (type == _ZPMT_ATTACHMENT) {
                if (att_len < 10000) {
                    att_mime[att_len++] = m;
                }
            }
        } ZVECTOR_WALK_END;

        parser->text_mimes = zvector_create_MPOOL(parser->mpool, text_len);
        for (i = 0; i < text_len; i++) {
            zvector_add(parser->text_mimes, text_mime[i]);
        }

        parser->attachment_mimes = zvector_create_MPOOL(parser->mpool, att_len);
        for (i = 0; i < att_len; i++) {
            zvector_add(parser->attachment_mimes, att_mime[i]);
        }
    }

    {
        /* similar to the above text-mime, 
         * in addition to the case of alternative, html is preferred */
        ___view_mime_t view_mime[10240];
        int view_len = 0;
        ZVECTOR_WALK_BEGIN(parser->all_mimes, m) {
            if (view_len < 10000) {
                ___mime_identify_view_part(m, view_mime, &view_len);
            }
        } ZVECTOR_WALK_END;

        parser->show_mimes = zvector_create_MPOOL(parser->mpool, view_len);
        for (i = 0; i < view_len; i++) {
            zvector_add(parser->show_mimes, view_mime[i].self);
        }
    }
}

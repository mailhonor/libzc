/*
 * ================================
 * eli960@qq.com
 * https://blog.csdn.net/eli960
 * 2015-12-11
 * ================================
 */

#include "zc.h"

static int enable_att = 0;

static char *name_char_validate(char *abc)
{
    char key[] = "?<>\"'|/\\*", *p = abc, ch;

    while((ch=*p)) {
        if (strchr(key, ch)) {
            *p = ' ';
        }
        p++;
    }
    return abc;

}

static int idx = 0;
static int save_att(zmail_t * parser, zmime_t * mime)
{
    const char *sname;
    char tmpname[256];

    idx++;
    sname = zmime_get_show_name(mime);
    if (zempty(sname)) {
        sprintf(tmpname, "atts/%d_unknown.dat", idx);
    } else {
        snprintf(tmpname, 255, "atts/%d_%s", idx, sname);
        name_char_validate(tmpname+5);
    }
    zbuf_t *dcon = zbuf_create(-1);
    zmime_get_decoded_content(mime, dcon);

    printf("save attachment %s\n", tmpname);
    if (!zfile_put_contents(tmpname, zbuf_data(dcon), zbuf_len(dcon))) {
        printf("ERR decode_mime_body: save %m\n");
    }

    zbuf_free(dcon);
    return 0;
}

static int save_all_attachments(zmail_t *parser)
{
    const zvector_t *allm = zmail_get_attachment_mimes(parser);
    ZVECTOR_WALK_BEGIN(allm, zmime_t *, m) {
        save_att(parser, m);
    } ZVECTOR_WALK_END;
    return 0;
}

static void do_parse(char *eml_fn)
{
    zmail_t *parser = zmail_create_parser_from_pathname(eml_fn, "");
    if (parser == 0) {
        printf("ERR open %s (%m)\n", eml_fn);
        exit(1);
    }
    zmail_debug_show(parser);

    if (enable_att) {
        save_all_attachments(parser);
    }

    zmail_free(parser);
}

int main(int argc, char **argv)
{
    zmain_argument_run(argc, argv, 0);
    enable_att = zconfig_get_bool(zvar_default_config, "att", 0);

    if (zvar_main_redundant_argc == 0) {
        printf("USAGE: %s [--att] eml_fn...\n", zvar_progname);
        exit(0);
    }
    for (int i = 0; i < zvar_main_redundant_argc; i++) {
        do_parse(zvar_main_redundant_argv[i]);
    }

    return 0;
}

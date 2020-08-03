/*
 * ================================
 * eli960@qq.com
 * http://linuxmail.cn/
 * 2020-07-29
 * ================================
 */

#include "zc.h"

static void usage()
{
    printf("USAGE: %s keyword_list_file file_for_dump\n", zvar_progname);
    exit(0);
}

int main(int argc, char **argv)
{
    zmain_argument_run(argc, argv, 0);
    if (zvar_main_redundant_argc != 2) {
        usage();
    }
    char *listfn = zvar_main_redundant_argv[0];
    char *dumpfn = zvar_main_redundant_argv[1];

    zmsearch_t *ms = 0;
    ms = zmsearch_create();
    if (zmsearch_add_token_from_pathname(ms, listfn) < 0) {
        printf("ERR can not open %s(%m)\n", listfn);
        exit(1);
    }
    zmsearch_add_over(ms);

    if (zfile_put_contents(dumpfn, zmsearch_get_compiled_data(ms), zmsearch_get_compiled_len(ms)) < 1) {
        printf("ERR write %s(%m)\n", dumpfn);
        exit(1);
    }

    zmsearch_free(ms);

    return 0;
}


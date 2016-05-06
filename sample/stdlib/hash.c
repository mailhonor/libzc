/*
 * ================================
 * eli960@163.com
 * http://www.mailhonor.com/
 * 2015-12-06
 * ================================
 */

#include "libzc.h"

void usage()
{
    printf("USAGE:\n\t%s filename\n", zvar_progname);
    exit(1);
}

int main(int argc, char **argv)
{
    char *fn;
    zmmap_reader reader;
    char result_md5[16 + 1];
    char result_sha1[20 + 1];
    unsigned int result_crc32;
    unsigned long result_crc64;
    char p_buf[64];
    int plen;

    zvar_progname = argv[0];
    if (argc != 2) {
        usage();
    }
    fn = argv[1];

    if (zmmap_reader_init(&reader, fn) < 0) {
        printf("can not open %s: %m\n", fn);
        exit(1);
    }

    result_crc32 = zcrc32(reader.data, reader.len, 0);
    plen = zhex_encode(&result_crc32, (int)(sizeof(unsigned int)), p_buf);
    p_buf[plen] = 0;
    printf("crc32\t: %s\n", p_buf);

    result_crc64 = zcrc64(reader.data, reader.len, 0);
    plen = zhex_encode(&result_crc64, (int)(sizeof(unsigned long)), p_buf);
    p_buf[plen] = 0;
    printf("crc64\t: %s\n", p_buf);

    zmd5(reader.data, reader.len, result_md5);
    plen = zhex_encode(result_md5, 16, p_buf);
    p_buf[plen] = 0;
    printf("md5\t: %s\n", p_buf);

    zsha1(reader.data, reader.len, result_sha1);
    plen = zhex_encode(result_sha1, 20, p_buf);
    p_buf[plen] = 0;
    printf("sha1\t: %s\n", p_buf);

    zmmap_reader_fini(&reader);

    return 0;
}

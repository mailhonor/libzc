/*
 * ================================
 * eli960@qq.com
 * http://www.mailhonor.com/
 * 2015-10-12
 * ================================
 */

#include "zc.h"
#include <ctype.h>

/* ################################################################## */
/* string case convert.
 * only support Enlish locale.
 */

unsigned const char zchar_lowercase_list[256] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x40, 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z', 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    0x60, 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z', 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
    0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
    0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

unsigned const char zchar_uppercase_list[256] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x40, 'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    0x60, 'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
    0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
    0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

char *ztolower(char *str)
{
    char *scan = str;

    while (*scan) {
        *scan = ZCHAR_TOLOWER(*scan);
        scan++;
    }

    return (str);
}

char *ztoupper(char *str)
{
    char *scan = str;

    while (*scan) {
        *scan = ZCHAR_TOUPPER(*scan);
        scan++;
    }

    return (str);
}

/* ################################################################## */
/* strtok */

void zstrtok_init(zstrtok_t * k, const char *sstr)
{
    k->sstr = (char *)sstr;
    k->len = 0;
    k->str = NULL;
}

zstrtok_t *zstrtok(zstrtok_t * k, const char *delim)
{
    char *r;

    r = k->sstr;
    r += strspn(k->sstr, delim);
    if (*r == 0)
        return (NULL);
    k->len = strcspn(r, delim);
    if (k->len == 0)
        return (NULL);
    k->sstr = r + k->len;
    k->str = r;

    return (k);
}

/* ################################################################## */
/* trim */

#define ___SKIP(start, var, cond) for (var = start; *var && (cond); var++);
#define ___DELETE(ch) ((isascii(ch) && isspace(ch)) || iscntrl(ch))
#define ___TRIM(s) { char *p; for (p = (s) + strlen(s); p > (s) && ___DELETE(p[-1]); p--); *p = 0; }

char *ztrim_left(char *str)
{
    char *np;

    ___SKIP(str, np, ___DELETE(*np));

    return np;
}

char *ztrim_right(char *str)
{

    ___TRIM(str);

    return str;
}

char *ztrim(char *str)
{
    char *np;

    ___SKIP(str, np, ___DELETE(*np));
    ___TRIM(np);

    return np;
}

/* skip */
char *zskip_left(const char *str, const char *ignores)
{
    char ch;
    int i = 0;

    while((ch = str[i++])) {
        const char *ignore_p = ignores;
        while(*ignore_p) {
            if (ch == (*ignore_p)) {
                break;
            }
            ignore_p ++;
        }
        if (!*ignore_p) {
            return (char *)str + i;
        }
    }
    return (NULL);
}

char *zskip_right(const char *str, int size, const char *ignores)
{
    int i = 0;
    if (size < 1)
        return (NULL);
    for (i = 0; i < size; i++) {
        const char ch = str[size - i - 1];
        const char *ignore_p = ignores;
        while(*ignore_p) {
            if (ch == (*ignore_p)) {
                break;
            }
            ignore_p ++;
        }
        if (!*ignore_p) {
            return (char *)str + i;
        }
    }
    return (NULL);
}

int zskip(const char *line, int len, const char *ignores_left, const char *ignores_right, char **start)
{
    const char *ps,  *pend = line + len;
    int i, ch;

    for (i = 0; i < len; i++) {
        ch = line[i];
        if (strchr(ignores_left, ch)) {
            continue;
        }
        break;
    }
    if (i == len) {
        return 0;
    }

    if (!ignores_right) {
        ignores_right = ignores_left;
    }
    ps = line + i;
    len = pend - ps;
    for (i = len - 1; i >= 0; i--) {
        ch = ps[i];
        if (strchr(ignores_right, ch)) {
            continue;
        }
        break;
    }
    if (i < 0) {
        return 0;
    }

    *start = (char *)ps;

    return i+1;

}

char *zfind_delim(const char *str, const char *delims)
{
    char ch;
    int i = 0;

    while((ch = str[i++])) {
        const char *ignore_p = delims;
        while(*ignore_p) {
            if (ch == (*ignore_p)) {
                return (char *)str + i;
            }
            ignore_p ++;
        }
    }
    return (NULL);
}

/* ################################################################## */
/* unit convert */

int zstr_to_bool(const char *s, int def)
{
    if (!strcmp(s, "1") || !strcasecmp(s, "y") || !strcasecmp(s, "yes") || !strcasecmp(s, "true"))
        return 1;
    if (!strcmp(s, "0") || !strcasecmp(s, "n") || !strcasecmp(s, "no") || !strcasecmp(s, "false"))
        return 0;

    return def;
}

long zstr_to_second(const char *s)
{
    char unit, junk;
    long intval;

    switch (sscanf(s, "%ld%c%c", &intval, &unit, &junk)) {
    case 1:
        unit = 's';
    case 2:
        if (intval < 0)
            return 0;
        switch (ZCHAR_TOLOWER(unit)) {
        case 'w':
            return (intval * (7 * 24 * 3600));
        case 'd':
            return (intval * (24 * 3600));
        case 'h':
            return (intval * 3600);
        case 'm':
            return (intval * 60);
        case 's':
        default:
            return (intval);
        }
    }

    return 0;
}

long zstr_to_size(const char *s)
{
    char unit, junk;
    long intval;

    switch (sscanf(s, "%ld%c%c", &intval, &unit, &junk)) {
    case 1:
        unit = 'b';
    case 2:
        if (intval < 0)
            return 0;
        switch (ZCHAR_TOLOWER(unit)) {
        case 'g':
            return (intval * (1024 * 1024 * 1024));
        case 'm':
            return (intval * (1024 * 1024));
        case 'k':
            return (intval * 1024);
        case 'b':
        default:
            return (intval);
        }
    }

    return 0;
}

/* find */
char *zmemstr(const void *s, const char *needle, int len)
{
    char *src_c = (char *)s;
    int nlen = strlen(needle);
    int i, j;

    if (len < nlen) {
        return 0;
    }
    len = len - nlen + 1;

    for (i = 0; i < len; i++) {
        for (j = 0; j < nlen; j++) {
            if (needle[j] != src_c[i + j]) {
                break;
            }
        }
        if (j == nlen) {
            return src_c + i;
        }
    }

    return 0;
}

char *zmemcasestr(const void *s, const char *needle, int len)
{
    char *src_c = (char *)s;
    int nlen = strlen(needle);
    int i, j;

    if (len < nlen) {
        return 0;
    }
    len = len - nlen + 1;

    for (i = 0; i < len; i++) {
        for (j = 0; j < nlen; j++) {
            if (zchar_toupper(needle[j]) != zchar_toupper(src_c[i + j])) {
                break;
            }
        }
        if (j == nlen) {
            return src_c + i;
        }
    }

    return 0;
}

/* ################################################################## */
/* strncpy, strncat */

char *zstrncpy(char *dest, const char *src, int len)
{
    int i;

    for (i=0;i<len;i++) {
        if (!(src[i])) {
            break;
        }
        dest[i] = src[i];
    }

    dest[i] = 0;

    return dest;
}

char *zstrncat(char *dest, const char *src, int len)
{
    int olen, i;

    olen = strlen(dest);
    for (i=0;i<len;i++) {
        if (!(src[i])) {
            break;
        }
        dest[olen + i] = src[i];
    }

    dest[olen + i] = 0;

    return dest;
}


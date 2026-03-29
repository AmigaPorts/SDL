/*
 * amiga_shims.c -- Missing libc functions for AmigaOS 3.x (libnix)
 *
 * libnix is a C89 runtime. These functions are expected by Chocolate Doom
 * but not provided by libnix or amiport's posix-shim.
 */

#include <string.h>

/* strnlen: return length of string, up to maxlen */
size_t strnlen(const char *s, size_t maxlen)
{
    size_t len = 0;
    while (len < maxlen && s[len] != '\0')
        len++;
    return len;
}

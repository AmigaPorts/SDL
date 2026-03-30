/* endian.h shim for AmigaOS 3.x (68k big-endian)
 * Provides POSIX endian macros that fheroes2 serialize.h expects.
 * 68k is big-endian: host-to-big is identity, host-to-little swaps. */

#ifndef AMIGA_ENDIAN_H
#define AMIGA_ENDIAN_H

#define BIG_ENDIAN 4321
#define LITTLE_ENDIAN 1234
#define BYTE_ORDER BIG_ENDIAN

#define htobe16(x) (x)
#define htole16(x) __builtin_bswap16(x)
#define be16toh(x) (x)
#define le16toh(x) __builtin_bswap16(x)
#define htobe32(x) (x)
#define htole32(x) __builtin_bswap32(x)
#define be32toh(x) (x)
#define le32toh(x) __builtin_bswap32(x)

#endif

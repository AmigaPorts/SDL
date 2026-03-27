# libnix Reference — C Runtime for AmigaOS/m68k

Extracted from [bebbo/libnix](https://github.com/bebbo/libnix) and [adtools/libnix](https://github.com/adtools/libnix/blob/master/libnix.texi). This is the C runtime linked with `-noixemul`.

## Overview

libnix is a static C link library for GCC on Amiga. It is similar to glibc or newlib but incomplete. It provides: auto-open-library, Workbench startup handling, auto-detach, minimal size, no shared library dependency, and automatic stack extension.

**Authors:** Matthias Fleischer & Gunther Nikl (public domain)
**Requires:** AmigaOS 2.0+

## Key Behaviors

### Stack Handling

The `__stack` variable sets minimum stack size. If the current stack is smaller, libnix allocates a new one. Supports `-mstackcheck` and `-mstackextend` compiler flags.

**IMPORTANT:** On vamos, the `__stack` cookie is NOT read at runtime (crash-patterns #7). The libnix startup in the amiport toolchain does NOT reallocate the stack. Use `vamos -s <KB>` or `Stack <bytes>` in ARexx Execute scripts.

### Memory Management

Uses `malloc()` with local memory pools. Default block size: 16384 bytes. Configurable via `_MSTEP` variable. Memory is reclaimed on exit for programs using libnix startup.

**With -noixemul:** Process memory IS cleaned up on normal exit (libnix's `__EXIT_LIST__` runs cleanup). However, `err()`/`errx()` call `_exit()` directly, bypassing cleanup. Use `atexit()` for guaranteed cleanup.

### Signal Handling

Only `SIGABRT` and `SIGINT` supported. `SIGINT` is polled via `__chkabort()` (called from stdio functions). Disable Ctrl-C checking with: `void __chkabort(void) {}`.

### Standard I/O

- `stdin`/`stdout` from `dos.library` (Input()/Output())
- `stderr` has three fallback methods: dos.library error stream, NIL:, or stdout
- Floating-point printf requires linking `-lm`

### Library Base Pointers

Auto-opened via `__LIB_LIST__` set elements. `__initlibraries()` opens them at startup, `__exitlibraries()` closes at exit.

### Startup Codes

- `ncrt0.o` — Normal large code/data model
- `nbcrt0.o` — Small data model (a4-relative, 64KB data limit)
- `nrcrt0.o` — Reentrant/resident programs

## Complete Function List

Extracted from `libc.a` via `nm`. These are ALL functions available with `-noixemul`:

### stdio.h
`clearerr` `fclose` `fdopen` `feof` `ferror` `fflush` `fgetc` `fgetpos` `fgets` `fileno` `fmemopen` `fopen` `fprintf` `fputc` `fputs` `fread` `freopen` `fscanf` `fseek` `fseeko` `fsetpos` `ftell` `ftello` `funopen` `fwide` `fwrite` `getc` `getchar` `gets` `getw` `perror` `printf` `putc` `putchar` `puts` `putw` `remove` `rename` `rewind` `scanf` `setbuf` `setbuffer` `setlinebuf` `setvbuf` `snprintf` `sprintf` `sscanf` `tempnam` `tmpfile` `tmpnam` `ungetc` `vfprintf` `vfscanf` `vprintf` `vscanf` `vsnprintf` `vsprintf` `vsscanf`

Also: `fpurge` `fopencookie` `open_memstream` `asprintf` `vasprintf` `dprintf` `vdprintf`

### stdlib.h
`abort` `abs` `atexit` `atof` `atoi` `atol` `atoll` `bsearch` `calloc` `div` `exit` `free` `getenv` `labs` `ldiv` `llabs` `lldiv` `malloc` `memalign` `mkdtemp` `mkostemp` `mkostemps` `mkstemp` `mkstemps` `mktemp` `putenv` `qsort` `qsort_r` `rand` `rand_r` `random` `realloc` `reallocarray` `reallocf` `setenv` `srand` `srand48` `srandom` `strtod` `strtof` `strtoimax` `strtol` `strtold` `strtoll` `strtoul` `strtoull` `strtoumax` `system` `unsetenv` `valloc`

Also: `aligned_alloc` `arc4random` `arc4random_buf` `arc4random_uniform` `on_exit` `quick_exit` `at_quick_exit`

### string.h
`bcmp` `bcopy` `bzero` `explicit_bzero` `index` `memccpy` `memchr` `memcmp` `memcpy` `memmem` `memmove` `mempcpy` `memrchr` `memset` `rawmemchr` `rindex` `stpcpy` `stpncpy` `strcasecmp` `strcasestr` `strcat` `strchr` `strchrnul` `strcmp` `strcoll` `strcpy` `strcspn` `strdup` `strerror` `strlcat` `strlcpy` `strlen` `strlwr` `strncasecmp` `strncat` `strncmp` `strncpy` `strndup` `strnlen` `strnstr` `strpbrk` `strrchr` `strsep` `strsignal` `strspn` `strstr` `strtok` `strtok_r` `strupr` `strverscmp` `strxfrm` `swab`

### time.h
`asctime` `asctime_r` `clock` `ctime` `ctime_r` `difftime` `gmtime` `gmtime_r` `localtime` `localtime_r` `mktime` `strftime` `strptime` `time` `tzset`

### ctype.h
`isalnum` `isalpha` `isascii` `isblank` `iscntrl` `isdigit` `isgraph` `islower` `isprint` `ispunct` `isspace` `isupper` `isxdigit` `toascii` `tolower` `toupper`

### wctype.h / wchar.h
`iswalnum` `iswalpha` `iswblank` `iswcntrl` `iswctype` `iswdigit` `iswgraph` `iswlower` `iswprint` `iswpunct` `iswspace` `iswupper` `iswxdigit` `towctrans` `towlower` `towupper` `wctrans` `wctype`

`fgetwc` `fgetws` `fputwc` `fputws` `fwprintf` `fwscanf` `getwc` `getwchar` `mbrlen` `mbrtowc` `mbsinit` `mbsnrtowcs` `mbsrtowcs` `mbstowcs` `mbtowc` `putwc` `putwchar` `swprintf` `swscanf` `ungetwc` `vfwprintf` `vfwscanf` `vswprintf` `vswscanf` `vwprintf` `vwscanf` `wcpcpy` `wcpncpy` `wcrtomb` `wcscasecmp` `wcscat` `wcschr` `wcscmp` `wcscoll` `wcscpy` `wcscspn` `wcsdup` `wcsftime` `wcslcat` `wcslcpy` `wcslen` `wcsncasecmp` `wcsncat` `wcsncmp` `wcsncpy` `wcsnlen` `wcsnrtombs` `wcspbrk` `wcsrchr` `wcsrtombs` `wcsspn` `wcsstr` `wcstod` `wcstof` `wcstoimax` `wcstok` `wcstol` `wcstold` `wcstoll` `wcstombs` `wcstoul` `wcstoull` `wcstoumax` `wcswidth` `wcsxfrm` `wctob` `wctomb` `wcwidth` `wmemchr` `wmemcmp` `wmemcpy` `wmemmove` `wmempcpy` `wmemset` `wprintf` `wscanf`

### POSIX / BSD extensions
`basename` `dirname` `getopt` `getopt_long` `getopt_long_only` `getsubopt` `hcreate` `hdestroy` `hsearch` `l64a` `a64l` `nl_langinfo` `rpmatch` `tdelete` `tdestroy` `tfind` `tsearch` `twalk` `uname`

### Low-level I/O
`close` `lseek` `open` `read` `write`

### Notable MISSING Functions

These are NOT in libc.a and need amiport shims:

| Function | Category | Shim |
|----------|----------|------|
| `fork()`, `exec*()`, `wait*()` | Process | Not possible on AmigaOS |
| `pipe()` | IPC | `amiport_emu_pipe()` (Tier 2) |
| `stat()`, `fstat()`, `lstat()` | File info | `amiport_stat()` etc. |
| `opendir()`, `readdir()`, `closedir()` | Directory | `amiport_opendir()` etc. |
| `scandir()`, `alphasort()` | Directory | `amiport_scandir()` |
| `fnmatch()` | Pattern | `amiport_fnmatch()` |
| `glob()`, `globfree()` | Pattern | `amiport_glob()` |
| `signal()` (full POSIX) | Signal | `amiport_signal()` (limited) |
| `pledge()`, `unveil()` | Sandbox | Stub as no-op |
| `getpwnam()`, `getgrnam()` | Users | Not applicable |
| `mmap()`, `munmap()` | Memory | Not possible (no MMU on 68000) |
| `popen()`, `pclose()` | Process | Tier 3 redesign |
| `regex` (`regcomp` etc.) | Pattern | `amiport_emu_regex()` (Tier 2) |

## Surprises — Functions That ARE Available

These are in libc.a but might be unexpected:

- `strlcpy()` / `strlcat()` — BSD extensions, available!
- `reallocarray()` — OpenBSD extension, available!
- `getopt_long()` — GNU extension, symbol exists in libnix BUT BROKEN: returns '?' for all options. Use `#include <amiport/getopt.h>` instead. See crash-patterns.md #16.
- `strcasecmp()` / `strncasecmp()` — POSIX, available!
- `strsep()` — BSD, available!
- `strtok_r()` — POSIX, available!
- `random()` / `srandom()` — BSD, listed in headers but **MISSING from libc.a** in current bebbo-gcc. Linker fails with `undefined reference to _random`. Use `rand()` / `srand()` instead, or `#define random() rand()`.
- `arc4random()` — BSD, available!
- `explicit_bzero()` — OpenBSD, available!
- `asprintf()` / `vasprintf()` — GNU, available!
- `strptime()` — POSIX, available!
- `mkstemp()` — POSIX, available!

**Note:** "Available in libc.a" does not mean it works correctly on AmigaOS. Some functions (like `tmpfile()`) may have AmigaOS-specific issues. The amiport shims exist to provide correct AmigaOS behavior even when libnix has the function.

## References

- [libnix source (bebbo fork)](https://github.com/bebbo/libnix)
- [libnix docs (adtools)](https://github.com/adtools/libnix/blob/master/libnix.texi)
- [clib2 (more complete alternative)](https://github.com/adtools/clib2)
- [ANSI C Reference Card (PDF)](https://users.ece.utexas.edu/~adnan/c-refcard.pdf)

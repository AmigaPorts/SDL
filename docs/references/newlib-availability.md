# newlib / -noixemul Function Availability

Reference for what C library functions are available in bebbo-gcc's `-noixemul` runtime (libnix / newlib). This determines whether a function needs shimming or is already provided.

The amiport toolkit targets `-noixemul` to avoid the heavy ixemul.library dependency. This means we get a smaller C runtime but some functions are missing.

## Legend

- **Available**: Function works out of the box with `-noixemul`
- **Partial**: Available but with caveats (noted)
- **Missing**: Not provided; needs amiport shim or inline replacement
- **Use Shim**: Available in libnix but amiport shim is preferred for consistency/correctness

---

## Standard I/O (`<stdio.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `printf`, `fprintf`, `sprintf`, `snprintf` | Available | |
| `vprintf`, `vfprintf`, `vsprintf`, `vsnprintf` | Available | |
| `fopen`, `fclose`, `fread`, `fwrite` | Available | |
| `fgets`, `fputs`, `fgetc`, `fputc` | Available | |
| `fseek`, `ftell`, `rewind`, `fflush` | Available | |
| `sscanf`, `fscanf`, `scanf` | Available | |
| `perror` | Available | |
| `tmpfile` | Missing | Use `amiport_tmpfile()` (T: assign) |
| `tmpnam` | Missing | Use `amiport_tmpfile()` instead |
| `popen`, `pclose` | Missing | Tier 3 — needs SystemTags+PIPE: redesign |
| `fileno` | Missing | Use `amiport_fileno()` |
| `fdopen` | Missing | Use `amiport_fdopen()` |
| `getline` | Missing | Use `amiport_getline()` |
| `getdelim` | Missing | Use `amiport_getdelim()` |
| `fgetln` | Missing | BSD extension; not in libnix |
| `asprintf`, `vasprintf` | Missing | Use `amiport_asprintf()` / `amiport_vasprintf()` |
| `setbuf`, `setvbuf` | Available | |
| `fpurge` | Missing | Use `amiport_fpurge()` (stub — no-op) |
| `pread`, `pwrite` | Missing | Use `amiport_pread()` / `amiport_pwrite()` |

## String (`<string.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `strlen`, `strcmp`, `strncmp` | Available | |
| `strcpy`, `strncpy` | Available | |
| `strcat`, `strncat` | Available | |
| `strchr`, `strrchr`, `strstr` | Available | |
| `strdup` | Available | |
| `strtok` | Available | Not reentrant; use `amiport_strtok_r()` for thread safety |
| `strtok_r` | Missing | Use `amiport_strtok_r()` |
| `strlcpy` | Missing | Use `amiport_strlcpy()` |
| `strlcat` | Missing | Use `amiport_strlcat()` |
| `memcpy`, `memmove`, `memset`, `memcmp` | Available | |
| `strerror` | Available | |
| `strsep` | Missing | BSD extension; simple to implement inline |
| `strcasestr` | Missing | Use `amiport_strcasestr()` |
| `strcasecmp` | Missing | Use `amiport_strcasecmp()` |
| `strncasecmp` | Missing | Use `amiport_strncasecmp()` |
| `strndup` | Missing | POSIX.1-2008; implement with malloc+strncpy |
| `explicit_bzero` | Missing | Use `amiport_explicit_bzero()` |

## Standard Library (`<stdlib.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `malloc`, `calloc`, `realloc`, `free` | Available | |
| `reallocarray` | Missing | Use `amiport_reallocarray()` |
| `recallocarray` | Missing | Use `amiport_recallocarray()` |
| `atoi`, `atol` | Available | |
| `strtol`, `strtoul` | Available | |
| `strtoll`, `strtoull` | Partial | May not be available on all builds; `long` is 32-bit on Amiga |
| `strtonum` | Missing | Use `amiport_strtonum()` (OpenBSD extension) |
| `qsort`, `bsearch` | Available | |
| `abs`, `labs` | Available | |
| `rand`, `srand` | Available | |
| `exit`, `atexit` | Available | |
| `getenv` | Partial | libnix provides it but uses ENV:; `amiport_getenv()` uses GetVar() for full compatibility |
| `setenv` | Missing | Use `amiport_setenv()` |
| `unsetenv` | Missing | Use `amiport_unsetenv()` |
| `mkstemp` | Missing | Use `amiport_mkstemp()` |
| `system` | Partial | Available but uses Execute(); prefer SystemTags() for more control |

## Character (`<ctype.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `isalpha`, `isdigit`, `isalnum`, etc. | Available | |
| `toupper`, `tolower` | Available | |
| `isascii` | Available | |
| `isblank` | Partial | C99; may not be in older libnix |

## Math (`<math.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `sin`, `cos`, `tan`, etc. | Available | Software FP with `-msoft-float` |
| `sqrt`, `pow`, `log`, `exp` | Available | |
| `floor`, `ceil`, `fabs` | Available | |
| `fmod` | Available | |
| `round`, `trunc` | Partial | C99; may need `-lm` |

## Time (`<time.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `time` | Partial | Available but may not handle timezone; use `amiport_time()` |
| `localtime`, `gmtime` | Partial | Available; timezone support varies |
| `strftime` | Available | |
| `strptime` | Missing | Use `amiport_strptime()` |
| `mktime` | Available | |
| `difftime` | Available | |
| `clock` | Partial | Available but resolution is poor |
| `gettimeofday` | Missing | Use `amiport_gettimeofday()` |

## POSIX / Unix (`<unistd.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `read`, `write` (raw) | Available | libnix wraps AmigaDOS Read()/Write() |
| `open`, `close` (raw) | Available | But flag mapping is wrong; use `amiport_open()` |
| `lseek` | Available | But semantics differ; use `amiport_lseek()` |
| `unlink` | Available | |
| `rename` | Missing | Use `amiport_rename()` |
| `access` | Missing | Use `amiport_access()` |
| `getcwd` | Missing | Use `amiport_getcwd()` |
| `chdir` | Missing | Use `amiport_chdir()` |
| `sleep` | Missing | Use `amiport_sleep()` |
| `usleep` | Missing | Use `amiport_usleep()` |
| `getpid` | Missing | Use `amiport_getpid()` |
| `isatty` | Missing | Use `amiport_isatty()` |
| `dup` | Missing | Use `amiport_dup()` |
| `dup2` | Missing | Use `amiport_dup2()` |
| `pipe` | Missing | Use `amiport_emu_pipe()` (Tier 2) |
| `fork`, `exec*`, `wait*` | Missing | Tier 3 — no process model |
| `ftruncate` | Missing | Use `amiport_ftruncate()` |
| `readlink` | Missing | Use `amiport_readlink()` (stub — returns EINVAL, no symlinks on classic FFS) |
| `realpath` | Missing | Use `amiport_realpath()` |
| `setlocale` | Missing | Use `amiport_setlocale()` (stub — returns "C") |

## Argument Parsing (`<getopt.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `getopt` | Missing | Use `amiport_getopt()` |
| `getopt_long` | Missing | Use `amiport_getopt_long()` |

## Error Reporting (BSD `<err.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `err`, `errx` | Missing | Use `amiport_err()` / `amiport_errx()` |
| `warn`, `warnx`, `warnc` | Missing | Use `amiport_warn()` / `amiport_warnx()` / `amiport_warnc()` |

## Directory (`<dirent.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `opendir` | Missing | Use `amiport_opendir()` |
| `readdir` | Missing | Use `amiport_readdir()` |
| `closedir` | Missing | Use `amiport_closedir()` |
| `scandir` | Missing | Use `amiport_scandir()` |
| `alphasort` | Missing | Use `amiport_alphasort()` |
| `mkdir` | Partial | libnix may provide; use `amiport_mkdir()` for consistency |
| `rmdir` | Missing | Use `amiport_rmdir()` |

## File Status (`<sys/stat.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `stat` | Missing | Use `amiport_stat()` |
| `fstat` | Missing | Use `amiport_fstat()` |
| `lstat` | Missing | Use `amiport_stat()` (no symlink distinction on classic FFS) |
| `chmod` | Missing | Use `amiport_chmod()` (stub — Amiga protection bits have inverted semantics) |

## Signals (`<signal.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `signal` | Partial | libnix may provide basic version; use `amiport_signal()` for SIGINT mapping |
| `raise` | Missing | Use `amiport_raise()` |
| `kill` | Missing | Tier 3 — no inter-process signaling |
| `sigaction`, `sigprocmask` | Missing | Tier 3 |
| `alarm` | Missing | Use `amiport_emu_alarm()` (Tier 2) |

## Regular Expressions (`<regex.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `regcomp` | Missing | Use `amiport_emu_regcomp()` (Tier 2) |
| `regexec` | Missing | Use `amiport_emu_regexec()` (Tier 2) |
| `regfree` | Missing | Use `amiport_emu_regfree()` (Tier 2) |
| `regerror` | Missing | Use `amiport_emu_regerror()` (Tier 2) |

## Memory Mapping (`<sys/mman.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `mmap` | Missing | Use `amiport_emu_mmap()` (Tier 2 — AllocMem+Read emulation) |
| `munmap` | Missing | Use `amiport_emu_munmap()` (Tier 2) |

## Select / Polling (`<sys/select.h>`)

| Function | Status | Notes |
|----------|--------|-------|
| `select` (on fds) | Missing | Use `amiport_emu_select()` (Tier 2 — WaitForChar polling) |

## Glob / Pattern Matching

| Function | Status | Notes |
|----------|--------|-------|
| `fnmatch` | Missing | Use `amiport_fnmatch()` |
| `glob`, `globfree` | Missing | Use `amiport_glob()` / `amiport_globfree()` from posix-shim |

## Networking (all missing with -noixemul)

All BSD socket functions (`socket`, `connect`, `bind`, `listen`, `accept`, `send`, `recv`, `select` on sockets, `gethostbyname`, etc.) are **missing** from libnix. Networking requires either:
- **ixemul.library** (which we avoid), or
- **bsdsocket.library** (AmiTCP/Roadshow/Miami) with direct API calls

Use `lib/bsdsocket-shim/` for BSD socket API wrappers. See ADR-010.

---

## How Agents Should Use This Reference

### source-analyzer
When encountering a function call, check this table:
1. If **Available**: no action needed (no transformation required)
2. If **Partial**: check notes — may need `Use Shim` depending on usage
3. If **Missing**: classify by tier and recommend appropriate shim/emu/redesign
4. If **Use Shim**: even though libnix provides it, prefer the amiport wrapper for better behavior

### build-manager
When hitting "undefined reference" errors:
1. Check if the function is listed as **Missing** here
2. If it has an amiport shim: the source transformation was incomplete — flag for re-transformation
3. If no shim exists: recommend `/extend-shim` or provide an inline replacement

Paths: ports/**/*.c, ports/**/*.h, lib/**/*.c, lib/**/*.h, examples/**/*.c, examples/**/*.h

# Known Pitfalls — Hard-Won Lessons

These are real bugs encountered in real ports. Check for them every time.

## fopen() Macro Collision

`amiport/stdio.h` defines `#define fopen(p, m) amiport_fopen(p, m)`. Inside `file_io.c` (which implements `amiport_fopen`), this causes infinite recursion. **Fix:** `#undef fopen` before the implementation. Same for `fclose`.

## vamos argv Pointer Arithmetic

On vamos, argv entries are NOT contiguous — each is independently allocated. Code that does `argv[argc-1] - argv[0]` will crash. **Fix:** Use explicit `strlen()` iteration.

## pledge/unveil Stubs

OpenBSD code almost always calls `pledge()` and `unveil()`. Stub as macros:
```c
#define pledge(p, e) (0)
#define unveil(p, f) (0)
```
Never shim as functions.

## vsnprintf(NULL, 0, ...) Crash

libnix's `vsnprintf` does NOT support `NULL` as the destination buffer (C99 extension). Calling `vsnprintf(NULL, 0, fmt, ap)` to measure buffer size crashes on 68000 — libnix writes to address zero. **Fix:** Use a probe buffer:
```c
char probe[1024];
int len = vsnprintf(probe, sizeof(probe), fmt, ap);
```
This commonly appears when replacing `vasprintf()`/`asprintf()`. Use `amiport_asprintf()` instead. See crash-patterns.md #5.

## Long-Running Loops Need Ctrl-C Check

Any `while (1)` or `for (;;)` loop that runs indefinitely (e.g., `tail -f` polling, event loops, recursive directory walks) MUST call `amiport_check_break()` from `<amiport/signal.h>`. Without this, the user cannot interrupt the program — there is no OS-level SIGINT delivery on AmigaOS. **Fix:**
```c
#include <amiport/signal.h>
/* ... inside the loop: */
if (amiport_check_break()) {
    (void)fflush(stdout);
    return;
}
```

## ~~exit() Hangs on AmigaOS~~ DEBUNKED

This was a misdiagnosis. Testing with minimal programs on FS-UAE + Workbench 3.1 confirmed that `exit(0)` returns immediately — no hang. The actual cause of all FS-UAE test timeouts was ARexx syntax errors in the test harness (UTF-8 characters and `\=` operator). See crash-patterns.md #9 for the full post-mortem.

The `amiport_exit()` shim exists but is unnecessary. It remains in place to avoid churn.

## ARexx Files Must Be Pure ASCII

ARexx (1987) does not understand UTF-8. Any non-ASCII byte in a `.rexx` file — including inside comments — causes "Error 8: Unrecognized token" and crashes the script. Also, use `~=` for not-equal, not `\=` which may not be recognized by all ARexx interpreters. **This caused weeks of misdiagnosed "exit hang" bugs.**

## AmigaDOS Double-Redirect with Run

`Run >file1 cmd >file2` applies BOTH `>` redirections to the `Run` command at the top level. The backgrounded command gets NO redirect and floods the console. **Fix:** Write the command + redirect into a temp Execute script, then `Run >clinumfile Execute scriptfile`. This isolates the command's `>` from Run's `>`. See the test-designer agent and write-arexx skill for the full pattern.

## Large Local Buffers Cause Guru on Real AmigaOS

Local arrays > 512 bytes are dangerous. On real AmigaOS, dos.library/filesystem calls add 2-4KB of hidden stack depth that vamos doesn't simulate. A program with `char buf[4096]` and `__stack=16384` passes all vamos tests but crashes with Guru Meditation ACPU_LineF (0x8000000B) on FS-UAE/real hardware. **Fix:** Use `static` for large buffers in non-recursive functions, or increase `__stack` with an 8KB safety margin. See crash-patterns.md #10.

## atexit() for argv Expansion Cleanup

When using `amiport_expand_argv()`, the expanded argv is never freed if `err()`/`errx()`/`exit()` are called before `amiport_free_argv()`. These functions terminate immediately, skipping cleanup code. **Fix:** Register cleanup via `atexit()` right after expanding argv:
```c
amiport_expand_argv(&argc, &argv);
atexit(cleanup);  /* cleanup() calls amiport_free_argv() + fflush(stdout) */
```
This ensures cleanup runs on ALL exit paths, including err/errx. Without this, every error exit leaks argv memory permanently on AmigaOS with `-noixemul`.

## Never fclose(stdin) on AmigaOS

Calling `fclose(stdin)` closes the shell's input file handle. On Workbench, this crashes the console handler and can take down the entire desktop. Many C programs unconditionally `fclose(fp)` after use — when `fp == stdin`, this is fatal. **Fix:** Guard with `if (fp != stdin) fclose(fp);`. The source-analyzer and code-transformer agents should flag any `fclose()` that could receive stdin.

## MB_CUR_MAX Is a Runtime Function Call (crash-patterns #11)

`MB_CUR_MAX` in bebbo-gcc libnix expands to `__locale_mb_cur_max()` — a **runtime function call**, not a compile-time constant. It can return >1 even without locale support. Code that checks `if (MB_CUR_MAX > 1)` to enable multibyte paths will enter that path on AmigaOS, even though there's no wchar/locale support.

This is dangerous when the multibyte code path is conditionally compiled out with `#ifndef __AMIGA__` — setting a flag based on `MB_CUR_MAX` but removing the code that uses that flag means the non-multibyte path is also skipped, producing wrong output (typically all zeros).

**Fix:** Guard the `MB_CUR_MAX` check itself:
```c
#ifndef __AMIGA__
if (MB_CUR_MAX > 1)
    multibyte = 1;
#endif
```

**General rule:** For any POSIX macro used in conditionals (`MB_CUR_MAX`, `PATH_MAX`, `BUFSIZ`, etc.), check the actual expansion in bebbo-gcc headers — it may be a function call, not a constant. Don't assume compile-time values.

## amiport_open() + fdopen() = Silent Failure

`amiport_open()` returns fds from amiport's internal fd table. `fdopen()` is a libnix function expecting libnix fds. **These are different namespaces.** Passing an amiport fd to `fdopen()` creates a FILE* that silently fails to read/write. No crash, no error — just empty output.

**Fix:** Use `fopen()` whenever you need a `FILE*`. Only use `amiport_open()` with `amiport_read()`/`amiport_write()`/`amiport_close()` — never cross into libnix stdio. See crash-patterns.md #12.

## fgetc() Is 3-5x Slower Than fgets() on 68000

Each `fgetc()` call costs a JSR + stack frame + buffer check through libnix. For a 40-character line that's 40 function calls. Replace character-at-a-time loops with `fgets()` into a static buffer + `memcpy()`. On 7MHz 68000 with chip RAM contention, this eliminates ~1-2 million cycles per 1000-line file.

## Recursive Functions With Large Local Arrays

Large local arrays (>512 bytes) in recursive functions will blow the stack on real AmigaOS, even with `__stack = 65536`. Real AmigaOS adds 2-4KB of hidden stack depth from dos.library dispatch that vamos doesn't simulate. **Fix:** Make large arrays `static` when the function is single-threaded and not reentrant (which is always the case on AmigaOS). See crash-patterns.md #10.

## Exit Path Cleanup

AmigaOS has no automatic process memory cleanup with `-noixemul`. Every `exit()` call must free all allocated memory. When porting programs with global allocations (pattern arrays, compiled regex, line buffers), add a cleanup function called before every `exit()`. See grep port for the `cleanup_patterns()` pattern.

## vamos Default Stack Is 8 KiB — __stack Cookie Not Read at Runtime

The libnix startup code in `-noixemul` binaries does NOT check the `LONG __stack` variable or reallocate the stack. It uses whatever stack the OS (or vamos) provides. vamos defaults to 8 KiB (`amitools/vamos/cfg/proc.py: "stack": 8`). Programs that use AmigaDOS calls (Lock/Examine/GetDeviceProc) consume extra hidden stack beyond what C locals suggest. **Fix:** Add `VAMOS_STACK = 256` to the port Makefile and pass `-s $(VAMOS_STACK)` to all vamos invocations. On real AmigaOS hardware, the shell reads the `__stack` cookie correctly. See crash-patterns.md #7.

## Directory Filename Comparison Must Be Case-Insensitive

AmigaOS filesystems (OFS, FFS, SFS) are case-insensitive. Ported `diff -r`, `find`, `ls` and other directory-walking tools that use `strcmp()` to match filenames across directories will fail to match `Makefile` with `makefile`. **Fix:** Replace `strcmp()` with `strcasecmp()` for any filename/path comparison in directory operations. libnix provides `strcasecmp()`.

## readdir() d_type Is Always DT_UNKNOWN on AmigaOS

The `d_type` field in `struct dirent` is never populated by AmigaOS filesystems (OFS, FFS, SFS). It is always `DT_UNKNOWN` (0). Code that checks `dp->d_type == DT_DIR` to detect directories will silently treat all directories as regular files, breaking recursive operations like `grep -R`, `find`, and `diff -r`. **Fix:** Replace `d_type` checks with an `opendir()` probe — try `opendir(path)` on each entry; if it succeeds, the entry is a directory. This was discovered in the grep 1.68 port where `-R` silently skipped subdirectories.

## __progname — Do NOT Define in Ported Source

~~The `__progname` variable was originally a weak symbol that got stripped.~~ **UPDATE (2026-03-25):** `argv_expand.o` in `libamiport.a` now defines `__progname` as a **strong** symbol. Defining `char *__progname = "progname";` in ported source causes a linker error: `multiple definition of '__progname'`.

**Fix:** Do NOT define `__progname` in ported source. Remove any `char *__progname = "...";` line. When `amiport_expand_argv()` is called, `argv_expand.o` is pulled from the archive and provides `__progname` as a strong symbol, initialized from `argv[0]` at runtime. The `extern char *__progname;` declaration in headers is sufficient.

**If `amiport_expand_argv()` is NOT used:** Then `argv_expand.o` won't be linked, and `__progname` won't exist. In that rare case, define it locally. But all standard ports use `amiport_expand_argv()`.

Previously discovered in uniq 1.33 (weak symbol era). Updated after basename/dirname 2026-03-25 (strong symbol era).

## Braceless Multi-Statement if/else Blocks

When adding multi-statement blocks to if/else branches (e.g., `fflush(stdout); exit(RC);`), forgetting braces is a common and subtle bug. In C, only the first statement belongs to the branch — the second executes unconditionally. The program appears to work but always exits with the wrong code. **Fix:** Always use braces when a branch has more than one statement. This was discovered in the grep 1.68 port where the exit-code logic always returned 0 regardless of match/error status.

Note: the `_exit()` pattern referenced in older code was based on a debunked exit hang theory (crash-patterns #9). Use `exit()` with `atexit()` cleanup instead.

## libnix getopt_long Is Broken — Use amiport/getopt.h

The system `getopt_long()` from `<getopt.h>` exists as a symbol in libnix but returns `'?'` for ALL options, not just unknown ones. Every ported program using `getopt_long` will exit via usage() with RC=10 on the first option. This can masquerade as "works for error tests" since those expect RC=10.

**Fix:** Replace `#include <getopt.h>` with `#include <amiport/getopt.h>`. The amiport implementation aliases `getopt_long` → `amiport_getopt_long`, so no other source changes are needed. See crash-patterns.md #17.

**Detection:** If all functional tests return RC=10 and debug output shows `ch=63` ('?') for valid flags, this is the cause.

## dirname() Corrupts Its Input Buffer

`dirname(path)` is permitted by POSIX to modify the input string in-place. OpenBSD's `dirname` uses a static buffer and leaves the input alone — but libnix's `dirname` from `<libgen.h>` DOES modify the input. Any code that calls `dirname(filearg[0])` and then uses `filearg[0]` as a filename will find `filearg[0]` corrupted or empty.

**Fix (when dirname result not needed):** Remove the `dirname()` call if the result is only passed to a no-op (e.g., `unveil()` is always a no-op on AmigaOS).

**Fix (when dirname result IS needed):** Pass a `strdup()` copy to `dirname`, use the result, then free the copy AFTER you're done with the result (the result points into the copy's buffer).

See crash-patterns.md #18.

## AmigaOS Exclusive Write Lock — No Double-Open for Writing

AmigaDOS `MODE_NEWFILE` (used by `fopen("w")`) acquires an exclusive lock. If a file is already open for writing by the same program, a second `fopen(path, "w")` fails with `ERROR_OBJECT_IN_USE` (reported as "Text file busy" by strerror, which is misleading). On Unix, multiple handles can write to the same file simultaneously.

**Fix:** Close the first handle before opening the second. Check for patterns where `init_output(path)` opens a file globally, then a subroutine like `write_lines(path)` tries to open the same file.

See crash-patterns.md #19.

## obsolete() Argv Rewrite Leaks Memory

Many OpenBSD utilities have an `obsolete()` function that rewrites old-style numeric options (`+2` → `-s2`, `-3` → `-f3`) by malloc'ing new strings and assigning them to `*argv`. These strings are never freed because the pointers are stored in argv (which is not tracked for cleanup). On AmigaOS with `-noixemul`, this is a permanent leak per invocation. Affected ports: grep, tail, uniq, and any OpenBSD tool with `obsolete()`.

**Fix:** Track allocations in a static array and free them in the atexit cleanup function:
```c
#define MAX_OBSOLETE_ALLOCS 4
static char *obsolete_allocs[MAX_OBSOLETE_ALLOCS];
static int obsolete_alloc_count;

/* In obsolete(), after malloc: */
if (obsolete_alloc_count < MAX_OBSOLETE_ALLOCS)
    obsolete_allocs[obsolete_alloc_count++] = start;

/* In cleanup(), before amiport_free_argv(): */
for (i = 0; i < obsolete_alloc_count; i++)
    free(obsolete_allocs[i]);
```

## 68k Alignment Is 2, Not 4 or 8

`offsetof(struct { char x; union { int; double; } u; }, u)` returns **2** on 68k (word alignment). Code that uses this for custom allocator alignment (arenas, slab stacks, memory pools) will pack blocks at 2-byte boundaries. Storing `int`/`long`/pointer metadata between blocks corrupts data when indexed. **Fix:** Use `AMIPORT_ALIGN(offsetof(...))` from `<amiport/compat.h>` to force minimum 4-byte alignment. See crash-patterns #15.

## amiport_getenv() Returns malloc'd Strings — Caller MUST Free

POSIX `getenv()` returns a pointer to static internal storage — the caller must NOT free it. `amiport_getenv()` returns a `malloc()`'d copy (necessary because AmigaOS `GetVar()` requires a caller-provided buffer). Every `getenv()` → `amiport_getenv()` transformation silently introduces a memory leak unless the caller frees the result.

**Patterns that leak:**
```c
/* Pattern 1: result stored but never freed */
env_value = amiport_getenv("FOO");
if (env_value != NULL) { use(env_value); }
/* LEAK: env_value never freed */

/* Pattern 2: result used only for NULL check — pointer lost */
if (amiport_getenv("BAR") != NULL) { ... }
/* LEAK: malloc'd string discarded immediately */
```

**Fix:** Track results and free them, or free immediately after use:
```c
/* For NULL-check only: */
char *tmp = amiport_getenv("BAR");
if (tmp != NULL) { flag = TRUE; free(tmp); }

/* For value needed later: track in static array, free in atexit cleanup */
env_allocs[env_alloc_count++] = amiport_getenv("FOO");
```

Discovered in bc 1.07.1 port — 3 getenv calls leaked ~768 bytes per invocation.

## random() Missing from libnix — Use rand()

The libnix-reference.md lists `random()` as available, but it is **absent from the actual libnix archive** in current bebbo-gcc. Linking fails with `undefined reference to _random`. **Fix:** `#define random() rand()`. Both return `int` from `<stdlib.h>` and are equivalent for non-cryptographic use. Discovered in bc 1.07.1 port (execute.c used `random()` for the bc `random` built-in).

## Bundled getopt Clashes with libnix Symbols

When a port bundles its own GNU getopt (the correct approach — libnix's `getopt_long` is broken, see above), the `getopt`, `getopt_long`, `optarg`, `optind`, `opterr`, and `optopt` symbols clash with libnix's copies at link time. **Fix:** Add `-Wl,--allow-multiple-definition` to LDFLAGS. The bundled version (linked as object files) wins over libnix's archive version, which is the correct behavior. Discovered in bc 1.07.1 port.

## atexit Cleanup Must Not Free Uninitialized Array Entries

When programs use `more_*()` growth functions (realloc pattern: allocate larger array, copy old entries, leave new entries uninitialized), the `atexit` cleanup MUST NOT iterate and free individual entries. The new entries contain garbage pointers, and `free(garbage)` causes Guru `8100 0005` (AN_MemCorrupt — non-recoverable memory list corruption). **Fix:** Only free the array headers (`free(array_ptr)`), not individual entries like `free(array_ptr[i])`. Accept the ~200 byte leak of individual name strings as a tradeoff vs crashing. Discovered in bc 1.07.1 port — aggressive cleanup of `f_names[i]`/`v_names[i]`/`a_names[i]` entries caused AN_MemCorrupt because `more_functions()` leaves uninitialized slots after reallocation.

## Default to -O0 for Bundled Libraries Until Proven Safe

bebbo-gcc (GCC 6.5.0b) has multiple codegen bugs at -O1/-O2 on 68k. The struct-by-value return corruption (crash-patterns #16) is the documented one, but there are others -- Oniguruma regex failed on real AmigaOS at -O2 with no obvious struct returns. The failure mode is silent (works on vamos, fails on FS-UAE) making it extremely hard to diagnose.

**Rule:** Build any new bundled library (`lib/<name>/`) with `-O0` initially. Only switch to `-O2` after the full FS-UAE test suite passes AND you've verified no regressions by switching back and forth. The binary size penalty (~30-50%) is acceptable for correctness.

## bebbo-gcc -O1/-O2 Corrupts Large Struct Returns

GCC 6.5.0b for 68k generates incorrect code for functions returning structs > 8 bytes by value at `-O1` or `-O2`. The first byte of the struct reads as 0 in the caller despite being correct inside the function. **Fix:** Compile with `-O0`. Add `CFLAGS := $(subst -O2,-O0,$(CFLAGS))` to the port Makefile. No source-level workaround exists. See crash-patterns #16.

## Libraries MUST Use -m68000 (Not -m68020)

vamos only emulates a 68000 CPU. Libraries compiled with `-m68020` produce object files containing 68020 instructions. When a test binary links against such a library, the test crashes on vamos with `ALERT: code=00068020` — even if the test code itself is pure C89 with no 68020-specific features. The 68020 instructions come from the library's `.o` files inside the `.a` archive.

**Fix:** ALL libraries (`lib/posix-shim/`, `lib/console-shim/`, `lib/posix-emu/`, `lib/bsdsocket-shim/`) and ALL test Makefiles (`tests/*/Makefile`) MUST use `-m68000`. Individual port Makefiles inherit `-m68000` from `common.mk`. Discovered when console-shim was compiled with `-m68020` and test_termcap crashed on vamos.

## Static Archive Globals Pull Unwanted Dependencies

When a static archive (`.a`) contains objects with heavy OS dependencies (e.g., `initscr.o` opens `intuition.library`), programs that only need lightweight functions from the archive still pull in those heavy objects if they reference shared global variables defined in those objects. **Fix:** Put shared globals (`COLS`, `LINES`, `stdscr`, etc.) in a separate dependency-free `.c` file (e.g., `globals.c`) with no AmigaOS `#include <proto/*.h>` headers. This prevents the linker from pulling heavyweight objects into lightweight consumers. Discovered in console-shim — `test_termcap` only needed `term.o` but `COLS`/`LINES` in `initscr.o` forced `intuition.library` linkage.

## Console Programs Launched via Execute Script Get Non-Interactive Input()

When a program is launched via `Run >clinumfile Execute scriptfile` (the ITEST harness pattern), `Input()` returns the script file handle, NOT the console. `IsInteractive(Input())` returns FALSE. Programs that check `isatty(STDIN_FILENO)` will panic or exit with an error. **Fix:** Open `"*"` (AmigaOS device name for "current console window") to get a direct console handle, then use `SelectInput()`/`SelectOutput()` to redirect process I/O:
```c
if (!IsInteractive(Input()) || !IsInteractive(Output())) {
    BPTR confh_in = Open("*", MODE_OLDFILE);
    BPTR confh_out = Open("*", MODE_OLDFILE);
    if (confh_in && confh_out && IsInteractive(confh_in)) {
        saved_in = Input(); saved_out = Output();
        SelectInput(confh_in); SelectOutput(confh_out);
    }
}
```
On cleanup, restore originals with `SelectInput(saved_in)` before `Close(confh_in)`. This is the same pattern used by the less port (ttyin.c). Discovered in the mg 3.7 port where all ITEST blocks returned RC=10 from panic().

## UTF-8 Characters in Comments Break bebbo-gcc Preprocessor

The bebbo-gcc preprocessor (GCC 6.5.0b) silently eats code surrounding UTF-8 multi-byte characters, even inside C comments. An em-dash (U+2014, bytes E2 80 94) or arrow (U+2192, bytes E2 86 92) in a `/* comment */` causes the preprocessor to skip entire functions without any error or warning. The function simply vanishes from the preprocessor output. **Fix:** Use only ASCII in ALL source files, including comments. Replace em-dashes with `--`, arrows with `->`, and smart quotes with straight quotes. Discovered in the mg 3.7 port where `getenvironmentvariable()` was silently eliminated by an em-dash in a comment 20 lines later.

## amiport_isatty() Does Not Know About libnix Standard File Descriptors

`amiport_isatty(fd)` checks the amiport internal fd table. File descriptors 0 (stdin), 1 (stdout), 2 (stderr) from libnix are in a DIFFERENT fd namespace. Calling `amiport_isatty(0)` returns 0 (not a tty) because fd 0 is not in amiport's table. **Fix:** For stdin/stdout/stderr checks, use `IsInteractive(Input())` / `IsInteractive(Output())` directly from `<proto/dos.h>` instead of `isatty()`. Or use libnix's native `isatty()` if available. Discovered in the mg 3.7 port.

## libnix getenv() Returns Static Pointer -- Do NOT Free

Unlike `amiport_getenv()` which returns malloc'd strings, libnix's native `getenv()` returns a pointer to static internal storage. If a port uses libnix `getenv()` (no `#define getenv amiport_getenv` macro), callers must NOT free the result. The `amiport/stdlib.h` header does NOT define a getenv macro -- it only defines `exit -> amiport_exit`. Check whether getenv is macro'd before adding free() calls. Discovered in the mg 3.7 port where the code-transformer and review both incorrectly flagged getenv as needing free().

## CSI 0x9B Not Translated to ESC [ for VT100 Key Bindings

AmigaOS console.device sends cursor keys, function keys, and other special keys as CSI sequences (0x9B + parameters + letter). Programs that use VT100/ANSI key bindings (ESC + [ + letter) won't recognize these keys unless 0x9B is explicitly translated to ESC [.

The METABIT handler in many editors (mg, less, nano) strips the high bit from 0x9B -> 0x1B (ESC) but pushes back 0x1B instead of `[`, producing ESC ESC (Meta-ESC) instead of ESC [ (CSI sequence start).

**Fix:** Add a CSI check before any METABIT handler:
```c
#ifdef __AMIGA__
if (c == 0x9B) {
    pushedc = '[';
    pushed = TRUE;
    c = CCHR('[');  /* ESC */
} else
#endif
if (use_metakey && (c & METABIT)) { ... }
```

This affects ALL ported programs that handle keyboard input with VT100 escape sequences. Check during code-transformer stage for any `METABIT` or `0x80` bit-stripping code.

**ALSO:** FS-UAE defaults to mapping host arrow keys to joystick port 1. This steals arrow keys from the keyboard entirely -- console.device receives zero bytes. Fix: `joystick_port_1_mode = nothing` in the FS-UAE config. This must be set for ANY interactive console testing. See `toolchain/configs/amiport-test.fs-uae`. This setting must also appear in the `test-fsemu.sh` generated config -- the static config is not enough if the script generates its own.

## FS-UAE Joystick Port 1 Steals Arrow Keys

FS-UAE maps host arrow keys to Amiga joystick port 1 by default. In RAW mode programs (mg, less, nano), this means arrow keys produce zero bytes -- console.device never sees them. The program appears unresponsive to cursor movement. This is NOT a bug in the ported code.

**Fix:** Set `joystick_port_1_mode = nothing` in ALL FS-UAE config files:
- `toolchain/configs/amiport-test.fs-uae` (static config)
- Generated config in `scripts/test-fsemu.sh` (dynamic config)

Both must have this setting. If only the static config has it but the test script generates its own config, arrow keys will still be stolen. Discovered during ADR-025 mg visual testing -- arrow keys worked in manual FS-UAE sessions (which used the static config) but failed in automated tests (which used the generated config).

## ConUnit Cursor Not Updated in RAW Mode

ConUnit fields `cu_XCCP` and `cu_YCCP` (offsets +62, +64) track the cursor column and row -- but ONLY in COOKED mode. When a program switches to RAW mode via `SetMode(fh, 1)` (as all console editors and pagers do), console.device's CSI processing is bypassed. The program writes raw ANSI escape sequences directly, and ConUnit's cursor fields stay at (0,0).

Similarly, `RastPort cp_x/cp_y` always reads (0,0) because console.device uses Layer-level rendering, not direct RastPort drawing.

**Impact on EXPECT_TRAP_CURSOR:** The ScreenRead trap (ADR-025 mode 150) reads ConUnit cursor position. For RAW mode programs like mg, less, and nano, EXPECT_TRAP_CURSOR always returns (0,0) regardless of actual cursor position.

**Workaround:** For RAW mode programs, verify cursor position indirectly via the program's own status line. mg's status line (row 29 on a 30-row window) shows `(line,col)` and is updated via CMD_WRITE, so EXPECT_AT can read it. Example:
```
EXPECT_AT 29,28,2:1    /* mg status shows line 2, col 1 after DOWN arrow */
```
Column offset varies by filename length in the status line. This is the proven approach from the mg 3.7 visual test suite.

## AddIEvents() Does Not Reliably Deliver to Active Window in Visual Tests

`commodities.library/AddIEvents()` (used by KeyInject) injects input events into the Amiga input.device event chain. While this works for functional ITEST blocks (exit code verification), the injected keys do NOT reliably reach the target program's console in visual test passes.

The root cause is that FS-UAE's emulated input.device processes AddIEvents() events differently from SDL-injected keyboard events. Physical keypresses go through FS-UAE's host-side SDL -> Amiga rawkey pipeline, which follows a different path than AddIEvents().

**Fix:** Use host-side key injection via `scripts/inject-keys.sh` for visual tests. This sends keystrokes through macOS `osascript` (System Events), which feeds into FS-UAE's SDL input -- the same path as physical keypresses. The ARexx harness coordinates via sentinel files (`keys-request-N` / `keys-done-N`).

**Rule of thumb:**
- **Functional ITESTs** (exit code only): KeyInject via AddIEvents() -- works reliably
- **Visual ITESTs** (SCRAPE + EXPECT_AT): Host-side injection via inject-keys.sh -- required for RAW mode programs

## AmigaDOS Has No Single-Quote Grouping

AmigaDOS shells do not treat `'` (single quote/tick) as a grouping character. On Unix, `sed 's/; old/ new/' file` passes `s/; old/ new/` as a single argv entry. On AmigaDOS, the `'` is literal and spaces split the argument, so sed receives `'s/;` as argv[1] -- a broken expression starting with `'`. This happens BEFORE the program runs; there is no code-level fix.

This affects ALL ports that accept expression arguments with spaces: sed, grep (-e), awk, and any program where Unix users would single-quote an argument.

**Impact on readmes and documentation:** Usage examples in `.readme` files must NOT use single quotes. Show expressions without quotes when possible (`sed s/old/new/ file`), or with double quotes when spaces are needed (`sed "s/; old/ new/" file`). Always recommend `-f script.sed` as the most reliable approach for complex expressions.

**Impact on testing:** The FS-UAE test harness passes arguments directly via ARexx `ADDRESS COMMAND`, bypassing shell quoting entirely. This means quoting issues are invisible to the test suite. Consider adding `-f` script file tests for expressions that would need quoting in real usage. Discovered via user report on sed port (2026-03-25).

## atexit Cleanup of getline() Buffer Requires NULL After free()

When using `getline()` with a static tracking pointer for atexit cleanup (the standard pattern for catching err() exit paths), the tracking pointer MUST be set to NULL after `free(p)` in the normal path. Otherwise, atexit cleanup calls `free()` on an already-freed pointer -- a double-free.

On Unix this is undefined behavior that often silently succeeds. On AmigaOS it is **always fatal**: Guru Meditation `8100 0005` (AN_MemCorrupt) -- non-recoverable memory list corruption requiring a hard reboot.

The bug is especially insidious in programs that process multiple files sequentially (e.g., `rev file1 file2`): the first `rev_file()` call frees the buffer but leaves the static pointer dangling. The second call allocates a new buffer and overwrites the pointer. After both calls complete, atexit frees the (already freed) second buffer.

**Fix:** Always NULL the tracking pointer after free:
```c
free(p);
getline_buf = NULL;  /* prevent double-free in atexit cleanup */
```

Discovered in the rev 1.16 port -- multi-file invocations crashed with AN_MemCorrupt.

## libnix snprintf %g Precision Must Not Exceed 15

libnix's `snprintf` with `%g` format does not properly strip trailing zeros when precision exceeds ~15 digits. `%.30g` of `1.0` produces `1.0000000000` instead of `1`. `%.15g` works correctly.

This is because IEEE 754 double has ~15.9 significant decimal digits. Beyond 15 digits, the representation noise in the least significant bits becomes visible, and libnix's `%g` formatter doesn't suppress the trailing zeros that result.

**Fix:** Any `%g` format string with precision > 15 should be reduced to `%.15g`. This is the maximum meaningful precision for a 64-bit double.

**Detection:** `grep -rn '%\.\(1[5-9]\|[2-9][0-9]\)g' ported/*.c`

Discovered in the awk port -- upstream uses `%.30g` for integer formatting. Outputs like `1.0000000000` and `6765.00000000000056840000000000` were initially misdiagnosed as a libnix `%g` bug and FP accumulation errors respectively. See crash-patterns #20.

## vamos GetVar() Returns 0 for Missing Variables

On real AmigaOS, `GetVar()` returns -1 when a variable does not exist. On vamos, `GetVar()` returns **0** (not -1) and writes an empty string to the buffer. Code that checks `len < 0` to detect missing variables will fall through to the `else` branch and use an empty string instead of a fallback default.

**Fix:** Always check `len <= 0` (not `len < 0`) when using `GetVar()` to detect missing environment variables:
```c
len = GetVar((CONST_STRPTR)"VARNAME", (STRPTR)buf, bufsize - 1, 0);
if (len <= 0) {
    /* Variable not set or empty -- use default */
    strcpy(buf, "default");
} else {
    buf[len] = '\0';
}
```

This affects `amiport_getenv()` (which already handles it by returning NULL for len < 0 -- but len=0 returns an empty malloc'd string) and any new shim functions using `GetVar()` directly.

Discovered in the POSIX shim batch extension (2026-03-25) -- `amiport_gethostname()` returned an empty string on vamos instead of the "amiga" fallback.

## FS-UAE Test Expressions With Quotes Must Use -f Filter Files

The ARexx test harness passes CMD lines via `ADDRESS COMMAND`, which goes through AmigaDOS command parsing. Escaped double quotes (`\"`) inside inline expressions do NOT survive this path — they get stripped or misinterpreted.

This affects any program that takes expression arguments containing quotes: jq (`test("pattern")`), sed (`s/"old"/"new"/`), awk (`{print "hello"}`), grep (`-e "pattern"`).

**Fix for tests:** Write the expression to a filter file and use `-f`:
```
# WRONG — quotes stripped by AmigaDOS
CMD: WORK:jq ".text | test(\"Hello\")" WORK:input.txt

# RIGHT — filter file preserves quotes
CMD: WORK:jq -f WORK:test-filter.txt WORK:input.txt
```

Where `test-filter.txt` contains: `.text | test("Hello")`

This is invisible to the vamos test suite (which pipes directly without ARexx), so tests pass on vamos but fail on FS-UAE. Discovered in jq 1.7.1-2 regex tests.

## AmigaDOS Escaped Quotes in Execute Scripts Do Not Work

AmigaDOS `Execute` does not handle escaped quotes (`\"`) inside double-quoted strings the way Unix shells do. A CMD line like `awk "BEGIN { print toupper(\"hello\") }"` will fail because AmigaDOS sees the backslash-quote sequence as literal characters, not as an escaped quote.

This affects ALL test harness CMD lines and any program arguments that contain quotes. The ARexx test harness runs commands via `Execute scriptfile`, which processes the command through the AmigaDOS shell parser.

**Fix:** For awk, sed, and any program that takes program text as an argument, ALWAYS put the program in a file and use `-f`:
```
# BAD -- escaped quotes break on AmigaDOS
CMD: WORK:awk "BEGIN { print toupper(\"hello\") }"

# GOOD -- program in .awk file, no quoting issues
CMD: WORK:awk -f WORK:test-awk-toupper.awk WORK:test-empty.txt
```

This applies to: awk programs, sed expressions with quotes, grep patterns with quotes, and any argument containing literal quote characters.

Discovered in the awk port -- 55 inline awk programs with escaped quotes all returned RC=2 (syntax error) on FS-UAE while working fine natively.

## libnix dirname() Is Buggy -- Use Local Implementation

libnix's `dirname()` from `<libgen.h>` has two bugs:

1. **2-character paths**: `dirname("/a")` returns `"/a"` instead of `"/"`. Fails to strip single-character filename components from root. Affects all paths of the form `/<single-char>`.
2. **Consecutive slashes**: `dirname("/usr//bin")` returns `"/usr/"` instead of `"/usr"`. Does not collapse double slashes before processing.

These are POSIX compliance failures. The bugs are in libnix's C library implementation, not in any shim code.

**Fix:** Do NOT use libnix `dirname()`. Implement a local POSIX-correct version using a static buffer (safe -- AmigaOS is single-threaded). See `ports/dirname/ported/dirname.c` for the `amiport_dirname()` reference implementation (~50 lines). The algorithm follows POSIX.1-2008 step-by-step: strip trailing slashes, strip trailing non-slash component, strip trailing slashes again, handle edge cases.

**Note:** libnix `basename()` works correctly AND is Amiga-aware (treats `:` as a path separator alongside `/`). Only `dirname()` is buggy.

Discovered in the dirname 1.17 port (2026-03-25) -- FS-UAE tests caught the discrepancy on `/x` and `/usr//bin` paths.

## Macro-Controlled Large Buffers Hide Stack Overflows

When a local buffer's size is controlled by a macro defined in a header file (e.g., `char table[TABSIZE]` where `TABSIZE` is `256*1024` in a separate `.h`), the stack overflow risk is invisible at the declaration site. The developer sees `table[TABSIZE]` and doesn't realize it's 256KB. With `__stack=16384`, the first call to that function is a guaranteed Guru Meditation.

**Fix:** During code review of ANY local array, expand the size macro mentally or with `grep`. If size > 512 bytes, make the buffer `static` (safe on single-threaded AmigaOS for non-recursive functions) or heap-allocate. The `__stack` cookie value is the hard ceiling — subtract 8KB for AmigaOS hidden depth.

**Rule of thumb:** `sizeof(local_buffer) + 8192 < __stack` must hold for every function in the call chain.

Discovered in factor 1.30 (2026-03-26) -- `TABSIZE=256*1024` in `primes.h` caused a 256KB stack allocation in `pr_bigfact()` with only 16KB `__stack`.

## Console-Shim tgetnum() Returns Hardcoded 80x24

`tgetnum("li")` and `tgetnum("co")` in `lib/console-shim/src/term.c` return `LINES` and `COLS` globals from `globals.c`, which are initialized to 24 and 80 respectively and **never updated**. Meanwhile, `amiport_ioctl(TIOCGWINSZ)` in `lib/posix-shim/src/file_io.c` correctly queries the actual console window size via CSI `0 q` window status request. But the termcap code path never calls this — it just returns the stale defaults.

**Impact:** All termcap programs (tetris, less, mg) render in an 80x24 box even when the Amiga shell window is larger. The game board or text area only fills the top-left portion of a bigger window.

**Fix (not yet applied):** `tgetent()` or a new `amiport_console_query_size()` function should send the same CSI `0 q` query that `amiport_ioctl` uses, parse the response, and update `COLS`/`LINES` globals. Programs that call `ioctl(TIOCGWINSZ)` work around this (the struct gets correct values), but programs using only `tgetnum` get stale 80x24.

**Workaround for ports:** If a port calls `ioctl(TIOCGWINSZ)` and uses the result, it gets real dimensions. If it only calls `tgetnum("co")`/`tgetnum("li")`, it gets 80x24. Tetris calls both — ioctl overrides tgetnum — but the board is hardcoded to 20 rows so the extra space is still empty.

Discovered across multiple Cat 3 ports (less, mg, tetris) on 2026-03-26.

## Do NOT Open("*") in Library Init Code (Console Handle Disruption)

`Open("*", MODE_OLDFILE)` opens a direct handle to the current console window. This was attempted as a fallback in `tgetent()` when `Input()` is non-interactive (Execute script launches). **It destabilized the ITEST harness** — crash rate jumped from 3 missed tests to 12 missed tests. The `Open("*")` / `Close("*")` during library initialization disrupts the console handle state for programs launched via `Run >clinumfile Execute scriptfile`.

**Rule:** Never call `Open("*")` in shim or console-shim library initialization functions (`tgetent()`, `setupterm()`, `initscr()`). These run early in program startup when the console handle lifecycle is fragile, especially under the ITEST harness. Programs that need `"*"` should open it explicitly in their own code (like the less port does in `ttyin.c`), not have it opened implicitly by a library call.

Discovered in the tetris 1.35 port (2026-03-26) — attempted fix for window size detection was reverted.

## Bare `<err.h>` Does Not Exist in bebbo-gcc

bebbo-gcc libnix does not ship `<err.h>`. Any ported source with `#include <err.h>` will fail with `fatal error: err.h: No such file or directory`. The code-transformer MUST replace bare `<err.h>` with `<amiport/err.h>`. Also provides `strtonum()`, `errc()`, `warnc()` macros.

Discovered in the tetris 1.35 port (2026-03-26) -- screen.c had a bare `<err.h>` that survived the initial transform.

## Static Local Buffers in Helper Functions Must Be Global for atexit Cleanup

When a helper function (e.g., `input()`, `fold()`, `slurp()`) allocates memory via `static` local variables or `getline()`, the `cleanup()` function registered via `atexit()` has NO visibility to free those allocations. On AmigaOS with `-noixemul`, these are permanent leaks -- there is no OS-level process memory cleanup.

**Common patterns that leak:**
- `static char *buf = NULL;` inside a function, grown by `malloc`/`realloc`/`getline`
- `strdup()` results stored in globals but not tracked for cleanup
- `obsolete()` argv rewrite pattern (malloc strings into argv)

**Fix:** Promote ALL dynamic allocations to file-scope globals so `cleanup()` can free them. Use `#define buf global_buf` inside the function to minimize code changes. Track `strdup()` results and `obsolete()` mallocs in global arrays.

**This is NOT optional.** Every port must have ALL dynamic allocations reachable from `cleanup()`. The memory-checker agent will flag this, but the code-transformer MUST apply this pattern during initial transformation -- do not defer to review.

Discovered in 10-port batch (2026-03-26) -- fold, join, column, expr all had unreachable allocations. 4 out of 10 ports failed memory audit on first pass.

## AmigaDOS Volume Requester on Path Probing — Suppress pr_WindowPtr

Any AmigaDOS `Lock()` or `Open()` call on a bare name (e.g., `"vim"`) triggers a system requester: "Please insert volume vim in any drive." This happens because AmigaDOS interprets any name without `/` or `:` as a potential volume reference. Programs that probe multiple paths during startup (editors, shells, interpreters) will pop up requesters for each non-existent path component.

This affects both direct AmigaDOS calls AND libnix `fopen()`/`stat()` which call `Lock()`/`Open()` internally. Fixing only the ported code's Lock() calls is insufficient — libnix paths also trigger it.

**Fix:** Suppress requesters globally at process startup:
```c
/* In the program's init function (e.g., mch_init for vim): */
struct Process *me = (struct Process *)FindTask(NULL);
me->pr_WindowPtr = (APTR)-1L;
```

`pr_WindowPtr = -1` is the ADCD-documented approach (see `dos.library/ErrorReport`). It causes all system requesters (volume insert, disk write-protected, etc.) to return failure immediately instead of prompting the user. This is appropriate for CLI tools that should handle errors programmatically.

For individual Lock() calls, use a save/restore wrapper:
```c
static BPTR safe_Lock(UBYTE *name, long mode) {
    struct Process *me = (struct Process *)FindTask(NULL);
    APTR oldwin = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1L;
    BPTR flock = Lock(name, mode);
    me->pr_WindowPtr = oldwin;
    return flock;
}
```

Discovered in the vim 9.1 port (2026-03-26) — vim probes `$VIM`, `$VIMRUNTIME`, `defaults.vim`, multiple vimrc locations during startup. Each non-existent path triggered a "Please insert volume" requester. The global suppression in `mch_init()` was the only complete fix because libnix's `fopen()` also calls Lock() internally.

## Large Binary ITEST OOM — 2.7MB vim Exhausts 8MB Fast RAM

Interactive tests (ITEST: blocks) spawn a new shell process per test via `Run`. Each process loads the full binary into memory. For large binaries (vim at 2.7MB), 3 ITEST launches in 8MB fast RAM cause "not enough memory available" on the 3rd launch, even if previous instances exited — AmigaOS memory fragmentation prevents reuse of contiguous blocks.

**Fix:** Limit ITESTs to 2-3 for binaries >1MB. Use `-c` command tests for non-interactive functionality instead. Document additional interactive tests in PORT.md manual checklist.

Discovered in the vim 9.1 port (2026-03-26) — first 2 ITESTs passed, 3rd got OOM.

## No /dev/urandom on AmigaOS -- Programs Needing Entropy Crash at Startup

Programs that use `getrandom()`, `getentropy()`, or read `/dev/urandom` for random seed initialization will crash or fail at startup on AmigaOS. There is no kernel entropy source. Common symptom: `failed to get random numbers` or similar fatal error during initialization.

**Fix:** Provide an `#ifdef __AMIGA__` path that seeds from available sources: `clock()`, `time()`, stack address (ASLR-like), `DateStamp()` ticks. Use a simple LCG to stretch these into a buffer of pseudo-random bytes. Not cryptographically secure but sufficient for hash randomization, temp filenames, and non-crypto PRNG.

**Pattern:**
```c
#ifdef __AMIGA__
{
    unsigned char *buf = (unsigned char *)buffer;
    unsigned long seed = (unsigned long)&buf;  /* stack address */
    seed ^= (unsigned long)clock() * 2654435761UL;
    seed ^= (unsigned long)time(NULL) * 1103515245UL;
    for (i = 0; i < size; i++) {
        seed = seed * 1103515245UL + 12345UL;
        buf[i] = (unsigned char)(seed >> 16);
    }
    return 0;
}
#endif
```

**Affected programs:** CPython (hash randomization), any program using OpenBSD `arc4random()`, programs seeding `srand()` from `/dev/urandom`.

Discovered in the CPython 3.11 port (2026-03-26) -- `_Py_HashRandomization_Init` called `pyurandom()` which fell through to `dev_urandom()` which tried to open `/dev/urandom`.

## vamos Needs -C 68020 for 68020+ Binaries

vamos defaults to 68000 CPU emulation. Binaries compiled with `-m68020` (like vim, python3) will crash with `ALERT: code=00068020` — an illegal instruction trap when the 68000 emulator hits a 68020-only opcode. **Fix:** Pass `-C 68020` to vamos. In Makefiles: `VAMOS_CPU = 68020` and add `-C $(VAMOS_CPU)` to vamos invocations. The existing `-m68000` rule for libraries (crash-patterns) is the inverse: libraries must use `-m68000` so they work on vamos's default CPU, but port binaries that intentionally target 68020+ must tell vamos to emulate that CPU.

Note: vamos also has a 24-bit address space limit. Binaries larger than ~3MB (like CPython at 3.06MB) need `-m 4096` or more for memory, but cannot use `-m 16384` (too much for 24-bit).

Discovered in the CPython 3.11 port (2026-03-26).

## libnix -noixemul Has Native POSIX fd Functions — Use Them for Large Ports

bebbo-gcc's libc.a (newlib-based, `-noixemul`) provides `open()`, `close()`, `read()`, `write()`, `lseek()`, `fdopen()`, `fileno()`, `fopen()`, `fclose()` in a **unified fd table**. `open()` returns fd=3+ (after stdin=0, stdout=1, stderr=2), and `fdopen()` works correctly on those fds. `fileno(stdin)` returns 0.

This means **the fd namespace conflict (crash-patterns #12) only applies when mixing `amiport_open()` with libnix's `fdopen()`/`fileno()`**. For large ports like CPython that use raw POSIX fd operations extensively, use libnix's native `open()`/`read()`/`write()` directly instead of `amiport_open()`. Only use amiport shims for functions libnix doesn't provide (stat, getenv, signal, time, directory ops).

**When to use which:**
- **Small ports using `fopen()`/`fclose()` only:** libnix native (default). No shim needed for file I/O.
- **Ports that use `open()`/`fdopen()` together:** libnix native — they share a fd table.
- **Ports that need `amiport_stat()` on an open fd:** Use `amiport_fstat()` with amiport fds, OR use libnix's `fstat()` with libnix fds. Don't cross namespaces.
- **Legacy ports already using `amiport_open()`:** Keep using `amiport_read()`/`amiport_write()`/`amiport_close()` consistently. Don't mix with libnix `fdopen()`.

Discovered during CPython 3.11 feasibility analysis (2026-03-26) — empirical vamos test confirmed `open()` + `fdopen()` interop works on bebbo-gcc libc.a.

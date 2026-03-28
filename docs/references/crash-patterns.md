# Crash Pattern Knowledge Base

This file stores structured crash signature to fix pattern entries used by the `debug-agent` to accelerate crash diagnosis. When the debug agent fixes a crash, it appends a new entry here. Over time this becomes a lookup table — the agent checks this KB before reasoning from scratch.

See ADR-016 for the autonomous debug agent architecture.

---

## 1. NULL Struct Member Access

**Enforcer Signature:** Address < `0x1000`. Typically a small offset from NULL (e.g., `0x00000014` for the 5th long field of a struct accessed via a NULL pointer).

**Hit Type:** `LONG-READ`, `WORD-READ`, or `BYTE-READ` from a low address.

**Root Cause:** A function returns NULL (e.g., failed allocation, failed lookup) and the caller dereferences the result without checking. The faulting address is the struct field offset from the NULL base pointer.

**Fix Template:**
```c
/* Before (crashes if find_node returns NULL): */
struct node *n = find_node(key);
printf("%s\n", n->name);

/* After: */
struct node *n = find_node(key);
if (n == NULL) {
    fprintf(stderr, "error: node not found for key '%s'\n", key);
    exit(10);  /* amiport: RETURN_ERROR */
}
printf("%s\n", n->name);
```

**Diagnostic Clue:** The offset in the Enforcer address reveals which struct field was accessed. Cross-reference with the struct definition to identify the field (e.g., offset `0x14` = 20 bytes = 5th `LONG` field or a field after shorter members).

**Example Port:** TBD

---

## 2. Use-After-Free (Mungwall Sentinel)

**Enforcer Signature:** Address is a Mungwall sentinel value:
- `0xDEADBEEF` — freed memory (Mungwall fills freed blocks with this)
- `0xABADCAFE` — pre-fill pattern (Mungwall fills allocated blocks before first use)
- `0xCCCCCCCC` — uninitialized memory (some allocators use this)

**Hit Type:** Any read or write to a sentinel address.

**Root Cause:** A pointer to a freed memory block is used after `free()` was called, or a pointer to freshly allocated memory is used before initialization. Mungwall fills freed/allocated memory with sentinel values, turning silent corruption into a detectable Enforcer hit.

**Fix Template (use-after-free):**
```c
/* Before (use-after-free): */
free(node);
/* ... other code ... */
printf("%s\n", node->name);  /* CRASH: node memory is 0xDEADBEEF */

/* After: */
free(node);
node = NULL;  /* amiport: NULL after free to catch reuse */
/* ... other code ... */
if (node != NULL) {
    printf("%s\n", node->name);
}
```

**Fix Template (uninitialized):**
```c
/* Before (uninitialized pointer in struct): */
struct context ctx;
/* forgot to set ctx.buffer */
memcpy(ctx.buffer, src, len);  /* CRASH: ctx.buffer is 0xABADCAFE */

/* After: */
struct context ctx;
memset(&ctx, 0, sizeof(ctx));  /* amiport: zero-init struct */
ctx.buffer = malloc(len);
if (ctx.buffer == NULL) {
    fprintf(stderr, "error: out of memory\n");
    exit(20);  /* amiport: RETURN_FAIL */
}
memcpy(ctx.buffer, src, len);
```

**Diagnostic Clue:** The specific sentinel value identifies the category. `0xDEADBEEF` means the memory was freed — search for `free()` calls on that pointer. `0xABADCAFE` means the memory was allocated but never written — search for missing initialization.

**Example Port:** TBD

---

## 3. Stack Overflow

**Enforcer Signature:** Crash occurs during deep recursion or in a function with large local arrays. The Enforcer hit may show access to an address near the end of the stack region, or (more commonly) the crash manifests as a Guru Meditation (alert) rather than a clean Enforcer hit because the stack overflows into unmapped memory.

**Hit Type:** `Alert` (Guru Meditation), or `LONG-WRITE`/`LONG-READ` to an address near the task's stack base. Enforcer's `STACKCHECK` option (requires SegTracker) annotates stack longwords to help identify stack-related crashes.

**Root Cause:** The Amiga default stack is 4KB. Ported POSIX programs often assume much larger stacks (Linux default is 8MB). Deep recursion (e.g., directory traversal, expression parsing) or large local arrays (e.g., `char buf[PATH_MAX]` where `PATH_MAX` is 4096) overflow the stack.

**Fix Template (increase stack cookie):**
```c
/* Add or increase the stack cookie at file scope: */
long __stack = 65536;  /* amiport: 64KB stack for recursive program */

/* For extremely deep recursion, use 131072 (128KB) */
```

**Fix Template (reduce stack usage):**
```c
/* Before (large local array on stack): */
void process(void) {
    char buffer[8192];  /* 8KB on stack — dangerous */
    /* ... */
}

/* After (allocate on heap): */
void process(void) {
    char *buffer = malloc(8192);
    if (buffer == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(20);  /* amiport: RETURN_FAIL */
    }
    /* ... */
    free(buffer);
}
```

**Diagnostic Clue:** If the crash happens in a recursive function or a function with large local variables, suspect stack overflow. Check the `__stack` cookie value — if it is missing (defaults to 4KB) or too small for the recursion depth, increase it. If the program uses `alloca()` or variable-length arrays, convert to heap allocation.

**Example Port:** TBD

---

## 4. Silent Wrong Results from st_dev/st_ino Comparison

**Enforcer Signature:** None — this bug produces **wrong output, not a crash**. No Enforcer hits. The program runs cleanly but gives incorrect results.

**Symptom:** Program treats different files as identical, skips comparisons, or reports "no differences" when files clearly differ.

**Root Cause:** Many POSIX programs compare `st_dev` and `st_ino` to detect whether two file paths refer to the same underlying file (hardlinks, symlinks). If the stat shim returned stub values (0 for both), all files on the same volume appeared to be the same file.

**Detection:** This is a **logic bug**, not a memory error. Enforcer won't catch it. Detect by:
- Running the program with files that should produce visible output and getting silence instead
- Searching the ported source for `st_dev` and `st_ino` comparisons
- `grep -n 'st_dev.*st_ino\|st_ino.*st_dev' ported/*.c`

**Fix:** Fixed at the shim level (March 2026) — `amiport_stat()` now populates:
- `st_ino` from `fib_DiskKey` (filesystem block number, unique per file on a volume)
- `st_dev` from `GetDeviceProc()->dvp_Port` (unique per mounted volume)

No per-port fix needed if using the current shim. For legacy ports built before this fix, add `#ifdef __AMIGA__` to skip the inode comparison.

**Programs Known to Be Affected:** Any program with `files_differ()`, `same_file()`, or similar logic: diff, cmp, cp, rsync, tar.

**Example Port:** diff (OpenBSD v1.95) — `diffreg.c:449`

## 5. vsnprintf(NULL, 0, ...) Crash

**Enforcer Signature:** `LONG-WRITE` to address `0x00000000` or very low address. Crash occurs inside `vsnprintf` or `vsprintf`.

**Symptom:** Program crashes immediately on startup or first string formatting operation. The crash happens inside a `vsnprintf(NULL, 0, fmt, ap)` call used to measure the required buffer size.

**Root Cause:** C99 specifies that `vsnprintf(NULL, 0, fmt, ap)` is valid and returns the number of characters that would have been written. However, libnix's `vsnprintf` does NOT support NULL as the destination buffer — it unconditionally writes to the pointer, causing a NULL dereference on the 68000.

This pattern commonly appears when replacing `vasprintf()` (which doesn't exist in libnix) with a two-pass vsnprintf approach. The code-transformer or developer writes `vsnprintf(NULL, 0, ...)` as the "measure" pass, not realizing libnix doesn't support it.

**Fix Template (use probe buffer):**
```c
/* WRONG — crashes on libnix: */
int len = vsnprintf(NULL, 0, fmt, ap);

/* CORRECT — use a probe buffer: */
char probe[1024];
int len = vsnprintf(probe, sizeof(probe), fmt, ap);
/* vsnprintf returns total chars that WOULD be written, even if truncated */
```

The 1024-byte probe buffer is sufficient because `vsnprintf` returns the full required length regardless of truncation. The subsequent allocation and second `vsnprintf` call will use the correct size.

**Detection:** Search for `vsnprintf(NULL` or `snprintf(NULL` in ported source:
```
grep -n 'vsnprintf(NULL\|snprintf(NULL' ported/*.c
```

**Programs Known to Be Affected:** Any program that uses `vasprintf()` or `asprintf()` — these are replaced during transformation and the replacement code must avoid the NULL pattern.

**Example Port:** diff (OpenBSD v1.95) — `xmalloc.c:xasprintf()`

---

## 6. amiport_fopen Sentinel BPTR Heap Corruption (MungWall)

- **Enforcer signature:** MungWall detects a corrupted allocation sentinel. Stack trace shows `malloc` / `fdopen` / `lseek` from libnix on top, with tail's code in the mid-stack. `Hunk 0002 Offset <bss+N>` in the MungWall report pointing at the amiport fd_table BSS. Guru Meditation #80000004 (Illegal Instruction) or #80000008 (Address Error) follows.
- **Root cause:** `amiport_fopen` (triggered by `#include <amiport/stdio.h>` + `#define fopen amiport_fopen`) calls the real libnix `fopen`, then allocates a **fake fd table slot** with sentinel BPTR value `(BPTR)1` (physical address 4). Mixing this sentinel into the fd_table BSS next to libnix's malloc arena causes MungWall to flag corrupted allocation sentinels when libnix's own `fdopen`/`malloc` next scans its heap structures. The crash is a heap integrity violation, not a direct NULL dereference.
- **Fix applied:** Remove `#include <amiport/stdio.h>` from files that use `amiport_stat(fname, ...)` instead of `fstat(fileno(fp), ...)`. The `amiport/stdio.h` shim was added to fix a fileno fd-table mismatch, but that mismatch is better avoided by using filename-based stat. For stdin pipe detection, replace `fstat(fileno(stdin)) + lseek()` with `IsInteractive(Input())` from `<proto/dos.h>`.
- **Port:** tail (OpenBSD v1.24)
- **Date:** 2026-03-21

## 7. vamos Stack Overflow — __stack Cookie Ignored

**Enforcer Signature:** `InvalidMemoryAccessError` with SP in the `0xffff0000` range (e.g., `SP=ffff0060`). Write addresses descend by 2 bytes (`ff005e, ff005c, ...ff0044`). The crash address in 24-bit mode appears as `0x00ff00xx` (wrap of `0xffff00xx`).

**Hit Type:** `WRITE` at descending addresses. Often crashes inside `err()`/`strerror()` or another deep call chain, but the crash location is a symptom — the stack was exhausted long before.

**Root Cause:** vamos has a hardcoded 8KB default stack (`amitools/vamos/cfg/proc.py: "stack": 8`). It does NOT read the `__stack` cookie from the binary's DATA segment. Any program declaring `__stack > 8192` that actually uses more than 8KB will silently overflow the stack, corrupt heap/BSS memory, and eventually wrap the 32-bit SP through zero into the `0xffff0000` range where no memory is mapped.

The overflow is silent because vamos maps all 1MB of RAM (`0x001000`–`0x100000`) as writable — the stack can corrupt heap and binary data without triggering an access error until SP wraps past `0x00000000`.

**Detection:** Check for the characteristic SP range `0xffff00xx` and descending write addresses. Also check if the binary declares `__stack`:
```
m68k-amigaos-objdump -t <binary> | grep __stack
```

**Fix Template (vamos wrapper):**
```bash
# Pass -s <KB> to vamos for programs needing large stacks
vamos -s 128 -- ./program args    # 128KB stack

# The toolchain/scripts/vamos wrapper defaults to 128KB automatically
```

**Fix Template (Makefile test target):**
For programs needing more than the default, add a `VAMOS_STACK` variable:
```makefile
# diff needs ~130 KiB (FileInfoBlock + GetDeviceProc + probe buffers + algorithm)
VAMOS_STACK = 256
test:
	vamos -s $(VAMOS_STACK) -- ./$(TARGET) ...
```

**Diagnosis tip:** Binary-search the minimum stack by testing with `-s 64`, `-s 128`, etc. The crash PC is always in the same function but stack addresses shift with allocation size.

**Programs Known to Be Affected:** Any port with `__stack > 8192` — especially recursive programs (diff, find), programs with large local arrays, and programs with deep call chains. Programs using AmigaDOS Lock/Examine/GetDeviceProc need extra stack beyond what the C code appears to use.

**Example Port:** diff (OpenBSD v1.95) — needed ~130 KiB minimum (72 KiB for basic diff, 144 KiB for identical-file exit path), using 256 KiB for safety with recursive `-r` mode.

---

## 8. FileInfoBlock Alignment — DOS Recoverable Alert (not Enforcer hit)

### Stack-allocated FileInfoBlock causes dos.library Address Error on 68000

- **Enforcer signature:** None — no Enforcer hits. The crash manifests as a **Recoverable Alert** with an address like `0x0100 000F` (type `0x0100` = recoverable, code `0x000F` = 15 = `ERROR_OBJECT_WRONG_TYPE` or address error in DOS). No memory access violation visible to Enforcer because the Address Error trap fires inside the ROM before Enforcer can intercept it.
- **Symptom:** Program crashes with "Error: 0100 000F Task: XXXXXXXX" immediately on file access. ARexx test harness shows `1..N` declared but zero `ok`/`not ok` lines — the binary crashed before producing any output.
- **Root cause:** `struct FileInfoBlock` (260 bytes) must be **longword-aligned** (4-byte boundary) when passed to `Examine()`, `ExamineFH()`, or `ExNext()`. The AmigaOS dos.library performs longword-sized reads on the FIB and will trap with an Address Error on a 68000 if the FIB is at an odd or word-aligned address. With `-m68000` and gcc's default stack layout, stack-allocated structs may only receive 2-byte alignment, causing this trap. The 68000 does not have an MMU, so Enforcer cannot see the crash — it fires as a CPU exception inside the ROM.
- **Fix applied:** Replace `struct FileInfoBlock fib;` (stack allocation) with `AllocDosObject(DOS_FIB, NULL)` in `amiport_stat()` (stat.c) and `amiport_fstat()` (file_io.c). `AllocDosObject` allocates from chip/fast RAM with guaranteed longword alignment and zero-initialises the FIB. Free with `FreeDosObject(DOS_FIB, fib)` when done. Note: `opendir()` in dir_ops.c uses `AllocVec(sizeof(AMIPORT_DIR), MEMF_PUBLIC|MEMF_CLEAR)` which already guarantees alignment — the FIB embedded in `struct _AMIPORT_DIR` is safe.
- **Detection grep:** `struct FileInfoBlock [a-z]` — any stack-allocated FIB in shim code.
- **Port:** tail (OpenBSD v1.24) — crash on first file argument (`WORK:tail WORK:test-tail-input.txt`)
- **Date:** 2026-03-21

---

### #9: ~~libnix exit() hangs on AmigaOS console~~ DEBUNKED

- **Status:** DEBUNKED — exit() works correctly on FS-UAE + Workbench 3.1 with libnix.
- **Original claim:** libnix's `exit()` hangs when stdout is connected to a console.
- **Actual root cause of observed hangs:** ARexx syntax errors in test-runner.rexx:
  1. UTF-8 em dashes (U+2014) in comments — ARexx is ASCII-only (1987 interpreter)
  2. `\=` (not-equal) operator not recognized by ARexx 1.15 — use `~=` instead
- **How it was debunked:** Built two test programs — one with `exit(0)`, one with `_exit(0)`. Both return to the shell prompt immediately on FS-UAE. No hang observed.
- **Impact:** An `amiport_exit()` shim was created and `#include <amiport/stdlib.h>` transformation added. Both are harmless (amiport_exit calls _exit which works identically to exit on this system) and remain in place to avoid churn. No port functionality was affected.
- **Lesson:** Always verify crash patterns empirically with minimal test programs before building infrastructure to work around them. The ARexx harness failure was misattributed to exit() because the timeout diagnosis heuristic matched ("source has exit() without _exit()").
- **Date:** 2026-03-21 (original), 2026-03-22 (debunked)

---

## 10. ACPU_LineF from Hidden Stack Overflow via Large Local Buffer

### Stack Budget vs Real AmigaOS Call Depth

- **Enforcer signature:** `ACPU_LineF` alert `0x8000000B` on FS-UAE/real AmigaOS. Program works correctly on vamos with SAME or SMALLER stack. No Enforcer hits (crash is a CPU exception, not an Enforcer-monitored memory access).
- **Root cause:** A large local array (e.g., `char buf[4096]`) in a frequently-called function creates a large stack frame. On vamos, call chains are shorter (vamos implements AmigaOS APIs directly without real library dispatch layers). On real AmigaOS, the same call chain consumes significantly more stack due to:
  - dos.library dispatching through the filesystem handler (packet passing, handler process interaction)
  - console.device buffer management
  - AmigaOS library vector dispatch overhead
  - The difference is typically 2-4KB of additional hidden stack depth not visible from static analysis.
  When the real stack exhausts, a saved return address is corrupted. If the corrupt address points to data bytes beginning with `0xF`, the 68000 executes an F-line trap (exception vector 11), which AmigaOS catches and reports as `Alert(ACPU_LineF) = 0x8000000B`.
- **Why vamos doesn't crash:** vamos ignores the `__stack` cookie and uses a hardcoded 8KB stack (crash-patterns #7). On vamos, `fgets → getc → ___srget → read()` never calls real AmigaOS filesystem code — vamos intercepts at the system call level with minimal stack usage.
- **Diagnostic clue:** Program crashes on FS-UAE but passes on vamos. The crash alert is `ACPU_LineF (0x8000000B)`. The binary has no F-line instructions (verified via `m68k-amigaos-objdump -d`). The crash location is in a function with a large local array.
- **Fix applied:** Two-part fix:
  1. Change `char buf[N]` (stack) to `static char buf[N]` (BSS). Safe when the function is not called recursively or from multiple threads (AmigaOS is single-threaded per process). The GCC frame shrinks from `link.w a5,#-N` to `link.w a5,#0`.
  2. Increase `__stack` from `16384` to `65536` as insurance against other hidden stack consumers.
- **Port:** head (OpenBSD v1.24)
- **Date:** 2026-03-22

## 11. Silent Wrong Output from MB_CUR_MAX Runtime Expansion

### Multibyte Guard Must Cover the Conditional, Not Just the Code Path

- **Signature:** No crash — program produces wrong output (typically all zeros) for a specific flag. Only manifests when the multibyte code path is compiled out with `#ifndef __AMIGA__` but the flag that enables it is still evaluated at runtime.
- **Root cause:** In bebbo-gcc libnix, `MB_CUR_MAX` is defined as `__locale_mb_cur_max()` — a **runtime function call**, not a compile-time constant. It may return >1 even without locale support. When source code has:
  ```c
  if (MB_CUR_MAX > 1)
      multibyte = 1;
  /* ... later ... */
  if (!multibyte) {
      /* single-byte counting logic */
  }
  #ifndef __AMIGA__
  else {
      /* multibyte logic using wchar.h — compiled out */
  }
  #endif
  ```
  The `MB_CUR_MAX > 1` check fires at runtime, setting `multibyte = 1`. The `if (!multibyte)` block is skipped. The `else` block is compiled out. **Neither path executes** — output is zero.
- **Diagnostic clue:** One flag produces wrong output (zeros) while a different flag with identical code path works. The broken flag has an `MB_CUR_MAX` conditional before it. vamos and FS-UAE both show the bug.
- **Fix:** Guard the `MB_CUR_MAX` check itself, not just the multibyte code path:
  ```c
  #ifndef __AMIGA__
  if (MB_CUR_MAX > 1)
      multibyte = 1;
  #endif
  ```
- **General rule:** For any POSIX macro used in conditionals (`MB_CUR_MAX`, `PATH_MAX`, `BUFSIZ`), check the actual expansion in bebbo-gcc — it may be a function call, not a constant.
- **Port:** wc (OpenBSD v1.32)
- **Date:** 2026-03-22

## 12. Silent Empty Output from amiport_open() + fdopen() Mismatch

### amiport fd Table Is a Separate Namespace from libnix fds

- **Signature:** No crash — program exits RC=0 (success) but produces **no stdout output** when given file arguments. Piped stdin works correctly. The `-o` flag (direct file output via fopen) may also work, making the bug intermittent-looking.
- **Root cause:** `amiport_open()` returns file descriptors from amiport's **internal fd table** (backed by AmigaDOS `Open()` BPTRs). `fdopen()` is a **libnix function** that expects libnix file descriptors (a completely separate fd table). Passing an amiport fd to `fdopen()` creates a `FILE*` that does not read from or write to the actual file — it silently operates on the wrong (or no) underlying handle.
- **Diagnostic clue:** Program works with stdin piping but not with file arguments. No error messages. RC=0. The `fdopen()` call itself may appear to succeed (returns non-NULL) but the resulting FILE* is broken.
- **Why it's hard to spot:** vamos may mask this if testing only with piped stdin. FS-UAE tests with file arguments will expose it (empty actual output for all output-checking tests, but RC-only tests pass).
- **Fix:** Never combine `amiport_open()` with `fdopen()`. Use `fopen()` (which goes through libnix's own fd management) for any code that needs a `FILE*`:
  ```c
  /* WRONG — amiport fd + libnix fdopen = broken FILE* */
  int fd = amiport_open(path, O_RDONLY);
  FILE *fp = fdopen(fd, "r");  /* fp reads from wrong/no handle */

  /* RIGHT — fopen goes through libnix, correctly maps to AmigaDOS */
  FILE *fp = fopen(path, "r");  /* works correctly */
  ```
  For output files:
  ```c
  /* WRONG */
  int fd = amiport_open(path, O_WRONLY|O_CREAT|O_TRUNC);
  FILE *fp = fdopen(fd, "w");

  /* RIGHT */
  FILE *fp = fopen(path, "w");
  ```
- **When amiport_open() IS correct:** When using raw fd I/O (`amiport_read()`, `amiport_write()`, `amiport_close()`) — these all use the amiport fd table consistently. The bug only occurs when crossing the boundary into libnix stdio.
- **Scope:** This affects **any port** that uses the pattern `amiport_open()` + `fdopen()`. Check all existing ports.
- **Alternative:** For large ports that need unified fds (e.g., CPython), use libnix's native `open()`/`read()`/`write()`/`fdopen()`/`fileno()` directly — they share a single fd table. bebbo-gcc's libc.a (newlib-based) provides all POSIX fd functions. Only use `amiport_open()` when you also need `amiport_stat()`/`amiport_fstat()` on the same fd. See known-pitfalls.md "libnix Has Native POSIX fd Functions."
- **Port:** sort (Plan 9)
- **Date:** 2026-03-22

---

## ROM Interrupt Handler False Positives (NOT a crash pattern)

**Enforcer Signature:** `LONG-WRITE to 00F0FFFC data=00000013 PC: 00F00408`, Name: "Processor Interrupt Level 3"

**This is NOT a bug.** This is the Kickstart ROM interrupt handler writing to the CIAB interrupt control register. It appears on every Amiga system running Enforcer and is harmless. All stack traces will show ROM code (exec, dos, input.device).

**How to identify:** All hits have identical PC (`00F00408`), identical target (`00F0FFFC`), and the Name field says "Processor Interrupt Level 3". There will be dozens or hundreds of these hits per test run.

**What to do:** Filter these out. Only count Enforcer hits where the PC is in user code (the port binary) or where the target address is below `0xF00000`. The `debug-report.py parse` command should filter these automatically.

---

## 13. -fbaserel Corrupts Global State in Large Programs

**Enforcer Signature:** Multiple `LONG-WRITE` hits at seemingly valid memory addresses during module initialization or global state access. Program may pass vamos tests but crash on real AmigaOS (FS-UAE). Hits appear during startup/initialization, not in user code paths.

**Hit Type:** `LONG-WRITE` — writes to wrong memory locations due to corrupted A4-relative addressing.

**Root Cause:** The `-fbaserel` GCC flag switches to A4-relative (small data model) addressing for global and static variables. This works for small programs but breaks programs with extensive global state (Lua has global registries, string caches, module tables, and function pointer arrays). The A4-relative offset table overflows or misaligns, causing writes to land at wrong addresses.

The flag was originally added to fix exit code 252 on vamos (libnix init list placement), but the real cause of exit 252 was a vamos-specific locale/math library initialization failure — unrelated to `-fbaserel`.

**Diagnosis Shortcut:** If a program:
1. Has many global/static variables or large global arrays
2. Passes vamos tests but crashes on FS-UAE with LONG-WRITE Enforcer hits
3. Was compiled with `-fbaserel`

→ Remove `-fbaserel` and retest. This is almost certainly the cause.

**Fix:** Remove `-fbaserel` from CFLAGS. If exit code 252 on vamos was the reason it was added, investigate the real cause (usually vamos library initialization, not init list placement).

**Scope:** Any program with >50 global/static variables or large global arrays. Small utilities (grep, sed, cal) are unlikely to be affected. Interpreters, compilers, and applications are high-risk.

- **Port:** lua (5.4.7)
- **Date:** 2026-03-22

---

## 14. Float Math Generates Line F Traps on 68000

**Enforcer Signature:** Guru Meditation `#8000000B` (ACPU_LineF). No Enforcer hits — this is a CPU trap, not a memory access violation.

**Hit Type:** Line F emulator exception. The 68000 encounters an opcode in the `$Fxxx` range (FPU instruction) and has no FPU to execute it.

**Root Cause:** Switching C `float` math functions (`sqrtf`, `powf`, `fmodf`, `floorf`, etc.) into a program compiled with `-m68000`. The 68000 has no FPU. AmigaOS provides software IEEE math only for `double` precision via `mathieeedoubbas.library` and `mathieeedoubtrans.library`. There is no `float`-precision equivalent. The GCC soft-float fallback for `float` still generates Line F traps in some code paths.

**Diagnosis Shortcut:** If a program:
1. Uses floating-point math
2. Is compiled with `-m68000` (no FPU)
3. Crashes with Guru `#8000000B` after changing float precision settings

→ Check for `float` vs `double` usage. Stick with `double` on 68000 targets.

**Fix:** Use `double` for all floating-point. On AmigaOS 68000 targets, do NOT enable `LUA_32BITS`, `-fsingle-precision-constant`, or any option that switches to `float` math.

**Exception:** Programs targeting 68020+ with 68881/68882 FPU can use `float` safely (`-m68020 -m68881`).

- **Port:** lua (5.4.7)
- **Date:** 2026-03-22

## 15. 68k Alignment=2 Corrupts Custom Allocator Data

### offsetof-Based Alignment Gives 2 on 68k Instead of 4/8

- **Signature:** Assertion failures with corrupted struct fields. The first byte (type tag, kind field, flags) reads as 0 while later fields contain valid-looking but shifted data. Crash is deterministic at a specific call number (e.g., always the 14th call). May appear to be a struct-by-value ABI issue but is actually allocator corruption.
- **Root cause:** Code uses `offsetof(struct { char x; union { int; double; } u; }, u)` to calculate alignment for a custom allocator or slab stack. On x86/ARM this returns 4 or 8. **On 68k this returns 2** because the 68000 only requires 2-byte alignment for word/long access. The allocator packs blocks at 2-byte boundaries. When `int`/`long`/pointer values are stored before each block (e.g., a next-pointer or stack linkage), they land at 2-byte-aligned addresses. Reading these values back produces corrupted data due to how the allocator indexes into the memory.
- **Diagnostic clue:** `ALIGNMENT` or similar alignment constant is 2. Custom stack/arena/slab allocator stores metadata (int-sized fields) interleaved with user data. Corruption manifests as wrong type tags or kind fields — the struct appears partially valid but the first byte is wrong.
- **Fix:** Force minimum 4-byte alignment:
  ```c
  #include <amiport/compat.h>
  enum {ALIGNMENT = AMIPORT_ALIGN(offsetof(struct determine_alignment, u))};
  ```
  Or directly: `((x) < 4) ? 4 : (x)`
- **Detection:** Source-analyzer should flag any `offsetof` used in alignment calculations for allocators, arenas, or stack structures.
- **Port:** jq (1.7.1) — `exec_stack.h` ALIGNMENT=2 corrupted VM stack
- **Date:** 2026-03-23

## 16. bebbo-gcc -O1/-O2 Corrupts Large Struct-by-Value Returns

### GCC 6.5.0b Code Generation Bug for Structs > 8 Bytes on 68k

- **Signature:** Functions that return structs > 8 bytes by value produce corrupted results at `-O1` or `-O2`. The struct's first byte (type tag, kind field) reads as 0 in the caller, despite being set correctly inside the returning function. Works correctly at `-O0`.
- **Root cause:** bebbo-gcc 6.5.0b generates incorrect register/stack management for struct return values larger than 8 bytes at optimization levels >= -O1. The hidden pointer mechanism for struct returns interacts badly with register allocation when the return value is immediately consumed in an expression.
- **Diagnostic clue:** (1) Struct type tag = 0 assertion, (2) struct > 8 bytes, (3) functions work in isolation, (4) crash disappears with `-O0`, (5) crash location varies with `-O1` vs `-O2`.
- **Fix:** Compile with `-O0`. No source-level fix exists.
  ```makefile
  CFLAGS := $(subst -O2,-O0,$(CFLAGS))
  ```
- **Impact:** ~12% larger binary. Acceptable for complex ports.
- **Detection:** Source-analyzer should flag functions returning structs > 8 bytes by value.
- **NOT affected:** Simple ports returning int/pointer/char*.
- **Port:** jq (1.7.1) — `jv` struct (16 bytes)
- **Date:** 2026-03-23

---

## 17. libnix getopt_long Returns '?' for All Options

### System getopt_long Is Broken — Use amiport/getopt.h

- **Enforcer signature:** No Enforcer hits — program exits cleanly with RC=10. No crash.
- **Symptom:** ALL functional tests return RC=10. Error-path tests that expect RC=10 appear to pass, but for the wrong reason. Debug output shows `ch=63` ('?') on the FIRST valid option.
- **Root cause:** `<getopt.h>` from the bebbo/crosstools system include path provides a newlib-based `getopt_long` that does NOT correctly parse short options from the optstring. It returns `'?'` for every option, even ones present in the options string. The `'?'` return triggers the `default:` case → `usage()` → exit with RC=10.
- **Detection:** Add `fprintf(stdout, "ch=%d\n", ch)` inside the getopt_long while loop. If `ch=63` appears for valid flags, this is the issue.
- **Fix:** Replace `#include <getopt.h>` with `#include <amiport/getopt.h>`:
  ```c
  /* amiport: replaced <getopt.h> with amiport/getopt.h — libnix getopt_long
   * returns '?' for all options (broken implementation). */
  #include <amiport/getopt.h>
  ```
  The amiport implementation (`amiport_getopt_long()`) works correctly and is aliased
  via macros to `getopt_long`, `optarg`, `optind`, etc. so no other changes are needed.
- **Port:** patch (OpenBSD v1.78)
- **Date:** 2026-03-23

---

## 18. dirname() Corrupts Its Input Buffer In-Place

### POSIX dirname() Modifies the Argument String — Save a Copy First

- **Enforcer signature:** No Enforcer hits — program fails with "can't find FILENAME" or
  "can't open file : Operation not permitted" (empty filename) after `dirname()` is called.
- **Symptom:** A filename argument stored in `filearg[0]` (or any buffer) is corrupted after
  `dirname(filearg[0])` is called. Subsequent use of `filearg[0]` as a filename fails because
  the string has been truncated or emptied by `dirname` modifying it in-place.
- **Root cause:** POSIX specifies that `dirname()` is permitted to modify the input string.
  OpenBSD's `dirname` uses a thread-local static buffer and does NOT modify the input, making
  the OpenBSD source safe to call `dirname(filearg[0])`. The libnix `dirname` from `libgen.h`
  DOES modify the input in-place (returns a pointer into the same buffer), corrupting it.
  The faulting address in "can't open file : Operation not permitted" shows an empty string
  because the truncated path `WORK:` has no file component.
- **Fix option 1 (preferred when dirname result not needed):** Remove the `dirname()` call
  entirely if its only purpose is to pass the result to another no-op (e.g., `unveil()` on
  AmigaOS is always a no-op):
  ```c
  /* amiport: debug-agent — removed dirname(filearg[0]) + unveil(origdir).
   * unveil() is a no-op on AmigaOS, so the whole block is dead code. */
  if (unveil(filearg[0], "rwc") == -1) { ... }
  ```
- **Fix option 2 (when dirname result IS needed):** Pass a copy to dirname, keep it alive
  until after origdir is consumed, then free it:
  ```c
  char *tmp = strdup(filearg[0]);
  char *origdir = dirname(tmp);
  /* use origdir here */
  free(tmp);   /* NOTE: origdir is now invalid — use before freeing! */
  ```
- **Detection grep:** `dirname(<variable>)` where the variable is used again after the call.
- **Port:** patch (OpenBSD v1.78)
- **Date:** 2026-03-23

---

## 19. AmigaOS Exclusive Write Lock Prevents Double-Open

### fopen("w") Fails with ERROR_OBJECT_IN_USE on Already-Open Files

- **Enforcer signature:** No Enforcer hits — `fopen()` returns NULL, program exits via pfatal with "Text file busy" (misleading errno string for ERROR_OBJECT_IN_USE).
- **Symptom:** A temp file created earlier in the program cannot be opened again for writing. `fopen(path, "w")` fails even though the file exists and the program owns it. The error message says "Text file busy" (ETXTBSY) which is a Unix concept that doesn't exist on AmigaOS — the real AmigaDOS error is ERROR_OBJECT_IN_USE (202).
- **Root cause:** AmigaDOS `Open(path, MODE_NEWFILE)` acquires an exclusive write lock on the file. If another file handle (from an earlier `fopen` or `amiport_open`) still holds the file open, the second open fails. On Unix, multiple processes/handles can open the same file for writing simultaneously. On AmigaOS, only one exclusive lock is allowed at a time.
- **Common trigger:** Programs that open a temp file for output early (e.g., `init_output(TMPOUTNAME)`), then a subroutine opens the same file again (e.g., `write_lines(TMPOUTNAME)` in ed mode). The first handle is still open when the second open is attempted.
- **Fix:** Close the first handle before opening the second:
  ```c
  /* amiport: close ofp before do_ed_script — AmigaOS MODE_NEWFILE
   * requires exclusive lock. Double-open causes ERROR_OBJECT_IN_USE. */
  if (ofp != NULL) {
      fclose(ofp);
      ofp = NULL;
  }
  do_ed_script();  /* write_lines() will fopen the same file */
  ```
- **Detection grep:** Look for two `fopen(..., "w")` calls on the same path variable without an intervening `fclose()`. Also check `init_output`/`init_reject` patterns followed by subroutines that re-open the same file.
- **Port:** patch (OpenBSD v1.78)
- **Date:** 2026-03-23

## 20. libnix snprintf %.Ng Shows FP Noise Above 15 Significant Digits

- **Signature:** Integers print as `1.0000000000` or `6765.00000000000056840000000000` instead of `1` or `6765`. Floating point accumulation appears wrong (`fib(20)` returns `6764.999...`).
- **Root cause:** libnix's `snprintf` with `%g` format does not properly strip trailing zeros when the precision exceeds ~15 digits. `%.30g` of `1.0` produces `1.0000000000` instead of `1`. `%.15g` works correctly. The math is actually correct -- the formatting just shows IEEE 754 representation noise beyond the meaningful precision of a 64-bit double (~15.9 significant digits).
- **Impact:** Any program using `snprintf(buf, size, "%.Ng", val)` where N > 15 will show FP noise on integer values.
- **Fix:** Reduce `%g` precision to 15 or fewer significant digits.
- **Detection grep:** `grep -rn '%\.\(1[5-9]\|[2-9][0-9]\)g' ported/*.c` -- finds `%g` with precision > 14.
- **NOT a crash** -- wrong output only. But easily misdiagnosed as a FP precision or math error.
- **Port:** awk (BWK "One True Awk" 2024.12.25)
- **Date:** 2026-03-25

## 21. Static Library Initialization Missing — Silent Failure on Real AmigaOS

- **Signature:** Bundled static library function returns error code or crashes on FS-UAE/real hardware, but works perfectly on vamos. RC 20 (RETURN_FAIL) with empty output.
- **Root cause:** Static linking (`.a` archives) does not run library constructor functions (`__attribute__((constructor))` or C++ static initializers). On vamos, uninitialized BSS is zeroed, so globals happen to be in a valid initial state. On real AmigaOS, uninitialized memory contains garbage from previous allocations.
- **Diagnostic clue:** Works on vamos, fails on FS-UAE. No Guru Meditation — the library function returns an error that the calling program handles as a fatal exit. Switching between -O0 and -O2 does NOT fix it (rules out codegen bug).
- **Fix:** Check if the bundled library requires explicit initialization (e.g., `onig_initialize()` for Oniguruma, `pcre2_config()` for PCRE2). Call the init function early in `main()`, guarded by `#ifdef HAVE_LIB*`. Register the cleanup function via `atexit()`.
- **General rule:** When bundling a third-party static library, always check its documentation for required init/shutdown functions. The autotools/cmake build system typically calls these automatically via shared library constructors — static builds do not.

---

## 22. AmigaDOS Volume Requester Hangs Program During Path Probing

- **Symptom:** Program hangs at startup with a system requester "Please insert volume X in any drive." The Retry/Cancel dialog cannot be dismissed by the test harness, causing FS-UAE test timeouts with 0 tests run.
- **Enforcer signature:** None — this is not a crash. The system requester is a normal AmigaDOS feature.
- **Root cause:** Any `Lock()` or `Open()` call on a bare name (e.g., `"vim"`, `"python"`) causes AmigaDOS to interpret it as a volume reference (`vim:`) and pop a system requester asking the user to insert that volume. This happens in BOTH direct AmigaDOS calls in ported code AND in libnix's `fopen()`/`stat()` which call `Lock()`/`Open()` internally. Programs that probe multiple paths during startup (editors, shells, interpreters searching for config/runtime files like `$VIM`, `$PYTHONPATH`, etc.) trigger this for each non-existent path.
- **Diagnostic clue:** Tests 1-N pass (simple invocations like `--version`), then test N+1 hangs forever. The hung test uses a flag that triggers runtime file loading (e.g., `--clean`, `-u`, loading rc files). The FS-UAE window shows the system requester dialog.
- **Fix:** Suppress system requesters globally at process startup by setting `pr_WindowPtr = -1`:
```c
/* In the program's init function: */
struct Process *me = (struct Process *)FindTask(NULL);
me->pr_WindowPtr = (APTR)-1L;
```
This causes all system requesters (volume insert, disk write-protected, etc.) to return failure immediately instead of prompting. For individual Lock() calls, use a save/restore wrapper (see known-pitfalls.md). The global suppression is preferred for CLI tools.
- **ADCD reference:** `dos.library/ErrorReport` documents that `pr_WindowPtr = -1` suppresses all requesters.
- **Example port:** vim 9.1 — probed `$VIM`, `$VIMRUNTIME`, `defaults.vim`, multiple vimrc paths. Each missing path triggered a requester. Global suppression in `mch_init()` was the only complete fix.
- **General rule:** Any Category 3+ port (editors, shells, interpreters) that searches for config/runtime files should suppress system requesters at startup. Category 1-2 ports rarely need this since they don't probe paths.
- **Port:** jq 1.7.1-2 (Oniguruma 6.9.9 integration)
- **Date:** 2026-03-25

---

## 23. libnix mbstowcs(NULL) Crash — HAVE_BROKEN_MBSTOWCS Required

- **Enforcer signature:** LONG-WRITE to address `0x00000000` from PC inside `mbstowcs` (libnix symbol). The Enforcer log shows `_mbstowcs + 0x2c` writing to NULL.
- **Hit type:** LONG-WRITE to NULL address.
- **Root cause:** CPython's `decode_current_locale()` in `Python/fileutils.c` calls `_Py_mbstowcs(NULL, arg, 0)` (which calls `mbstowcs(NULL, arg, 0)`) to query the required wchar_t buffer size. This is valid per C99/POSIX: `mbstowcs` with NULL destination should return the count of characters. However, libnix's `mbstowcs` implementation does NOT support `NULL` as the destination -- it dereferences the NULL pointer and writes to address 0, causing a crash. This is the exact same class of bug as crash-pattern #5 (vsnprintf(NULL,0,...) crash).
- **Fix:** Define `HAVE_BROKEN_MBSTOWCS 1` in `pyconfig.h`. CPython already has a fallback path guarded by this macro that uses `strlen(arg)` as the buffer size estimate instead of calling `mbstowcs(NULL, arg, 0)`. Since AmigaOS libnix uses C locale (ASCII superset), `strlen()` is always a correct upper bound.
- **Diagnostic approach:** The Enforcer log showed 117 hits all from "Processor Interrupt Level 3" (ROM-space writes -- false positives), masking the real crash. The actual NULL write was at `mbstowcs + 0x2c` with SR: 0014 (user mode), not the interrupt hits. The stack frames showed `_Py_DecodeLocale` -> `_Py_DecodeLocaleEx` -> `decode_current_locale` -> `_Py_mbstowcs(NULL, arg, 0)`.
- **Enforcer false positive note:** Enforcer hits at address `0x00F0FFFC` from PC `0x00F00408` with `Name: "Processor Interrupt Level 3"` are system timer interrupts writing to a ROM mirror -- NOT user code crashes. Ignore these when they appear; look for user-mode hits (SR field low bits = 0001 user mode) and NULL/small addresses.
- **Port:** python3 3.11.12
- **Date:** 2026-03-26

## 24. bebbo-gcc Uint64 Return Value Corruption (UNDER INVESTIGATION)

- **Symptom:** Function returning `Uint64` computes correct result internally (verified via file-based diagnostic writing to WORK:), but the caller receives 0. Affects `SDL_GetTicks64()`, `SDL_GetPerformanceCounter()`, `SDL_GetPerformanceFrequency()`.
- **Root Cause:** UNKNOWN. Not the same as #16 (struct returns > 8 bytes) since `Uint64` is a scalar. Disassembly shows correct D0:D1 return convention. Both 64-bit math (`___udivdi3`) and 32-bit math workaround produce correct internal results, but caller still gets 0.
- **Possible causes under investigation:**
  1. FS-UAE 68040 emulation bug with `movem.l` register restore + `unlk` + `rts` corrupting D0:D1
  2. bebbo-gcc 64-bit return ABI mismatch between compilation units (library .o vs test .o)
  3. Interaction with `-noixemul` libnix startup code
- **Diagnostic approach:** Added `timer_diag()` function that writes to `WORK:timer_diag.txt` from inside `SDL_GetTicks64()`. Confirmed `result=42` ms computed correctly inside function. Confirmed `timer_initialized=1`. Confirmed `eclock_freq=709379` (PAL). Caller's printf with `(unsigned long)t1` prints 0.
- **Fix:** NONE YET. 32-bit arithmetic workaround does not help (same symptom). May need to return via global variable or struct pointer instead of D0:D1.
- **Project:** libSDL2-amigaos3
- **Date:** 2026-03-28

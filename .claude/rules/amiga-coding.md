Paths: ports/**/*.c, ports/**/*.h, lib/**/*.c, lib/**/*.h, examples/**/*.c, examples/**/*.h

# Amiga C Coding Standards

These rules apply to ALL C code targeting AmigaOS in this project.

## API Documentation — MANDATORY LOOKUP (ENFORCED BY HOOK)

**HARD RULE: Before writing ANY code that includes `<proto/*.h>`, `<devices/*.h>`, `<exec/*.h>`, or references AmigaOS structs (ConUnit, MsgPort, IOStdReq, FileHandle, etc.):**

1. **Invoke `/amiga-api-lookup`** to load the ADCD reference documentation
2. **Dispatch `hardware-expert` agent** for any hardware assumptions (memory layout, CPU features, struct sizes, field offsets)
3. **Verify struct offsets** against the ADCD header — NEVER compute offsets from memory or guess them

A PreToolUse hook (`enforce-adcd-lookup.sh`) fires on every Edit/Write to C files containing AmigaOS API includes. It warns if ADCD docs weren't loaded. This is not optional.

**Why this is enforced:** Agents repeatedly guess at AmigaOS struct offsets (ConUnit fields, MsgPort size, FileHandle layout) and function signatures, producing subtle bugs that waste hours of debugging. The cost of looking it up is 5 seconds. The cost of guessing wrong is hours.

This applies to: shim implementations, new library features (profiler, crash handler, etc.), code review of AmigaOS calls, design work involving AmigaOS APIs, and FS-UAE trap handlers that read emulated memory.

## Character Encoding — ASCII ONLY

**ALL C source files (.c, .h) MUST be pure ASCII.** No UTF-8, no extended characters, not even inside comments. bebbo-gcc (GCC 6.5.0b) silently corrupts preprocessor output when it encounters multi-byte UTF-8 characters — entire functions vanish without any error or warning.

Common violations to avoid:
- Em-dash `—` (U+2014) → use `--` instead
- Arrow `→` (U+2192) → use `->` instead
- Smart quotes `''""` → use `''""` (straight quotes)
- Copyright `©` → use `(C)` instead

This applies to `/* comments */` and string literals equally. The pre-commit hook checks for non-ASCII bytes in ported source files.

## Language Standard

- **ANSI C89 by default.** New code (shim libraries, examples) must use C89.
- **`-std=gnu99` permitted for ports** where the upstream source requires C99 (see ADR-022). Add `CFLAGS += -std=gnu99` to the port Makefile and document in PORT.md.
- C99 **language** features (for-init declarations, `//` comments, mixed declarations, `inline`) are OK when using gnu99. C99 **library** functions are NOT assumed available — libnix is a C89 runtime. Check `docs/references/libnix-reference.md` before using any C99 stdlib addition.

## Headers

- Use `<proto/*.h>` for Amiga system calls (never `<clib/*.h>` pragmas).
- Replace `<stdlib.h>` with `<amiport/stdlib.h>` — activates the `exit()` → `amiport_exit()` macro.
- Use `<amiport/compat.h>` for platform compatibility macros (`AMIPORT_ALIGN()`, compiler workarounds).

## Types

- Use Amiga types (`LONG`, `ULONG`, `STRPTR`, `BPTR`, `APTR`) when interfacing with OS libraries.
- `LONG` is `long` (32-bit) — use `%ld`/`%lu` format specifiers, not `%d`/`%u`.

## Exit Codes — CRITICAL

POSIX `exit(1)` is **invisible** to Amiga shells. Amiga scripts test with `IF WARN` (>=5), `IF ERROR` (>=10), `IF FAIL` (>=20).

- `exit(0)` — OK (RETURN_OK)
- `exit(5)` — warning (RETURN_WARN)
- `exit(10)` — error (RETURN_ERROR) — use instead of `exit(1)` / `exit(EXIT_FAILURE)`
- `exit(20)` — fatal (RETURN_FAIL)
- Fix `err(1, ...)` / `errx(1, ...)` calls too — change to `err(10, ...)`

## Version String

Every program must include a version string with the **upstream version** plus **port revision** (when revision > 1):
```c
/* First release of upstream 1.68 (REVISION=1, implicit): */
static const char *verstag = "$VER: progname 1.68 (DD.MM.YYYY)";

/* Second port revision of same upstream (REVISION=2, explicit): */
static const char *verstag = "$VER: progname 1.68-2 (DD.MM.YYYY)";
```

- **Upstream version** (e.g., `1.68`): from the original project. Only changes when pulling new upstream source.
- **Port revision** (`-2`, `-3`): increments when `ported/`, Makefile, shim deps, or tests change but upstream version stays the same. Omitted for revision 1.
- The Makefile `DISPLAY_VERSION` (from `VERSION` + `REVISION`) must match the `$VER` string and `.readme Version:` field. Run `make check-port-metadata` to validate.

## Stack Size

Amiga default stack is 4KB. Always add a stack cookie:
```c
long __stack = 32768;  /* or 65536 for recursive programs */
```

## Temp Files

No `/tmp` on Amiga. Use `T:` (maps to `RAM:T/`). Use `amiport_tmpfile()` / `amiport_mkstemp()`.

## Epoch

AmigaOS epoch is 1978-01-01, Unix is 1970-01-01. Offset: 252460800 seconds (AMIGA_EPOCH_OFFSET).

## Transformation Comments

Document every POSIX-to-Amiga transformation:
```c
/* amiport: replaced POSIX open() with amiport_open() */
```

## Platform Compatibility

- **68k alignment (crash-patterns #15):** `offsetof()` returns 2 on 68k, not 4/8. Custom allocators using `offsetof()` for alignment will corrupt metadata. Use `AMIPORT_ALIGN(size, align)` from `<amiport/compat.h>`.
- **Struct-by-value returns (crash-patterns #16):** bebbo-gcc (GCC 6.5.0b) corrupts struct returns > 8 bytes at `-O1`/`-O2`. Compile with `-O0` or refactor to return via pointer.

## Cross-Platform

Use `#ifdef __AMIGA__` blocks when code should remain cross-platform. Target AmigaOS 3.x on 68020+ as default.

# ADR-009: Upstream Test Integration

## Status

Accepted

## Date

2026-03-25

## Context

SDL2 upstream (libsdl-org/SDL, SDL2 branch) includes a comprehensive test suite in its `test/` directory: `testsprite2`, `testkeys`, `testaudio`, `testthread`, `testatomic`, and many others. These tests exercise the SDL2 API from the application side and are the canonical validation that a backend implementation is correct.

We could write custom test programs from scratch, but this has several disadvantages:
- Custom tests may not exercise the same code paths as real SDL2 applications
- They duplicate effort already done upstream
- They may mask backend bugs by testing only the subset we thought to test

However, upstream tests assume POSIX or Windows conventions:
- No `__stack` cookie (Amiga needs explicit stack size declaration)
- No `$VER` version string (Amiga convention for `VERSION` command)
- Some tests use `printf` with format specifiers that differ on AmigaOS (`%d` for `int` vs `%ld` for `LONG`)
- Some tests have infinite main loops (need modification or tier M classification)

## Decision

**Port upstream SDL2 test programs rather than writing custom tests.** Use a preamble header to inject Amiga-specific declarations without modifying upstream source files.

The approach:
1. Copy upstream test `.c` files to `examples/` (or reference them via the build system)
2. Compile with `-include amiga_test_preamble.h` which injects:
   ```c
   long __stack = 65536;
   static const char *verstag = "$VER: testname 2.28.0 (DD.MM.YYYY)";
   ```
3. Build `libSDL2_test.a` separately from `libSDL2.a` (upstream test helpers like `SDLTest_CommonCreateState`)
4. Classify each test in `tests.txt` with the appropriate tier (1/2/12/M)
5. Minimize modifications to upstream source -- use `#ifdef __AMIGA__` blocks only when unavoidable

## Consequences

### Positive

- Tests exercise the same code paths as real SDL2 applications
- Leverages upstream's comprehensive coverage (input, video, audio, threading, atomics)
- Passing upstream tests provides high confidence that the backend is correct
- `-include` preamble avoids modifying upstream files, making updates easy

### Negative

- Some upstream tests need Amiga-specific patches (infinite loops, POSIX assumptions) -- these must be maintained as a patch set or `#ifdef` blocks
- `libSDL2_test.a` adds build complexity (separate static library)
- Not all upstream tests are applicable (e.g., tests for subsystems we stub out)

### Neutral

- The preamble header pattern is a standard cross-compilation technique
- Custom tests are still written for Amiga-specific scenarios (e.g., CHIP RAM audio, Paula-specific behavior) alongside upstream tests

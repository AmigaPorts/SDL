# ADR-022: C99 Compiler Support for Complex Ports

## Status

Accepted

## Date

2026-03-22

## Context

The project's coding standard (amiga-coding.md) mandates "ANSI C89 only" for all C code targeting AmigaOS 3.x. This rule was established when all ports were single-file OpenBSD CLI tools that were already written in C89.

Modern C projects increasingly require C99. jq 1.7.1 (the first complex multi-file port attempted) has 60+ `for (int i = ...)` declarations, mixed declarations and code, and `//` comments throughout 20 source files. Converting these to C89 mechanically would:

- Touch hundreds of lines across 20 files, introducing bug risk
- Increase the diff from upstream, making future version upgrades harder
- Provide zero runtime benefit — the generated machine code is identical

bebbo-gcc (GCC 6.5.0) fully supports `-std=gnu99` and produces the same 68020 machine code regardless of C standard level. The C standard flag affects only what syntax the compiler *accepts*, not what it *emits*. There is no RAM, CPU, or binary size difference.

## Decision

**Allow `-std=gnu99` in CFLAGS for ports where the upstream source requires C99.**

Rules:
1. **C99 *language* features are allowed** — for-init declarations, `//` comments, mixed declarations, `inline`, designated initializers, compound literals
2. **C99 *library* functions are NOT assumed available** — libnix is a C89 runtime. Do not use `strtoll`, `strtof`, `_Bool`/`stdbool.h`, or other C99 stdlib additions unless verified in `docs/references/libnix-reference.md`
3. **`stdint.h` IS available** — bebbo-gcc provides this header
4. **Per-port opt-in** — add `CFLAGS += -std=gnu99` to the port Makefile. The project default remains C89 for new code (shim libraries, examples)
5. **Document in PORT.md** — note that the port uses gnu99 and why
6. **VBCC incompatible** — ports using gnu99 are bebbo-gcc only. Note in PORT.md if relevant

The amiga-coding.md rule is updated from "ANSI C89 only" to "ANSI C89 by default; gnu99 permitted for ports where upstream requires it."

## Consequences

### Positive

- Unblocks porting of modern C projects (jq, curl, sqlite, etc.) without massive mechanical churn
- Keeps diffs from upstream minimal, easing future version upgrades
- Focuses porting effort on real problems (POSIX shims, pthread stubs, config.h) instead of syntax conversion

### Negative

- VBCC cannot build gnu99 ports (acceptable — complex ports already require bebbo-gcc features)
- The amiga-coding.md rule becomes conditional rather than absolute
- New code written for shim libraries should still use C89 for maximum compatibility

### Neutral

- No change to runtime behavior, binary size, RAM usage, or CPU performance
- The constraint that matters (libnix C89 runtime) is unchanged

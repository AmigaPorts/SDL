# ADR-003: Compile at -O0 by Default

## Status

Accepted

## Date

2026-03-15

## Context

bebbo-gcc (GCC 6.5.0b) is the only maintained cross-compiler targeting AmigaOS 3.x on 68k. It is a fork of GCC 6.5 with extensive patches for Amiga-specific code generation (register-relative addressing, CHIP RAM placement, Amiga calling conventions).

This compiler has known code generation bugs at optimization levels `-O1` and `-O2`:

1. **Struct return corruption:** Functions returning structs larger than 4 bytes by value produce corrupted results at `-O1` and above. The return value is silently wrong -- no crash, no warning, just incorrect data. This affects `SDL_Color` (4 bytes, borderline), `SDL_Rect` (16 bytes), `SDL_Point` (8 bytes), and any backend code returning structs.

2. **Register allocation issues:** Certain register pressure scenarios at `-O2` produce incorrect code, particularly in functions with many local variables and nested loops.

These bugs are intermittent and depend on the specific code being compiled, making them extremely difficult to diagnose. A function may work correctly at `-O0` and produce subtle data corruption at `-O1`.

## Decision

**Compile all source files at `-O0` by default.** Individual files may be upgraded to `-O2` after they have been tested and proven stable at that optimization level.

The Makefile supports per-file optimization overrides for future use:
```makefile
# Example: upgrade a hot path after verification
src/video/amigaos3/SDL_os3blit.o: CFLAGS += -O2
```

## Consequences

### Positive

- Eliminates an entire class of silent data corruption bugs
- Makes debugging straightforward -- generated code matches source closely
- Reduces time spent chasing phantom bugs caused by the compiler

### Negative

- Larger binary size (no dead code elimination, no inlining)
- Slower execution (no loop optimization, no strength reduction)
- Performance-sensitive code (blitters, audio mixing) will need per-file optimization in Phase 6

### Neutral

- 68k Amigas are already slow by modern standards; correctness matters more than optimization at this stage
- The performance impact is acceptable for Phase 0-5 (getting things working); Phase 6 explicitly addresses optimization

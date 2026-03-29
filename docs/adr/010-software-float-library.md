# ADR-010: Software IEEE 754 Float Library

## Status

Accepted

## Date

2026-03-28

## Context

SDL2's renderer uses `float` extensively (`SDL_FRect`, `SDL_FPoint`, DPI scaling, coordinate transforms). On 68030 without FPU (`-m68030`, no `-m68881`), GCC generates calls to software float functions: `__divsf3`, `__mulsf3`, `__addsf3`, `__subsf3`, etc.

libnix's implementations of these functions call through the ROM's `mathieeesingbas.library` (e.g., `__divsf3` -> `IEEESPDiv` at LVO -84). On FS-UAE, ALL of these ROM library calls crash with Guru #8000000B. The crash occurs even though `MathIeeeSingBasBase` is valid (opened successfully by libstubs auto-open). The ROM library's emulation is broken in FS-UAE for both A4000/040 and A1200/030 configs.

This blocks ALL float operations in SDL2, making the entire SDL_Renderer pipeline unusable.

## Decision

**Provide a complete software IEEE 754 single-precision float library in `src/stdlib/SDL_os3float.c`.**

The library implements these functions using pure integer math (no ROM library dependency):

| Function | Purpose |
|----------|---------|
| `__divsf3` | float division |
| `__mulsf3` | float multiplication |
| `__addsf3` | float addition |
| `__subsf3` | float subtraction |
| `__fixsfsi` | float to int conversion |
| `__floatsisf` | int to float conversion |
| `__cmpsf2` | float comparison |
| `__eqsf2`, `__nesf2`, etc. | comparison variants |

These override libnix's ROM-calling versions at link time because `libSDL2.a` comes before `-lm` on the link line. Programs must link: `-lSDL2 ... -lm -lstubs`.

## Consequences

### Positive

- ALL float operations work on FS-UAE without ROM library dependency
- SDL_Renderer fully functional (RenderFillRect, RenderClear, RenderPresent, RenderCopy)
- game_2048 (SDL_Renderer-based game) runs and renders correctly
- Works on any 68k CPU (68020+) without FPU

### Negative

- Software float is slower than ROM library (which can use 68040/060 FPU when available)
- On real hardware with FPU, this soft float is unnecessary overhead
- Future optimization: compile with `-m68040 -m68881` for FPU-equipped machines, producing a separate binary. The soft float build targets stock 68030 boards without FPU.

### Neutral

- The `-lstubs` link flag is now required for all SDL2 programs (provides `MathIeeeSingBasBase` auto-open for any code that still references the ROM library)
- Double-precision float (`__divdf3` etc.) is not yet provided -- add when needed

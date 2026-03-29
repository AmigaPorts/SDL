# ADR-002: Disable SDL_DYNAMIC_API

## Status

Accepted

## Date

2026-03-15

## Context

SDL2 has a dynamic API dispatch mechanism (`SDL_DYNAMIC_API`) that allows applications to load a different SDL2 shared library at runtime via an environment variable. This mechanism uses `dlopen()` / `dlsym()` (or platform equivalents) to redirect all SDL2 function calls through a jump table loaded from a shared object.

AmigaOS 3.x has no `dlopen()` equivalent. The OS uses Amiga shared libraries (`.library` files opened via `OpenLibrary()`), which have a completely different calling convention (LVO jump tables, A6 base register). There is no POSIX dynamic linker, no ELF shared objects, and no way to load arbitrary object code at runtime in a way compatible with SDL2's dispatch mechanism.

The `loadso` subsystem is implemented as a dummy backend that always returns failure.

## Decision

**Disable SDL_DYNAMIC_API by defining `SDL_DYNAMIC_API 0` in the build configuration.**

All SDL2 function calls resolve directly at link time. The library is built as `libSDL2.a` (static archive) and linked directly into applications.

## Consequences

### Positive

- Eliminates dead code paths related to dynamic dispatch (jump table setup, dlopen probing)
- Simpler debugging -- function calls go directly to implementations, no indirection
- Smaller binary size (no jump table overhead)
- No risk of SDL2 core attempting dlopen at startup and crashing

### Negative

- Applications cannot swap SDL2 implementations at runtime (not possible on AmigaOS 3.x anyway)
- Every application statically links its own copy of SDL2 (typical for Amiga software)

### Neutral

- This matches how SDL 1.2 for AmigaOS 3.x was distributed (static library)
- The SDL2 AmigaOS 4 port also uses static linking

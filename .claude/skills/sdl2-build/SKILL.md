---
name: sdl2-build
description: Build libSDL2.a and examples via Docker cross-compilation
user_invocable: true
---

# SDL2 Build

Run the SDL2 cross-compilation build via Docker (bebbo-gcc).

## Instructions

Execute the build and report results:

1. Run `make` to build `libSDL2.a`
2. If successful, report object count and library size
3. If failed, analyze the error:
   - Missing includes: check if the header exists in bebbo-gcc sysroot
   - Undefined symbols: check if the function is stubbed or needs implementation
   - Compiler errors: check crash-patterns.md for known bebbo-gcc issues
4. Optionally run `make examples` to build test programs

Key build settings (from CLAUDE.md):
- Compiler: m68k-amigaos-gcc via Docker
- CPU target: -m68020 (RTG requires 68020+)
- Optimization: -O0 (bebbo-gcc codegen bugs at -O1/-O2)
- Standard: -std=gnu99 (SDL2 requires C99)
- SDL_DYNAMIC_API: disabled (no dlopen on AmigaOS 3.x)

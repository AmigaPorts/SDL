# libSDL2-amigaos3 -- Claude Code Project Instructions

## What This Project Is

A port of SDL2 (Simple DirectMedia Layer 2) to AmigaOS 3.x on Motorola 68k. This is a **platform library** -- it provides `libSDL2.a` that other programs link against. It is NOT a POSIX port; it implements SDL2's platform abstraction layer using native AmigaOS APIs.

## Architecture

SDL2 has a backend/driver architecture. Each subsystem (video, audio, threading, etc.) has a platform-specific implementation. We provide AmigaOS 3.x backends:

| Subsystem | Backend | AmigaOS API | Source Dir |
|-----------|---------|------------|-----------|
| Video | CyberGraphX / Picasso96 | `WritePixelArray()`, screen modes | `src/video/amigaos3/` |
| Video (AGA) | Custom chipset + c2p | Blitter, bitplanes | `src/video/amigaos3/` (Phase 6) |
| Audio | AHI | `AHI_AllocAudio()`, callbacks | `src/audio/amigaos3/` |
| Threading | Exec Tasks | `CreateNewProc()`, `SignalSemaphore` | `src/thread/amigaos3/` |
| Timer | timer.device | `ReadEClock()` | `src/timer/amigaos3/` |
| Input/Events | Intuition IDCMP | `IDCMP_RAWKEY`, `IDCMP_MOUSEMOVE` | `src/events/` (via video driver) |
| Joystick | gameport.device | `GPD_ASKCTYPE` | `src/joystick/amigaos3/` |
| Filesystem | dos.library | `Lock()`, `Examine()` | `src/filesystem/amigaos3/` |
| Loadso | Stub (no dlopen) | -- | `src/loadso/dummy/` |
| Haptic | Stub | -- | `src/haptic/dummy/` |
| Render | Software (built-in) | -- | `src/render/software/` |

## Codebase Map

```
include/SDL2/              # Standard SDL2 public headers (from upstream)
src/
  video/amigaos3/          # CyberGraphX/P96 + optional AGA + optional AMMX
  audio/amigaos3/          # AHI audio
  thread/amigaos3/         # Exec Tasks
  timer/amigaos3/          # timer.device
  joystick/amigaos3/       # gameport.device
  filesystem/amigaos3/     # dos.library
  loadso/dummy/            # Stub (no dlopen on OS3)
  haptic/dummy/            # Stub (no haptic)
  main/amigaos3/           # SDL_main entry point
  render/software/         # SDL2 built-in software renderer
  events/                  # IDCMP -> SDL event translation
examples/                  # Test programs (testsprite2, loopwave, testkeys, etc.)
docs/
  references/              # Amiga hardware and API reference docs
  adr/                     # Architecture Decision Records
Makefile                   # Cross-compile to libSDL2.a via bebbo-gcc
```

## Build Instructions

```bash
make setup-toolchain   # Pull/verify bebbo-gcc Docker image
make                   # Build libSDL2.a (cross-compile via Docker)
make examples          # Build example/test programs
make test              # Run tests via FS-UAE with RTG
make clean             # Remove build artifacts
```

**Prerequisites:** Docker, Python + amitools, FS-UAE with RTG-capable config.

## Compiler Settings

- **Language:** C99 (`-std=gnu99`). SDL2 requires C99.
- **CPU target:** `-m68020` for the library (RTG cards require 68020+).
- **Optimization:** `-O0` initially until backends are proven stable. Upgrade to `-O2` per-file after testing. bebbo-gcc has codegen bugs at `-O1`/`-O2` (see `docs/references/crash-patterns.md` #16).
- **`SDL_DYNAMIC_API`:** Disabled (`#define SDL_DYNAMIC_API 0`). AmigaOS 3.x has no `dlopen()`.

## Coding Standards

### C99 with AmigaOS Constraints

- Use C99 features (for-init, `//` comments, mixed declarations, `inline`).
- Do NOT assume C99 library functions exist -- libnix is a C89 runtime. Check `docs/references/libnix-reference.md`.
- Use `<proto/*.h>` for Amiga system calls (never `<clib/*.h>`).
- Use Amiga types (`LONG`, `ULONG`, `STRPTR`, `BPTR`, `APTR`) for OS interfaces.
- Format specifiers: `%ld`/`%lu` for `LONG`/`ULONG` (32-bit `long`).

### ASCII Only in Source

ALL `.c` and `.h` files must be pure ASCII. No UTF-8, not even in comments. bebbo-gcc silently corrupts preprocessor output on multi-byte characters.

### Memory Safety

AmigaOS has no memory protection. Every `malloc()` must have a `free()`. Every `OpenLibrary()` must have a `CloseLibrary()`. Every `OpenDevice()` must have a `CloseDevice()`. Leaked resources persist until reboot.

### Stack Safety

Backend functions called from SDL2's core must not use large local arrays. Keep stack usage under 512 bytes per function. SDL2 programs set their own `__stack` cookie; the library shouldn't blow it.

### Threading Safety

Exec Tasks are cooperative on the same address space. No memory protection between tasks. `SignalSemaphore` is the primitive for mutual exclusion. `Forbid()`/`Permit()` for brief critical sections only. Never hold a semaphore across a `Wait()` call.

## Key References

### Critical (consult during every backend implementation)

- `docs/references/crash-patterns.md` -- Crash patterns from real 68k development. #7 (stack overflow), #10 (large buffers), #15 (alignment), #16 (struct returns at -O2) all apply.
- `docs/references/68k-hardware.md` -- Memory map, addressing modes, crash signatures.
- `docs/references/libnix-reference.md` -- What C library functions are actually available.

### AmigaOS API Documentation

- `docs/references/adcd/` -- ADCD 2.1 reference in markdown. exec.library, dos.library, intuition.library, graphics.library, timer.device.
- `docs/references/amiga-intern/` -- "Amiga Intern" (1992). Custom chip architecture, memory map, DMA timing.
- `docs/references/m68000-prm/` -- Motorola M68000 Family Programmer's Reference Manual.

### SDL2 References

- [SDL2 source](https://github.com/libsdl-org/SDL/tree/SDL2) -- upstream SDL2 branch
- [SDL2 OS4 backend](https://github.com/AmigaPorts/SDL) -- AmigaOS 4 (PPC) implementation
- [SDL 1.2 68k](https://github.com/AmigaPorts/libSDL12) -- proven AmigaOS 3.x backends
- [SDL2 Porting Guide](https://wiki.libsdl.org/SDL2/README-porting) -- official backend documentation
- [SDL2 Porting Walkthrough](https://mohammedisam2000.medium.com/porting-sdl-2-0-to-a-new-platform-a6786baec01d)

### New References Needed (not yet in docs/)

These are third-party APIs not in the ADCD. Reference docs must be created before implementing their backends:

| API | Backend | Priority |
|-----|---------|----------|
| CyberGraphX V4 | Video | Critical (Phase 1) |
| Picasso96 | Video (alt) | Critical (Phase 1) |
| AHI | Audio | Critical (Phase 3) |

## Phased Delivery

| Phase | Focus | Key Files |
|-------|-------|-----------|
| **0: Bootstrap** | All stubs, `SDL_Init()` returns 0 | All `src/*/amigaos3/*.c` as stubs |
| **1: First Pixels** | CyberGraphX video + software render | `src/video/amigaos3/`, `src/render/software/` |
| **2: Input** | IDCMP -> SDL events | `src/video/amigaos3/SDL_os3events.c` |
| **3: Audio** | AHI backend | `src/audio/amigaos3/` |
| **4: Threading** | Exec Tasks | `src/thread/amigaos3/` |
| **5: Polish** | Timer, filesystem, joystick | Remaining backends |
| **6: Optimization** | AGA c2p, AMMX, asm hotpaths | `src/video/amigaos3/` extensions |

## Phase Gate Rules

Before starting Phase N, confirm Phase N-1 is stable:

| Starting Phase | Prerequisite |
|---------------|-------------|
| **1: First Pixels** | Phase 0 tests pass: `SDL_Init(0)` returns 0, `SDL_Quit()` clean exit |
| **2: Input** | Phase 1 tests pass: window opens on FS-UAE with RTG, `testsprite2` draws pixels |
| **3: Audio** | Phase 2 tests pass: keyboard/mouse events received, `testkeys` reports scancodes |
| **4: Threading** | Phase 3 tests pass: `loopwave` plays audio via AHI |
| **5: Polish** | Phase 4 tests pass: threaded programs work (mutex, semaphore, TLS) |
| **6: Optimization** | Phase 5 tests pass: timer, filesystem, joystick backends functional |

Do not skip phases. If a phase's prerequisite test fails, fix it before moving forward.

## Testing

- **Phase 0-1:** vamos smoke test (`SDL_Init()` / `SDL_Quit()` without crashing).
- **Phase 1+:** FS-UAE with RTG enabled. Visual verification via FS-UAE screenshots.
- **All phases:** Exit code verification for all example programs.

FS-UAE config must include:
```
graphics_card = uaegfx
graphics_card_memory = 16384
joystick_port_1_mode = nothing
```

## Relationship to amiport

This is a **separate project** from [amiport](https://github.com/bdgscotland/amiport). It does not use amiport's porting pipeline, shim libraries, or test infrastructure. Once `libSDL2.a` is functional, amiport can reference it as a dependency for graphical port candidates.

Shared resources copied from amiport:
- `docs/references/` -- Amiga hardware and API docs (kept in sync manually)
- `.claude/rules/` -- Amiga coding rules (adapted for library development)
- Toolchain Docker image (same `bebbo/amiga-gcc`)

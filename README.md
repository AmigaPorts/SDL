# libSDL2-amigaos3

**SDL2 for AmigaOS 3.x on Motorola 68k** -- CyberGraphX/P96 video, AHI audio, Exec Task threading.

The first full SDL2 implementation for classic Amiga hardware.

## Status

**Phase 0: Bootstrap** -- compiles to `libSDL2.a` with all stubs; `SDL_Init()` returns 0.

| Phase | Deliverable | Milestone Test | Status |
|-------|-------------|----------------|--------|
| **0: Bootstrap** | Compiles to libSDL2.a with all stubs | `SDL_Init()` returns 0 | In Progress |
| **1: First Pixels** | CyberGraphX video backend + software renderer | `testsprite2` draws rectangles | -- |
| **2: Input** | IDCMP -> SDL events (keyboard, mouse) | `testkeys` responds to input | -- |
| **3: Audio** | AHI audio backend | `loopwave` plays a WAV file | -- |
| **4: Threading** | Exec Task-based thread/mutex/cond | `testthread` + stable audio | -- |
| **5: Polish** | Timer, filesystem, joystick, full test suite | Simple SDL2 game runs | -- |
| **6: Optimization** | AGA backend, AMMX blitters, 68k asm hotpaths | DOSBox-SDL2 or equivalent | -- |

## Hardware Requirements

### Minimum
- AmigaOS 3.x (Kickstart 3.1+)
- 68020 CPU
- RTG graphics card (Picasso96 or CyberGraphX)
- AHI audio system
- 4 MB Fast RAM minimum (8+ MB recommended)

### AGA Backend (Phase 6)
- AGA chipset (A1200, A4000) -- no RTG card needed
- Chunky-to-planar conversion (from SDL 1.2 68k port)
- Slower than RTG but reaches more machines

### Recommended
- 68040+ or accelerator (PiStorm, Vampire)
- 16+ MB Fast RAM
- RTG card or SAGA (Vampire)

## Building

```bash
make setup-toolchain   # Pull bebbo-gcc Docker image
make                   # Build libSDL2.a
make examples          # Build test/example programs
make test              # Test via FS-UAE with RTG
make clean             # Remove build artifacts
```

**Prerequisites:** Docker (for cross-compiler), Python + amitools (for vamos smoke tests), FS-UAE (for RTG testing).

## Architecture

SDL2 backends map to AmigaOS subsystems:

| SDL2 Subsystem | AmigaOS Backend | Reference Code |
|----------------|----------------|----------------|
| Video | CyberGraphX / Picasso96 (RTG) | SDL 1.2 68k `SDL_cgxvideo.c` |
| Video (AGA) | Custom chipset + c2p | SDL 1.2 68k `SDL_agavideo.c` |
| Audio | AHI (Audio Hardware Interface) | SDL 1.2 68k `SDL_ahiaudio.c` |
| Threading | Exec Tasks + SignalSemaphore | SDL 1.2 68k `SDL_sys*.c` |
| Timer | timer.device / ReadEClock | SDL 1.2 68k `SDL_systimer.c` |
| Input | Intuition IDCMP messages | SDL2 OS4 `SDL_os4events.c` |
| Joystick | gameport.device | SDL 1.2 68k joystick backend |
| Filesystem | dos.library | SDL2 OS4 filesystem backend |
| Render | Software renderer (built-in) | SDL2 upstream |

### Key Design Decisions

- **C99 required** (`-std=gnu99`). SDL2 requires C99; bebbo-gcc supports it.
- **`SDL_DYNAMIC_API` disabled** -- AmigaOS 3.x has no `dlopen()`.
- **Threading via Exec Tasks** -- `CreateNewProc()`, `SignalSemaphore`, Exec signals. Proven by SDL 1.2 68k.
- **RTG-first** -- CyberGraphX/P96 is the primary video target. AGA c2p is Phase 6.

## Reference Code

Three existing codebases provide ~80% of the implementation:

- **[SDL 1.2 for 68k](https://github.com/AmigaPorts/libSDL12)** -- CyberGraphX, AHI, Exec Tasks (proven, shipping)
- **[SDL 1.2 HenrykRichter fork](https://github.com/HenrykRichter/libSDL12_Amiga68k)** -- additional fixes
- **[SDL2 for AmigaOS 4](https://github.com/AmigaPorts/SDL)** -- OS4 backend structure (PPC, but same API surface)

## Relationship to amiport

This is a standalone library. Once functional, [amiport](https://github.com/bdgscotland/amiport) gains SDL2 as a dependency for graphical port candidates (Category 6). The library itself is not built through the amiport pipeline.

## License

zlib license (matches SDL upstream). See [LICENSE](LICENSE).

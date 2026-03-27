# libSDL2-amigaos3

**SDL2 for AmigaOS 3.x on Motorola 68k** -- CyberGraphX video, AHI audio, Exec Task threading.

The first open-source SDL2 implementation for classic Amiga hardware.

## Status

**Phase 0: Bootstrap COMPLETE** -- `libSDL2.a` compiles (117 files, 1.2 MB), `SDL_Init(0)` returns 0, all tests pass on vamos.

### Subsystem Status (Boot Matrix)

| Subsystem | Status | Backend | Phase |
|-----------|--------|---------|-------|
| **Core** | Working | SDL_Init/SDL_Quit/SDL_GetError | 0 |
| **Video** | Stub | CyberGraphX (registered, not implemented) | 1 |
| **Audio** | Stub | AHI (registered, returns unavailable) | 3 |
| **Threading** | Working | Exec Tasks (SignalSemaphore, Signal/Wait, CreateNewProc) | 0 |
| **Atomics** | Working | 68020+ CAS instruction (inline asm) | 0 |
| **Timer** | Stub | timer.device/ReadEClock (returns 0) | 1 |
| **Joystick** | Stub | gameport.device (reports 0 joysticks) | 5 |
| **Filesystem** | Stub | dos.library (returns NULL) | 1 |
| **Haptic** | Disabled | No hardware | -- |
| **Sensor** | Disabled | No hardware | -- |
| **Loadso** | Disabled | No dlopen on AmigaOS 3.x | -- |
| **Render** | Compiled | Software renderer (built-in) | 1 |

### Phase Roadmap

| Phase | Deliverable | Milestone Test | Status |
|-------|-------------|----------------|--------|
| **0: Bootstrap** | libSDL2.a compiles, SDL_Init works | 11/11 tests pass on vamos | **DONE** |
| **1: First Pixels** | CyberGraphX video + software render | testsprite2 draws on FS-UAE | Next |
| **2: Input** | IDCMP -> SDL events | testkeys responds to input | -- |
| **3: Audio** | AHI audio backend | loopwave plays a WAV | -- |
| **4: Threading** | Full thread testing on FS-UAE | testthread create/join | -- |
| **5: Polish** | Timer, filesystem, joystick | Simple SDL2 game runs | -- |
| **6: Optimization** | AGA c2p, AMMX blitters | Performance targets | -- |

## Hardware Requirements

### Minimum
- AmigaOS 3.x (Kickstart 3.1+)
- **68030 CPU** (minimum target)
- RTG graphics card (CyberGraphX)
- AHI audio system
- 4 MB Fast RAM (8+ MB recommended)

### Recommended
- 68040+ or accelerator (PiStorm, Vampire)
- 16+ MB Fast RAM
- RTG card or SAGA (Vampire)

## Building

```bash
make setup-toolchain   # Pull bebbo-gcc Docker image
make                   # Build libSDL2.a (cross-compile via Docker)
make examples          # Build test programs
make clean             # Remove build artifacts
```

**Test on vamos:**
```bash
vamos -C 68020 -s 32 -m 8192 examples/test_init
```
(vamos -C 68020 is correct: 68030 integer ISA == 68020)

**Prerequisites:** Docker, Python + amitools (vamos), FS-UAE (Phase 1+).

## Architecture

SDL2 backends map to AmigaOS subsystems:

| SDL2 Subsystem | AmigaOS Backend | API |
|----------------|----------------|-----|
| Video | CyberGraphX | WritePixelArray, screen modes |
| Audio | AHI | AHI_AllocAudio, callbacks |
| Threading | Exec Tasks | CreateNewProc, SignalSemaphore, Signal/Wait |
| Atomics | 68020+ CAS | Hardware compare-and-swap (inline asm) |
| Timer | timer.device | ReadEClock |
| Input | Intuition IDCMP | IDCMP_RAWKEY, IDCMP_MOUSEMOVE |
| Joystick | gameport.device | GPD_ASKCTYPE |
| Filesystem | dos.library | Lock, Examine, PROGDIR: |
| Render | Software | SDL2 built-in software renderer |

### Key Design Decisions

- **Target: 68030 minimum** -- all RTG setups have 68030+
- **C99 required** (`-std=gnu99`), SDL2 needs C99; bebbo-gcc supports it
- **`SDL_DYNAMIC_API=0`** -- no dlopen on AmigaOS 3.x
- **CAS atomics** -- 68020+ hardware compare-and-swap, no Forbid/Permit
- **Exec Tasks threading** -- CreateNewProc, SignalSemaphore, Exec signals
- **CyberGraphX only** for Phase 0-1 (P96 compatibility later)

## Reference Code

- **[SDL 1.2 for 68k](https://github.com/AmigaPorts/libSDL12)** -- proven CyberGraphX, AHI, Exec Tasks backends
- **[SDL2 for AmigaOS 4](https://github.com/AmigaPorts/SDL)** -- SDL2 backend structure reference (PPC)
- **[SDL2 Porting Guide](https://wiki.libsdl.org/SDL2/README-porting)** -- official backend documentation

## License

zlib license (matches SDL upstream). See [LICENSE](LICENSE).

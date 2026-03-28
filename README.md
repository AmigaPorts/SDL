# libSDL2-amigaos3

**SDL2 for AmigaOS 3.x on Motorola 68k** -- CyberGraphX video, Paula/AHI audio, Exec Task threading.

The first open-source SDL2 implementation for classic Amiga hardware.

## Status

**Phase 4: Threading COMPLETE** -- Video, input, timer, audio, and threading all working on FS-UAE with RTG. 17/17 automated tests pass (10 vamos + 17 FS-UAE), including 6 upstream SDL2 test programs.

### Subsystem Status

| Subsystem | Status | Backend | Phase |
|-----------|--------|---------|-------|
| **Core** | Working | SDL_Init/SDL_Quit/SDL_GetError | 0 |
| **Video** | Working | CyberGraphX (WritePixelArray framebuffer) | 1 |
| **Input** | Working | Intuition IDCMP (keyboard, mouse, window events) | 2 |
| **Audio** | Working | Paula audio.device (8-bit mono, CHIP RAM DMA) | 3 |
| **Audio** | Blocked | AHI (correct code, FS-UAE has dead stub) | 3 |
| **Threading** | Working | Exec Tasks (CreateNewProc, Signal/Wait join) | 4 |
| **Atomics** | Working | Forbid/Permit emulated CAS (single-core safe) | 0 |
| **Timer** | Working | timer.device/ReadEClock (709 KHz monotonic) | 1 |
| **Joystick** | Stub | gameport.device (reports 0 joysticks) | 5 |
| **Filesystem** | Stub | dos.library (returns NULL) | 5 |
| **Haptic** | Disabled | No hardware | -- |
| **Sensor** | Disabled | No hardware | -- |
| **Loadso** | Disabled | No dlopen on AmigaOS 3.x | -- |
| **Render** | Working | Software renderer (SDL2 built-in) | 1 |

### Phase Roadmap

| Phase | Deliverable | Milestone Test | Status |
|-------|-------------|----------------|--------|
| **0: Bootstrap** | libSDL2.a compiles, SDL_Init works | 11/11 tests pass on vamos | **DONE** |
| **1: First Pixels** | CyberGraphX video + software render | test_sprite draws on FS-UAE | **DONE** |
| **2: Input** | IDCMP -> SDL events | test_events responds to input | **DONE** |
| **3: Audio** | Paula audio backend | test_audio plays 440 Hz tone | **DONE** |
| **4: Threading** | Full thread testing on FS-UAE | 17/17 tests pass (incl. upstream) | **DONE** |
| **5: Polish** | Timer, filesystem, joystick | Simple SDL2 game runs | -- |
| **6: Optimization** | AGA c2p, AMMX blitters | Performance targets | -- |

### Audio Driver Details

Two audio backends are implemented:

- **Paula (audio.device)** -- Primary driver. Uses native Paula DMA with CHIP RAM double-buffering. Works on all Amigas including FS-UAE. 8-bit signed mono, up to 22050 Hz.
- **AHI** -- Secondary driver. Uses the AHI retargetable audio system for 16-bit stereo on sound cards. Code is complete and correct but FS-UAE's AHI emulation is a non-functional stub from 1999. Works on real hardware with AHI installed.

Bootstrap order: Paula -> AHI -> Dummy. SDL2's audio conversion layer handles format conversion (e.g., S16 -> S8) transparently.

## Hardware Requirements

### Minimum
- AmigaOS 3.x (Kickstart 3.1+)
- **68030 CPU** (minimum target -- RTG cards require 68020+)
- RTG graphics card (CyberGraphX or Picasso96)
- 4 MB Fast RAM (8+ MB recommended)

### Recommended
- 68040+ or accelerator (PiStorm, Vampire)
- 16+ MB Fast RAM
- RTG card or SAGA (Vampire)
- AHI audio system (for 16-bit sound on real hardware)

## Building

```bash
make setup-toolchain   # Pull bebbo-gcc Docker image
make                   # Build libSDL2.a (cross-compile via Docker)
make examples          # Build test programs
make test              # Run vamos smoke tests (no GUI)
make test-fsemu        # Run full FS-UAE test suite (RTG + audio)
make clean             # Remove build artifacts
```

**Prerequisites:** Docker, Python + amitools (vamos), FS-UAE (for visual/audio tests).

**Single test:**
```bash
make test-fsemu TEST=test_audio
```

## Architecture

SDL2 backends map to AmigaOS subsystems:

| SDL2 Subsystem | AmigaOS Backend | API |
|----------------|----------------|-----|
| Video | CyberGraphX | WritePixelArray, screen modes |
| Audio (Paula) | audio.device | CMD_WRITE, BeginIO/WaitIO, CHIP RAM DMA |
| Audio (AHI) | ahi.device | CMD_WRITE, SendIO, double-buffered |
| Threading | Exec Tasks | CreateNewProc, SignalSemaphore, Signal/Wait join |
| Atomics | Forbid/Permit | Emulated CAS (single-core cooperative) |
| Timer | timer.device | ReadEClock |
| Input | Intuition IDCMP | IDCMP_RAWKEY, IDCMP_MOUSEMOVE |
| Joystick | gameport.device | GPD_ASKCTYPE |
| Filesystem | dos.library | Lock, Examine, PROGDIR: |
| Render | Software | SDL2 built-in software renderer |

### Key Design Decisions

- **Target: 68030 minimum** -- all RTG setups have 68030+
- **C99 required** (`-std=gnu99`), SDL2 needs C99; bebbo-gcc supports it
- **`SDL_DYNAMIC_API=0`** -- no dlopen on AmigaOS 3.x
- **`-O0` default** -- bebbo-gcc has codegen bugs at -O1/-O2 (struct return corruption)
- **Forbid/Permit atomics** -- emulated CAS via task-switch inhibition (single-core safe)
- **Signal-based thread join** -- child signals parent before exit per ADCD III-17 pattern; Forbid() prevents race during DOS process cleanup
- **Lazy device open** -- MsgPort created in audio thread context (AmigaOS signals are task-relative)
- **Paula first, AHI second** -- Paula works on all emulators; AHI for real hardware sound cards

## Reference Code

- **[SDL 1.2 for 68k](https://github.com/AmigaPorts/libSDL12)** -- proven CyberGraphX and AHI backends
- **[SDL2 for AmigaOS 4](https://github.com/AmigaPorts/SDL)** -- SDL2 backend structure reference (PPC)
- **[SDL2 Porting Guide](https://wiki.libsdl.org/SDL2/README-porting)** -- official backend documentation

## License

zlib license (matches SDL upstream). See [LICENSE](LICENSE).

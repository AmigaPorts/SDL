# libSDL2-amigaos3

**SDL2 for AmigaOS 3.x on Motorola 68k** -- CyberGraphX video, Paula audio, SDL_Renderer, Exec Task threading.

The first open-source SDL2 implementation for classic Amiga hardware.

## Status

**Phase 4: Threading COMPLETE** -- All major subsystems working on FS-UAE with RTG. 20/20 automated tests pass. **game_2048 is playable** (first real SDL2 game on our port).

### Subsystem Status

| Subsystem | Status | Backend | Phase |
|-----------|--------|---------|-------|
| **Core** | Working | SDL_Init/SDL_Quit/SDL_GetError | 0 |
| **Video** | Working | CyberGraphX (WritePixelArray framebuffer) | 1 |
| **Renderer** | Working | Software renderer (SDL_RenderFillRect, RenderCopy, etc.) | 4 |
| **Input** | Working | Intuition IDCMP (keyboard, mouse, window events) | 2 |
| **Audio** | Working | Paula audio.device (8-bit mono, CHIP RAM DMA) | 3 |
| **Audio** | Blocked | AHI (correct code, FS-UAE has dead stub) | 3 |
| **Threading** | Working | Exec Tasks (CreateNewProc, Signal/Wait join) | 4 |
| **Atomics** | Working | Forbid/Permit emulated CAS (single-core safe) | 0 |
| **Timer** | Working | timer.device/ReadEClock (709 KHz monotonic) | 1 |
| **Float** | Working | Software IEEE 754 (bypasses broken ROM math libs) | 4 |
| **Joystick** | Stub | gameport.device (reports 0 joysticks) | 5 |
| **Filesystem** | Stub | dos.library (SDL_GetBasePath returns NULL) | 5 |
| **Haptic** | Disabled | No hardware | -- |
| **Sensor** | Disabled | No hardware | -- |
| **Loadso** | Disabled | No dlopen on AmigaOS 3.x | -- |

### Test Suite

| Category | Count | Platform |
|----------|-------|----------|
| **Automated (pass)** | 20 | FS-UAE (all), vamos (10) |
| **Manual/Interactive** | 15 | FS-UAE only, run individually |
| **Upstream SDL2 tests** | 19 | From libsdl-org/SDL SDL2 branch |
| **Custom tests** | 14 | test_sprite, test_gameloop, test_threads, etc. |
| **Games** | 1 | game_2048 (SDL_Renderer, playable) |

### Phase Roadmap

| Phase | Deliverable | Milestone Test | Status |
|-------|-------------|----------------|--------|
| **0: Bootstrap** | libSDL2.a compiles, SDL_Init works | 11/11 tests pass on vamos | **DONE** |
| **1: First Pixels** | CyberGraphX video + software render | test_sprite draws on FS-UAE | **DONE** |
| **2: Input** | IDCMP -> SDL events | test_events responds to input | **DONE** |
| **3: Audio** | Paula audio backend | test_audio plays 440 Hz tone | **DONE** |
| **4: Threading** | Full thread + renderer testing | 20/20 tests, game_2048 playable | **DONE** |
| **5: Polish** | Filesystem, joystick, SDL_GetBasePath | Chocolate Doom boots | Next |
| **6: Optimization** | AGA c2p, AMMX, FPU build variant | Performance targets | -- |

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
make                   # Build libSDL2.a + libSDL2_test.a (cross-compile via Docker)
make examples          # Build test programs + upstream SDL2 tests + games
make test              # Run vamos smoke tests (no GUI)
make test-fsemu        # Run full FS-UAE test suite (RTG + audio)
make clean             # Remove build artifacts
```

**Prerequisites:** Docker, Python + amitools (vamos), FS-UAE (for visual/audio tests).

**Single test:**
```bash
make test-fsemu TEST=test_audio     # Run one automated test
make test-fsemu TEST=game_2048      # Run interactive game
```

## Architecture

SDL2 backends map to AmigaOS subsystems:

| SDL2 Subsystem | AmigaOS Backend | API |
|----------------|----------------|-----|
| Video | CyberGraphX | WritePixelArray, screen modes |
| Renderer | Software (SDL2 built-in) | SDL_RenderFillRect, SDL_RenderCopy, SDL_RenderPresent |
| Audio (Paula) | audio.device | CMD_WRITE, BeginIO/WaitIO, CHIP RAM DMA |
| Audio (AHI) | ahi.device | CMD_WRITE, SendIO, double-buffered |
| Threading | Exec Tasks | CreateNewProc, SignalSemaphore, Signal/Wait join |
| Atomics | Forbid/Permit | Emulated CAS (single-core cooperative) |
| Timer | timer.device | ReadEClock (709 KHz on PAL) |
| Input | Intuition IDCMP | IDCMP_RAWKEY, IDCMP_MOUSEMOVE |
| Float | Software IEEE 754 | Pure integer __divsf3/__mulsf3/__addsf3 |
| Joystick | gameport.device | GPD_ASKCTYPE |
| Filesystem | dos.library | Lock, Examine, PROGDIR: |

### Key Design Decisions

See `docs/adr/` for full Architecture Decision Records. Key decisions:

- **ADR-001: Target 68030 minimum** -- all RTG setups have 68030+
- **ADR-002: SDL_DYNAMIC_API=0** -- no dlopen on AmigaOS 3.x
- **ADR-003: Compile at -O0** -- bebbo-gcc codegen bugs at -O1/-O2
- **ADR-004: Forbid/Permit atomics** -- single-core makes this safe
- **ADR-005: Signal-based thread join** -- ADCD III-17 pattern, child signals parent before exit
- **ADR-006: Paula first, AHI second** -- Paula works on all emulators
- **ADR-007: Lazy device open** -- MsgPort in worker thread context (signals are task-relative)
- **ADR-008: Test tier system** -- 1=vamos, 2=FS-UAE, 12=both, M=manual
- **ADR-009: Upstream test integration** -- -include preamble header, libSDL2_test.a
- **ADR-010: Software float library** -- bypasses broken ROM mathieeesingbas.library on FS-UAE

### Audio Driver Details

Two audio backends are implemented:

- **Paula (audio.device)** -- Primary driver. Uses native Paula DMA with CHIP RAM double-buffering. Works on all Amigas including FS-UAE. 8-bit signed mono, up to 22050 Hz.
- **AHI** -- Secondary driver. Uses the AHI retargetable audio system for 16-bit stereo on sound cards. Code is complete and correct but FS-UAE's AHI emulation is a non-functional stub from 1999. Works on real hardware with AHI installed.

Bootstrap order: Paula -> AHI -> Dummy. SDL2's audio conversion layer handles format conversion (e.g., S16 -> S8) transparently.

### Debug Infrastructure

- **SDL_Log** writes to `WORK:sdl_log.txt` (survives crashes, read from host after FS-UAE exit)
- **DLOG()** macro writes to `WORK:sdl_debug.log` (for backend code, uses Forbid/Permit)
- **test_render_debug** -- step-by-step renderer debugging test
- All debug output persists across Guru crashes -- no screenshot dependency

## Reference Code

- **[SDL 1.2 for 68k](https://github.com/AmigaPorts/libSDL12)** -- proven CyberGraphX and AHI backends
- **[SDL2 for AmigaOS 4](https://github.com/AmigaPorts/SDL)** -- SDL2 backend structure reference (PPC)
- **[SDL2 Porting Guide](https://wiki.libsdl.org/SDL2/README-porting)** -- official backend documentation

## License

zlib license (matches SDL upstream). See [LICENSE](LICENSE).

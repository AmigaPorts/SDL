# libSDL2-amigaos3

**SDL2 for AmigaOS 3.x on Motorola 68k** -- CyberGraphX video, Paula audio, SDL_Renderer, Exec Task threading.

The first open-source SDL2 implementation for classic Amiga hardware.

## Status

**Phase 4 COMPLETE. Phase 5 in progress.** All major subsystems working on FS-UAE with RTG. Two games playable (game_2048, game_snake). SDL_Texture streaming pipeline validated -- ready for Chocolate Doom.

### SDL2 API Coverage Heatmap

```
Subsystem       Coverage  Status    What Works
------------------------------------------------------------
Video            65%      WORKING   Window, fullscreen, framebuffer, events
Renderer (SW)   100%      WORKING   FillRect, DrawLine, RenderCopy, textures
Audio (Paula)    85%      WORKING   8-bit playback, CHIP RAM DMA
Audio (AHI)      85%      BLOCKED   Code correct, FS-UAE stub broken
Threading        95%      WORKING   Mutex, semaphore, condvar, TLS
Timer           100%      WORKING   GetTicks, Delay, PerfCounter
Atomics         100%      WORKING   Forbid/Permit CAS (single-core)
Float           100%      WORKING   Software IEEE 754 (__divsf3 etc)
Input           100%      WORKING   Keyboard, mouse, window events
Joystick          0%      STUB      Reports 0 joysticks (Phase 5)
Filesystem        0%      STUB      GetBasePath/GetPrefPath return NULL
Haptic            --      N/A       No hardware
Sensor            --      N/A       No hardware
Loadso            --      N/A       No dlopen on AmigaOS 3.x
------------------------------------------------------------
OVERALL          ~74%               Ready for real game ports
```

### What's Validated

| Feature | Test | Result |
|---------|------|--------|
| SDL_Init / SDL_Quit | test_init (11 subtests) | PASS |
| SDL_CreateWindow (windowed) | test_video | PASS |
| SDL_CreateWindow (fullscreen) | game_snake | PASS |
| SetWindowFullscreen (toggle) | game_snake | PASS |
| SDL_CreateRenderer (software) | test_render | PASS |
| SDL_RenderFillRect | game_2048, game_snake | PASS |
| SDL_RenderDrawLine | game_snake (score) | PASS |
| SDL_CreateTexture (STREAMING) | test_texture | PASS |
| SDL_LockTexture / UnlockTexture | test_texture | PASS |
| SDL_RenderCopy (texture->screen) | test_texture | PASS |
| SDL_RenderSetLogicalSize | game_snake, test_texture | PASS |
| SDL_PollEvent (keyboard) | test_events, games | PASS |
| SDL_PollEvent (mouse) | test_events | PASS |
| SDL_GetTicks / SDL_Delay | test_timer | PASS |
| SDL_OpenAudioDevice (Paula) | test_audio | PASS |
| SDL_CreateThread / WaitThread | test_threads | PASS |
| SDL_CreateMutex / Lock / Unlock | testlock | PASS |
| SDL_CreateSemaphore | testsem | PASS |
| SDL_LoadBMP | test_bmpview | PASS |
| Forbid/Permit atomics | testatomic (basic) | PASS |

### What's Missing (for Chocolate Doom)

| Feature | Blocker? | Fix |
|---------|----------|-----|
| SDL_GetBasePath | Yes | Return `PROGDIR:` (Phase 5) |
| SDL_GetPrefPath | Yes | Return `ENVARC:{org}/{app}/` (Phase 5) |
| SDL_SetRelativeMouseMode | Maybe | Need to implement for FPS games |
| SDL_WarpMouseInWindow | Maybe | SetWindowPointer or manual |
| SDL_ShowSimpleMessageBox | No | Can stub (returns error string) |
| SDL_SetWindowIcon | No | Ignored on Amiga |

### Test Suite

| Category | Count | Platform |
|----------|-------|----------|
| **Automated (pass)** | 20 | FS-UAE (all), vamos (11) |
| **Manual/Interactive** | 15 | FS-UAE only, run individually |
| **Upstream SDL2 tests** | 19 | From libsdl-org/SDL SDL2 branch |
| **Custom tests** | 16 | Including test_texture (Doom path) |
| **Games** | 2 | game_2048 (tiles), game_snake (arcade) |

### Phase Roadmap

| Phase | Deliverable | Milestone Test | Status |
|-------|-------------|----------------|--------|
| **0: Bootstrap** | libSDL2.a compiles, SDL_Init works | 11/11 tests pass on vamos | DONE |
| **1: First Pixels** | CyberGraphX video + software render | test_sprite draws on FS-UAE | DONE |
| **2: Input** | IDCMP -> SDL events | test_events responds to input | DONE |
| **3: Audio** | Paula audio backend | test_audio plays 440 Hz tone | DONE |
| **4: Threading** | Full thread + renderer + games | 20/20 tests, 2 games playable | DONE |
| **5: Polish** | Filesystem, textures, Doom prep | Chocolate Doom boots | **IN PROGRESS** |
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

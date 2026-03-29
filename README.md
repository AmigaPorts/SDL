# libSDL2-amigaos3

**SDL2 for AmigaOS 3.x on Motorola 68k** -- the first open-source SDL2 for classic Amiga hardware.

## Status: Phase 5 (Polish)

Two games playable. SDL_Texture streaming pipeline validated. Next target: [Chocolate Doom](https://github.com/bdgscotland/chocolate-doom).

### API Coverage

```
Subsystem       Coverage  Status    What Works
------------------------------------------------------------
Video            65%      WORKING   Window, fullscreen, framebuffer
Renderer (SW)   100%      WORKING   FillRect, DrawLine, RenderCopy, textures
Audio (Paula)    85%      WORKING   8-bit playback, CHIP RAM DMA
Audio (AHI)      85%      BLOCKED   Code correct, FS-UAE stub broken
Threading        95%      WORKING   Mutex, semaphore, condvar, TLS
Timer           100%      WORKING   GetTicks, Delay, PerfCounter
Atomics         100%      WORKING   Forbid/Permit CAS (single-core)
Float           100%      WORKING   Software IEEE 754
Input           100%      WORKING   Keyboard, mouse, window events
Joystick          0%      STUB      Phase 5
Filesystem        0%      STUB      Phase 5
------------------------------------------------------------
OVERALL          ~74%               Ready for real game ports
```

### Validated Features

| Feature | Test |
|---------|------|
| SDL_CreateWindow (windowed + fullscreen) | test_video, game_snake |
| SetWindowFullscreen (mode toggle) | game_snake |
| SDL_CreateTexture (STREAMING) | test_texture |
| SDL_LockTexture + SDL_RenderCopy | test_texture |
| SDL_RenderSetLogicalSize | game_snake, test_texture |
| SDL_RenderFillRect / DrawLine | game_2048, game_snake |
| SDL_PollEvent (keyboard, mouse) | test_events, games |
| SDL_OpenAudioDevice (Paula) | test_audio |
| SDL_CreateThread / WaitThread | test_threads |
| SDL_CreateMutex / Semaphore / CondVar | testlock, testsem |
| SDL_GetTicks / SDL_Delay | test_timer |
| SDL_LoadBMP | test_bmpview |

### Test Suite

| Category | Count | Platform |
|----------|-------|----------|
| Automated (pass) | 20 | FS-UAE + vamos |
| Manual/Interactive | 15 | FS-UAE only |
| Games | 2 | game_2048, game_snake |

### Roadmap

| Phase | Status |
|-------|--------|
| 0: Bootstrap (SDL_Init, stubs) | DONE |
| 1: First Pixels (CyberGraphX) | DONE |
| 2: Input (IDCMP events) | DONE |
| 3: Audio (Paula) | DONE |
| 4: Threading (Exec Tasks) | DONE |
| 5: Polish (filesystem, Doom prep) | **IN PROGRESS** |
| 6: Optimization (AGA, AMMX) | -- |

## Hardware Requirements

- AmigaOS 3.x (Kickstart 3.1+)
- 68030+ CPU with RTG graphics card (CyberGraphX or Picasso96)
- 4 MB Fast RAM (8+ MB recommended)

## Building

```bash
make setup-toolchain   # Pull bebbo-gcc Docker image
make                   # Build libSDL2.a (cross-compile via Docker)
make examples          # Build tests + games
make test              # Run vamos smoke tests
make test-fsemu        # Run FS-UAE test suite (RTG)
```

**Prerequisites:** Docker, Python + amitools (vamos), FS-UAE (for visual tests).

```bash
make test-fsemu TEST=game_snake    # Run a single test/game
```

## Architecture

| SDL2 Subsystem | AmigaOS Backend |
|----------------|-----------------|
| Video | CyberGraphX (WritePixelArray) |
| Audio | Paula audio.device / AHI |
| Threading | Exec Tasks (CreateNewProc, SignalSemaphore) |
| Timer | timer.device (ReadEClock 709 KHz) |
| Input | Intuition IDCMP |
| Float | Software IEEE 754 (bypasses broken ROM libs) |
| Renderer | SDL2 built-in software renderer |

See `docs/adr/` for Architecture Decision Records.

## References

- [SDL 1.2 for 68k](https://github.com/AmigaPorts/libSDL12) -- proven AmigaOS backends
- [SDL2 for AmigaOS 4](https://github.com/AmigaPorts/SDL) -- SDL2 backend reference (PPC)
- [SDL2 Porting Guide](https://wiki.libsdl.org/SDL2/README-porting)

## License

zlib license (matches SDL upstream). See [LICENSE](LICENSE).

# libSDL2 for AmigaOS 3.x -- Port Plan

## Phase 0: Bootstrap [COMPLETE]

- [x] Vendor SDL2 2.33.0 source (1197 files, 447K lines)
- [x] SDL_config_amigaos3.h platform config
- [x] SDL_platform.h __AMIGAOS3__ detection
- [x] Backend stubs wired to bootstrap arrays (video, audio, joystick)
- [x] Exec Tasks threading (SignalSemaphore mutex, Signal/Wait condvar, TLS)
- [x] Forbid/Permit spinlock (replaces CAS -- simpler on cooperative single-core)
- [x] SDL_Delay via dos.library Delay() (real yield for cooperative multitasking)
- [x] SDL_Init(0) returns 0 on vamos -C 68020
- [x] 11/11 tests pass on vamos

## Phase 1: First Pixels [COMPLETE]

- [x] CyberGraphX V4 reference doc (1184 lines)
- [x] OS3_VideoInit -- open graphics/intuition/cybergraphics libraries
- [x] Display mode enumeration (NextDisplayInfo + IsCyberModeID + GetCyberIDAttr)
- [x] OS3_CreateWindow -- Intuition window on RTG WB screen or custom RTG screen
- [x] OS3_CreateWindowFramebuffer -- ARGB8888 SDL_Surface + WritePixelArray blit
- [x] OS3_UpdateWindowFramebuffer -- RECTFMT_ARGB dirty rect updates
- [x] OS3_DestroyWindowFramebuffer -- surface cleanup
- [x] OS3_PumpEvents -- IDCMP rawkey/mouse/window event pump
- [x] TLS lazy InitSemaphore fix (deadlock on real AmigaOS, silent on vamos)
- [x] P96 v2.0 + uaegfx monitor driver setup for FS-UAE
- [x] Picasso96API.library fallback when cybergraphics.library unavailable
- [x] WB RTG screen detection with custom screen fallback for AGA WB
- [x] test_video: colored quadrants on A4000/040 FS-UAE with RTG
- [x] FS-UAE config: A4000/040, Zorro III, 128MB RAM, 16MB RTG VRAM

## Phase 1.5: Automated Test Infrastructure [TODO -- CRITICAL PATH]

Autonomous closed-loop testing is required before Phase 2+. Manual FS-UAE
testing does not scale. The goal: `make test-fsemu` runs all tests, captures
results, reports pass/fail -- no human in the loop.

### State Machine

```
  [Build]          [Deploy]           [Boot]            [Execute]         [Capture]
make examples --> cp to WORK: --> FS-UAE boots --> ARexx runs test --> Results to WORK:
                                      |                    |                  |
                                      v                    v                  v
                                 P96 RTG init      test writes output    UAEQuit exits
                                 Shell ready       to WORK:result.txt   FS-UAE cleanly
                                                                             |
                                                                             v
                                                                      [Host reads result]
                                                                      Parse pass/fail
                                                                      Report TAP output
```

### Steps

- [ ] **Bootable system with auto-login shell**
  - S:User-Startup runs test harness automatically after boot
  - No manual Shell window opening required
  - P96 uaegfx initializes at boot (Devs:Monitors/uaegfx)

- [ ] **ARexx test harness** (port from amiport pattern)
  - `WORK:run_tests.rexx` -- master script that runs each test binary
  - Each test writes `>WORK:<testname>_result.txt` with stdout/stderr
  - Exit code captured via `RC` variable after ADDRESS COMMAND
  - Final summary written to `WORK:test_summary.txt`
  - `WORK:UAEQuit` called after all tests complete

- [ ] **Host-side test runner** (`scripts/test-fsemu.sh`)
  - Builds examples via Docker (`make examples`)
  - Copies binaries + ARexx scripts to `build/amiga/`
  - Clears previous result files
  - Launches FS-UAE with `sdl2-test.fs-uae`
  - Polls for `WORK:test_summary.txt` (with timeout)
  - Parses results into TAP format
  - Reports pass/fail to stdout
  - Returns exit code 0 (all pass) or 1 (any fail)
  - Kills FS-UAE if timeout exceeded

- [ ] **Sentinel-based shutdown** (no arbitrary timeouts)
  - ARexx harness writes `WORK:tests_done` sentinel file after UAEQuit
  - Host polls for sentinel, not fixed sleep
  - Timeout is a fallback for crashes/hangs, not normal flow

- [ ] **Screenshot capture for visual tests**
  - FS-UAE `FSEMU_SCREENSHOTS_DIR` env var points to results dir
  - ARexx triggers F12 (or configured key) for screenshots
  - Host compares screenshots against reference images (future)

- [ ] **Test categories**
  - SMOKE: SDL_Init/SDL_Quit -- must pass for any other test to run
  - UNIT: spinlock, atomic, TLS, mutex, semaphore, timer
  - VIDEO: window creation, framebuffer blit, display modes
  - INPUT: keyboard events, mouse events, window events (Phase 2+)
  - AUDIO: AHI playback, format conversion (Phase 3+)
  - INTEGRATION: multi-subsystem tests (Phase 4+)

- [ ] **Failure detection**
  - Guru Meditation: FS-UAE serial output or log grep for "GURU\|Alert"
  - Hang: test timeout (per-test, not global)
  - Crash: result file missing or empty after timeout
  - Wrong output: result file content doesn't match expected

- [ ] **Makefile integration**
  - `make test` -- vamos smoke tests (fast, no GUI)
  - `make test-fsemu` -- full FS-UAE test suite (slow, RTG)
  - `make test-fsemu TARGET=test_video` -- single test
  - Both return proper exit codes for CI

- [ ] **FS-UAE instance isolation**
  - Never `pkill -f fs-uae` (kills other sessions)
  - Use PID file: `build/fs-uae-state/fs-uae.pid`
  - Kill only our PID on cleanup
  - Separate state_dir per invocation if needed

### Test Binaries Needed

| Binary | Category | What it tests | Pass criteria |
|--------|----------|---------------|---------------|
| test_init | SMOKE | SDL_Init(0), SDL_Quit | RC=0, "tests passed" |
| test_spinlock | UNIT | AtomicLock, CAS, SetError, Init(0) | RC=0, all steps print |
| test_video | VIDEO | Window, framebuffer, WritePixelArray | RC=0, window opened |
| test_events | INPUT | Key/mouse event receipt (Phase 2) | RC=0, events logged |
| test_audio | AUDIO | AHI playback (Phase 3) | RC=0, no underruns |
| test_thread | UNIT | CreateThread, join, mutex contention | RC=0, thread completed |
| test_timer | UNIT | GetTicks, Delay precision (Phase 5) | RC=0, timing within 20% |

## Phase 2: Input

- [ ] Verify rawkey -> SDL scancode table on FS-UAE (table implemented, untested)
- [ ] Keyboard repeat handling
- [ ] Mouse wheel (IDCMP_EXTENDEDMOUSE if available)
- [ ] Window resize events (IDCMP_NEWSIZE -- handler exists, needs testing)
- [ ] Window drag/move events
- [ ] test_events example + automated verification
- [ ] Qualifier keys (shift/ctrl/alt state tracking)

## Phase 3: Audio

- [ ] AHI reference doc (stub exists at docs/references/ahi-reference.md)
- [ ] OS3_AudioInit -- open AHI device, enumerate audio modes
- [ ] AHI double-buffer playback via sound hook callback
- [ ] Audio format negotiation (S16, S8, Float32 -> AHI native)
- [ ] Callback runs at interrupt level -- no alloc/dos calls
- [ ] Signal audio task from callback for buffer refill
- [ ] test_audio: sine wave or WAV playback verification
- [ ] loopwave example test

## Phase 4: Threading (stress test)

- [ ] SDL_CreateThread via CreateNewProc (implemented, untested on FS-UAE)
- [ ] Thread join/detach verification
- [ ] Condition variable broadcast under contention
- [ ] Multi-thread mutex stress test
- [ ] TLS per-thread isolation test
- [ ] test_thread automated verification

## Phase 5: Polish

- [ ] Timer: ReadEClock high-resolution SDL_GetTicks64
- [ ] Timer: SDL_AddTimer callback via timer.device TR_ADDREQUEST
- [ ] Filesystem: SDL_GetBasePath via PROGDIR:
- [ ] Filesystem: SDL_GetPrefPath via ENVARC:
- [ ] Joystick: gameport.device enumeration + input
- [ ] SDL_ShowSimpleMessageBox via EasyRequest
- [ ] test_timer: timing accuracy verification

## Phase 6: Optimization

- [ ] AGA chipset + c2p (chunky-to-planar) for non-RTG Amigas
- [ ] AMMX SIMD for Apollo/Vampire accelerators
- [ ] Per-file -O2 audit (bebbo-gcc has codegen bugs at -O1/-O2)
- [ ] LockBitMapTags direct framebuffer as WritePixelArray alternative
- [ ] Profiling on real 68030/040 hardware
- [ ] Chip RAM vs Fast RAM allocation strategy
- [ ] DMA contention avoidance for blitter operations

## Key Bugs Fixed (for reference)

| Bug | Symptom | Root Cause | Fix |
|-----|---------|------------|-----|
| TLS deadlock | SDL_Init hangs on FS-UAE | ObtainSemaphore on uninitialized SignalSemaphore | Lazy InitSemaphore in Get/SetTLSData |
| Cooperative starvation | SDL_AtomicLock spins forever | SDL_Delay(0) was no-op | dos.library Delay(0) yields timeslice |
| Grey window | WritePixelArray no visible output | WB screen in AGA mode, not RTG | Check IsCyberGfx, open custom RTG screen |
| No RTG modes | BestCModeIDTags returns INVALID_ID | P96 monitor driver name mismatch | Devs:Monitors/uaegfx (name must match board) |
| P96 Guru 8100 0008 | AN_FreeTwice on P96 API call | P96 v1.33 incompatible with FS-UAE built-in P96 | Use P96 v2.0 from Aminet |
| Z2 memory overflow | "Too large Z2 RTG memory size" | A1200 Z2 bus: 8MB shared fast+RTG | Use A4000/040 with Zorro III |

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

## Phase 1.5: Automated Test Infrastructure [COMPLETE]

Two-tier test infrastructure:

**Tier 1: vamos (fast, no GUI)** -- `make test`
- test_bare, test_init, test_spinlock run via vamos -C 68020
- ~2 seconds, no FS-UAE required
- Fails make on first test failure

**Tier 2: FS-UAE (RTG, full stack)** -- `make test-fsemu`
- ARexx harness (`scripts/amiga/run_tests.rexx`) runs all 4 tests
- S:User-Startup auto-runs harness on boot
- Sentinel-based completion detection (WORK:tests_done)
- TAP output on stdout, exit 0/1
- PID-based FS-UAE cleanup (never pkill)

**Future: Serial TCP channel** -- upgrade from sentinel polling to
`serial_port = tcp://...` for deterministic result streaming. The FS-UAE
fork at ~/Developer/fs-uae/ supports this. Deferred until Phase 2+.

### Test Binaries

| Binary | Category | Tier | What it tests | Pass criteria |
|--------|----------|------|---------------|---------------|
| test_bare | SMOKE | 1+2 | C hello world, no SDL | RC=0 |
| test_init | SMOKE | 1+2 | SDL_Init(0), SDL_Quit | RC=0 |
| test_spinlock | UNIT | 1+2 | AtomicLock, CAS, SetError, Init(0) | RC=0 |
| test_video | VIDEO | 2 | Window, framebuffer, WritePixelArray | RC=0 |
| test_events | INPUT | 2 | Key/mouse events (Phase 2) | RC=0 |
| test_audio | AUDIO | 2 | AHI playback (Phase 3) | RC=0 |
| test_timer | UNIT | 1+2 | GetTicks, Delay precision | RC=0 |

## Phase 2: Input [IN PROGRESS]

- [x] Verify rawkey -> SDL scancode table on FS-UAE (table implemented, verified)
- [x] IDCMP -> SDL event pump (RAWKEY, MOUSEBUTTONS, MOUSEMOVE, window events)
- [x] test_events example + automated verification (5/5 pass on FS-UAE)
- [x] ACTIVEWINDOW/INACTIVEWINDOW -> focus gained/lost
- [x] CLOSEWINDOW -> SDL_QUIT
- [x] NEWSIZE -> SDL_WINDOWEVENT_RESIZED (handler exists)
- [ ] Keyboard repeat handling
- [ ] Mouse wheel (IDCMP_EXTENDEDMOUSE if available)
- [ ] Qualifier keys (shift/ctrl/alt state tracking)
- [ ] Window drag/move events

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

- [x] Timer: ReadEClock high-resolution SDL_GetTicks64
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

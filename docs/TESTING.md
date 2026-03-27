# Testing SDL2 for AmigaOS 3.x

## Overview

SDL2 testing requires **FS-UAE with RTG enabled** -- the standard Amiga console is not involved. SDL2 programs open their own screens/windows via CyberGraphX/Picasso96, not console.device.

## Test Infrastructure

The test harness is shared with [amiport](https://github.com/bdgscotland/amiport) and adapted for SDL2's RTG requirements.

### Key Differences from amiport CLI Testing

| Aspect | amiport (CLI) | SDL2 (graphical) |
|--------|--------------|-----------------|
| Display | Console/Shell | RTG screen (CyberGraphX) |
| FS-UAE config | `amiport-test.fs-uae` | `sdl2-test.fs-uae` (+ `graphics_card = uaegfx`) |
| Visual verification | SCRAPE + EXPECT_AT (console ANSI) | FS-UAE screenshots + pixel comparison |
| Input injection | KeyInject (AddIEvents) or osascript | Same tooling, different target (SDL window vs console) |
| Memory | 8 MB Fast RAM | 16 MB Fast RAM (surface buffers) |
| Test output | TAP format (stdout) | Exit codes + screenshot diffs |

### FS-UAE Configuration

Use `toolchain/configs/sdl2-test.fs-uae` which enables:
- `graphics_card = uaegfx` -- virtual RTG card
- `graphics_card_memory = 16384` -- 16 MB VRAM
- `fast_memory = 16384` -- 16 MB system RAM
- `joystick_port_1_mode = nothing` -- arrow keys reach keyboard

### Forked FS-UAE

The amiport project maintains a forked FS-UAE at `~/Developer/fs-uae/` with:
- ANSI output capture (per-unit capture via custom trap)
- ScreenRead trap (mode 150) for cursor position verification
- Screenshot automation

For SDL2, the standard FS-UAE may suffice for most testing (exit code + screenshots). The forked FS-UAE's ANSI capture is console-specific and won't apply to RTG screens.

## Test Phases

### Phase 0: Smoke Test
```bash
# Compile test_init and run via vamos
make examples
vamos -s 65536 examples/test_init
# Expected: "SDL_Init: OK" / "SDL_Quit: OK"
```

### Phase 1+: Visual Tests
```bash
# Run via FS-UAE with RTG
make test-fsemu
# Captures screenshots, verifies exit codes
```

### Screenshot Comparison (Phase 5+)

FS-UAE can save screenshots via input mapping. The test harness:
1. Launches SDL2 program in FS-UAE
2. Waits for program to initialize (timing-based)
3. Triggers screenshot capture
4. Compares against reference screenshot (pixel diff)
5. Verifies clean exit

## Test Utilities

| Tool | Location | Purpose |
|------|----------|---------|
| KeyInject | `toolchain/keyinject/` | Inject keystrokes via AddIEvents() |
| ScreenRead | `toolchain/screenread/` | Read screen state via FS-UAE trap |
| UAEQuit | `toolchain/uaequit/` | Cleanly exit FS-UAE from Amiga side |
| inject-keys.sh | `scripts/` | Host-side keystroke injection via osascript |
| verify-screen.py | `scripts/` | Screen verification via pyte |
| test-fsemu.sh | `scripts/` | Main test harness orchestrator |
| doctor.sh | `scripts/` | System diagnostics (Docker, vamos, FS-UAE) |

## Debug Tools

Pre-built AmigaOS debug tools in `toolchain/debug-tools/`:
- **Enforcer** -- memory access violation detector (like AddressSanitizer)
- **MungWall** -- memory allocation tracker (fills freed memory with 0xDEADBEEF)
- **SegTracker** -- tracks which segment owns each memory address (for crash diagnosis)
- **bgdbserver** -- GDB remote debugging server

---
name: sdl2-test
description: Run SDL2 smoke tests via vamos or FS-UAE
user_invocable: true
---

# SDL2 Test

Run SDL2 tests and verify results.

## Instructions

### vamos Smoke Tests (Phase 0-1)

Run `make test` which executes test programs via vamos:
- Verify SDL_Init(0) returns 0
- Verify SDL_Init(SDL_INIT_VIDEO) returns 0 (with stubs)
- Verify SDL_Quit() does not crash
- Check exit codes (0 = success)

vamos flags:
- `-s 65536` for stack size (dos.library needs extra stack)
- `-C 68020` if binary uses 68020 instructions

### FS-UAE Visual Tests (Phase 1+)

Requires FS-UAE with RTG config:
```
graphics_card = uaegfx
graphics_card_memory = 16384
joystick_port_1_mode = nothing
```

For visual verification:
1. Launch test program in FS-UAE
2. Take screenshot for comparison
3. Verify window appears with expected content
4. Verify clean exit without Guru Meditation

### Interpreting Failures

- `ALERT: code=00068020`: Binary has 68020 instructions, vamos is in 68000 mode
- Guru Meditation: Check crash-patterns.md for the alert code
- Timeout: Check for infinite loops missing break checks
- Exit code 10/20: Check stderr output for error details

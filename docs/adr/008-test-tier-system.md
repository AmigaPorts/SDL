# ADR-008: Test Tier System

## Status

Accepted

## Date

2026-03-22

## Context

libSDL2 tests run in two different environments with very different capabilities:

1. **vamos** (from amitools): A lightweight AmigaOS emulation layer that runs Amiga binaries on the host. Fast startup, no GUI, no custom chips, no hardware emulation. Cannot run `CreateNewProc()` (no Exec task scheduler), no RTG, no audio hardware.

2. **FS-UAE**: Full Amiga hardware emulator with RTG (uaegfx), Paula audio, Exec task scheduling, and full AmigaOS. Slow startup (~5 seconds), requires a configured Kickstart ROM and Workbench.

Additionally, some tests are interactive (event loops waiting for keyboard/mouse input, infinite audio playback loops) and cannot be run in an automated harness without hanging.

A flat test list with a single `make test` target would either:
- Skip all tests that need FS-UAE (losing coverage), or
- Run all tests on FS-UAE (slow, and interactive tests hang the harness)

## Decision

**Implement a tier system in `tests.txt` where each test is tagged with its execution tier.**

| Tier | Environment | Description |
|------|------------|-------------|
| 1 | vamos | No GUI, no hardware. Basic init/quit, data structures, utility functions |
| 2 | FS-UAE | Full hardware. Video, audio, threading, input |
| 12 | Both | Can run on either environment |
| M | Manual | Interactive tests requiring human input or producing infinite output |

The `tests.txt` file is a simple registry:
```
# test_name  tier  timeout  description
test_init    12    10       SDL_Init/SDL_Quit smoke test
test_sprite  2     15       Sprite rendering with RTG
test_events  M     0        Interactive keyboard/mouse event loop
```

`make test` runs tier 1 tests on vamos. `make test-fsemu` runs tier 2 tests on FS-UAE. Tier M tests are never run automatically.

## Consequences

### Positive

- Fast feedback loop: `make test` completes in seconds (vamos, no emulator boot)
- Full coverage: `make test-fsemu` exercises hardware-dependent code paths
- No hangs: interactive tests are explicitly excluded from automated runs
- Easy to add new tests -- just add a line to `tests.txt`

### Negative

- Tier classification requires human judgment (is this test safe for automation?)
- vamos limitations mean some tests that could theoretically run there need tier 2 (e.g., threading tests)
- Two separate test commands instead of one

### Neutral

- The tier system scales to future test environments (e.g., WinUAE, real hardware via serial)
- Timeout values prevent runaway tests from blocking the harness

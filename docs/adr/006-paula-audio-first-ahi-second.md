# ADR-006: Paula Audio First, AHI Second

## Status

Accepted

## Date

2026-03-25

## Context

AmigaOS 3.x has two audio paths:

1. **Paula (audio.device):** The native custom chip audio hardware present in every Amiga. Four 8-bit DMA channels, up to ~28 kHz sample rate, requires samples in CHIP RAM. Accessed via the standard `audio.device` Exec device interface (OpenDevice/BeginIO/WaitIO).

2. **AHI (Audio Hardware Interface):** A retargetable audio system that abstracts sound cards (Toccata, Prelude, Delfina, etc.) and can also use Paula as an output. Supports 16-bit stereo, arbitrary sample rates, and software mixing. AHI is not part of the base OS -- it must be installed separately.

SDL2 probes audio backends in order via the `AudioBootStrap` array and uses the first one whose `Available()` function returns true.

The question is bootstrap order. AHI would seem preferable (higher quality output), but there is a critical practical problem: **FS-UAE's AHI emulation is non-functional.** The `ahi.device` included in FS-UAE's bundled Workbench is a stub from 1999 that opens successfully but produces no audio output. It does not crash -- it silently accepts commands and does nothing. This means:

- If AHI is probed first, it will claim to be available (OpenDevice succeeds)
- SDL2 will use AHI and produce silence
- Developers testing on FS-UAE will think audio is broken
- Debugging silent audio is much harder than debugging no audio

Paula, by contrast, works correctly on every emulator (FS-UAE, WinUAE, vamos) and every real Amiga.

## Decision

**Bootstrap order: Paula -> AHI -> Dummy.**

Paula is the primary audio driver. AHI is the secondary driver for users who have real AHI hardware and want 16-bit stereo. The dummy driver is the fallback if neither is available.

Applications can force a specific driver via `SDL_AUDIODRIVER=ahi` environment variable if they know AHI is functional.

## Consequences

### Positive

- Audio works out of the box on FS-UAE, WinUAE, and all real hardware
- Developers get immediate audio feedback during testing
- Paula is the simplest and most reliable audio path on AmigaOS 3.x
- SDL2's audio conversion layer transparently handles format conversion (e.g., S16 -> S8 downmix)

### Negative

- Default audio quality is limited to Paula's capabilities (8-bit, mono, ~22 kHz max)
- Users with AHI-capable hardware must set `SDL_AUDIODRIVER=ahi` to get 16-bit stereo (or the bootstrap order can be changed if AHI emulation improves)

### Neutral

- Both backends are always compiled in; bootstrap order only affects the default
- This matches the practical reality: most SDL2 development and testing happens on emulators

---
name: sdl2-api-lookup
description: Look up SDL2 internal API contracts for backend implementers
user_invocable: true
---

# SDL2 API Lookup

Load SDL2 internal API contract documentation for backend driver implementers.

## What This Does

Reads the SDL2 contract reference docs and presents the relevant backend contract.
Use this before implementing any SDL2 backend function pointer.

## Instructions

When invoked, check which subsystem the user is asking about and read the appropriate doc:

- **Video**: `docs/references/sdl2-video-contract.md` -- VideoBootStrap, SDL_VideoDevice
  function pointers, framebuffer lifecycle, display modes
- **Audio**: `docs/references/sdl2-audio-contract.md` -- AudioBootStrap,
  SDL_AudioDriverImpl, audio thread model, format negotiation
- **Events**: `docs/references/sdl2-events-contract.md` -- PumpEvents protocol,
  SDL_Send* functions, scancode mapping, IDCMP translation

If no specific query, list the available contract docs and their key sections.

Also cross-reference with the AmigaOS-specific reference docs:
- `docs/references/cybergraphx-reference.md` for video
- `docs/references/ahi-reference.md` for audio
- ADCD autodocs for Intuition/IDCMP events

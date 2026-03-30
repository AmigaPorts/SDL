# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.6.0] - 2026-03-30

### Added
- Port: Julius (Caesar III) for AmigaOS 3.x -- 360 files, 1 source fix, runs on FS-UAE
- Port: Celeste Classic (ccleste) for AmigaOS 3.x -- math redirected to SDL
- SDL2 mouse/cursor backend (SetPointer, CHIP RAM sprites, color reduction)
- Filesystem backend (SDL_GetBasePath, SDL_GetPrefPath via dos.library)
- Power, locale, misc dummy backends wired into build (129 -> 130 source files)
- SDL2_mixer integration (WAV-only, Paula 8-bit mono) -- Doom has sound effects
- Release management: VERSION file, CHANGELOG.md, scripts/release.sh

### Fixed
- Fullscreen scaling: correct colors via WritePixelArray + BitMapScale
- Hardware sprite cursor flickers in fullscreen -- documented, use software cursor

## [0.5.0] - 2026-03-29

### Added
- Initial release: SDL2 port for AmigaOS 3.x (68030+, RTG required)
- Video: CyberGraphX/Picasso96 RTG backend (640x480 32-bit)
- Audio: Paula audio.device backend (8-bit mono, DMA double-buffered)
- Threading: Exec Tasks (CreateNewProc, SignalSemaphore, condvar, TLS)
- Timer: ReadEClock 709 KHz monotonic timer
- Input: Intuition IDCMP (keyboard scancodes, mouse, window events)
- Joystick: gameport.device backend
- Renderer: Full SDL2 software renderer (RenderCopy, textures, streaming)
- Float: Software IEEE 754 math (bypasses broken ROM math libraries on FS-UAE)
- Port: Chocolate Doom 3.1.0 runs with zero game code patches

[Unreleased]: https://github.com/bdgscotland/libSDL2-amigaos3/compare/v0.6.0...HEAD
[0.6.0]: https://github.com/bdgscotland/libSDL2-amigaos3/compare/v0.5.0...v0.6.0
[0.5.0]: https://github.com/bdgscotland/libSDL2-amigaos3/releases/tag/v0.5.0

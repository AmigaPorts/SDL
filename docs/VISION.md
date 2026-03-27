# PDR-008: SDL2 for AmigaOS 3.x — Vision and Feasibility

## Status

Proposed

## Date

2026-03-27

## Problem

amiport currently ports only CLI/console programs (Categories 1-4). The entire world of graphical applications — games, image viewers, emulators, visualization tools — is unreachable because AmigaOS 3.x on 68k has no SDL2 library. SDL 1.2 exists and works, but the ecosystem has moved on: most open-source games and graphical tools now require SDL2, and SDL 1.2 is unmaintained.

A crowdfunded effort to port SDL2 to 68k (Steffen "MagicSN" Häuser, GoFundMe Oct 2025) has no public code or progress updates as of March 2026. The community is waiting.

## Target Users

- **Amiga game enthusiasts** who want modern open-source games on real/emulated hardware
- **Amiga application developers** who want a modern, maintained graphics/audio abstraction
- **The amiport project** which gains a new category of port candidates (Category 5/6: SDL graphical)
- **Accelerator owners** (PiStorm, Vampire) whose hardware can run SDL2 programs at playable speeds

## Decision

Create a **separate repository** (`bdgscotland/libSDL2-amigaos3`) to port SDL2 to AmigaOS 3.x on 68k. This is a platform library — not a POSIX port — and belongs outside the amiport pipeline. Once functional, amiport gains it as a dependency for graphical port candidates.

## Scope

### In Scope

- SDL2 video backend via CyberGraphX / Picasso96 (RTG)
- SDL2 audio backend via AHI
- SDL2 threading backend via Exec Tasks (proven approach from SDL 1.2 68k port)
- SDL2 input backend via Intuition IDCMP messages
- SDL2 timer backend via timer.device
- SDL2 joystick backend via gameport.device
- SDL2 filesystem backend via dos.library
- Software renderer (SDL2 built-in)
- Optional AGA video backend (chunky-to-planar, from SDL 1.2)
- Optional AMMX-accelerated blitting (from SDL 1.2, for Vampire)
- Cross-compilation via bebbo-gcc in Docker
- Testing via FS-UAE with RTG enabled

### Out of Scope (Stubs)

- OpenGL / Vulkan / GPU API (no hardware support)
- Haptic feedback, sensor, camera, pen APIs
- Dynamic library loading (no dlopen on AmigaOS 3.x; stub)
- Power management API
- SDL2_net (bsdsocket-shim in amiport handles networking separately)

### Stretch Goals

- SDL2_mixer (audio mixing via AHI)
- SDL2_image (PNG/JPEG decode — could bundle stb_image)
- SDL2_ttf (TrueType rendering — would need FreeType)

## Architecture

### Reference Code

Three existing codebases provide ~80% of the implementation:

| Subsystem | Primary Reference | Secondary Reference |
|-----------|------------------|---------------------|
| Video (RTG) | SDL 1.2 68k: `video/amigaos/SDL_cgxvideo.c` | SDL2 OS4: `src/video/amigaos4/` |
| Video (AGA) | SDL 1.2 68k: `video/amigaos/SDL_agavideo.c` | — |
| Video (AMMX) | SDL 1.2 68k: `video/apollo/` | — |
| Audio | SDL 1.2 68k: `audio/amigaos/SDL_ahiaudio.c` | SDL2 OS4: `src/audio/amigaos4/` |
| Threading | SDL 1.2 68k: `thread/amigaos/SDL_sys*.c` | SDL2 generic: `src/thread/generic/` |
| Timer | SDL 1.2 68k: `timer/amigaos/SDL_systimer.c` | SDL2 OS4: `src/timer/amigaos4/` |
| Joystick | SDL 1.2 68k: joystick backend | SDL2 OS4: `src/joystick/amigaos4/` |
| Filesystem | — | SDL2 OS4: `src/filesystem/amigaos4/` |
| Render | — | SDL2 software renderer (built-in) |

Key insight: **SDL 1.2 for 68k already solved the hardest problems** — CyberGraphX blitting, AHI audio mixing, and Exec Task-based threading. The work is adapting these proven backends to SDL2's API surface, not inventing new platform abstractions.

### Threading Strategy

SDL2 uses threads internally for audio callbacks and optionally for rendering. Three options:

1. **Exec Tasks (recommended)** — `SDL_CreateThread` → `CreateNewProc()`, `SDL_mutex` → `SignalSemaphore`, `SDL_cond` → Exec signals. The SDL 1.2 68k port proves this works.
2. **`SDL_THREADS_DISABLED`** — Compile-time flag disables all threading. Audio must use polling instead of callbacks. Simplest but limits functionality.
3. **Hybrid** — Exec Task for audio thread (must have), single-threaded everything else. Pragmatic middle ground.

Option 1 is preferred since the reference code exists. Fall back to Option 3 if edge cases in SDL2's internal threading assumptions prove problematic.

### Compiler Requirements

- SDL2 requires **C99**. bebbo-gcc supports `-std=gnu99`. ✓
- SDL2 does NOT require C11 (that's SDL3). ✓
- The `SDL_DYNAMIC_API` can be disabled (`#define SDL_DYNAMIC_API 0`) since AmigaOS 3.x has no dlopen. ✓

### Repository Structure

```
libSDL2-amigaos3/
├── include/SDL2/              # Standard SDL2 headers (from upstream, unmodified)
├── src/
│   ├── video/amigaos3/        # CyberGraphX/P96 + optional AGA + optional AMMX
│   │   ├── SDL_os3video.c     # VideoInit, VideoQuit, display enumeration
│   │   ├── SDL_os3video.h     # Internal driver state
│   │   ├── SDL_os3window.c    # Intuition window management
│   │   ├── SDL_os3modes.c     # Display mode querying via P96/CGX
│   │   ├── SDL_os3events.c    # IDCMP → SDL event translation
│   │   ├── SDL_os3mouse.c     # Pointer/cursor management
│   │   └── SDL_os3framebuffer.c  # Surface ↔ WritePixelArray bridge
│   ├── audio/amigaos3/        # AHI audio
│   │   ├── SDL_os3audio.c     # OpenDevice, PlayDevice, CloseDevice
│   │   └── SDL_os3audio.h
│   ├── thread/amigaos3/       # Exec Tasks
│   │   ├── SDL_systhread.c    # CreateNewProc() wrapper
│   │   ├── SDL_sysmutex.c     # SignalSemaphore wrapper
│   │   ├── SDL_syssem.c       # Exec signal-based semaphores
│   │   ├── SDL_syscond.c      # Condition variables via signals
│   │   └── SDL_systls.c       # Thread-local storage
│   ├── timer/amigaos3/        # timer.device
│   │   └── SDL_systimer.c     # ReadEClock-based timing
│   ├── joystick/amigaos3/     # gameport.device
│   │   └── SDL_sysjoystick.c
│   ├── filesystem/amigaos3/   # dos.library
│   │   └── SDL_sysfilesystem.c
│   ├── loadso/dummy/          # No dynamic linking (stub)
│   ├── haptic/dummy/          # No haptic (stub)
│   └── main/amigaos3/         # SDL_main entry point
│       └── SDL_os3_main.c
├── Makefile                   # bebbo-gcc cross-compile → libSDL2.a
├── examples/                  # Test programs (testsprite2, loopwave, etc.)
├── LICENSE                    # zlib (matches SDL upstream)
└── README.md
```

## Phased Delivery

| Phase | Deliverable | Milestone Test | Sessions |
|-------|-------------|----------------|----------|
| **0: Bootstrap** | Compiles to libSDL2.a with all stubs | `SDL_Init()` returns 0 | 1 |
| **1: First Pixels** | CyberGraphX video backend + software renderer | `testsprite2` draws rectangles | 1-2 |
| **2: Input** | IDCMP → SDL events (keyboard, mouse) | `testkeys` responds to input | 1 |
| **3: Audio** | AHI audio backend | `loopwave` plays a WAV file | 1 |
| **4: Threading** | Exec Task-based thread/mutex/cond | `testthread` + stable audio | 1-2 |
| **5: Polish** | Timer, filesystem, joystick, full test suite | Simple SDL2 game runs | 1 |
| **6: Optimization** | AGA backend, AMMX blitters, 68k asm hotpaths | DOSBox-SDL2 or equivalent | 2-3 |

**Total estimate: 8-12 sessions to production quality.**

## Hardware Requirements

### Minimum

- AmigaOS 3.x (Kickstart 3.1+)
- 68020 CPU
- RTG graphics card (Picasso96 or CyberGraphX) — **required for standard backend**
- AHI audio system
- 4 MB Fast RAM minimum (8+ MB recommended)

### Optional — AGA Backend (Phase 6)

- AGA chipset (A1200, A4000) — no RTG card needed
- Chunky-to-planar conversion (from SDL 1.2 68k port)
- Slower than RTG but reaches more machines

### Recommended for Good Performance

- 68040+ or accelerator (PiStorm, Vampire)
- 16+ MB Fast RAM
- RTG card or SAGA (Vampire)

### Performance Expectations

| Hardware | Expected FPS (simple 2D game) | Source |
|----------|------------------------------|--------|
| Stock A1200 (68020, AGA) | 5-15 FPS (c2p overhead) | SDL 1.2 AGA experience |
| A1200 + RTG card | 15-30 FPS | SDL 1.2 CyberGraphX experience |
| Vampire V2 (AMMX) | 30-60 FPS | AMMX-accelerated blitting |
| PiStorm (~2000 MIPS) | 60+ FPS | Quake runs at 90 FPS via RTG |

## Port Candidates Unlocked

Once SDL2 exists, these become viable amiport targets. ~37 viable candidates identified across three tiers.

### Tier 1 — Simple (30-150 KB binary, < 2 MB RAM, first ports)

| Program | Type | SDL2 Subsystems | Source | Notes |
|---------|------|----------------|--------|-------|
| **Pong** | Classic game | Render, Events | Various GitHub | Absolute minimum test — two rectangles |
| **2048.c** | Puzzle | Render, Events | [mevdschee/2048.c](https://github.com/mevdschee/2048.c) | Colored rectangles, keyboard only |
| **Snake** | Classic game | Render, Events, Timer | Various GitHub | Grid rendering, good early test |
| **CHIP-8 emulator** | Emulator | Render/Surface, Events, Audio (beep) | [kurtjd/jaxe](https://github.com/kurtjd/jaxe) | 64x32 pixel framebuffer — "hello world" of emulators |
| **Minesweeper** | Puzzle | Render, Events (mouse) | Various GitHub | Tests mouse input |
| **Tetris** | Puzzle | Render, Events, Timer | Various GitHub | Already have console version; SDL2 tests graphics |
| **Sokoban** | Puzzle | Render, Events | Various GitHub | Tile-based rendering test |
| **Lights Out** | Puzzle | Render, Events (mouse) | Various GitHub | Grid of colored squares, trivial |
| **Conway's Life** | Simulation | Render/Surface, Events | Various GitHub | Bulk pixel rendering performance test |
| **Flappy Bird** | Action | Render, Events, Timer | [RafaelGSS/flappy-bird-c](https://github.com/RafaelGSS/flappy-bird-c) | Tests scrolling and sprite rendering |

### Tier 2 — Medium (100 KB - 1 MB binary, 1-8 MB RAM)

| Program | Type | SDL2 Subsystems | Source | Notes |
|---------|------|----------------|--------|-------|
| **SDLPoP** | Platformer | Render, Mixer, Events, Timer | [NagyD/SDLPoP](https://github.com/NagyD/SDLPoP) | **Prince of Persia** reimplementation. 320x200. Pure C. Amiga homecoming. |
| **Chocolate Doom** | FPS | Render (software), Mixer, Events, Timer | [chocolate-doom](https://github.com/chocolate-doom/chocolate-doom) | Flagship candidate. Pure C. 320x200. ADoom proved Doom works on 68k. |
| **Chocolate Heretic/Hexen** | FPS | Same as Doom | Same repo | Comes nearly free if Doom works |
| **Brogue CE** | Roguelike | Render, Events, Timer | [tmewett/BrogueCE](https://github.com/tmewett/BrogueCE) | Beautiful roguelike. Grid-based. No Amiga port exists. |
| **Angband** | Roguelike | Render, Events | [angband/angband](https://github.com/angband/angband) | Modular frontend. SDL2 or console output. |
| **OpenTyrian** | Shmup | Surface, Audio, Events | [opentyrian/opentyrian](https://github.com/opentyrian/opentyrian) | Vertical scroller. 320x200. Software rendered. |
| **xrick** | Platformer | Surface, Audio, Events | [zpqrtbnk/xrick](https://github.com/zpqrtbnk/xrick) | Rick Dangerous reimplementation. Amiga classic. Pure C. |
| **Sopwith** | Action | Surface, Events, Timer | [fragglet/sdl-sopwith](https://github.com/fragglet/sdl-sopwith) | By Chocolate Doom author. Clean C. |
| **Peanut-GB** | Emulator | Render/Surface, Audio, Events | [deltabeard/Peanut-GB](https://github.com/deltabeard/Peanut-GB) | Single-header Game Boy emulator. 160x144. Needs 68040+. |
| **Space Invaders** | Classic game | Render, Events, Timer, Mixer | Various GitHub | Fixed-screen. Low rendering load. |
| **Asteroids** | Classic game | Render (line drawing), Events | Various GitHub | Tests SDL_RenderDrawLine |
| **Solitaire** | Card game | Render, Events (mouse drag) | Various GitHub | Sprite blitting + mouse input |
| **Sudoku** | Puzzle | Render, Events | Various GitHub | Grid rendering, minimal |
| **Image viewer (BMP)** | Tool | Surface, Render, Events | Custom or examples | BMP built into SDL2. First non-game tool. |
| **WAV player** | Tool | Audio | Custom or examples | Tests SDL_Audio callback path |

### Tier 3 — Ambitious (500 KB - 2 MB binary, 8+ MB RAM, accelerator recommended)

| Program | Type | SDL2 Subsystems | Source | Min Hardware | Notes |
|---------|------|----------------|--------|-------------|-------|
| **Quake** (software) | FPS | Surface, Audio, Events, Timer | Various C ports | 68060 + 8 MB | AmiQuake proved it's possible (5-10 FPS on 68060) |
| **Abuse** | Action | Surface, Audio, Events | [Xenoveritas/abuse](https://github.com/Xenoveritas/abuse) | 68040 + 4 MB | **Amiga homecoming** — originally released on Amiga |
| **REminiscence** | Platformer | Surface, Mixer, Events | [cyxx/REminiscence](https://github.com/cyxx/REminiscence) | 68040 + 4 MB | **Flashback** engine. Amiga homecoming. C++, but contained. |
| **Cave Story** (NXEngine) | Platformer | Render, Mixer, Events | [nxengine-evo](https://github.com/nxengine/nxengine-evo) | 68040 + 4 MB | C++ but C-like core. Popular retro game. |
| **NES emulator** (LiteNES) | Emulator | Render, Audio, Events | Various C impls | 68040 + 4 MB | 256x240. CPU-intensive. |
| **Stratagus** | RTS engine | Render, Mixer, Net, Events | [Wargus/stratagus](https://github.com/Wargus/stratagus) | 68060 + 32 MB | The SDL2 crowdfunding's proof-of-concept target |
| **Cannonball** (OutRun) | Racing | Render, Audio, Events | [djyt/cannonball](https://github.com/djyt/cannonball) | 68060 + 8 MB | Sprite scaling intensive. C++. |
| **Powder** | Roguelike | Render, Events | [powder-roguelike](https://github.com/clach04/powder-roguelike) | 68040 + 4 MB | Designed for GBA/DS — very constrained C++ |

### Excluded (researched but not viable)

| Program | Reason |
|---------|--------|
| ScummVM | Multi-MB binary, heavy C++ templates/STL |
| DOSBox | Multi-MB binary, too CPU-intensive |
| Taisei Project | Requires OpenGL |
| OpenLara (Tomb Raider) | Requires 3D rendering |
| DevilutionX (Diablo) | Modern C++ (C++17) |
| Cataclysm-DDA | Massive C++ codebase |
| FreeCiv/FreeCol | Too large, wrong language |
| The Powder Toy | Physics sim too CPU-heavy for 68k |

### "Amiga Homecoming" Ports (special category)

These are games that **originally shipped on the Amiga** and now have open-source reimplementations. Porting them back would resonate strongly with the community:

| Game | Engine | Original Amiga Year |
|------|--------|-------------------|
| **Prince of Persia** | SDLPoP | 1990 |
| **Flashback** | REminiscence | 1992 |
| **Rick Dangerous** | xrick | 1989 |
| **Abuse** | abuse-sdl | 1996 |

### Recommended Porting Order (after SDL2 library is functional)

1. **Pong** → prove SDL2 works (rectangles + input)
2. **2048.c** → slightly richer rendering
3. **CHIP-8** → pixel buffer + input mapping
4. **Sokoban** → tile-based rendering
5. **Minesweeper** → mouse input
6. **SDLPoP (Prince of Persia)** → first "real" game, Amiga homecoming
7. **Chocolate Doom** → flagship, ultimate proof-of-concept
8. **Brogue CE** → unique roguelike, no Amiga version exists
9. **OpenTyrian** → scrolling performance test
10. **Peanut-GB** → emulation tier

### SDL2 Subsystem Priority (informed by candidates)

| Subsystem | Needed By | Priority |
|-----------|----------|----------|
| SDL_Video (window/surface) | ALL | Phase 1 |
| SDL_Events (keyboard/mouse) | ALL | Phase 1-2 |
| SDL_Render (2D software) | Most games | Phase 1 |
| SDL_Timer | Most games | Phase 5 |
| SDL_Surface (pixel manipulation) | Emulators, Doom, viewers | Phase 1 (comes with video) |
| SDL_Audio (callback) | Doom, PoP, emulators, audio player | Phase 3 |
| SDL_Mixer | Doom, PoP, action games | Stretch goal |
| SDL_Net | Stratagus (optional) | Not needed |

## Relationship to amiport

- **Separate repo**: `bdgscotland/libSDL2-amigaos3` (zlib license, matches SDL)
- **amiport integration**: Once libSDL2.a exists, bundle under `lib/sdl2/` (like `lib/oniguruma/`) or reference as external dependency
- **New port category**: Category 6 "SDL Graphical" in `data/catalog.json`
- **Pipeline changes**: `build-manager` learns `-lSDL2`, FS-UAE test configs gain RTG mode
- **No impact on existing ports**: CLI ports (Cat 1-4) remain unchanged

## Risks

| Risk | Likelihood | Impact | Mitigation |
|------|-----------|--------|------------|
| SDL2 internal code assumes pthreads semantics we can't fully match | Medium | High | SDL 1.2 68k proves Exec Tasks work; `SDL_THREADS_DISABLED` is escape hatch |
| bebbo-gcc C99 edge cases | Low | Medium | SDL2 is mainstream C99; patches for any issues |
| Performance too slow on stock hardware | Medium | Medium | AGA backend optional; target accelerated hardware primarily |
| Häuser ships his port, making ours redundant | Low | Low | Good outcome — more SDL2 on 68k is better; efforts could merge |
| SDL2 hard EOL before we finish | Very Low | Low | SDL2 maintenance continues (2.32.8 recent); even if EOL, code remains functional |
| RTG requirement excludes most classic Amigas | Medium | Medium | AGA backend (Phase 6) addresses this; PiStorm/Vampire users all have RTG |
| Scope creep into SDL2_mixer/image/ttf | Medium | Medium | Explicit stretch goals; only after core is solid |

## Community Impact

The Amiga community's #1 software request is a capable web browser. #2 is modern networking. #3 is new games. SDL2 directly addresses #3 and indirectly enables applications that use SDL2 for UI (which touches #1 for lightweight browsers like NetSurf's SDL backend).

Community size estimates (GenerationAmiga.com, 2026):
- 120K-200K operating original hardware
- 40K-80K on FPGA/modern hardware (Vampire, PiStorm) — the primary audience
- 300K-600K using emulators — can test immediately via FS-UAE

An SDL2 library for 68k would be one of the highest-impact contributions to the classic Amiga ecosystem. DOSBox, ScummVM, and dozens of indie games become immediately portable.

## Alternatives Considered

### Use SDL 1.2 only
- **Pros**: Already exists, proven, in bebbo toolchain
- **Cons**: Unmaintained, most new software requires SDL2, shrinking pool of compatible programs
- **Verdict**: Good for near-term but not a long-term strategy

### Wait for Häuser's crowdfunded port
- **Pros**: No effort from us, professional developer
- **Cons**: No public progress in 5 months, unknown timeline, single point of failure
- **Verdict**: Can't plan around an unknown delivery date

### Port SDL3 instead
- **Pros**: Latest version, actively developed
- **Cons**: Requires C11 (bebbo-gcc may not support), new APIs (GPU, async I/O) irrelevant to 68k, SDL2 isn't even ported yet
- **Verdict**: Premature. SDL2 first, SDL3 only if SDL2 goes hard EOL

### Skip SDL entirely, use native AmigaOS graphics
- **Pros**: Maximum performance, no abstraction overhead
- **Cons**: Every port needs custom graphics code, no ecosystem of existing SDL programs to draw from
- **Verdict**: Wrong tradeoff — SDL2's value is the ecosystem it unlocks, not the abstraction itself

### Write an SDL2-compat shim over SDL 1.2
- **Pros**: Reuses existing SDL 1.2 with no new backend code
- **Cons**: SDL2-compat is incomplete, doesn't cover renderer API or new audio, would still need debugging
- **Verdict**: Interesting fallback if the full port stalls, but inferior to a proper backend

## Knowledge Base Additions Required

The SDL2 port touches AmigaOS APIs that are **not in our existing ADCD knowledge base**. CyberGraphX, Picasso96, and AHI are third-party libraries — they shipped separately from the AmigaOS ROM and NDK. We need new reference docs before serious implementation begins.

### New Reference Docs Needed

| Document | What It Covers | Source | Priority |
|----------|---------------|--------|----------|
| **`docs/references/cybergraphx-reference.md`** | CyberGraphX V4 API: `WritePixelArray()`, `LockBitMapTags()`, `GetCyberMapAttr()`, screen mode enumeration, pixel format constants | CyberGraphX SDK docs, cgx_protos.h, existing SDL 1.2 code | **Critical** — core of the video backend |
| **`docs/references/picasso96-reference.md`** | Picasso96 API: `p96WritePixelArray()`, `p96AllocBitMap()`, P96 screen mode management, P96 vs CGX compatibility layer | P96 SDK, p96_protos.h | **Critical** — alternative RTG path |
| **`docs/references/ahi-reference.md`** | AHI (Audio Hardware Interface): `AHI_AllocAudio()`, `AHI_ControlAudio()`, `AHI_SetVol()`, `AHI_LoadSound()`, callback-based audio, mixing modes | AHI autodocs (Martin Blom), ahi_protos.h | **Critical** — audio backend |
| **`docs/references/rtg-programming.md`** | Practical guide: how CGX and P96 relate, WritePixelArray pixel format pitfalls, double-buffering patterns, screen mode selection strategy, AGA fallback via c2p | Synthesized from SDL 1.2 source + community guides | **High** — prevents trial-and-error |
| **`docs/references/exec-tasks-reference.md`** | Exec task/process creation: `CreateNewProc()`, `Signal()`, `Wait()`, `SignalSemaphore` (InitSemaphore/ObtainSemaphore/ReleaseSemaphore), message ports for IPC | ADCD (already have exec.library) — needs extraction + practical threading patterns | **High** — threading backend |
| **`docs/references/intuition-input.md`** | IDCMP messages: `IDCMP_RAWKEY`, `IDCMP_MOUSEMOVE`, `IDCMP_MOUSEBUTTONS`, raw key → ASCII translation, qualifier bits, IntuiMessage handling | ADCD Intuition chapter — needs focused extraction | **Medium** — input backend |
| **`docs/references/gameport-reference.md`** | gameport.device: joystick reading, event-driven vs polled mode, GPD_ASKCTYPE | ADCD devices chapter — needs extraction | **Low** — joystick backend (Phase 5) |

### Existing KB We Can Leverage

| Document | Relevance to SDL2 |
|----------|-------------------|
| `docs/references/crash-patterns.md` | Crash patterns #7 (stack overflow), #10 (large buffers), #15 (alignment), #16 (struct returns at -O2) all apply to SDL2 backend code |
| `docs/references/68k-hardware.md` | Memory map, addressing modes — relevant for AMMX blitter code |
| `docs/references/amiga-intern/` | Custom chip architecture — relevant for AGA c2p backend |
| ADCD `exec.library` | SignalSemaphore, Task creation — directly used by thread backend |
| ADCD `graphics.library` | `WritePixelArray8` — related to (but distinct from) CyberGraphX `WritePixelArray` |
| ADCD `intuition.library` | Window management, IDCMP — directly used by video/input backends |
| ADCD `timer.device` | ReadEClock, microsecond timing — directly used by timer backend |

### New Crash Patterns Expected

SDL2 backend code will encounter new crash patterns not seen in CLI ports:

| Predicted Pattern | Subsystem | Why |
|------------------|-----------|-----|
| **RTG pixel format mismatch** | Video | WritePixelArray with wrong PIXFMT constant silently corrupts display or crashes |
| **Screen mode not available** | Video | Opening a P96/CGX screen mode that doesn't exist on the user's card |
| **AHI callback in wrong context** | Audio | AHI audio callback runs as a software interrupt — can't call dos.library or allocate memory |
| **SignalSemaphore deadlock** | Threading | ObtainSemaphore from within a semaphore-holding task — classic Exec deadlock |
| **Chip RAM allocation failure** | Video (AGA) | AGA c2p needs Chip RAM for bitplanes — none available if Fast RAM is abundant but Chip is full |
| **Intuition window close race** | Input | Closing window while IDCMP messages are queued — must ReplyMsg all pending messages first |

These should be documented in crash-patterns.md as they're discovered, following the existing format.

### Skills Needed (New)

| Skill | Purpose | When |
|-------|---------|------|
| **`/sdl2-api-lookup`** | Load SDL2 API reference: function signatures, struct layouts, subsystem init/quit patterns, callback conventions | When writing or reviewing backend code |
| **`/rtg-api-lookup`** | Load CyberGraphX + P96 + AHI reference docs | When implementing video/audio backends |
| **`/sdl2-build`** | Cross-compile libSDL2.a and test programs with bebbo-gcc | After backend code changes |
| **`/sdl2-test`** | Run SDL2 test suite on FS-UAE with RTG enabled | After build succeeds |

### Agents Needed (New or Extended)

| Agent | Role | New or Extended? |
|-------|------|-----------------|
| **`sdl2-backend-developer`** | Writes SDL2 platform backend code (video/audio/thread). Knows CyberGraphX, AHI, Exec Tasks. Has `/sdl2-api-lookup` + `/rtg-api-lookup` + `/amiga-api-lookup` injected. | **New** — this is library engineering, not POSIX porting |
| **`build-manager`** | Needs to learn `-lSDL2` linking, RTG library dependencies, SDL2 header paths | **Extended** — new build profile |
| **`test-designer`** | Needs SDL2-aware test generation: visual output verification, audio playback confirmation, input event testing | **Extended** — new test category |
| **`hardware-expert`** | Needs CyberGraphX/P96 knowledge: RTG card capabilities, SAGA vs CGX differences, AGA chipset constraints for c2p | **Extended** — graphics hardware domain |
| **`visual-test-expert`** | SDL2 programs render to RTG screens, not console.device. Needs new capture approach (screenshot via CyberGraphX `ReadPixelArray`, or FS-UAE screenshot feature) | **Extended** — new capture method |
| **`perf-optimizer`** | 68k asm blitting analysis, AMMX instruction selection, c2p optimization, AHI mixing efficiency | **Extended** — graphics/audio perf domain |
| **`dependency-auditor`** | Must know that SDL2 programs need: CyberGraphX OR P96 (runtime), AHI (runtime), and the specific SDL2 subsystems their code uses | **Extended** — new dependency class |

### Pipeline Extension

The amiport pipeline currently has 5 stages. SDL2 graphical ports would add/modify:

```
Stage 0:  Aminet research (unchanged)
Stage 0b: Dependency audit — now flags "requires SDL2 + RTG"
Stage 1:  Source analysis — now detects SDL2 subsystem usage (SDL_Render, SDL_mixer, etc.)
Stage 2:  (new) SDL2 subsystem check — verify required backends exist in libSDL2.a
Stage 3:  Transform — SDL2 programs need fewer POSIX transforms (SDL abstracts OS)
Stage 4:  Build — links -lSDL2, adds RTG library include paths
Stage 5:  Test — FS-UAE with RTG enabled, new visual test approach for graphical output
Stage 6:  Review — memory-checker + perf-optimizer (unchanged but with new domains)
Stage 7:  Package — .readme notes RTG/AHI requirements
```

### FS-UAE Test Infrastructure for SDL2

SDL2 programs render to **RTG screens**, not the Workbench console. The existing test infrastructure (SCRAPE, EXPECT_AT, ConUnit cursor) doesn't apply. New approach needed:

| Method | How | Feasibility |
|--------|-----|-------------|
| **FS-UAE screenshot** | FS-UAE has built-in screenshot capability (`input_mapping = action_screenshot`). Trigger via ARexx or host-side key injection, then compare PNG. | **High** — proven feature |
| **CyberGraphX ReadPixelArray** | Read back framebuffer contents from within the test harness. Compare against expected pixel data. | **Medium** — works but requires Amiga-side test code |
| **Exit code only** | Ignore visual output, just verify the program starts, runs, and exits cleanly. | **Immediate** — works with existing infrastructure |
| **Timing-based validation** | Measure FPS, frame time. Verify performance doesn't regress. | **Medium** — useful for optimization phase |

Recommended approach: **Exit code first** (Phase 0-4), **FS-UAE screenshots** (Phase 5+), **pixel comparison** (Phase 6 optimization).

## References

- [SDL 1.2 for 68k (AmigaPorts/libSDL12)](https://github.com/AmigaPorts/libSDL12) — video, audio, thread backends
- [SDL 1.2 for 68k (HenrykRichter fork)](https://github.com/HenrykRichter/libSDL12_Amiga68k) — additional fixes
- [SDL2/3 for AmigaOS 4 (AmigaPorts/SDL)](https://github.com/AmigaPorts/SDL) — OS4 backend structure
- [SDL2 Porting Guide](https://wiki.libsdl.org/SDL2/README-porting) — official stub/backend documentation
- [SDL2 Porting Walkthrough (Mohammed Isam)](https://mohammedisam2000.medium.com/porting-sdl-2-0-to-a-new-platform-a6786baec01d) — detailed step-by-step
- [SDL2 for 68k Crowdfunding (GoFundMe)](https://www.gofundme.com/f/sdl2-for-amigaos-68k-and-amigaos-warpos) — Häuser's effort
- [Crowdfunding Announcement (Amigans.net)](https://www.amigans.net/modules/news/article.php?storyid=3374)
- [Amiga Community Statistics 2026](https://www.generationamiga.com/2026/03/06/amiga-statistics-2026-users-demographics-hardware-and-the-modern-amiga-ecosystem/)
- [PiStorm Emu68 Benchmarks](https://amitopia.com/pistorm-emu68-1-1-reaches-2050-mips/)
- [Exec Tasks (AmigaOS Wiki)](https://wiki.amigaos.net/wiki/Exec_Tasks)

# PDR-009: Hardware Expansion, SDL, and WHDLoad — Exploration Notes

## Status

Proposed (exploratory — no decisions yet, captures research findings)

## Date

2026-03-27

## Problem

amiport targets a narrow hardware slice: AmigaOS 3.x on 68020 with limited RAM, CLI programs only. The Amiga community in 2026 has significantly more capable hardware (PiStorm at 2,000 MIPS, Vampire with 2 GB RAM) and wants graphical programs, games, interpreters, and networking tools. What does expanding scope look like, and what does it unlock?

## Research Findings

### Hardware Landscape (March 2026)

#### PiStorm — The People's Accelerator
- $13-25 EUR, open-source (BSD/MPL), multiple variants (A500/A600/A1200/A2000/MiniMig)
- Emu68 v1.1: ~2,050 MIPS (Pi4 stock), ~2,333 MIPS (overclocked) — 1,300x a stock A1200
- 128 MB - 2 GB Fast RAM, RTG via Pi HDMI, WiFi, Ethernet
- PiStorm68K (Jan 2026): dual-mode board for MiniMig — switch between real 68000 and emulated
- Chip RAM access slow (GPIO bit-banging); Fast RAM is extremely fast (local to Pi)
- Likely the most widely adopted Amiga accelerator
- Sources: [Hackaday](https://hackaday.com/2026/01/06/pistorm68k-offers-supercharged-retro-amiga-experience/), [Amitopia](https://amitopia.com/pistorm-emu68-1-1-reaches-2050-mips/)

#### Vampire (Apollo Core) — FPGA Premium
- Apollo A6000 shipped Sept 2025 (standalone, ~960 EUR, sold out immediately)
- AC68080 FPGA: ~154 MIPS, SAGA chipset (1080p HDMI, 32-bit color)
- A6000: 2 GB Fast RAM + 12 MB Chip RAM, 100 Mbit Ethernet, 4x USB, NVMe
- V2 cards: 128 MB Fast RAM for A500/A600/A1200
- Sources: [Tom's Hardware](https://www.tomshardware.com/video-games/retro-gaming/proper-next-gen-amiga-launched-by-apollo-computing-promises-full-fpga-powered-backwards-compatibility-with-its-new-68080-chip), [NotebookCheck](https://www.notebookcheck.net/Apollo-Computer-announces-sale-date-for-the-second-batch-of-Apollo-A6000-Amiga-compatible-computers.1126314.0.html)

#### Other Active Accelerators
| Hardware | CPU | RAM | Price | Notes |
|----------|-----|-----|-------|-------|
| TF1260 | Real 68060 @ 50 MHz | 128 MB | ~260 EUR | Purist choice |
| ACA1233n/1234 | 68030 @ 55 MHz | 128 MB | ~200 EUR | PCMCIA-friendly |
| Wicher 520i (Mar 2026) | 68020 + 32 MB | 32 MB | New | A500 |
| Warp accelerators | 68060 overclocked | 128 MB | Varies | HDMI, RTG |

#### Upcoming Hardware
- **THE A1200** by Retro Games Ltd — modern recreation, targeting 2026
- **A1200 NG** by AmigaKit — modern motherboard, bundles AmiBrowser (Chromium-via-Pi)
- **AmigaOS 3.3** — in development by Hyperion, targeting 2026

### Community Size (GenerationAmiga.com, 2026)
- 120K-200K operating original hardware
- 300K-600K using emulators
- 40K-80K on FPGA/modern hardware
- 15K-35K dedicated enthusiasts
- Concentrated in Europe (Germany, UK)
- Source: [GenerationAmiga](https://www.generationamiga.com/2026/03/06/amiga-statistics-2026-users-demographics-hardware-and-the-modern-amiga-ecosystem/)

### Software Unlocked by Hardware Tier

#### Current (68020 + 4 MB) — What We Do Today
CLI utilities, text processors, simple interpreters (Lua). Category 1-4 ports.

#### Tier A: Real 68060 + 128 MB (TF1260, Warp)
- zlib/gzip, lz4 compression at useful speeds
- diff3, sdiff, patch
- make (bmake) — on-Amiga builds
- Perl 5 (subset)

#### Tier B: Vampire ~154 MIPS + 128 MB-2 GB
- Python 2.7 (AmigaPython exists)
- TCL, Forth (gforth)
- SQLite 3.x (existing OS3 port based on 3.6.1)
- curl/wget (with Vampire's 100 Mbit Ethernet)
- dropbear SSH (crypto slow but usable)
- lz4/zstd decompression
- gnuplot (text mode), m4

#### Tier C: PiStorm ~2,000 MIPS + 2 GB
- Python 3.11 (3.06 MB binary, genuinely usable at this speed)
- SQLite 3 (modern) as real database
- zstd (full, both directions)
- mbedTLS/BearSSL — HTTPS possible
- curl with TLS
- make + m4 + yacc/bison (full build system)
- git (core operations: diff, apply, log)
- groff/nroff document formatting

#### Still Infeasible (Any Hardware)
- Full web browsers (JS engines too heavy)
- Modern compilers (LLVM/Clang)
- Video encoding (needs SIMD)
- ML inference

### SDL Status

#### SDL 1.2 for 68k — EXISTS AND WORKS
- AmigaPorts/libSDL12 v1.2.15-RC1
- CyberGraphX/P96 video, AHI audio, Exec Task threading
- 68k ASM-optimized blitting, AMMX for Vampire
- Pre-built in bebbo-gcc Docker image (`-lSDL`)
- DOSBox runs on it (proof of viability)
- Sources: [GitHub](https://github.com/AmigaPorts/libSDL12), [HenrykRichter fork](https://github.com/HenrykRichter/libSDL12_Amiga68k)

#### SDL2 for 68k — DOES NOT EXIST
- Crowdfunding by Steffen "MagicSN" Häuser (GoFundMe, Oct 2025)
- No public code, repo, or progress update as of March 2026
- SDL2 for AmigaOS 4 (PPC) exists as reference: [AmigaPorts/SDL](https://github.com/AmigaPorts/SDL)
- See [PDR-008](008-sdl2-amigaos3-vision.md) for our feasibility assessment and plan
- Sources: [GoFundMe](https://www.gofundme.com/f/sdl2-for-amigaos-68k-and-amigaos-warpos), [Amigans.net](https://www.amigans.net/modules/news/article.php?storyid=3374)

#### SDL3 — NOT RELEVANT FOR 68k
- Released Jan 2025 (3.2.0), now at 3.4.2 (Feb 2026)
- Requires C11 (bebbo-gcc only supports C99)
- New APIs (GPU, async I/O, HDR) irrelevant to 68k
- Listed as stretch goal of SDL2 crowdfunding
- Source: [SDL3 wiki](https://wiki.libsdl.org/SDL3/NewFeatures)

### WHDLoad — NOT APPLICABLE TO AMIPORT

WHDLoad **shuts down AmigaOS** to run programs that bang hardware directly. Fundamentally wrong for ported CLI tools which need AmigaOS running.

- ~3,695 packages: 2,697 games, 883 demos, 104 magazines, 37 cracktros, 4 "applications"
- Zero precedent for WHDLoad packaging of ported Unix tools
- Open-source game ports (Doom, Quake, ScummVM) all use standard Aminet .lha
- WHDLoad v20.0 released Feb 2026, still very active — just not for us
- Aminet .lha + amiport website remains the correct distribution approach
- Sources: [WHDLoad FAQ](https://www.whdload.de/docs/en/faq.html), [Wikipedia](https://en.wikipedia.org/wiki/WHDLoad)

### Community's Top Software Wants
1. Capable modern web browser
2. Modern networking (SSH, HTTPS)
3. New games
4. Modern development environments
5. Unix/Linux CLI tool ports (exactly what amiport does)
6. Media players and codecs

## Decisions Deferred

| Topic | Status | Dependency |
|-------|--------|------------|
| SDL2 port (separate repo) | PDR-008 captures the plan | User creates `bdgscotland/libSDL2-amigaos3` |
| Hardware profiles in catalog.json | Ready to implement | No blockers — just metadata |
| New port categories (5/6/7) | Needs SDL2 first for Cat 6 | SDL2 library |
| Accelerator-specific binary variants | Low priority | Demand-driven |
| AGA video backend for SDL2 | Phase 6 stretch goal | SDL2 RTG backend first |

## What the Community Wants vs What We Provide

```
Community want          amiport today       amiport + SDL2 + accel
─────────────────────   ─────────────────   ──────────────────────
Web browser             ✗                   ✗ (still too heavy)
SSH / HTTPS             ✗                   Possible (dropbear + mbedTLS)
New games               ✗                   ✓ (SDL2 games)
Dev environment         Partial (vim, make) Better (+ git subset, m4, yacc)
CLI tools               ✓✓✓                 ✓✓✓
Media players           ✗                   Possible (SDL2 audio players)
```

SDL2 is the single highest-leverage expansion. It addresses want #3 directly and enables #6, while our existing pipeline continues to serve #5.

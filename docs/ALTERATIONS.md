# Alterations to the upstream SDL2 sources

This repository vendors the SDL2 AmigaOS 3.x port from
<https://github.com/bdgscotland/libSDL2-amigaos3> and modifies it. The zlib
License requires that altered sources be plainly marked, so this is the
complete list. Each altered file also carries a notice at the top.

## Modified

### `include/SDL_hints.h`

Added `SDL_HINT_VIDEO_AMIGAOS3_SCREEN`, documented alongside the other video
hints.

### `src/video/amigaos3/SDL_os3window.c`

`OS3_OpenWindowed` now consults that hint before applying its own heuristic:

| value | behaviour |
|---|---|
| `workbench` | always open on the Workbench public screen — a normal titled, draggable window |
| `screen` | always open a private screen with a borderless window |
| `auto`, unset | the original behaviour: probe, and decide |

**Why.** The original probe asks whether the Workbench bitmap reports
`CYBRMATTR_ISCYBERGFX`, or failing that whether it is at least 15 bits deep.
That test is conservative, and it declines Picasso96 Workbench screens that
host a window perfectly well — SDL 1.2 opens one on the same machine. With no
way to override it, the application is stuck on a private borderless screen.

A heuristic nobody can override is a policy baked into the driver. The
heuristic remains the default; the application now gets the last word.

The hint is deliberately **not** honoured on AGA. Without an RTG library there
is no blit path for an ARGB surface into a window on a planar screen, so a
private screen is used regardless of the hint.

`patches/` holds this change in isolation, for anyone who wants to apply it to
a stock upstream checkout rather than use this repository.

## Not included from upstream

Removed as out of scope for an SDL2 library distribution, not modified:

| Path | Reason |
|---|---|
| `ports/` | ccleste, chocolate-doom, julius — applications that *use* SDL2, carrying their own licences |
| `docs/references/adcd/` | Amiga Developer CD, ~81 MB of platform documentation |
| `docs/references/autodocs/` | AmigaOS autodocs |
| `docs/references/amiga-intern/` | Amiga Intern reference |
| `docs/references/m68000-prm/` | Motorola 68000 programmer's reference |

The SDL-specific contents of `docs/references/` — the `sdl2-*-contract.md`
files and `sdl12-ahiaudio.c` — are kept.

Everything else upstream tracks is present, including the full `src/`,
`include/`, `examples/`, `scripts/` and `toolchain/` trees, so a single clone
builds without fetching anything else.

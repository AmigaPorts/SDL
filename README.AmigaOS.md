# SDL2.Library-Amiga-m68K

SDL2 for m68k Amiga as a **shared library** — called into from an application
rather than linked into it.

This is a complete, self-contained SDL2 distribution. It vendors the SDL2
AmigaOS 3.x port and adds an AmigaOS shared-library envelope on top, so one
clone builds both `libSDL2.a` and `sdl2.library` with nothing else to fetch.

**Porting a game?** See [PORTING.md](PORTING.md). The short version: write
ordinary SDL2, rename `SDL_Foo` to `SDL2_Foo`, open the library, link nothing.

## Why a library

On AmigaOS 3 the usual arrangement is to link SDL statically into every binary.
That has two costs this project exists to remove:

- **Every application carries its own copy.** SDL2 is ~1.1 MB. Two programs
  running at once means two copies resident.
- **A wedged SDL thread outlives the program that made it.** A statically
  linked copy dies with a hung process only in theory; in practice an orphaned
  thread waiting on a process that already exited pins resources until reboot.
  A library has one well-defined teardown point — expunge, when the last client
  has closed — with no caller inside it.

Amiga library functions take their arguments in **registers**; SDL2's take them
on the stack. Each export is therefore a thin wrapper that declares register
arguments and calls straight through. No policy, no application logic, no
display decisions.

## Status

`sdl2.library 33.0` — the version is SDL's minor release and the revision its
patchlevel, both read from `include/SDL_version.h` at build time, so
`OpenLibrary("sdl2.library", 33)` means "at least SDL 2.33".

Verified on Picasso96 RTG under emulation:

| | |
|---|---|
| Library loads and links | ROMTag, `MakeFunctions`, jump table, terminator |
| Register ABI | `SDL2_Ping(100) -> 142` through the generated inlines |
| libnix runtime in a library | heap, TLS, semaphores, error buffer |
| `SDL_Init(VIDEO\|AUDIO)` | returns 0 |
| Audio | device opens, `SDL_QueueAudio` accepted |
| Video | window, surface, `SDL_FillRect`, `SDL_UpdateWindowSurface` |
| Clean shutdown | `SDL_Quit` returns, library expunges, nothing pinned |

**783 of SDL2's 877 public functions are exported**, plus 12 diagnostics. The
94 that are not are reserved slots with recorded reasons, not omissions — see
*The ABI* below.

The AGA path (8-bit `INDEX8` surface, c2p) exists in the video driver but has
not been exercised here.

## Layout

```
library/              the shared-library envelope
  sdl2lib.c             ROMTag, __UserLibInit/__UserLibCleanup
  sdl2api.c             GENERATED -- register wrappers, 783 SDL functions
  sdl2table.c           GENERATED -- the export table, ORDER IS THE ABI
  sdl2_lib.fd           GENERATED -- function descriptions
  clib/sdl2_protos.h    GENERATED -- fd2pragma input
  sdl2probes.c          hand-written diagnostics, slots 1000+
  sdl2crt.c             globals a library has no startup module to provide
tools/genabi.py       regenerates the four generated files from SDL's dynapi
test/                 the test application
  sdl2test.c            opens the library, draws squares, plays a sound
  sdl2test.cfg          runtime configuration
  cuckoo.wav/.raw       the sound it plays, and its 8-bit mono conversion
tools/wav2raw.py      WAV -> signed 8-bit mono raw, the format Paula wants

src/  include/        SDL2 itself, and its headers
examples/             upstream's AmigaOS test programs (statically linked)
scripts/ toolchain/   build and emulator-test harness
lib/                  SDL2_mixer
docs/                 design docs, ADRs, SDL2 contracts, build notes
  ALTERATIONS.md        what this repo changes in the vendored SDL2
  BUILD-NOTES.md        long-form notes on building an AmigaOS shared library
patches/              the SDL2 change in isolation (already applied to src/)
PORTING.md            how to build a game against the library
dist/                 produced by ./build.sh dist -- library + SDK
```

The test links **nothing** of SDL2. Every call goes through the library's jump
table via the inlines generated from `sdl2_lib.fd`, so it exercises the real
interface — no statically linked copy can stand in for a library that isn't
working. It does include SDL2's *headers*, because caller and library must
agree on struct layout: the `.fd` file fixes **registers**, not layout.

## Building

```sh
./build.sh
```

Builds `libSDL2.a` if it is missing, then `sdl2.library` into `build/`.

| command | does |
|---|---|
| `./build.sh` | SDL2 if needed, then the library |
| `./build.sh sdl2` | `libSDL2.a` only |
| `./build.sh lib` | the library only, reusing `libSDL2.a` |
| `./build.sh test` | also build the test application |
| `./build.sh dev` | build under a unique name, for iterating on the library |
| `./build.sh dist` | assemble `dist/` to hand to other developers |
| `./build.sh clean` | remove build products |

`DEPLOY=/path` copies the results out to a shared folder.

**`dev` matters if you are changing the library itself.** AmigaOS keeps a
library resident after its last client closes, and a run that *hangs* never
closes it — so the next run silently gets the previous jump table and any newly
added export calls off the end of it. `dev` names each build uniquely, so a
pinned copy from a crashed run is simply not what the next one asks for. No
reboots.

The only requirement is Docker, for `amigadev/crosstools:m68k-amigaos` (GCC
6.5). Newer m68k GCC releases miscompile NDK macros and mishandle libnix's exit
list; 6.5 predates both.

Changing the library itself? See [CONTRIBUTING.md](CONTRIBUTING.md) — four
files under `library/` are generated and must not be hand-edited.

See [BUILDING.md](BUILDING.md) for the full procedure and the non-obvious
constraints — several of which silently produce a library that loads and then
crashes on its first call.

## The ABI

**Generated, not hand-maintained.** `tools/genabi.py` reads SDL's own
`src/dynapi/SDL_dynapi_procs.h` — the list that becomes `SDL2.dll`'s export
table — and emits `sdl2_lib.fd`, `sdl2api.c`, `sdl2table.c` and
`clib/sdl2_protos.h` from it.

That file declares itself append-only:

> NEVER REARRANGE THIS FILE, THE ORDER IS ABI LAW.

So we adopt its order wholesale. **Slot *n* is dynapi entry *n***, at LVO
`-(30 + 6n)`. A later SDL release appends to that file, so it appends here too,
and no existing LVO ever moves. `SDL_Init` is dynapi entry 27, therefore
LVO −192, on this platform and on any future build.

Entries that cannot be expressed in a register ABI still **consume their slot**,
as `##private`, so nothing after them shifts:

| reserved | count | why |
|---|---|---|
| future SDL | 123 | headroom to slot 1000 before our own exports begin |
| not built for AmigaOS | 55 | Android/iOS/D3D/WinRT/Linux platform calls |
| variadic | 12 | `...` has no register form — SDL's `*V` variants **are** exported |
| returns a struct by value | 8 | the hidden return pointer collides with an argument register |
| Windows-only signature | 6 | dynapi carries `pfnSDL_CurrentBeginThread` for the thread calls |
| no Vulkan on AmigaOS 3 | 6 | headers absent |
| struct passed by value | 4 | `SDL_JoystickGUID` by value has no register form |
| `FILE *` vs `void *` | 2 | differs by configuration |
| over 11 arguments | 1 | `SDL_RenderGeometryRaw`, wider than `LP11` |

Register allocation: pointers take `a0`–`a3` and spill into data registers when
those run out; 64-bit values (`Sint64`, `Uint64`, `double`, `SDL_TouchID` …)
consume a **pair** of consecutive data registers.

Slots 1000+ are this library's own — the `Ping` / `Probe*` diagnostics in
`sdl2probes.c`. Keeping them above SDL's range means SDL can grow without
colliding with them. They earn their keep while porting: each answered a
question that otherwise cost a crash or a hang to guess at, and `ProbeMalloc`
is what located the missing `__initmalloc` call that hung *every* SDL2 entry
point.

**To regenerate after updating SDL:** `python tools/genabi.py` (needs
`libSDL2.a` built, since it checks which symbols actually exist).

## Configuration

Where a window goes is the **application's** choice, not the driver's:

```
# test/sdl2test.cfg
screen=workbench   # normal titled window on the Workbench screen
screen=screen      # private screen, borderless window
screen=auto        # let the SDL2 driver probe and decide (default)
```

The value is passed to `SDL_SetHint` as `SDL_VIDEO_AMIGAOS3_SCREEN`. Nothing
about display policy is compiled into the library. See
[docs/ALTERATIONS.md](docs/ALTERATIONS.md) for what that hint changes in the
vendored driver and why.

## Credits

- [SDL2](https://www.libsdl.org/) — Sam Lantinga and the SDL contributors.
- [libSDL2-amigaos3](https://github.com/bdgscotland/libSDL2-amigaos3) —
  bdgscotland. **The AmigaOS 3.x port vendored here is that project's work**:
  the video, audio, threading and TLS backends, the c2p path, the examples and
  the test harness. Its own README is preserved at
  [docs/UPSTREAM-README.md](docs/UPSTREAM-README.md).
- This repository adds the shared-library envelope, the register-argument ABI
  and `.fd` definitions, the test application, and the
  `SDL_VIDEO_AMIGAOS3_SCREEN` hint.

Altered files are marked in place and listed in
[docs/ALTERATIONS.md](docs/ALTERATIONS.md).

## License

zlib, matching SDL2's own and that of the AmigaOS 3.x port vendored here.
See [LICENCE.MD](LICENCE.MD); SDL2's own notice is in [LICENSE](LICENSE).

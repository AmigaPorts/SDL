# Contributing

## The shape of the repository

`src/`, `include/`, `examples/`, `scripts/`, `toolchain/` and most of `docs/`
are the vendored SDL2 AmigaOS 3.x port. Changes there are changes to SDL2, and
every one must be recorded in [docs/ALTERATIONS.md](docs/ALTERATIONS.md) and
marked in the file itself — the zlib licence requires altered sources to be
plainly marked, and we are redistributing.

`library/`, `test/` and `tools/` are this project's own.

## Four of those files are generated

```
library/sdl2api.c          register wrappers
library/sdl2table.c        the export table
library/sdl2_lib.fd        function descriptions
library/clib/sdl2_protos.h prototypes
```

`tools/genabi.py` writes all four from SDL's own
`src/dynapi/SDL_dynapi_procs.h`. **Do not edit them by hand** — the next
regeneration silently discards the edit.

```sh
./build.sh sdl2          # genabi needs libSDL2.a: it checks which
python tools/genabi.py   # symbols actually exist before exporting them
```

## Adding an export

Usually you do not. If SDL gained the function, update the vendored SDL and
rerun the generator; the new entry appends itself.

Hand-written exports are for things SDL does not provide, or that the generator
had to reserve. Add them to `EXTENSIONS` in `tools/genabi.py`, implement them in
`library/sdl2probes.c`, and regenerate. They land at slot 1000 and upward.

**Never renumber.** `SDL_dynapi_procs.h` calls its own order "ABI law" and we
inherit that: slot *n* is dynapi entry *n*, at LVO `-(30 + 6n)`. Anything
already shipped must keep its slot forever. Slots 877–999 are reserved so SDL
can grow without colliding with our additions.

If SDL ever exceeds 1000 entries the generator stops with an error rather than
quietly shifting our exports. Raising `SDL_SLOTS` at that point breaks the ABI
for everything above it, so it needs a version bump and a note in the changelog.

## Why a function might be reserved

The generator classifies every entry and records the reason next to the slot in
the `.fd`. The interesting cases:

- **variadic** — no register-ABI form. SDL's `*V` variants are exported instead.
- **returns a struct by value** — the compiler adds a hidden return pointer,
  which lands on a register already given to an argument.
- **struct passed by value** — same problem, inbound.
- **not built for AmigaOS** — determined by reading `libSDL2.a`, not by taste.

Two allocation rules matter if you touch the generator: pointers take `a0`–`a3`
and spill into data registers when those run out, and **64-bit values take a
consecutive pair of data registers**. Getting that second one wrong produces
`two parameters allocated for one register`, or worse, silently wrong arguments.

## Building and testing

```sh
./build.sh            # libSDL2.a if needed, then sdl2.library
./build.sh test       # and the test application
./build.sh dev        # unique library name -- use this while iterating
./build.sh dist       # assemble dist/ for handing out
```

**Use `dev` while changing the library.** AmigaOS keeps a library resident
after its last client closes, and a run that *hangs* never closes it at all, so
the next run silently gets the previous jump table and any newly added export
calls off the end of it. `dev` names each build uniquely, so a pinned copy from
a crashed run is not what the next one asks for. Without it you will be
rebooting between test runs and misattributing crashes.

`DEPLOY=/path/to/amiga/share ./build.sh dev` copies the results out.

## Testing on hardware or emulation

`test/sdl2test.c` walks a ladder of checks, each logging before the call that
follows, so the **last line in `sdl2test.log` names the call that failed**. That
structure is the point of it: a library that hangs produces no output at all
otherwise.

`test/sdl2test.cfg` selects where the window goes (`workbench`, `screen`,
`auto`) without a rebuild.

## Changing the sound

`tools/wav2raw.py` converts any PCM WAV to signed 8-bit mono — what the AmigaOS
audio path wants, Paula being an 8-bit signed DMA device — and prints the
matching `SDL_AudioSpec`. Both the `.wav` and the generated `.raw` are
committed so a clone is runnable without Python.

## Style

Match what is there: C89 declarations at the top of a block, no `//` comments,
tabs nowhere. Comments explain *why*, especially where the reason is an AmigaOS
behaviour that is not obvious from the code — most of the hard-won knowledge in
this repository is in those comments, and [docs/BUILD-NOTES.md](docs/BUILD-NOTES.md)
holds the long-form version.

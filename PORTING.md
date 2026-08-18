# Porting a game against sdl2.library

You write ordinary SDL2 code. The difference from a static link is that calls
go through an AmigaOS shared library, so the names are prefixed and the library
has to be opened.

## Install

Copy `sdl2.library` to `LIBS:`, or keep it beside your executable and open it
as `PROGDIR:sdl2.library`.

## Open it

```c
#include <proto/exec.h>
#include "SDL.h"          /* SDL2's own headers, for types */
#include "sdl2.h"         /* the inlines -- AFTER SDL's headers */

struct Library *SDL2Base;

int main(void)
{
    /* 33 = SDL minor version; see below */
    SDL2Base = OpenLibrary("sdl2.library", 33);
    if (!SDL2Base) {
        printf("sdl2.library 33 (SDL 2.33) or newer is required\n");
        return 20;
    }

    if (SDL2_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        printf("SDL_Init: %s\n", SDL2_GetError());
        CloseLibrary(SDL2Base);
        return 20;
    }

    /* ... game ... */

    SDL2_Quit();
    CloseLibrary(SDL2Base);
    return 0;
}
```

**The version number is SDL's minor release.** AmigaOS gives a library a
version/revision pair and `OpenLibrary` tests the version half with `>=`. SDL's
major is always 2, so putting that there would make the check meaningless —
instead SDL's *minor* is the version and the patchlevel is the revision. SDL
2.33.0 is `sdl2.library 33.0`, and asking for `33` means "at least SDL 2.33".

The ABI is append-only, so a newer library always satisfies an older program.

For a finer check at runtime, use SDL's own mechanism:

```c
SDL_version v;
SDL2_GetVersion(&v);       /* v.major=2, v.minor=33, v.patch=0 */
```

## The two rules

**1. `SDL_Foo` becomes `SDL2_Foo`.** Everything else about the call is
unchanged — same arguments, same order, same return value. Porting existing
code is a mechanical rename:

```c
sed -i 's/\bSDL_\([A-Za-z]\)/SDL2_\1/g' *.c
```

Careful with that: it also renames constants and types, which must **not**
change. `SDL_INIT_VIDEO`, `SDL_Surface`, `SDL_Rect`, `SDL_QUIT` all stay as
they are. Rename functions only.

**2. Include SDL's headers before `sdl2.h`.** The prototype header carries no
includes of its own, because `fd2pragma` copies any it finds into the generated
inlines in a form that is not valid C.

## Compiling

```sh
m68k-amigaos-gcc -m68030 -O2 -noixemul -I sdk/include -o mygame mygame.c
```

**Link nothing.** No `-lSDL2`. Every call goes through the library's jump
table; the only SDL2 in your binary is the inline `jsr -N(a6)` per call.

## What is exported

783 of SDL2's 877 public functions — everything in SDL's own dynamic API list
that can be expressed in a register ABI on this platform.

The 94 that are not are reserved slots, and the reasons are recorded in
`sdk/fd/sdl2_lib.fd` next to each one. The ones most likely to affect a port:

| not available | do this instead |
|---|---|
| `SDL_Log`, `SDL_SetError`, `SDL_snprintf` and other variadic calls | use SDL's `*V` variants (`SDL2_LogMessageV`, `SDL2_vsnprintf`) which take a `va_list` and **are** exported |
| `SDL_CreateThread`, `SDL_CreateThreadWithStackSize` | SDL's dynamic API carries the Windows signature for these; use AmigaOS tasks directly for now |
| `SDL_JoystickGetGUIDString` and friends | these pass `SDL_JoystickGUID` **by value**, which a register ABI cannot express |
| Vulkan, Metal, D3D, Android, iOS, WinRT entry points | not built on AmigaOS 3 |

If you need one of the reserved ones, the fix is a hand-written wrapper added
at slot 1000+ — see `tools/genabi.py` and the `EXTENSIONS` list.

## Choosing a window or a screen

The AmigaOS 3 video driver decides for itself whether to open on Workbench or
on a private screen, and its probe is conservative — it declines some Picasso96
Workbench screens that would host a window perfectly well.

Your program can say what it wants:

```c
SDL2_SetHint("SDL_VIDEO_AMIGAOS3_SCREEN", "workbench");  /* titled window   */
SDL2_SetHint("SDL_VIDEO_AMIGAOS3_SCREEN", "screen");     /* private screen  */
SDL2_SetHint("SDL_VIDEO_AMIGAOS3_SCREEN", "auto");       /* driver decides  */
```

Set it **before** `SDL2_CreateWindow`. On AGA it has no effect: without RTG
there is no path for an ARGB surface into a window on a planar screen, so a
private screen is always used.

## Getting at the Intuition window

`SDL2_GetWindowWMInfo` is exported, so Amiga-native code can reach the real
`struct Window` behind an SDL window — for IDCMP, menus, or anything SDL does
not model.

## Things that will bite

**Struct layout is not guaranteed by the `.fd`.** It fixes which *register*
each argument arrives in, and nothing else. Use SDL2's real headers; do not
hand-copy struct definitions. `SDL_Rect` is four `int`s (16 bytes) — declaring
it as four `WORD`s costs 8, and `SDL_FillRect` then silently clips every
rectangle away and returns success.

**8-bit surfaces need a palette.** On AGA the driver hands back an `INDEX8`
surface, and `SDL_AllocPalette` fills all 256 entries with the same colour.
`SDL_MapRGB` on an indexed format is a nearest-colour search, so every colour
returns the same index and the display is one flat colour. Install a real
palette with `SDL2_SetPaletteColors` before drawing.

**A resident library is not replaced by copying over the file.** If you are
building the library itself, use `./build.sh dev`, which names each build
uniquely so a pinned copy from a crashed run cannot be found. Otherwise
`Avail FLUSH` from a shell, or reboot.

## A worked example

`test/sdl2test.c` in the repository opens the library, reports what the video
driver actually gave it, installs a palette when the surface is indexed, plays
a sound and draws to the window surface. It is the shortest complete example of
every rule above.

Its sound is `test/cuckoo.raw` — signed 8-bit mono at 11025 Hz, which is what
the AmigaOS audio path wants, since Paula is an 8-bit signed DMA device.
`tools/wav2raw.py` converts any PCM WAV to that format and prints the
`SDL_AudioSpec` to match:

```sh
python tools/wav2raw.py mysound.wav mysound.raw
```

It keeps the source rate by default. Resampling invents samples and gains
nothing; pass `--rate` only when the source rate is one the target cannot play.

A recording is used deliberately in preference to a synthesised tone: a sine
wave sounds much the same whether the rate, the signedness and the channel
count are right or merely close, and a real sample does not.

# Building

## 0. What you need, and what this repository does not ship

Everything **SDL** is in this repository. The cross toolchain and the machine
to run the result on are not, so here is where they come from.

| | |
|---|---|
| [Docker](https://docs.docker.com/get-docker/) | the only hard requirement on the build host |
| [`amigadev/crosstools:m68k-amigaos`](https://hub.docker.com/r/amigadev/crosstools) | the cross toolchain image, from the [amigadev/crosstools](https://github.com/AmigaPorts/docker-cross-compiler-m68k) project |
| [WinUAE](https://www.winuae.net/) or [FS-UAE](https://fs-uae.net/) | to run the result |
| A Kickstart 3.x ROM | **not redistributable** — obtain legally, e.g. [Amiga Forever](https://www.amigaforever.com/) |

Inside the toolchain image, the pieces this build actually depends on:

| | |
|---|---|
| **GCC 6.5** (`m68k-amigaos-gcc`) | the compiler — see below for why this version specifically |
| **libnix** | the C runtime, and `libinit.o` / `ADD2LIST`, which *are* the shared-library mechanism |
| **NDK includes** | `exec/`, `dos/`, `intuition/`, `inline/macros.h` |
| **`fd2pragma`** | generates every caller-side inline from the `.fd`. By Dirk Stöcker, from [Aminet](https://aminet.net/package/dev/misc/fd2pragma) |
| **`vasm`** | assembles the c2p routine |
| **GNU `ld`** | not `vlink` — see *Link with GNU ld* below |

`toolchain/` in this repository carries emulator configs, debug helpers and
test scripts inherited from the upstream port.

## 1. Toolchain

```sh
docker pull amigadev/crosstools:m68k-amigaos
```

**Use GCC 6.5, which is what this image provides.** This is not conservatism:

- GCC 13–15 miscompile NDK macros — literal constants reach the wrong register.
- GCC 15.2's libnix CRT walks `__EXIT_LIST__` into garbage after `main`.
- The tag `m68k-amigaos-gcc10` is misnamed; its digest drifted to GCC 15.2.

## 2. SDL2

Clone and build [libSDL2-amigaos3](https://github.com/bdgscotland/libSDL2-amigaos3),
then apply the patch:

```sh
cd /path/to/libSDL2-amigaos3
git apply /path/to/SDL2.Library-Amiga-m68K/patches/0001-video-amigaos3-add-SDL_HINT_VIDEO_AMIGAOS3_SCREEN.patch
make
```

The patch adds `SDL_HINT_VIDEO_AMIGAOS3_SCREEN`, letting an application choose
between a Workbench window and a private screen. Without it the driver decides
on its own, and its probe declines some Picasso96 Workbench screens that are
perfectly capable of hosting a window — you get a borderless private screen
with no way to ask for anything else.

To rebuild a single driver object without a full `make`:

```sh
m68k-amigaos-gcc -std=gnu99 -O0 -m68030 -noixemul \
  -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare \
  -I./include -I./src -D__AMIGAOS3__ -DSDL_OS3_DEBUG \
  -c src/video/amigaos3/SDL_os3window.c -o src/video/amigaos3/SDL_os3window.o
m68k-amigaos-ar r libSDL2.a src/video/amigaos3/SDL_os3window.o
m68k-amigaos-ranlib libSDL2.a
```

Those source files use CRLF line endings. Preserve them when patching.

## 3. This library

```sh
SDL2_SRC=/path/to/libSDL2-amigaos3 ./build.sh
```

Optionally `DEPLOY=/path/to/amiga/share` to copy the results out, and
`./build.sh release` to build as plain `sdl2.library` instead of the
development name.

Products land in `build/`.

---

## Constraints that will otherwise cost you a day

Every one of these produces a library that builds cleanly and then fails at
runtime, usually with a symptom that points somewhere else entirely.

### libinit.o is the startup — but it does not start everything

`libinit.o` supplies the ROMTag, Open/Close/Expunge and the C runtime
scaffolding a library otherwise has none of. Do **not** replace it with a
hand-written assembly skeleton; the link then fails on `__CTOR_LIST__`,
`____filelist`, `____stdin` and `DOSBase`.

It does **not** call `__initmalloc`. Its only undefined symbols are
`LibName`/`LibVersion`/`LibRevision`/`LibIdString` and the two user hooks, so
every libnix subsystem that needs starting is yours to start.

**This one is vicious.** SDL2 is built with `HAVE_MALLOC`, so every SDL
allocation is libnix's heap. libnix's `malloc` begins:

```
movea.l (__memsema),a0
jsr     -564(a6)            ; ObtainSemaphore
```

`__initmalloc` is what allocates and initialises that semaphore. Without it
`__memsema` is NULL and `malloc` calls `ObtainSemaphore(NULL)`. That does not
crash: `InitSemaphore` sets `ss_QueueCount` to −1 precisely so the uncontested
path fires on zero, and at address zero that word is exception vector 11, never
zero — so it takes the **contested** path, queues a request, and `Wait`s for a
signal nobody will send. The task blocks forever, cannot be reaped, pins the
library open, and corrupts exception vectors 10 and 11 on the way through.

The symptom is that *every* SDL2 call hangs with no crash and no output.

Signatures come from the image, not from a manual — several libnix versions
exist and disagree. This targets libnix 4:

```c
extern LONG __stdargs __UserLibInit(struct Library *, REG(a4, APTR));
extern VOID __stdargs __UserLibCleanup(REG(a4, APTR));
```

Note `Cleanup`, lowercase `u`, and the `a4` argument. An older manual documents
`__UserLibCleanUp(void)`, which would silently never be called.

### `ADD2LIST(..., 22)`, not 24

`libinit.o` places `__FuncTable__` in section `.list___FuncTable__`. The linker
script gathers `.list_*` into TEXT but `.dlist_*` into DATA, so type 24 puts the
exports in a different output section and leaves the table truncated after
libinit's own four entries. Calling any export then reads past the end of the
table and jumps into whatever follows — which presents as a Line-1111 "A-line"
crash in a program containing no A-line instruction.

### Link with GNU `ld`, not vlink

vlink drops the `ADD2LIST` sections silently. libnix's mechanism needs ld's
`SORT_BY_NAME` rules.

### The function table must end with `-1`

`MakeFunctions` walks the table until it reads −1, writing one jump entry per
element downward from the library base. Without the terminator it never stops:
it consumes whatever follows in memory and writes jump entries over unrelated
memory until the machine locks up — caught in ROM at `MakeFunctions`' own
`move.l d1,-(a0)` with interrupts masked.

### `fd2pragma --special 40` or `41`, never `43`

Mode 43 emits **positive** LVO offsets — `jsr 114(a6)` instead of
`jsr -114(a6)`. Calls land just above the library base and execute whatever is
there. Also presents as a bogus Line-1111 crash.

### Callers need SDL2's headers

The `.fd` file guarantees **register** marshalling. It guarantees nothing about
struct layout. Hand-copying SDL2 struct definitions into a caller is how
`SDL_Rect` ends up declared as four `WORD`s when it is four `int`s — 8 bytes
against 16. `SDL_FillRect` then reads `x` as `(x<<16|y)`, `y` as `(w<<16|h)`,
and `w`/`h` from adjacent stack; every rectangle lands outside the surface, is
clipped away, and `FillRect` returns success having drawn nothing. The window
stays blank while the log says everything worked.

### Replacing the library file does nothing while it is resident

AmigaOS keeps a library in memory after its last client closes. `Avail FLUSH`
from a shell expunges it; a Workbench-launched program has to do it itself.

A run that **hangs** never closes the library at all, so it cannot be expunged
and the next run silently gets the previous jump table. Newly added exports
then call off the end of it and crash — and the only cure is a reboot.

Hence the development naming scheme. exec's `OpenLibrary` finds a resident
library **by name** (verified against Kickstart 3.1: `OpenLibrary` is LVO −552,
and is `Forbid` → `FindName` on `SysBase->LibList` → version check → the
library's own Open; `FindName` compares bytes to the NUL, with no path
stripping or case folding). Naming each development build
`sdl2_r<revision>.library` means a pinned copy from an earlier build is simply
not what the next one asks for. It becomes inert rather than hazardous, and
nothing needs rebooting.

Release builds use the plain `sdl2.library`.

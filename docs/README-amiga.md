# Building the Amiga targets with CMake

The `amigadev/crosstools` Docker images contain CMake wrappers that select the
matching cross-toolchain file automatically. Do not pass
`CMAKE_TOOLCHAIN_FILE` for the AmigaOS 3 or AmigaOS 4 commands below.

Run all commands from the repository root. The source tree is mounted at
`/work`, so build products remain on the host.

To install into a staging directory, set an absolute container path at
configure time, for example `-DCMAKE_INSTALL_PREFIX=/work/stage`, then run
`cmake --build <build-directory> --target install`. The images' toolchain
wrappers do not support the newer `cmake --install ... --prefix ...` form.

## AmigaOS 3

Build the static libraries with the m68k image:

```sh
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:m68k-amigaos \
  cmake -S . -B build-amigaos3 \
    -DSDL_AMIGAOS3_LIBRARY=OFF -DSDL_TEST=OFF -DSDL_TESTS=OFF
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:m68k-amigaos \
  cmake --build build-amigaos3 -j2
```

To also build the native Amiga `sdl2.library`:

```sh
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:m68k-amigaos \
  cmake -S . -B build-amigaos3-library \
    -DSDL_AMIGAOS3_LIBRARY=ON -DSDL_TEST=OFF -DSDL_TESTS=OFF
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:m68k-amigaos \
  cmake --build build-amigaos3-library --target SDL2-amiga-library -j2
```

`SDL_AMIGAOS3_AGA=ON` enables the AGA chunky-to-planar implementation and
requires `vasmm68k_mot`; the image currently supplies it. An RTG-only build can
set this option to `OFF`.

The AmigaOS 3 audio bootstrap order is Paula, AHI, then dummy. AHI is an
optional runtime installation and can be selected explicitly with
`SDL_AUDIODRIVER=ahi`. The backend supports playback and capture through
`ahi.device` version 4 or newer. FS-UAE's old AHI stub can open successfully
while producing no sound, so audio still needs testing on a working AHI
installation or real hardware.

The existing `build.sh` workflow remains available for the classic native
library and packaging. CMake is the portable build-system entry point.

## AmigaOS 4

The image defaults to clib2, which builds the static library:

```sh
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:ppc-amigaos \
  cmake -S . -B build-amigaos4 -DSDL_TEST=OFF -DSDL_TESTS=OFF
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:ppc-amigaos \
  cmake --build build-amigaos4 -j2
```

Use newlib when building the ELF shared object:

```sh
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:ppc-amigaos \
  cmake -S . -B build-amigaos4-so \
    -DPPC_CRT=newlib -DSDL_TEST=OFF -DSDL_TESTS=OFF
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:ppc-amigaos \
  cmake --build build-amigaos4-so -j2
```

The native AmigaOS 4 `.library` format is a separate option and also requires
newlib:

```sh
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:ppc-amigaos \
  cmake -S . -B build-amigaos4-library \
    -DPPC_CRT=newlib -DSDL_SHARED=OFF -DSDL_AMIGAOS4_LIBRARY=ON \
    -DSDL_AMIGAOS4_PREFS=OFF -DSDL_TEST=OFF -DSDL_TESTS=OFF
docker run --rm -v "$PWD:/work" -w /work \
  amigadev/crosstools:ppc-amigaos \
  cmake --build build-amigaos4-library \
    --target SDL2-amigaos4-library -j2
```

This produces `build-amigaos4-library/sdl2.library`. Following the
`gic400.library` example, CMake calls `sfdc(...)` once, makes the executable
depend on and link the resulting `sdl2` interface target, and installs both
the source and generated SDK headers. The OS4 resident and SFDC-generated
server gates/function table are normal project sources under
`library/amigaos4/`; there is no Python OS4 library generator.

The native OS4 interface omits four `va_list` entry points that SFDC's PPC/68K
compatibility gates cannot marshal. They remain available in the static and
ELF shared libraries.

When `library/amigaos4/sdl2_lib.sfd` changes, regenerate the checked-in files
under `library/amigaos4/generated/` and
`library/amigaos4/include/interfaces/` with the pinned SFDC version. CMake's
single `sfdc(...)` call continues to own the clib/proto/inline/pragmas SDK
headers in the build directory.

## CPM, SFDC and offline builds

The native `.library` options use CPM.cmake to obtain the pinned
`cmake-amiga-common-library` package. The m68k image contains SFDC at
`/opt/m68k-amigaos/bin/sfdc`. The PPC image does not currently contain SFDC,
so CMake obtains the pinned `AmigaPorts/sfdc` source through CPM and runs it as
a Perl program.

The first native-library configure therefore requires network access unless
the dependencies are already cached. Set `CPM_SOURCE_CACHE` to a mounted,
persistent directory to reuse downloads. For a fully offline build, populate
that cache beforehand and pass `-DSDL_SFDC_EXECUTABLE=/path/to/sfdc` when SFDC
is not installed in the image. Exact dependency revisions are recorded in
`package-lock.cmake`. The native-library setup uses `file(CHMOD)` for its
target-specific SFDC launcher and therefore requires CMake 3.19 or newer; both
documented Docker images satisfy this requirement.

`SDL_AMIGA_SFDC_TARGET` defaults to `m68k-amigaos` or `ppc-amigaos` as
appropriate. SFDC also supports targets such as `ppc-morphos` and
`i386-aros`; override the cache variable when reusing the generated SDK setup
for those toolchains. This selects SFDC's header dialect; it does not by itself
turn this repository's OS3/OS4 CMake platform backend into an AROS or MorphOS
build.

## WarpOS

Use `build-scripts/cmake-toolchain-warpos.cmake` with a toolchain that provides
both `m68k-amigaos-gcc` and `powerpc-amigaos-gcc`:

```sh
cmake -S . -B build-warpos \
  -DCMAKE_TOOLCHAIN_FILE=build-scripts/cmake-toolchain-warpos.cmake
cmake --build build-warpos -j2
```

The current `amigadev/crosstools:m68k-amigaos` image does not provide the
WarpOS `powerpc-amigaos-gcc` compiler, so it cannot validate this target by
itself.

## Reference implementations and tooling

These repositories are the primary references used for the Amiga work:

- [AmigaOS 4 SDL](https://github.com/AmigaPorts/SDL)
- [AROS SDL2 contribution](https://github.com/aros-development-team/contrib/tree/master/SDL2/main)
- [MorphOS SDL 2.32 branch](https://github.com/BeWorld2018/SDL/tree/release-2.32.x-MOS)
- [Classic SDL 1.2](https://github.com/AmigaPorts/libSDL12)
- [CMake Amiga common library](https://github.com/AmigaPorts/cmake-amiga-common-library)
- [SFDC](https://github.com/AmigaPorts/sfdc)
- [gic400.library CMake example](https://github.com/MBeijer/emu68-gic400-library/tree/feature/cmake-improvements)
- [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake)

The AHI SDK headers and `ahi.device` autodoc used for the AmigaOS 3 backend
are installed in the m68k cross-tools image.

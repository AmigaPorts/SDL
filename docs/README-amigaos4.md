================================================================================
SDL 2 requirements
================================================================================

AmigaOS 4.1 Final Edition
MiniGL (optional)
OpenGL ES 2.0 (optional)

================================================================================
Installation
================================================================================

There is an installer script that can be used to install shared objects, prefs
program and the SDK. Many current SDL2 applications are linked statically but
there are some apps like RebelSDL (Hollywood) that use SDL2 as a shared object.

Installer script creates soft link from libSDL2.so to the latest libSDL2-2.x.so
file. SDL2 version numbering changed after 2.0.22 release: next stable release
had version 2.24.0.

================================================================================
Building SDL 2 library
================================================================================

    # non-debug variant
    gmake -f Makefile.amigaos4

    # with serial debug prints
    gmake -f Makefile.amigaos4 debug

The `amigadev/crosstools:ppc-amigaos` image also supports CMake. Its `cmake`
wrapper selects the image's AmigaOS 4 toolchain automatically. See
`README-amiga.md` for the complete cross-build guide and dependency caveats:

    docker run --rm -v "$PWD:/work" -w /work \
        amigadev/crosstools:ppc-amigaos \
        cmake -S . -B build-amigaos4 -DPPC_CRT=newlib
    docker run --rm -v "$PWD:/work" -w /work \
        amigadev/crosstools:ppc-amigaos \
        cmake --build build-amigaos4

The newlib configuration builds both `libSDL2.a` and
`libSDL2-2.<minor>.so`. The image's default clib2 configuration builds the
static library only, because clib2 cannot link this port's shared object.

A native AmigaOS 4 library can be requested independently of the ELF shared
object:

    cmake -S . -B build-amigaos4-library -DPPC_CRT=newlib \
        -DSDL_AMIGAOS4_LIBRARY=ON

This produces `sdl2.library` with native `__library` and `main` interfaces.
The option requires newlib. CMake uses the single `sfdc(...)` integration from
`cmake-amiga-common-library`; the native library target depends on and links
the generated interface target. Its resident and SFDC-generated server sources
are kept under `library/amigaos4/`. There is no Python OS4 library generator.

The PPC image currently lacks SFDC. The CMake build fetches the pinned
`AmigaPorts/sfdc` source through CPM on first configure. Set
`CPM_SOURCE_CACHE` for repeatable downloads or provide
`SDL_SFDC_EXECUTABLE` for an offline build.

================================================================================
Using SDL 2 in your projects
================================================================================

    #include "SDL2/SDL.h"
    ...do magical SDL2 things...

    gcc helloworld.c -use-dynld -lSDL2

================================================================================
Setting REGAPP_Description
================================================================================

Set SDL_HINT_APP_NAME before SDL_Init():

    SDL_SetHint(SDL_HINT_APP_NAME, "Some description");

================================================================================
About SDL_Renderers
================================================================================

A renderer is a subsystem that can do 2D drawing. There are 4 renderers:
software, OpenGL, OpenGL ES 2.0 and compositing.

Software renderer is always available. This is the slowest option but emulation
users may need to use this.

OpenGL renderer uses MiniGL (and Warp3D) for accelerated drawing. Drawing is
done in immediate mode. This should be fairly fast if textures are static.

OpenGL ES 2.0 renderer uses ogles2.library (and Warp3D Nova).

Compositing renderer uses AmigaOS 4 graphics.library for accelerated drawing.
However, blended lines and points are not accelerated since compositing doesn't
support them. Compositing renderer supports ARGB8888, IYUV and YV12 texture
formats. Compositing renderer is the default one.

It's possible to select the preferred renderer before its creation, like this:

    SDL_SetHint(SDL_HINT_RENDER_DRIVER, name);

where name is "software", "opengl" or "compositing".

It's possible to enable VSYNC with:

    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");

There is a benchmark tool called sdl2benchmark which was written to test
available renderers.

================================================================================
About ENV variables
================================================================================

Advanced users may use ENV variables to control some things in SDL2.
Some variables supported by the SDL_Renderer subsystem:

Batch drawing:

setenv SDL_RENDER_BATCHING 1 # Enable
setenv SDL_RENDER_BATCHING 0 # Disable

Driver selection:

setenv SDL_RENDER_DRIVER "software"
setenv SDL_RENDER_DRIVER "compositing"
setenv SDL_RENDER_DRIVER "opengl"
setenv SDL_RENDER_DRIVER "opengles2"

VSYNC:

setenv SDL_RENDER_VSYNC 1 # Enable
setenv SDL_RENDER_VSYNC 0 # Disable

It must be noted that these variables apply only to those applications that
actually use the SDL_Renderer subsystem, and not 3D games.

Screensaver control:

setenv SDL_VIDEO_ALLOW_SCREENSAVER 1 # Enable
setenv SDL_VIDEO_ALLOW_SCREENSAVER 0 # Disable

Please check also SDL2 preferences program.

================================================================================
About OpenGL
================================================================================

If you want to draw accelerated 3D graphics or use explicitly OpenGL functions,
you have to create an OpenGL context, instead of an SDL_Renderer.

If you would like to create an OpenGL ES 2.0 context, you need to specify the
version before window creation, for example:

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

MiniGL context can be created using major version 1 and minor version 3. This is
also the default setup.

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

================================================================================
About Joysticks
================================================================================

AmigaInput-compatible joysticks can be used with SDL2. In addition to legacy
joystick API, SDL supports new game controller API which uses a predefined
database to map joystick axes and buttons. At the moment game controller
database contains the following entries:

- Speedlink Competition Pro
- Ewent Joypad EW3170
- PS2 Joystick (USB adaptor)
- SHARK 91230 Joystick
- MAGIC-NS
- Wireless Controller
- 8Bitdo SN30 Pro
- Thrustmaster dual analog 3.2
- XEOX Gamepad SL-6556-BK
- Strike2 Joystick
- GeeekPi_A gamepad
- Logitech Cordless RumblePad 2
- Logitech RumblePad 2 USB
- Logitech(R) Precision(TM) Gamepad
- Logitech Dual Action
- MAYFLASH Arcade Fightstick F300
- Game Controller for Android
- 2In1 USB Joystick
- DualSense Wireless Controller

Joysticks can be tested using testjoystick tool. New game controller mappings
can be generated using controllermap tool. New mappings can be then added to
the game controller database.

================================================================================
WinUAE / QEMU
================================================================================

Because emulators doesn't support hardware-accelerated compositing or 3D, you
need to install the following software:

- http://os4depot.net/index.php?function=showfile&file=graphics/misc/patchcompositetags.lha
- http://os4depot.net/index.php?function=showfile&file=library/graphics/wazp3d.lha

================================================================================
Tips
================================================================================

If you are already familiar with SDL 1.2, or porting SDL 1.2 code, it's worth
checking the migration guide at:

https://wiki.libsdl.org/SDL2/MigrationGuide

Always check the return values of functions and in error case you can get more
information using SDL_GetError() function!

================================================================================
Limitations
================================================================================

Altivec support is disabled for compatibility reasons. It should be possible to
enable in private builds.

Unsupported subsystems include Haptic and Power. There is no Vulkan backend for
AmigaOS either.

OpenGL renderer doesn't support render targets and blend modes "ADD" or "MOD".
This is due to missing features in MiniGL.

Compositing renderer doesn't support color modulation for triangle geometry. Use
"software" or "opengles2" driver if you need it.

================================================================================
Project page and bug tracker
================================================================================

https://github.com/AmigaPorts/SDL

/* Chocolate Doom config.h for AmigaOS 3.x cross-compilation */

#define PACKAGE_NAME "chocolate-doom"
#define PACKAGE_TARNAME "chocolate-doom"
#define PACKAGE_VERSION "3.1.0"
#define PACKAGE_STRING "chocolate-doom 3.1.0"
#define PROGRAM_PREFIX "chocolate-"

/* Disabled: no SDL2_mixer, SDL2_net, libpng, libsamplerate, FluidSynth */
/* #undef HAVE_FLUIDSYNTH */
/* #undef HAVE_LIBSAMPLERATE */
/* #undef HAVE_LIBPNG */

/* libnix has dirent.h via amiport posix-shim */
#define HAVE_DIRENT_H 1

/* libnix/amiport provides these */
#define HAVE_DECL_STRCASECMP 1
#define HAVE_DECL_STRNCASECMP 1

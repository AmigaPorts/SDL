/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>
  AmigaOS 3.x port (C) 2026

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL_config_amigaos3_h_
#define SDL_config_amigaos3_h_
#define SDL_config_h_

#include "SDL_platform.h"

/*
 * SDL2 configuration for AmigaOS 3.x on Motorola 68k.
 *
 * Target: 68030+ with CyberGraphX RTG.
 * Compiler: bebbo-gcc (GCC 6.5.0b), -std=gnu99, -noixemul.
 *
 * Reference: SDL_config_minimal.h, SDL2 OS4 port config.
 */

/* C library features available in bebbo-gcc libnix */
#define HAVE_STDARG_H   1
#define HAVE_STDDEF_H   1
#define HAVE_STDINT_H   1

/* libnix provides these (C89 runtime) */
#define HAVE_ALLOCA_H   0
#define HAVE_ALLOCA     0
#define HAVE_MALLOC     1
#define HAVE_CALLOC     1
#define HAVE_REALLOC    1
#define HAVE_FREE       1
#define HAVE_MEMSET     1
#define HAVE_MEMCPY     1
#define HAVE_MEMMOVE    1
#define HAVE_MEMCMP     1
#define HAVE_STRLEN     1
#define HAVE_STRLCPY    0
#define HAVE_STRLCAT    0
#define HAVE_STRDUP     1
#define HAVE_STRCHR     1
#define HAVE_STRRCHR    1
#define HAVE_STRSTR     1
#define HAVE_STRTOL     1
#define HAVE_STRTOUL    1
#define HAVE_STRTOLL    0
#define HAVE_STRTOULL   0
#define HAVE_STRTOD     1
#define HAVE_ATOI       1
#define HAVE_ATOF       1
#define HAVE_STRCMP      1
#define HAVE_STRNCMP    1
#define HAVE_STRCASECMP 1
#define HAVE_STRNCASECMP 1
#define HAVE_SSCANF     1
#define HAVE_VSSCANF    0
#define HAVE_SNPRINTF   1
#define HAVE_VSNPRINTF  1

/* Math functions */
#define HAVE_ACOS       1
#define HAVE_ACOSF      0
#define HAVE_ASIN       1
#define HAVE_ASINF      0
#define HAVE_ATAN       1
#define HAVE_ATANF      0
#define HAVE_ATAN2      1
#define HAVE_ATAN2F     0
#define HAVE_CEIL       1
#define HAVE_CEILF      0
#define HAVE_COPYSIGN   0
#define HAVE_COPYSIGNF  0
#define HAVE_COS        1
#define HAVE_COSF       0
#define HAVE_EXP        1
#define HAVE_EXPF       0
#define HAVE_FABS       1
#define HAVE_FABSF      0
#define HAVE_FLOOR      1
#define HAVE_FLOORF     0
#define HAVE_FMOD       1
#define HAVE_FMODF      0
#define HAVE_LOG        1
#define HAVE_LOGF       0
#define HAVE_LOG10      1
#define HAVE_LOG10F     0
#define HAVE_LROUND     0
#define HAVE_LROUNDF    0
#define HAVE_POW        1
#define HAVE_POWF       0
#define HAVE_ROUND      0
#define HAVE_ROUNDF     0
#define HAVE_SCALBN     0
#define HAVE_SCALBNF    0
#define HAVE_SIN        1
#define HAVE_SINF       0
#define HAVE_SQRT       1
#define HAVE_SQRTF      0
#define HAVE_TAN        1
#define HAVE_TANF       0
#define HAVE_TRUNC      0
#define HAVE_TRUNCF     0

/* POSIX features NOT available in libnix / AmigaOS 3.x */
#define HAVE_GETENV     0
#define HAVE_SETENV     0
#define HAVE_PUTENV     0
#define HAVE_UNSETENV   0
#define HAVE_QSORT      1
#define HAVE_ABS        1
#define HAVE_CTYPE_H    1
#define HAVE_MATH_H     1
#define HAVE_FLOAT_H    1
#define HAVE_LIMITS_H   1
#define HAVE_SIGNAL_H   0
#define HAVE_ICONV_H    0
#define HAVE_ICONV      0
#define HAVE_SYS_TYPES_H 0
#define HAVE_STDIO_H    1
#define HAVE_STRING_H   1
#define HAVE_WCHAR_H    0
#define HAVE_INTTYPES_H 0
#define HAVE_STRINGS_H  0
#define HAVE_MPROTECT   0
#define HAVE_SIGACTION   0

/* Byte order -- 68k is big-endian */
#define SDL_BYTEORDER   SDL_BIG_ENDIAN

/* Atomics -- 68020+ has CAS instruction. No GCC builtins. */
#define HAVE_GCC_ATOMICS 0
#define HAVE_GCC_SYNC_LOCK_TEST_AND_SET 0

/* Dynamic API -- disabled, no dlopen on AmigaOS 3.x */
#define SDL_DYNAMIC_API 0

/* --- VIDEO DRIVERS --- */
#define SDL_VIDEO_DRIVER_AMIGAOS3   1
#define SDL_VIDEO_DRIVER_DUMMY      1   /* fallback */

/* --- AUDIO DRIVERS --- */
#define SDL_AUDIO_DRIVER_AHI        1
#define SDL_AUDIO_DRIVER_DUMMY      1   /* fallback */

/* --- RENDER DRIVERS --- */
#define SDL_VIDEO_RENDER_SW         1   /* software renderer */

/* --- THREADING --- */
#define SDL_THREAD_AMIGAOS3         1

/* --- TIMER --- */
#define SDL_TIMER_AMIGAOS3          1

/* --- JOYSTICK --- */
#define SDL_JOYSTICK_AMIGAOS3       1

/* --- HAPTIC --- */
#define SDL_HAPTIC_DISABLED         1

/* --- HIDAPI --- */
#define SDL_HIDAPI_DISABLED         1

/* --- SENSOR --- */
#define SDL_SENSOR_DISABLED         1

/* --- LOADSO --- */
#define SDL_LOADSO_DISABLED         1

/* --- FILESYSTEM --- */
#define SDL_FILESYSTEM_AMIGAOS3     1

/* --- POWER --- */
#define SDL_POWER_DISABLED          1

/* --- LOCALE --- */
#define SDL_LOCALE_DISABLED         1

/* --- MISC --- */
#define SDL_MISC_DISABLED           1

#endif /* SDL_config_amigaos3_h_ */

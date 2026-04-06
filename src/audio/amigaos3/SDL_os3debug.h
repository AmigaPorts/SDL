/*
  Debug output for AmigaOS 3.x backends.

  Two modes:
  1. kprintf (serial) -- needs socat + serial_port config in FS-UAE
  2. File-based -- appends to WORK:sdl_debug.log via AmigaDOS

  File-based works without any serial setup. Uses Forbid/Permit around
  the file write to be safe from any task context.
*/

#ifndef SDL_os3debug_h_
#define SDL_os3debug_h_

#ifdef SDL_OS3_DEBUG

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <proto/dos.h>
#include <string.h>
#include <stdio.h>
#ifdef WARPUP
#pragma pop
#endif

/* Write debug line to WORK:sdl_debug.log.
   Safe to call from any task (uses Forbid/Permit). */
static inline void os3_dlog(const char *msg)
{
    BPTR fh;
    Forbid();
    fh = Open((CONST_STRPTR)"WORK:sdl_debug.log", MODE_OLDFILE);
    if (fh) {
        Seek(fh, 0, OFFSET_END);
    } else {
        fh = Open((CONST_STRPTR)"WORK:sdl_debug.log", MODE_NEWFILE);
    }
    if (fh) {
        Write(fh, (APTR)msg, strlen(msg));
        Write(fh, (APTR)"\n", 1);
        Close(fh);
    }
    Permit();
}

/* Format + write. Uses a small stack buffer (safe, <256 bytes). */
#define DLOG(fmt, ...) do { \
    char _dbuf[256]; \
    snprintf(_dbuf, sizeof(_dbuf), "[SDL] " fmt, ##__VA_ARGS__); \
    os3_dlog(_dbuf); \
} while(0)

#else
#define DLOG(fmt, ...) do {} while(0)
#endif

#endif /* SDL_os3debug_h_ */

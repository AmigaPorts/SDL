/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Internal header: structs and library base declarations.
*/

#ifndef SDL_os3video_h_
#define SDL_os3video_h_

#include "../../SDL_internal.h"
#include "../SDL_sysvideo.h"

/* AmigaOS headers */
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/cybergraphics.h>
#include <cybergraphx/cybergraphics.h>
#include <graphics/displayinfo.h>
#include <intuition/screens.h>
#include <intuition/intuition.h>
#include <exec/types.h>

/*
 * Library bases.
 * IntuitionBase and GfxBase are declared by <proto/intuition.h> and
 * <proto/graphics.h> as their specific struct types (struct IntuitionBase *,
 * struct GfxBase *). Do not redeclare them here.
 * CyberGfxBase is declared by <proto/cybergraphics.h> as struct Library *.
 */

/* Per-display driver data */
typedef struct OS3_DisplayData {
    ULONG modeID;    /* CyberGraphX display mode ID for this display */
    int   width;     /* display width in pixels */
    int   height;    /* display height in pixels */
    int   depth;     /* display depth in bits */
    struct Screen *fullscreen_screen; /* custom screen for fullscreen mode (NULL = WB) */
} OS3_DisplayData;

/* Per-window driver data */
typedef struct OS3_WindowData {
    struct Window *window;    /* Intuition window */
    struct Screen *screen;    /* Intuition screen (NULL if using WB screen) */
    int            is_fullscreen; /* non-zero if we own the screen */
    /* AGA palette shadow for dirty detection (used when CyberGfxBase == NULL) */
    SDL_Color      aga_palette[256];
    int            aga_palette_set; /* 0 = never synced */
} OS3_WindowData;

/* Bootstrap entry -- wired into SDL_VideoBootStrap array */
extern VideoBootStrap OS3_bootstrap;

#endif /* SDL_os3video_h_ */

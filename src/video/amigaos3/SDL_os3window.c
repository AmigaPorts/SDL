/*
 * ALTERED SOURCE -- SDL2.Library-Amiga-m68K.
 *
 * This file differs from the original libSDL2-amigaos3 release at
 * https://github.com/bdgscotland/libSDL2-amigaos3
 *
 * Change: OS3_OpenWindowed honours SDL_HINT_VIDEO_AMIGAOS3_SCREEN,
 *         so the application chooses between a Workbench window
 *         and a private screen instead of the driver deciding.
 *
 * See patches/ for the change in isolation, and docs/ALTERATIONS.md
 * for the full list of files this repository modifies.
 */
/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Window management: open/close Intuition windows and screens.

  Default strategy: windowed on Workbench screen.
  SDL_WINDOW_FULLSCREEN: open a custom CGX screen + borderless window.

  Reference: cybergraphx-reference.md -- Window Management section
             crash-patterns.md -- #7 (stack), #10 (large buffers)
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <graphics/modeid.h>   /* BIDTAG_* for BestModeID (AGA mode selection) */
#include <graphics/displayinfo.h>  /* DisplayInfo, DimensionInfo for P96 fallback */
#ifdef WARPUP
#pragma pop
#endif
#include "SDL_os3video.h"
#include "SDL_os3window.h"
#include "SDL_os3framebuffer.h"
#include "../../events/SDL_windowevents_c.h"
#include "SDL_hints.h"

/*
 * Find an RTG mode >= requested size and depth by manually walking
 * the display database. Fallback for when BestCModeIDTags() fails
 * (e.g. Picasso96 without cybergraphics.library on Vampire SAGA).
 */
ULONG OS3_FindRTGMode(int want_w, int want_h, int want_depth)
{
    ULONG nextid;
    ULONG best_id = INVALID_ID;
    ULONG best_w = 0xFFFFFFFF, best_h = 0xFFFFFFFF;

    nextid = NextDisplayInfo(INVALID_ID);
    while (nextid != INVALID_ID) {
        int is_rtg = 0;
        ULONG w, h, bpp;

        if (CyberGfxBase && IsCyberModeID(nextid)) {
            w   = GetCyberIDAttr(CYBRIDATTR_WIDTH,  nextid);
            h   = GetCyberIDAttr(CYBRIDATTR_HEIGHT, nextid);
            bpp = GetCyberIDAttr(CYBRIDATTR_DEPTH,  nextid);
            is_rtg = 1;
        } else {
            struct DisplayInfo di;
            if (GetDisplayInfoData(NULL, (UBYTE *)&di, sizeof(di),
                                   DTAG_DISP, nextid)) {
                if (di.PropertyFlags & (1UL << 12)) {
                    struct DimensionInfo dim;
                    if (GetDisplayInfoData(NULL, (UBYTE *)&dim,
                            sizeof(dim), DTAG_DIMS, nextid)) {
                        w   = dim.Nominal.MaxX - dim.Nominal.MinX + 1;
                        h   = dim.Nominal.MaxY - dim.Nominal.MinY + 1;
                        bpp = dim.MaxDepth;
                        is_rtg = 1;
                    }
                }
            }
        }

        if (is_rtg && (int)w >= want_w && (int)h >= want_h &&
            (int)bpp >= want_depth) {
            /* Prefer smallest mode that fits */
            if (w < best_w || (w == best_w && h < best_h)) {
                best_w = w;
                best_h = h;
                best_id = nextid;
            }
        }
        nextid = NextDisplayInfo(nextid);
    }
    return best_id;
}

/* IDCMP flags for windowed mode */
#define OS3_IDCMP_WINDOWED \
    (IDCMP_CLOSEWINDOW   | \
     IDCMP_RAWKEY        | \
     IDCMP_MOUSEBUTTONS  | \
     IDCMP_MOUSEMOVE     | \
     IDCMP_NEWSIZE       | \
     IDCMP_ACTIVEWINDOW  | \
     IDCMP_INACTIVEWINDOW)

/* IDCMP flags for fullscreen mode (no close gadget) */
#define OS3_IDCMP_FULLSCREEN \
    (IDCMP_RAWKEY        | \
     IDCMP_MOUSEBUTTONS  | \
     IDCMP_MOUSEMOVE     | \
     IDCMP_ACTIVEWINDOW  | \
     IDCMP_INACTIVEWINDOW)

/* Window flags for windowed mode */
#define OS3_WFLG_WINDOWED \
    (WFLG_DRAGBAR    | \
     WFLG_DEPTHGADGET| \
     WFLG_CLOSEGADGET| \
     WFLG_ACTIVATE   | \
     WFLG_RMBTRAP    | \
     WFLG_REPORTMOUSE)

/* Window flags for fullscreen mode */
#define OS3_WFLG_FULLSCREEN \
    (WFLG_BORDERLESS | \
     WFLG_ACTIVATE   | \
     WFLG_RMBTRAP    | \
     WFLG_REPORTMOUSE)

/* --- Internal: close window and screen, leaving driverdata allocated --- */
static void OS3_CloseWindowAndScreen(OS3_WindowData *data)
{
    if (data->window) {
        ClearPointer(data->window);
        CloseWindow(data->window);
        data->window = NULL;
    }
    if (data->screen) {
        /* Free CHIP RAM empty pointer if we allocated one (stored in UserData) */
        if (data->screen->UserData) {
            FreeMem(data->screen->UserData, 6 * sizeof(UWORD));
            data->screen->UserData = NULL;
        }
        CloseScreen(data->screen);
        data->screen = NULL;
    }
    data->is_fullscreen = 0;
}

/* --- Internal: open a custom screen + borderless window --- */
static int OS3_OpenScreen(OS3_WindowData *data, int w, int h,
                          ULONG modeid, int depth)
{
    struct Screen *screen;
    struct Window *iwin;

    screen = OpenScreenTags(NULL,
        SA_Title,      (ULONG)"SDL",
        SA_Quiet,      TRUE,
        SA_ShowTitle,  FALSE,
        SA_Depth,      (ULONG)depth,
        SA_DisplayID,  modeid,
        SA_Type,       CUSTOMSCREEN,
        SA_Exclusive,  TRUE,
        SA_Draggable,  FALSE,
        SA_AutoScroll, FALSE,
        TAG_DONE
    );
    if (!screen) {
        return SDL_SetError("OS3: OpenScreenTags failed for %dx%dx%d",
                            w, h, depth);
    }

    iwin = OpenWindowTags(NULL,
        WA_Left,          0,
        WA_Top,           0,
        WA_Width,         (ULONG)screen->Width,
        WA_Height,        (ULONG)screen->Height,
        WA_Flags,         (ULONG)OS3_WFLG_FULLSCREEN,
        WA_IDCMP,         (ULONG)OS3_IDCMP_FULLSCREEN,
        WA_CustomScreen,  (ULONG)screen,
        TAG_DONE
    );
    if (!iwin) {
        CloseScreen(screen);
        return SDL_SetError("OS3: OpenWindowTags failed");
    }

    data->window        = iwin;
    data->screen        = screen;
    data->is_fullscreen = 1;

    /* Hide the Intuition pointer in fullscreen to prevent flicker.
     * Sprite data must be in CHIP RAM (ADCD pitfall). */
    {
        UWORD *empty_ptr = (UWORD *)AllocMem(6 * sizeof(UWORD),
                                              MEMF_CHIP | MEMF_CLEAR);
        if (empty_ptr) {
            SetPointer(iwin, empty_ptr, 1, 1, 0, 0);
            screen->UserData = (APTR)empty_ptr;
        }
    }

    return 0;
}

/* --- Internal: find RTG mode and open fullscreen --- */
static int OS3_OpenFullscreen(OS3_WindowData *data, int w, int h)
{
    ULONG modeid;

    if (!CyberGfxBase) {
        /* AGA path: use BestModeID for native mode selection */
        modeid = BestModeID(
            BIDTAG_NominalWidth,  (ULONG)w,
            BIDTAG_NominalHeight, (ULONG)h,
            BIDTAG_Depth,         8UL,
            TAG_DONE
        );
        if (modeid == INVALID_ID) {
            return SDL_SetError("OS3: no AGA mode found for %dx%d", w, h);
        }
        return OS3_OpenScreen(data, w, h, modeid, 8);
    }

    /* RTG path: BestCModeIDTags for CyberGraphX mode */
    if (w < 640) w = 640;
    if (h < 480) h = 480;

    modeid = BestCModeIDTags(
        CYBRBIDTG_NominalWidth,  w,
        CYBRBIDTG_NominalHeight, h,
        CYBRBIDTG_Depth,         32,
        TAG_DONE
    );
    if (modeid == INVALID_ID) {
        modeid = BestCModeIDTags(
            CYBRBIDTG_NominalWidth,  640,
            CYBRBIDTG_NominalHeight, 480,
            CYBRBIDTG_Depth,         16,
            TAG_DONE
        );
    }
    if (modeid == INVALID_ID) {
        /* P96/SAGA fallback: BestCModeIDTags may fail without
           cybergraphics.library. Walk modes manually. */
        modeid = OS3_FindRTGMode(w, h, 16);
    }
    if (modeid == INVALID_ID) {
        return SDL_SetError("OS3: no suitable RTG fullscreen mode found");
    }

    return OS3_OpenScreen(data, w, h, modeid, 32);
}

/* --- Internal: open a windowed window on WB or custom screen --- */
static int OS3_OpenWindowed(OS3_WindowData *data, SDL_Window *window)
{
    struct Window *iwin;
    int use_wb = 0;
    int xpos, ypos;
    const char *hint;
    int force_wb = 0, force_screen = 0;

    /*
     * SDL_HINT_VIDEO_AMIGAOS3_SCREEN lets the APPLICATION say where its
     * window goes, rather than this driver deciding on its behalf.
     *
     *   "workbench"  -- open on the Workbench public screen, skipping the
     *                   capability sniffing below
     *   "screen"     -- always open our own screen
     *   "auto"/unset -- existing behaviour: Workbench when the probe says
     *                   it is usable, our own screen otherwise
     *
     * The probe is a heuristic and it is demonstrably wrong in at least
     * one real case: on a Picasso96 Workbench it declines a screen that
     * SDL 1.2 windows onto quite happily. A heuristic nobody can override
     * is a policy baked into the driver, so it stays as the DEFAULT and
     * the application gets the last word.
     */
    hint = SDL_GetHint(SDL_HINT_VIDEO_AMIGAOS3_SCREEN);
    if (hint) {
        force_wb     = (SDL_strcasecmp(hint, "workbench") == 0);
        force_screen = (SDL_strcasecmp(hint, "screen") == 0);
    }

    if (force_screen) {
        return OS3_OpenFullscreen(data, window->w, window->h);
    }

    if (!CyberGfxBase) {
        /* AGA: always open a custom fullscreen screen.
         * No windowed mode on AGA (no chunky WB screen to open on).
         * "workbench" cannot be honoured here: there is no blit path for
         * an ARGB surface into a window on a planar screen. */
        return OS3_OpenFullscreen(data, window->w, window->h);
    }

    /* RTG path: check if Workbench is suitable */
    {
        struct Screen *wbscreen = LockPubScreen(NULL);
        if (wbscreen) {
            struct BitMap *bm = wbscreen->RastPort.BitMap;
            ULONG is_cyber = GetCyberMapAttr(bm, CYBRMATTR_ISCYBERGFX);
            /* If GetCyberMapAttr fails (P96 without CGX), check if WB
               screen depth >= 15 as a proxy for RTG */
            if (!is_cyber && GetBitMapAttr(bm, BMA_DEPTH) >= 15) {
                is_cyber = 1;
            }
            if (is_cyber && window->w <= (int)wbscreen->Width &&
                window->h <= (int)wbscreen->Height) {
                use_wb = 1;
            }
            /* Asked for Workbench explicitly: a public screen existing is
             * the only precondition we still insist on. */
            if (force_wb) {
                use_wb = 1;
            }
            UnlockPubScreen(NULL, wbscreen);
        }
    }

    if (use_wb) {
        xpos = (window->x == SDL_WINDOWPOS_CENTERED ||
                window->x == SDL_WINDOWPOS_UNDEFINED) ? 32 : window->x;
        ypos = (window->y == SDL_WINDOWPOS_CENTERED ||
                window->y == SDL_WINDOWPOS_UNDEFINED) ? 32 : window->y;

        iwin = OpenWindowTags(NULL,
            WA_Left,          (ULONG)xpos,
            WA_Top,           (ULONG)ypos,
            WA_InnerWidth,    (ULONG)window->w,
            WA_InnerHeight,   (ULONG)window->h,
            WA_Flags,         (ULONG)OS3_WFLG_WINDOWED,
            WA_IDCMP,         (ULONG)OS3_IDCMP_WINDOWED,
            WA_PubScreen,     (ULONG)NULL,
            WA_GimmeZeroZero, TRUE,
            WA_Title,         (ULONG)(window->title ? window->title : "SDL"),
            TAG_DONE
        );
        if (!iwin) {
            return SDL_SetError("OS3: OpenWindowTags (WB) failed");
        }
        data->window        = iwin;
        data->screen        = NULL;
        data->is_fullscreen = 0;
    } else {
        /* Open our own RTG screen + window.
         * PERF FIX (PDR-015 OpenTTD): use EXACT requested size for the screen
         * instead of +64 padding. The padding caused BestCModeIDTags to pick
         * the next-bigger Picasso96 mode (640+64=704 -> 800x600) which made
         * window->Width != surface->w, forcing UpdateWindowFramebuffer down
         * the BitMapScale path instead of the LockBitMap fast-path memcpy.
         * For OpenTTD this was ~30 ms / frame extra. Real fix is to use the
         * exact size and let the LockBitMap branch fire. */
        ULONG modeid;
        int scrw = window->w;
        int scrh = window->h;

        modeid = BestCModeIDTags(
            CYBRBIDTG_NominalWidth,  scrw,
            CYBRBIDTG_NominalHeight, scrh,
            CYBRBIDTG_Depth,         32,
            TAG_DONE
        );
        if (modeid == INVALID_ID) {
            modeid = BestCModeIDTags(
                CYBRBIDTG_NominalWidth,  640,
                CYBRBIDTG_NominalHeight, 480,
                CYBRBIDTG_Depth,         16,
                TAG_DONE
            );
        }
        if (modeid == INVALID_ID) {
            /* P96/SAGA fallback */
            modeid = OS3_FindRTGMode(scrw, scrh, 16);
        }
        if (modeid == INVALID_ID) {
            return SDL_SetError("OS3: no RTG mode found for windowed");
        }

        return OS3_OpenScreen(data, scrw, scrh, modeid, 32);
    }
    return 0;
}

int OS3_CreateWindow(_THIS, SDL_Window *window)
{
    OS3_WindowData *data;
    int fullscreen;
    int rc;

    data = (OS3_WindowData *)SDL_calloc(1, sizeof(OS3_WindowData));
    if (!data) {
        return SDL_OutOfMemory();
    }

    fullscreen = (window->flags & SDL_WINDOW_FULLSCREEN) ? 1 : 0;

    if (fullscreen) {
        rc = OS3_OpenFullscreen(data, window->w, window->h);
    } else {
        rc = OS3_OpenWindowed(data, window);
    }

    if (rc < 0) {
        SDL_free(data);
        return rc;
    }

    window->driverdata = data;
    return 0;
}

void OS3_SetWindowFullscreen(_THIS, SDL_Window *window,
                             SDL_VideoDisplay *display, SDL_bool fullscreen)
{
    OS3_WindowData *data = (OS3_WindowData *)window->driverdata;
    OS3_DisplayData *disp_data = display ? (OS3_DisplayData *)display->driverdata : NULL;
    struct Window *iwin;

    if (!data || window->is_destroying) {
        return;
    }

    /* Destroy framebuffer -- it will be recreated on next
     * UpdateWindowFramebuffer with the new window's RastPort */
    OS3_DestroyWindowFramebuffer(_this, window);

    /* Close existing window (but NOT the display's fullscreen screen --
     * that's managed by SetDisplayMode) */
    if (data->window) {
        ClearPointer(data->window);
        CloseWindow(data->window);
        data->window = NULL;
    }
    /* Close any screen WE own (from windowed custom screen path) */
    if (data->screen && (!disp_data || data->screen != disp_data->fullscreen_screen)) {
        if (data->screen->UserData) {
            FreeMem(data->screen->UserData, 6 * sizeof(UWORD));
            data->screen->UserData = NULL;
        }
        CloseScreen(data->screen);
    }
    data->screen = NULL;
    data->is_fullscreen = 0;

    if (fullscreen && disp_data && disp_data->fullscreen_screen) {
        /* SetDisplayMode already opened a screen at the right resolution.
         * Open a borderless window filling that screen. */
        struct Screen *screen = disp_data->fullscreen_screen;

        iwin = OpenWindowTags(NULL,
            WA_Left,          0,
            WA_Top,           0,
            WA_Width,         (ULONG)screen->Width,
            WA_Height,        (ULONG)screen->Height,
            WA_Flags,         (ULONG)OS3_WFLG_FULLSCREEN,
            WA_IDCMP,         (ULONG)OS3_IDCMP_FULLSCREEN,
            WA_CustomScreen,  (ULONG)screen,
            TAG_DONE
        );
        if (iwin) {
            UWORD *empty_ptr;
            data->window = iwin;
            data->screen = screen;
            data->is_fullscreen = 1;

            /* Hide pointer in fullscreen (same reason as OS3_OpenFullscreen) */
            empty_ptr = (UWORD *)AllocMem(6 * sizeof(UWORD), MEMF_CHIP | MEMF_CLEAR);
            if (empty_ptr) {
                SetPointer(iwin, empty_ptr, 1, 1, 0, 0);
                screen->UserData = (APTR)empty_ptr;
            }

            /* Do NOT send SDL_WINDOWEVENT_RESIZED to screen size.
             * Keep SDL window at the game's logical size (e.g. 320x200).
             * The framebuffer stays small and ScalePixelArray in
             * UpdateWindowFramebuffer handles upscaling to the
             * actual Intuition window/screen size. */
        } else {
            /* Fallback to windowed */
            OS3_OpenWindowed(data, window);
        }
    } else if (fullscreen) {
        /* No display screen available -- use our own fullscreen */
        OS3_OpenFullscreen(data, window->w, window->h);
    } else {
        /* Leaving fullscreen -- reopen windowed */
        OS3_OpenWindowed(data, window);
    }
}

void OS3_DestroyWindow(_THIS, SDL_Window *window)
{
    OS3_WindowData *data = (OS3_WindowData *)window->driverdata;

    if (!data) {
        return;
    }

    /* Destroy framebuffer surface first */
    OS3_DestroyWindowFramebuffer(_this, window);

    /* Close window before screen -- mandatory order per ADCD */
    OS3_CloseWindowAndScreen(data);

    SDL_free(data);
    window->driverdata = NULL;
}

void OS3_SetWindowTitle(_THIS, SDL_Window *window)
{
    OS3_WindowData *data = (OS3_WindowData *)window->driverdata;

    if (!data || !data->window) {
        return;
    }

    /* SetWindowTitles: NULL means "do not change". Pass ~0 for icon title. */
    SetWindowTitles(data->window,
                    (CONST_STRPTR)(window->title ? window->title : ""),
                    (CONST_STRPTR)~0UL);   /* ~0 = leave icon title unchanged */
}

void OS3_ShowWindow(_THIS, SDL_Window *window)
{
    /* Intuition windows are visible as soon as they are opened.
       Nothing to do for Phase 1. */
    (void)window;
}

void OS3_HideWindow(_THIS, SDL_Window *window)
{
    /* No iconification API in bare Intuition without workbench.library.
       Phase 1: no-op. */
    (void)window;
}

void OS3_RaiseWindow(_THIS, SDL_Window *window)
{
    OS3_WindowData *data = (OS3_WindowData *)window->driverdata;

    if (!data || !data->window) {
        return;
    }

    WindowToFront(data->window);
    ActivateWindow(data->window);
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

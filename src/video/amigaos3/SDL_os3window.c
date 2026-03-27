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

#include "SDL_os3video.h"
#include "SDL_os3window.h"
#include "SDL_os3framebuffer.h"

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

int OS3_CreateWindow(_THIS, SDL_Window *window)
{
    OS3_WindowData *data;
    int fullscreen;

    data = (OS3_WindowData *)SDL_calloc(1, sizeof(OS3_WindowData));
    if (!data) {
        return SDL_OutOfMemory();
    }

    fullscreen = (window->flags & SDL_WINDOW_FULLSCREEN) ? 1 : 0;

    if (fullscreen) {
        /* --- Fullscreen: open a custom CGX screen, then a borderless window --- */
        ULONG modeid;
        int depth;
        struct Screen *screen;
        struct Window *iwin;

        /* Choose depth based on requested pixel format.
           Default to 32-bit if not specified. */
        depth = 32;

        modeid = BestCModeIDTags(
            CYBRBIDTG_NominalWidth,  window->w,
            CYBRBIDTG_NominalHeight, window->h,
            CYBRBIDTG_Depth,         depth,
            TAG_DONE
        );
        if (modeid == INVALID_ID) {
            /* Fall back to any available mode */
            modeid = BestCModeIDTags(
                CYBRBIDTG_NominalWidth,  640,
                CYBRBIDTG_NominalHeight, 480,
                CYBRBIDTG_Depth,         16,
                TAG_DONE
            );
        }
        if (modeid == INVALID_ID) {
            SDL_free(data);
            return SDL_SetError("OS3_CreateWindow: no suitable CGX mode found");
        }

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
            SDL_free(data);
            return SDL_SetError("OS3_CreateWindow: OpenScreenTags failed");
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
            SDL_free(data);
            return SDL_SetError("OS3_CreateWindow: OpenWindowTags (fullscreen) failed");
        }

        data->window      = iwin;
        data->screen      = screen;
        data->is_fullscreen = 1;
    } else {
        /* --- Windowed: try WB screen first (may be RTG), fall back to custom screen --- */
        struct Screen *wbscreen;
        struct Window *iwin;
        int use_wb = 0;
        int xpos, ypos;

        /* Lock the default public screen (Workbench) and check if it's RTG */
        wbscreen = LockPubScreen(NULL);
        if (wbscreen) {
            struct BitMap *bm = wbscreen->RastPort.BitMap;
            if (GetCyberMapAttr(bm, CYBRMATTR_ISCYBERGFX)) {
                use_wb = 1;
            }
            UnlockPubScreen(NULL, wbscreen);
        }

        if (use_wb) {
            /* WB is an RTG screen -- open a window on it */
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
                SDL_free(data);
                return SDL_SetError("OS3_CreateWindow: OpenWindowTags (WB) failed");
            }
            data->window        = iwin;
            data->screen        = NULL;  /* using public screen */
            data->is_fullscreen = 0;
        } else {
            /* WB is AGA -- open our own RTG screen */
            ULONG modeid;
            struct Screen *screen;
            int scrw, scrh;

            scrw = window->w + 64;
        scrh = window->h + 64;
        if (scrw < 640) scrw = 640;
        if (scrh < 480) scrh = 480;

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
            SDL_free(data);
            return SDL_SetError("OS3_CreateWindow: no RTG mode found");
        }

        screen = OpenScreenTags(NULL,
            SA_Title,      (ULONG)(window->title ? window->title : "SDL"),
            SA_ShowTitle,  TRUE,
            SA_Depth,      32UL,
            SA_DisplayID,  modeid,
            SA_Type,       CUSTOMSCREEN,
            SA_Draggable,  TRUE,
            SA_AutoScroll, FALSE,
            TAG_DONE
        );
        if (!screen) {
            SDL_free(data);
            return SDL_SetError("OS3_CreateWindow: OpenScreenTags failed");
        }

        iwin = OpenWindowTags(NULL,
            WA_Left,          0,
            WA_Top,           (ULONG)screen->BarHeight + 1,
            WA_InnerWidth,    (ULONG)window->w,
            WA_InnerHeight,   (ULONG)window->h,
            WA_Flags,         (ULONG)OS3_WFLG_WINDOWED,
            WA_IDCMP,         (ULONG)OS3_IDCMP_WINDOWED,
            WA_CustomScreen,  (ULONG)screen,
            WA_GimmeZeroZero, TRUE,
            WA_Title,         (ULONG)(window->title ? window->title : "SDL"),
            TAG_DONE
        );
        if (!iwin) {
            CloseScreen(screen);
            SDL_free(data);
            return SDL_SetError("OS3_CreateWindow: OpenWindowTags failed");
        }

            data->window      = iwin;
            data->screen      = screen;   /* we own this screen */
            data->is_fullscreen = 0;
        }
    }

    window->driverdata = data;
    return 0;
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
    if (data->window) {
        CloseWindow(data->window);
        data->window = NULL;
    }

    /* Close our custom screen (fullscreen only) */
    if (data->screen) {
        CloseScreen(data->screen);
        data->screen = NULL;
    }

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

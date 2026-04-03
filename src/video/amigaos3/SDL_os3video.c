/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Phase 1: Real CyberGraphX RTG backend with software renderer.

  Library open/close order (CRITICAL -- see cybergraphx-reference.md #9):
    Open:  graphics -> intuition -> cybergraphics
    Close: cybergraphics -> intuition -> graphics
    Window must be closed before screen. Screen before libraries.
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include <proto/dos.h>
#include <graphics/gfxbase.h>  /* ChipRevBits0, GFXF_AA_ALICE/LISA for AGA detection */
#include "SDL_os3video.h"
#include "SDL_os3window.h"
#include "SDL_os3framebuffer.h"
#include "SDL_os3events.h"
#include "SDL_os3mouse.h"
#include "../SDL_sysvideo.h"
#include "../../events/SDL_events_c.h"

/*
 * AmigaOS library bases.
 * IntuitionBase is struct IntuitionBase * (declared by proto/intuition.h).
 * GfxBase is struct GfxBase * (declared by proto/graphics.h).
 * CyberGfxBase is struct Library * (declared by proto/cybergraphics.h).
 * All are defined as NULL here and opened in OS3_VideoInit.
 */
struct Library         *CyberGfxBase  = NULL;
struct IntuitionBase   *IntuitionBase = NULL;
struct GfxBase         *GfxBase       = NULL;

#define OS3VID_DRIVER_NAME "amigaos3"

/* Forward declarations */
static int  OS3_VideoInit(_THIS);
static void OS3_VideoQuit(_THIS);
static void OS3_DeleteDevice(SDL_VideoDevice *device);
static void OS3_GetDisplayModes(_THIS, SDL_VideoDisplay *display);
static int  OS3_SetDisplayMode(_THIS, SDL_VideoDisplay *display,
                               SDL_DisplayMode *mode);

/* Map CyberGraphX depth to SDL pixel format.
   Returns SDL_PIXELFORMAT_UNKNOWN for unsupported depths. */
static Uint32 OS3_DepthToFormat(ULONG depth)
{
    switch (depth) {
    case 15: return SDL_PIXELFORMAT_RGB555;
    case 16: return SDL_PIXELFORMAT_RGB565;
    case 24: return SDL_PIXELFORMAT_RGB24;
    case 32: return SDL_PIXELFORMAT_ARGB8888;
    default: return SDL_PIXELFORMAT_UNKNOWN;
    }
}

static SDL_VideoDevice *OS3_CreateDevice(void)
{
    SDL_VideoDevice *device;

    device = (SDL_VideoDevice *)SDL_calloc(1, sizeof(SDL_VideoDevice));
    if (device == NULL) {
        SDL_OutOfMemory();
        return NULL;
    }

    /* Initialization */
    device->VideoInit    = OS3_VideoInit;
    device->VideoQuit    = OS3_VideoQuit;
    device->free         = OS3_DeleteDevice;

    /* Display */
    device->GetDisplayModes = OS3_GetDisplayModes;
    device->SetDisplayMode  = OS3_SetDisplayMode;

    /* Window */
    device->CreateSDLWindow  = OS3_CreateWindow;
    device->DestroyWindow    = OS3_DestroyWindow;
    device->SetWindowTitle   = OS3_SetWindowTitle;
    device->SetWindowFullscreen = OS3_SetWindowFullscreen;
    device->ShowWindow       = OS3_ShowWindow;
    device->HideWindow       = OS3_HideWindow;
    device->RaiseWindow      = OS3_RaiseWindow;

    /* Framebuffer (software renderer path) */
    device->CreateWindowFramebuffer  = OS3_CreateWindowFramebuffer;
    device->UpdateWindowFramebuffer  = OS3_UpdateWindowFramebuffer;
    device->DestroyWindowFramebuffer = OS3_DestroyWindowFramebuffer;

    /* Disable the texture framebuffer optimization. SDL2 normally tries to
     * create an accelerated texture via SDL_CreateRenderer when
     * SDL_GetWindowSurface is first called (ShouldAttemptTextureFramebuffer).
     * On AmigaOS with only a software renderer, this causes infinite
     * recursion: SDL_CreateRenderer -> SDL_GetWindowSurface ->
     * SDL_CreateWindowTexture -> SDL_CreateRenderer -> crash.
     * Mark as already checked to skip the attempt entirely. */
    device->checked_texture_framebuffer = SDL_TRUE;

    /* Events */
    device->PumpEvents = OS3_PumpEvents;

    return device;
}

VideoBootStrap OS3_bootstrap = {
    OS3VID_DRIVER_NAME, "AmigaOS 3.x CyberGraphX/P96",
    OS3_CreateDevice, NULL /* ShowMessageBox */
};

static int OS3_VideoInit(_THIS)
{
    ULONG nextid;
    SDL_DisplayMode best_mode;
    int found_any;
    struct Process *me;
    APTR oldwin;

    /* Suppress AmigaDOS system requesters ("Please insert volume...")
       during library opens. Without this, a missing cybergraphics.library
       causes an invisible requester that hangs the program.
       See known-pitfalls.md: "AmigaDOS Volume Requester on Path Probing" */
    me = (struct Process *)FindTask(NULL);
    oldwin = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1L;

    /* V40 required for WriteChunkyPixels (AGA c2p path) */
    GfxBase = (struct GfxBase *)
              OpenLibrary((CONST_STRPTR)"graphics.library", 40UL);
    if (!GfxBase) {
        me->pr_WindowPtr = oldwin;
        return SDL_SetError("Cannot open graphics.library V40+");
    }

    IntuitionBase = (struct IntuitionBase *)
                    OpenLibrary((CONST_STRPTR)"intuition.library", 39UL);
    if (!IntuitionBase) {
        CloseLibrary((struct Library *)GfxBase);
        GfxBase = NULL;
        me->pr_WindowPtr = oldwin;
        return SDL_SetError("Cannot open intuition.library V39+");
    }

    /* Try CyberGraphX name first (native CGX or P96 with monitor driver).
       Fall back to Picasso96API.library (P96 without monitor driver,
       common on FS-UAE where uaegfx provides the card but the P96
       monitor driver is not installed). Both provide the same API. */
    CyberGfxBase = OpenLibrary((CONST_STRPTR)CYBERGFXNAME, 40UL);
    if (!CyberGfxBase) {
        CyberGfxBase = OpenLibrary(
            (CONST_STRPTR)"Picasso96API.library", 0UL);
    }

    /* Restore requesters now that library opens are done */
    me->pr_WindowPtr = oldwin;

    SDL_zero(best_mode);
    best_mode.refresh_rate = 60;
    best_mode.driverdata = NULL;

    if (CyberGfxBase) {
        /*
         * RTG path: enumerate CyberGraphX display modes.
         * If the library opened but no modes exist (P96 installed
         * without a graphics card), fall through to AGA.
         */
        best_mode.format = SDL_PIXELFORMAT_ARGB8888;
        best_mode.w = 640;
        best_mode.h = 480;

        found_any = 0;
        nextid = NextDisplayInfo(INVALID_ID);
        while (nextid != INVALID_ID) {
            ULONG is_cyber = IsCyberModeID(nextid);
            /* Also check via DisplayInfo for P96/SAGA modes that
               IsCyberModeID may miss on older P96 versions */
            struct DisplayInfo di;
            ULONG is_rtg = 0;
            if (!is_cyber &&
                GetDisplayInfoData(NULL, (UBYTE *)&di, sizeof(di),
                                   DTAG_DISP, nextid)) {
                /* PropertyFlags bit 12 = DIPF_IS_FOREIGN = RTG mode */
                if (di.PropertyFlags & (1UL << 12))
                    is_rtg = 1;
            }
            if (is_cyber || is_rtg) {
                ULONG w, h, bpp;
                Uint32 fmt;
                if (is_cyber) {
                    w   = GetCyberIDAttr(CYBRIDATTR_WIDTH,  nextid);
                    h   = GetCyberIDAttr(CYBRIDATTR_HEIGHT, nextid);
                    bpp = GetCyberIDAttr(CYBRIDATTR_DEPTH,  nextid);
                } else {
                    struct DimensionInfo dim;
                    w = 0; h = 0; bpp = 0;
                    if (GetDisplayInfoData(NULL, (UBYTE *)&dim,
                            sizeof(dim), DTAG_DIMS, nextid)) {
                        w   = dim.Nominal.MaxX - dim.Nominal.MinX + 1;
                        h   = dim.Nominal.MaxY - dim.Nominal.MinY + 1;
                        bpp = dim.MaxDepth;
                    }
                }
                fmt = OS3_DepthToFormat((int)bpp);

                if (fmt != SDL_PIXELFORMAT_UNKNOWN && (int)bpp >= 16) {
                    if (!found_any) {
                        best_mode.w      = (int)w;
                        best_mode.h      = (int)h;
                        best_mode.format = fmt;
                        found_any = 1;
                    } else if ((int)w == 640 && (int)h == 480) {
                        best_mode.w      = 640;
                        best_mode.h      = 480;
                        best_mode.format = fmt;
                    } else if (best_mode.w != 640 && (int)w < best_mode.w) {
                        best_mode.w      = (int)w;
                        best_mode.h      = (int)h;
                        best_mode.format = fmt;
                    }
                }
            }
            nextid = NextDisplayInfo(nextid);
        }
        if (!found_any) {
            /* P96/CGX library exists but no RTG modes available
             * (no graphics card). Close it and fall through to AGA. */
            SDL_Log("OS3: CGX library found but no RTG modes -- trying AGA");
            CloseLibrary(CyberGfxBase);
            CyberGfxBase = NULL;
        }
    }

    if (!CyberGfxBase) {
        /* No RTG available. Check for AGA chipset (ADCD gfxbase.h:
         * GFXF_AA_ALICE = 4, GFXF_AA_LISA = 8). */
        if (!(GfxBase->ChipRevBits0 & (GFXF_AA_ALICE | GFXF_AA_LISA))) {
            CloseLibrary((struct Library *)IntuitionBase);
            IntuitionBase = NULL;
            CloseLibrary((struct Library *)GfxBase);
            GfxBase = NULL;
            return SDL_SetError("No RTG and not AGA chipset"
                                " -- ECS/OCS not supported");
        }

        SDL_Log("OS3: No RTG found, using AGA native display");

        /* Register a default AGA display mode.
         * PAL low-res: 320x256, 8-bit (256 colors). */
        best_mode.format = SDL_PIXELFORMAT_INDEX8;
        best_mode.w = 320;
        best_mode.h = 256;
    }

    if (SDL_AddBasicVideoDisplay(&best_mode) < 0) {
        if (CyberGfxBase) {
            CloseLibrary(CyberGfxBase);
            CyberGfxBase = NULL;
        }
        CloseLibrary((struct Library *)IntuitionBase);
        IntuitionBase = NULL;
        CloseLibrary((struct Library *)GfxBase);
        GfxBase = NULL;
        return -1;
    }

    OS3_InitMouse();

    return 0;
}

static void OS3_VideoQuit(_THIS)
{
    OS3_QuitMouse();

    /* Libraries -- close in reverse order. Windows and screens must be
       closed already (DestroyWindow is called before VideoQuit). */
    if (CyberGfxBase) {
        CloseLibrary(CyberGfxBase);
        CyberGfxBase = NULL;
    }
    if (IntuitionBase) {
        CloseLibrary((struct Library *)IntuitionBase);
        IntuitionBase = NULL;
    }
    if (GfxBase) {
        CloseLibrary((struct Library *)GfxBase);
        GfxBase = NULL;
    }
}

static void OS3_GetDisplayModes(_THIS, SDL_VideoDisplay *display)
{
    ULONG nextid;

    if (!CyberGfxBase) {
        /* AGA mode: offer common PAL/NTSC resolutions at 8-bit */
        static const struct { int w, h; } aga_modes[] = {
            { 320, 200 }, { 320, 240 }, { 320, 256 },
            { 640, 256 }, { 640, 480 }, { 640, 512 }
        };
        int i;
        for (i = 0; i < (int)(sizeof(aga_modes) / sizeof(aga_modes[0])); i++) {
            SDL_DisplayMode mode;
            SDL_zero(mode);
            mode.format       = SDL_PIXELFORMAT_INDEX8;
            mode.w            = aga_modes[i].w;
            mode.h            = aga_modes[i].h;
            mode.refresh_rate = 50; /* PAL default */
            mode.driverdata   = NULL;
            SDL_AddDisplayMode(display, &mode);
        }
        return;
    }

    nextid = NextDisplayInfo(INVALID_ID);
    while (nextid != INVALID_ID) {
        if (IsCyberModeID(nextid)) {
            ULONG w   = GetCyberIDAttr(CYBRIDATTR_WIDTH,  nextid);
            ULONG h   = GetCyberIDAttr(CYBRIDATTR_HEIGHT, nextid);
            ULONG bpp = GetCyberIDAttr(CYBRIDATTR_DEPTH,  nextid);
            Uint32 fmt = OS3_DepthToFormat((int)bpp);

            if (fmt != SDL_PIXELFORMAT_UNKNOWN) {
                SDL_DisplayMode mode;
                SDL_zero(mode);
                mode.format       = fmt;
                mode.w            = (int)w;
                mode.h            = (int)h;
                mode.refresh_rate = 60;
                mode.driverdata   = NULL;
                SDL_AddDisplayMode(display, &mode);
            }
        }
        nextid = NextDisplayInfo(nextid);
    }
}

static int OS3_SetDisplayMode(_THIS, SDL_VideoDisplay *display,
                              SDL_DisplayMode *mode)
{
    OS3_DisplayData *data = (OS3_DisplayData *)display->driverdata;
    ULONG modeid;
    struct Screen *screen;
    int depth;

    if (!mode) {
        /* NULL mode = restore desktop mode. Close fullscreen screen if any. */
        if (data && data->fullscreen_screen) {
            CloseScreen(data->fullscreen_screen);
            data->fullscreen_screen = NULL;
        }
        return 0;
    }

    /* AGA mode: screen management is handled in OS3_OpenFullscreen.
     * SetDisplayMode is a no-op because we open/close the AGA screen
     * directly in the window lifecycle, not via the display abstraction. */
    if (!CyberGfxBase) {
        return 0;
    }

    /* Close any previous fullscreen screen */
    if (data && data->fullscreen_screen) {
        CloseScreen(data->fullscreen_screen);
        data->fullscreen_screen = NULL;
    }

    depth = SDL_BYTESPERPIXEL(mode->format) * 8;
    if (depth < 16) depth = 16;

    modeid = BestCModeIDTags(
        CYBRBIDTG_NominalWidth,  mode->w,
        CYBRBIDTG_NominalHeight, mode->h,
        CYBRBIDTG_Depth,         depth,
        TAG_DONE
    );
    if (modeid == INVALID_ID) {
        return SDL_SetError("OS3_SetDisplayMode: no matching CGX mode for %dx%dx%d",
                            mode->w, mode->h, depth);
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
        return SDL_SetError("OS3_SetDisplayMode: OpenScreenTags failed");
    }

    if (data) {
        data->fullscreen_screen = screen;
    }

    return 0;
}

static void OS3_DeleteDevice(SDL_VideoDevice *device)
{
    SDL_free(device);
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>

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
#include "SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS4

#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/wb.h>
#include <proto/dos.h>
#include <proto/icon.h>

#include <intuition/imageclass.h>
#include <intuition/gadgetclass.h>
#include <intuition/menuclass.h>

#include <unistd.h>

#include "SDL_os4video.h"
#include "SDL_os4window.h"
#include "SDL_os4modes.h"
#include "SDL_os4opengl.h"
#include "SDL_os4mouse.h"
#include "SDL_os4events.h"
#include "SDL_os4locale.h"

#include "SDL_timer.h"

#include "../../events/SDL_keyboard_c.h"
#include "../../events/SDL_events_c.h"

#include "../../main/amigaos4/SDL_os4debug.h"

#define CATCOMP_NUMBERS
#include "../../amiga-extra/locale_generated.h"

#define MIN_WINDOW_SIZE 100

extern bool (*OS4_ResizeGlContext)(SDL_VideoDevice *_this, SDL_Window * window);
extern void (*OS4_UpdateGlWindowPointer)(SDL_VideoDevice *_this, SDL_Window * window);

static void OS4_CloseSystemWindow(SDL_VideoDevice *_this, struct Window * window);
static void OS4_CloseWindow(SDL_VideoDevice *_this, SDL_Window * sdlwin);

void
OS4_GetWindowSize(struct Window * window, int * width, int * height)
{
    LONG ret = IIntuition->GetWindowAttrs(
        window,
        WA_InnerWidth, width,
        WA_InnerHeight, height,
        TAG_DONE);

    if (ret) {
        dprintf("GetWindowAttrs() returned %ld\n", ret);
    }
}

// TODO: can this be handled asynchronously now?
void
OS4_WaitForResize(SDL_Window * window, int * width, int * height)
{
    SDL_WindowData * data = window->internal;

    int counter = 0;
    int w = 0;
    int h = 0;

    while (counter++ < 100) {
        OS4_GetWindowSize(data->syswin, &w, &h);

        if (w == window->w && h == window->h) {
            break;
        }

        dprintf("Waiting for Intuition %d\n", counter);
        dprintf("System window size (%d * %d), SDL window size (%d * %d)\n",
            w, h, window->w, window->h);
        usleep(1000);
    }

    if (width) {
        *width = w;
    }

    if (height) {
        *height = h;
    }
}

static bool
OS4_IsFullscreen(SDL_Window * window)
{
    return window->flags & SDL_WINDOW_FULLSCREEN;
}

static void
OS4_RemoveAppWindow(SDL_WindowData *data)
{
    if (data->appWin) {
        dprintf("Removing AppWindow\n");

        if (IWorkbench->RemoveAppWindow(data->appWin) == FALSE) {
            dprintf("Failed to remove AppWindow\n");
        }
        data->appWin = NULL;
    }
}

static void
OS4_RemoveAppIcon(SDL_WindowData *data)
{
    if (data->appIcon) {
        dprintf("Removing AppIcon\n");

        if (IWorkbench->RemoveAppIcon(data->appIcon) == FALSE) {
            dprintf("Failed to remove AppIcon\n");
        }
        data->appIcon = NULL;
    }
}

static void
OS4_RemoveMenuObject(SDL_WindowData *data)
{
    if (data->menuObject) {
        if (IIntuition->SetWindowAttrs(data->syswin,
                                       WA_MenuStrip, NULL,
                                       TAG_DONE) != 0) {
            dprintf("Failed to remove menu strip (window %p)\n", data->syswin);
        }

        dprintf("Dispose window menu %p\n", data->menuObject);
        IIntuition->DisposeObject(data->menuObject);
        data->menuObject = NULL;
    }
}

static void
OS4_CreateAppWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_VideoData *videodata = (SDL_VideoData *) _this->internal;
    SDL_WindowData *data = window->internal;

    if (data->appWin) {
        dprintf("AppWindow already exists for window '%s'\n", window->title);
        return;
    }

    // Pass SDL window as user data
    data->appWin = IWorkbench->AddAppWindow(0, (ULONG)window, data->syswin,
        videodata->appMsgPort, TAG_DONE);

    if (!data->appWin) {
        dprintf("Couldn't create AppWindow\n");
    }
}

static bool
OS4_SetupWindowData(SDL_Window * sdlwin, struct Window * syswin)
{
    SDL_WindowData *data;

    if (sdlwin->internal) {
        data = sdlwin->internal;
        dprintf("Old window data %p exists\n", data);
    } else {
        data = (SDL_WindowData *) SDL_calloc(1, sizeof(*data));

        if (!data) {
            return SDL_OutOfMemory();
        }

        sdlwin->internal = data;
    }

    data->sdlwin = sdlwin;
    data->syswin = syswin;
    data->pointerGrabTicks = 0;

    if (data->syswin) {
        int width = 0;
        int height = 0;

        OS4_GetWindowSize(data->syswin, &width, &height);

        dprintf("'%s' dimensions %d*%d\n", sdlwin->title, width, height);

        sdlwin->w = width;
        sdlwin->h = height;
    }

    return true;
}

static uint32
OS4_GetIDCMPFlags(SDL_Window * window, bool fullscreen)
{
    uint32 IDCMPFlags = IDCMP_MOUSEBUTTONS | IDCMP_MOUSEMOVE
                      | IDCMP_DELTAMOVE | IDCMP_RAWKEY | IDCMP_ACTIVEWINDOW
                      | IDCMP_INACTIVEWINDOW | IDCMP_INTUITICKS
                      | IDCMP_EXTENDEDMOUSE;

    dprintf("Called\n");

    if (!fullscreen) {
        if (!(window->flags & SDL_WINDOW_BORDERLESS)) {
            IDCMPFlags |= IDCMP_CLOSEWINDOW | IDCMP_GADGETUP | IDCMP_CHANGEWINDOW | IDCMP_MENUPICK;
        }

        if (window->flags & SDL_WINDOW_RESIZABLE) {
            //IDCMPFlags  |= IDCMP_SIZEVERIFY; no handling so far
            IDCMPFlags |= IDCMP_NEWSIZE;
        }
    }

    return IDCMPFlags;
}

static uint32
OS4_GetWindowFlags(SDL_Window * window, bool fullscreen)
{
    uint32 windowFlags = WFLG_REPORTMOUSE | WFLG_RMBTRAP | WFLG_SMART_REFRESH | WFLG_NOCAREREFRESH;

    dprintf("Called\n");

    if (fullscreen) {
        windowFlags |= WFLG_BORDERLESS | WFLG_BACKDROP;
    } else {
        windowFlags |= WFLG_NEWLOOKMENUS;

        if (window->flags & SDL_WINDOW_BORDERLESS) {
            windowFlags |= WFLG_BORDERLESS;
        } else {
            windowFlags |= WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET;

            if (window->flags & SDL_WINDOW_RESIZABLE) {
                windowFlags |= WFLG_SIZEGADGET | WFLG_SIZEBBOTTOM;
            }
        }
    }

    return windowFlags;
}

static struct Screen *
OS4_GetScreenForWindow(SDL_VideoDevice *_this, SDL_VideoDisplay * display)
{
    if (display) {
        SDL_DisplayData *displaydata = (SDL_DisplayData *) display->internal;

        dprintf("Fullscreen (displaydata %p, screen %p)\n", displaydata, displaydata->screen);
        return displaydata->screen;
    } else {
        SDL_VideoData *videodata = (SDL_VideoData *) _this->internal;

        dprintf("Window mode (public screen)\n");
        return videodata->publicScreen;
    }
}

static ULONG
OS4_BackFill(const struct Hook *hook, struct RastPort *rastport, struct BackFillMessage *message)
{
    struct Rectangle *rect = &message->Bounds;
    struct GraphicsIFace *igfx = hook->h_Data;

    struct RastPort bfRastport;

    igfx->InitRastPort(&bfRastport);
    bfRastport.BitMap = rastport->BitMap;

    igfx->RectFillColor(&bfRastport, rect->MinX, rect->MinY, rect->MaxX, rect->MaxY, 0xFF000000);

    return 0;
}

static struct Hook OS4_BackFillHook = {
    {0, 0},       /* h_MinNode */
    (void *)OS4_BackFill, /* h_Entry */
    0,            /* h_SubEntry */
    0             /* h_Data */
};

static void
OS4_CenterWindow(struct Screen * screen, SDL_Window * window)
{
    if (SDL_WINDOWPOS_ISCENTERED(window->windowed.x) ||
        SDL_WINDOWPOS_ISUNDEFINED(window->windowed.x)) {

        window->x = window->windowed.x = (screen->Width - window->windowed.w) / 2;
        dprintf("X centered %d\n", window->x);
    }

    if (SDL_WINDOWPOS_ISCENTERED(window->windowed.y) ||
        SDL_WINDOWPOS_ISUNDEFINED(window->windowed.y)) {

        window->y = window->windowed.y = (screen->Height - window->windowed.h) / 2;
        dprintf("Y centered %d\n", window->y);
    }
}

static void
OS4_DefineWindowBox(SDL_Window * window, struct Screen * screen, bool fullscreen, SDL_Rect * box)
{
    //dprintf("windowed %d, %d, w %d, h %d\n", window->windowed.x, window->windowed.y, window->windowed.w, window->windowed.h);
    //dprintf("floating %d, %d, w %d, h %d\n", window->floating.x, window->floating.y, window->floating.w, window->floating.h);

    if (screen) {
        if (fullscreen) {
            box->x = 0;
            box->y = 0;
            box->w = screen->Width;
            box->h = screen->Height;
        } else {
            OS4_CenterWindow(screen, window);

            box->x = window->windowed.x;
            box->y = window->windowed.y;
            box->w = window->windowed.w;
            box->h = window->windowed.h;
        }
    } else {
        dprintf("Screen is NULL\n");
        box->x = window->windowed.x;
        box->y = window->windowed.y;
        box->w = window->windowed.w;
        box->h = window->windowed.h;
    }
}

static void
OS4_CreateIconifyGadget(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_VideoData *videodata = (SDL_VideoData *) _this->internal;
    SDL_WindowData *data = window->internal;

    dprintf("Called\n");

    struct DrawInfo *di = IIntuition->GetScreenDrawInfo(videodata->publicScreen);

    if (di) {
        data->image = (struct Image *)IIntuition->NewObject(NULL, SYSICLASS,
            SYSIA_Which, ICONIFYIMAGE,
            SYSIA_DrawInfo, di,
            TAG_DONE);

        if (data->image) {

            dprintf("Image %p for gadget created\n", data->image);

            data->gadget = (struct Gadget *)IIntuition->NewObject(NULL, BUTTONGCLASS,
                GA_Image, data->image,
                GA_ID, GID_ICONIFY,
                GA_TopBorder, TRUE,
                GA_RelRight, TRUE,
                GA_Titlebar, TRUE,
                GA_RelVerify, TRUE,
                TAG_DONE);

            if (data->gadget) {
                struct Window *syswin = data->syswin;

                IIntuition->AddGadget(syswin, data->gadget, -1);

                dprintf("Gadget %p created and added\n", data->gadget);
            } else {
                dprintf("Failed to create button class\n");
            }
        } else {
           dprintf("Failed to create image class\n");
        }

        IIntuition->FreeScreenDrawInfo(videodata->publicScreen, di);

    } else {
        dprintf("Failed to get screen draw info\n");
    }
}

static void
OS4_CreateIconifyGadgetForWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    if (!OS4_IsFullscreen(window) && !(window->flags & SDL_WINDOW_BORDERLESS)) {
        if (window->w > 99 && window->h > 99) {
            OS4_CreateIconifyGadget(_this, window);
        } else {
            dprintf("Don't add gadget for too small window %d*%d (OS4 bug)\n",
                window->w, window->h);
        }
    }
}

static void
OS4_CreateMenu(SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    OS4_RemoveMenuObject(data);

    if (!OS4_IsFullscreen(window)) {
        data->menuObject = IIntuition->NewObject(NULL, "menuclass",
            MA_Type, T_ROOT,
            MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                MA_Type, T_MENU,
                MA_Label, OS4_GetString(MSG_APP_MAIN_MENU),
                MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                    MA_Type, T_ITEM,
                    MA_Label, OS4_GetString(MSG_APP_MAIN_ICONIFY),
                    MA_ID, MID_Iconify,
                    TAG_DONE),
                MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                    MA_Type, T_ITEM,
                    MA_Label, OS4_GetString(MSG_APP_MAIN_LAUNCH_PREFERENCES),
                    MA_ID, MID_LaunchPrefs,
                    TAG_DONE),
                MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                    MA_Type, T_ITEM,
                    MA_Separator, TRUE,
                    TAG_DONE),
                MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                    MA_Type, T_ITEM,
                    MA_Label, OS4_GetString(MSG_APP_MAIN_ABOUT),
                    MA_ID, MID_About,
                    TAG_DONE),
                MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                    MA_Type, T_ITEM,
                    MA_Separator, TRUE,
                    TAG_DONE),
                MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                    MA_Type, T_ITEM,
                    MA_Label, OS4_GetString(MSG_APP_MAIN_QUIT),
                    MA_ID, MID_Quit,
                    TAG_DONE),
                TAG_DONE),
            TAG_DONE);

        if (data->menuObject) {
            dprintf("Menu object %p\n", data->menuObject);
            if (IIntuition->SetWindowAttrs(data->syswin,
                                           WA_MenuStrip, data->menuObject,
                                           TAG_DONE) != 0) {
                dprintf("Failed add menu strip %p\n", data->menuObject);
            }
        } else {
            dprintf("Failed to create menu\n");
        }
    }
}

static int max(int a, int b)
{
    return (a > b) ? a : b;
}

static void
OS4_SetWindowLimits(SDL_Window * window, struct Window * syswin)
{
    const int borderWidth = syswin->BorderLeft + syswin->BorderRight;
    const int borderHeight = syswin->BorderTop + syswin->BorderBottom;

    const int minW = borderWidth + (window->min_w ? max(MIN_WINDOW_SIZE, window->min_w) : MIN_WINDOW_SIZE);
    const int minH = borderHeight + (window->min_h ? max(MIN_WINDOW_SIZE, window->min_h) : MIN_WINDOW_SIZE);

    const int maxW = window->max_w ? (borderWidth + window->max_w) : -1;
    const int maxH = window->max_h ? (borderHeight + window->max_h) : -1;

    dprintf("SDL_Window limits: min_w %d, min_h %d, max_w %d, max_h %d (0 means default)\n",
            window->min_w, window->min_h, window->max_w, window->max_h);

    dprintf("System window limits (with borders): minW %d, minH %d, maxW %d, maxH %d (-1 means no limit)\n",
            minW, minH, maxW, maxH);

    BOOL ret = IIntuition->WindowLimits(syswin, minW, minH, maxW, maxH);

    if (!ret) {
        dprintf("Setting window limits failed\n");
    }
}

static struct Window *
OS4_CreateSystemWindow(SDL_VideoDevice *_this, SDL_Window * window, SDL_VideoDisplay * display)
{
    SDL_VideoData *videodata = (SDL_VideoData *) _this->internal;

    struct Window *syswin;

    const bool fullscreen = display ? true : false;

    const uint32 IDCMPFlags = OS4_GetIDCMPFlags(window, fullscreen);
    const uint32 windowFlags = OS4_GetWindowFlags(window, fullscreen);
    struct Screen *screen = OS4_GetScreenForWindow(_this, display);

    SDL_Rect box;

    OS4_BackFillHook.h_Data = IGraphics; // Smuggle interface ptr for the hook
    OS4_DefineWindowBox(window, screen, fullscreen, &box);

    dprintf("Opening window '%s' at (%d,%d) of size (%dx%d) on screen %p\n",
        window->title, box.x, box.y, box.w, box.h, screen);

    // TODO: consider window.class
    syswin = IIntuition->OpenWindowTags(
        NULL,
        WA_PubScreen, screen,
        WA_Title, (fullscreen || (window->flags & SDL_WINDOW_BORDERLESS)) ? NULL : window->title,
        WA_ScreenTitle, window->title,
        WA_Left, box.x,
        WA_Top, box.y,
        WA_InnerWidth, box.w,
        WA_InnerHeight, box.h,
        WA_Flags, windowFlags,
        WA_IDCMP, IDCMPFlags,
        WA_Hidden, (window->flags & SDL_WINDOW_HIDDEN) ? TRUE : FALSE,
        WA_GrabFocus, (window->flags & SDL_WINDOW_MOUSE_GRABBED) ? POINTER_GRAB_TIMEOUT : 0,
        WA_UserPort, videodata->userPort,
        WA_BackFill, &OS4_BackFillHook,
        TAG_DONE);

    if (syswin) {
        dprintf("Window address %p\n", syswin);

        SDL_PropertiesID props = SDL_GetWindowProperties(window);
        //SDL_SetProperty(props, "SDL.window.amigaos4.screen", screen); TODO: set or not?
        SDL_SetPointerProperty(props, "SDL.window.amigaos4.window", syswin);
    } else {
        dprintf("Couldn't create window\n");
        return NULL;
    }

    if (window->flags & SDL_WINDOW_RESIZABLE && !fullscreen) {
        // If this window is resizable, reset window size limits
        // so that the user can actually resize it.
        OS4_SetWindowLimits(window, syswin);
    }

    return syswin;
}

static void
OS4_CreateControls(SDL_VideoDevice *_this, SDL_Window *window)
{
    OS4_CreateIconifyGadgetForWindow(_this, window);
    OS4_CreateAppWindow(_this, window);
    OS4_CreateMenu(window);
}

bool
OS4_CreateWindow(SDL_VideoDevice *_this, SDL_Window * window, SDL_PropertiesID create_props)
{
    struct Window *syswin = (struct Window *)SDL_GetPointerProperty(create_props, "amigaos4.window",
                                                                    SDL_GetPointerProperty(create_props, "sdl2-compat.external_window", NULL));

    dprintf("amigaos4.window %p\n", syswin);

    if (syswin) {
        window->flags |= SDL_WINDOW_EXTERNAL;

        if (syswin->Title && SDL_strlen(syswin->Title)) {
            window->title = SDL_strdup(syswin->Title);
        }

        if (!OS4_SetupWindowData(window, syswin)) {
            return false;
        }
    } else {
        if (OS4_IsFullscreen(window)) {
            // We may not have the screen opened yet, so let's wait that SDL calls us back with
            // SDL_SetWindowFullscreen() and open the window then.
            dprintf("Open fullscreen window with delay\n");
        } else {
            if (!(syswin = OS4_CreateSystemWindow(_this, window, NULL))) {
                return SDL_SetError("Failed to create system window");
            }
        }

        if (!OS4_SetupWindowData(window, syswin)) {
            // There is no AppWindow in this scenario
            OS4_CloseSystemWindow(_this, syswin);
            return SDL_SetError("Failed to setup window data");
        }

        OS4_CreateControls(_this, window);
    }

    return true;
}

void
OS4_SetWindowTitle(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    //dprintf("Called\n");

    if (data->syswin) {
        STRPTR title = window->title ? window->title : "";

        IIntuition->SetWindowTitles(data->syswin, title, title);
    }
}

void
OS4_SetWindowBox(SDL_VideoDevice *_this, SDL_Window * window, SDL_Rect * rect)
{
    SDL_WindowData *data = window->internal;

    if (data->syswin) {
        const LONG ret = IIntuition->SetWindowAttrs(data->syswin,
            WA_Left, rect->x,
            WA_Top, rect->y,
            WA_InnerWidth, rect->w,
            WA_InnerHeight, rect->h,
            TAG_DONE);

        if (ret) {
            dprintf("SetWindowAttrs() returned %ld\n", ret);
        }

        if (data->glContext) {
            OS4_ResizeGlContext(_this, window);
        }
    }
}

bool
OS4_SetWindowPosition(SDL_VideoDevice *_this, SDL_Window * window)
{
    dprintf("New window position %d, %d\n", window->pending.x, window->pending.y);

    SDL_Rect r;
    r.x = window->pending.x;
    r.y = window->pending.y;
    r.w = window->w;
    r.h = window->h;

    OS4_SetWindowBox(_this, window, &r);

    SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_MOVED,
        window->pending.x,
        window->pending.y);

    return true;
}

void
OS4_SetWindowSize(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    if (data->syswin) {
        int width = 0;
        int height = 0;

        OS4_GetWindowSize(data->syswin, &width, &height);

        if (width != window->pending.w || height != window->pending.h) {
            dprintf("New window size %d*%d\n", window->pending.w, window->pending.h);

            OS4_SetWindowBox(_this, window, &window->pending);

            SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_RESIZED,
                window->pending.w,
                window->pending.h);
        } else {
            dprintf("Ignored size request %d*%d\n", width, height);
        }
    }
}

void
OS4_ShowWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    if (data->appIcon) {
        dprintf("Window '%s' is in iconified (minimized) stated, ignoring show request\n", window->title);
        return;
    }

    if (data->syswin) {
        LONG ret;

        dprintf("Showing window '%s'\n", window->title);

        // TODO: could use ShowWindow but what we pass for the Other?
        ret = IIntuition->SetWindowAttrs(data->syswin,
            WA_Hidden, FALSE,
            TAG_DONE);

        if (ret) {
            dprintf("SetWindowAttrs() returned %ld\n", ret);
        }

        if (OS4_IsFullscreen(window)) {
            IIntuition->ScreenToFront(data->syswin->WScreen);
        }

        IIntuition->ActivateWindow(data->syswin);

        SDL_SetKeyboardFocus(window);

        // If cursor was disabled earlier, make sure also this window gets the news
        OS4_RefreshCursorState();
    }
}

void
OS4_HideWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    if (window->is_destroying) {
        dprintf("Ignore hide request, window '%s' is destroying\n", window->title);
        return;
    }

    if (data->syswin) {
        BOOL result;

        dprintf("Hiding window '%s'\n", window->title);

        // TODO: how to hide a fullscreen window? Close the screen?
        result = IIntuition->HideWindow(data->syswin);

        if (!result) {
            dprintf("HideWindow() failed\n");
        }
    }
}

void
OS4_RaiseWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    if (data->syswin) {
        dprintf("Raising window '%s'\n", window->title);

        IIntuition->WindowToFront(data->syswin);
        IIntuition->ActivateWindow(data->syswin);
    }
}

static void
OS4_CloseSystemWindow(SDL_VideoDevice *_this, struct Window * window)
{
    if (window) {
        dprintf("Closing window '%s' (address %p)\n", window->Title, window);

        struct Screen *screen = window->WScreen;

        IIntuition->CloseWindow(window);

        OS4_CloseScreen(_this, screen);
    } else {
        dprintf("NULL pointer\n");
    }
}

static void
OS4_CloseWindow(SDL_VideoDevice *_this, SDL_Window * sdlwin)
{
    SDL_WindowData *data = sdlwin->internal;

    if (!data) {
        dprintf("data is NULL\n");
        return;
    }

    OS4_RemoveAppWindow(data);
    OS4_RemoveAppIcon(data);
    OS4_RemoveMenuObject(data);

    if (data->syswin) {
        OS4_CloseSystemWindow(_this, data->syswin);
        data->syswin = NULL;

        if (data->gadget) {
            dprintf("Disposing gadget %p\n", data->gadget);
            IIntuition->DisposeObject((Object *)data->gadget);
            data->gadget = NULL;
        }

        if (data->image) {
            dprintf("Disposing gadget image %p\n", data->image);
            IIntuition->DisposeObject((Object *)data->image);
            data->image = NULL;
        }
    } else {
        dprintf("syswin is NULL\n");
    }
}

#ifdef DEBUG
static const char*
OS4_DecodeFullscreenOp(SDL_FullscreenOp fullscreen)
{
    switch(fullscreen) {
        case SDL_FULLSCREEN_OP_LEAVE:
            return "leave fullscreen";
        case SDL_FULLSCREEN_OP_ENTER:
            return "enter fullscreen";
        case SDL_FULLSCREEN_OP_UPDATE:
            return "update";
    }

    return "unknown";
}
#endif

SDL_FullscreenResult
OS4_SetWindowFullscreen(SDL_VideoDevice *_this, SDL_Window * window, SDL_VideoDisplay * display, SDL_FullscreenOp fullscreen)
{
    // TODO: SDL_FULLSCREEN_OP_UPDATE
    if (window->is_destroying) {
        // This function gets also called during window closing
        dprintf("Window '%s' is being destroyed, mode change ignored\n", window->title);
    } else {
        SDL_WindowData *data = window->internal;

        dprintf("'%s': %s (%d), display %p\n", window->title, OS4_DecodeFullscreenOp(fullscreen), fullscreen, display);

        if (window->flags & SDL_WINDOW_EXTERNAL) {
            dprintf("Native window '%s' (%p), mode change ignored\n", window->title, data->syswin);
        } else {
            int oldWidth = 0;
            int oldHeight = 0;

            if (display) {
                SDL_DisplayData *displayData = display->internal;

                // Detect dummy transitions and keep calm

                if (fullscreen == SDL_FULLSCREEN_OP_ENTER) {
                    if (displayData->screen && data->syswin) {
                        dprintf("WScreen %p, screen %p\n", data->syswin->WScreen, displayData->screen);
                        if (data->syswin->WScreen == displayData->screen) {
                            dprintf("Same screen, useless mode change ignored\n");
                            return SDL_FULLSCREEN_SUCCEEDED;
                        }
                    }
                } else {
                    if (!displayData->screen && data->syswin) {
                        dprintf("Same (NULL) screen, useless mode change ignored\n");
                        return SDL_FULLSCREEN_SUCCEEDED;
                    }
                }
            }

            if (data->syswin) {
                dprintf("Reopening window '%s' (%p) due to mode change\n",
                    window->title, data->syswin);

                OS4_GetWindowSize(data->syswin, &oldWidth, &oldHeight);
                OS4_CloseWindow(_this, window);
            } else {
                dprintf("System window doesn't exist yet, let's open it\n");
            }

            if (fullscreen == SDL_FULLSCREEN_OP_LEAVE) {
                SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_LEAVE_FULLSCREEN, 0, 0);
            } else if (fullscreen == SDL_FULLSCREEN_OP_ENTER) {
                SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_ENTER_FULLSCREEN, 0, 0);
            }

            data->syswin = OS4_CreateSystemWindow(_this, window, (fullscreen == SDL_FULLSCREEN_OP_ENTER) ? display : NULL);

            if (data->syswin) {
                OS4_CreateControls(_this, window);

                // Make sure the new window is active
                OS4_ShowWindow(_this, window);

                if ((window->flags & SDL_WINDOW_OPENGL) && data->glContext) {
                    OS4_UpdateGlWindowPointer(_this, window);
                }

                if (oldWidth && oldHeight) {
                    int width, height;

                    OS4_GetWindowSize(data->syswin, &width, &height);

                    if (oldWidth != width || oldHeight != height) {
                        dprintf("Inform SDL about window resize\n");
                        SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_RESIZED,
                            width, height);
                    }
                }

                OS4_ResetNormalKeys();

                if (fullscreen == SDL_FULLSCREEN_OP_ENTER) {
                    if (window->flags & SDL_WINDOW_MAXIMIZED) {
                        data->wasMaximized = TRUE;
                        // testautomation video_getSetWindowState verifies this
                        window->flags &= ~SDL_WINDOW_MAXIMIZED;
                    }
                } else if (fullscreen == SDL_FULLSCREEN_OP_LEAVE) {
                    if (data->wasMaximized) {
                        window->flags |= SDL_WINDOW_MAXIMIZED;
                        data->wasMaximized = FALSE;
                    }
                }
            }
        }
    }

    return SDL_FULLSCREEN_SUCCEEDED;
}

// This may be called from os4events.c
bool
OS4_SetWindowGrabPrivate(SDL_VideoDevice *_this, struct Window * w, bool activate)
{
    if (w) {
        struct IBox grabBox = {
            w->BorderLeft,
            w->BorderTop,
            w->Width  - w->BorderLeft - w->BorderRight,
            w->Height - w->BorderTop  - w->BorderBottom
        };

        LONG ret;

        if (activate) {
            // It seems to be that grabbed window should be active, otherwise some other
            // window (like shell) may be grabbed?
            IIntuition->ActivateWindow(w);

            ret = IIntuition->SetWindowAttrs(w,
                WA_MouseLimits, &grabBox,
                WA_GrabFocus, POINTER_GRAB_TIMEOUT,
                TAG_DONE);
        } else {
            ret = IIntuition->SetWindowAttrs(w,
                WA_MouseLimits, NULL,
                WA_GrabFocus, 0,
                TAG_DONE);
        }

        if (ret) {
            dprintf("SetWindowAttrs() returned %ld\n", ret);
        } else {
            dprintf("Window %p ('%s') input was %s\n",
                w, w->Title, activate ? "grabbed" : "released");
	    return true;
        }
    }

    return false;
}

bool
OS4_SetWindowMouseGrab(SDL_VideoDevice *_this, SDL_Window * window, bool grabbed)
{
    SDL_WindowData *data = window->internal;

    data->pointerGrabTicks = 0;
    return OS4_SetWindowGrabPrivate(_this, data->syswin, grabbed);
}

void
OS4_DestroyWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    dprintf("Called for '%s' (flags 0x%llX)\n", window->title, window->flags);

    if (!data) {
        dprintf("data is NULL\n");
        return;
    }

    if (data->syswin) {
        if (!(window->flags & SDL_WINDOW_EXTERNAL)) {
            OS4_CloseWindow(_this, window);
        } else {
            dprintf("Ignored for native window\n");
        }
    }

    if (window->flags & SDL_WINDOW_OPENGL) {
        OS4_GL_FreeBuffers(_this, data);
    }

    SDL_free(data);
    window->internal = NULL;
}

bool
OS4_SetWindowHitTest(SDL_Window * window, bool enabled)
{
    return true; // just succeed, the real work is done elsewhere
}

static bool
OS4_SetWindowOpacityPrivate(struct Window * window, const UBYTE value)
{
    const LONG ret = IIntuition->SetWindowAttrs(
        window,
        WA_Opaqueness, value,
        TAG_DONE);

    if (ret) {
        dprintf("Failed to set window opaqueness to %u\n", value);
        return false;
    }

    return true;
}

bool
OS4_SetWindowOpacity(SDL_VideoDevice *_this, SDL_Window * window, float opacity)
{
    struct Window *syswin = ((SDL_WindowData *) window->internal)->syswin;

    const UBYTE value = opacity * 255;

    dprintf("Setting window '%s' opaqueness to %u\n", window->title, value);

    return OS4_SetWindowOpacityPrivate(syswin, value);
}

bool
OS4_GetWindowBordersSize(SDL_VideoDevice *_this, SDL_Window * window, int * top, int * left, int * bottom, int * right)
{
    struct Window *syswin = ((SDL_WindowData *) window->internal)->syswin;

    if (top) {
        *top = syswin->BorderTop;
    }

    if (left) {
        *left = syswin->BorderLeft;
    }

    if (bottom) {
        *bottom = syswin->BorderBottom;
    }

    if (right) {
        *right = syswin->BorderRight;
    }

    return true;
}

void
OS4_SetWindowMinMaxSize(SDL_VideoDevice *_this, SDL_Window * window)
{
    if (window->flags & SDL_WINDOW_RESIZABLE) {
        SDL_WindowData *data = window->internal;

        OS4_SetWindowLimits(window, data->syswin);
    } else {
        dprintf("Window is not resizable\n");
    }
}

void
OS4_MaximizeWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    struct Window* syswin = data->syswin;
    struct Screen* screen = syswin->WScreen;

    const int borderWidth = syswin->BorderLeft + syswin->BorderRight;
    const int borderHeight = syswin->BorderTop + syswin->BorderBottom;

    // If there are no user-given limits, use screen dimensions
    const int width = window->max_w ? window->max_w : (screen->Width - borderWidth);
    const int height = window->max_h ? window->max_h : (screen->Height - borderHeight);

    dprintf("Maximizing '%s' to %d*%d\n", window->title, width, height);

    if (window->flags & SDL_WINDOW_MINIMIZED) {
        OS4_UniconifyWindow(_this, window);
    }

    SDL_Rect rect;
    rect.x = window->x;
    rect.y = window->y;
    rect.w = width;
    rect.h = height;

    OS4_SetWindowBox(_this, window, &rect);

    SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_MAXIMIZED, 0, 0);
}

void
OS4_MinimizeWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    dprintf("Minimizing '%s'\n", window->title);

    OS4_IconifyWindow(_this, window);
}

void
OS4_RestoreWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    if (window->flags & SDL_WINDOW_MINIMIZED) {
        dprintf("Restoring iconified '%s'\n", window->title);
        OS4_UniconifyWindow(_this, window);
    } else if (window->flags & SDL_WINDOW_MAXIMIZED) {
        dprintf("Restoring '%s' to x %d, y %d, w %d, h %d\n", window->title,
            window->floating.x, window->floating.y, window->floating.w, window->floating.h);

        OS4_SetWindowBox(_this, window, &window->floating);

        SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_RESTORED, 0, 0);
    } else {
        dprintf("Don't know what to do\n");
    }
}

static struct DiskObject*
OS4_GetDiskObject(SDL_VideoDevice *_this)
{
    SDL_VideoData *videodata = (SDL_VideoData *) _this->internal;
    struct DiskObject *diskObject = NULL;

    if (videodata->appName) {
        BPTR oldDir = IDOS->SetCurrentDir(IDOS->GetProgramDir());
        diskObject = IIcon->GetDiskObject(videodata->appName);
        IDOS->SetCurrentDir(oldDir);
    }

    if (!diskObject) {
        CONST_STRPTR fallbackIconName = "ENVARC:Sys/def_window";

        dprintf("Falling back to '%s'\n", fallbackIconName);
        diskObject = IIcon->GetDiskObjectNew(fallbackIconName);
    }

    return diskObject;
}

void
OS4_IconifyWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_VideoData *videodata = (SDL_VideoData *) _this->internal;

    SDL_WindowData *data = window->internal;

    if (window->flags & SDL_WINDOW_MINIMIZED) {
        dprintf("Window '%s' is already iconified\n", window->title);
    } else {
        struct DiskObject *diskObject = OS4_GetDiskObject(_this);

        if (diskObject) {
            diskObject->do_CurrentX = NO_ICON_POSITION;
            diskObject->do_CurrentY = NO_ICON_POSITION;

            data->appIcon = IWorkbench->AddAppIcon(
                0,
                (ULONG)window,
                videodata->appName,
                videodata->appMsgPort,
                0,
                diskObject,
                TAG_DONE);

            if (!data->appIcon) {
                dprintf("Failed to add AppIcon\n");
            } else {
                dprintf("Iconifying '%s'\n", window->title);

                OS4_HideWindow(_this, window);

                SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_MINIMIZED, 0, 0);
            }

            IIcon->FreeDiskObject(diskObject);
        } else {
            dprintf("Failed to load icon\n");
        }
    }
}

void
OS4_UniconifyWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    SDL_WindowData *data = window->internal;

    if (data->appIcon) {
        dprintf("Restoring '%s'\n", window->title);

        OS4_RemoveAppIcon(data);
        OS4_ShowWindow(_this, window);

        SDL_SendWindowEvent(window, SDL_EVENT_WINDOW_RESTORED, 0, 0);
    } else {
        dprintf("Window '%s' isn't in iconified (minimized) state\n", window->title);
    }
}

static void
OS4_RecreateWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    if (window->flags & SDL_WINDOW_EXTERNAL) {
        dprintf("Cannot modify native window '%s'\n", window->title);
        return;
    }

    SDL_WindowData *data = window->internal;

    if (data->syswin) {
        dprintf("Closing system window '%s' before re-creation\n", window->title);
        OS4_CloseWindow(_this, window);
    }

    data->syswin = OS4_CreateSystemWindow(_this, window, NULL);

    if (data->syswin) {
        OS4_CreateControls(_this, window);

        // Make sure the new window is active
        OS4_ShowWindow(_this, window);

        if ((window->flags & SDL_WINDOW_OPENGL) && data->glContext) {
            OS4_UpdateGlWindowPointer(_this, window);
        }
    } else {
        dprintf("Failed to re-create window '%s'\n", window->title);
    }
}

void
OS4_SetWindowResizable (SDL_VideoDevice *_this, SDL_Window * window, bool resizable)
{
    OS4_RecreateWindow(_this, window);
}

void
OS4_SetWindowBordered(SDL_VideoDevice *_this, SDL_Window * window, bool bordered)
{
    OS4_RecreateWindow(_this, window);
}

void
OS4_SetWindowAlwaysOnTop(SDL_VideoDevice *_this, SDL_Window * window, bool on_top)
{
    SDL_WindowData *data = window->internal;

    if (data->syswin && on_top) {
        // It doesn't seem possible to set WA_StayTop after window creation
        // but let's do what we can.
        IIntuition->WindowToFront(data->syswin);
    }
}

static
void OS4_FlashWindowPrivate(struct Window * window)
{
    // There is no system support to handle flashing but let's improvise
    // something using window opaqueness (requires compositing effects)
    ULONG opacity = 255;

    if (IIntuition->GetWindowAttr(window, WA_Opaqueness, &opacity, sizeof(opacity)) == 0) {
        dprintf("Failed to query original window opacity\n");
        return;
    }

    const Uint32 start = SDL_GetTicks();

    while (TRUE) {
        const Uint32 elapsed = SDL_GetTicks() - start;
        if (elapsed > 200) {
            break;
        }

        const UBYTE value = 128 + 127 * sinf(elapsed * 3.14159f / 50.0f);

        OS4_SetWindowOpacityPrivate(window, value);

        SDL_Delay(1);
    }

    OS4_SetWindowOpacityPrivate(window, opacity);
}

bool
OS4_FlashWindow(SDL_VideoDevice *_this, SDL_Window * window, SDL_FlashOperation operation)
{
    SDL_WindowData *data = window->internal;

    if (data->syswin) {
        switch (operation) {
            case SDL_FLASH_BRIEFLY:
            case SDL_FLASH_UNTIL_FOCUSED:
                OS4_FlashWindowPrivate(data->syswin);
                break;
            case SDL_FLASH_CANCEL:
                break;
        }
    }
    return true;
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS4 */

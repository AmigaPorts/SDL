/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2023 Sam Lantinga <slouken@libsdl.org>

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

#ifndef _SDL_os4window_h
#define _SDL_os4window_h

#include "../SDL_sysvideo.h"

#define POINTER_GRAB_TIMEOUT        20  /* Number of ticks before pointer grab needs to be reactivated */

#define GID_ICONIFY 123

typedef struct HitTestInfo
{
    SDL_HitTestResult htr;
    SDL_Point point;
} HitTestInfo;

struct SDL_WindowData
{
    SDL_Window      * sdlwin;
    struct Window   * syswin;
    struct BitMap   * bitmap;
    struct AppWindow * appWin;
    struct AppIcon  * appIcon;

    Uint32            pointerGrabTicks;

    void*           * glContext;
    struct BitMap   * glFrontBuffer;
    struct BitMap   * glBackBuffer;

    HitTestInfo       hti;

    struct Gadget   * gadget;
    struct Image    * image;

    int               originalX, originalY, originalW, originalH;
};

extern void OS4_GetWindowSize(SDL_VideoDevice *this, struct Window * window, int * width, int * height);
extern void OS4_WaitForResize(SDL_VideoDevice *this, SDL_Window * window, int * width, int * height);

extern int OS4_CreateWindow(SDL_VideoDevice *this, SDL_Window * window);
extern int OS4_CreateWindowFrom(SDL_VideoDevice *this, SDL_Window * window, const void *data);
extern void OS4_SetWindowTitle(SDL_VideoDevice *this, SDL_Window * window);
//extern void OS4_SetWindowIcon(SDL_VideoDevice *this, SDL_Window * window, SDL_Surface * icon);
extern void OS4_SetWindowBox(SDL_VideoDevice *this, SDL_Window * window);
extern int OS4_SetWindowPosition(SDL_VideoDevice *this, SDL_Window * window);
extern void OS4_SetWindowSize(SDL_VideoDevice *this, SDL_Window * window);
extern void OS4_ShowWindow(SDL_VideoDevice *this, SDL_Window * window);
extern void OS4_HideWindow(SDL_VideoDevice *this, SDL_Window * window);
extern void OS4_RaiseWindow(SDL_VideoDevice *this, SDL_Window * window);

extern void OS4_SetWindowMinMaxSize(SDL_VideoDevice *this, SDL_Window * window);

extern void OS4_MaximizeWindow(SDL_VideoDevice *this, SDL_Window * window);
extern void OS4_MinimizeWindow(SDL_VideoDevice *this, SDL_Window * window);
extern void OS4_RestoreWindow(SDL_VideoDevice *this, SDL_Window * window);

extern void OS4_SetWindowResizable(SDL_VideoDevice *this, SDL_Window * window, SDL_bool resizable);
extern void OS4_SetWindowAlwaysOnTop(SDL_VideoDevice *this, SDL_Window * window, SDL_bool on_top);

extern void OS4_SetWindowBordered(SDL_VideoDevice *this, SDL_Window * window, SDL_bool bordered);
extern void OS4_SetWindowFullscreen(SDL_VideoDevice *this, SDL_Window * window, SDL_VideoDisplay * display, SDL_bool fullscreen);
//extern int OS4_SetWindowGammaRamp(SDL_VideoDevice *this, SDL_Window * window, const Uint16 * ramp);
//extern int OS4_GetWindowGammaRamp(SDL_VideoDevice *this, SDL_Window * window, Uint16 * ramp);

extern void OS4_SetWindowGrabPrivate(SDL_VideoDevice *this, struct Window * w, SDL_bool activate);
extern void OS4_SetWindowMouseGrab(SDL_VideoDevice *this, SDL_Window * window, SDL_bool grabbed);
//extern void OS4_SetWindowKeyboardGrab(SDL_VideoDevice *this, SDL_Window * window, SDL_bool grabbed);

extern void OS4_DestroyWindow(SDL_VideoDevice *this, SDL_Window * window);
extern int OS4_GetWindowWMInfo(SDL_VideoDevice *this, SDL_Window * window, struct SDL_SysWMinfo *info);

//extern void OS4_OnWindowEnter(SDL_VideoDevice *this, SDL_Window * window);
extern int OS4_FlashWindow(SDL_VideoDevice *this, SDL_Window * window, SDL_FlashOperation operation);

//extern void OS4_UpdateClipCursor(SDL_Window *window);

extern int OS4_SetWindowHitTest(SDL_Window * window, SDL_bool enabled);

extern int OS4_SetWindowOpacity(SDL_VideoDevice *this, SDL_Window * window, float opacity);
extern int OS4_GetWindowBordersSize(SDL_VideoDevice *this, SDL_Window * window, int * top, int * left, int * bottom, int * right);

extern void OS4_IconifyWindow(SDL_VideoDevice *this, SDL_Window * window);
extern void OS4_UniconifyWindow(SDL_VideoDevice *this, SDL_Window * window);

#endif /* _SDL_os4window_h */

/* vi: set ts=4 sw=4 expandtab: */

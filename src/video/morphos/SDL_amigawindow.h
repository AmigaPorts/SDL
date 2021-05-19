/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2021 Sam Lantinga <slouken@libsdl.org>

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
#include "../../SDL_internal.h"

#ifndef _SDL_amigawindow_h
#define _SDL_amigawindow_h

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

typedef struct
{
	Uint32 kludge1, kludge2, bpr, pixfmt;
	Uint8 buffer[0];
} SDL_Framebuffer;

typedef struct
{
	struct MinNode node;

	struct Region *region;
	SDL_Framebuffer *fb;

	SDL_Window *window;
	struct Window *win;
	struct AppWindow *appmsg;

	// Localized window title, use SDL_free() to deallocate
	char *window_title;

	struct SDL_VideoData *videodata;

	// Currently known window position and dimensions
	LONG curr_x, curr_y, curr_w, curr_h;

	// Flags that must be taken into account at AMIGA_ShowWindow()
	Uint32 sdlflags;

	BYTE grabbed;
	BYTE first_deltamove;
	BYTE winflags;
	
	APTR visualinfo;
	struct Menu *menu;
} SDL_WindowData;

/* Is this window shown (not iconified) */
#define SDL_AMIGA_WINDOW_SHOWN      (1 << 0)
#define SDL_AMIGA_WINDOW_FULLSCREEN (1 << 1)

extern void AMIGA_CloseWindows(_THIS);
extern void AMIGA_OpenWindows(_THIS);


extern int AMIGA_CreateWindow(_THIS, SDL_Window * window);
extern int AMIGA_CreateWindowFrom(_THIS, SDL_Window * window, const void *data);
extern void AMIGA_SetWindowTitle(_THIS, SDL_Window * window);
extern void AMIGA_SetWindowIcon(_THIS, SDL_Window * window, SDL_Surface * icon);
extern void AMIGA_SetWindowPosition(_THIS, SDL_Window * window);
extern void AMIGA_SetWindowMinimumSize(_THIS, SDL_Window * window);
extern void AMIGA_SetWindowMaximumSize(_THIS, SDL_Window * window);
extern void AMIGA_SetWindowSize(_THIS, SDL_Window * window);
extern void AMIGA_ShowWindow(_THIS, SDL_Window * window);
extern void AMIGA_HideWindow(_THIS, SDL_Window * window);
extern void AMIGA_RaiseWindow(_THIS, SDL_Window * window);
extern void AMIGA_MaximizeWindow(_THIS, SDL_Window * window);
extern void AMIGA_MinimizeWindow(_THIS, SDL_Window * window);
extern void AMIGA_RestoreWindow(_THIS, SDL_Window * window);
extern void AMIGA_SetWindowBordered(_THIS, SDL_Window * window, SDL_bool bordered);
extern void AMIGA_SetWindowFullscreen(_THIS, SDL_Window * window, SDL_VideoDisplay * display, SDL_bool fullscreen);
extern int AMIGA_SetWindowGammaRamp(_THIS, SDL_Window * window, const Uint16 * ramp);
extern void AMIGA_SetWindowGrab(_THIS, SDL_Window * window, SDL_bool grabbed);
extern void AMIGA_DestroyWindow(_THIS, SDL_Window * window);
extern SDL_bool AMIGA_GetWindowWMInfo(_THIS, SDL_Window * window, struct SDL_SysWMinfo *info);

extern void AMIGA_ShowWindow_Internal(_THIS, SDL_Window * window);
extern void AMIGA_HideWindow_Internal(_THIS, SDL_Window * window);

extern void AMIGA_SetWindowResizable (_THIS, SDL_Window * window, SDL_bool resizable);

extern int AMIGA_SetWindowOpacity(_THIS, SDL_Window * window, float opacity);
extern int AMIGA_GetWindowBordersSize(_THIS, SDL_Window * window, int * top, int * left, int * bottom, int * right);

#endif /* _SDL_amigawindow_h */

/* vi: set ts=4 sw=4 expandtab: */

/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2020 Sam Lantinga <slouken@libsdl.org>

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

#include "SDL_hints.h"
#include "SDL_syswm.h"
#include "SDL_version.h"
#include "../SDL_sysvideo.h"
#include "../SDL_pixels_c.h"
#include "../../core/morphos/SDL_misc.h"
#include "../../events/SDL_keyboard_c.h"
#include "../../events/SDL_mouse_c.h"

#include "SDL_amigavideo.h"
#include "SDL_amigamodes.h"
#include "SDL_amigamouse.h"
#include "SDL_amigaopengl.h"

#include <sys/param.h>

#include <intuition/extensions.h>
#include <libraries/charsets.h>
#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/gadtools.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/wb.h>

extern struct NewMenu SDL_NewMenu;

static void CloseWindowSafely(SDL_Window *sdlwin, struct Window *win)
{
	D("[%s]\n", __FUNCTION__);

	if (SDL_GetKeyboardFocus() == sdlwin)
		SDL_SetKeyboardFocus(NULL);

	if (SDL_GetMouseFocus() == sdlwin)
		SDL_SetMouseFocus(NULL);

	if ((sdlwin->flags & SDL_WINDOW_FOREIGN) == 0)
	{
		struct IntuiMessage *msg, *tmp;

		Forbid();

		ForeachNodeSafe(&win->UserPort->mp_MsgList, msg, tmp)
		{
			if (msg->IDCMPWindow == win)
			{
				REMOVE(&msg->ExecMessage.mn_Node);
				ReplyMsg(&msg->ExecMessage);
			}
		}

		#if !defined(__MORPHOS__)
		win->UserPort = NULL;
		ModifyIDCMP(win, 0);
		#endif
		
		SDL_WindowData *data = (SDL_WindowData *) sdlwin->driverdata;
		if (data->appmsg) {
			if (RemoveAppWindow(data->appmsg)) {
				data->appmsg = NULL;
			}
		}
		
		ClearMenuStrip(win);
		
		CloseWindow(win);
		if (data->menu) FreeMenus(data->menu);
		if (data->visualinfo) FreeVisualInfo(data->visualinfo);
		data->menu = NULL;
		data->visualinfo = NULL;
		Permit();
	}
}

void
AMIGA_CloseWindows(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	SDL_WindowData *wd;
	D("[%s]\n", __FUNCTION__);

	ForeachNode(&data->windowlist, wd)
	{
		struct Window *win = wd->win;

		if (win)
		{
			wd->win = NULL;
			CloseWindowSafely(wd->window, win);
		}
	}
}

void AMIGA_OpenWindows(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	SDL_WindowData *wd;
	D("[%s]\n", __FUNCTION__);

	ForeachNode(&data->windowlist, wd)
	{
		if (wd->win == NULL && !(wd->window->flags & SDL_WINDOW_FOREIGN) && (wd->winflags & SDL_AMIGA_WINDOW_SHOWN))
		{
			AMIGA_ShowWindow_Internal(_this, wd->window);
		}
	}
}

static int
AMIGA_SetupWindowData(_THIS, SDL_Window *window, struct Window *win)
{
	D("[%s]\n", __FUNCTION__);
	
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	SDL_WindowData *wd = SDL_malloc(sizeof(*wd));
	
	if (wd)
	{
		window->driverdata = wd;
		
		ADDHEAD(&data->windowlist, wd);

		wd->region = NULL;
		wd->fb = NULL;
		wd->window = window;
		wd->win = win;
		wd->grabbed = -1;
		wd->sdlflags = 0;
		wd->window_title = NULL;
		wd->videodata = data;
		wd->first_deltamove = 0;
		wd->winflags = 0;
		wd->appmsg = NULL;

		if (win)
		{
			win->UserData = (APTR)wd;
		}
	}
	else
	{
		return SDL_OutOfMemory();
	}

	return 0;
}

int
AMIGA_CreateWindow(_THIS, SDL_Window * window)
{
	return AMIGA_SetupWindowData(_this, window, NULL);
}

int
AMIGA_CreateWindowFrom(_THIS, SDL_Window * window, const void *data)
{
	struct Window *win = (struct Window *)data;
	size_t flags;

	if (win->Title && win->Title != (APTR)-1)
		window->title = AMIGA_ConvertText(win->Title, MIBENUM_SYSTEM, MIBENUM_UTF_8);

	flags = (window->flags | SDL_WINDOW_SHOWN | SDL_WINDOW_FOREIGN) & ~SDL_WINDOW_MINIMIZED;

	if (win->Flags & WFLG_SIZEGADGET)
		flags |= SDL_WINDOW_RESIZABLE;
	else
		flags &= ~SDL_WINDOW_RESIZABLE;

	if (win->Flags & WFLG_BORDERLESS)
		flags |= SDL_WINDOW_BORDERLESS;
	else
		flags &= ~SDL_WINDOW_BORDERLESS;

	if (win->Flags & WFLG_WINDOWACTIVE)
	{
		flags |= SDL_WINDOW_INPUT_FOCUS;
		SDL_SetKeyboardFocus(window);
	}

	window->flags = flags;

	return AMIGA_SetupWindowData(_this, window, win);
}

void
AMIGA_SetWindowTitle(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	APTR old = data->window_title;
	APTR title = NULL;

	D("[%s] 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		title = AMIGA_ConvertText(window->title, MIBENUM_UTF_8, MIBENUM_SYSTEM);

		D("[AMIGA_SetWindowTitle] %s to %s (0x%08lx)\n", window->title, title, data->win);
		SetWindowTitles(data->win, title, title);
	}

	data->window_title = title;

	SDL_free(old);
}

void
AMIGA_SetWindowIcon(_THIS, SDL_Window * window, SDL_Surface * icon)
{
	//#warning convert this icon to appicon
}

void
AMIGA_SetWindowPosition(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		SDL_VideoData *vd = data->videodata;
		struct Screen *scr = vd->WScreen;
		size_t bh = 0, top = window->y;

		if (vd->CustomScreen == NULL)
			bh = scr->BarHeight + 1;

		top = MAX(bh, top);

		ChangeWindowBox(data->win, window->x, top, data->win->Width, data->win->Height);
	}
}

void
AMIGA_SetWindowMinimumSize(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		SDL_VideoData *vd = data->videodata;
		struct Screen *scr = vd->WScreen;
		size_t bh = 0, min_h = window->min_h, min_w = window->min_w;

		if ((window->flags & SDL_WINDOW_BORDERLESS) == 0)
		{
			min_w += data->win->BorderLeft + data->win->BorderRight;
			min_h += data->win->BorderTop + data->win->BorderBottom;
		}

		if (vd->CustomScreen == NULL)
			bh = scr->BarHeight + 1;

		min_h = MIN(scr->Height - bh, min_h);

		WindowLimits(data->win, min_w, min_h, data->win->MaxWidth, MAX(data->win->MaxHeight, min_h));
	}
}

void
AMIGA_SetWindowMaximumSize(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		SDL_VideoData *vd = data->videodata;
		struct Screen *scr = vd->WScreen;
		size_t bh = 0, max_h = window->max_h, max_w = window->max_w;

		if ((window->flags & SDL_WINDOW_BORDERLESS) == 0)
		{
			max_w += data->win->BorderLeft + data->win->BorderRight;
			max_h += data->win->BorderTop + data->win->BorderBottom;
		}

		if (vd->CustomScreen == NULL)
			bh = scr->BarHeight + 1;

		max_h = MIN(scr->Height - bh, max_h);

		WindowLimits(data->win, data->win->MinWidth, MIN(data->win->MinHeight, max_h), max_w, max_h);
	}
}

void
AMIGA_SetWindowSize(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s]\n", __FUNCTION__);

	if (data->win)
	{
		SDL_VideoData *vd = data->videodata;
		struct Screen *scr = vd->WScreen;
		size_t bh = 0, h = window->h, w = window->w; 

		if ((window->flags & SDL_WINDOW_BORDERLESS) == 0)
		{
			w += data->win->BorderLeft + data->win->BorderRight;
			h += data->win->BorderTop + data->win->BorderBottom;
		}

		if (vd->CustomScreen == NULL)
			bh = scr->BarHeight + 1;

		h = MIN(scr->Height - bh, h);

		ChangeWindowBox(data->win, data->win->LeftEdge, data->win->TopEdge, w, h);
	}
}

static void
AMIGA_UpdateWindowState(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s]\n", __FUNCTION__);

	if (data->win)
	{
		AMIGA_HideWindow(_this, window);
		AMIGA_ShowWindow(_this, window);
	}
}

void
AMIGA_SetWindowBordered(_THIS, SDL_Window * window, SDL_bool bordered)
{
	D("[%s]\n", __FUNCTION__);
	AMIGA_UpdateWindowState(_this, window);
}

static void
AMIGA_WindowToFront(struct Window *win)
{
	D("[%s] wnd 0x%08lx\n", __FUNCTION__, win);
	ActivateWindow(win);
	WindowToFront(win);
}

void
AMIGA_ShowWindow_Internal(_THIS, SDL_Window * window) 
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	SDL_VideoData *vd = data->videodata;
	D("[%s] wnd 0x%08lx, scr 0x%08lx\n", __FUNCTION__, data->win, vd->WScreen);

	if (data->win == NULL && (data->sdlflags & SDL_WINDOW_MINIMIZED) == 0)
	{
		struct Screen *scr;
		size_t flags = WFLG_SIMPLE_REFRESH | WFLG_REPORTMOUSE | WFLG_ACTIVATE;
		size_t w = window->w, h = window->h, max_w = window->max_w, max_h = window->max_h;
		size_t min_w = window->min_w, min_h = window->min_h;
		size_t left = window->x, top = window->y;
		int maxheight, barheight = 0;
		BYTE fullscreen = data->winflags & SDL_AMIGA_WINDOW_FULLSCREEN;

		data->winflags |= SDL_AMIGA_WINDOW_SHOWN;

		D("[%s] initial sizes %ld/%ld and %ld/%ld\n", __FUNCTION__, w, h, max_w, max_h);

		if (vd->WScreen == NULL)
			AMIGA_GetScreen(vd->VideoDevice, vd->FullScreen, (window->flags & SDL_WINDOW_OPENGL) != 0);

		scr = vd->WScreen;

		D("[%s] screen 0x%08lx is %ld/%ld and %ld/%ld\n", __FUNCTION__, scr, scr->Width, scr->Height);

		// Add border sizes
		APTR di = GetScreenDrawInfo(scr);

		if (vd->CustomScreen == NULL)
			barheight = GetSkinInfoAttrA(di, SI_ScreenTitlebarHeight, NULL);

		FreeScreenDrawInfo(scr, di);

		maxheight = scr->Height - barheight;

		// Maximize window
		if (fullscreen)
		{
			w = scr->Width;
			h = maxheight;
			top = left = 0;
		}
		else if (data->sdlflags & SDL_WINDOW_MAXIMIZED)
		{
			int border_w = GetSkinInfoAttrA(di, SI_BorderLeft    , NULL) + GetSkinInfoAttrA(di, SI_BorderRight, NULL);
			int border_h = GetSkinInfoAttrA(di, SI_BorderTopTitle, NULL) + GetSkinInfoAttrA(di, window->flags & SDL_WINDOW_RESIZABLE ? SI_BorderBottomSize : SI_BorderBottom, NULL);

			D("[%s] Border width %ld, border height %ld, bar height %ld\n", __FUNCTION__, border_w, border_h, barheight);

			max_w = MAX(w, max_w) - border_w;
			max_h = MAX(h, max_h) - border_h;
			max_h = MIN(maxheight - border_h, max_h);

			left = 0;
			top = barheight; //MAX(barheight, top);

			w = max_w;
			h = max_h;

			if ((window->flags & SDL_WINDOW_BORDERLESS) == 0)
			{
				//top = barheight;
			}

			D("[%s] maximize to %ld/%ld\n", __FUNCTION__, w, h);
		}
		if (!fullscreen)
		{
			data->visualinfo = GetVisualInfoA(vd->WScreen, NULL);
			if (data->visualinfo) 
			{
				data->menu = CreateMenusA(&SDL_NewMenu, NULL);
				if (data->menu)
				{
					LayoutMenusA(data->menu, data->visualinfo, NULL);
				}
			}
		}

		min_w = MIN(min_w, scr->Width);
		min_h = MIN(min_h, maxheight);
		max_w = MIN(max_w, scr->Width);
		max_h = MIN(max_h, maxheight);
		w = MAX(min_w, w);
		h = MAX(min_h, h);

		if (window->flags & SDL_WINDOW_BORDERLESS || fullscreen)
			flags |= WFLG_BORDERLESS;
		else
			flags |= WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET;

		SDL_bool win_resizable = (window->flags & SDL_WINDOW_RESIZABLE && !fullscreen);
		
		if (win_resizable)
			flags |= WFLG_SIZEGADGET | WFLG_SIZEBBOTTOM;

		if (data->window_title == NULL)
			data->window_title = AMIGA_ConvertText(window->title, MIBENUM_UTF_8, MIBENUM_SYSTEM);

		D("[%s] min %ld/%ld, normal %ld/%ld, max %ld/%ld\n", __FUNCTION__, min_w, min_h, w, h, max_w, max_h);

		data->win = OpenWindowTags(NULL,
			WA_Left, left, WA_Top, top,
			WA_InnerWidth, w,
			WA_InnerHeight, h,
			WA_MinWidth, win_resizable ? 32 : min_w,
			WA_MinHeight, win_resizable ? 32 : min_h,
			WA_MaxWidth, win_resizable ? -1 : max_w,
			WA_MaxHeight, win_resizable ? -1 : max_h,
			WA_Flags, flags,
			vd->CustomScreen ? WA_CustomScreen : TAG_IGNORE, vd->CustomScreen,
			vd->CustomScreen ? TAG_IGNORE : WA_PubScreen, vd->WScreen,
			data->region ? WA_TransparentRegion : TAG_IGNORE, data->region,
			WA_ScreenTitle, data->window_title,
			fullscreen ? TAG_IGNORE : WA_Title, data->window_title,
			WA_UserPort, &vd->WinPort,
			WA_AutoAdjust, TRUE,
			WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_RAWKEY | IDCMP_MOUSEMOVE | IDCMP_DELTAMOVE | IDCMP_MOUSEBUTTONS | IDCMP_REFRESHWINDOW | IDCMP_ACTIVEWINDOW | IDCMP_INACTIVEWINDOW | IDCMP_CHANGEWINDOW | IDCMP_GADGETUP | IDCMP_MENUPICK,
			WA_ExtraTitlebarGadgets, ETG_ICONIFY,
			TAG_DONE);

		if (data->win)
		{
			if (IS_SYSTEM_CURSOR(vd->CurrentPointer))
			{
				size_t pointertags[] = { WA_PointerType, vd->CurrentPointer == NULL ? POINTERTYPE_INVISIBLE : (size_t)vd->CurrentPointer->driverdata, TAG_DONE };
				SetAttrsA(data->win, (struct TagItem *)&pointertags);
			}
			else
			{
				SDL_AmigaCursor *ac = (SDL_AmigaCursor *)vd->CurrentPointer;
				size_t pointertags[] = { POINTERA_BitMap, (size_t)ac->Pointer.bmp, POINTERA_XOffset, ac->Pointer.offx, POINTERA_YOffset, ac->Pointer.offy, TAG_DONE };
				SetWindowPointerA(data->win, (struct TagItem *)&pointertags);
			}

			data->curr_x = data->win->LeftEdge;
			data->curr_y = data->win->TopEdge;
			data->curr_w = data->win->Width;
			data->curr_h = data->win->Height;

			data->first_deltamove = TRUE;

			data->win->UserData = (APTR)data;
			
			if (data->menu)
			{
				SetMenuStrip(data->win, data->menu);
			}
			
			if (!data->appmsg) {
				data->appmsg = AddAppWindow(0, (ULONG)window, data->win, &vd->WBPort, TAG_DONE);
				if (!data->appmsg) {
					D("[%s] ERROR AddAppWindow \n", __FUNCTION__);
				}
			}
			
			if (data->grabbed > 0)
				DoMethod((Object *)data->win, WM_ObtainEvents);
		}
			
	}
	else if (data->win)
	{
		AMIGA_WindowToFront(data->win);
	}
}

void
AMIGA_ShowWindow(_THIS, SDL_Window * window)
{
	D("[%s]\n", __FUNCTION__);

	AMIGA_ShowWindow_Internal(_this, window);
}

void
AMIGA_HideWindow_Internal(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		CloseWindowSafely(window, data->win);
		data->win = NULL;
	}
}

void
AMIGA_HideWindow(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s]\n", __FUNCTION__);

	data->winflags &= ~SDL_AMIGA_WINDOW_SHOWN;
	AMIGA_HideWindow_Internal(_this, window);
}

void
AMIGA_RaiseWindow(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] wnd 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		AMIGA_WindowToFront(data->win);
	}
}

void
AMIGA_MaximizeWindow(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	SDL_VideoData *videodata = (SDL_VideoData *) data->videodata;
	struct Screen *scr = data->win->WScreen;
	ULONG bh = 0;

	D("[%s] wnd 0x%08lx\n", __FUNCTION__, data->win);

	data->sdlflags |=  SDL_WINDOW_MAXIMIZED;
	data->sdlflags &= ~SDL_WINDOW_MINIMIZED;

	if (data->win)
	{
		if (videodata->CustomScreen == NULL)
			bh = scr->BarHeight + 1;

		ChangeWindowBox(data->win, 0, bh, data->win->MaxWidth, data->win->MaxHeight);
	}
}

void
AMIGA_MinimizeWindow(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] wnd 0x%08lx\n", __FUNCTION__, data->win);

	data->sdlflags |=  SDL_WINDOW_MINIMIZED;
	data->sdlflags &= ~SDL_WINDOW_MAXIMIZED;

	AMIGA_HideWindow(_this, window);
}

void
AMIGA_RestoreWindow(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] wnd 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		data->sdlflags &= ~(SDL_WINDOW_MINIMIZED | SDL_WINDOW_MAXIMIZED);

		ChangeWindowBox(data->win, window->x, window->y, window->w, window->h);
		AMIGA_WindowToFront(data->win);
	}
}

void
AMIGA_SetWindowFullscreen(_THIS, SDL_Window * window, SDL_VideoDisplay * _display, SDL_bool fullscreen)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	SDL_VideoData *vd = data->videodata;

	D("[%s]\n", __FUNCTION__);

	if (fullscreen)
		data->winflags |= SDL_AMIGA_WINDOW_FULLSCREEN;
	else
		data->winflags &= ~SDL_AMIGA_WINDOW_FULLSCREEN;

	vd->FullScreen = fullscreen;

	AMIGA_OpenWindows(_this);
	//AMIGA_UpdateWindowState(_this, window);
	AMIGA_GL_ResizeContext(_this, window);
}


int
AMIGA_SetWindowGammaRamp(_THIS, SDL_Window * window, const Uint16 * ramp)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	SDL_VideoData *vd = data->videodata;
	int i;

	for (i = 0; i < 256; i++) {
		vd->gammatable[0][i] = ramp[0*256 + i] >> 8;
		vd->gammatable[1][i] = ramp[1*256 + i] >> 8;
		vd->gammatable[2][i] = ramp[2*256 + i] >> 8;
	}

	if (vd->CustomScreen) {
		SetAttrs(vd->CustomScreen,
			SA_GammaRed,   (IPTR)vd->gammatable[0],
			SA_GammaGreen, (IPTR)vd->gammatable[1],
			SA_GammaBlue,  (IPTR)vd->gammatable[2],
			TAG_DONE);
	}

	return 0;
}

void
AMIGA_SetWindowGrab(_THIS, SDL_Window * window, SDL_bool grabbed)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;

	if (data->win && data->grabbed != (grabbed ? 1 : 0))
	{
		D("[%s] %s\n", __FUNCTION__, grabbed ? "grabbed" : "not grabbed");

		data->grabbed = grabbed ? 1 : 0;

		if (grabbed && (data->win->Flags & WFLG_WINDOWACTIVE) == 0)
			AMIGA_WindowToFront(data->win);

		DoMethod((Object *)data->win, grabbed ? WM_ObtainEvents : WM_ReleaseEvents);
	}
}

void
AMIGA_DestroyWindow(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;

	D("[%s]\n", __FUNCTION__);
	window->driverdata = NULL;

	if (data)
	{
		SDL_VideoData *videodata = (SDL_VideoData *) data->videodata;

		REMOVE(&data->node);

		if (data->win)
			CloseWindowSafely(window, data->win);

		if (data->region)
			DisposeRegion(data->region);

		if (IsListEmpty((struct List *)&videodata->windowlist)) // && videodata->CustomScreen)
		{
			D("[%s] Was last window... get rid of screen.\n", __FUNCTION__);
			AMIGA_CloseDisplay(_this);
			//CloseScreen(videodata->CustomScreen);
			//videodata->CustomScreen = NULL;
		}

		SDL_free(data->window_title);
		SDL_free(data);
	}
}

SDL_bool
AMIGA_GetWindowWMInfo(_THIS, SDL_Window * window, struct SDL_SysWMinfo * info)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;

	if (info->version.major >= SDL_MAJOR_VERSION)
	{
		info->subsystem = SDL_SYSWM_AMIGA;
		info->info.intui.window = data->win;
		return SDL_TRUE;
	} else {
		SDL_SetError("Application not compiled with SDL %d\n", SDL_MAJOR_VERSION);
		return SDL_FALSE;
	}
}

static void AMIGA_CloseWindow(SDL_Window *window) 
{
	
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	D("[%s] 0x%08lx\n", __FUNCTION__, data->win);

	if (data->win)
	{
		if (data->appmsg) {
			if (RemoveAppWindow(data->appmsg)) {
				data->appmsg = NULL;
			}
		}
	
		struct Window *win = data->win;
		CloseWindow(win);
		data->win = NULL;	
	}
}

void
AMIGA_SetWindowResizable(_THIS, SDL_Window * window, SDL_bool resizable)
{
	SDL_WindowData *data = window->driverdata;
	D("[%s] 0x%08lx\n", __FUNCTION__, data->win);
	
    if (window->flags & SDL_WINDOW_FOREIGN) {
        D("[%s] Cannot modify native window '%s'\n", __FUNCTION__, window->title);
        return;
    }

    if (data->win) {
        D("[%s] Closing system window '%s' before re-creation\n", __FUNCTION__, window->title);
        AMIGA_CloseWindow(window);
    }

    AMIGA_ShowWindow_Internal(_this, window);

    if (data->win) {
        // Make sure the new window is active
        AMIGA_ShowWindow(_this, window);
    } else {
        D("[%s] Failed to re-create window '%s'\n", __FUNCTION__, window->title);
    }
}

int
AMIGA_SetWindowOpacity(_THIS, SDL_Window * window, float opacity)
{
    SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
    LONG ret;

    ULONG value = ((opacity) * (ULONG_MAX));

    D("Setting window '%s' opaqueness to %lu\n", window->title, value);

    ret = SetAttrs(
        data->win,
        WA_Opacity, value,
        TAG_DONE);

    if (ret) {
        D("Failed to set window opaqueness to %d\n", value);
        return -1;
    }

    return 0;
}
/* vi: set ts=4 sw=4 expandtab: */

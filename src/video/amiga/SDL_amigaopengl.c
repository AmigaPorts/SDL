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

#if SDL_VIDEO_DRIVER_AMIGA

/* TinyGL implementation of SDL OpenGL support */
/* MorphOS/TinyGL support by LouiSe */

#include "SDL_error.h"
#include "SDL_syswm.h"
#include "../SDL_sysvideo.h"
/*#include "SDL_cgxgl_c.h"
#include "SDL_cgxvideo.h"
#include "mydebug.h"*/
#include "SDL_amigavideo.h"
#include "SDL_amigawindow.h"
#include "../../core/morphos/SDL_library.h"

#include <proto/exec.h>
#include <proto/tinygl.h>
#include <proto/intuition.h>
#include <tgl/gl.h>
#include <tgl/glu.h>

GLContext *__tglContext;
extern void *AmiGetGLProc(const char *proc);
//struct Screen *DefaultScreen;

//extern struct SDL_Library *PowerSDLBase;
extern struct SDL_Library *SDL2Base;

int AMIGA_GL_LoadLibrary(_THIS, const char *path)
{
	D("[%s]\n", __FUNCTION__);

	if (SDL2Base->MyTinyGLBase) {
		if (!TinyGLBase)
			TinyGLBase = OpenLibrary("tinygl.library", 52); // This is opened only once, closed only at final exit

		if (TinyGLBase) {

				*SDL2Base->MyTinyGLBase = TinyGLBase;
				return 0;
		}
	}

	SDL_SetError("Failed to open tinygl.library");
	return -1;
}

void *AMIGA_GL_GetProcAddress(_THIS, const char *proc)
{
	void *func = NULL;

	func = AmiGetGLProc(proc);

	D("[%s] proc %s func 0x%08lx\n", __FUNCTION__, proc, func);

	return func;
}

void AMIGA_GL_UnloadLibrary(_THIS)
{
	D("[%s]\n", __FUNCTION__);

	if (SDL2Base->MyTinyGLBase && *SDL2Base->MyTinyGLBase && TinyGLBase) {
		CloseLibrary(TinyGLBase);
		*SDL2Base->MyTinyGLBase = TinyGLBase = NULL;
	}
}

SDL_GLContext AMIGA_GL_CreateContext(_THIS, SDL_Window * window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	SDL_VideoData *vd = data->videodata;
	BYTE fullscreen = data->winflags & SDL_AMIGA_WINDOW_FULLSCREEN;

	GLContext *glcont = GLInit();

	D("[%s] context 0x%08lx\n", __FUNCTION__, glcont);

	if (glcont) {
		int success;
		struct TagItem tgltags[] =
		{
			{TAG_IGNORE, 0},
			{TGL_CONTEXT_STENCIL, TRUE}, // TODO check if stencil and depth are needed
			{TAG_DONE}
		};

		if (fullscreen) {
			tgltags[0].ti_Tag = TGL_CONTEXT_SCREEN;
			tgltags[0].ti_Data = (IPTR)vd->CustomScreen;
		} else {
			tgltags[0].ti_Tag = TGL_CONTEXT_WINDOW;
			tgltags[0].ti_Data = (IPTR)data->win;
		}

		success = GLAInitializeContext(glcont, tgltags);

		D("[%s] success %d\n", __FUNCTION__, success);

		if (success) {
			*SDL2Base->MyGLContext = __tglContext = glcont;
			return glcont;
		}

		GLClose(glcont);
	} else {
		SDL_SetError("Couldn't create TinyGL/OpenGL context");
	}

	return NULL;
}

int
AMIGA_GL_MakeCurrent(_THIS, SDL_Window * window, SDL_GLContext context)
{
	D("[%s] context 0x%08lx\n", __FUNCTION__, context);

	/*if (window && context)*/ {
		*SDL2Base->MyGLContext = __tglContext = context;
		return 0;
	}

	return -1;
}

void AMIGA_GL_GetDrawableSize(_THIS, SDL_Window * window, int *w, int *h)
{
	//D("[%s]\n", __FUNCTION__);

	if (window) {
		SDL_WindowData * data = window->driverdata;

		if (w) {
			*w = data->win->Width - data->win->BorderLeft - data->win->BorderRight;
			//D("[%s] w %d\n", __FUNCTION__, *w);
		}

		if (h) {
			*h = data->win->Height - data->win->BorderTop - data->win->BorderBottom;
			//D("[%s] h %d\n", __FUNCTION__, *h);
		}
	}
}

int AMIGA_GL_SetSwapInterval(_THIS, int interval)
{
	D("[%s]\n", __FUNCTION__);

	return 0; // pretend to succeed
}

int AMIGA_GL_GetSwapInterval(_THIS)
{
	SDL_VideoData *data = _this->driverdata;

	D("[%s]\n", __FUNCTION__);

	// full screen double buffering is always vsynced
	return data->CustomScreen != NULL ? 1 : 0;
}

int AMIGA_GL_SwapWindow(_THIS, SDL_Window * window)
{
	//D("[%s]\n", __FUNCTION__);
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	if (!data->win)
		return -1;
	// TODO check the window context
	GLASwapBuffers(__tglContext);
	return 0;
}

void
AMIGA_GL_DeleteContext(_THIS, SDL_GLContext context)
{
	D("[%s] context 0x%08lx\n", __FUNCTION__, context);

	if (TinyGLBase == NULL) {
		D("[%s] the library is already closed\n", __FUNCTION__);
		return;
	}

	if (context) {
		GLADestroyContext((GLContext *)context);
		GLClose(context);
	}
}

int AMIGA_GL_ResizeContext(_THIS, SDL_Window *window)
{
	SDL_WindowData *data = (SDL_WindowData *) window->driverdata;
	SDL_VideoData *vd = data->videodata;
	int success;

	D("[%s]\n", __FUNCTION__);

	if (__tglContext == NULL) {
		// only if __tglContext exists
		D("[%s] no OpenGL context\n", __FUNCTION__);
		return -1;
	}

	if (vd->CustomScreen) {
		struct TagItem tgltags[] =
		{
			{TGL_CONTEXT_SCREEN, (IPTR)vd->CustomScreen},
			{TGL_CONTEXT_STENCIL, TRUE}, // TODO check if stencil and depth are needed
			{TAG_DONE}
		};
		GLADestroyContext(__tglContext);
		success = GLAInitializeContext(__tglContext, tgltags);
	} else {
		success = GLAReinitializeContextWindowed(__tglContext, data->win);
	}
	D("[%s] success %d\n", __FUNCTION__, success);

	return success ? 0 : -1;
}

#endif

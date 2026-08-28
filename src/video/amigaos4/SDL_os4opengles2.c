/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

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

#if SDL_VIDEO_OPENGL_ES2

#include <proto/graphics.h>
#include <proto/ogles2.h>
#include <GLES2/gl2.h>

#include "SDL_os4video.h"
#include "SDL_os4window.h"
#include "SDL_os4opengles2.h"
#include "SDL_os4library.h"

#include "../../main/amigaos4/SDL_os4debug.h"

static struct Library *OGLES2base;
struct OGLES2IFace *IOGLES2;

static void
OS4_OGLES2_LogLibraryError()
{
    dprintf("No OpenGL ES 2 library available\n");
    SDL_SetError("No OpenGL ES 2 library available");
}

bool
OS4_OGLES2_LoadLibrary(SDL_VideoDevice *_this, const char * path)
{
    dprintf("Called %d\n", _this->gl_config.driver_loaded);

    if (!OGLES2base) {
        OGLES2base = OS4_OpenLibrary("ogles2.library", 2);
    }

    if (!OGLES2base) {
        dprintf("Failed to open ogles2.library\n");
        return SDL_SetError("Failed to open ogles2.library");
    }

    if (!IOGLES2) {
        IOGLES2 = (struct OGLES2IFace *) OS4_GetInterface(OGLES2base);
    }

    if (!IOGLES2) {
        dprintf("Failed to open OpenGL ES 2 interface\n");
        return SDL_SetError("Failed to open OpenGL ES 2 interface");
    }

    dprintf("OpenGL ES 2 library opened\n");
    return true;
}

SDL_FunctionPointer
OS4_OGLES2_GetProcAddress(SDL_VideoDevice *_this, const char * proc)
{
    void *func = NULL;

    dprintf("Called for '%s'\n", proc);

    if (IOGLES2) {
        func = aglGetProcAddress(proc);
    }

    if (func == NULL) {
        dprintf("Failed to load '%s'\n", proc);
        SDL_SetError("Failed to load function");
    }

    return func;
}

void
OS4_OGLES2_UnloadLibrary(SDL_VideoDevice *_this)
{
    dprintf("Called %d\n", _this->gl_config.driver_loaded);

    OS4_DropInterface((void *) &IOGLES2);
    OS4_CloseLibrary(&OGLES2base);
}

SDL_GLContext
OS4_OGLES2_CreateContext(SDL_VideoDevice *_this, SDL_Window * window)
{
    dprintf("Called\n");

    if (!IOGLES2) {
        OS4_OGLES2_LogLibraryError();
        return NULL;
    }

    ULONG errCode = 0;

    SDL_WindowData *data = window->internal;

    if (data->glContext) {
        dprintf("Old context %p found, deleting\n", data->glContext);

        aglDestroyContext(data->glContext);

        data->glContext = NULL;
    }

    dprintf("Depth buffer size %d, stencil buffer size %d\n",
        _this->gl_config.depth_size, _this->gl_config.stencil_size);

    data->glContext = aglCreateContextTags2(
        &errCode,
        OGLES2_CCT_WINDOW, (ULONG)data->syswin,
        OGLES2_CCT_VSYNC, 0,
        OGLES2_CCT_DEPTH, _this->gl_config.depth_size,
        OGLES2_CCT_STENCIL, _this->gl_config.stencil_size,
        TAG_DONE);

    if (!data->glContext) {
        dprintf("Failed to create OpenGL ES 2 context for window '%s' (error code %lu)\n",
            window->title, errCode);

        SDL_SetError("Failed to create OpenGL ES 2 context");
        return NULL;
    }

    dprintf("OpenGL ES 2 context %p created for window '%s'\n",
        data->glContext, window->title);

    aglMakeCurrent(data->glContext);
    glViewport(0, 0, window->w, window->h);
    return (SDL_GLContext)data->glContext;
}

bool
OS4_OGLES2_MakeCurrent(SDL_VideoDevice *_this, SDL_Window * window, SDL_GLContext context)
{
    if (!window || !context) {
        dprintf("Called (window %p, context %p)\n", window, context);
    }

    if (!IOGLES2) {
        OS4_OGLES2_LogLibraryError();
        return false;
    }

    aglMakeCurrent(context);
    return true;
}

bool
OS4_OGLES2_SwapWindow(SDL_VideoDevice *_this, SDL_Window * window)
{
    //dprintf("Called\n");

    if (!IOGLES2) {
        OS4_OGLES2_LogLibraryError();
        return false;
    }

    SDL_WindowData *data = window->internal;

    if (!data->glContext) {
        dprintf("No OpenGL ES 2 context\n");
        return false;
    }

    SDL_VideoData *videodata = _this->internal;

    glFinish();

    if (videodata->vsyncEnabled) {
        IGraphics->WaitTOF();
    }

    aglSwapBuffers();
    return true;
}

bool
OS4_OGLES2_DestroyContext(SDL_VideoDevice *_this, SDL_GLContext context)
{
    dprintf("Called with context=%p\n", context);

    if (!IOGLES2) {
        OS4_OGLES2_LogLibraryError();
        return false;
    }

    if (!context) {
        dprintf("No context to delete\n");
        return false;
    }

    SDL_Window *sdlwin;
    Uint32 deletions = 0;

    for (sdlwin = _this->windows; sdlwin; sdlwin = sdlwin->next) {
        SDL_WindowData *data = sdlwin->internal;

        if ((SDL_GLContext)data->glContext == context) {
            dprintf("Found OpenGL ES 2 context, clearing window binding\n");

            aglDestroyContext(context);

            data->glContext = NULL;
            deletions++;
        }
    }

    if (deletions == 0) {
        dprintf("OpenGL ES 2 context doesn't seem to have window binding\n");
        return false;
    }

    return true;
}

bool
OS4_OGLES2_ResizeContext(SDL_VideoDevice *_this, SDL_Window * window)
{
    // TODO: remove function?
    return true;
}

void
OS4_OGLES2_UpdateWindowPointer(SDL_VideoDevice *_this, SDL_Window * window)
{
    if (!IOGLES2) {
        OS4_OGLES2_LogLibraryError();
        return;
    }

    SDL_WindowData *data = window->internal;

    dprintf("Updating GLES2 window pointer %p\n", data->syswin);
    aglSetParamsTags2(OGLES2_CCT_WINDOW, (ULONG)data->syswin, TAG_DONE);
}

#endif /* SDL_VIDEO_OPENGL_ES2 */

#endif /* SDL_VIDEO_DRIVER_AMIGAOS4 */

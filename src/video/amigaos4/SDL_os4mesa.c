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
#include "../../SDL_internal.h"

#if defined(SDL_VIDEO_DRIVER_AMIGAOS4) && defined(SDL_VIDEO_OPENGL_MESA)

// NOTE: Mesa needs its own GL headers which conflict with both MiniGL and OGLES2.
// This define is used to reroute preprocessor to correct files.
#define USE_MESA_HEADERS

#include <proto/graphics.h>
#include <proto/mesa.h>

#include "SDL_os4video.h"
#include "SDL_os4window.h"
#include "SDL_os4mesa.h"
#include "SDL_os4library.h"

#include "../../main/amigaos4/SDL_os4debug.h"

static struct Library *Mesabase;
struct MesaIFace *IMesa;

static int
OS4_Mesa_LogLibraryError()
{
    dprintf("No Mesa library available\n");
    return SDL_SetError("No Mesa library available");
}

static SDL_bool
OS4_Mesa_CreateWindowDrawable(_THIS, const SDL_WindowData * data)
{
    dprintf("red_size %d, green_size %d, blue_size %d, alpha_size %d, depth_size %d, stencil_size %d, double_buffer %d\n",
            _this->gl_config.red_size,
            _this->gl_config.green_size,
            _this->gl_config.blue_size,
            _this->gl_config.alpha_size,
            _this->gl_config.depth_size,
            _this->gl_config.stencil_size,
            _this->gl_config.double_buffer);

    // testgles2 default color sizes were 5 bits which failed. Therefore using 0 (default)
    const struct TagItem drawableTags[] = {
        { MESA_DRAWABLE_RED_BITS, 0 /*_this->gl_config.red_size*/ },
        { MESA_DRAWABLE_GREEN_BITS, 0 /*_this->gl_config.green_size*/ },
        { MESA_DRAWABLE_BLUE_BITS, 0 /*_this->gl_config.blue_size*/ },
        { MESA_DRAWABLE_ALPHA_BITS, 0 /*_this->gl_config.alpha_size*/ },
        { MESA_DRAWABLE_DEPTH_BITS, _this->gl_config.depth_size },
        { MESA_DRAWABLE_STENCIL_BITS, _this->gl_config.stencil_size },
        { MESA_DRAWABLE_SAMPLES, 0 }, // TODO: to be checked
        { MESA_DRAWABLE_DOUBLE_BUFFERED, _this->gl_config.double_buffer },
        { TAG_DONE, TAG_DONE }
    };

    const MesaStatus status = IMesa->MesaCreateWindowDrawable(data->syswin, drawableTags, (MesaDrawable *)&data->mesaDrawable);
    if (status != MESA_STATUS_OK) {
        dprintf("MesaCreateWindowDrawable() failed %d\n", status);
        return SDL_FALSE;
    }

    return SDL_TRUE;
}

static void
OS4_Mesa_DestroyDrawable(MesaDrawable* drawable)
{
    if (!drawable || !*drawable) {
        dprintf("MesaDrawable NULL\n");
        return;
    }

    const MesaStatus status = IMesa->MesaDestroyDrawable(*drawable);
    if (status != MESA_STATUS_OK) {
        dprintf("MesaDestroyDrawable() failed %d\n", status);
    }

    *drawable = NULL;
}

static void
OS4_Mesa_UnbindCurrent()
{
    const MesaStatus status = IMesa->MesaUnbindCurrent();
    if (status != MESA_STATUS_OK) {
        dprintf("MesaUnbindContext() failed %d\n", status);
    }
}

int
OS4_Mesa_LoadLibrary(_THIS, const char * path)
{
    dprintf("Called %d\n", _this->gl_config.driver_loaded);

    if (!Mesabase) {
        Mesabase = OS4_OpenLibrary("mesa.library", 1);
    }

    if (!Mesabase) {
        dprintf("Failed to open mesa.library\n");
        return SDL_SetError("Failed to open mesa.library");
    }

    if (!IMesa) {
        IMesa = (struct MesaIFace *) OS4_GetInterface(Mesabase);
    }

    if (!IMesa) {
        dprintf("Failed to open Mesa interface\n");
        return SDL_SetError("Failed to open Mesa interface");
    }

    dprintf("Mesa library opened\n");
    return 0;
}

void*
OS4_Mesa_GetProcAddress(_THIS, const char * proc)
{
    void *func = NULL;

    dprintf("Called for '%s'\n", proc);

    if (IMesa) {
        func = IMesa->MesaGetProcAddress(proc);
    }

    if (func == NULL) {
        dprintf("Failed to load '%s'\n", proc);
        SDL_SetError("Failed to load function");
    }

    return func;
}

void
OS4_Mesa_UnloadLibrary(_THIS)
{
    dprintf("Called %d\n", _this->gl_config.driver_loaded);

    OS4_DropInterface((void *) &IMesa);
    OS4_CloseLibrary(&Mesabase);
}

SDL_GLContext
OS4_Mesa_CreateContext(_THIS, SDL_Window * window)
{
    dprintf("Called\n");

    if (!IMesa) {
        OS4_Mesa_LogLibraryError();
        return NULL;
    }

    SDL_WindowData *data = window->driverdata;

    if (data->glContext) {
        dprintf("Old context %p found, deleting\n", data->glContext);

        OS4_Mesa_UnbindCurrent();

        MesaStatus status = IMesa->MesaDestroyContext((MesaContext)data->glContext);
        if (status != MESA_STATUS_OK) {
            dprintf("MesaDestroyContext() failed %d\n", status);
        }

        data->glContext = NULL;

        OS4_Mesa_DestroyDrawable((MesaDrawable*)&data->mesaDrawable);
    }

    if (!OS4_Mesa_CreateWindowDrawable(_this, data)) {
        return NULL;
    }

    uint32 api = MESA_API_OPENGL;
    uint32 profile = MESA_PROFILE_COMPATIBILITY;

    if (_this->gl_config.profile_mask == SDL_GL_CONTEXT_PROFILE_ES) {
        api = MESA_API_GLES2;
        profile = MESA_PROFILE_ES;
    } else if (_this->gl_config.profile_mask == SDL_GL_CONTEXT_PROFILE_CORE) {
        profile = MESA_PROFILE_CORE;
    }

    dprintf("API %lu, profile %lu\n", api, profile);

    const struct TagItem contextTags[] = {
        { MESA_CONTEXT_API, api },
        { MESA_CONTEXT_PROFILE, profile },
        { MESA_CONTEXT_MAJOR_VERSION, _this->gl_config.major_version },
        { MESA_CONTEXT_MINOR_VERSION, _this->gl_config.minor_version },
        { MESA_CONTEXT_FLAGS, 0 }, // TODO: to be checked
        { TAG_DONE, TAG_DONE }
    };

    MesaStatus status = IMesa->MesaCreateContext(data->mesaDrawable, contextTags, (MesaContext *)&data->glContext);
    if (status != MESA_STATUS_OK) {
        dprintf("MesaCreateContext() failed %d\n", status);
        OS4_Mesa_DestroyDrawable((MesaDrawable*)&data->mesaDrawable);
        return NULL;
    }

    if (!data->glContext) {
        dprintf("Failed to create Mesa context for window '%s'\n", window->title);
        SDL_SetError("Failed to create Mesa context");
        OS4_Mesa_DestroyDrawable((MesaDrawable*)&data->mesaDrawable);
        return NULL;
    }

    dprintf("Mesa context %p created for window '%s'\n",
        data->glContext, window->title);

    status = IMesa->MesaMakeCurrent((MesaContext)data->glContext, data->mesaDrawable, data->mesaDrawable);
    if (status != MESA_STATUS_OK) {
        dprintf("MesaMakeCurrent() failed %d\n", status);
    }

    IMesa->glViewport(0, 0, window->w, window->h);
    return (SDL_GLContext)data->glContext;
}

int
OS4_Mesa_MakeCurrent(_THIS, SDL_Window * window, SDL_GLContext context)
{
    if (!IMesa) {
        return OS4_Mesa_LogLibraryError();
    }

    if (!window) {
        dprintf("Window NULL\n");
        return -1;
    }

    if (!context) {
        dprintf("Context NULL\n");
        OS4_Mesa_UnbindCurrent();
        return -1;
    }

    SDL_WindowData *data = window->driverdata;

    const MesaStatus status = IMesa->MesaMakeCurrent((MesaContext)context, data->mesaDrawable, data->mesaDrawable);
    if (status != MESA_STATUS_OK) {
        dprintf("MesaMakeCurrent() failed %d\n", status);
    }
    return 0;
}

int
OS4_Mesa_SwapWindow(_THIS, SDL_Window * window)
{
    //dprintf("Called\n");

    if (!IMesa) {
        return OS4_Mesa_LogLibraryError();
    }

    SDL_WindowData *data = window->driverdata;

    if (!data->glContext) {
        dprintf("No Mesa context\n");
        return -1;
    }

    SDL_VideoData *videodata = _this->driverdata;

    IMesa->glFinish();

    if (videodata->vsyncEnabled) {
        IGraphics->WaitTOF();
    }

    const MesaStatus status = IMesa->MesaSwapBuffers(data->mesaDrawable);
    if (status != MESA_STATUS_OK) {
        dprintf("MesaSwapBuffers() failed %d\n", status);
        return SDL_FALSE;
    }

    return 0;
}

void
OS4_Mesa_DeleteContext(_THIS, SDL_GLContext context)
{
    dprintf("Called with context=%p\n", context);

    if (!IMesa) {
        OS4_Mesa_LogLibraryError();
        return;
    }

    if (!context) {
        dprintf("No context to delete\n");
        return;
    }

    SDL_Window *sdlwin;
    Uint32 deletions = 0;

    OS4_Mesa_UnbindCurrent();

    for (sdlwin = _this->windows; sdlwin; sdlwin = sdlwin->next) {
        SDL_WindowData *data = sdlwin->driverdata;

        if ((SDL_GLContext)data->glContext == context) {
            dprintf("Found Mesa context, clearing window binding\n");

            const MesaStatus status = IMesa->MesaDestroyContext((MesaContext)context);
            if (status != MESA_STATUS_OK) {
                dprintf("MesaDestroyContext() failed %d\n", status);
            }

            data->glContext = NULL;

            OS4_Mesa_DestroyDrawable((MesaDrawable *)&data->mesaDrawable);

            deletions++;
        }
    }

    if (deletions == 0) {
        dprintf("Mesa context doesn't seem to have window binding\n");
    }
}

void
OS4_Mesa_UpdateWindowPointer(_THIS, SDL_Window * window)
{
    if (!IMesa) {
        OS4_Mesa_LogLibraryError();
        return;
    }

    SDL_WindowData *data = window->driverdata;

    dprintf("Updating Mesa window pointer %p\n", data->syswin);

    OS4_Mesa_UnbindCurrent();
    OS4_Mesa_DestroyDrawable((MesaDrawable *)&data->mesaDrawable);

    if (!OS4_Mesa_CreateWindowDrawable(_this, data)) {
        return;
    }

    const MesaStatus status = IMesa->MesaMakeCurrent(data->glContext, data->mesaDrawable, data->mesaDrawable);
    if (!status != MESA_STATUS_OK) {
        dprintf("MesaMakeCurrent() failed %d\n", status);
        return;
    }
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS4 && SDL_VIDEO_OPENGL_MESA */

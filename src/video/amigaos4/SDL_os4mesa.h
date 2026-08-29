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

#ifndef SDL_os4mesa_h_
#define SDL_os4mesa_h_

extern bool OS4_Mesa_LoadLibrary(SDL_VideoDevice *_this, const char *path);
extern SDL_FunctionPointer OS4_Mesa_GetProcAddress(SDL_VideoDevice *_this, const char *proc);
extern void OS4_Mesa_UnloadLibrary(SDL_VideoDevice *_this);
extern SDL_GLContext OS4_Mesa_CreateContext(SDL_VideoDevice *_this, SDL_Window * window);
extern bool OS4_Mesa_MakeCurrent(SDL_VideoDevice *_this, SDL_Window * window, SDL_GLContext context);
extern bool OS4_Mesa_SwapWindow(SDL_VideoDevice *_this, SDL_Window * window);
extern bool OS4_Mesa_DestroyContext(SDL_VideoDevice *_this, SDL_GLContext context);

extern void OS4_Mesa_UpdateWindowPointer(SDL_VideoDevice *_this, SDL_Window * window);

#endif /* SDL_os4mesa_h_ */

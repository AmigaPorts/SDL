/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Window management function declarations.
*/

#ifndef SDL_os3window_h_
#define SDL_os3window_h_

#include "../SDL_sysvideo.h"

extern int  OS3_CreateWindow(_THIS, SDL_Window *window);
extern void OS3_DestroyWindow(_THIS, SDL_Window *window);
extern void OS3_SetWindowTitle(_THIS, SDL_Window *window);
extern void OS3_ShowWindow(_THIS, SDL_Window *window);
extern void OS3_HideWindow(_THIS, SDL_Window *window);
extern void OS3_RaiseWindow(_THIS, SDL_Window *window);

#endif /* SDL_os3window_h_ */

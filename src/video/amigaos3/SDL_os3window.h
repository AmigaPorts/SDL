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
extern void OS3_SetWindowFullscreen(_THIS, SDL_Window *window,
                                    SDL_VideoDisplay *display, SDL_bool fullscreen);
extern void OS3_ShowWindow(_THIS, SDL_Window *window);
extern void OS3_HideWindow(_THIS, SDL_Window *window);
extern void OS3_RaiseWindow(_THIS, SDL_Window *window);

/* RTG mode fallback: walk display database manually when BestCModeIDTags fails */
extern ULONG OS3_FindRTGMode(int want_w, int want_h, int want_depth);

#endif /* SDL_os3window_h_ */

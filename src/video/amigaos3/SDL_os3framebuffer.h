/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Framebuffer function declarations.
*/

#ifndef SDL_os3framebuffer_h_
#define SDL_os3framebuffer_h_

#include "../SDL_sysvideo.h"

extern int  OS3_CreateWindowFramebuffer(_THIS, SDL_Window *window,
                                        Uint32 *format, void **pixels,
                                        int *pitch);
extern int  OS3_UpdateWindowFramebuffer(_THIS, SDL_Window *window,
                                        const SDL_Rect *rects, int numrects);
extern void OS3_DestroyWindowFramebuffer(_THIS, SDL_Window *window);

#endif /* SDL_os3framebuffer_h_ */

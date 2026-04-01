/*
  SDL2 Video Driver -- AmigaOS 3.x AGA (non-RTG) helpers.
  Palette management and future c2p optimization entry point.
*/

#ifndef SDL_os3aga_h_
#define SDL_os3aga_h_

#include "../../SDL_internal.h"
#include "SDL_pixels.h"        /* SDL_Palette, SDL_Color */
#include <intuition/screens.h>

/* Convert SDL_Palette to LoadRGB32 format and apply to AGA screen.
 * LoadRGB32 table format (ADCD graphics.library/LoadRGB32):
 *   ULONG[0] = (count << 16) | start_index
 *   ULONG[1..count*3] = R, G, B triplets (32-bit left-justified)
 *   ULONG[count*3+1] = 0 (terminator)
 */
void OS3_AGA_SetPalette(struct Screen *screen, SDL_Palette *pal);

#endif /* SDL_os3aga_h_ */

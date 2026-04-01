/*
  SDL2 Video Driver -- AmigaOS 3.x AGA (non-RTG) helpers.
  Palette management and Kalms c2p (chunky-to-planar) conversion.
*/

#ifndef SDL_os3aga_h_
#define SDL_os3aga_h_

#include "../../SDL_internal.h"
#include "SDL_pixels.h"        /* SDL_Palette, SDL_Color */
#include <intuition/screens.h>
#include <graphics/gfx.h>      /* struct BitMap */

/* Convert SDL_Palette to LoadRGB32 format and apply to AGA screen. */
void OS3_AGA_SetPalette(struct Screen *screen, SDL_Palette *pal);

/* Chunky-to-planar conversion: write 8-bit chunky pixels to an AGA
 * screen's bitplanes. Uses Kalms c2p assembly (public domain, 68020+).
 *
 * chunky: source 8-bit pixel buffer (width * height bytes)
 * screen: target AGA screen (writes to screen's BitMap planes)
 * width:  pixel width (must match c2p init, must be multiple of 32)
 * height: pixel height
 */
void OS3_AGA_C2P(const void *chunky, struct Screen *screen,
                 int width, int height);

/* Initialize c2p for a given screen geometry. Call once after opening
 * the AGA screen, before the first OS3_AGA_C2P call. */
void OS3_AGA_C2PInit(int width, int height);

#endif /* SDL_os3aga_h_ */

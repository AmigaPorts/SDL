/*
  SDL2 Video Driver -- AmigaOS 3.x AGA (non-RTG) helpers.
  Palette management via LoadRGB32.
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include "SDL_os3aga.h"
#include "SDL_os3video.h"

#include <proto/graphics.h>

void OS3_AGA_SetPalette(struct Screen *screen, SDL_Palette *pal)
{
    /* LoadRGB32 table: header + 256 RGB triplets + terminator = 771 ULONGs.
     * 3076 bytes exceeds the 512-byte stack budget, so use static. */
    static ULONG table[256 * 3 + 2];
    int i, ncolors;

    if (!screen || !pal) {
        return;
    }

    ncolors = pal->ncolors;
    if (ncolors > 256) {
        ncolors = 256;
    }

    /* Header: count in upper 16 bits, start index in lower 16 bits */
    table[0] = ((ULONG)ncolors << 16) | 0;

    for (i = 0; i < ncolors; i++) {
        /* LoadRGB32 wants 32-bit left-justified: 0xRR000000 */
        table[1 + i * 3 + 0] = (ULONG)pal->colors[i].r << 24;
        table[1 + i * 3 + 1] = (ULONG)pal->colors[i].g << 24;
        table[1 + i * 3 + 2] = (ULONG)pal->colors[i].b << 24;
    }

    /* Terminator */
    table[1 + ncolors * 3] = 0;

    LoadRGB32(&screen->ViewPort, table);
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

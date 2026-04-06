/*
  SDL2 Video Driver -- AmigaOS 3.x AGA (non-RTG) helpers.
  Palette management via LoadRGB32.
  Chunky-to-planar via Kalms c2p assembly (public domain, 68020+).
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include "SDL_os3aga.h"
#include "SDL_os3video.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/graphics.h>
#ifdef WARPUP
#pragma pop
#endif

#ifndef WARPUP
/* Kalms c2p assembly functions (c2p1x1_8_c5_gen.s, assembled by vasm).
 * Register constraints match the asm: d0, d1, d3 for init; a0, a1 for convert.
 * bebbo-gcc supports __asm register constraints for 68k. */
extern void c2p1x1_8_c5_gen_init(
    int chunkyx __asm("d0"),
    int chunkyy __asm("d1"),
    int scroffsy __asm("d3"));
extern void c2p1x1_8_c5_gen(
    void *c2pscreen __asm("a0"),
    void *bitplanes __asm("a1"));
#endif

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

void OS3_AGA_C2PInit(int width, int height)
{
#ifndef WARPUP
    c2p1x1_8_c5_gen_init(width, height, 0);
#endif
}

void OS3_AGA_C2P(const void *chunky, struct Screen *screen,
                 int width, int height)
{
    struct BitMap *bm;

    (void)width;
    (void)height;

    if (!screen) {
        return;
    }

    bm = screen->RastPort.BitMap;
    if (!bm || !bm->Planes[0]) {
        return;
    }

#ifndef WARPUP
    /* Kalms c2p expects contiguous bitplanes with BPLSIZE spacing.
     * Standard AGA screen bitmaps from OpenScreen have this layout. */
    c2p1x1_8_c5_gen((void *)chunky, (void *)bm->Planes[0]);
#endif
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

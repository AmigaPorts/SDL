/*
  Framebuffer: SDL_Surface <-> screen via CyberGraphX (RTG) or AGA (planar).

  RTG path: ARGB8888 surface -> WritePixelArray or LockBitMapTags.
  AGA path: INDEX8 surface -> WriteChunkyPixels (system c2p) + LoadRGB32 palette.

  Scaling strategy (RTG only): WritePixelArray to temp BitMap, BitMapScale to stretch.

  VRAM pixel format: FS-UAE uaegfx reports PIXFMT_BGRA32 (12).
  LockBitMap memcpy must convert ARGB->BGRA inline (bswap32 per pixel).
*/

#include "../../SDL_internal.h"
#include "SDL_os3video.h"
#include "SDL_os3aga.h"

#include <proto/graphics.h>

/* CyberGraphX headers only needed when RTG is available (compile always,
 * guarded at runtime by CyberGfxBase != NULL) */
#include <proto/cybergraphics.h>
#include <cybergraphx/cybergraphics.h>

/* Key strings for SDL_SetWindowData / SDL_GetWindowData */
#define OS3_SURFACE_KEY  "OS3_Surface"
#define OS3_SCALEBM_KEY  "OS3_ScaleBM"
#define OS3_SCALERP_KEY  "OS3_ScaleRP"

/* Bytes per pixel for ARGB8888 */
#define OS3_BPP 4

/* Forward declaration (defined later in this file) */
void OS3_DestroyWindowFramebuffer(_THIS, SDL_Window *window);

/* Inline ARGB->BGRA memcpy for LockBitMap VRAM writes.
 * Combines the copy and byte-swap in one pass -- 3x faster than
 * separate ConvertARGB_to_BGRA + memcpy + ConvertBGRA_to_ARGB. */
static void MemcpyARGB_to_BGRA(Uint32 *dst, const Uint32 *src, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        Uint32 p = src[i];
        dst[i] = ((p & 0x000000FFu) << 24)
                | ((p & 0x0000FF00u) << 8)
                | ((p & 0x00FF0000u) >> 8)
                | ((p & 0xFF000000u) >> 24);
    }
}

int OS3_CreateWindowFramebuffer(_THIS, SDL_Window *window,
                                Uint32 *format, void **pixels,
                                int *pitch)
{
    SDL_Surface *surface;
    int w, h;

    if (!window) {
        return SDL_SetError("OS3_CreateWindowFramebuffer: no window");
    }

    /* Destroy any previous framebuffer */
    OS3_DestroyWindowFramebuffer(_this, window);

    SDL_GetWindowSizeInPixels(window, &w, &h);

    if (!CyberGfxBase) {
        /* AGA path: 8-bit paletted surface.
         * Games blitting 8-bit surfaces get a fast memcpy. */
        surface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 8,
                                                SDL_PIXELFORMAT_INDEX8);
        if (!surface) {
            return -1;
        }
        SDL_SetWindowData(window, OS3_SURFACE_KEY, surface);
        *format = SDL_PIXELFORMAT_INDEX8;
        *pixels = surface->pixels;
        *pitch  = surface->pitch;
        return 0;
    }

    /* RTG path: 32-bit ARGB surface */
    surface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32,
                                            SDL_PIXELFORMAT_ARGB8888);
    if (!surface) {
        return -1;
    }

    SDL_SetWindowData(window, OS3_SURFACE_KEY, surface);

    /* Pre-allocate scaling resources if window > surface */
    {
        OS3_WindowData *data = (OS3_WindowData *)window->driverdata;
        int win_w = data->window->Width;
        int win_h = data->window->Height;
        if (win_w > w || win_h > h) {
            struct BitMap *friend_bm = data->window->RPort->BitMap;
            struct BitMap *scale_bm = AllocBitMap(w, h,
                GetCyberMapAttr(friend_bm, CYBRMATTR_DEPTH),
                BMF_MINPLANES, friend_bm);

            if (scale_bm) {
                struct RastPort *scale_rp;
                SDL_SetWindowData(window, OS3_SCALEBM_KEY, scale_bm);

                scale_rp = (struct RastPort *)SDL_calloc(1, sizeof(struct RastPort));
                if (scale_rp) {
                    InitRastPort(scale_rp);
                    scale_rp->BitMap = scale_bm;
                    SDL_SetWindowData(window, OS3_SCALERP_KEY, scale_rp);
                }
            }
        }
    }

    *format = SDL_PIXELFORMAT_ARGB8888;
    *pixels = surface->pixels;
    *pitch  = surface->pitch;

    return 0;
}

int OS3_UpdateWindowFramebuffer(_THIS, SDL_Window *window,
                                const SDL_Rect *rects, int numrects)
{
    OS3_WindowData *data = (OS3_WindowData *)window->driverdata;
    SDL_Surface    *surface;
    int             i;

    if (!data || !data->window) {
        return SDL_SetError("OS3_UpdateWindowFramebuffer: no window data");
    }

    surface = (SDL_Surface *)SDL_GetWindowData(window, OS3_SURFACE_KEY);
    if (!surface) {
        return SDL_SetError("OS3_UpdateWindowFramebuffer: no framebuffer surface");
    }

    /* --- AGA path: WriteChunkyPixels + LoadRGB32 palette --- */
    if (!CyberGfxBase) {
        /* Get palette from the window surface SDL2 exposes to the game.
         * Our internal surface (OS3_SURFACE_KEY) and SDL_GetWindowSurface
         * may return different surface objects with different palettes. */
        SDL_Surface *win_surf = SDL_GetWindowSurface(window);
        SDL_Palette *pal = NULL;

        if (win_surf && win_surf->format) {
            pal = win_surf->format->palette;
        }
        if (!pal && surface->format) {
            pal = surface->format->palette;
        }

        if (pal) {
            OS3_AGA_SetPalette(data->screen, pal);
        }

        /* WriteChunkyPixels: inclusive xstop/ystop (ADCD) */
        WriteChunkyPixels(
            &data->screen->RastPort,
            0, 0,
            (LONG)(surface->w - 1),
            (LONG)(surface->h - 1),
            (UBYTE *)surface->pixels,
            (LONG)surface->pitch
        );

        {
            static int path_logged = 0;
            if (!path_logged) {
                SDL_Log("OS3_FB: AGA path active (WriteChunkyPixels %dx%d)",
                        surface->w, surface->h);
                path_logged = 1;
            }
        }

        return 0;
    }

    /* --- RTG path --- */
    {
        int win_w = data->window->Width;
        int win_h = data->window->Height;
        int need_scale = (win_w > surface->w || win_h > surface->h);

        if (need_scale) {
            struct RastPort *scale_rp =
                (struct RastPort *)SDL_GetWindowData(window, OS3_SCALERP_KEY);
            struct BitMap *scale_bm =
                (struct BitMap *)SDL_GetWindowData(window, OS3_SCALEBM_KEY);

            if (scale_rp && scale_bm) {
                struct BitScaleArgs bsa;

                /* WritePixelArray handles ARGB->native conversion internally */
                WritePixelArray(
                    (APTR)surface->pixels,
                    0, 0,
                    (UWORD)surface->pitch,
                    scale_rp,
                    0, 0,
                    (UWORD)surface->w,
                    (UWORD)surface->h,
                    RECTFMT_ARGB
                );

                SDL_memset(&bsa, 0, sizeof(bsa));
                bsa.bsa_SrcBitMap  = scale_bm;
                bsa.bsa_SrcX       = 0;
                bsa.bsa_SrcY       = 0;
                bsa.bsa_SrcWidth   = surface->w;
                bsa.bsa_SrcHeight  = surface->h;
                bsa.bsa_XSrcFactor = surface->w;
                bsa.bsa_YSrcFactor = surface->h;
                bsa.bsa_XDestFactor = win_w;
                bsa.bsa_YDestFactor = win_h;
                bsa.bsa_DestBitMap = data->window->RPort->BitMap;
                bsa.bsa_DestX      = 0;
                bsa.bsa_DestY      = 0;

                BitMapScale(&bsa);
            } else {
                /* Fallback: blit without scaling */
                WritePixelArray(
                    (APTR)surface->pixels,
                    0, 0,
                    (UWORD)surface->pitch,
                    data->window->RPort,
                    0, 0,
                    (UWORD)surface->w,
                    (UWORD)surface->h,
                    RECTFMT_ARGB
                );
            }
        } else {
            /* No scaling needed.
             * Try LockBitMapTags for direct VRAM write (fast path),
             * fall back to WritePixelArray if lock fails. */
            struct BitMap *win_bm = data->window->RPort->BitMap;
            int used_lock = 0;

            if (GetCyberMapAttr(win_bm, CYBRMATTR_ISCYBERGFX)) {
                ULONG bm_base = 0, bm_pitch = 0;
                ULONG bm_pixfmt = 0, bm_bppix = 0;
                APTR lock;

                lock = LockBitMapTags(win_bm,
                    LBMI_BASEADDRESS, (ULONG)&bm_base,
                    LBMI_BYTESPERROW, (ULONG)&bm_pitch,
                    LBMI_PIXFMT,      (ULONG)&bm_pixfmt,
                    LBMI_BYTESPERPIX, (ULONG)&bm_bppix,
                    TAG_DONE);

                if (lock && bm_base && bm_bppix == OS3_BPP) {
                    UBYTE *fb = (UBYTE *)bm_base;
                    int needs_swap = (bm_pixfmt != 11); /* 11 = PIXFMT_ARGB32 */

                    for (i = 0; i < numrects; i++) {
                        const SDL_Rect *r = &rects[i];
                        const Uint32 *src_row;
                        Uint32 *dst_row;
                        int row;

                        if (r->w <= 0 || r->h <= 0) {
                            continue;
                        }

                        src_row = (const Uint32 *)((const Uint8 *)surface->pixels
                                  + (r->y * surface->pitch)
                                  + (r->x * OS3_BPP));
                        dst_row = (Uint32 *)(fb
                                  + (r->y * bm_pitch)
                                  + (r->x * bm_bppix));

                        if (needs_swap) {
                            /* VRAM is BGRA32 or other non-ARGB format:
                             * inline bswap32 during copy (one pass) */
                            for (row = 0; row < r->h; row++) {
                                MemcpyARGB_to_BGRA(dst_row, src_row, r->w);
                                src_row = (const Uint32 *)((const Uint8 *)src_row + surface->pitch);
                                dst_row = (Uint32 *)((Uint8 *)dst_row + bm_pitch);
                            }
                        } else {
                            /* VRAM is ARGB32: straight memcpy */
                            for (row = 0; row < r->h; row++) {
                                SDL_memcpy(dst_row, src_row, r->w * OS3_BPP);
                                src_row = (const Uint32 *)((const Uint8 *)src_row + surface->pitch);
                                dst_row = (Uint32 *)((Uint8 *)dst_row + bm_pitch);
                            }
                        }
                    }
                    used_lock = 1;
                }

                if (lock) {
                    UnLockBitMap(lock);
                }
            }

            {
                static int path_logged = 0;
                if (!path_logged) {
                    if (used_lock) {
                        SDL_Log("OS3_FB: LockBitMap FAST path active (direct VRAM)");
                    } else {
                        SDL_Log("OS3_FB: WritePixelArray path (lock failed or not CGX)");
                    }
                    path_logged = 1;
                }
            }

            if (!used_lock) {
                /* Fallback: WritePixelArray with format conversion */
                for (i = 0; i < numrects; i++) {
                    const SDL_Rect *r = &rects[i];
                    UBYTE *src;

                    if (r->w <= 0 || r->h <= 0) {
                        continue;
                    }

                    src = (UBYTE *)surface->pixels
                          + (r->y * surface->pitch)
                          + (r->x * OS3_BPP);

                    WritePixelArray(
                        (APTR)src,
                        0, 0,
                        (UWORD)surface->pitch,
                        data->window->RPort,
                        (UWORD)r->x,
                        (UWORD)r->y,
                        (UWORD)r->w,
                        (UWORD)r->h,
                        RECTFMT_ARGB
                    );
                }
            }
        }
    }

    return 0;
}

void OS3_DestroyWindowFramebuffer(_THIS, SDL_Window *window)
{
    SDL_Surface *surface;
    struct RastPort *scale_rp;
    struct BitMap *scale_bm;

    surface = (SDL_Surface *)SDL_SetWindowData(window, OS3_SURFACE_KEY, NULL);
    if (surface) {
        SDL_FreeSurface(surface);
    }

    scale_rp = (struct RastPort *)SDL_SetWindowData(window, OS3_SCALERP_KEY, NULL);
    if (scale_rp) {
        SDL_free(scale_rp);
    }

    scale_bm = (struct BitMap *)SDL_SetWindowData(window, OS3_SCALEBM_KEY, NULL);
    if (scale_bm) {
        FreeBitMap(scale_bm);
    }
}

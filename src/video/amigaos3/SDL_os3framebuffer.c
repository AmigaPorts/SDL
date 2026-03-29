/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Framebuffer: SDL_Surface <-> Intuition RastPort via WritePixelArray.

  Pixel format: SDL_PIXELFORMAT_ARGB8888 <-> RECTFMT_ARGB.
  WritePixelArray handles ARGB->screen format conversion correctly.

  Scaling strategy: WritePixelArray to a temp CGX BitMap (handles format
  conversion), then BltBitMapRastPort to stretch to the window.
  ScalePixelArray is avoided -- P96/uaegfx has color/banding bugs with it.

  Reference: cybergraphx-reference.md -- WritePixelArray section
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include "SDL_os3video.h"
#include "SDL_os3framebuffer.h"
#include <graphics/scale.h>

/* Key used to store the framebuffer SDL_Surface in SDL's window data map */
#define OS3_SURFACE_KEY "_SDL_OS3Surface"

/* Keys for scaling resources */
#define OS3_SCALEBM_KEY  "_SDL_OS3ScaleBM"
#define OS3_SCALERP_KEY  "_SDL_OS3ScaleRP"

/* Bytes per pixel for ARGB8888 */
#define OS3_BPP 4

int OS3_CreateWindowFramebuffer(_THIS, SDL_Window *window,
                                Uint32 *format, void **pixels, int *pitch)
{
    OS3_WindowData *data = (OS3_WindowData *)window->driverdata;
    SDL_Surface    *surface;
    int             w, h;

    if (!data || !data->window) {
        return SDL_SetError("OS3_CreateWindowFramebuffer: no window data");
    }

    /* Destroy any previous framebuffer */
    OS3_DestroyWindowFramebuffer(_this, window);

    SDL_GetWindowSizeInPixels(window, &w, &h);

    surface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32,
                                            SDL_PIXELFORMAT_ARGB8888);
    if (!surface) {
        return -1;
    }

    SDL_SetWindowData(window, OS3_SURFACE_KEY, surface);

    /* Pre-allocate scaling resources if window > surface */
    {
        int win_w = data->window->Width;
        int win_h = data->window->Height;
        if (win_w > w || win_h > h) {
            /* Allocate a friend BitMap at the surface size.
             * This is a CGX bitmap matching the screen's pixel format,
             * so WritePixelArray can convert ARGB -> native format,
             * and BltBitMapRastPort can then scale it. */
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

                /* Step 1: WritePixelArray converts ARGB surface -> native
                 * format in the temp bitmap. This conversion is correct. */
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

                /* Step 2: BitMapScale stretches the temp bitmap to the
                 * window's RastPort. Works on native CGX bitmaps. */
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
            /* No scaling needed -- blit dirty rects directly.
             * WritePixelArray handles ARGB->screen conversion correctly. */
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

    return 0;
}

void OS3_DestroyWindowFramebuffer(_THIS, SDL_Window *window)
{
    SDL_Surface *surface;
    struct RastPort *scale_rp;
    struct BitMap *scale_bm;

    surface = (SDL_Surface *)SDL_SetWindowData(window, OS3_SURFACE_KEY, NULL);
    SDL_FreeSurface(surface);

    scale_rp = (struct RastPort *)SDL_SetWindowData(window, OS3_SCALERP_KEY, NULL);
    SDL_free(scale_rp);

    scale_bm = (struct BitMap *)SDL_SetWindowData(window, OS3_SCALEBM_KEY, NULL);
    if (scale_bm) {
        FreeBitMap(scale_bm);
    }
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Framebuffer: SDL_Surface <-> Intuition RastPort via WritePixelArray.

  Pixel format: SDL_PIXELFORMAT_ARGB8888 <-> RECTFMT_ARGB.
  This avoids any color conversion on ARGB32 RTG boards (the most common).

  Reference: cybergraphx-reference.md -- WritePixelArray section
             Pitfall #7: alignment must be LONG (4-byte) aligned.
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include "SDL_os3video.h"
#include "SDL_os3framebuffer.h"

/* Key used to store the framebuffer SDL_Surface in SDL's window data map */
#define OS3_SURFACE_KEY "_SDL_OS3Surface"

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

    /* ARGB8888 matches RECTFMT_ARGB -- no conversion needed on ARGB32 boards */
    surface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32,
                                            SDL_PIXELFORMAT_ARGB8888);
    if (!surface) {
        return -1;
    }

    /* Store it in the window data map */
    SDL_SetWindowData(window, OS3_SURFACE_KEY, surface);

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

    /*
     * Blit each dirty rectangle to the RastPort.
     *
     * WritePixelArray parameters:
     *   srcRect  -- pointer into SDL surface pixel buffer at (rect.x, rect.y)
     *   srcX     -- 0 (we already offset the pointer)
     *   srcY     -- 0
     *   srcMod   -- surface->pitch (bytes per row of the full surface)
     *   rastPort -- window->RPort  (WA_GimmeZeroZero makes (0,0) = inner area)
     *   destX    -- rect.x
     *   destY    -- rect.y
     *   sizeX    -- rect.w
     *   sizeY    -- rect.h
     *   srcFormat-- RECTFMT_ARGB (matches SDL_PIXELFORMAT_ARGB8888)
     */
    /* Check if we need to scale: window (Intuition) is larger than
     * framebuffer (SDL surface). This happens when a game opens a
     * 320x200 window on a 640x480 custom screen. */
    {
        int win_w = data->window->Width;
        int win_h = data->window->Height;
        int need_scale = (win_w > surface->w || win_h > surface->h);

        if (need_scale) {
            /* Scale the entire framebuffer to fill the window.
             * ScalePixelArray (CGX V41) does hardware-assisted scaling. */
            ScalePixelArray(
                (APTR)surface->pixels,
                (UWORD)surface->w,
                (UWORD)surface->h,
                (UWORD)surface->pitch,
                data->window->RPort,
                0,
                0,
                (UWORD)win_w,
                (UWORD)win_h,
                RECTFMT_ARGB
            );
        } else {
            /* No scaling needed -- blit dirty rects directly */
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
                    0,
                    0,
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

    surface = (SDL_Surface *)SDL_SetWindowData(window, OS3_SURFACE_KEY, NULL);
    SDL_FreeSurface(surface);
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

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

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/graphics.h>
#include <proto/dos.h>

/* CyberGraphX headers only needed when RTG is available (compile always,
 * guarded at runtime by CyberGfxBase != NULL) */
#include <proto/cybergraphics.h>
#include <cybergraphx/cybergraphics.h>
#ifdef WARPUP
#pragma pop
#endif

#ifdef SDL_OS3_PROFILE
/* Self-contained profiling for the framebuffer path. Uses ReadEClock for
 * sub-microsecond timing. Writes results to WORK:OpenTTD-SDL2/sdl2-perf.log
 * (or wherever, hardcoded path is fine for one-off perf debug) via direct
 * AmigaDOS Open/Write/Close to bypass libnix stdio buffering.
 *
 * Captures: LockBitMapTags time, memcpy/bswap loop time, UnLockBitMap time,
 * needs_swap value, bm_pixfmt, fast-path-vs-fallback selection, call count.
 */
#include <devices/timer.h>
#include <proto/exec.h>
#include <proto/timer.h>

static struct timerequest *sdl2_prof_io = NULL;
static struct Device *sdl2_prof_TimerBase = NULL;
static ULONG sdl2_prof_freq = 0;

static struct {
    ULONG total_lock_ticks;
    ULONG total_memcpy_ticks;
    ULONG total_unlock_ticks;
    ULONG total_wpa_ticks;
    ULONG call_count;
    ULONG fast_path_count;
    ULONG fallback_count;
    ULONG bm_pixfmt;
    ULONG bm_bppix;
    int   needs_swap;
} sdl2_prof = {0};

static void sdl2_prof_init(void)
{
    struct EClockVal ecv;
    if (sdl2_prof_io) return;
    sdl2_prof_io = (struct timerequest *)AllocMem(sizeof(struct timerequest), MEMF_PUBLIC | MEMF_CLEAR);
    if (!sdl2_prof_io) return;
    if (OpenDevice((CONST_STRPTR)TIMERNAME, UNIT_ECLOCK,
                   (struct IORequest *)sdl2_prof_io, 0) != 0) {
        FreeMem(sdl2_prof_io, sizeof(struct timerequest));
        sdl2_prof_io = NULL;
        return;
    }
    sdl2_prof_TimerBase = sdl2_prof_io->tr_node.io_Device;
    /* HACK: temporarily assign global TimerBase so ReadEClock binds */
    {
        extern struct Device *TimerBase;
        TimerBase = sdl2_prof_TimerBase;
        sdl2_prof_freq = ReadEClock(&ecv);
    }
}

static ULONG sdl2_prof_now(void)
{
    struct EClockVal ecv;
    extern struct Device *TimerBase;
    TimerBase = sdl2_prof_TimerBase;
    if (!sdl2_prof_TimerBase) return 0;
    ReadEClock(&ecv);
    return ecv.ev_lo;
}

static void sdl2_prof_dump(void)
{
    char buf[2048];
    int pos = 0;
    BPTR fh;

    if (sdl2_prof.call_count == 0) return;

    pos += sprintf(buf + pos, "=== libSDL2 OS3_FB profile (%lu Hz E-Clock) ===\n", sdl2_prof_freq);
    pos += sprintf(buf + pos, "Calls: %lu (fast=%lu fallback=%lu)\n",
                   sdl2_prof.call_count, sdl2_prof.fast_path_count, sdl2_prof.fallback_count);
    pos += sprintf(buf + pos, "VRAM: bm_pixfmt=%lu bm_bppix=%lu needs_swap=%d\n",
                   sdl2_prof.bm_pixfmt, sdl2_prof.bm_bppix, sdl2_prof.needs_swap);

    if (sdl2_prof.fast_path_count > 0) {
        ULONG lock_us  = (sdl2_prof.total_lock_ticks    / sdl2_prof.fast_path_count) * 1410 / 1000;
        ULONG copy_us  = (sdl2_prof.total_memcpy_ticks  / sdl2_prof.fast_path_count) * 1410 / 1000;
        ULONG unlk_us  = (sdl2_prof.total_unlock_ticks  / sdl2_prof.fast_path_count) * 1410 / 1000;
        pos += sprintf(buf + pos, "Fast-path avg per call: lock=%lu us, copy=%lu us, unlock=%lu us\n",
                       lock_us, copy_us, unlk_us);
    }
    if (sdl2_prof.fallback_count > 0) {
        ULONG wpa_us = (sdl2_prof.total_wpa_ticks / sdl2_prof.fallback_count) * 1410 / 1000;
        pos += sprintf(buf + pos, "Fallback avg per call: WritePixelArray=%lu us\n", wpa_us);
    }

    fh = Open((CONST_STRPTR)"WORK:OpenTTD-SDL2/sdl2-perf.log", MODE_NEWFILE);
    if (fh) {
        Write(fh, (CONST_APTR)buf, (LONG)pos);
        Close(fh);
    }
}
#define SDL2_PROF_NOW() sdl2_prof_now()
#define SDL2_PROF_INIT() sdl2_prof_init()
#define SDL2_PROF_DUMP() sdl2_prof_dump()
#else
#define SDL2_PROF_NOW() 0
#define SDL2_PROF_INIT() ((void)0)
#define SDL2_PROF_DUMP() ((void)0)
#endif

/* Key strings for SDL_SetWindowData / SDL_GetWindowData */
#define OS3_SURFACE_KEY  "OS3_Surface"
#define OS3_SCALEBM_KEY  "OS3_ScaleBM"
#define OS3_SCALERP_KEY  "OS3_ScaleRP"

/* Bytes per pixel for ARGB8888 */
#define OS3_BPP 4

/* Forward declaration (defined later in this file) */
void OS3_DestroyWindowFramebuffer(_THIS, SDL_Window *window);

/* Inline ARGB->BGRA memcpy for LockBitMap VRAM writes.
 * 68k assembly: byte-reverse a 32-bit word in 3 instructions
 *   ROL.W #8, Dn  -- swap bytes within low word    (8 cycles)
 *   SWAP Dn       -- swap high/low words           (4 cycles)
 *   ROL.W #8, Dn  -- swap bytes within (now low) word (8 cycles)
 * Total per pixel: ~20 cycles for the swap + load/store ~16 = 36 cycles.
 * The pure-C version is 4 mask + 4 shift + 3 OR + load/store ~80 cycles.
 * 2-3x faster on 68030/40 -- direct attack on the OpenTTD memcpy bottleneck
 * (PDR-015: previously 77 ms / frame at 640x480, this should drop to ~25-35 ms). */
static void MemcpyARGB_to_BGRA(Uint32 *dst, const Uint32 *src, int count)
{
    int i;
#ifdef __GNUC__
    for (i = 0; i < count; i++) {
        Uint32 p = src[i];
        __asm__ volatile (
            "rol.w  #8, %0\n\t"
            "swap   %0\n\t"
            "rol.w  #8, %0"
            : "+d" (p)
        );
        dst[i] = p;
    }
#else
    for (i = 0; i < count; i++) {
        Uint32 p = src[i];
        dst[i] = ((p & 0x000000FFu) << 24)
                | ((p & 0x0000FF00u) << 8)
                | ((p & 0x00FF0000u) >> 8)
                | ((p & 0xFF000000u) >> 24);
    }
#endif
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

#ifdef SDL_OS3_PROFILE
    /* DEBUG: write a heartbeat file on the very first call so we can confirm
     * this function is being entered at all. If this file appears but
     * sdl2-perf.log doesn't, the issue is the dump function. If neither
     * appears, OS3_UpdateWindowFramebuffer is never called. */
    {
        static int heartbeat_written = 0;
        if (!heartbeat_written) {
            BPTR fh = Open((CONST_STRPTR)"WORK:OpenTTD-SDL2/sdl2-heartbeat.log", MODE_NEWFILE);
            if (fh) { Write(fh, (CONST_APTR)"OS3_UpdateWindowFramebuffer entered\n", 36); Close(fh); }
            heartbeat_written = 1;
        }
    }
#endif

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

        /* Kalms c2p: direct chunky-to-planar to screen bitplanes.
         * ~10ms on 030/50MHz vs ~189ms for WriteChunkyPixels. */
        {
            static int c2p_inited = 0;
            if (!c2p_inited) {
                OS3_AGA_C2PInit(surface->w, surface->h);
                c2p_inited = 1;
            }
        }
        OS3_AGA_C2P(surface->pixels, data->screen, surface->w, surface->h);

        return 0;
    }

    /* --- RTG path --- */
    {
        int win_w = data->window->Width;
        int win_h = data->window->Height;
        int need_scale = (win_w > surface->w || win_h > surface->h);

#ifdef SDL_OS3_PROFILE
        /* PRE-SPLIT: increment call_count AND dump regardless of which branch
         * is taken. Earlier we put call_count++ inside the no-scale branch
         * only; if FS-UAE hits need_scale, dump never fires. Also write a
         * one-shot diagnostic so we know which branch is being taken. */
        sdl2_prof.call_count++;
        SDL2_PROF_INIT();
        {
            static int branch_logged = 0;
            if (!branch_logged) {
                char dbgbuf[256];
                int n = snprintf(dbgbuf, sizeof(dbgbuf),
                    "win_w=%d win_h=%d surface_w=%d surface_h=%d need_scale=%d\n",
                    win_w, win_h, surface->w, surface->h, need_scale);
                BPTR fh = Open((CONST_STRPTR)"WORK:OpenTTD-SDL2/sdl2-branch.log", MODE_NEWFILE);
                if (fh) { Write(fh, (CONST_APTR)dbgbuf, (LONG)n); Close(fh); }
                branch_logged = 1;
            }
        }
        if ((sdl2_prof.call_count % 10) == 0) {
            SDL2_PROF_DUMP();
        }
#endif

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
#ifdef SDL_OS3_PROFILE
            /* call_count + init now hoisted to pre-split (above). Don't double-count. */
            ULONG _t0, _t1;
#endif

            if (GetCyberMapAttr(win_bm, CYBRMATTR_ISCYBERGFX)) {
                ULONG bm_base = 0, bm_pitch = 0;
                ULONG bm_pixfmt = 0, bm_bppix = 0;
                APTR lock;

#ifdef SDL_OS3_PROFILE
                _t0 = SDL2_PROF_NOW();
#endif
                lock = LockBitMapTags(win_bm,
                    LBMI_BASEADDRESS, (ULONG)&bm_base,
                    LBMI_BYTESPERROW, (ULONG)&bm_pitch,
                    LBMI_PIXFMT,      (ULONG)&bm_pixfmt,
                    LBMI_BYTESPERPIX, (ULONG)&bm_bppix,
                    TAG_DONE);
#ifdef SDL_OS3_PROFILE
                _t1 = SDL2_PROF_NOW();
                sdl2_prof.total_lock_ticks += (_t1 - _t0);
                sdl2_prof.bm_pixfmt = bm_pixfmt;
                sdl2_prof.bm_bppix = bm_bppix;
#endif

                if (lock && bm_base && bm_bppix == OS3_BPP) {
                    UBYTE *fb = (UBYTE *)bm_base;
                    int needs_swap = (bm_pixfmt != 11); /* 11 = PIXFMT_ARGB32 */
#ifdef SDL_OS3_PROFILE
                    sdl2_prof.needs_swap = needs_swap;
                    _t0 = SDL2_PROF_NOW();
#endif

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
#ifdef SDL_OS3_PROFILE
                    _t1 = SDL2_PROF_NOW();
                    sdl2_prof.total_memcpy_ticks += (_t1 - _t0);
                    sdl2_prof.fast_path_count++;
#endif
                    used_lock = 1;
                }

                if (lock) {
#ifdef SDL_OS3_PROFILE
                    _t0 = SDL2_PROF_NOW();
#endif
                    UnLockBitMap(lock);
#ifdef SDL_OS3_PROFILE
                    _t1 = SDL2_PROF_NOW();
                    sdl2_prof.total_unlock_ticks += (_t1 - _t0);
#endif
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
#ifdef SDL_OS3_PROFILE
                _t0 = SDL2_PROF_NOW();
                sdl2_prof.fallback_count++;
#endif
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
#ifdef SDL_OS3_PROFILE
                _t1 = SDL2_PROF_NOW();
                sdl2_prof.total_wpa_ticks += (_t1 - _t0);
#endif
            }
#ifdef SDL_OS3_PROFILE
            /* Dump every 10 calls (was 25; lower so we see results even on
             * very short test runs / abrupt FS-UAE close). */
            if ((sdl2_prof.call_count % 10) == 0) {
                SDL2_PROF_DUMP();
            }
#endif
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

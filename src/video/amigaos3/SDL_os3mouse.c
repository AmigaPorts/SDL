/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Mouse/cursor backend: SetPointer-based cursor management.

  Amiga hardware sprites: 16px wide max, 2 bitplanes (4 colors: transparent + 3).
  Sprite data must be in CHIP RAM (ADCD ch.10).
  Sprite 0 (Intuition pointer) uses color registers 17, 18, 19.

  References:
    ADCD: 10-custom-pointer-the-sprite-data-structure.md
    ADCD: 4-sprite-hardware-summary-of-sprite-color-registers.md
    ADCD: intuition-library-setpointer-2.md
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <exec/types.h>
#include <exec/memory.h>

#include "SDL_os3video.h"
#include "SDL_os3mouse.h"
#include "../../events/SDL_mouse_c.h"
#include "../../events/default_cursor.h"

/* Driver data stored in SDL_Cursor->driverdata */
typedef struct {
    UWORD *sprite_data;   /* CHIP RAM sprite image */
    ULONG  alloc_size;    /* Size of CHIP RAM allocation (for FreeMem) */
    int    width;         /* Sprite width (max 16) */
    int    height;        /* Sprite height */
    int    hot_x;         /* Hot spot X */
    int    hot_y;         /* Hot spot Y */
    Uint32 colors[3];     /* Chosen palette colors as 0x00RRGGBB */
} OS3_CursorData;

/* Forward declarations */
static SDL_Cursor *OS3_CreateCursor(SDL_Surface *surface, int hot_x, int hot_y);
static SDL_Cursor *OS3_CreateSystemCursor(SDL_SystemCursor id);
static int  OS3_ShowCursor(SDL_Cursor *cursor);
static void OS3_FreeCursor(SDL_Cursor *cursor);
static void OS3_WarpMouse(SDL_Window *window, int x, int y);

/* ------------------------------------------------------------------ */
/* Color reduction: find 3 most frequent non-transparent colors       */
/* ------------------------------------------------------------------ */

/* Simple histogram bucket -- we only track a small number of unique colors */
#define MAX_COLOR_BUCKETS 64

typedef struct {
    Uint32 color;   /* 0x00RRGGBB */
    int    count;
} ColorBucket;

/* Return squared distance between two RGB colors (no overflow for 8-bit) */
static Uint32 OS3_ColorDistSq(Uint32 a, Uint32 b)
{
    int dr = (int)((a >> 16) & 0xFF) - (int)((b >> 16) & 0xFF);
    int dg = (int)((a >>  8) & 0xFF) - (int)((b >>  8) & 0xFF);
    int db = (int)((a      ) & 0xFF) - (int)((b      ) & 0xFF);
    return (Uint32)(dr * dr + dg * dg + db * db);
}

/* Find the top 3 most frequent non-transparent colors in an ARGB8888 surface.
   Returns the number of distinct colors found (0..3). */
static int OS3_FindTopColors(SDL_Surface *surface, int sw, int sh,
                             Uint32 out_colors[3])
{
    ColorBucket buckets[MAX_COLOR_BUCKETS];
    int num_buckets = 0;
    int x, y, i;

    for (y = 0; y < sh; y++) {
        Uint32 *row = (Uint32 *)((Uint8 *)surface->pixels + y * surface->pitch);
        for (x = 0; x < sw; x++) {
            Uint32 px = row[x];
            Uint8 alpha = (Uint8)(px >> 24);
            Uint32 rgb;
            int found;

            if (alpha < 128) {
                continue;  /* transparent */
            }
            rgb = px & 0x00FFFFFF;

            /* Find or insert into histogram */
            found = 0;
            for (i = 0; i < num_buckets; i++) {
                /* Merge similar colors (distance < 32^2 = 1024) */
                if (OS3_ColorDistSq(buckets[i].color, rgb) < 1024) {
                    buckets[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found && num_buckets < MAX_COLOR_BUCKETS) {
                buckets[num_buckets].color = rgb;
                buckets[num_buckets].count = 1;
                num_buckets++;
            }
        }
    }

    /* Sort by count descending (simple selection sort, max 64 items) */
    for (i = 0; i < num_buckets - 1 && i < 3; i++) {
        int best = i;
        int j;
        for (j = i + 1; j < num_buckets; j++) {
            if (buckets[j].count > buckets[best].count) {
                best = j;
            }
        }
        if (best != i) {
            ColorBucket tmp = buckets[i];
            buckets[i] = buckets[best];
            buckets[best] = tmp;
        }
    }

    /* Output top 3 */
    {
        int result = (num_buckets < 3) ? num_buckets : 3;
        for (i = 0; i < result; i++) {
            out_colors[i] = buckets[i].color;
        }
        return result;
    }
}

/* ------------------------------------------------------------------ */
/* ARGB8888 surface -> Amiga sprite data in CHIP RAM                  */
/* ------------------------------------------------------------------ */

/* Map a single ARGB pixel to sprite color index 0-3.
   0 = transparent, 1/2/3 = palette colors. */
static int OS3_MapPixel(Uint32 px, const Uint32 palette[3], int num_colors)
{
    Uint8 alpha = (Uint8)(px >> 24);
    Uint32 rgb;
    Uint32 best_dist;
    int best_idx;
    int i;

    if (alpha < 128 || num_colors == 0) {
        return 0;  /* transparent */
    }
    rgb = px & 0x00FFFFFF;
    best_dist = OS3_ColorDistSq(rgb, palette[0]);
    best_idx = 1;  /* sprite color 1 */

    for (i = 1; i < num_colors; i++) {
        Uint32 d = OS3_ColorDistSq(rgb, palette[i]);
        if (d < best_dist) {
            best_dist = d;
            best_idx = i + 1;  /* sprite colors are 1-based */
        }
    }
    return best_idx;
}

/* Build Amiga sprite data from an ARGB8888 surface.
   Downsamples if source > 16px wide or > 64px tall.
   Returns CHIP RAM pointer (caller must FreeMem with returned alloc_size). */
static UWORD *OS3_BuildSpriteData(SDL_Surface *surface, int hot_x, int hot_y,
                                   const Uint32 palette[3], int num_colors,
                                   int *out_w, int *out_h,
                                   int *out_hot_x, int *out_hot_y,
                                   ULONG *out_alloc_size)
{
    int src_w = surface->w;
    int src_h = surface->h;
    int dst_w, dst_h;
    int scale_x, scale_y;
    ULONG alloc_size;
    UWORD *sprite;
    int row, col;

    /* Determine scaling */
    scale_x = 1;
    scale_y = 1;
    dst_w = src_w;
    dst_h = src_h;

    while (dst_w > 16) {
        scale_x *= 2;
        dst_w = src_w / scale_x;
    }
    while (dst_h > 64) {
        scale_y *= 2;
        dst_h = src_h / scale_y;
    }
    if (dst_w > 16) dst_w = 16;
    if (dst_h > 64) dst_h = 64;

    /* Sprite data: 2 control + (height * 2 bitplane words) + 2 terminator */
    alloc_size = (ULONG)((2 + dst_h * 2 + 2) * sizeof(UWORD));

    sprite = (UWORD *)AllocMem(alloc_size, MEMF_CHIP | MEMF_CLEAR);
    if (!sprite) {
        return NULL;
    }

    /* Control words are 0 (MEMF_CLEAR handles this) */
    /* sprite[0] = 0; sprite[1] = 0; */

    /* Build bitplane data -- interleaved: plane0, plane1 per line */
    for (row = 0; row < dst_h; row++) {
        UWORD plane0 = 0;
        UWORD plane1 = 0;
        int src_y = row * scale_y;
        Uint32 *src_row;

        if (src_y >= src_h) src_y = src_h - 1;
        src_row = (Uint32 *)((Uint8 *)surface->pixels + src_y * surface->pitch);

        for (col = 0; col < dst_w; col++) {
            int src_x = col * scale_x;
            int ci;
            int bit;

            if (src_x >= src_w) src_x = src_w - 1;
            ci = OS3_MapPixel(src_row[src_x], palette, num_colors);

            /* Bit position: MSB = leftmost pixel */
            bit = 15 - col;
            if (ci & 1) plane0 |= (UWORD)(1 << bit);
            if (ci & 2) plane1 |= (UWORD)(1 << bit);
        }

        sprite[2 + row * 2]     = plane0;
        sprite[2 + row * 2 + 1] = plane1;
    }

    /* Terminator words are 0 (MEMF_CLEAR handles this) */

    *out_w = dst_w;
    *out_h = dst_h;
    *out_hot_x = hot_x / scale_x;
    *out_hot_y = hot_y / scale_y;
    *out_alloc_size = alloc_size;

    return sprite;
}

/* ------------------------------------------------------------------ */
/* Set sprite 0 color registers (17, 18, 19) for the active screen    */
/* ------------------------------------------------------------------ */

static void OS3_SetSpriteColors(struct Screen *screen,
                                const Uint32 colors[3], int num_colors)
{
    struct ViewPort *vp;
    int i;

    if (!screen) return;
    vp = &screen->ViewPort;

    for (i = 0; i < num_colors && i < 3; i++) {
        ULONG r = (colors[i] >> 16) & 0xFF;
        ULONG g = (colors[i] >>  8) & 0xFF;
        ULONG b = (colors[i]      ) & 0xFF;

        /* SetRGB32 takes 32-bit left-justified fractions.
           Expand 8-bit value to full 32-bit range. */
        ULONG r32 = (r << 24) | (r << 16) | (r << 8) | r;
        ULONG g32 = (g << 24) | (g << 16) | (g << 8) | g;
        ULONG b32 = (b << 24) | (b << 16) | (b << 8) | b;

        /* Sprite 0 uses color registers 17, 18, 19 */
        SetRGB32(vp, (ULONG)(17 + i), r32, g32, b32);
    }
}

/* ------------------------------------------------------------------ */
/* SDL_Mouse callbacks                                                */
/* ------------------------------------------------------------------ */

static SDL_Cursor *OS3_CreateCursor(SDL_Surface *surface, int hot_x, int hot_y)
{
    SDL_Cursor *cursor;
    OS3_CursorData *data;
    UWORD *sprite;
    Uint32 colors[3] = {0, 0, 0};
    int num_colors;
    int dst_w, dst_h, dst_hx, dst_hy;
    ULONG alloc_size;

    SDL_assert(surface->format->format == SDL_PIXELFORMAT_ARGB8888);

    /* Find dominant colors */
    num_colors = OS3_FindTopColors(surface, surface->w, surface->h, colors);
    if (num_colors == 0) {
        /* Fully transparent cursor -- still allocate a minimal sprite */
        num_colors = 1;
        colors[0] = 0x000000;
    }

    /* Build sprite data */
    sprite = OS3_BuildSpriteData(surface, hot_x, hot_y,
                                  colors, num_colors,
                                  &dst_w, &dst_h, &dst_hx, &dst_hy,
                                  &alloc_size);
    if (!sprite) {
        SDL_OutOfMemory();
        return NULL;
    }

    /* Allocate SDL cursor + driver data */
    cursor = (SDL_Cursor *)SDL_calloc(1, sizeof(*cursor));
    if (!cursor) {
        FreeMem(sprite, alloc_size);
        SDL_OutOfMemory();
        return NULL;
    }

    data = (OS3_CursorData *)SDL_calloc(1, sizeof(*data));
    if (!data) {
        FreeMem(sprite, alloc_size);
        SDL_free(cursor);
        SDL_OutOfMemory();
        return NULL;
    }

    data->sprite_data = sprite;
    data->alloc_size  = alloc_size;
    data->width       = dst_w;
    data->height      = dst_h;
    data->hot_x       = dst_hx;
    data->hot_y       = dst_hy;
    SDL_memcpy(data->colors, colors, sizeof(data->colors));

    cursor->driverdata = data;
    return cursor;
}

static SDL_Cursor *OS3_CreateSystemCursor(SDL_SystemCursor id)
{
    /* Use SDL's built-in default cursor data for all system cursor types.
       Amiga Intuition doesn't have themed system cursors. */
    (void)id;
    return SDL_CreateCursor(default_cdata, default_cmask,
                            DEFAULT_CWIDTH, DEFAULT_CHEIGHT,
                            DEFAULT_CHOTX, DEFAULT_CHOTY);
}

static int OS3_ShowCursor(SDL_Cursor *cursor)
{
    SDL_Window *sdl_window;
    OS3_WindowData *wdata;
    struct Window *iwin;
    struct Screen *screen;

    sdl_window = SDL_GetMouseFocus();
    if (!sdl_window) {
        /* No focused window -- nothing to do, will be applied when focus arrives */
        return 0;
    }
    wdata = (OS3_WindowData *)sdl_window->driverdata;
    if (!wdata || !wdata->window) {
        return 0;
    }
    iwin = wdata->window;
    screen = iwin->WScreen;

    if (cursor) {
        OS3_CursorData *data = (OS3_CursorData *)cursor->driverdata;

        if (!data || !data->sprite_data) {
            ClearPointer(iwin);
            return 0;
        }

        /* Set sprite palette colors on the screen */
        OS3_SetSpriteColors(screen, data->colors, 3);

        /* ADCD: xOffset/yOffset are from hot spot to top-left of sprite.
           "For compatibility, the application must specify that the
           hot spot is one pixel to the left of the desired position." */
        SetPointer(iwin, data->sprite_data,
                   (WORD)data->height, (WORD)data->width,
                   (WORD)(-data->hot_x), (WORD)(-data->hot_y));
    } else {
        /* Hide cursor: set an empty 1x1 transparent sprite */
        /* Use a static CHIP RAM allocation for the empty pointer.
           Cannot use stack -- sprite data must persist and be in CHIP RAM. */
        static UWORD *empty_sprite = NULL;
        static ULONG empty_size = 0;

        if (!empty_sprite) {
            /* 2 control + 2 data (1 line) + 2 terminator = 6 words */
            empty_size = 6 * sizeof(UWORD);
            empty_sprite = (UWORD *)AllocMem(empty_size, MEMF_CHIP | MEMF_CLEAR);
        }
        if (empty_sprite) {
            SetPointer(iwin, empty_sprite, 1, 1, 0, 0);
        }
    }

    return 0;
}

static void OS3_FreeCursor(SDL_Cursor *cursor)
{
    OS3_CursorData *data;

    if (!cursor) return;

    data = (OS3_CursorData *)cursor->driverdata;
    if (data) {
        if (data->sprite_data && data->alloc_size > 0) {
            FreeMem(data->sprite_data, data->alloc_size);
        }
        SDL_free(data);
    }
    SDL_free(cursor);
}

static void OS3_WarpMouse(SDL_Window *window, int x, int y)
{
    /* Not implemented for Phase 2.
       Would require moving the mouse via input.device which is complex
       and rarely needed by SDL2 applications. */
    (void)window;
    (void)x;
    (void)y;
}

/* ------------------------------------------------------------------ */
/* Init / Quit                                                        */
/* ------------------------------------------------------------------ */

void OS3_InitMouse(void)
{
    SDL_Mouse *mouse = SDL_GetMouse();

    mouse->CreateCursor      = OS3_CreateCursor;
    mouse->CreateSystemCursor = OS3_CreateSystemCursor;
    mouse->ShowCursor         = OS3_ShowCursor;
    mouse->FreeCursor         = OS3_FreeCursor;
    mouse->WarpMouse          = OS3_WarpMouse;

    SDL_SetDefaultCursor(OS3_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
}

void OS3_QuitMouse(void)
{
    SDL_Mouse *mouse = SDL_GetMouse();

    /* SDL2 core frees cursors via FreeCursor callback.
       Just clear the function pointers. */
    mouse->CreateCursor       = NULL;
    mouse->CreateSystemCursor = NULL;
    mouse->ShowCursor         = NULL;
    mouse->FreeCursor         = NULL;
    mouse->WarpMouse          = NULL;

    /* Note: the static empty_sprite in OS3_ShowCursor is intentionally
       NOT freed here. It is a tiny 12-byte CHIP RAM allocation that
       persists until process exit. Freeing it while SetPointer may still
       reference it risks a crash. On AmigaOS, process exit reclaims it. */
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

/*
 * test_render: SDL_Renderer pipeline test.
 *
 * Tests the SDL2 software renderer end-to-end:
 *   - SDL_CreateRenderer (software)
 *   - SDL_RenderClear, SDL_RenderFillRect, SDL_RenderDrawLine
 *   - SDL_RenderCopyEx (rotation + scaling)
 *   - SDL_CreateTexture + SDL_UpdateTexture
 *
 * Draws a checkerboard texture, rotates it, and draws primitives.
 * Exits after 3 seconds or on ESC.
 *
 * Build: make examples
 * Run:   WORK:test_render on FS-UAE with RTG
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_render 0.1 (28.03.2026)";
long __stack = 65536;

#define WIN_W 320
#define WIN_H 240
#define TEX_W 64
#define TEX_H 64
#define RUN_MS 3000

/* Generate a checkerboard pattern in ARGB8888 */
static void make_checkerboard(Uint32 *pixels, int w, int h, int tile)
{
    int x, y;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int cx = x / tile;
            int cy = y / tile;
            if ((cx + cy) % 2 == 0) {
                pixels[y * w + x] = 0xFF00CC00; /* green */
            } else {
                pixels[y * w + x] = 0xFF003366; /* dark blue */
            }
        }
    }
}

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    Uint32 pixels[TEX_W * TEX_H];
    SDL_Event event;
    SDL_Rect dst;
    Uint32 start;
    int running = 1;
    int frames = 0;
    double angle = 0.0;
    int rc;

    (void)argc; (void)argv; (void)verstag;

    printf("test_render: SDL_Renderer pipeline test\n");
    fflush(stdout);

    rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc != 0) {
        printf("FAIL: SDL_Init(VIDEO): %s\n", SDL_GetError());
        return 10;
    }

    window = SDL_CreateWindow(
        "SDL2 Renderer Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H, 0
    );
    if (!window) {
        printf("FAIL: SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_Quit();
        return 10;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        printf("FAIL: SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }

    printf("Renderer: %s\n", "software");

    /* Create texture with checkerboard */
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STATIC, TEX_W, TEX_H);
    if (!texture) {
        printf("FAIL: SDL_CreateTexture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }

    make_checkerboard(pixels, TEX_W, TEX_H, 8);
    SDL_UpdateTexture(texture, NULL, pixels, TEX_W * sizeof(Uint32));
    printf("Created %dx%d checkerboard texture\n", TEX_W, TEX_H);
    fflush(stdout);

    start = SDL_GetTicks();
    while (running && (SDL_GetTicks() - start) < RUN_MS) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                running = 0;
        }

        /* Clear to dark background */
        SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
        SDL_RenderClear(renderer);

        /* Draw some lines */
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderDrawLine(renderer, 0, 0, WIN_W - 1, WIN_H - 1);
        SDL_RenderDrawLine(renderer, WIN_W - 1, 0, 0, WIN_H - 1);

        /* Draw a filled rect */
        {
            SDL_Rect r;
            r.x = 10; r.y = 10; r.w = 60; r.h = 40;
            SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
            SDL_RenderFillRect(renderer, &r);
        }

        /* Draw rotated texture in center */
        dst.x = (WIN_W - TEX_W) / 2;
        dst.y = (WIN_H - TEX_H) / 2;
        dst.w = TEX_W;
        dst.h = TEX_H;
        SDL_RenderCopyEx(renderer, texture, NULL, &dst,
                         angle, NULL, SDL_FLIP_NONE);

        SDL_RenderPresent(renderer);

        angle += 2.0;
        if (angle >= 360.0) angle -= 360.0;

        frames++;
        SDL_Delay(16);
    }

    printf("Rendered %d frames (%.1f fps)\n", frames,
           frames * 1000.0 / (SDL_GetTicks() - start));
    fflush(stdout);

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    if (frames < 10) {
        printf("FAIL: too few frames (%d)\n", frames);
        return 10;
    }

    printf("PASS: renderer test complete\n");
    return 0;
}

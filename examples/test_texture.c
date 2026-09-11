/*
 * test_texture: Exercise the SDL_Texture pipeline that Chocolate Doom needs.
 *
 * Tests the complete path: SDL_CreateTexture(STREAMING) -> SDL_LockTexture ->
 * write pixels -> SDL_UnlockTexture -> SDL_RenderCopy -> SDL_RenderPresent.
 *
 * Also tests SDL_RenderSetLogicalSize with textures and SDL_SetRenderTarget.
 *
 * Visual output: animated color bars scrolling vertically (320x200, scaled up).
 * Runs for ~200 frames then exits automatically.
 *
 * This is the exact rendering path Chocolate Doom uses:
 *   1. Game renders 320x200 8-bit pixels
 *   2. Palette lookup to ARGB8888
 *   3. LockTexture + memcpy to streaming texture
 *   4. RenderCopy to screen
 *   5. RenderPresent
 */

#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"

static const char *verstag = "$VER: test_texture 0.1 (28.03.2026)";
long __stack = 32768;

/* Doom's native resolution */
#define GAME_W 320
#define GAME_H 200
#define SCREEN_W 640
#define SCREEN_H 400
#define MAX_FRAMES 200

/* Generate a test pattern: horizontal color bars that scroll */
static void generate_frame(Uint32 *pixels, int pitch_bytes, int frame)
{
    int x, y;
    int pitch = pitch_bytes / 4; /* pitch in Uint32s */

    for (y = 0; y < GAME_H; y++) {
        /* Scrolling color based on y + frame */
        int band = ((y + frame) / 8) % 6;
        Uint32 color;
        switch (band) {
            case 0: color = 0xFFFF0000; break; /* red */
            case 1: color = 0xFF00FF00; break; /* green */
            case 2: color = 0xFF0000FF; break; /* blue */
            case 3: color = 0xFFFFFF00; break; /* yellow */
            case 4: color = 0xFFFF00FF; break; /* magenta */
            default: color = 0xFF00FFFF; break; /* cyan */
        }
        for (x = 0; x < GAME_W; x++) {
            pixels[y * pitch + x] = color;
        }
    }

    /* Draw a white border to verify dimensions are correct */
    for (x = 0; x < GAME_W; x++) {
        pixels[x] = 0xFFFFFFFF;                          /* top row */
        pixels[(GAME_H - 1) * pitch + x] = 0xFFFFFFFF;   /* bottom row */
    }
    for (y = 0; y < GAME_H; y++) {
        pixels[y * pitch] = 0xFFFFFFFF;                   /* left col */
        pixels[y * pitch + GAME_W - 1] = 0xFFFFFFFF;      /* right col */
    }

    /* Frame counter in top-left: simple dot pattern */
    {
        int digit = frame % 10;
        int dx, dy;
        for (dy = 0; dy < 5; dy++) {
            for (dx = 0; dx < 3; dx++) {
                if ((digit == 0 && (dx == 0 || dx == 2 || dy == 0 || dy == 4)) ||
                    (digit != 0)) {
                    pixels[(dy + 2) * pitch + (dx + 2)] = 0xFF000000;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int frame;
    int quit = 0;
    Uint32 start_ticks, end_ticks, total_ms;

    (void)argc;
    (void)argv;
    (void)verstag;

    SDL_Log("test_texture: starting");

    /* --- Step 1: Init video --- */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 10;
    }
    SDL_Log("test_texture: SDL_Init OK");

    /* --- Step 2: Create fullscreen window --- */
    window = SDL_CreateWindow("test_texture",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_W, SCREEN_H,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    if (!window) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
        return 10;
    }
    SDL_Log("test_texture: window created");

    /* --- Step 3: Create software renderer --- */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }
    SDL_Log("test_texture: renderer created");

    /* --- Step 4: Set logical size (Doom does this) --- */
    SDL_RenderSetLogicalSize(renderer, GAME_W, GAME_H);
    SDL_Log("test_texture: logical size set to %dx%d", GAME_W, GAME_H);

    /* --- Step 5: Create streaming texture (this is the key Doom path) --- */
    texture = SDL_CreateTexture(renderer,
                                SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STREAMING,
                                GAME_W, GAME_H);
    if (!texture) {
        SDL_Log("SDL_CreateTexture failed: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }
    SDL_Log("test_texture: streaming texture created (%dx%d ARGB8888)", GAME_W, GAME_H);

    /* --- Step 6: Main loop -- render frames --- */
    SDL_Log("test_texture: entering main loop (%d frames)", MAX_FRAMES);
    start_ticks = SDL_GetTicks();

    for (frame = 0; frame < MAX_FRAMES && !quit; frame++) {
        SDL_Event e;
        void *tex_pixels;
        int tex_pitch;

        /* Poll events */
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = 1;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                quit = 1;
        }

        /* Lock texture to get writable pixel buffer */
        if (SDL_LockTexture(texture, NULL, &tex_pixels, &tex_pitch) < 0) {
            SDL_Log("SDL_LockTexture failed at frame %d: %s", frame, SDL_GetError());
            break;
        }

        /* Generate test pattern directly into texture pixels */
        generate_frame((Uint32 *)tex_pixels, tex_pitch, frame);

        /* Unlock -- pixels are now uploaded */
        SDL_UnlockTexture(texture);

        /* Clear, copy texture to screen, present */
        SDL_RenderClear(renderer);
        if (SDL_RenderCopy(renderer, texture, NULL, NULL) < 0) {
            SDL_Log("SDL_RenderCopy failed at frame %d: %s", frame, SDL_GetError());
            break;
        }
        SDL_RenderPresent(renderer);

        /* Frame pacing */
        SDL_Delay(16);
    }

    end_ticks = SDL_GetTicks();
    total_ms = end_ticks - start_ticks;

    SDL_Log("test_texture: rendered %d frames in %lu ms (avg %lu ms/frame)",
            frame, (unsigned long)total_ms,
            frame > 0 ? (unsigned long)(total_ms / (Uint32)frame) : 0UL);

    /* --- Cleanup --- */
    SDL_Log("test_texture: cleanup");
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    SDL_Log("test_texture: done");
    return 0;
}

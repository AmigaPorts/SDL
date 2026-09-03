/*
 * test_bmpview: Load and display a BMP image.
 *
 * Tests SDL_LoadBMP (SDL_RWops file I/O) + video blitting together.
 * Loads icon.bmp from PROGDIR: and displays it centered in the window.
 * Exits after 3 seconds or on ESC.
 *
 * Build: make examples
 * Run:   Copy icon.bmp to same directory, then WORK:test_bmpview on FS-UAE
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_bmpview 0.1 (28.03.2026)";
long __stack = 65536;

#define WIN_W 320
#define WIN_H 240
#define DISPLAY_MS 3000

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL;
    SDL_Surface *bmp = NULL;
    SDL_Rect dst;
    SDL_Event event;
    Uint32 start;
    int running = 1;
    int rc;

    (void)argc; (void)argv; (void)verstag;

    printf("test_bmpview: BMP load + display test\n");
    fflush(stdout);

    rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc != 0) {
        printf("FAIL: SDL_Init(VIDEO): %s\n", SDL_GetError());
        return 10;
    }

    /* Try loading BMP from current directory */
    bmp = SDL_LoadBMP("PROGDIR:icon.bmp");
    if (!bmp) {
        bmp = SDL_LoadBMP("icon.bmp");
    }
    if (!bmp) {
        printf("FAIL: SDL_LoadBMP: %s\n", SDL_GetError());
        printf("  (make sure icon.bmp is in the same directory)\n");
        SDL_Quit();
        return 10;
    }
    printf("Loaded BMP: %dx%d %dbpp\n", bmp->w, bmp->h,
           bmp->format->BitsPerPixel);
    fflush(stdout);

    window = SDL_CreateWindow(
        "SDL2 BMP Viewer",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H, 0
    );
    if (!window) {
        printf("FAIL: SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_FreeSurface(bmp);
        SDL_Quit();
        return 10;
    }

    screen = SDL_GetWindowSurface(window);
    if (!screen) {
        printf("FAIL: SDL_GetWindowSurface: %s\n", SDL_GetError());
        SDL_FreeSurface(bmp);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }

    /* Clear to dark blue */
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 64));

    /* Blit BMP centered */
    dst.x = (WIN_W - bmp->w) / 2;
    dst.y = (WIN_H - bmp->h) / 2;
    dst.w = bmp->w;
    dst.h = bmp->h;
    rc = SDL_BlitSurface(bmp, NULL, screen, &dst);
    printf("BlitSurface returned %d\n", rc);

    SDL_UpdateWindowSurface(window);
    printf("Displayed BMP at (%d,%d) -- showing for %d ms\n",
           dst.x, dst.y, DISPLAY_MS);
    fflush(stdout);

    start = SDL_GetTicks();
    while (running && (SDL_GetTicks() - start) < DISPLAY_MS) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                running = 0;
        }
        SDL_Delay(20);
    }

    SDL_FreeSurface(bmp);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("PASS: BMP view test complete\n");
    return 0;
}

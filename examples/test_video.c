/*
 * Phase 1 Visual Test: CyberGraphX video backend verification.
 *
 * Opens a 320x256 window on the Workbench screen and draws four
 * colored quadrants:
 *
 *   +--------+--------+
 *   |  RED   | GREEN  |
 *   +--------+--------+
 *   |  BLUE  | WHITE  |
 *   +--------+--------+
 *
 * If the quadrants appear in the correct colors, the entire pipeline
 * works: VideoInit -> CreateWindow -> CreateWindowFramebuffer ->
 * FillRect -> UpdateWindowFramebuffer (WritePixelArray) -> visible.
 *
 * Exits after 5 seconds or when the close gadget / ESC is pressed.
 *
 * Build: make examples
 * Run:   Copy to WORK: and run from Amiga shell on FS-UAE with RTG.
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_video 0.1 (27.03.2026)";
long __stack = 65536;

#define WIN_W 320
#define WIN_H 256
#define TIMEOUT_MS 5000

int main(int argc, char *argv[])
{
    SDL_Window  *window  = NULL;
    SDL_Surface *surface = NULL;
    SDL_Event    event;
    SDL_Rect     rect;
    Uint32       red, green, blue, white;
    Uint32       start;
    int          running = 1;
    int          rc;

    (void)argc;
    (void)argv;
    (void)verstag;

    printf("\n");
    printf("  libSDL2 for AmigaOS 3.x -- First Pixels\n");
    printf("  =========================================\n");
    printf("  SDL2 2.33.0 on Motorola 68k + CyberGraphX RTG\n");
    printf("  github.com/bdgscotland/libSDL2-amigaos3\n");
    printf("\n");

    /* Init video subsystem -- opens cybergraphics.library etc. */
    printf("Calling SDL_Init(SDL_INIT_VIDEO)...\n");
    fflush(stdout);
    rc = SDL_Init(SDL_INIT_VIDEO);
    printf("SDL_Init returned %d\n", rc);
    fflush(stdout);
    if (rc != 0) {
        printf("FAIL: SDL_Init(VIDEO) returned %d: %s\n", rc, SDL_GetError());
        fflush(stdout);
        return 10;
    }
    printf("PASS: SDL_Init(SDL_INIT_VIDEO) succeeded\n");

    /* Create a windowed window on the Workbench screen */
    window = SDL_CreateWindow(
        "SDL2 Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H,
        0  /* windowed */
    );
    if (!window) {
        printf("FAIL: SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_Quit();
        return 10;
    }
    printf("PASS: SDL_CreateWindow(%dx%d) succeeded\n", WIN_W, WIN_H);

    /* Get window surface -- triggers CreateWindowFramebuffer */
    surface = SDL_GetWindowSurface(window);
    if (!surface) {
        printf("FAIL: SDL_GetWindowSurface: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }
    printf("PASS: SDL_GetWindowSurface succeeded (format=%s, %dx%d, pitch=%d)\n",
           SDL_GetPixelFormatName(surface->format->format),
           surface->w, surface->h, surface->pitch);

    /* Map colors */
    red   = SDL_MapRGB(surface->format, 255,   0,   0);
    green = SDL_MapRGB(surface->format,   0, 255,   0);
    blue  = SDL_MapRGB(surface->format,   0,   0, 255);
    white = SDL_MapRGB(surface->format, 255, 255, 255);

    /* Draw four quadrants */
    /* Top-left: RED */
    rect.x = 0;           rect.y = 0;
    rect.w = WIN_W / 2;   rect.h = WIN_H / 2;
    SDL_FillRect(surface, &rect, red);

    /* Top-right: GREEN */
    rect.x = WIN_W / 2;   rect.y = 0;
    rect.w = WIN_W / 2;   rect.h = WIN_H / 2;
    SDL_FillRect(surface, &rect, green);

    /* Bottom-left: BLUE */
    rect.x = 0;           rect.y = WIN_H / 2;
    rect.w = WIN_W / 2;   rect.h = WIN_H / 2;
    SDL_FillRect(surface, &rect, blue);

    /* Bottom-right: WHITE */
    rect.x = WIN_W / 2;   rect.y = WIN_H / 2;
    rect.w = WIN_W / 2;   rect.h = WIN_H / 2;
    SDL_FillRect(surface, &rect, white);

    /* Blit to screen -- triggers WritePixelArray via UpdateWindowFramebuffer */
    rc = SDL_UpdateWindowSurface(window);
    if (rc != 0) {
        printf("FAIL: SDL_UpdateWindowSurface: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }
    printf("PASS: SDL_UpdateWindowSurface succeeded\n");

    /* Open a second window with the same colored quadrants pattern
       but titled with the project info for the screenshot. */
    {
        SDL_Window *infowin;
        SDL_Surface *infosurface;

        infowin = SDL_CreateWindow(
            "libSDL2 for AmigaOS 3.x -- SDL2 2.33.0 on 68k + CyberGraphX",
            350, 300, 240, 200, 0
        );
        if (infowin) {
            infosurface = SDL_GetWindowSurface(infowin);
            if (infosurface) {
                Uint32 r2, g2, b2, w2;
                SDL_Rect r;
                r2 = SDL_MapRGB(infosurface->format, 255, 0, 0);
                g2 = SDL_MapRGB(infosurface->format, 0, 255, 0);
                b2 = SDL_MapRGB(infosurface->format, 0, 0, 255);
                w2 = SDL_MapRGB(infosurface->format, 255, 255, 255);

                r.x = 0;   r.y = 0;   r.w = 120; r.h = 100;
                SDL_FillRect(infosurface, &r, r2);
                r.x = 120; r.y = 0;   r.w = 120; r.h = 100;
                SDL_FillRect(infosurface, &r, g2);
                r.x = 0;   r.y = 100; r.w = 120; r.h = 100;
                SDL_FillRect(infosurface, &r, b2);
                r.x = 120; r.y = 100; r.w = 120; r.h = 100;
                SDL_FillRect(infosurface, &r, w2);

                SDL_UpdateWindowSurface(infowin);
            }
        }
    }

    printf("\nIf you see RED/GREEN/BLUE/WHITE quadrants, Phase 1 video works!\n");
    printf("Press ESC or close gadget to exit.\n");

    /* Event loop -- respond to close/ESC, timeout after 5s */
    start = SDL_GetTicks();
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    running = 0;
                }
                break;
            }
        }

        if (SDL_GetTicks() - start >= TIMEOUT_MS) {
            running = 0;
        }

        SDL_Delay(50);  /* 20 Hz poll -- don't burn CPU */
    }

    printf("Shutting down cleanly...\n");
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("PASS: Clean shutdown\n");

    return 0;
}

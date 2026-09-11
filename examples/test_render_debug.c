/*
 * test_render_debug: Step-by-step renderer debugging.
 * Each step prints before/after to pinpoint the crash.
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_render_debug 0.1 (28.03.2026)";
long __stack = 65536;

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Rect rect;
    int rc;

    (void)argc; (void)argv; (void)verstag;

    printf("STEP 1: SDL_Init(VIDEO)\n"); fflush(stdout);
    rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc != 0) { printf("FAIL: %s\n", SDL_GetError()); return 10; }
    printf("  OK\n"); fflush(stdout);

    printf("STEP 2: SDL_CreateWindow\n"); fflush(stdout);
    window = SDL_CreateWindow("RenderDebug",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        320, 240, 0);
    if (!window) { printf("FAIL: %s\n", SDL_GetError()); SDL_Quit(); return 10; }
    printf("  OK window=%p\n", (void *)window); fflush(stdout);

    /* SDL_Renderer is opaque -- sizeof printed from inside SDL_CreateRenderer */
    printf("STEP 3: SDL_GetNumRenderDrivers\n"); fflush(stdout);
    {
        int nd = SDL_GetNumRenderDrivers();
        SDL_RendererInfo ri;
        int di;
        printf("  %d render drivers\n", nd); fflush(stdout);
        for (di = 0; di < nd; di++) {
            SDL_GetRenderDriverInfo(di, &ri);
            printf("  driver %d: %s flags=0x%lx\n", di, ri.name, (unsigned long)ri.flags);
            fflush(stdout);
        }
    }

    printf("STEP 3b: SDL_CreateRenderer(SOFTWARE)\n"); fflush(stdout);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) { printf("FAIL: %s\n", SDL_GetError()); SDL_DestroyWindow(window); SDL_Quit(); return 10; }
    printf("  OK renderer=%p\n", (void *)renderer); fflush(stdout);

    printf("STEP 4: SDL_SetRenderDrawColor\n"); fflush(stdout);
    SDL_SetRenderDrawColor(renderer, 100, 50, 50, 255);
    printf("  OK\n"); fflush(stdout);

    printf("STEP 5: SDL_RenderClear\n"); fflush(stdout);
    SDL_RenderClear(renderer);
    printf("  OK\n"); fflush(stdout);

    printf("STEP 6: SDL_RenderPresent\n"); fflush(stdout);
    SDL_RenderPresent(renderer);
    printf("  OK\n"); fflush(stdout);

    printf("STEP 7: SDL_SetRenderDrawColor (green)\n"); fflush(stdout);
    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    printf("  OK\n"); fflush(stdout);

    printf("STEP 8: SDL_RenderFillRect\n"); fflush(stdout);
    rect.x = 50; rect.y = 50; rect.w = 100; rect.h = 80;
    rc = SDL_RenderFillRect(renderer, &rect);
    printf("  OK rc=%d\n", rc); fflush(stdout);

    printf("STEP 9: SDL_RenderPresent (with rect)\n"); fflush(stdout);
    SDL_RenderPresent(renderer);
    printf("  OK\n"); fflush(stdout);

    printf("STEP 10: SDL_Delay(2000)\n"); fflush(stdout);
    SDL_Delay(2000);

    printf("STEP 11: cleanup\n"); fflush(stdout);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    printf("PASS: renderer debug complete\n");
    return 0;
}

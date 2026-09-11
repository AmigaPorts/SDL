/* Minimal window creation test for real hardware debugging */
#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_window 0.1 (03.04.2026)";
long __stack = 65536;

int main(int argc, char *argv[])
{
    SDL_Window *win;
    int nd;

    (void)argc; (void)argv; (void)verstag;

    printf("=== Window Test ===\n");

    printf("Step 1: SDL_Init(SDL_INIT_VIDEO)...\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("FAIL: SDL_Init: %s\n", SDL_GetError());
        return 10;
    }
    printf("  OK\n");

    nd = SDL_GetNumVideoDisplays();
    printf("Step 2: SDL_GetNumVideoDisplays() = %d\n", nd);

    if (nd <= 0) {
        printf("FAIL: no displays!\n");
        SDL_Quit();
        return 10;
    }

    printf("Step 3: SDL_CreateWindow(640x480 fullscreen)...\n");
    win = SDL_CreateWindow("Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_FULLSCREEN);
    if (!win) {
        printf("FAIL fullscreen: %s\n", SDL_GetError());
        printf("Step 3b: trying windowed...\n");
        win = SDL_CreateWindow("Test",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            320, 200, 0);
        if (!win) {
            printf("FAIL windowed: %s\n", SDL_GetError());
            SDL_Quit();
            return 10;
        }
    }
    printf("  OK -- window created!\n");

    SDL_Delay(3000);
    SDL_DestroyWindow(win);
    SDL_Quit();
    printf("PASS\n");
    return 0;
}

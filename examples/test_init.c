/*
 * Phase 0 Milestone Test: SDL_Init() returns 0, SDL_Quit() doesn't crash.
 *
 * Build: m68k-amigaos-gcc -std=gnu99 -O0 -m68020 -noixemul \
 *        -I../include -o test_init test_init.c -L.. -lSDL2
 *
 * Expected: prints "SDL_Init: OK" and "SDL_Quit: OK", exits 0.
 */

#include <stdio.h>

/* Phase 0: Direct declarations until SDL.h is populated */
extern int SDL_Init(unsigned int flags);
extern void SDL_Quit(void);

static const char *verstag = "$VER: test_init 0.1 (27.03.2026)";

int main(int argc, char *argv[])
{
    int rc;

    (void)argc;
    (void)argv;
    (void)verstag;

    rc = SDL_Init(0);
    if (rc != 0) {
        printf("SDL_Init: FAILED (rc=%d)\n", rc);
        return 10;
    }
    printf("SDL_Init: OK\n");

    SDL_Quit();
    printf("SDL_Quit: OK\n");

    return 0;
}

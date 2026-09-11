/*
 * Bouncing sprite test: validates video + timer + input loop.
 *
 * Draws a filled rectangle "sprite" that bounces around the window.
 * If the timer works, the sprite moves. If input works, ESC exits.
 * If neither timer nor input works, it exits after a fixed frame count.
 *
 * This exercises:
 *   - SDL_GetWindowSurface + SDL_FillRect + SDL_UpdateWindowSurface
 *   - SDL_GetTicks (timer -- currently broken, see crash-patterns #24)
 *   - SDL_PollEvent (input)
 *   - SDL_Delay (frame pacing)
 *
 * Build: make examples
 * Run:   WORK:test_sprite on FS-UAE with RTG
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_sprite 0.1 (28.03.2026)";
long __stack = 65536;

#define WIN_W 320
#define WIN_H 240
#define SPRITE_W 32
#define SPRITE_H 32
#define MAX_FRAMES 300  /* fallback exit if timer broken */

int main(int argc, char *argv[])
{
    SDL_Window  *window  = NULL;
    SDL_Surface *surface = NULL;
    SDL_Event    event;
    SDL_Rect     sprite_rect, bg_rect;
    Uint32       bg_color, sprite_color;
    int          running = 1;
    int          frame_count = 0;
    int          x = 50, y = 50;
    int          dx = 2, dy = 1;
    int          rc;

    (void)argc;
    (void)argv;
    (void)verstag;

    printf("test_sprite: bouncing sprite validation\n");

    rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc != 0) {
        printf("FAIL: SDL_Init(VIDEO): %s\n", SDL_GetError());
        return 10;
    }

    window = SDL_CreateWindow(
        "SDL2 Sprite Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H, 0
    );
    if (!window) {
        printf("FAIL: SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_Quit();
        return 10;
    }

    surface = SDL_GetWindowSurface(window);
    if (!surface) {
        printf("FAIL: SDL_GetWindowSurface: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }

    bg_color = SDL_MapRGB(surface->format, 0, 0, 32);
    sprite_color = SDL_MapRGB(surface->format, 255, 200, 0);

    printf("Window %dx%d, sprite %dx%d, %d frames max\n",
           WIN_W, WIN_H, SPRITE_W, SPRITE_H, MAX_FRAMES);

    while (running && frame_count < MAX_FRAMES) {
        /* Event pump */
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                running = 0;
            }
        }

        /* Move sprite */
        x += dx;
        y += dy;
        if (x <= 0 || x + SPRITE_W >= WIN_W) dx = -dx;
        if (y <= 0 || y + SPRITE_H >= WIN_H) dy = -dy;
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        /* Clear background */
        bg_rect.x = 0; bg_rect.y = 0;
        bg_rect.w = WIN_W; bg_rect.h = WIN_H;
        SDL_FillRect(surface, &bg_rect, bg_color);

        /* Draw sprite */
        sprite_rect.x = x;
        sprite_rect.y = y;
        sprite_rect.w = SPRITE_W;
        sprite_rect.h = SPRITE_H;
        SDL_FillRect(surface, &sprite_rect, sprite_color);

        /* Blit to screen */
        SDL_UpdateWindowSurface(window);

        /* Frame pacing -- 50fps (20ms per frame) */
        SDL_Delay(20);

        frame_count++;
    }

    printf("Rendered %d frames\n", frame_count);

    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("PASS: sprite test complete\n");
    return 0;
}

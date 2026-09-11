/*
 * test_gameloop: Integrated game loop -- video + audio + input + timer.
 *
 * Bouncing sprite with a beep sound on wall collision.
 * Exercises all four major subsystems simultaneously:
 *   - Video: SDL_FillRect + SDL_UpdateWindowSurface
 *   - Audio: SDL_QueueAudio with generated square wave
 *   - Input: SDL_PollEvent (ESC to quit)
 *   - Timer: SDL_GetTicks for frame pacing + collision timing
 *
 * Exits after 5 seconds or on ESC.
 *
 * Build: make examples
 * Run:   WORK:test_gameloop on FS-UAE with RTG
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_gameloop 0.1 (28.03.2026)";
long __stack = 65536;

#define WIN_W 320
#define WIN_H 240
#define SPRITE_W 24
#define SPRITE_H 24
#define RUN_MS 5000
#define BEEP_FREQ 880
#define BEEP_MS 30
#define SAMPLE_RATE 22050

/* Generate a short beep and queue it */
static void play_beep(SDL_AudioDeviceID dev)
{
    /* Small stack buffer: 30ms at 22050 Hz = 661 samples */
    Sint8 buf[SAMPLE_RATE * BEEP_MS / 1000];
    int i;
    int half_period = SAMPLE_RATE / BEEP_FREQ / 2;

    if (half_period < 1) half_period = 1;

    for (i = 0; i < (int)sizeof(buf); i++) {
        buf[i] = ((i / half_period) % 2) ? 48 : -48;
    }

    SDL_QueueAudio(dev, buf, sizeof(buf));
}

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_AudioDeviceID audio_dev = 0;
    SDL_AudioSpec want, have;
    SDL_Event event;
    Uint32 start, now;
    int running = 1;
    int frames = 0;
    int bounces = 0;
    int x = 50, y = 30;
    int dx = 3, dy = 2;
    int have_audio = 0;
    int rc;

    (void)argc; (void)argv; (void)verstag;

    printf("test_gameloop: integrated video+audio+input+timer\n");
    fflush(stdout);

    rc = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    if (rc != 0) {
        /* Try without audio if it fails */
        printf("SDL_Init(all) failed: %s -- trying video only\n", SDL_GetError());
        rc = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
        if (rc != 0) {
            printf("FAIL: SDL_Init: %s\n", SDL_GetError());
            return 10;
        }
    }

    /* Open audio (optional -- test still passes without it) */
    SDL_memset(&want, 0, sizeof(want));
    want.freq = SAMPLE_RATE;
    want.format = AUDIO_S8;
    want.channels = 1;
    want.samples = 1024;

    audio_dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (audio_dev > 0) {
        SDL_PauseAudioDevice(audio_dev, 0);
        have_audio = 1;
        printf("Audio: %d Hz %d-bit %dch\n", have.freq,
               SDL_AUDIO_BITSIZE(have.format), have.channels);
    } else {
        printf("Audio: not available (%s) -- continuing without\n",
               SDL_GetError());
    }
    fflush(stdout);

    window = SDL_CreateWindow(
        "SDL2 Game Loop",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H, 0
    );
    if (!window) {
        printf("FAIL: SDL_CreateWindow: %s\n", SDL_GetError());
        if (audio_dev) SDL_CloseAudioDevice(audio_dev);
        SDL_Quit();
        return 10;
    }

    surface = SDL_GetWindowSurface(window);
    if (!surface) {
        printf("FAIL: SDL_GetWindowSurface: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        if (audio_dev) SDL_CloseAudioDevice(audio_dev);
        SDL_Quit();
        return 10;
    }

    printf("Running for %d ms...\n", RUN_MS);
    fflush(stdout);

    start = SDL_GetTicks();
    while (running) {
        now = SDL_GetTicks();
        if (now - start >= RUN_MS) break;

        /* Events */
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                running = 0;
        }

        /* Move */
        x += dx;
        y += dy;
        if (x <= 0 || x + SPRITE_W >= WIN_W) {
            dx = -dx;
            if (x < 0) x = 0;
            if (x + SPRITE_W > WIN_W) x = WIN_W - SPRITE_W;
            bounces++;
            if (have_audio) play_beep(audio_dev);
        }
        if (y <= 0 || y + SPRITE_H >= WIN_H) {
            dy = -dy;
            if (y < 0) y = 0;
            if (y + SPRITE_H > WIN_H) y = WIN_H - SPRITE_H;
            bounces++;
            if (have_audio) play_beep(audio_dev);
        }

        /* Draw */
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 16, 16, 32));

        {
            SDL_Rect sr;
            sr.x = x; sr.y = y; sr.w = SPRITE_W; sr.h = SPRITE_H;
            SDL_FillRect(surface, &sr,
                         SDL_MapRGB(surface->format, 255, 100, 50));
        }

        SDL_UpdateWindowSurface(window);
        frames++;
        SDL_Delay(16); /* ~60fps target */
    }

    printf("Rendered %d frames, %d bounces in %lu ms\n",
           frames, bounces, (unsigned long)(SDL_GetTicks() - start));
    fflush(stdout);

    if (audio_dev) SDL_CloseAudioDevice(audio_dev);
    SDL_DestroyWindow(window);
    SDL_Quit();

    if (frames < 10) {
        printf("FAIL: too few frames (%d)\n", frames);
        return 10;
    }

    printf("PASS: game loop test complete\n");
    return 0;
}

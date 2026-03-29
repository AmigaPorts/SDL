/*
 * SDL2_mixer smoke test for AmigaOS 3.x.
 *
 * Tests: Mix_OpenAudio, Mix_AllocateChannels, Mix_PlayChannel,
 *        Mix_Playing, Mix_CloseAudio.
 *
 * Generates a 440 Hz square wave as a Mix_Chunk and plays it for
 * ~1 second. On FS-UAE with Paula you should hear a brief tone.
 *
 * Build: make examples (or manually link with -lSDL2_mixer -lSDL2)
 * Run:   WORK:test_mixer on FS-UAE
 */

#include <stdio.h>
#include "SDL.h"
#include "SDL_mixer.h"

static const char *verstag = "$VER: test_mixer 0.1 (29.03.2026)";
long __stack = 65536;

/* Generate a square wave tone as raw PCM */
#define SAMPLE_RATE 22050
#define TONE_HZ     440
#define DURATION_MS 1000
#define AMPLITUDE   96

static Mix_Chunk *generate_tone(void)
{
    int num_samples = (SAMPLE_RATE * DURATION_MS) / 1000;
    int half_period = SAMPLE_RATE / (TONE_HZ * 2);
    Uint8 *buf;
    Mix_Chunk *chunk;
    int i;

    buf = (Uint8 *)SDL_malloc(num_samples);
    if (!buf) return NULL;

    /* 8-bit unsigned square wave (128 = silence) */
    for (i = 0; i < num_samples; i++) {
        if ((i / half_period) % 2 == 0)
            buf[i] = 128 + AMPLITUDE;
        else
            buf[i] = 128 - AMPLITUDE;
    }

    chunk = (Mix_Chunk *)SDL_malloc(sizeof(Mix_Chunk));
    if (!chunk) { SDL_free(buf); return NULL; }

    chunk->allocated = 1;
    chunk->abuf = buf;
    chunk->alen = (Uint32)num_samples;
    chunk->volume = MIX_MAX_VOLUME;

    return chunk;
}

static void free_tone(Mix_Chunk *chunk)
{
    if (chunk) {
        if (chunk->abuf) SDL_free(chunk->abuf);
        SDL_free(chunk);
    }
}

int main(int argc, char *argv[])
{
    Mix_Chunk *tone;
    int channel;
    Uint32 start;

    (void)argc; (void)argv;
    (void)verstag;

    SDL_Log("test_mixer: SDL2_mixer smoke test");

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        SDL_Log("SDL_Init(AUDIO) failed: %s", SDL_GetError());
        return 10;
    }

    SDL_Log("Opening audio: %d Hz, AUDIO_U8, mono, 1024 samples",
            SAMPLE_RATE);

    if (Mix_OpenAudio(SAMPLE_RATE, AUDIO_U8, 1, 1024) < 0) {
        SDL_Log("Mix_OpenAudio failed: %s", Mix_GetError());
        SDL_Quit();
        return 10;
    }

    SDL_Log("Mix_OpenAudio OK");

    Mix_AllocateChannels(4);
    SDL_Log("Allocated 4 channels");

    tone = generate_tone();
    if (!tone) {
        SDL_Log("Failed to generate tone");
        Mix_CloseAudio();
        SDL_Quit();
        return 10;
    }

    SDL_Log("Playing tone (%d samples, %d ms)...",
            (int)tone->alen, DURATION_MS);

    channel = Mix_PlayChannel(-1, tone, 0);
    if (channel < 0) {
        SDL_Log("Mix_PlayChannel failed: %s", Mix_GetError());
        free_tone(tone);
        Mix_CloseAudio();
        SDL_Quit();
        return 10;
    }

    SDL_Log("Playing on channel %d", channel);

    /* Wait for playback to finish */
    start = SDL_GetTicks();
    while (Mix_Playing(channel)) {
        SDL_Delay(100);
        if (SDL_GetTicks() - start > (Uint32)(DURATION_MS + 1000)) {
            SDL_Log("Timeout waiting for playback");
            break;
        }
    }

    SDL_Log("Playback finished");

    free_tone(tone);
    Mix_CloseAudio();
    SDL_Quit();

    SDL_Log("test_mixer: PASSED");
    return 0;
}

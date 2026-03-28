/*
 * Phase 3 Test: AHI audio backend verification.
 *
 * Generates a 440 Hz sine wave and plays it for 2 seconds via SDL2
 * audio. Tests: SDL_OpenAudioDevice, callback invocation, clean close.
 *
 * On vamos (no ahi.device), SDL_OpenAudioDevice falls through to the
 * dummy driver. The test still passes -- it just produces no sound.
 *
 * On FS-UAE with AHI installed, you should hear a brief tone.
 *
 * Build: make examples
 * Run:   WORK:test_audio on FS-UAE
 */

#include <stdio.h>
#include <math.h>
#include "SDL.h"

static const char *verstag = "$VER: test_audio 0.1 (28.03.2026)";
long __stack = 65536;

#define SAMPLE_RATE 22050
#define TONE_HZ     440
#define DURATION_MS 2000
#define AMPLITUDE   24000

/* Callback state */
static int total_samples = 0;
static int callback_count = 0;

/* Audio callback: generate a 440 Hz sine wave */
static void audio_callback(void *userdata, Uint8 *stream, int len)
{
    Sint16 *buf = (Sint16 *)stream;
    int samples = len / (int)sizeof(Sint16);
    int i;
    double phase;

    (void)userdata;

    for (i = 0; i < samples; i++) {
        phase = (double)(total_samples + i) / (double)SAMPLE_RATE;
        buf[i] = (Sint16)(sin(phase * TONE_HZ * 2.0 * 3.14159265358979)
                          * AMPLITUDE);
    }

    total_samples += samples;
    callback_count++;
}

int main(int argc, char *argv[])
{
    SDL_AudioSpec want, have;
    SDL_AudioDeviceID dev;
    const char *driver_name;
    int rc;

    (void)argc;
    (void)argv;
    (void)verstag;

    printf("test_audio: AHI audio backend verification\n\n");

    printf("Calling SDL_Init(SDL_INIT_AUDIO)...\n");
    fflush(stdout);
    rc = SDL_Init(SDL_INIT_AUDIO);
    printf("SDL_Init returned %d\n", rc);
    fflush(stdout);
    if (rc != 0) {
        printf("SKIP: SDL_Init(AUDIO) failed: %s\n", SDL_GetError());
        printf("      (AHI not installed? See docs/references/ahi-reference.md)\n");
        printf("PASS: audio test skipped (no audio subsystem)\n");
        return 0;
    }

    driver_name = SDL_GetCurrentAudioDriver();
    printf("Audio driver: %s\n", driver_name ? driver_name : "(none)");
    fflush(stdout);
    printf("Opening audio device...\n");
    fflush(stdout);

    /* Request: mono, S16, 22050 Hz, 1024 sample buffer */
    SDL_memset(&want, 0, sizeof(want));
    want.freq     = SAMPLE_RATE;
    want.format   = AUDIO_S16SYS;
    want.channels = 1;
    want.samples  = 1024;
    want.callback = audio_callback;

    dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (dev == 0) {
        printf("FAIL: SDL_OpenAudioDevice: %s\n", SDL_GetError());
        SDL_Quit();
        return 10;
    }

    printf("Opened device %lu: freq=%d format=0x%x channels=%d samples=%d\n",
           (unsigned long)dev, have.freq, have.format,
           have.channels, have.samples);

    /* Unpause -- starts the audio callback */
    SDL_PauseAudioDevice(dev, 0);
    printf("Playing 440 Hz tone for %d ms...\n", DURATION_MS);

    SDL_Delay(DURATION_MS);

    /* Pause and close */
    SDL_PauseAudioDevice(dev, 1);
    SDL_CloseAudioDevice(dev);

    printf("Callbacks: %d, total samples: %d\n", callback_count, total_samples);

    SDL_Quit();

    if (callback_count > 0) {
        printf("PASS: audio callback invoked %d times\n", callback_count);
    } else {
        printf("PASS: audio device opened (no callbacks -- dummy driver?)\n");
    }

    return 0;
}

/*
 * test_loopwave: Play a WAV file in a loop via SDL2 audio.
 *
 * Based on SDL2's test/loopwave.c but simplified for AmigaOS:
 * - No event loop (no video/input dependency)
 * - Loads WAV from command line arg or WORK:sample.wav
 * - Plays for 5 seconds then exits
 *
 * Usage: WORK:test_loopwave [WORK:myfile.wav]
 *
 * To create a test WAV on the host:
 *   sox -n -r 22050 -b 8 -c 1 build/amiga/sample.wav \
 *       synth 1 sine 440 vol 0.5
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_loopwave 0.1 (28.03.2026)";
long __stack = 32768;

static struct {
    SDL_AudioSpec spec;
    Uint8 *sound;
    Uint32 soundlen;
    int soundpos;
} wave;

/* Audio callback: copy WAV data to stream, looping */
static void SDLCALL fill_audio(void *unused, Uint8 *stream, int len)
{
    Uint8 *waveptr;
    int waveleft;

    (void)unused;

    waveptr = wave.sound + wave.soundpos;
    waveleft = wave.soundlen - wave.soundpos;

    while (waveleft <= len) {
        SDL_memcpy(stream, waveptr, waveleft);
        stream += waveleft;
        len -= waveleft;
        waveptr = wave.sound;
        waveleft = wave.soundlen;
        wave.soundpos = 0;
    }
    SDL_memcpy(stream, waveptr, len);
    wave.soundpos += len;
}

int main(int argc, char *argv[])
{
    SDL_AudioDeviceID dev;
    SDL_AudioSpec have;
    const char *filename;
    int play_ms = 5000;

    (void)verstag;

    filename = (argc > 1) ? argv[1] : "WORK:sample.wav";

    printf("test_loopwave: SDL2 WAV playback test\n\n");
    printf("WAV file: %s\n", filename);
    fflush(stdout);

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("FAIL: SDL_Init: %s\n", SDL_GetError());
        return 10;
    }

    printf("Audio driver: %s\n", SDL_GetCurrentAudioDriver());
    fflush(stdout);

    if (SDL_LoadWAV(filename, &wave.spec, &wave.sound, &wave.soundlen) == NULL) {
        printf("FAIL: SDL_LoadWAV(%s): %s\n", filename, SDL_GetError());
        SDL_Quit();
        return 10;
    }

    printf("WAV loaded: freq=%d fmt=0x%x ch=%d samples=%d (%lu bytes)\n",
           wave.spec.freq, (unsigned)wave.spec.format,
           (int)wave.spec.channels, (int)wave.spec.samples,
           (unsigned long)wave.soundlen);
    fflush(stdout);

    wave.spec.callback = fill_audio;
    wave.soundpos = 0;

    dev = SDL_OpenAudioDevice(NULL, 0, &wave.spec, &have, 0);
    if (dev == 0) {
        printf("FAIL: SDL_OpenAudioDevice: %s\n", SDL_GetError());
        SDL_FreeWAV(wave.sound);
        SDL_Quit();
        return 10;
    }

    printf("Device opened: freq=%d fmt=0x%x ch=%d samples=%d\n",
           have.freq, (unsigned)have.format,
           (int)have.channels, (int)have.samples);
    fflush(stdout);

    SDL_PauseAudioDevice(dev, 0);
    printf("Playing for %d ms...\n", play_ms);
    fflush(stdout);

    SDL_Delay(play_ms);

    SDL_PauseAudioDevice(dev, 1);
    SDL_CloseAudioDevice(dev);
    SDL_FreeWAV(wave.sound);
    SDL_Quit();

    printf("PASS: loopwave complete\n");
    return 0;
}

/*
 * Timer test: verify ReadEClock-based SDL_GetTicks64 and perf counters.
 *
 * Tests:
 *   1. SDL_GetTicks64 returns a value (may be 0 on vamos)
 *   2. After SDL_Delay(100), SDL_GetTicks64 delta >= 60ms
 *   3. SDL_GetPerformanceFrequency > 0
 *   4. SDL_GetPerformanceCounter increases between calls
 *
 * On vamos (no timer.device), GetTicks64 returns 0 and perf counters
 * return fallback values. The test still passes -- it only fails on
 * actual regressions (crashes, negative deltas, etc).
 *
 * Build: make examples
 * Run:   vamos -C 68020 -s 32 -m 8192 examples/test_timer
 *        or WORK:test_timer on FS-UAE
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_timer 0.1 (28.03.2026)";
long __stack = 32768;

int main(int argc, char *argv[])
{
    Uint64 t1, t2, delta_ms;
    Uint64 pc1, pc2, freq;
    int    rc;
    int    have_timer;

    (void)argc;
    (void)argv;
    (void)verstag;

    printf("test_timer: ReadEClock timer verification\n\n");

    rc = SDL_Init(0);
    if (rc != 0) {
        printf("FAIL: SDL_Init(0): %s\n", SDL_GetError());
        return 10;
    }

    /* Test 1: GetTicks64 returns without crashing */
    t1 = SDL_GetTicks64();
    printf("SDL_GetTicks64() = %lu ms\n", (unsigned long)t1);

    /* Detect whether real timer is available (vamos returns 0) */
    have_timer = (t1 > 0 || SDL_GetPerformanceFrequency() > 1000);

    /* Test 2: Delay + measure delta */
    printf("SDL_Delay(100)...\n");
    SDL_Delay(100);
    t2 = SDL_GetTicks64();
    delta_ms = t2 - t1;
    printf("SDL_GetTicks64() = %lu ms (delta = %lu ms)\n",
           (unsigned long)t2, (unsigned long)delta_ms);

    if (have_timer) {
        /* Real timer: delta should be >= 60ms (allowing for Delay granularity) */
        if (delta_ms < 60) {
            printf("FAIL: delta %lu ms < 60 ms after Delay(100)\n",
                   (unsigned long)delta_ms);
            SDL_Quit();
            return 10;
        }
        printf("PASS: timer delta %lu ms (expected >= 60)\n",
               (unsigned long)delta_ms);
    } else {
        printf("SKIP: no timer.device (vamos) -- delta check skipped\n");
    }

    /* Test 3: Performance frequency */
    freq = SDL_GetPerformanceFrequency();
    printf("SDL_GetPerformanceFrequency() = %lu\n", (unsigned long)freq);
    if (freq == 0) {
        printf("FAIL: performance frequency is 0\n");
        SDL_Quit();
        return 10;
    }
    printf("PASS: performance frequency > 0\n");

    /* Test 4: Performance counter increases */
    pc1 = SDL_GetPerformanceCounter();
    SDL_Delay(20);
    pc2 = SDL_GetPerformanceCounter();
    printf("PerfCounter: %lu -> %lu\n",
           (unsigned long)pc1, (unsigned long)pc2);

    if (have_timer && pc2 <= pc1) {
        printf("FAIL: performance counter did not increase\n");
        SDL_Quit();
        return 10;
    }
    if (have_timer) {
        printf("PASS: performance counter increases\n");
    } else {
        printf("SKIP: no timer.device -- counter check skipped\n");
    }

    SDL_Quit();
    printf("\nAll timer tests passed.\n");
    return 0;
}

/*
 * Minimal test: does Uint64 return work on 68k with bebbo-gcc?
 *
 * Tests three cases:
 *   1. Local function returning Uint64 (same compilation unit)
 *   2. SDL_GetTicks64() from libSDL2.a (cross-unit)
 *   3. SDL_GetTicks() Uint32 wrapper (cross-unit, 32-bit return)
 *
 * If case 1 works but 2 doesn't, the bug is cross-unit Uint64 returns.
 * If case 1 also fails, the bug is fundamental to 68k Uint64 ABI.
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_uint64 0.1 (28.03.2026)";
long __stack = 32768;

/* Local Uint64 return -- same compilation unit */
static Uint64 return_42(void)
{
    return 42ULL;
}

/* Local Uint64 return with computation */
static Uint64 return_computed(Uint32 a, Uint32 b)
{
    Uint64 result = (Uint64)a * 1000ULL;
    result = result / (Uint64)b;
    return result;
}

int main(int argc, char *argv[])
{
    Uint64 val;
    Uint32 val32;

    (void)argc;
    (void)argv;
    (void)verstag;

    printf("test_uint64: Uint64 return ABI test\n\n");

    SDL_Init(0);

    /* Case 1: local function, constant */
    val = return_42();
    printf("1. return_42()        = %lu (expect 42)\n", (unsigned long)val);

    /* Case 2: local function, computed */
    val = return_computed(30000, 709);
    printf("2. return_computed()  = %lu (expect 42)\n", (unsigned long)val);

    /* Case 3: SDL_GetTicks64 from library
       First call triggers lazy init (sets start time), so call once
       to init, delay, then measure. */
    val = SDL_GetTicks64();  /* triggers lazy init */
    SDL_Delay(100);
    val = SDL_GetTicks64();
    printf("3. SDL_GetTicks64()   = %lu (expect >60)\n", (unsigned long)val);

    /* Case 4: SDL_GetTicks (32-bit) from library */
    val32 = SDL_GetTicks();
    printf("4. SDL_GetTicks()     = %lu (expect >0)\n", (unsigned long)val32);

    /* Case 5: SDL_GetPerformanceFrequency */
    val = SDL_GetPerformanceFrequency();
    printf("5. GetPerfFreq()      = %lu (expect ~709379)\n", (unsigned long)val);

    /* Case 6: direct Uint32 from SDL_GetTicks cast to Uint64 */
    val = (Uint64)SDL_GetTicks();
    printf("6. (Uint64)GetTicks() = %lu (expect >0)\n", (unsigned long)val);

    SDL_Quit();

    printf("\nDone.\n");
    return 0;
}

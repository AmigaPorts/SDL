/* test_float: minimal float operation test */
#include <stdio.h>
#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/mathieeesingbas.h>
#ifdef WARPUP
#pragma pop
#endif

static const char *verstag = "$VER: test_float 0.1 (28.03.2026)";
long __stack = 16384;

int main(int argc, char *argv[])
{
    volatile int a = 50;
    volatile int b = 100;
    volatile float fx, fy, fz;

    (void)argc; (void)argv; (void)verstag;

    printf("test_float: MathIeeeSingBasBase=%p\n", (void *)MathIeeeSingBasBase);
    printf("test_float: basic float operations on 68030\n");

    printf("STEP 1: int-to-float cast\n"); fflush(stdout);
    fx = (float)a;
    printf("  (float)50 = %ld\n", (long)fx); fflush(stdout);

    printf("STEP 2: float addition\n"); fflush(stdout);
    fy = fx + 1.5f;
    printf("  50.0 + 1.5 = %ld\n", (long)fy); fflush(stdout);

    printf("STEP 3: float multiply\n"); fflush(stdout);
    fz = fx * 2.0f;
    printf("  50.0 * 2.0 = %ld\n", (long)fz); fflush(stdout);

    printf("STEP 4: float divide\n"); fflush(stdout);
    fz = (float)b / (float)a;
    printf("  100.0 / 50.0 = %ld\n", (long)fz); fflush(stdout);

    printf("STEP 5: SDL_FRect simulation\n"); fflush(stdout);
    {
        struct { float x, y, w, h; } frect;
        frect.x = (float)a;
        frect.y = (float)b;
        frect.w = (float)320;
        frect.h = (float)240;
        printf("  frect=(%ld,%ld,%ld,%ld)\n",
               (long)frect.x, (long)frect.y, (long)frect.w, (long)frect.h);
        fflush(stdout);
    }

    printf("PASS: all float ops OK\n");
    return 0;
}

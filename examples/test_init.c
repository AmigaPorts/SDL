/*
 * Phase 0 Milestone Test: SDL_Init/SDL_Quit verification.
 *
 * Tests:
 *   1. SDL_Init(0) returns 0 (core init, no subsystems)
 *   2. SDL_Quit() after Init(0) completes cleanly
 *   3. SDL_GetError() returns non-NULL
 *   4. Double SDL_Init(0) is idempotent
 *   5. SDL_Quit() without prior SDL_Init() doesn't crash
 *   6. SDL_Init(SDL_INIT_VIDEO) doesn't crash
 *   7. Mutex create/lock/unlock/destroy works (single-task)
 *
 * Build: make examples
 * Run:   vamos -C 68020 -s 65536 examples/test_init
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_init 0.1 (27.03.2026)";
long __stack = 65536;

static int tests_run = 0;
static int tests_passed = 0;

static void test(const char *name, int condition)
{
    tests_run++;
    if (condition) {
        tests_passed++;
        printf("  PASS: %s\n", name);
    } else {
        printf("  FAIL: %s\n", name);
    }
}

int main(int argc, char *argv[])
{
    int rc;
    SDL_mutex *mtx;

    (void)argc;
    (void)argv;
    (void)verstag;

    printf("SDL2 Phase 0 Test Suite\n");
    printf("=======================\n");

    /* Test 1: SDL_Init(0) */
    rc = SDL_Init(0);
    test("SDL_Init(0) returns 0", rc == 0);

    /* Test 2: SDL_Quit after Init(0) */
    SDL_Quit();
    test("SDL_Quit() after Init(0)", 1); /* if we got here, it didn't crash */

    /* Test 3: SDL_GetError returns non-NULL */
    test("SDL_GetError() non-NULL", SDL_GetError() != NULL);

    /* Test 4: Double SDL_Init(0) */
    rc = SDL_Init(0);
    test("SDL_Init(0) first call", rc == 0);
    rc = SDL_Init(0);
    test("SDL_Init(0) second call (idempotent)", rc == 0);
    SDL_Quit();

    /* Test 5: SDL_Quit without prior Init */
    SDL_Quit();
    test("SDL_Quit() without Init", 1); /* didn't crash */

    /* Test 6: SDL_Init(SDL_INIT_VIDEO) */
    rc = SDL_Init(SDL_INIT_VIDEO);
    /* May return 0 (stub success) or -1 (not available) -- both OK */
    test("SDL_Init(VIDEO) doesn't crash", 1);
    if (rc == 0) {
        printf("    (video init succeeded -- stub returned OK)\n");
    } else {
        printf("    (video init returned %d: %s)\n", rc, SDL_GetError());
    }
    SDL_Quit();

    /* Test 7: Mutex operations (single-task) */
    SDL_Init(0);
    mtx = SDL_CreateMutex();
    test("SDL_CreateMutex() non-NULL", mtx != NULL);
    if (mtx) {
        rc = SDL_LockMutex(mtx);
        test("SDL_LockMutex() returns 0", rc == 0);
        rc = SDL_UnlockMutex(mtx);
        test("SDL_UnlockMutex() returns 0", rc == 0);
        SDL_DestroyMutex(mtx);
        test("SDL_DestroyMutex() didn't crash", 1);
    }
    SDL_Quit();

    printf("\n%d/%d tests passed\n", tests_passed, tests_run);
    return (tests_passed == tests_run) ? 0 : 10;
}

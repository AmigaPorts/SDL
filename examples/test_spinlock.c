/* Diagnose the FS-UAE SDL_Init(0) hang step by step. */
#include <stdio.h>
#include "SDL.h"
#include "SDL_atomic.h"

static const char *verstag = "$VER: test_spinlock 0.2 (27.03.2026)";
long __stack = 65536;

int main(int argc, char *argv[])
{
    SDL_SpinLock lock = 0;
    SDL_atomic_t atom;
    int rc;

    (void)argc; (void)argv; (void)verstag;

    printf("=== Spinlock test ===\n"); fflush(stdout);
    SDL_AtomicLock(&lock);
    printf("Lock OK\n"); fflush(stdout);
    SDL_AtomicUnlock(&lock);
    printf("Unlock OK\n"); fflush(stdout);

    printf("\n=== AtomicCAS test ===\n"); fflush(stdout);
    atom.value = 0;
    rc = SDL_AtomicCAS(&atom, 0, 42);
    printf("CAS(0->42) returned %d, value=%d\n", rc, atom.value); fflush(stdout);

    printf("\n=== AtomicAdd test ===\n"); fflush(stdout);
    atom.value = 0;
    rc = SDL_AtomicAdd(&atom, 1);
    printf("AtomicAdd returned %d, value=%d\n", rc, atom.value); fflush(stdout);

    printf("\n=== SDL_SetError test ===\n"); fflush(stdout);
    SDL_SetError("test error");
    printf("SetError OK: %s\n", SDL_GetError()); fflush(stdout);

    printf("\n=== SDL_ClearError test ===\n"); fflush(stdout);
    SDL_ClearError();
    printf("ClearError OK\n"); fflush(stdout);

    printf("\n=== SDL_Init(0) ===\n"); fflush(stdout);
    rc = SDL_Init(0);
    printf("SDL_Init(0) returned %d\n", rc); fflush(stdout);
    if (rc == 0) {
        SDL_Quit();
        printf("SDL_Quit() done\n");
    } else {
        printf("Error: %s\n", SDL_GetError());
    }
    fflush(stdout);

    return 0;
}

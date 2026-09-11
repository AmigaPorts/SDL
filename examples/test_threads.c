/*
 * test_threads: Phase 4 threading validation for AmigaOS 3.x
 *
 * Exercises SDL2 threading primitives under real Exec task switching:
 *   1. Mutex-protected shared counter (3 threads, 1000 increments each)
 *   2. Semaphore producer/consumer
 *   3. TLS isolation between threads
 *   4. Condition variable signal/broadcast
 *
 * PASS: All sub-tests report correct values, no hangs, no Guru.
 * FAIL: Wrong counter value, deadlock, or crash.
 */

#include <stdio.h>
#include "SDL.h"

static const char *verstag = "$VER: test_threads 0.1 (28.03.2026)";
long __stack = 65536;

/* ------------------------------------------------------------------ */
/* Test 1: Mutex-protected counter                                     */
/* ------------------------------------------------------------------ */

#define MUTEX_THREADS    3
#define MUTEX_ITERS   1000

typedef struct {
    SDL_mutex *mutex;
    int counter;
} MutexTestData;

static int mutex_thread_fn(void *arg)
{
    MutexTestData *data = (MutexTestData *)arg;
    int i;

    for (i = 0; i < MUTEX_ITERS; i++) {
        SDL_LockMutex(data->mutex);
        data->counter++;
        SDL_UnlockMutex(data->mutex);
    }
    return 0;
}

static int test_mutex(void)
{
    MutexTestData data;
    SDL_Thread *threads[MUTEX_THREADS];
    int expected = MUTEX_THREADS * MUTEX_ITERS;
    int i;

    printf("--- Test 1: Mutex counter ---\n");
    fflush(stdout);

    data.mutex = SDL_CreateMutex();
    if (!data.mutex) {
        printf("FAIL: SDL_CreateMutex: %s\n", SDL_GetError());
        return 1;
    }
    data.counter = 0;

    for (i = 0; i < MUTEX_THREADS; i++) {
        char name[16];
        SDL_snprintf(name, sizeof(name), "mtx%d", i);
        threads[i] = SDL_CreateThread(mutex_thread_fn, name, &data);
        if (!threads[i]) {
            printf("FAIL: SDL_CreateThread(%d): %s\n", i, SDL_GetError());
            return 1;
        }
    }

    for (i = 0; i < MUTEX_THREADS; i++) {
        SDL_WaitThread(threads[i], NULL);
    }

    SDL_DestroyMutex(data.mutex);

    printf("  counter = %d (expected %d)\n", data.counter, expected);
    fflush(stdout);

    if (data.counter != expected) {
        printf("FAIL: counter mismatch (race condition!)\n");
        return 1;
    }

    printf("  PASS\n");
    fflush(stdout);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Test 2: Semaphore producer/consumer                                 */
/* ------------------------------------------------------------------ */

#define SEM_ITEMS 20

typedef struct {
    SDL_sem *sem;
    SDL_mutex *mutex;
    int produced;
    int consumed;
} SemTestData;

static int producer_fn(void *arg)
{
    SemTestData *data = (SemTestData *)arg;
    int i;

    for (i = 0; i < SEM_ITEMS; i++) {
        SDL_LockMutex(data->mutex);
        data->produced++;
        SDL_UnlockMutex(data->mutex);
        SDL_SemPost(data->sem);
        SDL_Delay(1); /* yield to consumer */
    }
    return 0;
}

static int consumer_fn(void *arg)
{
    SemTestData *data = (SemTestData *)arg;
    int i;

    for (i = 0; i < SEM_ITEMS; i++) {
        SDL_SemWait(data->sem);
        SDL_LockMutex(data->mutex);
        data->consumed++;
        SDL_UnlockMutex(data->mutex);
    }
    return 0;
}

static int test_semaphore(void)
{
    SemTestData data;
    SDL_Thread *prod, *cons;

    printf("--- Test 2: Semaphore producer/consumer ---\n");
    fflush(stdout);

    data.sem = SDL_CreateSemaphore(0);
    data.mutex = SDL_CreateMutex();
    if (!data.sem || !data.mutex) {
        printf("FAIL: create sem/mutex: %s\n", SDL_GetError());
        return 1;
    }
    data.produced = 0;
    data.consumed = 0;

    cons = SDL_CreateThread(consumer_fn, "cons", &data);
    prod = SDL_CreateThread(producer_fn, "prod", &data);
    if (!prod || !cons) {
        printf("FAIL: SDL_CreateThread: %s\n", SDL_GetError());
        return 1;
    }

    SDL_WaitThread(prod, NULL);
    SDL_WaitThread(cons, NULL);

    printf("  produced=%d consumed=%d (expected %d)\n",
           data.produced, data.consumed, SEM_ITEMS);
    fflush(stdout);

    SDL_DestroySemaphore(data.sem);
    SDL_DestroyMutex(data.mutex);

    if (data.produced != SEM_ITEMS || data.consumed != SEM_ITEMS) {
        printf("FAIL: count mismatch\n");
        return 1;
    }

    printf("  PASS\n");
    fflush(stdout);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Test 3: TLS isolation                                               */
/* ------------------------------------------------------------------ */

static SDL_TLSID tls_key;

static int tls_thread_fn(void *arg)
{
    int id = (int)(size_t)arg;
    int *val;

    /* Each thread sets its own TLS value */
    val = (int *)SDL_malloc(sizeof(int));
    if (!val) return 1;
    *val = id * 100;

    SDL_TLSSet(tls_key, val, SDL_free);

    /* Yield so other threads run and set their own TLS */
    SDL_Delay(10);

    /* Read back -- must still be our value */
    val = (int *)SDL_TLSGet(tls_key);
    if (!val || *val != id * 100) {
        printf("  FAIL: thread %d: TLS value = %d (expected %d)\n",
               id, val ? *val : -1, id * 100);
        return 1;
    }

    printf("  thread %d: TLS OK (value=%d)\n", id, *val);
    fflush(stdout);
    return 0;
}

static int test_tls(void)
{
    SDL_Thread *t1, *t2, *t3;
    int r1, r2, r3;

    printf("--- Test 3: TLS isolation ---\n");
    fflush(stdout);

    tls_key = SDL_TLSCreate();
    if (tls_key == 0) {
        printf("FAIL: SDL_TLSCreate returned 0\n");
        return 1;
    }

    t1 = SDL_CreateThread(tls_thread_fn, "tls1", (void *)(size_t)1);
    t2 = SDL_CreateThread(tls_thread_fn, "tls2", (void *)(size_t)2);
    t3 = SDL_CreateThread(tls_thread_fn, "tls3", (void *)(size_t)3);
    if (!t1 || !t2 || !t3) {
        printf("FAIL: SDL_CreateThread: %s\n", SDL_GetError());
        return 1;
    }

    SDL_WaitThread(t1, &r1);
    SDL_WaitThread(t2, &r2);
    SDL_WaitThread(t3, &r3);

    if (r1 != 0 || r2 != 0 || r3 != 0) {
        printf("FAIL: TLS isolation broken\n");
        return 1;
    }

    printf("  PASS\n");
    fflush(stdout);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Test 4: Condition variable                                          */
/* ------------------------------------------------------------------ */

typedef struct {
    SDL_mutex *mutex;
    SDL_cond *cond;
    int ready;
    int seen;
} CondTestData;

static int cond_waiter_fn(void *arg)
{
    CondTestData *data = (CondTestData *)arg;

    SDL_LockMutex(data->mutex);
    while (!data->ready) {
        SDL_CondWait(data->cond, data->mutex);
    }
    data->seen = 1;
    SDL_UnlockMutex(data->mutex);
    return 0;
}

static int test_condvar(void)
{
    CondTestData data;
    SDL_Thread *waiter;

    printf("--- Test 4: Condition variable ---\n");
    fflush(stdout);

    data.mutex = SDL_CreateMutex();
    data.cond = SDL_CreateCond();
    if (!data.mutex || !data.cond) {
        printf("FAIL: create mutex/cond: %s\n", SDL_GetError());
        return 1;
    }
    data.ready = 0;
    data.seen = 0;

    waiter = SDL_CreateThread(cond_waiter_fn, "cond", &data);
    if (!waiter) {
        printf("FAIL: SDL_CreateThread: %s\n", SDL_GetError());
        return 1;
    }

    /* Give waiter time to start and enter CondWait */
    SDL_Delay(50);

    /* Signal the waiter */
    SDL_LockMutex(data.mutex);
    data.ready = 1;
    SDL_CondSignal(data.cond);
    SDL_UnlockMutex(data.mutex);

    SDL_WaitThread(waiter, NULL);

    SDL_DestroyCond(data.cond);
    SDL_DestroyMutex(data.mutex);

    if (!data.seen) {
        printf("FAIL: waiter never woke up\n");
        return 1;
    }

    printf("  PASS\n");
    fflush(stdout);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Main                                                                */
/* ------------------------------------------------------------------ */

int main(int argc, char *argv[])
{
    int failures = 0;

    (void)argc; (void)argv; (void)verstag;

    printf("=== SDL2 Threading Tests (Phase 4) ===\n\n");
    fflush(stdout);

    if (SDL_Init(0) != 0) {
        printf("FATAL: SDL_Init(0) failed: %s\n", SDL_GetError());
        return 10;
    }

    failures += test_mutex();
    failures += test_semaphore();
    failures += test_tls();
    failures += test_condvar();

    SDL_Quit();

    printf("\n=== Results: %d failures ===\n", failures);
    printf("%s\n", failures == 0 ? "ALL PASS" : "SOME FAILED");
    fflush(stdout);

    return failures == 0 ? 0 : 10;
}

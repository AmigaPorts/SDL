/*
  SDL2 Thread-Local Storage -- AmigaOS 3.x
  Uses FindTask(NULL)->tc_UserData as a task-keyed lookup.

  Design: Maintains a linked list of (task, tls_data) pairs protected
  by a SignalSemaphore. FindTask(NULL) is O(1) on AmigaOS, so lookup
  is fast. The list is small (one entry per active thread).
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "../SDL_thread_c.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <exec/tasks.h>
#ifdef WARPUP
#pragma pop
#endif

/* TLS entry: one per task that has TLS data */
typedef struct OS3_TLSEntry {
    struct OS3_TLSEntry *next;
    struct Task *task;
    SDL_TLSData *data;
} OS3_TLSEntry;

static struct SignalSemaphore tls_lock;
static OS3_TLSEntry *tls_list = NULL;
static int tls_initialized = 0;

void SDL_SYS_InitTLSData(void)
{
    if (!tls_initialized) {
        InitSemaphore(&tls_lock);
        tls_list = NULL;
        tls_initialized = 1;
    }
}

static OS3_TLSEntry *OS3_FindTLSEntry(struct Task *task)
{
    OS3_TLSEntry *entry;
    for (entry = tls_list; entry != NULL; entry = entry->next) {
        if (entry->task == task) {
            return entry;
        }
    }
    return NULL;
}

SDL_TLSData *SDL_SYS_GetTLSData(void)
{
    struct Task *me = FindTask(NULL);
    SDL_TLSData *data = NULL;
    OS3_TLSEntry *entry;

    /* Lazy init: SDL_TLSGet can be called before SDL_InitTLSData
       (e.g. from SDL_GetErrBuf -> SDL_SetError path).
       ObtainSemaphore on an uninitialized SignalSemaphore deadlocks. */
    if (!tls_initialized) {
        SDL_SYS_InitTLSData();
    }

    ObtainSemaphore(&tls_lock);
    entry = OS3_FindTLSEntry(me);
    if (entry != NULL) {
        data = entry->data;
    }
    ReleaseSemaphore(&tls_lock);

    return data;
}

int SDL_SYS_SetTLSData(SDL_TLSData *data)
{
    struct Task *me = FindTask(NULL);
    OS3_TLSEntry *entry;

    if (!tls_initialized) {
        SDL_SYS_InitTLSData();
    }

    ObtainSemaphore(&tls_lock);
    entry = OS3_FindTLSEntry(me);

    if (entry != NULL) {
        /* Update existing entry */
        entry->data = data;
    } else {
        /* Create new entry */
        entry = (OS3_TLSEntry *)SDL_calloc(1, sizeof(*entry));
        if (entry == NULL) {
            ReleaseSemaphore(&tls_lock);
            return SDL_OutOfMemory();
        }
        entry->task = me;
        entry->data = data;
        entry->next = tls_list;
        tls_list = entry;
    }
    ReleaseSemaphore(&tls_lock);

    return 0;
}

void SDL_SYS_QuitTLSData(void)
{
    OS3_TLSEntry *entry, *next;

    if (!tls_initialized) {
        return;
    }

    ObtainSemaphore(&tls_lock);
    entry = tls_list;
    while (entry != NULL) {
        next = entry->next;
        /* Note: SDL_TLSData itself is freed by SDL_thread.c's cleanup */
        SDL_free(entry);
        entry = next;
    }
    tls_list = NULL;
    ReleaseSemaphore(&tls_lock);

    tls_initialized = 0;
}

#endif /* SDL_THREAD_AMIGAOS3 */

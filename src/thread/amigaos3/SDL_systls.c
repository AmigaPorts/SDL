/*
  SDL2 Thread-Local Storage -- AmigaOS 3.x
  Phase 0: Stub using static pointer (single-task only).
  Commit 4: Real task-keyed TLS via tc_UserData or linked list.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "../SDL_thread_c.h"

/* Phase 0: single-task, just use a static pointer */
static SDL_TLSData *tls_data = NULL;

void SDL_SYS_InitTLSData(void)
{
    /* Phase 0: nothing to init */
}

SDL_TLSData *SDL_SYS_GetTLSData(void)
{
    return tls_data;
}

int SDL_SYS_SetTLSData(SDL_TLSData *data)
{
    tls_data = data;
    return 0;
}

void SDL_SYS_QuitTLSData(void)
{
    tls_data = NULL;
}

#endif /* SDL_THREAD_AMIGAOS3 */

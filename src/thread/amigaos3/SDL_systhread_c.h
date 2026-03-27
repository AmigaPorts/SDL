/*
  SDL2 Threading -- AmigaOS 3.x internals
  Defines SYS_ThreadHandle for the Exec Tasks backend.
*/
#ifndef SDL_systhread_c_h_amigaos3
#define SDL_systhread_c_h_amigaos3

#include "../../SDL_internal.h"

/* The thread handle is an AmigaOS Process pointer.
   We use struct Task* since Process extends Task. */
typedef struct Task *SYS_ThreadHandle;

#endif /* SDL_systhread_c_h_amigaos3 */

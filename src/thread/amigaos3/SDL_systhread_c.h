/*
  SDL2 Threading -- AmigaOS 3.x internals
  Defines SYS_ThreadHandle for the Exec Tasks backend.
*/
#include "../../SDL_internal.h"

/* Phase 0: use int as placeholder handle.
   Commit 4: will be struct Process* or struct Task* */
typedef int SYS_ThreadHandle;

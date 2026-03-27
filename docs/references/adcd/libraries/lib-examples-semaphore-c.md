---
title: Lib_examples/semaphore.c
manual: libraries
chapter: libraries
section: lib-examples-semaphore-c
functions: [ObtainSemaphore]
libraries: [exec.library]
---

# Lib_examples/semaphore.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* A simple "do nothing" example of Exec signal semaphore use is shown   */
/* below. When the semaphore is owned by a task, attempted access by     */
/* other tasks will block.  A nesting count is maintained, so the        */
/* current task can safely call ObtainSemaphore() on the same semaphore. */
/*
/* semaphore.c - Exec semaphore example - compile with lc -L semaphore.c */
#include <exec/types.h>
#include <exec/semaphores.h>
#include <clib/exec_protos.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void)  { return(0); }  /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }  /* really */
#endif

struct SignalSemaphore LockSemaphore = {0};

VOID main(int argc,char *argv[])
{
```c
    InitSemaphore(&LockSemaphore);
    ObtainSemaphore(&LockSemaphore);  /* Task now owns the semaphore. */
         ...
    ReleaseSemaphore(&LockSemaphore); /* Task has released the semaphore. */
```
}

---

## See Also

- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)

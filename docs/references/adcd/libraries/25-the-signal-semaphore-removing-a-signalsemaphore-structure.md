---
title: 25 / / The Signal Semaphore / Removing a SignalSemaphore Structure
manual: libraries
chapter: libraries
section: 25-the-signal-semaphore-removing-a-signalsemaphore-structure
functions: [Forbid, Permit, RemSemaphore]
libraries: [exec.library]
---

# 25 / / The Signal Semaphore / Removing a SignalSemaphore Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Semaphore resources can only be freed if the semaphore is not locked.  A
[public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) semaphore should first be removed from the system semaphore list
with the [RemSemaphore()](autodocs-2.0/exec-library-remsemaphore.md) function. This prevents other tasks from finding
the semaphore and trying to lock it. Once the semaphore is removed from
the system list, the semaphore should be [locked exclusively](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md) so no other
task can lock it.  Once the lock is obtained, it can be released again,
and the resources can be deallocated.

The following code should be used to remove a [public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) semaphore:


```c
    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore=FindSemaphore(name))
    {
        RemSemaphore(semaphore);       /* So no one else can find it... */
        ObtainSemaphore(semaphore);    /* Wait for us to be last user...*/
        ReleaseSemaphore(semaphore);   /* Ready for cleanup...          */
    }
    FreeMem(semaphore, sizeof(struct SignalSemaphore));
    Permit();
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [RemSemaphore — exec.library](../autodocs/exec.library.md#remsemaphore)

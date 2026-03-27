---
title: 25 / / The Signal Semaphore / Obtaining a SignalSemaphore Exclusively
manual: libraries
chapter: libraries
section: 25-the-signal-semaphore-obtaining-a-signalsemaphore
functions: [Forbid, ObtainSemaphore, Permit]
libraries: [exec.library]
---

# 25 / / The Signal Semaphore / Obtaining a SignalSemaphore Exclusively

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md) function can be used to get an exclusive lock on a
semaphore.  If another task currently has an exclusive or [shared](libraries/25-the-signal-semaphore-obtaining-a-shared-signalsemaphore.md) lock(s)
on the semaphore, your task will be put to sleep until all locks on the
the semaphore are released.


```c
    Semaphore Nesting.
    ------------------
    [SignalSemaphore](libraries/25-semaphore-functions-the-signal-semaphore.md)s have nesting.  That is, if your task already
    owns the semaphore, it will get a second ownership of that semaphore.
    This simplifies the writing of routines that must own the semaphore
    but do not know if the caller has obtained it yet.
```
To obtain a semaphore use:


```c
    struct SignalSemaphore *semaphore;
    ObtainSemaphore(semaphore);
```
To get an exclusive lock on a [public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) semaphore, the following code should
be used:


```c
    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();     /* Make sure the semaphore will not go away if found. */
    if (semaphore=FindSemaphore(name))
        ObtainSemaphore(semaphore);
    Permit();
```
The value of semaphore is NULL if the semaphore does not exist.  This is
only needed if the semaphore has a chance of going away at any time (i.e.,
the semaphore is [public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) and  might be removed by some other program).  If
there is a guarantee that the semaphore will not disappear, the semaphore
address could be cached, and all that would be needed is a call to the
[ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md) function.

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [Permit — exec.library](../autodocs/exec.library.md#permit)

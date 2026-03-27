---
title: 25 / / The Signal Semaphore / Checking a SignalSemaphore
manual: libraries
chapter: libraries
section: 25-the-signal-semaphore-checking-a-signalsemaphore
functions: [AttemptSemaphore, Forbid, ObtainSemaphore, Permit]
libraries: [exec.library]
---

# 25 / / The Signal Semaphore / Checking a SignalSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you attempt to obtain a semaphore with [ObtainSemaphore()](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md), your task
will be put to sleep if the semaphore is not currently available. If you
do not want to wait, you can call [AttemptSemaphore()](autodocs-2.0/exec-library-attemptsemaphore.md) instead. If the
semaphore is available for [exclusive locking](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md), AttemptSemaphore() obtains
it for you and returns TRUE.  If it is not available, the function returns
FALSE immediately instead of waiting for the semaphore to be released.

To attempt to obtain a semaphore, use the following:


```c
    struct SignalSemaphore *semaphore;
    AttemptSemaphore(semaphore);
```
To make an attempt to obtain a [public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) semaphore, the following code should
be used:


```c
    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore = FindSemaphore(name)) AttemptSemaphore(semaphore);
    Permit();
```

---

## See Also

- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [Permit — exec.library](../autodocs/exec.library.md#permit)

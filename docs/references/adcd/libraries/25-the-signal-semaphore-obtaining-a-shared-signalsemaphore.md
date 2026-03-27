---
title: 25 / / The Signal Semaphore / Obtaining a Shared SignalSemaphore
manual: libraries
chapter: libraries
section: 25-the-signal-semaphore-obtaining-a-shared-signalsemaphore
functions: [Forbid, Permit]
libraries: [exec.library]
---

# 25 / / The Signal Semaphore / Obtaining a Shared SignalSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For read-only purposes, multiple tasks may have a shared lock on a signal
semaphore.  If a semaphore is already exclusively locked, all attempts to
obtain the semaphore shared will be blocked until the [exclusive lock](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md) is
[released](libraries/25-the-signal-semaphore-releasing-a-signalsemaphore.md).  At that point, all shared locks will be obtained and the
calling tasks will wake up.

To obtain a shared semaphore, use:


```c
    struct SignalSemaphore *semaphore;
    ObtainSemaphoreShared(semaphore);
```
To obtain a [public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) shared semaphore, the following code should be used:


```c
    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore = FindSemaphore(name))
        ObtainSemaphoreShared(semaphore);
    Permit();
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)

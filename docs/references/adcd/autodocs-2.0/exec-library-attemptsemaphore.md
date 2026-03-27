---
title: exec.library/AttemptSemaphore
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-attemptsemaphore
functions: [ObtainSemaphore, ObtainSemaphoreShared, ReleaseSemaphore]
libraries: [exec.library]
---

# exec.library/AttemptSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AttemptSemaphore -- try to obtain without blocking
SYNOPSIS

```c
    success = AttemptSemaphore(signalSemaphore)
    D0                         A0

    LONG AttemptSemaphore(struct [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) *);
```
FUNCTION

```c
    This call is similar to [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md), except that it will not
    block if the semaphore could not be locked.
```
INPUT
   signalSemaphore -- an initialized signal semaphore structure

RESULT

    success -- TRUE if the semaphore was locked, false if some
        other task already possessed the semaphore.
NOTE

    This call does NOT preserve registers.
SEE ALSO

```c
    [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md) [ObtainSemaphoreShared()](autodocs-2.0/exec-library-obtainsemaphoreshared.md), [ReleaseSemaphore()](autodocs-2.0/exec-library-releasesemaphore.md),
    [exec/semaphores.h](autodocs-2.0/includes-exec-semaphores-h.md)
```

---

## See Also

- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)

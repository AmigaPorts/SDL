---
title: exec.library/ReleaseSemaphore
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-releasesemaphore
functions: [InitSemaphore, ObtainSemaphore, ObtainSemaphoreShared, ReleaseSemaphore]
libraries: [exec.library]
---

# exec.library/ReleaseSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReleaseSemaphore -- make signal semaphore available to others
SYNOPSIS

```c
    ReleaseSemaphore(signalSemaphore)
                     A0

    void ReleaseSemaphore(struct [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) *);
```
FUNCTION

```c
    ReleaseSemaphore() is the inverse of [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md). It makes
    the semaphore lockable to other users.  If tasks are waiting for
    the semaphore and this this task is done with the semaphore then
    the next waiting task is signalled.

    Each [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md) call must be balanced by exactly one
    ReleaseSemaphore() call.  This is because there is a nesting count
    maintained in the semaphore of the number of times that the current
    task has locked the semaphore. The semaphore is not released to
    other tasks until the number of releases matches the number of
    obtains.

    Needless to say, havoc breaks out if the task releases more times
    than it has obtained.
```
INPUT
   signalSemaphore -- an initialized signal semaphore structure

NOTE

    This call is guaranteed to preserve all registers.
SEE ALSO

```c
    [InitSemaphore()](autodocs-2.0/exec-library-initsemaphore.md), [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md), [ObtainSemaphoreShared()](autodocs-2.0/exec-library-obtainsemaphoreshared.md)
```

---

## See Also

- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)

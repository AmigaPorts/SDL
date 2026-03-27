---
title: exec.library/ObtainSemaphoreShared
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-obtainsemaphoreshared
functions: [AttemptSemaphore, InitSemaphore, ObtainSemaphore, ObtainSemaphoreShared, ReleaseSemaphore]
libraries: [exec.library]
---

# exec.library/ObtainSemaphoreShared

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ObtainSemaphoreShared -- gain shared access to a semaphore (V36)
```
SYNOPSIS

```c
    ObtainSemaphoreShared(signalSemaphore)
                          a0

    void ObtainSemaphoreShared(struct [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) *);
```
FUNCTION

```c
    A lock on a signal semaphore may either be exclusive, or shared.
    Exclusive locks are granted by the [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md) and
    [AttemptSemaphore()](autodocs-2.0/exec-library-attemptsemaphore.md) functions.  Shared locks are granted by
    ObtainSemaphoreShared().  Calls may be nested.

    Any number of tasks may simultaneously hold a shared lock on a
    semaphore.  Only one task may hold an exclusive lock.  A typical
    application is a list that is often read, but only occasionally
    written to.

    Any exlusive locker will be held off until all shared lockers
    release the semaphore.  Likewise, if an exlusive lock is held,
    all potential shared lockers will block until the exclusive lock
    is released.  All shared lockers are restarted at the same time.
```
EXAMPLE

```c
            ObtainSemaphoreShared(ss);
            /* read data */
            ReleaseSemaohore(ss);

            ObtainSemaphore(ss);
            /* modify data */
            ReleaseSemaohore(ss);
```
NOTES

    While this function was added for V36, the feature magically works
    with all older semaphore structures.

    A task owning a shared lock must not attempt to get an exclusive
    lock on the same semaphore.
INPUT

    signalSemaphore -- an initialized signal semaphore structure
NOTE

    This call is guaranteed to preserve all registers, starting with
    V37 exec.
RESULT

SEE ALSO

```c
    [InitSemaphore()](autodocs-2.0/exec-library-initsemaphore.md), [ReleaseSemaphore()](autodocs-2.0/exec-library-releasesemaphore.md)
```

---

## See Also

- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)

---
title: exec.library/InitSemaphore
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-initsemaphore
functions: [AttemptSemaphore, Forbid, ObtainSemaphore, ObtainSemaphoreShared, Permit, ReleaseSemaphore]
libraries: [exec.library]
---

# exec.library/InitSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    InitSemaphore -- initialize a signal semaphore
SYNOPSIS

```c
    InitSemaphore(signalSemaphore)
                  A0

    void InitSemaphore(struct [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) *);
```
FUNCTION

```c
    This function initializes a signal semaphore and prepares it for
    use.  It does not allocate anything, but does initialize list
    pointers and the semaphore counters.

    Semaphores are often used to protect critical data structures
    or hardware that can only be accessed by one task at a time.
    After initialization, the address of the [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) may be
    made available to any number of tasks.  Typically a task will
    try to [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md), passing this address in.  If no other
    task owns the semaphore, then the call will lock and return
    quickly.  If more tasks try to [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md), they will
    be put to sleep.  When the owner of the semaphore releases
    it, the next waiter in turn will be woken up.

    Semaphores are often preferable to the old-style [Forbid()/Permit()](autodocs-2.0/exec-library-permit.md)
    type arbitration.  With [Forbid()/Permit()](autodocs-2.0/exec-library-permit.md) *all* other tasks are
    prevented from running.  With semaphores, only those tasks that
    need access to whatever the semaphore protects are subject
    to waiting.
```
INPUT

```c
    signalSemaphore -- a signal semaphore structure (with all fields
                       set to zero before the call)
```
SEE ALSO

```c
    [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md), [ObtainSemaphoreShared()](autodocs-2.0/exec-library-obtainsemaphoreshared.md), [AttemptSemaphore()](autodocs-2.0/exec-library-attemptsemaphore.md),
    [ReleaseSemaphore()](autodocs-2.0/exec-library-releasesemaphore.md), [exec/semaphores.h](autodocs-2.0/includes-exec-semaphores-h.md)
```

---

## See Also

- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)

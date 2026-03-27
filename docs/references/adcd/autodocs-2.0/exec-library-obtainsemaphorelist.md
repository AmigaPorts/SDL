---
title: exec.library/ObtainSemaphoreList
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-obtainsemaphorelist
functions: [InitSemaphore, ObtainSemaphore, ObtainSemaphoreList, ReleaseSemaphoreList]
libraries: [exec.library]
---

# exec.library/ObtainSemaphoreList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ObtainSemaphoreList -- get a list of semaphores.
SYNOPSIS

```c
    ObtainSemaphoreList(list)
                        A0

    void ObtainSemaphoreList(struct [List](autodocs-2.0/includes-exec-lists-h.md) *);
```
FUNCTION

```c
    [Signal](autodocs-2.0/exec-library-signal.md) semaphores may be linked together into a list. This function
    takes a list of these semaphores and attempts to lock all of them at
    once. This call is preferable to applying [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md) to each
    element in the list because it attempts to lock all the elements
    simultaneously, and won't deadlock if someone is attempting to lock
    in some other order.

    This function assumes that only one task at a time will attempt to
    lock the entire list of semaphores.  In other words, there needs to
    be a higher level lock (perhaps another signal semaphore...) that is
    used before someone attempts to lock the semaphore list via
    ObtainSemaphoreList().

    Note that deadlocks may result if this call is used AND someone
    attempts to use [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md) to lock more than one semaphore on
    the list.  If you wish to lock more than semaphore (but not all of
    them) then you should obtain the higher level lock (see above)
```
INPUT
   list -- a list of signal semaphores

SEE ALSO

```c
    [InitSemaphore()](autodocs-2.0/exec-library-initsemaphore.md), [ReleaseSemaphoreList()](autodocs-2.0/exec-library-releasesemaphorelist.md)
```

---

## See Also

- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [ReleaseSemaphoreList — exec.library](../autodocs/exec.library.md#releasesemaphorelist)

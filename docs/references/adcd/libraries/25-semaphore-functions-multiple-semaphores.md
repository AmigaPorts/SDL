---
title: 25 / Semaphore Functions / Multiple Semaphores
manual: libraries
chapter: libraries
section: 25-semaphore-functions-multiple-semaphores
functions: [ObtainSemaphore, ObtainSemaphoreList, ReleaseSemaphore, ReleaseSemaphoreList]
libraries: [exec.library]
---

# 25 / Semaphore Functions / Multiple Semaphores

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The semaphore system has the ability to ask for ownership of a complete
list of semaphores.  This can help prevent deadlocks when there are two or
more tasks trying to get the same set of semaphores.  If task A gets
semaphore 1 and tries to obtain semaphore 2 after task B has obtained
semaphore 2 but before task B tries to obtain semaphore 1 then both tasks
will hang.  Exec provides [ObtainSemaphoreList()](autodocs-2.0/exec-library-obtainsemaphorelist.md) and [ReleaseSemaphoreList()](autodocs-2.0/exec-library-releasesemaphorelist.md)
to prevent this problem.

A semaphore list is a list header to a list that contains [SignalSemaphore](libraries/25-semaphore-functions-the-signal-semaphore.md)
structures.  The semaphore list must not contain any [public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) semaphores.
This is because the semaphore list functions use the standard node
structures in the semaphore.

To arbitrate access to a semaphore list use another semaphore.  Create a
[public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) semaphore and use it to arbitrate access to the list header of the
semaphore list.  This also gives you a locking semaphore, protecting the
[ObtainSemaphoreList()](autodocs-2.0/exec-library-obtainsemaphorelist.md) call.  Once you have gained access to the list with
[ObtainSemaphore()](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md), you may obtain all the semaphores on the list via
ObtainSemaphoreList() (or get individual semaphores with
ObtainSemaphore()).  When you are finished with the protected objects,
release the semaphores on the list with [ReleaseSemaphoreList()](autodocs-2.0/exec-library-releasesemaphorelist.md), and then
release the list semaphore via [ReleaseSemaphore()](libraries/25-the-signal-semaphore-releasing-a-signalsemaphore.md).

For example:


```c
    ObtainSemaphore((struct SignalSemaphore *)SemaphoreList);
    ObtainSemaphoreList(SemaphoreList->sl_List);

    /* At this point the objects are protected, and can be manipulated */

    ReleaseSemaphoreList(SemaphoreList->sl_List);
    ReleaseSemaphore((struct SignalSemaphore *)SemaphoreList);
```
See the [SharedList](libraries/25-semaphore-functions-the-signal-semaphore.md) structure above for an example of a semaphore structure
with a list header.

---

## See Also

- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)
- [ReleaseSemaphoreList — exec.library](../autodocs/exec.library.md#releasesemaphorelist)

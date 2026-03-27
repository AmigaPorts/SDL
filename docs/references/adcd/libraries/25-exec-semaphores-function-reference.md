---
title: 25 Exec Semaphores / Function Reference
manual: libraries
chapter: libraries
section: 25-exec-semaphores-function-reference
functions: [AddSemaphore, AttemptSemaphore, FindSemaphore, InitSemaphore, ObtainSemaphore, ObtainSemaphoreList, ObtainSemaphoreShared, ReleaseSemaphore, ReleaseSemaphoreList, RemSemaphore]
libraries: [exec.library]
---

# 25 Exec Semaphores / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following charts give a brief description of the Exec semaphore
functions.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details about each call.


                   Table 25-1: Exec Semaphore Functions
  ________________________________________________________________________
 |                                                                        |
 |  Exec Semaphore Function                 Description                   |
 |========================================================================|
 |           [AddSemaphore()](autodocs-2.0/exec-library-addsemaphore.md)  Initialize and add a signal semaphore to the |
 |                           system.                                      |
 |       [AttemptSemaphore()](autodocs-2.0/exec-library-attemptsemaphore.md)  Try to get an exclusive lock on a signal     |
 |                           semaphore without blocking.                  |
 |          [FindSemaphore()](autodocs-2.0/exec-library-findsemaphore.md)  Find a given system signal semaphore.        |
 |          [InitSemaphore()](autodocs-2.0/exec-library-initsemaphore.md)  Initialize a signal semaphore.               |
 |        [ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md)  Try to get exclusive access to a signal      |
 |                           semaphore.                                   |
 |    [ObtainSemaphoreList()](autodocs-2.0/exec-library-obtainsemaphorelist.md)  Try to get exclusive access to a list of     |
 |                           signal semaphores.                           |
 |  [ObtainSemaphoreShared()](autodocs-2.0/exec-library-obtainsemaphoreshared.md)  Try to get shared access to a signal         |
 |                           semaphore (V36).                             |
 |       [ReleaseSemaphore()](autodocs-2.0/exec-library-releasesemaphore.md)  Release the lock on a signal semaphore.      |
 |   [ReleaseSemaphoreList()](autodocs-2.0/exec-library-releasesemaphorelist.md)  Release the locks on a list of signal        |
 |                           semaphores.                                  |
 |           [RemSemaphore()](autodocs-2.0/exec-library-remsemaphore.md)  Remove a signal semaphore from the system.   |
 |________________________________________________________________________|

---

## See Also

- [AddSemaphore — exec.library](../autodocs/exec.library.md#addsemaphore)
- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [FindSemaphore — exec.library](../autodocs/exec.library.md#findsemaphore)
- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)
- [ReleaseSemaphoreList — exec.library](../autodocs/exec.library.md#releasesemaphorelist)
- [RemSemaphore — exec.library](../autodocs/exec.library.md#remsemaphore)

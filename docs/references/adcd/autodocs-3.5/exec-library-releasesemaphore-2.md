---
title: exec.library/ReleaseSemaphore
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-releasesemaphore-2
functions: [InitSemaphore, ObtainSemaphore, ObtainSemaphoreShared, ReleaseSemaphore]
libraries: [exec.library]
---

# exec.library/ReleaseSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReleaseSemaphore -- make signal semaphore available to others

   SYNOPSIS
	ReleaseSemaphore(signalSemaphore)
			 A0

	void ReleaseSemaphore(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	ReleaseSemaphore() is the inverse of [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md). It makes
	the semaphore lockable to other users.	If tasks are waiting for
	the semaphore and this this task is done with the semaphore then
	the next waiting task is signalled.

	Each [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md) call must be balanced by exactly one
	ReleaseSemaphore() call.  This is because there is a nesting count
	maintained in the semaphore of the number of times that the current
	task has locked the semaphore. The semaphore is not released to
	other tasks until the number of releases matches the number of
	obtains.

	Needless to say, havoc breaks out if the task releases more times
	than it has obtained.

   INPUT

       signalSemaphore -- an initialized signal semaphore structure
   NOTE
	This call is guaranteed to preserve all registers.

   SEE ALSO
	[InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md), [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), [ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md)

---

## See Also

- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)

---
title: exec.library/ObtainSemaphoreList
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-obtainsemaphorelist-2
functions: [AttemptSemaphore, InitSemaphore, ObtainSemaphore, ObtainSemaphoreList, ObtainSemaphoreShared, Procure, ReleaseSemaphore, Vacate]
libraries: [exec.library]
---

# exec.library/ObtainSemaphoreList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ObtainSemaphoreList -- get a list of semaphores.

   SYNOPSIS
	ObtainSemaphoreList(list)
			    A0

	void ObtainSemaphoreList(struct [List](autodocs-3.5/include-exec-lists-h.md) *);

   FUNCTION
	[Signal](autodocs-3.5/exec-library-signal-2.md) semaphores may be linked together into a list. This function
	takes a list of these semaphores and attempts to lock all of them at
	once. This call is preferable to applying [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md) to each
	element in the list because it attempts to lock all the elements
	simultaneously, and won't deadlock if someone is attempting to lock
	in some other order.

	This function assumes that only one task at a time will attempt to
	lock the entire list of semaphores.  In other words, there needs to
	be a higher level lock (perhaps another signal semaphore...) that is
	used before someone attempts to lock the semaphore list via
	ObtainSemaphoreList().

	Note that deadlocks may result if this call is used AND someone
	attempts to use [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md) to lock more than one semaphore on
	the list.  If you wish to lock more than semaphore (but not all of
	them) then you should obtain the higher level lock (see above)

   INPUT

       list -- a list of signal semaphores
   SEE ALSO
	[ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md), [ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md),
	[AttemptSemaphore()](autodocs-3.5/exec-library-attemptsemaphore-2.md), [ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [Procure()](autodocs-3.5/exec-library-procure-2.md), [Vacate()](autodocs-3.5/exec-library-vacate-2.md)

---

## See Also

- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [Procure — exec.library](../autodocs/exec.library.md#procure)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)
- [Vacate — exec.library](../autodocs/exec.library.md#vacate)

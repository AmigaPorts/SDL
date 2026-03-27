---
title: exec.library/ObtainSemaphoreShared
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-obtainsemaphoreshared-2
functions: [AttemptSemaphore, InitSemaphore, ObtainSemaphore, ObtainSemaphoreList, ObtainSemaphoreShared, Procure, ReleaseSemaphore, Vacate]
libraries: [exec.library]
---

# exec.library/ObtainSemaphoreShared

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ObtainSemaphoreShared -- gain shared access to a semaphore (V36)

    SYNOPSIS
	ObtainSemaphoreShared(signalSemaphore)
	                      a0

	void ObtainSemaphoreShared(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

    FUNCTION
	A lock on a signal semaphore may either be exclusive, or shared.
	Exclusive locks are granted by the [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md) and
	[AttemptSemaphore()](autodocs-3.5/exec-library-attemptsemaphore-2.md) functions.  Shared locks are granted by
	ObtainSemaphoreShared().  Calls may be nested.

	Any number of tasks may simultaneously hold a shared lock on a
	semaphore.  Only one task may hold an exclusive lock.  A typical
	application is a list that is often read, but only occasionally
	written to.

	Any exlusive locker will be held off until all shared lockers
	release the semaphore.  Likewise, if an exlusive lock is held,
	all potential shared lockers will block until the exclusive lock
	is released.  All shared lockers are restarted at the same time.

    EXAMPLE
		ObtainSemaphoreShared(ss);
		/* read data */
		ReleaseSemaohore(ss);

		ObtainSemaphore(ss);
		/* modify data */
		ReleaseSemaohore(ss);

    NOTES
	While this function was added for V36, the feature magically works
	with all older semaphore structures.

	A task owning a shared lock must not attempt to get an exclusive
	lock on the same semaphore.

	Starting in V39, if the caller already has an exclusive lock on the
	semaphore it will return with another nesting of the lock.  Pre-V39
	this would cause a deadlock.  For pre-V39 use, you can use the
	following workaround:

		/* Try to get the shared semaphore */
		if (!AttemptSemaphoreShared(ss))
		{
			/* Check if we can get the exclusive version */
			if (!AttemptSemaphore(ss))
			{
				/* Oh well, wait for the shared lock */
				ObtainSemaphoreShared(ss));
			}
		}
		:
		:
		ReleaseSemaphore(ss);

    INPUT
	signalSemaphore -- an initialized signal semaphore structure

    NOTE
	This call is guaranteed to preserve all registers, starting with
	V37 exec.

    RESULT

    SEE ALSO
	[ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), [InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md), [ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md),
	[AttemptSemaphore()](autodocs-3.5/exec-library-attemptsemaphore-2.md), [ObtainSemaphoreList()](autodocs-3.5/exec-library-obtainsemaphorelist-2.md), [Procure()](autodocs-3.5/exec-library-procure-2.md), [Vacate()](autodocs-3.5/exec-library-vacate-2.md)

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

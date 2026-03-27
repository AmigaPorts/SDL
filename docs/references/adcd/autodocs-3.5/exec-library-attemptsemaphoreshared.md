---
title: exec.library/AttemptSemaphoreShared
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-attemptsemaphoreshared
functions: [ObtainSemaphore, ObtainSemaphoreShared, ReleaseSemaphore]
libraries: [exec.library]
---

# exec.library/AttemptSemaphoreShared

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AttemptSemaphoreShared -- try to obtain without blocking       (V37)

   SYNOPSIS
	success = AttemptSemaphoreShared(signalSemaphore)
	D0			         A0

	[LONG](autodocs-3.5/include-exec-types-h.md) AttemptSemaphoreShared(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	This call is similar to [ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), except that it
	will not block if the semaphore could not be locked.

   INPUT

       signalSemaphore -- an initialized signal semaphore structure
   RESULT
	success -- TRUE if the semaphore was granted, false if some
	    other task already possessed the semaphore in exclusive mode.

   NOTE
	This call does NOT preserve registers.

	Starting in V39 this call will grant the semaphore if the
	caller is already the owner of an exclusive lock on the semaphore.
	In pre-V39 systems this would not be the case.  If you need this
	feature you can do the following workaround:

	[LONG](autodocs-3.5/include-exec-types-h.md) myAttemptSempahoreShared(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *ss)
	{
	[LONG](autodocs-3.5/include-exec-types-h.md) result;

		/* Try for a shared semaphore */
		if (!(result=AttemptSemaphoreShared(ss)))
		{
			/* Now try for the exclusive one... */
			result=AttempSemaphore(ss);
		}
		return(result);
	}

   SEE ALSO
	[ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md) [ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md),
	[exec/semaphores.h](autodocs-3.5/include-exec-semaphores-h.md)

---

## See Also

- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)

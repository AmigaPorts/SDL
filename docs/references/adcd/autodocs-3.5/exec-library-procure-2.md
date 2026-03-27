---
title: exec.library/Procure
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-procure-2
functions: [AttemptSemaphore, InitSemaphore, ObtainSemaphore, ObtainSemaphoreList, ObtainSemaphoreShared, Procure, ReleaseSemaphore, ReplyMsg, Vacate]
libraries: [exec.library]
---

# exec.library/Procure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Procure -- bid for a semaphore                                   (V39)

   SYNOPSIS
	Procure(semaphore, bidMessage)
		A0	    A1

	VOID Procure(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *, struct [SemaphoreMessage](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	This function is used to obtain a semaphore in an async manner.
	Like [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), it will obtain a [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) for you
	but unlike [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), you will not block until you get
	the semaphore.  Procure() will just post a request for the semaphore
	and will return.  When the semaphore is available (which could
	be at any time) the bidMessage will [ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md) and you will own
	the semaphore.  This lets you wait on multiple semaphores at once
	and to continue processing while waiting for the semaphore.

	NOTE:  Pre-V39, Procure() and [Vacate()](autodocs-3.5/exec-library-vacate-2.md) did not work correctly.
	They also did not operate on [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) semaphores.
	Old (and broken) MessageSemaphore use as of V39 will no longer work.

   INPUT
	semaphore - The [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) that you wish to Procure()
	bidMessage- The [SemaphoreMessage](autodocs-3.5/include-exec-semaphores-h.md) that you wish replied when
		you obtain access to the semaphore.  The message's
		ssm_Semaphore field will point at the semaphore that
		was obtained.  If the ssm_Semaphore field is NULL,
		the Procure() was aborted via [Vacate()](autodocs-3.5/exec-library-vacate-2.md).
		The mn_ReplyPort field of the message must point to
		a valid message port.
		To obtain a shared semaphore, the ln_Name field
		must be set to 1.  For an exclusive lock, the ln_Name
		field must be 0.  No other values are valid.

   BUGS
	Before V39, Procure() and [Vacate()](autodocs-3.5/exec-library-vacate-2.md) used a different semaphore
	system that was very broken.  This new system is only available
	as of V39 even though the LVOs are the same.

   SEE ALSO
	[ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md), [ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md),
	[AttemptSemaphore()](autodocs-3.5/exec-library-attemptsemaphore-2.md), [ObtainSemaphoreList()](autodocs-3.5/exec-library-obtainsemaphorelist-2.md), [Vacate()](autodocs-3.5/exec-library-vacate-2.md), [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md)

---

## See Also

- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [Procure — exec.library](../autodocs/exec.library.md#procure)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
- [Vacate — exec.library](../autodocs/exec.library.md#vacate)

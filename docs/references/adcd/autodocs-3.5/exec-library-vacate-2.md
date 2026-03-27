---
title: exec.library/Vacate
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-vacate-2
functions: [AttemptSemaphore, InitSemaphore, ObtainSemaphore, ObtainSemaphoreList, ObtainSemaphoreShared, Procure, ReleaseSemaphore, Vacate]
libraries: [exec.library]
---

# exec.library/Vacate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Vacate -- release a bitMessage from [Procure()](autodocs-3.5/exec-library-procure-2.md)                    (V39)

   SYNOPSIS
	Vacate(semaphore, bidMessage)
	       A0         A1

	void Vacate(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *,struct [SemaphoreMessage](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	This function can be used to release a semaphore obtained via
	[Procure()](autodocs-3.5/exec-library-procure-2.md).  However, the main purpose for this call is to be
	able to remove a bid for a semaphore that has not yet responded.
	This is required when a [Procure()](autodocs-3.5/exec-library-procure-2.md) was issued and the program
	no longer needs to get the semaphore and wishes to cancel the
	[Procure()](autodocs-3.5/exec-library-procure-2.md) request.  The canceled request will be replied with
	the ssm_Semaphore field set to NULL.  If you own the semaphore,
	the message was already replied and only the ssm_Semaphore field
	will be cleared.

	NOTE:  Pre-V39, [Procure()](autodocs-3.5/exec-library-procure-2.md) and Vacate() did not work correctly.
	They also did not operate on [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) semaphores.
	Old (and broken) MessageSemaphore use as of V39 will no longer work.

   INPUT
	semaphore - The [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) that you wish to Vacate()
	bidMessage- The [SemaphoreMessage](autodocs-3.5/include-exec-semaphores-h.md) that you wish to abort.
		The message's ssm_Semaphore field will be cleared.
		The message will be replied if it is still on the waiting
		list.  If it is not on the waiting list, it is assumed
		that the semaphore is owned and it will be released.

   BUGS
	Before V39, [Procure()](autodocs-3.5/exec-library-procure-2.md) and Vacate() used a different semaphore
	system that was very broken.  This new system is only available
	as of V39 even though the LVOs are the same.

   SEE ALSO
	[ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md), [ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md),
	[AttemptSemaphore()](autodocs-3.5/exec-library-attemptsemaphore-2.md), [ObtainSemaphoreList()](autodocs-3.5/exec-library-obtainsemaphorelist-2.md), [Procure()](autodocs-3.5/exec-library-procure-2.md), [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md)

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

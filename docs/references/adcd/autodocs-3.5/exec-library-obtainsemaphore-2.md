---
title: exec.library/ObtainSemaphore
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-obtainsemaphore-2
functions: [AttemptSemaphore, InitSemaphore, ObtainSemaphore, ObtainSemaphoreList, ObtainSemaphoreShared, Procure, ReleaseSemaphore, Vacate]
libraries: [exec.library]
---

# exec.library/ObtainSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ObtainSemaphore -- gain exclusive access to a semaphore

   SYNOPSIS
	ObtainSemaphore(signalSemaphore)
			A0

	void ObtainSemaphore(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	[Signal](autodocs-3.5/exec-library-signal-2.md) semaphores are used to gain exclusive access to an object.
	ObtainSemaphore is the call used to gain this access.  If another
	user currently has the semaphore locked the call will block until
	the object is available.

	If the current task already has locked the semaphore and attempts to
	lock it again the call will still succeed.  A "nesting count" is
	incremented each time the current owning task of the semaphore calls
	ObtainSemaphore().  This counter is decremented each time
	[ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md) is called.  When the counter returns to zero the
	semaphore is actually released, and the next waiting task is called.

	A queue of waiting tasks is maintained on the stacks of the waiting
	tasks.	Each will be called in turn as soon as the current task
	releases the semaphore.

	[Signal](autodocs-3.5/exec-library-signal-2.md) Semaphores are different than [Procure()/Vacate()](autodocs-3.5/exec-library-vacate-2.md) semaphores.
	The former requires less CPU time, especially if the semaphore is
	not currently locked.  They require very little set up and user
	thought.  The latter flavor of semaphore make no assumptions about
	how they are used -- they are completely general.  Unfortunately
	they are not as efficient as signal semaphores, and require the
	locker to have done some setup before doing the call.

   INPUT

       signalSemaphore -- an initialized signal semaphore structure
   NOTE
	This function preserves all registers (see BUGS).

   BUGS
	Until V37, this function could destroy A0.

   SEE ALSO
	[ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md), [ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md),
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

---
title: exec.library/InitSemaphore
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-initsemaphore-2
functions: [AttemptSemaphore, Forbid, ObtainSemaphore, ObtainSemaphoreShared, Permit, Procure, ReleaseSemaphore, Vacate]
libraries: [exec.library]
---

# exec.library/InitSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InitSemaphore -- initialize a signal semaphore

   SYNOPSIS
	InitSemaphore(signalSemaphore)
		      A0

	void InitSemaphore(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	This function initializes a signal semaphore and prepares it for
	use.  It does not allocate anything, but does initialize list
	pointers and the semaphore counters.

	Semaphores are often used to protect critical data structures
	or hardware that can only be accessed by one task at a time.
	After initialization, the address of the [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) may be
	made available to any number of tasks.  Typically a task will
	try to [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), passing this address in.  If no other
	task owns the semaphore, then the call will lock and return
	quickly.  If more tasks try to [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), they will
	be put to sleep.  When the owner of the semaphore releases
	it, the next waiter in turn will be woken up.

	Semaphores are often preferable to the old-style [Forbid()/Permit()](autodocs-3.5/exec-library-permit-2.md)
	type arbitration.  With [Forbid()/Permit()](autodocs-3.5/exec-library-permit-2.md) *all* other tasks are
	prevented from running.  With semaphores, only those tasks that
	need access to whatever the semaphore protects are subject
	to waiting.

   INPUT
	signalSemaphore -- a signal semaphore structure (with all fields
			   set to zero before the call)

   SEE ALSO
	[ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), [ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md), [AttemptSemaphore()](autodocs-3.5/exec-library-attemptsemaphore-2.md),
	[ReleaseSemaphore()](autodocs-3.5/exec-library-releasesemaphore-2.md), [Procure()](autodocs-3.5/exec-library-procure-2.md), [Vacate()](autodocs-3.5/exec-library-vacate-2.md), [exec/semaphores.h](autodocs-3.5/include-exec-semaphores-h.md)

---

## See Also

- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [Procure — exec.library](../autodocs/exec.library.md#procure)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)
- [Vacate — exec.library](../autodocs/exec.library.md#vacate)

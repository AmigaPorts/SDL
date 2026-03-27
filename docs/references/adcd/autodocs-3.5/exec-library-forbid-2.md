---
title: exec.library/Forbid
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-forbid-2
functions: [Disable, Forbid, ObtainSemaphore, ObtainSemaphoreShared, Permit, Wait]
libraries: [exec.library]
---

# exec.library/Forbid

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Forbid -- forbid task rescheduling.

    SYNOPSIS
	Forbid()

	void Forbid(void);

    FUNCTION
	Prevents other tasks from being scheduled to run by the dispatcher,
	until a matching [Permit()](autodocs-3.5/exec-library-permit-2.md) is executed, or this task is scheduled to
	[Wait()](autodocs-3.5/exec-library-wait-2.md).  Interrupts are NOT disabled.

	DO NOT USE THIS CALL WITHOUT GOOD JUSTIFICATION.  THIS CALL IS
	DANGEROUS!

    RESULTS
	The current task will not be rescheduled as long as it is ready to
	run.  In the event that the current task enters a wait state, other
	tasks may be scheduled.  Upon return from the wait state, the original
	task will continue to run without disturbing the Forbid().

	Calls to Forbid() nest. In order to restore normal task rescheduling,
	the programmer must execute exactly one call to [Permit()](autodocs-3.5/exec-library-permit-2.md) for every
	call to Forbid().

    WARNING
	In the event of a task entering a [Wait()](autodocs-3.5/exec-library-wait-2.md) after a Forbid(), the system
	"breaks" the forbidden state and runs normally until the task which
	called Forbid() is rescheduled.  If caution is not taken, this can
	cause subtle bugs, since any device or DOS call will (in effect)
	cause your task to wait.

	Forbid() is not useful or safe from within interrupt code
	(All interrupts are always higher priority than tasks, and
	interrupts are allowed to break a Forbid()).

    NOTE
	This call is guaranteed to preserve all registers.

    SEE ALSO
	[Permit()](autodocs-3.5/exec-library-permit-2.md), [Disable()](autodocs-3.5/exec-library-disable-2.md), [ObtainSemaphore()](autodocs-3.5/exec-library-obtainsemaphore-2.md), [ObtainSemaphoreShared()](autodocs-3.5/exec-library-obtainsemaphoreshared-2.md)

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [Wait — exec.library](../autodocs/exec.library.md#wait)

---
title: amiga.lib/CxSignal
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-cxsignal-2
functions: [AllocSignal, CreateCxObj, FindTask, Signal]
libraries: [commodities.library, exec.library]
---

# amiga.lib/CxSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxSignal -- create a commodity signaller object. (V36)

   SYNOPSIS
	signalerObj = CxSignal(task,signal);

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CxSignal(struct [Task](autodocs-3.5/include-exec-tasks-h.md) *,LONG);

   FUNCTION
	This function creates a Commodities signal object. The action
	of this object on receiving a Commodities message is to
	send the 'signal' to the 'task'. The caller is responsible
	for allocating the signal and determining the proper task ID.

	Note that 'signal' is the signal value as returned by [AllocSignal()](autodocs-3.5/exec-library-allocsignal-2.md),
	not the mask made from that value.

	This function is a C-language macro for [CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), defined
	in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

   INPUTS
	task - the task for the signaller to signal
	signal - the signal bit number for the signaller to send

   RESULTS
	signallerObj - a pointer to the signaller object, or NULL if it could
		       not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), [exec.library/FindTask()](autodocs-3.5/exec-library-findtask-2.md)
	[exec.library/Signal()](autodocs-3.5/exec-library-signal-2.md), [exec.library/AllocSignal()](autodocs-3.5/exec-library-allocsignal-2.md),

---

## See Also

- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [FindTask — exec.library](../autodocs/exec.library.md#findtask)
- [Signal — exec.library](../autodocs/exec.library.md#signal)

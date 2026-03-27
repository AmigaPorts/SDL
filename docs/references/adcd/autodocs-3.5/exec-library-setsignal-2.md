---
title: exec.library/SetSignal
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-setsignal-2
functions: [Signal, Wait]
libraries: [exec.library]
---

# exec.library/SetSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetSignal -- define the state of this task's signals

   SYNOPSIS
	oldSignals = SetSignal(newSignals, signalMask)
	D0		       D0	   D1

	ULONG SetSignal(ULONG,ULONG);

   FUNCTION
	This function can query or modify the state of the current task's
	received signal mask.  Setting the state of signals is considered
	dangerous.  Reading the state of signals is safe.

   INPUTS
	newSignals - the new values for the signals specified in
		     signalSet.
	signalMask - the set of signals to be affected.

   RESULTS
	oldSignals - the prior values for all signals

   EXAMPLES
	Get the current state of all signals:
	    SetSignal(0L,0L);
	Clear the CTRL-C signal:
	    SetSignal(0L,SIGBREAKF_CTRL_C);


	Check if the CTRL-C signal was pressed:

	    #include [<libraries/dos.h>](autodocs-3.5/include-libraries-dos-h.md)

	    /* Check & clear CTRL_C signal */
	    if(SetSignal(0L,SIGBREAKF_CTRL_C) & SIGBREAKF_CTRL_C)
		{
		printf("CTRL-C pressed!n");
		}

   SEE ALSO
	[Signal()](autodocs-3.5/exec-library-signal-2.md), [Wait()](autodocs-3.5/exec-library-wait-2.md)

---

## See Also

- [Signal — exec.library](../autodocs/exec.library.md#signal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)

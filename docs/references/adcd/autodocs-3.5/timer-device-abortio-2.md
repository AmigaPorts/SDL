---
title: timer.device/AbortIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-abortio-2
functions: [AbortIO]
libraries: [timer.device]
---

# timer.device/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AbortIO -- [Remove](autodocs-3.5/exec-library-remove-2.md) an existing timer request.

   SYNOPSIS
	error = AbortIO( [timerequest](autodocs-3.5/include-devices-timer-h.md) )
	D0               A1

	[LONG](autodocs-3.5/include-exec-types-h.md) AbortIO( struct [timerequest](autodocs-3.5/include-devices-timer-h.md) * );

   FUNCTION
	This is an exec.library call.

	This routine removes a timerquest from the timer.  It runs in
	the context of the caller.

   INPUTS
	[timerequest](autodocs-3.5/include-devices-timer-h.md) - the timer request to be aborted

   RETURNS
	0  if the request was aborted, io_Error will also be set to
	    IOERR_ABORTED.
	-1 otherwise

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	exec.library/AbortIO()

   BUGS

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)

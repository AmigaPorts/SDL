---
title: exec.library/WaitIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-waitio-2
functions: [AbortIO, CheckIO, DoIO, Remove, SendIO, Wait, WaitIO]
libraries: [exec.library, timer.device]
---

# exec.library/WaitIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WaitIO -- wait for completion of an I/O request

   SYNOPSIS
	error = WaitIO(iORequest)
	D0	       A1

	[BYTE](autodocs-3.5/include-exec-types-h.md) WaitIO(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	This function waits for the specified I/O request to complete, then
	removes it from the replyport.	If the I/O has already completed,
	this function will return immediately.

	This function should be used with care, as it does not return until
	the I/O request completes; if the I/O never completes, this
	function will never return, and your task will hang.  If this
	situation is a possibility, it is safer to use the [Wait()](autodocs-3.5/exec-library-wait-2.md) function.
	[Wait()](autodocs-3.5/exec-library-wait-2.md) will return return when any of a specified set of signal is
	received.  This is how I/O timeouts can be properly handled.

   WARNING
	If this [IORequest](autodocs-3.5/include-exec-io-h.md) was "Quick" or otherwise finished BEFORE this
	call, this function drops though immediately, with no call to
	[Wait()](autodocs-3.5/exec-library-wait-2.md).  A side effect is that the signal bit related the port may
	remain set.  Expect this.

	When removing a known complete [IORequest](autodocs-3.5/include-exec-io-h.md) from a port, WaitIO() is the
	preferred method.  A simple [Remove()](autodocs-3.5/exec-library-remove-2.md) would require a [Disable/Enable](autodocs-3.5/exec-library-enable-2.md)
	pair!

   INPUTS
	iORequest - pointer to an I/O request block

   RESULTS
	error - zero if successful, else an error is returned
		(a sign extended copy of io_Error).

   SEE ALSO
	[DoIO()](autodocs-3.5/exec-library-doio-2.md), [SendIO()](autodocs-3.5/exec-library-sendio-2.md), [CheckIO()](autodocs-3.5/exec-library-checkio-2.md), [AbortIO()](autodocs-3.5/exec-library-abortio-2.md)

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)

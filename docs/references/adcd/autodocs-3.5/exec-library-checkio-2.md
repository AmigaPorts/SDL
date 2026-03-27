---
title: exec.library/CheckIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-checkio-2
functions: [AbortIO, CheckIO, Disable, DoIO, Remove, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# exec.library/CheckIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CheckIO -- get the status of an [IORequest](autodocs-3.5/include-exec-io-h.md)

   SYNOPSIS
	result = CheckIO(IORequest)
	D0		 A1

	struct [IORequest](autodocs-3.5/include-exec-io-h.md) *CheckIO(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	This function determines the current state of an I/O request and
	returns FALSE if the I/O has not yet completed.  This function
	effectively hides the internals of the I/O completion mechanism.

	CheckIO() will NOT remove the returned [IORequest](autodocs-3.5/include-exec-io-h.md) from the reply port.
	This is best performed with [WaitIO()](autodocs-3.5/exec-library-waitio-2.md). If the request has already
	completed, [WaitIO()](autodocs-3.5/exec-library-waitio-2.md) will return quickly. Use of the [Remove()](autodocs-3.5/exec-library-remove-2.md)
	function is dangerous, since other tasks may still be adding things
	to your message port; a [Disable()](autodocs-3.5/exec-library-disable-2.md) would be required.

	This function should NOT be used to busy loop (looping until IO is
	complete).  [WaitIO()](autodocs-3.5/exec-library-waitio-2.md) is provided for that purpose.

   INPUTS
	iORequest - pointer to an I/O request block

   RESULTS
	result - NULL if I/O is still in progress.  Otherwise
		 D0 points to the [IORequest](autodocs-3.5/include-exec-io-h.md) block.

   NOTE
	CheckIO can hang if called on an [IORequest](autodocs-3.5/include-exec-io-h.md) that has never been used.
	This occurs if LN_TYPE of the [IORequest](autodocs-3.5/include-exec-io-h.md) is set to "NT_MESSAGE".
	Instead simply set LN_TYPE to 0.

   SEE ALSO
	[DoIO()](autodocs-3.5/exec-library-doio-2.md), [SendIO()](autodocs-3.5/exec-library-sendio-2.md), [WaitIO()](autodocs-3.5/exec-library-waitio-2.md), [AbortIO()](autodocs-3.5/exec-library-abortio-2.md)

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)

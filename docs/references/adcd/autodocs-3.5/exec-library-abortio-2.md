---
title: exec.library/AbortIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-abortio-2
functions: [AbortIO, CheckIO, DoIO, Remove, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# exec.library/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AbortIO - attempt to abort an in-progress I/O request

   SYNOPSIS
	AbortIO(iORequest)
	        A1

	VOID AbortIO(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	Ask a device to abort a previously started [IORequest](autodocs-3.5/include-exec-io-h.md).  This is done
	by calling the device's ABORTIO vector, with your given [IORequest](autodocs-3.5/include-exec-io-h.md).


	AbortIO is a command the device that may or may not grant.  If
	successful, the device will stop processing the [IORequest](autodocs-3.5/include-exec-io-h.md), and
	reply to it earlier than it would otherwise have done.

   NOTE
	AbortIO() does NOT [Remove()](autodocs-3.5/exec-library-remove-2.md) the [IORequest](autodocs-3.5/include-exec-io-h.md) from your ReplyPort, OR
	wait for it to complete.  After an AbortIO() you must wait normally
	for the reply message before actually reusing the request.

	If a request has already completed when AbortIO() is called, no
	action is taken.

   EXAMPLE
	    AbortIO(timer_request);
	    WaitIO(timer_request);
	    /* [Message](autodocs-3.5/include-exec-ports-h.md) is free to be reused */

   INPUTS
	iORequest - pointer to an I/O request block (must have been used
		at least once.  May be active or finished).

   SEE ALSO
	[WaitIO()](autodocs-3.5/exec-library-waitio-2.md), [DoIO()](autodocs-3.5/exec-library-doio-2.md), [SendIO()](autodocs-3.5/exec-library-sendio-2.md), [CheckIO()](autodocs-3.5/exec-library-checkio-2.md)

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)

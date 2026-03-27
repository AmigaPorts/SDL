---
title: exec.library/DoIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-doio-2
functions: [AbortIO, CheckIO, DoIO, OpenDevice, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# exec.library/DoIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DoIO -- perform an I/O command and wait for completion

   SYNOPSIS
	error = DoIO(iORequest)
	D0	     A1

	[BYTE](autodocs-3.5/include-exec-types-h.md) DoIO(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	This function requests a device driver to perform the I/O command
	specified in the I/O request.  This function will always wait until
	the I/O request is fully complete.

	DoIO() handles all the details, including Quick I/O, waiting for
	the request, and removing the reply message, etc..

   IMPLEMENTATION
	This function first tries to complete the IO via the "Quick I/O"
	mechanism.  The io_Flags field is always set to IOF_QUICK (0x01)
	before the internal device call.

	The LN_TYPE field is used internally to flag completion.  Active
	requests have type NT_MESSAGE.  Requests that have been replied
	have type NT_REPLYMSG.  It is illegal to start IO using a
	still active [IORequest](autodocs-3.5/include-exec-io-h.md), or a request with type NT_REPLYMSG.

   INPUTS
	iORequest - pointer to an [IORequest](autodocs-3.5/include-exec-io-h.md) initialized by [OpenDevice()](autodocs-3.5/exec-library-opendevice-2.md)

   RESULTS
	error - a sign-extended copy of the io_Error field of the
		[IORequest](autodocs-3.5/include-exec-io-h.md).  Most device commands require that the error
		return be checked.

   SEE ALSO
	[SendIO()](autodocs-3.5/exec-library-sendio-2.md), [CheckIO()](autodocs-3.5/exec-library-checkio-2.md), [WaitIO()](autodocs-3.5/exec-library-waitio-2.md), [AbortIO()](autodocs-3.5/exec-library-abortio-2.md), [amiga.lib/BeginIO](autodocs-3.5/serial-device-beginio-2.md)

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)

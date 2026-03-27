---
title: exec.library/SendIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-sendio-2
functions: [AbortIO, CheckIO, DoIO, WaitIO]
libraries: [exec.library, timer.device]
---

# exec.library/SendIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SendIO -- initiate an I/O command

   SYNOPSIS
	SendIO(iORequest)
	       A1

	void SendIO(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	This function requests the device driver start processing the given
	I/O request.  The device will return control without waiting for
	the I/O to complete.

	The io_Flags field of the [IORequest](autodocs-3.5/include-exec-io-h.md) will be set to zero before the
	request is sent.  See [BeginIO()](autodocs-3.5/serial-device-beginio-2.md) for more details.

   INPUTS
	iORequest - pointer to an I/O request, or a device specific
		    extended [IORequest](autodocs-3.5/include-exec-io-h.md).

   SEE ALSO
	[DoIO()](autodocs-3.5/exec-library-doio-2.md), [CheckIO()](autodocs-3.5/exec-library-checkio-2.md), [WaitIO()](autodocs-3.5/exec-library-waitio-2.md), [AbortIO()](autodocs-3.5/exec-library-abortio-2.md)

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)

---
title: amiga.lib/BeginIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-beginio-2
functions: [DoIO, SendIO, WaitIO]
libraries: [exec.library]
---

# amiga.lib/BeginIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	BeginIO -- initiate asynchronous device I/O

   SYNOPSIS
	BeginIO(ioReq)

	VOID BeginIO(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	This function takes an [IORequest](autodocs-3.5/include-exec-io-h.md), and passes it directly to the
	"BeginIO" vector of the proper device.  This is equivalent to
	[SendIO()](autodocs-3.5/exec-library-sendio-2.md), except that io_Flags is not cleared. A good understanding
	of Exec device I/O is required to properly use this function.

	This function does not wait for the I/O to complete.

   INPUTS
	ioReq - an initialized and opened [IORequest](autodocs-3.5/include-exec-io-h.md) structure with the
	        io_Flags field set to a reasonable value (set to 0 if you do
		not require io_Flags).

   SEE ALSO
	[exec.library/DoIO()](autodocs-3.5/exec-library-doio-2.md), [exec.library/SendIO()](autodocs-3.5/exec-library-sendio-2.md), [exec.library/WaitIO()](autodocs-3.5/exec-library-waitio-2.md)

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)

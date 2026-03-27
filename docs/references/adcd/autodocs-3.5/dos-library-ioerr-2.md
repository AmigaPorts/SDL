---
title: dos.library/IoErr
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-ioerr-2
functions: [Fault, IoErr, PrintFault, SetIoErr]
libraries: [dos.library]
---

# dos.library/IoErr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	IoErr -- Return extra information from the system

    SYNOPSIS
	error = IoErr()
	  D0

	[LONG](autodocs-3.5/include-exec-types-h.md) IoErr(void)

    FUNCTION
	Most I/O routines return zero to indicate an error. When this
	happens (or whatever the defined error return for the routine)
	this routine may be called to determine more information. It is
	also used in some routines to pass back a secondary result.

	Note: there is no guarantee as to the value returned from IoErr()
	after a successful operation, unless to specified by the routine.

    RESULTS
	error - integer

    SEE ALSO
	[Fault()](autodocs-3.5/dos-library-fault-2.md), [PrintFault()](autodocs-3.5/dos-library-printfault-2.md), [SetIoErr()](autodocs-3.5/dos-library-setioerr-2.md)

---

## See Also

- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PrintFault — dos.library](../autodocs/dos.library.md#printfault)
- [SetIoErr — dos.library](../autodocs/dos.library.md#setioerr)

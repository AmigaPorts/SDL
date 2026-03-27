---
title: dos.library/SetIoErr
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setioerr-2
functions: [Fault, IoErr, PrintFault]
libraries: [dos.library]
---

# dos.library/SetIoErr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetIoErr -- Sets the value returned by [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) (V36)

   SYNOPSIS
	oldcode = SetIoErr(code)
	D0		    D1

	[LONG](autodocs-3.5/include-exec-types-h.md) SetIoErr(LONG);

   FUNCTION
	This routine sets up the secondary result (pr_Result2) return code
	(returned by the [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) function).

   INPUTS
	code - Code to be returned by a call to [IoErr](autodocs-3.5/dos-library-ioerr-2.md).

   RESULT
	oldcode - The previous error code.

   SEE ALSO
	[IoErr()](autodocs-3.5/dos-library-ioerr-2.md), [Fault()](autodocs-3.5/dos-library-fault-2.md), [PrintFault()](autodocs-3.5/dos-library-printfault-2.md)

---

## See Also

- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PrintFault — dos.library](../autodocs/dos.library.md#printfault)

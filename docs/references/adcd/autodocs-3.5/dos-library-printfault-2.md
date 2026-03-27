---
title: dos.library/PrintFault
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-printfault-2
functions: [FPuts, Fault, IoErr, Output, SetIoErr]
libraries: [dos.library]
---

# dos.library/PrintFault

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PrintFault -- Returns the text associated with a DOS error code (V36)

   SYNOPSIS
	success = PrintFault(code, header)
	D0                    D1     D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) PrintFault(LONG, STRPTR)

   FUNCTION
	This routine obtains the error message text for the given error code.
	This is similar to the [Fault()](autodocs-3.5/dos-library-fault-2.md) function, except that the output is
	written to the default output channel with buffered output.
	The value returned by [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) is set to the code passed in.

   INPUTS
	code   - Error code
	header - header to output before error text

   RESULT
	success - Success/failure code.

   SEE ALSO
	[IoErr()](autodocs-3.5/dos-library-ioerr-2.md), [Fault()](autodocs-3.5/dos-library-fault-2.md), [SetIoErr()](autodocs-3.5/dos-library-setioerr-2.md), [Output()](autodocs-3.5/dos-library-output-2.md), [FPuts()](autodocs-3.5/dos-library-fputs-2.md)

---

## See Also

- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SetIoErr — dos.library](../autodocs/dos.library.md#setioerr)

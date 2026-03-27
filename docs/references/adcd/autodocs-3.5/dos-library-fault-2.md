---
title: dos.library/Fault
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-fault-2
functions: [IoErr, PrintFault, SetIoErr]
libraries: [dos.library]
---

# dos.library/Fault

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Fault -- Returns the text associated with a DOS error code (V36)

   SYNOPSIS
	len = Fault(code, header, buffer, len)
	D0           D1     D2      D3    D4

	[LONG](autodocs-3.5/include-exec-types-h.md) Fault(LONG, [STRPTR](autodocs-3.5/include-exec-types-h.md), [STRPTR](autodocs-3.5/include-exec-types-h.md), LONG)

   FUNCTION
	This routine obtains the error message text for the given error code.
	The header is prepended to the text of the error message, followed
	by a colon.  Puts a null-terminated string for the error message into
	the buffer.  By convention, error messages should be no longer than 80
	characters (+1 for termination), and preferably no more than 60.
	The value returned by [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) is set to the code passed in.  If there
	is no message for the error code, the message will be "Error code
	<number>n".

	The number of characters put into the buffer is returned, which will
	be 0 if the code passed in was 0.

   INPUTS
	code   - Error code
	header - header to output before error text
	buffer - Buffer to receive error message.
	len    - Length of the buffer.

   RESULT
	len    - number of characters put into buffer (may be 0)

   SEE ALSO
	[IoErr()](autodocs-3.5/dos-library-ioerr-2.md), [SetIoErr()](autodocs-3.5/dos-library-setioerr-2.md), [PrintFault()](autodocs-3.5/dos-library-printfault-2.md)

   BUGS
	In older documentation, the return was shown as [BOOL](autodocs-3.5/include-exec-types-h.md) success.  This
	was incorrect, it has always returned the length.

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PrintFault — dos.library](../autodocs/dos.library.md#printfault)
- [SetIoErr — dos.library](../autodocs/dos.library.md#setioerr)

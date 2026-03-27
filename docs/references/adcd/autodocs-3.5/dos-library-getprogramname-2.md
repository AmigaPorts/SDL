---
title: dos.library/GetProgramName
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getprogramname-2
functions: [IoErr]
libraries: [dos.library]
---

# dos.library/GetProgramName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetProgramName -- Returns the current program name (V36)

   SYNOPSIS
	success = GetProgramName(buf, len)
	D0                       D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) GetProgramName(STRPTR, LONG)

   FUNCTION
	Extracts the program name from the CLI structure and puts it
	into the buffer.  If the buffer is too small, the name is truncated.
	If no CLI structure is present, a null string is returned in the
	buffer, and failure from the call (with [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) ==
	ERROR_OBJECT_WRONG_TYPE);

   INPUTS
	buf     - Buffer to hold extracted name
	len     - Number of bytes of space in buffer

   RESULT
	success - Success/failure indicator

   SEE ALSO
	[SetProgramName()](autodocs-3.5/dos-library-setprogramname-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)

---
title: dos.library/GetCurrentDirName
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getcurrentdirname-2
functions: [IoErr]
libraries: [dos.library]
---

# dos.library/GetCurrentDirName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetCurrentDirName -- returns the current directory name (V36)

   SYNOPSIS
	success = GetCurrentDirName(buf, len)
	D0                          D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) GetCurrentDirName(STRPTR, LONG)

   FUNCTION
	Extracts the current directory name from the CLI structure and puts it
	into the buffer.  If the buffer is too small, the name is truncated
	appropriately and a failure code returned.  If no CLI structure is
	present, a null string is returned in the buffer, and failure from
	the call (with [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) == ERROR_OBJECT_WRONG_TYPE);

   INPUTS
	buf     - Buffer to hold extracted name
	len     - Number of bytes of space in buffer

   RESULT
	success - Success/failure indicator

   BUGS
	In V36, this routine didn't handle 0-length buffers correctly.

   SEE ALSO
	[SetCurrentDirName()](autodocs-3.5/dos-library-setcurrentdirname-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)

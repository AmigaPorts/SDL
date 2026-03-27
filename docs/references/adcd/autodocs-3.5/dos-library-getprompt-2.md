---
title: dos.library/GetPrompt
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getprompt-2
functions: [IoErr]
libraries: [dos.library]
---

# dos.library/GetPrompt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetPrompt -- Returns the prompt for the current process (V36)

   SYNOPSIS
	success = GetPrompt(buf, len)
	D0                  D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) GetPrompt(STRPTR, LONG)

   FUNCTION
	Extracts the prompt string from the CLI structure and puts it
	into the buffer.  If the buffer is too small, the string is truncated
	appropriately and a failure code returned.  If no CLI structure is
	present, a null string is returned in the buffer, and failure from
	the call (with [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) == ERROR_OBJECT_WRONG_TYPE);

   INPUTS
	buf     - Buffer to hold extracted prompt
	len     - Number of bytes of space in buffer

   RESULT
	success - Success/failure indicator

   SEE ALSO
	[SetPrompt()](autodocs-3.5/dos-library-setprompt-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)

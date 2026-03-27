---
title: dos.library/PutStr
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-putstr-2
functions: [FPutC, FPuts, FWrite, WriteChars]
libraries: [dos.library]
---

# dos.library/PutStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PutStr -- Writes a string the the default output (buffered) (V36)

   SYNOPSIS
	error = PutStr(str)
	D0             D1

	[LONG](autodocs-3.5/include-exec-types-h.md) PutStr(STRPTR)

   FUNCTION
	This routine writes an unformatted string to the default output.  No
	newline is appended to the string and any error is returned.  This
	routine is buffered.

   INPUTS
	str   - Null-terminated string to be written to default output

   RESULT
	error - 0 for success, -1 for any error.  NOTE: this is opposite
		most Dos function returns!

   SEE ALSO
	[FPuts()](autodocs-3.5/dos-library-fputs-2.md), [FPutC()](autodocs-3.5/dos-library-fputc-2.md), [FWrite()](autodocs-3.5/dos-library-fwrite-2.md), [WriteChars()](autodocs-3.5/dos-library-writechars-2.md)

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [WriteChars — dos.library](../autodocs/dos.library.md#writechars)

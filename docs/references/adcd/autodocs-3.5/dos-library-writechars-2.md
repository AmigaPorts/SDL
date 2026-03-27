---
title: dos.library/WriteChars
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-writechars-2
functions: [FPutC, FPuts, FWrite, PutStr]
libraries: [dos.library]
---

# dos.library/WriteChars

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WriteChars -- Writes bytes to the the default output (buffered) (V36)

   SYNOPSIS
	count = WriteChars(buf, buflen)
	D0                 D1   D2

	[LONG](autodocs-3.5/include-exec-types-h.md) WriteChars(STRPTR, LONG)

   FUNCTION
	This routine writes a number of bytes to the default output.  The
	length is returned.  This routine is buffered.

   INPUTS
	buf    - buffer of characters to write
	buflen - number of characters to write

   RESULT
	count - Number of bytes written.  -1 (EOF) indicates an error

   SEE ALSO
	[FPuts()](autodocs-3.5/dos-library-fputs-2.md), [FPutC()](autodocs-3.5/dos-library-fputc-2.md), [FWrite()](autodocs-3.5/dos-library-fwrite-2.md), [PutStr()](autodocs-3.5/dos-library-putstr-2.md)

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [PutStr — dos.library](../autodocs/dos.library.md#putstr)

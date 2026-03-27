---
title: dos.library/FPuts
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-fputs-2
functions: [FGets, FPutC, FWrite, PutStr]
libraries: [dos.library]
---

# dos.library/FPuts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FPuts -- Writes a string the the specified output (buffered) (V36)

   SYNOPSIS
	error = FPuts(fh, str)
	D0            D1  D2

	[LONG](autodocs-3.5/include-exec-types-h.md) FPuts(BPTR, STRPTR)

   FUNCTION
	This routine writes an unformatted string to the filehandle.  No
	newline is appended to the string.  This routine is buffered.

   INPUTS
	fh    - filehandle to use for buffered I/O
	str   - Null-terminated string to be written to default output

   RESULT
	error - 0 normally, otherwise -1.  Note that this is opposite of
		most other Dos functions, which return success.

   SEE ALSO
	[FGets()](autodocs-3.5/dos-library-fgets-2.md), [FPutC()](autodocs-3.5/dos-library-fputc-2.md), [FWrite()](autodocs-3.5/dos-library-fwrite-2.md), [PutStr()](autodocs-3.5/dos-library-putstr-2.md)

---

## See Also

- [FGets — dos.library](../autodocs/dos.library.md#fgets)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [PutStr — dos.library](../autodocs/dos.library.md#putstr)

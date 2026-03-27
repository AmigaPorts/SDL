---
title: dos.library/FGetC
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-fgetc-2
functions: [FGetC, FPutC, UnGetC]
libraries: [dos.library]
---

# dos.library/FGetC

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FGetC -- [Read](autodocs-3.5/dos-library-read-2.md) a character from the specified input (buffered) (V36)

   SYNOPSIS
	char = FGetC(fh)
	D0	     D1

	[LONG](autodocs-3.5/include-exec-types-h.md) FGetC(BPTR)

   FUNCTION
	Reads the next character from the input stream.  A -1 is
	returned when EOF or an error is encountered.  This call is buffered.
	Use [Flush()](autodocs-3.5/dos-library-flush-2.md) between buffered and unbuffered I/O on a filehandle.

   INPUTS
	fh - filehandle to use for buffered I/O

   RESULT
	char - character read (0-255) or -1

   BUGS
	In V36, after an EOF was read, EOF would always be returned from
	FGetC() from then on.  Starting in V37, it tries to read from the
	handler again each time (unless UnGetC(fh,-1) was called).

   SEE ALSO
	[FPutC()](autodocs-3.5/dos-library-fputc-2.md), [UnGetC()](autodocs-3.5/dos-library-ungetc-2.md), [Flush()](autodocs-3.5/dos-library-flush-2.md)

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)

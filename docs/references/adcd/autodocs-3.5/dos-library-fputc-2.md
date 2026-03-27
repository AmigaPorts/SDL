---
title: dos.library/FPutC
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-fputc-2
functions: [FGetC, UnGetC]
libraries: [dos.library]
---

# dos.library/FPutC

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FPutC -- [Write](autodocs-3.5/dos-library-write-2.md) a character to the specified output (buffered) (V36)

   SYNOPSIS
	char = FPutC(fh, char)
	D0           D1   D2

	[LONG](autodocs-3.5/include-exec-types-h.md) FPutC(BPTR, LONG)

   FUNCTION
	Writes a single character to the output stream.  This call is
	buffered.  Use [Flush()](autodocs-3.5/dos-library-flush-2.md) between buffered and unbuffered I/O on a
	filehandle.  Interactive filehandles are flushed automatically
	on a newline, return, '0', or line feed.

   INPUTS
	fh   - filehandle to use for buffered I/O
	char - character to write

   RESULT
	char - either the character written, or EOF for an error.

   BUGS
	Older autodocs indicated that you should pass a [UBYTE](autodocs-3.5/include-exec-types-h.md).  The
	correct usage is to pass a [LONG](autodocs-3.5/include-exec-types-h.md) in the range 0-255.

   SEE ALSO
	[FGetC()](autodocs-3.5/dos-library-fgetc-2.md), [UnGetC()](autodocs-3.5/dos-library-ungetc-2.md), [Flush()](autodocs-3.5/dos-library-flush-2.md)

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)

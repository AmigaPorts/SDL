---
title: dos.library/FRead
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-fread-2
functions: [FGetC, FGets, FWrite, IoErr]
libraries: [dos.library]
---

# dos.library/FRead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FRead -- Reads a number of blocks from an input (buffered) (V36)

   SYNOPSIS
	count = FRead(fh, buf, blocklen, blocks)
	D0	      D1  D2     D3        D4

	[LONG](autodocs-3.5/include-exec-types-h.md) FRead(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), ULONG, ULONG)

   FUNCTION
	Attempts to read a number of blocks, each blocklen long, into the
	specified buffer from the input stream.  May return less than
	the number of blocks requested, either due to EOF or read errors.
	This call is buffered.

   INPUTS
	fh	 - filehandle to use for buffered I/O
	buf      - Area to read bytes into.
	blocklen - number of bytes per block.  Must be > 0.
	blocks	 - number of blocks to read.  Must be > 0.

   RESULT
	count - Number of _blocks_ read, or 0 for EOF.  On an error, the
		number of blocks actually read is returned.

   BUGS
	Doesn't clear [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) before starting.  If you want to find out
	about errors, use SetIoErr(0L) before calling.

   SEE ALSO
	[FGetC()](autodocs-3.5/dos-library-fgetc-2.md), [FWrite()](autodocs-3.5/dos-library-fwrite-2.md), [FGets()](autodocs-3.5/dos-library-fgets-2.md)

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FGets — dos.library](../autodocs/dos.library.md#fgets)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)

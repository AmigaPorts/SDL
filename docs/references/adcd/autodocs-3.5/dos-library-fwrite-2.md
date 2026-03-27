---
title: dos.library/FWrite
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-fwrite-2
functions: [FPutC, FPuts, FRead, IoErr]
libraries: [dos.library]
---

# dos.library/FWrite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FWrite -- Writes a number of blocks to an output (buffered) (V36)

   SYNOPSIS
	count = FWrite(fh, buf, blocklen, blocks)
	D0	       D1  D2     D3        D4

	[LONG](autodocs-3.5/include-exec-types-h.md) FWrite(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), ULONG, ULONG)

   FUNCTION
	Attempts to write a number of blocks, each blocklen long, from the
	specified buffer to the output stream.  May return less than the
	number of blocks requested, if there is some error such as a full
	disk or r/w error.  This call is buffered.

   INPUTS
	fh	 - filehandle to use for buffered I/O
	buf      - Area to write bytes from.
	blocklen - number of bytes per block.  Must be > 0.
	blocks	 - number of blocks to write.  Must be > 0.

   RESULT
	count - Number of _blocks_ written.  On an error, the number of
		blocks actually written is returned.

   BUGS
	Doesn't clear [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) before starting.  If you want to find out
	about errors, use SetIoErr(0L) before calling.

   SEE ALSO
	[FPutC()](autodocs-3.5/dos-library-fputc-2.md), [FRead()](autodocs-3.5/dos-library-fread-2.md), [FPuts()](autodocs-3.5/dos-library-fputs-2.md)

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FRead — dos.library](../autodocs/dos.library.md#fread)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)

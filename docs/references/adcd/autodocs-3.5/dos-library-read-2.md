---
title: dos.library/Read
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-read-2
functions: [Close, FGetC, Open, Read, Write]
libraries: [dos.library]
---

# dos.library/Read

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Read -- Read bytes of data from a file

    SYNOPSIS
	actualLength = Read( file, buffer, length )
	D0		     D1    D2	   D3

	[LONG](autodocs-3.5/include-exec-types-h.md) Read(BPTR, void *, LONG)

    FUNCTION
	Data can be copied using a combination of Read() and [Write()](autodocs-3.5/dos-library-write-2.md).
	Read() reads bytes of information from an opened file (represented
	here by the argument 'file') into the buffer given. The argument
	'length' is the length of the buffer given.

	The value returned is the length of the information actually read.
	So, when 'actualLength' is greater than zero, the value of
	'actualLength' is the the number of characters read. Usually Read
	will try to fill up your buffer before returning. A value of zero
	means that end-of-file has been reached. Errors are indicated by a
	value of -1.

	Note: this is an unbuffered routine (the request is passed directly
	to the filesystem.)  Buffered I/O is more efficient for small
	reads and writes; see [FGetC()](autodocs-3.5/dos-library-fgetc-2.md).

    INPUTS
	file - BCPL pointer to a file handle
	buffer - pointer to buffer
	length - integer

    RESULTS
	actualLength - integer

    SEE ALSO
	[Open()](autodocs-3.5/dos-library-open-2.md), [Close()](autodocs-3.5/dos-library-close-2.md), [Write()](autodocs-3.5/dos-library-write-2.md), [Seek()](autodocs-3.5/dos-library-seek-2.md), [FGetC()](autodocs-3.5/dos-library-fgetc-2.md)

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)

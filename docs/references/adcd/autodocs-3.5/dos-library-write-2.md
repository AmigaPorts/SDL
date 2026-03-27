---
title: dos.library/Write
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-write-2
functions: [Close, FPutC, Open, Read, Write]
libraries: [dos.library]
---

# dos.library/Write

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Write -- Write bytes of data to a file

    SYNOPSIS
	returnedLength =  Write( file, buffer, length )
	D0			 D1    D2      D3

	[LONG](autodocs-3.5/include-exec-types-h.md) Write (BPTR, void *, LONG)

    FUNCTION
	Write() writes bytes of data to the opened file 'file'. 'length'
	indicates the length of data to be transferred; 'buffer' is a
	pointer to the buffer. The value returned is the length of
	information actually written. So, when 'length' is greater than
	zero, the value of 'length' is the number of characters written.
	Errors are indicated by a value of -1.

	Note: this is an unbuffered routine (the request is passed directly
	to the filesystem.)  Buffered I/O is more efficient for small
	reads and writes; see [FPutC()](autodocs-3.5/dos-library-fputc-2.md).

    INPUTS
	file - BCPL pointer to a file handle
	buffer - pointer to the buffer
	length - integer

    RESULTS
	returnedLength - integer

    SEE ALSO
	[Read()](autodocs-3.5/dos-library-read-2.md), [Seek()](autodocs-3.5/dos-library-seek-2.md), [Open()](autodocs-3.5/dos-library-open-2.md), [Close()](autodocs-3.5/dos-library-close-2.md), [FPutC](autodocs-3.5/dos-library-fputc-2.md)

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)

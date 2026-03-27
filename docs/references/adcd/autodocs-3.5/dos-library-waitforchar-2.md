---
title: dos.library/WaitForChar
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-waitforchar-2
functions: [FGetC, Read, WaitForChar]
libraries: [dos.library]
---

# dos.library/WaitForChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	WaitForChar -- Determine if chars arrive within a time limit

    SYNOPSIS
	status = WaitForChar( file, timeout )
	D0		      D1    D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) WaitForChar(BPTR, LONG)

    FUNCTION
	If a character is available to be read from 'file' within the
	time (in microseconds) indicated by 'timeout', WaitForChar()
	returns -1 (TRUE). If a character is available, you can use [Read()](autodocs-3.5/dos-library-read-2.md)
	to read it.  Note that WaitForChar() is only valid when the I/O
	stream is connected to a virtual terminal device. If a character is
	not available within 'timeout', a 0 (FALSE) is returned.

    BUGS
	Due to a bug in the timer.device in V1.2/V1.3, specifying a timeout
	of zero for WaitForChar() can cause the unreliable timer & floppy
	disk operation.

    INPUTS
	file - BCPL pointer to a file handle
	timeout - integer

    RESULTS
	status - boolean

    SEE ALSO
	[Read()](autodocs-3.5/dos-library-read-2.md), [FGetC()](autodocs-3.5/dos-library-fgetc-2.md)

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [WaitForChar — dos.library](../autodocs/dos.library.md#waitforchar)

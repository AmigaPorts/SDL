---
title: dos.library/Close
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-close-2
functions: [Close, Open, OpenFromLock]
libraries: [dos.library]
---

# dos.library/Close

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Close -- Close an open file

    SYNOPSIS
	success = Close( file )
	   D0             D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) Close(BPTR)

    FUNCTION
	The file specified by the file handle is closed. You must close all
	files you explicitly opened, but you must not close inherited file
	handles that are passed to you (each filehandle must be closed once
	and ONLY once).  If Close() fails, the file handle is still
	deallocated and should not be used.

    INPUTS
	file - BCPL pointer to a file handle

    RESULTS
	success - returns if Close() succeeded.  Note that it might fail
		  depending on buffering and whatever IO must be done to
		  close a file being written to.  NOTE: this return value
		  did not exist before V36!

    SEE ALSO
	[Open()](autodocs-3.5/dos-library-open-2.md), [OpenFromLock()](autodocs-3.5/dos-library-openfromlock-2.md)

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [OpenFromLock — dos.library](../autodocs/dos.library.md#openfromlock)

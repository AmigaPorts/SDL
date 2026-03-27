---
title: dos.library/Seek
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-seek-2
functions: [IoErr, Read, Write]
libraries: [dos.library]
---

# dos.library/Seek

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Seek -- Set the current position for reading and writing

    SYNOPSIS
	oldPosition = Seek( file, position, mode )
	D0		    D1	  D2	    D3

	[LONG](autodocs-3.5/include-exec-types-h.md) Seek(BPTR, [LONG](autodocs-3.5/include-exec-types-h.md), LONG)

    FUNCTION
	Seek() sets the read/write cursor for the file 'file' to the
	position 'position'. This position is used by both [Read()](autodocs-3.5/dos-library-read-2.md) and
	[Write()](autodocs-3.5/dos-library-write-2.md) as a place to start reading or writing. The result is the
	current absolute position in the file, or -1 if an error occurs, in
	which case [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) can be used to find more information. 'mode' can
	be OFFSET_BEGINNING, OFFSET_CURRENT or OFFSET_END. It is used to
	specify the relative start position. For example, 20 from current
	is a position 20 bytes forward from current, -20 is 20 bytes back
	from current.

	So that to find out where you are, seek zero from current. The end
	of the file is a Seek() positioned by zero from end. You cannot
	Seek() beyond the end of a file.

    INPUTS
	file - BCPL pointer to a file handle
	position - integer
	mode - integer

    RESULTS
	oldPosition - integer

    BUGS
	The V36 and V37 ROM filesystem (and V36/V37 l:fastfilesystem)
	returns the current position instead of -1 on an error.  It sets
	[IoErr()](autodocs-3.5/dos-library-ioerr-2.md) to 0 on success, and an error code on an error.  This bug
	was fixed in the V39 filesystem.

    SEE ALSO
	[Read()](autodocs-3.5/dos-library-read-2.md), [Write()](autodocs-3.5/dos-library-write-2.md), [SetFileSize()](autodocs-3.5/dos-library-setfilesize-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)

---
title: dos.library/SetFileSize
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setfilesize-2
functions: []
libraries: []
---

# dos.library/SetFileSize

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetFileSize -- Sets the size of a file (V36)

   SYNOPSIS
	newsize = SetFileSize(fh, offset, mode)
	D0                    D1    D2     D3

	[LONG](autodocs-3.5/include-exec-types-h.md) SetFileSize(BPTR, [LONG](autodocs-3.5/include-exec-types-h.md), LONG)

   FUNCTION
	Changes the file size, truncating or extending as needed.  Not all
	handlers may support this; be careful and check the return code.  If
	the file is extended, no values should be assumed for the new bytes.
	If the new position would be before the filehandle's current position
	in the file, the filehandle will end with a position at the
	end-of-file.  If there are other filehandles open onto the file, the
	new size will not leave any filehandle pointing past the end-of-file.
	You can check for this by looking at the new size (which would be
	different than what you requested).

	The seek position should not be changed unless the file is made
	smaller than the current seek position.  However, see BUGS.

	Do NOT count on any specific values to be in any extended area.

   INPUTS
	fh     - File to be truncated/extended.
	offset - Offset from position determined by mode.
	mode   - One of OFFSET_BEGINNING, OFFSET_CURRENT, or OFFSET_END.

   RESULT
	newsize - position of new end-of-file or -1 for error.

   BUGS
	The RAM: filesystem and the normal Amiga filesystem act differently
	in where the file position is left after SetFileSize().  RAM: leaves
	you at the new end of the file (incorrectly), while the Amiga ROM
	filesystem leaves the seek position alone, unless the new position
	is less than the current position, in which case you're left at the
	new EOF.

	The best workaround is to not make any assumptions about the seek
	position after SetFileSize().

   SEE ALSO
	[Seek()](autodocs-3.5/dos-library-seek-2.md)


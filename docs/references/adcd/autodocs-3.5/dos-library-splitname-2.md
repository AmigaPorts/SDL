---
title: dos.library/SplitName
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-splitname-2
functions: [AddPart, FilePart, PathPart, SplitName]
libraries: [dos.library]
---

# dos.library/SplitName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SplitName -- splits out a component of a pathname into a buffer (V36)

   SYNOPSIS
	newpos = SplitName(name, separator, buf, oldpos, size)
	D0                  D1      D2      D3     D4     D5

	WORD SplitName(STRPTR, [UBYTE](autodocs-3.5/include-exec-types-h.md), [STRPTR](autodocs-3.5/include-exec-types-h.md), WORD, LONG)

   FUNCTION
	This routine splits out the next piece of a name from a given file
	name.  Each piece is copied into the buffer, truncating at size-1
	characters.  The new position is then returned so that it may be
	passed in to the next call to splitname.  If the separator is not
	found within 'size' characters, then size-1 characters plus a null will
	be put into the buffer, and the position of the next separator will
	be returned.

	If a a separator cannot be found, -1 is returned (but the characters
	from the old position to the end of the string are copied into the
	buffer, up to a maximum of size-1 characters).  Both strings are
	null-terminated.

	This function is mainly intended to support handlers.

   INPUTS
	name      - Filename being parsed.
	separator - Separator charactor to split by.
	buf       - Buffer to hold separated name.
	oldpos    - Current position in the file.
	size 	  - Size of buf in bytes (including null termination).

   RESULT
	newpos    - New position for next call to splitname.  -1 for last one.

   BUGS
	In V36 and V37, path portions greater than or equal to 'size' caused
	the last character of the portion to be lost when followed by a
	separator.  Fixed for V39 dos.  For V36 and V37, the suggested work-
	around is to call SplitName() with a buffer one larger than normal
	(for example, 32 bytes), and then set buf[size-2] to '0' (for example,
	buf[30] = '0';).

   SEE ALSO
	[FilePart()](autodocs-3.5/dos-library-filepart-2.md), [PathPart()](autodocs-3.5/dos-library-pathpart-2.md), [AddPart()](autodocs-3.5/dos-library-addpart-2.md)

---

## See Also

- [AddPart — dos.library](../autodocs/dos.library.md#addpart)
- [FilePart — dos.library](../autodocs/dos.library.md#filepart)
- [PathPart — dos.library](../autodocs/dos.library.md#pathpart)
- [SplitName — dos.library](../autodocs/dos.library.md#splitname)

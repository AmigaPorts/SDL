---
title: dos.library/FilePart
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-filepart-2
functions: [AddPart, PathPart]
libraries: [dos.library]
---

# dos.library/FilePart

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FilePart -- Returns the last component of a path (V36)

   SYNOPSIS
	fileptr = FilePart( path )
	D0		     D1

	[STRPTR](autodocs-3.5/include-exec-types-h.md) FilePart( [STRPTR](autodocs-3.5/include-exec-types-h.md) )

   FUNCTION
	This function returns a pointer to the last component of a string path
	specification, which will normally be the file name.  If there is only
	one component, it returns a pointer to the beginning of the string.

   INPUTS
	path - pointer to an path string.  May be relative to the current
	       directory or the current disk.

   RESULT
	fileptr - pointer to the last component of the path.

   EXAMPLE
	FilePart("xxx:yyy/zzz/qqq") would return a pointer to the first 'q'.
	FilePart("xxx:yyy") would return a pointer to the first 'y').

   SEE ALSO
	[PathPart()](autodocs-3.5/dos-library-pathpart-2.md), [AddPart()](autodocs-3.5/dos-library-addpart-2.md)

---

## See Also

- [AddPart — dos.library](../autodocs/dos.library.md#addpart)
- [PathPart — dos.library](../autodocs/dos.library.md#pathpart)

---
title: dos.library/PathPart
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-pathpart-2
functions: [AddPart, FilePart]
libraries: [dos.library]
---

# dos.library/PathPart

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PathPart -- Returns a pointer to the end of the next-to-last (V36)
		    component of a path.

   SYNOPSIS
	fileptr = PathPart( path )
	D0		     D1

	[STRPTR](autodocs-3.5/include-exec-types-h.md) PathPart( [STRPTR](autodocs-3.5/include-exec-types-h.md) )

   FUNCTION
	This function returns a pointer to the character after the next-to-last
	component of a path specification, which will normally be the directory
	name.  If there is only one component, it returns a pointer to the
	beginning of the string.  The only real difference between this and
	[FilePart()](autodocs-3.5/dos-library-filepart-2.md) is the handling of '/'.

   INPUTS
	path - pointer to an path string.  May be relative to the current
	       directory or the current disk.

   RESULT
	fileptr - pointer to the end of the next-to-last component of the path.

   EXAMPLE
	PathPart("xxx:yyy/zzz/qqq") would return a pointer to the last '/'.
	PathPart("xxx:yyy") would return a pointer to the first 'y').

   SEE ALSO
	[FilePart()](autodocs-3.5/dos-library-filepart-2.md), [AddPart()](autodocs-3.5/dos-library-addpart-2.md)

---

## See Also

- [AddPart — dos.library](../autodocs/dos.library.md#addpart)
- [FilePart — dos.library](../autodocs/dos.library.md#filepart)

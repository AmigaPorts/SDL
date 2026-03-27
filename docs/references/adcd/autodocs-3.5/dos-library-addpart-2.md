---
title: dos.library/AddPart
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-addpart-2
functions: [FilePart, PathPart]
libraries: [dos.library]
---

# dos.library/AddPart

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddPart -- Appends a file/dir to the end of a path (V36)

   SYNOPSIS
	success = AddPart( dirname, filename, size )
	D0                   D1        D2      D3

	[BOOL](autodocs-3.5/include-exec-types-h.md) AddPart( [STRPTR](autodocs-3.5/include-exec-types-h.md), [STRPTR](autodocs-3.5/include-exec-types-h.md), ULONG )

   FUNCTION
	This function adds a file, directory, or subpath name to a directory
	path name taking into account any required separator characters.  If
	filename is a fully-qualified path it will totally replace the current
	value of dirname.

   INPUTS
	dirname  - the path to add a file/directory name to.
	filename - the filename or directory name to add.  May be a relative
		   pathname from the current directory (example: foo/bar).
		   Can deal with leading '/'(s), indicating one directory up
		   per '/', or with a ':', indicating it's relative to the
		   root of the appropriate volume.
	size     - size in bytes of the space allocated for dirname.  Must
		   not be 0.

   RESULT
	success - non-zero for ok, FALSE if the buffer would have overflowed.
		  If an overflow would have occured, dirname will not be
		  changed.

   BUGS
	Doesn't check if a subpath is legal (i.e. doesn't check for ':'s) and
	doesn't handle leading '/'s in 2.0 through 2.02 (V36).  V37 fixes
	this, allowing filename to be any path, including absolute.

   SEE ALSO
	[FilePart()](autodocs-3.5/dos-library-filepart-2.md), [PathPart()](autodocs-3.5/dos-library-pathpart-2.md)

---

## See Also

- [FilePart — dos.library](../autodocs/dos.library.md#filepart)
- [PathPart — dos.library](../autodocs/dos.library.md#pathpart)

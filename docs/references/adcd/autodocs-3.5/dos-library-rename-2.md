---
title: dos.library/Rename
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-rename-2
functions: [Relabel, Rename]
libraries: [dos.library]
---

# dos.library/Rename

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Rename -- Rename a directory or file

    SYNOPSIS
	success = Rename( oldName, newName )
	D0		  D1	   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) Rename(STRPTR, STRPTR)

    FUNCTION
	Rename() attempts to rename the file or directory specified as
	'oldName' with the name 'newName'. If the file or directory
	'newName' exists, Rename() fails and returns an error. Both
	'oldName' and the 'newName' can contain a directory specification.
	In this case, the file will be moved from one directory to another.

	Note: it is impossible to Rename() a file from one volume to
	another.

    INPUTS
	oldName - pointer to a null-terminated string
	newName - pointer to a null-terminated string

    RESULTS
	success - boolean

    SEE ALSO
	[Relabel()](autodocs-3.5/dos-library-relabel-2.md)

---

## See Also

- [Relabel — dos.library](../autodocs/dos.library.md#relabel)
- [Rename — dos.library](../autodocs/dos.library.md#rename)

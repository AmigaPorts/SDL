---
title: dos.library/SetFileDate
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setfiledate-2
functions: [DateStamp]
libraries: [dos.library]
---

# dos.library/SetFileDate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetFileDate -- Sets the modification date for a file or dir (V36)

   SYNOPSIS
	success = SetFileDate(name, date)
	D0                     D1    D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetFileDate(STRPTR, struct [DateStamp](autodocs-3.5/include-dos-dos-h.md) *)

   FUNCTION
	Sets the file date for a file or directory.  Note that for the Old
	File System and the Fast File System, the date of the root directory
	cannot be set.  Other filesystems may not support setting the date
	for all files/directories.

   INPUTS
	name - Name of object
	date - New modification date

   RESULT
	success - Success/failure indication

   SEE ALSO
	[DateStamp()](autodocs-3.5/dos-library-datestamp-2.md), [Examine()](autodocs-3.5/dos-library-examine-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [ExAll()](autodocs-3.5/dos-library-exall-2.md)

---

## See Also

- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)

---
title: dos.library/ExamineFH
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-examinefh-2
functions: [AllocDosObject, Open]
libraries: [dos.library]
---

# dos.library/ExamineFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ExamineFH -- Gets information on an open file (V36)

   SYNOPSIS
	success = ExamineFH(fh, fib)
	D0                  D1  D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) ExamineFH(BPTR, struct [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md) *)

   FUNCTION
	Examines a filehandle and returns information about the file in the
	[FileInfoBlock](autodocs-3.5/include-dos-dos-h.md).  There are no guarantees as to whether the fib_Size
	field will reflect any changes made to the file size it was opened,
	though filesystems should attempt to provide up-to-date information
	for it.

   INPUTS
	fh  - Filehandle you wish to examine
	fib - [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md), must be longword aligned.

   RESULT
	success - Success/failure indication

   SEE ALSO
	[Examine()](autodocs-3.5/dos-library-examine-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [ExAll()](autodocs-3.5/dos-library-exall-2.md), [Open()](autodocs-3.5/dos-library-open-2.md), [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md)

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [Open — dos.library](../autodocs/dos.library.md#open)

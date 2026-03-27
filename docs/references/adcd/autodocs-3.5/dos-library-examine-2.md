---
title: dos.library/Examine
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-examine-2
functions: [AllocDosObject, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/Examine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Examine -- Examine a directory or file associated with a lock

    SYNOPSIS
	success = Examine( lock, [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md) )
	D0		    D1	      D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) Examine(BPTR,struct [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md) *)

    FUNCTION
	Examine() fills in information in the [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md) concerning the
	file or directory associated with the lock. This information
	includes the name, size, creation date and whether it is a file or
	directory.  [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md) must be longword aligned.  Examine() gives
	a return code of zero if it fails.

	You may make a local copy of the [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md), as long as it is
	never passed to [ExNext()](autodocs-3.5/dos-library-exnext-2.md).

    INPUTS
	lock	  - BCPL pointer to a lock
	infoBlock - pointer to a [FileInfoBlock](autodocs-3.5/include-dos-dos-h.md) (MUST be longword aligned)

    RESULTS
	success - boolean

    SPECIAL NOTE
	[FileInfoBlock](autodocs-3.5/include-dos-dos-h.md) must be longword-aligned.  [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md) will
	allocate them correctly for you.

    SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [ExamineFH()](autodocs-3.5/dos-library-examinefh-2.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md), [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md),
	[ExAll()](autodocs-3.5/dos-library-exall-2.md)

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

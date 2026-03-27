---
title: dos.library/SetProtection
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setprotection-2
functions: [SetComment, SetProtection]
libraries: [dos.library]
---

# dos.library/SetProtection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetProtection -- Set protection for a file or directory

    SYNOPSIS
	success = SetProtection( name, mask )
	D0			 D1    D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetProtection (STRPTR, LONG)

    FUNCTION
	SetProtection() sets the protection attributes on a file or
	directory.  See [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md) for a listing of protection bits.

	Before V36, the ROM filesystem didn't respect the [Read](autodocs-3.5/dos-library-read-2.md) and [Write](autodocs-3.5/dos-library-write-2.md)
	bits.  In V36 or later and in the FFS, the [Read](autodocs-3.5/dos-library-read-2.md) and [Write](autodocs-3.5/dos-library-write-2.md)
	bits are respected.

	The archive bit should be cleared by the filesystem whenever the file
	is changed.  Backup utilities will generally set the bit after
	backing up each file.

	The V36 Shell looks at the execute bit, and will refuse to execute
	a file if it is set.

	Other bits will be defined in the [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md) include files.  Rather
	than referring to bits by number you should use the definitions in
	[<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md).

    INPUTS
	name - pointer to a null-terminated string
	mask - the protection mask required

    RESULTS
	success - boolean

    SEE ALSO
	[SetComment()](autodocs-3.5/dos-library-setcomment-2.md), [Examine()](autodocs-3.5/dos-library-examine-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md)

---

## See Also

- [SetComment — dos.library](../autodocs/dos.library.md#setcomment)
- [SetProtection — dos.library](../autodocs/dos.library.md#setprotection)

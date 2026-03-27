---
title: dos.library/NameFromFH
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-namefromfh-2
functions: [NameFromFH, NameFromLock]
libraries: [dos.library]
---

# dos.library/NameFromFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NameFromFH -- Get the name of an open filehandle (V36)

   SYNOPSIS
	success = NameFromFH(fh, buffer, len)
	D0                   D1    D2    D3

	[BOOL](autodocs-3.5/include-exec-types-h.md) NameFromFH(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), LONG)

   FUNCTION
	Returns a fully qualified path for the filehandle.  This routine is
	guaranteed not to write more than len characters into the buffer.  The
	name will be null-terminated.  See [NameFromLock()](autodocs-3.5/dos-library-namefromlock-2.md) for more information.

	Note: Older filesystems that don't support [ExamineFH()](autodocs-3.5/dos-library-examinefh-2.md) will cause
	NameFromFH() to fail with ERROR_ACTION_NOT_SUPPORTED.

   INPUTS
	fh     - [Lock](autodocs-3.5/dos-library-lock-2.md) of object to be examined.
	buffer - Buffer to store name.
	len    - Length of buffer.

   RESULT
	success - Success/failure indicator.

   SEE ALSO
	[NameFromLock()](autodocs-3.5/dos-library-namefromlock-2.md), [ExamineFH()](autodocs-3.5/dos-library-examinefh-2.md)

---

## See Also

- [NameFromFH — dos.library](../autodocs/dos.library.md#namefromfh)
- [NameFromLock — dos.library](../autodocs/dos.library.md#namefromlock)

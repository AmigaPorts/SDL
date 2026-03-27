---
title: dos.library/ParentOfFH
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-parentoffh-2
functions: [DupLockFromFH, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/ParentOfFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ParentOfFH -- returns a lock on the parent directory of a file (V36)

   SYNOPSIS
	lock = ParentOfFH(fh)
	D0               D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) ParentOfFH(BPTR)

   FUNCTION
	Returns a shared lock on the parent directory of the filehandle.

   INPUTS
	fh   - Filehandle you want the parent of.

   RESULT
	lock - [Lock](autodocs-3.5/dos-library-lock-2.md) on parent directory of the filehandle or NULL for failure.

   SEE ALSO
	Parent(), [Lock()](autodocs-3.5/dos-library-lock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md) [DupLockFromFH()](autodocs-3.5/dos-library-duplockfromfh-2.md)

---

## See Also

- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

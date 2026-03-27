---
title: dos.library/DupLockFromFH
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-duplockfromfh-2
functions: [DupLock, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/DupLockFromFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DupLockFromFH -- Gets a lock on an open file (V36)

   SYNOPSIS
	lock = DupLockFromFH(fh)
	D0                   D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) DupLockFromFH(BPTR)

   FUNCTION
	Obtain a lock on the object associated with fh.  Only works if the
	file was opened using a non-exclusive mode.  Other restrictions may be
	placed on success by the filesystem.

   INPUTS
	fh   - Opened file for which to obtain the lock

   RESULT
	lock - Obtained lock or NULL for failure

   SEE ALSO
	[DupLock()](autodocs-3.5/dos-library-duplock-2.md), [Lock()](autodocs-3.5/dos-library-lock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md)

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

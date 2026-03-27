---
title: dos.library/DupLock
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-duplock-2
functions: [DupLock, DupLockFromFH, Lock, ParentOfFH, UnLock]
libraries: [dos.library]
---

# dos.library/DupLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DupLock -- Duplicate a lock

    SYNOPSIS
	lock = DupLock( lock )
	D0		D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) DupLock(BPTR)

    FUNCTION
	DupLock() is passed a shared filing system lock.  This is the ONLY
	way to obtain a duplicate of a lock... simply copying is not
	allowed.

	Another lock to the same object is then returned.  It is not
	possible to create a copy of a exclusive lock.

	A zero return indicates failure.

    INPUTS
	lock - BCPL pointer to a lock

    RESULTS
	newLock - BCPL pointer to a lock

    SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md), [DupLockFromFH()](autodocs-3.5/dos-library-duplockfromfh-2.md), [ParentOfFH()](autodocs-3.5/dos-library-parentoffh-2.md)

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ParentOfFH — dos.library](../autodocs/dos.library.md#parentoffh)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

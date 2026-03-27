---
title: dos.library/UnLock
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-unlock-2
functions: [CreateDir, DupLock, DupLockFromFH, Lock, ParentOfFH, UnLock]
libraries: [dos.library]
---

# dos.library/UnLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnLock -- Unlock a directory or file

    SYNOPSIS
	UnLock( lock )
		D1

	void UnLock(BPTR)

    FUNCTION
	The filing system lock (obtained from [Lock()](autodocs-3.5/dos-library-lock-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md), or
	[CreateDir()](autodocs-3.5/dos-library-createdir-2.md)) is removed and deallocated.

    INPUTS
	lock - BCPL pointer to a lock

    NOTE
	passing zero to UnLock() is harmless

    SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md), [ParentOfFH()](autodocs-3.5/dos-library-parentoffh-2.md), [DupLockFromFH()](autodocs-3.5/dos-library-duplockfromfh-2.md)

---

## See Also

- [CreateDir — dos.library](../autodocs/dos.library.md#createdir)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ParentOfFH — dos.library](../autodocs/dos.library.md#parentoffh)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

---
title: dos.library/Lock
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-lock-2
functions: [ChangeMode, DupLock, DupLockFromFH, Lock, NameFromLock, UnLock]
libraries: [dos.library]
---

# dos.library/Lock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Lock -- Lock a directory or file

    SYNOPSIS
	lock  = Lock( name, accessMode )
	D0	      D1	D2

	[BPTR](autodocs-3.5/include-dos-dos-h.md) Lock(STRPTR, LONG)

    FUNCTION
	A filing system lock on the file or directory 'name' is returned if
	possible.

	If the accessMode is ACCESS_READ, the lock is a shared read lock;
	if the accessMode is ACCESS_WRITE then it is an exclusive write
	lock.  Do not use random values for mode.

	If Lock() fails (that is, if it cannot obtain a filing system lock
	on the file or directory) it returns a zero.

	Tricky assumptions about the internal format of a lock are unwise,
	as are any attempts to use the fl_Link or fl_Access fields.

    INPUTS
	name	   - pointer to a null-terminated string
	accessMode - integer

    RESULTS
	lock - BCPL pointer to a lock

    SEE ALSO
	[UnLock()](autodocs-3.5/dos-library-unlock-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md), [ChangeMode()](autodocs-3.5/dos-library-changemode-2.md), [NameFromLock()](autodocs-3.5/dos-library-namefromlock-2.md), [DupLockFromFH()](autodocs-3.5/dos-library-duplockfromfh-2.md)

---

## See Also

- [ChangeMode — dos.library](../autodocs/dos.library.md#changemode)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [NameFromLock — dos.library](../autodocs/dos.library.md#namefromlock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

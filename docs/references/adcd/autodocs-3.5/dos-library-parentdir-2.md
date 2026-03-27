---
title: dos.library/ParentDir
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-parentdir-2
functions: [DupLock, DupLockFromFH, Lock, ParentDir, ParentOfFH, UnLock]
libraries: [dos.library]
---

# dos.library/ParentDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ParentDir -- Obtain the parent of a directory or file

    SYNOPSIS
	newlock = ParentDir( lock )
	D0		     D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) ParentDir(BPTR)

    FUNCTION
	The argument 'lock' is associated with a given file or directory.
	ParentDir() returns 'newlock' which is associated the parent
	directory of 'lock'.

	Taking the ParentDir() of the root of the current filing system
	returns a NULL (0) lock.  Note this 0 lock represents the root of
	file system that you booted from (which is, in effect, the parent
	of all other file system roots.)

    INPUTS
	lock - BCPL pointer to a lock

    RESULTS
	newlock - BCPL pointer to a lock

    SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md), [ParentOfFH()](autodocs-3.5/dos-library-parentoffh-2.md), [DupLockFromFH()](autodocs-3.5/dos-library-duplockfromfh-2.md)

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ParentDir — dos.library](../autodocs/dos.library.md#parentdir)
- [ParentOfFH — dos.library](../autodocs/dos.library.md#parentoffh)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

---
title: dos.library/CurrentDir
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-currentdir-2
functions: [DupLock, Lock, Open, UnLock]
libraries: [dos.library]
---

# dos.library/CurrentDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CurrentDir -- Make a directory lock the current directory

    SYNOPSIS
	oldLock = CurrentDir( lock )
	D0		      D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) CurrentDir(BPTR)

    FUNCTION
	CurrentDir() causes a directory associated with a lock to be made
	the current directory.	The old current directory lock is returned.

	A value of zero is a valid result here, this 0 lock represents the
	root of file system that you booted from.

	Any call that has to [Open()](autodocs-3.5/dos-library-open-2.md) or [Lock()](autodocs-3.5/dos-library-lock-2.md) files (etc) requires that
	the current directory be a valid lock or 0.

    INPUTS
	lock - BCPL pointer to a lock

    RESULTS
	oldLock - BCPL pointer to a lock

    SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md), [Open()](autodocs-3.5/dos-library-open-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md)

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

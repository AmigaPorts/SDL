---
title: dos.library/AssignLock
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-assignlock-2
functions: [AssignAdd, AssignLate, AssignLock, AssignPath, DupLock, Lock, RemAssignList]
libraries: [dos.library]
---

# dos.library/AssignLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AssignLock -- Creates an assignment to a locked object (V36)

   SYNOPSIS
	success = AssignLock(name,lock)
	D0                    D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) AssignLock(STRPTR,BPTR)

   FUNCTION
	Sets up an assign of a name to a given lock.  Passing NULL for a lock
	cancels any outstanding assign to that name.  If an assign entry of
	that name is already on the list, this routine replaces that entry.  If
	an entry is on the list that conflicts with the new assign, then a
	failure code is returned.

	NOTE: you should not use the lock in any way after making this call
	successfully.  It becomes the assign, and will be unlocked by the
	system when the assign is removed.  If you need to keep the lock,
	pass a lock from [DupLock()](autodocs-3.5/dos-library-duplock-2.md) to AssignLock().

   INPUTS
	name - Name of device to assign lock to (without trailing ':')
	lock - [Lock](autodocs-3.5/dos-library-lock-2.md) associated with the assigned name

   RESULT
	success - Success/failure indicator.  On failure, the lock is not
		  unlocked.

   SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [AssignAdd()](autodocs-3.5/dos-library-assignadd-2.md), [AssignPath()](autodocs-3.5/dos-library-assignpath-2.md), [AssignLate()](autodocs-3.5/dos-library-assignlate-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md),
	[RemAssignList()](autodocs-3.5/dos-library-remassignlist-2.md)

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [RemAssignList — dos.library](../autodocs/dos.library.md#remassignlist)

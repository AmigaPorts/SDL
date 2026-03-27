---
title: dos.library/AssignAdd
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-assignadd-2
functions: [AssignLate, AssignLock, AssignPath, DupLock, Lock, RemAssignList]
libraries: [dos.library]
---

# dos.library/AssignAdd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AssignAdd -- Adds a lock to an assign for multi-directory assigns (V36)

   SYNOPSIS
	success = AssignAdd(name,lock)
	D0                   D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) AssignAdd(STRPTR,BPTR)

   FUNCTION
	Adds a lock to an assign, making or adding to a multi-directory
	assign.  Note that this only will succeed on an assign created with
	[AssignLock()](autodocs-3.5/dos-library-assignlock-2.md), or an assign created with [AssignLate()](autodocs-3.5/dos-library-assignlate-2.md) which has been
	resolved (converted into a AssignLock()-assign).

	NOTE: you should not use the lock in any way after making this call
	successfully.  It becomes the part of the assign, and will be unlocked
	by the system when the assign is removed.  If you need to keep the
	lock, pass a lock from [DupLock()](autodocs-3.5/dos-library-duplock-2.md) to [AssignLock()](autodocs-3.5/dos-library-assignlock-2.md).

   INPUTS
	name - Name of device to assign lock to (without trailing ':')
	lock - [Lock](autodocs-3.5/dos-library-lock-2.md) associated with the assigned name

   RESULT
	success - Success/failure indicator.  On failure, the lock is not
		  unlocked.

   SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [AssignLock()](autodocs-3.5/dos-library-assignlock-2.md), [AssignPath()](autodocs-3.5/dos-library-assignpath-2.md), [AssignLate()](autodocs-3.5/dos-library-assignlate-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md),
	[RemAssignList()](autodocs-3.5/dos-library-remassignlist-2.md)

---

## See Also

- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [RemAssignList — dos.library](../autodocs/dos.library.md#remassignlist)

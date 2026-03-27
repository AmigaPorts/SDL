---
title: dos.library/RemAssignList
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-remassignlist-2
functions: [AssignAdd, AssignLate, AssignLock, AssignPath, DupLock, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/RemAssignList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemAssignList -- [Remove](autodocs-3.5/exec-library-remove-2.md) an entry from a multi-dir assign (V36)

   SYNOPSIS
	success = RemAssignList(name,lock)
	D0                  	 D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) RemAssignList(STRPTR,BPTR)

   FUNCTION
	Removes an entry from a multi-directory assign.  The entry removed is
	the first one for which [SameLock](autodocs-3.5/dos-library-samelock-2.md) with 'lock' returns that they are on
	the same object.  The lock for the entry in the list is unlocked (not
	the entry passed in).

   INPUTS
	name - Name of device to remove lock from (without trailing ':')
	lock - [Lock](autodocs-3.5/dos-library-lock-2.md) associated with the object to remove from the list

   RESULT
	success - Success/failure indicator.

   BUGS
	In V36 through V39.23 dos, it would fail to remove the first lock
	in the assign.  Fixed in V39.24 dos (after the V39.106 kickstart).

   SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [AssignLock()](autodocs-3.5/dos-library-assignlock-2.md), [AssignPath()](autodocs-3.5/dos-library-assignpath-2.md), [AssignLate()](autodocs-3.5/dos-library-assignlate-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md),
	[AssignAdd()](autodocs-3.5/dos-library-assignadd-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md)

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)

---
title: dos.library/AssignLate
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-assignlate-2
functions: [AssignAdd, AssignLock, AssignPath, Lock]
libraries: [dos.library]
---

# dos.library/AssignLate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AssignLate -- Creates an assignment to a specified path later (V36)

   SYNOPSIS
	success = AssignLate(name,path)
	D0                    D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) AssignLate(STRPTR,STRPTR)

   FUNCTION
	Sets up a assignment that is expanded upon the FIRST reference to the
	name.  The path (a string) would be attached to the node.  When
	the name is referenced (Open("FOO:xyzzy"...), the string will be used
	to determine where to set the assign to, and if the directory can be
	locked, the assign will act from that point on as if it had been
	created by [AssignLock()](autodocs-3.5/dos-library-assignlock-2.md).

	A major advantage is assigning things to unmounted volumes, which
	will be requested upon access (useful in startup sequences).

   INPUTS
	name - Name of device to be assigned (without trailing ':')
	path - Name of late assignment to be resolved on the first reference.

   RESULT
	success - Success/failure indicator of the operation

   SEE ALSO
	[Lock()](autodocs-3.5/dos-library-lock-2.md), [AssignAdd()](autodocs-3.5/dos-library-assignadd-2.md), [AssignPath()](autodocs-3.5/dos-library-assignpath-2.md), [AssignLock()](autodocs-3.5/dos-library-assignlock-2.md),

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [Lock — dos.library](../autodocs/dos.library.md#lock)

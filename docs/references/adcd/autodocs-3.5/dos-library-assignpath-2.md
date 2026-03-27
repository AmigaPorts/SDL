---
title: dos.library/AssignPath
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-assignpath-2
functions: [AssignAdd, AssignLate, AssignLock, AssignPath, Open]
libraries: [dos.library]
---

# dos.library/AssignPath

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AssignPath -- Creates an assignment to a specified path (V36)

   SYNOPSIS
	success = AssignPath(name,path)
	D0                    D1   D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) AssignPath(STRPTR,STRPTR)

   FUNCTION
	Sets up a assignment that is expanded upon EACH reference to the name.
	This is implemented through a new device list type (DLT_ASSIGNPATH, or
	some such).  The path (a string) would be attached to the node.  When
	the name is referenced (Open("FOO:xyzzy"...), the string will be used
	to determine where to do the open.  No permanent lock will be part of
	it.  For example, you could AssignPath() c2: to df2:c, and references
	to c2: would go to df2:c, even if you change disks.

	The other major advantage is assigning things to unmounted volumes,
	which will be requested upon access (useful in startup sequences).

   INPUTS
	name - Name of device to be assigned (without trailing ':')
	path - Name of late assignment to be resolved at each reference

   RESULT
	success - Success/failure indicator of the operation

   SEE ALSO
	[AssignAdd()](autodocs-3.5/dos-library-assignadd-2.md), [AssignLock()](autodocs-3.5/dos-library-assignlock-2.md), [AssignLate()](autodocs-3.5/dos-library-assignlate-2.md), [Open()](autodocs-3.5/dos-library-open-2.md)

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [Open — dos.library](../autodocs/dos.library.md#open)

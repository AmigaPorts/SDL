---
title: rexxsyslib.library/UnlockRexxBase
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-unlockrexxbase-2
functions: [LockRexxBase]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/UnlockRexxBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnlockRexxBase - Release a semaphore lock on the RexxBase structure

    SYNOPSIS
	UnlockRexxBase(resource)
	               D0

	VOID UnlockRexxBase(ULONG);

    FUNCTION
	Releases the specified resource in the ARexx library base.

    INPUTS
	resource - A manifest constant defining which resource to unlock.
	           This value *MUST* match the value used in the matching
	           [LockRexxBase()](autodocs-3.5/rexxsyslib-library-lockrexxbase-2.md) call.

    NOTES
	Currently, only ZERO resource type is available.  You *MUST* make
	sure that you do not call this function with an undefined value
	as it may become defined at some future date and cause unwanted
	behavior.  You *MUST* make sure that you only call this function
	after a matching call to [LockRexxBase()](autodocs-3.5/rexxsyslib-library-lockrexxbase-2.md) was made.

    SEE ALSO
	[LockRexxBase()](autodocs-3.5/rexxsyslib-library-lockrexxbase-2.md)


    BUGS

---

## See Also

- [LockRexxBase — rexxsyslib.library](../autodocs/rexxsyslib.library.md#lockrexxbase)

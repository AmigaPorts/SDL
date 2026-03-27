---
title: rexxsyslib.library/LockRexxBase
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-lockrexxbase-2
functions: [UnlockRexxBase]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/LockRexxBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LockRexxBase - Obtain a semaphore lock on the RexxBase structure

    SYNOPSIS
	LockRexxBase(resource)
	             D0

	VOID LockRexxBase(ULONG);

    FUNCTION
	Secures the specified resource in the ARexx library base.

    INPUTS
	resource - A manifest constant defining which resource to lock.
	           ZERO locks all resources.

    NOTES
	Currently, only ZERO resource type is available.  You *MUST* make
	sure that you do not call this function with an undefined value
	as it may become defined at some future date and cause unwanted
	behavior.

    SEE ALSO
	[UnlockRexxBase()](autodocs-3.5/rexxsyslib-library-unlockrexxbase-2.md)


    BUGS

---

## See Also

- [UnlockRexxBase — rexxsyslib.library](../autodocs/rexxsyslib.library.md#unlockrexxbase)

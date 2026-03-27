---
title: intuition.library/UnlockIBase
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-unlockibase-2
functions: [LockIBase]
libraries: [intuition.library]
---

# intuition.library/UnlockIBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnlockIBase -- Surrender an Intuition lock gotten by [LockIBase()](autodocs-3.5/intuition-library-lockibase-2.md).

    SYNOPSIS
	UnlockIBase( [Lock](autodocs-3.5/dos-library-lock-2.md) )
		     A0

	VOID UnlockIBase( ULONG );


    FUNCTION
	Surrenders lock gotten by [LockIBase()](autodocs-3.5/intuition-library-lockibase-2.md).

	Calling this function when you do not own the specified lock will
	immediately crash the system.

    INPUTS
	The value returned by [LockIBase()](autodocs-3.5/intuition-library-lockibase-2.md) should be passed to this function,
	to specify which internal lock is to be freed.

	Note that the parameter is passed in A0, not D0, for historical reasons.

    RESULT
	None

    BUGS

    SEE ALSO
	[LockIBase()](autodocs-3.5/intuition-library-lockibase-2.md)

---

## See Also

- [LockIBase — intuition.library](../autodocs/intuition.library.md#lockibase)

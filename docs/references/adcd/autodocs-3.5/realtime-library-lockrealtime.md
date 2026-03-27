---
title: realtime.library/LockRealTime
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-lockrealtime
functions: []
libraries: []
---

# realtime.library/LockRealTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LockRealTime -- prevent other tasks from changing internal structures.
			(V37)

   SYNOPSIS
	lockHandle = LockRealTime(lockType);
	D0                        D0

	[APTR](autodocs-3.5/include-exec-types-h.md) LockRealTime(ULONG);

   FUNCTION
	This routine will lock the internal sempahores in the RealTime library.
	If they are already locked by another task, this routine will wait
	until they are free.

   INPUTS
	lockType - the internal list to lock. Only RT_CONDUCTORS is
		   currently defined.

   RESULT
	handle - if lockType is valid, returns a value that must be passed
		 later to [UnlockRealTime()](autodocs-3.5/realtime-library-unlockrealtime.md) to unlock the list. Returns NULL
		 if passed an invalid lock type.

   SEE ALSO
	[UnlockRealTime()](autodocs-3.5/realtime-library-unlockrealtime.md)


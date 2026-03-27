---
title: realtime.library/NextConductor
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-nextconductor
functions: []
libraries: []
---

# realtime.library/NextConductor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NextConductor -- return the next conductor on realtime.library's
			 conductor list. (V37)

   SYNOPSIS
	conductor = NextConductor(previousConductor);
	D0			  A0

	struct [Conductor](autodocs-3.5/include-libraries-realtime-h.md) *NextConductor(struct [Conductor](autodocs-3.5/include-libraries-realtime-h.md) *);

   FUNCTION
	Returns the next conductor on realtime.library's conductor list. If
	previousConductor is NULL, returns the first conductor in the list.
	Returns NULL if no more conductors.

	The conductor list must be locked before calling this function. This
	is done by calling LockRealTime(RT_CONDUCTORS).

   INPUTS
	previousConductor - previous conductor or NULL to get first conductor.

   RESULTS
	conductor - next conductor on the list, or NULL if no more.

   SEE ALSO
	[FindConductor()](autodocs-3.5/realtime-library-findconductor.md), [LockRealTime()](autodocs-3.5/realtime-library-lockrealtime.md), [UnlockRealTime()](autodocs-3.5/realtime-library-unlockrealtime.md)


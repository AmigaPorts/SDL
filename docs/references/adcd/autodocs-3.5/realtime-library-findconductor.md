---
title: realtime.library/FindConductor
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-findconductor
functions: []
libraries: []
---

# realtime.library/FindConductor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindConductor -- find a conductor by name. (V37)

   SYNOPSIS
	conductor = FindConductor(name);
	D0			  A0

	struct [Conductor](autodocs-3.5/include-libraries-realtime-h.md) *FindConductor(STRPTR);

   FUNCTION
	Returns the conductor with the given name or NULL if not found.

	The conductor list must be locked before calling this function. This
	is done by calling LockRealTime(RT_CONDUCTORS).

   INPUTS
	name - name of conductor to find.

   RESULTS
	conductor - pointer to a [Conductor](autodocs-3.5/include-libraries-realtime-h.md) structure, or NULL if not found.

   SEE ALSO
	[NextConductor()](autodocs-3.5/realtime-library-nextconductor.md), [LockRealTime()](autodocs-3.5/realtime-library-lockrealtime.md), [UnlockRealTime()](autodocs-3.5/realtime-library-unlockrealtime.md)


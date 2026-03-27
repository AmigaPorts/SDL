---
title: realtime.library/UnlockRealTime
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-unlockrealtime
functions: []
libraries: []
---

# realtime.library/UnlockRealTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UnlockRealTime -- unlock internal lists. (V37)

   SYNOPSIS
	UnlockRealTime(lockHandle);
	               A0

	VOID UnlockRealTime(APTR);

   FUNCTION
	Undoes the effects of [LockRealTime()](autodocs-3.5/realtime-library-lockrealtime.md).

   INPUTS
	lockHandle - value returned by [LockRealTime()](autodocs-3.5/realtime-library-lockrealtime.md). May be NULL.

   SEE ALSO
	[LockRealTime()](autodocs-3.5/realtime-library-lockrealtime.md)


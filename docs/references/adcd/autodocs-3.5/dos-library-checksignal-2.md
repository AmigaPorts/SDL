---
title: dos.library/CheckSignal
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-checksignal-2
functions: []
libraries: []
---

# dos.library/CheckSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CheckSignal -- Checks for break signals (V36)

   SYNOPSIS
	signals = CheckSignal(mask)
	D0		      D1

	ULONG CheckSignal(ULONG)

   FUNCTION
	This function checks to see if any signals specified in the mask have
	been set and if so, returns them.  Otherwise it returns FALSE.
	All signals specified in mask will be cleared.

   INPUTS
	mask    - Signals to check for.

   RESULT
	signals - Signals specified in mask that were set.

   SEE ALSO


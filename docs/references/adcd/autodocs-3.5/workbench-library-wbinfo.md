---
title: workbench.library/WBInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-wbinfo
functions: []
libraries: []
---

# workbench.library/WBInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WBInfo - Bring up the Information requester                     (V39)

   SYNOPSIS
	worked = WBInfo(lock, name, screen)
	d0              a0    a1    a2

	ULONG WBInfo(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *);

   FUNCTION
	This is the LVO that Workbench calls to bring up the Icon Information
	requester.  External applications may also call this requester.
	In addition, if someone were to wish to replace this requester
	with another one, they could do so via a [SetFunction](autodocs-3.5/exec-library-setfunction-2.md).

   INPUTS
	lock   - A lock on the parent directory
	name   - The name of the icon contained within above directory
	screen - A screen pointer on which the requester is to show up

   RESULTS
	worked - Returns TRUE if the requester came up, FALSE if it did not.

   NOTE
	Note that this LVO may be called many times by different tasks
	before other calls return.  Thus, the code must be 100% re-entrant.

   SEE ALSO
	icon.library


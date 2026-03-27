---
title: graphics.library/SetChipRev
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setchiprev
functions: []
libraries: []
---

# graphics.library/SetChipRev

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetChipRev -- turns on the features of a Chip Set  (V39)

   SYNOPSIS
	chiprevbits = SetChipRev(ChipRev)
	                           d0

	ULONG SetChipRev(ULONG);

   FUNCTION
	Enables the features of the requested Chip Set if available,
	and updates the graphics database accordingly.

   INPUTS
	ChipRev - Chip Rev that you would like to be enabled.

   RESULT
	chiprevbits - Actual bits set in GfxBase->ChipRevBits0.

   NOTES
	This routine should only be called once. It will be called by the system
	in the startup-sequence, but is included in the autodocs for authors
	of bootblock-games that wish to take advantage of post-ECS features.

   SEE ALSO
	[<graphics/gfxbase.h>](autodocs-3.5/include-graphics-gfxbase-h.md)


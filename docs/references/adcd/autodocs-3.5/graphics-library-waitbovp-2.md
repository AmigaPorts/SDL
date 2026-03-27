---
title: graphics.library/WaitBOVP
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-waitbovp-2
functions: [VBeamPos, WaitTOF]
libraries: [graphics.library]
---

# graphics.library/WaitBOVP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WaitBOVP -- [Wait](autodocs-3.5/exec-library-wait-2.md) till vertical beam reached bottom of
		    this viewport.

   SYNOPSIS
	WaitBOVP( vp )
		  a0

	void WaitBOVP( struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) * );

   FUNCTION
	Returns when the vertical beam has reached the bottom of this viewport

   INPUTS
	vp - pointer to [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure

   RESULT
	This function will return sometime after the beam gets beyond
	the bottom of the viewport.  Depending on the multitasking load
	of the system, the actual beam position may be different than
	what would be expected in a lightly loaded system.

   BUGS
	Horrors! This function currently busy waits waiting for the
	beam to get to the right place.  It should use the copper
	interrupt to trigger and send signals like [WaitTOF](autodocs-3.5/graphics-library-waittof-2.md) does.

   SEE ALSO
	[WaitTOF()](autodocs-3.5/graphics-library-waittof-2.md) [VBeamPos()](autodocs-3.5/graphics-library-vbeampos-2.md)

---

## See Also

- [VBeamPos — graphics.library](../autodocs/graphics.library.md#vbeampos)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)

---
title: graphics.library/GetVPModeID
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getvpmodeid-2
functions: [ModeNotAvailable]
libraries: [graphics.library]
---

# graphics.library/GetVPModeID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetVPModeID -- get the 32 bit DisplayID from a [ViewPort](autodocs-3.5/include-graphics-view-h.md). (V36)

   SYNOPSIS
	modeID =  GetVPModeID( vp )
	d0		       a0

	ULONG GetVPModeID( struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION
	returns the normal display modeID, if one is currently  associated
	with this [ViewPort](autodocs-3.5/include-graphics-view-h.md).

   INPUTS
	vp -- pointer to a [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure.

   RESULT

	modeID -- a 32 bit DisplayInfoRecord identifier associated with
		  this [ViewPort](autodocs-3.5/include-graphics-view-h.md), or INVALID_ID.

   NOTES
	Test the return value of this function against INVALID_ID, not NULL.
	(INVALID_ID is defined in [graphics/displayinfo.h)](autodocs-3.5/include-graphics-displayinfo-h.md).

   BUGS

   SEE ALSO
	[graphics/displayinfo.h](autodocs-3.5/include-graphics-displayinfo-h.md), [ModeNotAvailable()](autodocs-3.5/graphics-library-modenotavailable-2.md)

---

## See Also

- [ModeNotAvailable — graphics.library](../autodocs/graphics.library.md#modenotavailable)

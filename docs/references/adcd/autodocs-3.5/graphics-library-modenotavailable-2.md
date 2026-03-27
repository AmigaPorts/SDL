---
title: graphics.library/ModeNotAvailable
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-modenotavailable-2
functions: [GetVPModeID, ModeNotAvailable]
libraries: [graphics.library]
---

# graphics.library/ModeNotAvailable

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ModeNotAvailable -- check to see if a DisplayID isn't available. (V36)

   SYNOPSIS
	error =  ModeNotAvailable( modeID )
	d0		           d0

	ULONG	ModeNotAvailable( ULONG);

   FUNCTION
	returns an error code, indicating why this modeID is not available,
	or NULL if there is no reason known why this mode should not be there.

   INPUTS
	modeID -- a 32 bit DisplayInfoRecord identifier.

   RESULT
	error -- a general indication of why this modeID is not available,
		 or NULL if there is no reason why it shouldn't be available.

   NOTE
	ULONG return values from this function are a proper superset of the
	DisplayInfo.NotAvailable field (defined in [graphics/displayinfo.h)](autodocs-3.5/include-graphics-displayinfo-h.md).

	ModeNotAvailable() will return INVALID_ID when given a non-existant
	moe ID.

   BUGS

   SEE ALSO
	[graphics/displayinfo.h](autodocs-3.5/include-graphics-displayinfo-h.md), [GetVPModeID()](autodocs-3.5/graphics-library-getvpmodeid-2.md)

---

## See Also

- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [ModeNotAvailable — graphics.library](../autodocs/graphics.library.md#modenotavailable)

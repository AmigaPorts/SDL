---
title: graphics.library/CoerceMode
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-coercemode
functions: []
libraries: []
---

# graphics.library/CoerceMode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CoerceMode -- calculate [ViewPort](autodocs-3.5/include-graphics-view-h.md) mode coercion (V39)

   SYNOPSIS
	ID = CoerceMode(RealViewPort, MonitorID, Flags);
	d0              a0            d0         d1

	ULONG CoerceMode(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, ULONG, ULONG);

   FUNCTION
	To determine the best mode in the MonitorID to coerce RealViewPort to,
	given the restrictions set in Flags.

   INPUTS
	RealViewPort - [ViewPort](autodocs-3.5/include-graphics-view-h.md) to coerce
	MonitorID    - Montor number to coerce to (ie a mode masked with
	               MONITOR_ID_MASK).
	Flags        - PRESERVE_COLORS - keep the number of bitplanes
	               in the [ViewPort](autodocs-3.5/include-graphics-view-h.md).
	               AVOID_FLICKER - do not coerce to an interlace mode

   RESULTS
	ID      - ID of the best mode to coerce to, or INVALID_ID if could not
	          coerce (see NOTES).

   NOTES
	This function takes into account the compatibility of the Monitor
	being coerced to, and the [ViewPort](autodocs-3.5/include-graphics-view-h.md) that is being coerced.
	Incompatibilities will cause a result of INVALID_ID.

   EXAMPLE
	newmode = CoerceMode(vp, VGA_MONITOR_ID, PRESERVE_COLORS);

   SEE ALSO
	[<graphics/coerce.h>](autodocs-3.5/include-graphics-coerce-h.md) [<graphics/displayinfo.h>](autodocs-3.5/include-graphics-displayinfo-h.md)


---
title: intuition.library/QueryOverscan
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-queryoverscan-2
functions: [OpenScreen, OpenScreenTagList]
libraries: [intuition.library]
---

# intuition.library/QueryOverscan

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	QueryOverscan -- Inquire about a standard overscan region. (V36)

    SYNOPSIS
	success = QueryOverscan( DisplayID, Rect, OScanType )
	D0                       A0         A1    D0

	[LONG](autodocs-3.5/include-exec-types-h.md) QueryOverscan( ULONG, struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) *, WORD );

    FUNCTION
	This function fills in a rectangle with one of the system
	overscan dimensions, scaled appropriately for the mode of
	the DisplayID it is passed.

	There are three types of system overscan values:
	OSCAN_TEXT: completely visible, by user preference.  Used
	  for Workbench screen and screen dimensions STDSCREENWIDTH
	  and STDSCREENHEIGHT.  Left/Top is always 0,0.
	OSCAN_STANDARD: just beyond visible bounds of monitor, by
	  user preference.  Left/Top may be negative.
	OSCAN_MAX: The largest region we can display, AND display
	  any smaller region (see note below).
	OSCAN_VIDEO: The absolute largest region that the graphics.library
	  can display.  This region must be used as-is.


    INPUTS
	DisplayID -- A 32-bit identifier for a display mode, as defined
	  in the [<graphics/modeid.h>](autodocs-3.5/include-graphics-modeid-h.md) include file (V39 and up) or in
	  [<graphics/displayinfo.h>](autodocs-3.5/include-graphics-displayinfo-h.md) (V37/V38).

	  NOTE: If you only intend to use one of the four standard
	  overscan dimensions as is, and open your screen to exactly
	  the DisplayClip dimensions, you can specify one of
	  the OSCAN_ values using the SA_Overscan tag to the
	  [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md) function and omit all of SA_Left, SA_Top,
	  SA_Width, and SA_Height.  This also requires that you do
	  not supply a [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure, since it always contains
	  left/top/width/height information.

	  If you wish to supply a [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure, then you are
	  supplying left/top/width/height information.  This information
	  can be taken from the rectangle resulting from this function:
		NewScreen.LeftEdge = Rect.MinX;
		NewScreen.TopEdge = Rect.MinY;
		NewScreen.Width = STDSCREENWIDTH;
			/* or ( Rect.MaxX - Rect.MinX + 1 ) */
		NewScreen.Height = STDSCREENHEIGHT;
			/* or ( Rect.MaxY - Rect.Miny + 1 ) */

	Rect -- pointer to a [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) structure which this function
	  will fill out with its return values.  Note that to convert
	  a rectangle to a screen "Height" you do (MaxY - MinY + 1), and
	  similarly for "Width."  The rectangle may be passed directly
	  to [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md) as a DisplayClip region (SA_DClip).

    RESULT
	0 (FALSE) if the [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) your [NewScreen](autodocs-3.5/include-intuition-screens-h.md) requests
	does not exist.  Non-zero (TRUE) if it does.

    BUGS
	Change in parameter V36.A17 might cause problems for some.

    SEE ALSO
	[OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md), Intuition V36 update documentation

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)

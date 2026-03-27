---
title: graphics.library/InitView
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-initview-2
functions: []
libraries: []
---

# graphics.library/InitView

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   
   InitView - Initialize [View](autodocs-3.5/include-graphics-view-h.md) structure.

   SYNOPSIS
	InitView( view )
		   a1

	void InitView( struct [View](autodocs-3.5/include-graphics-view-h.md) * );

   FUNCTION
	Initialize [View](autodocs-3.5/include-graphics-view-h.md) structure to default values.

   INPUTS
	view - pointer to a [View](autodocs-3.5/include-graphics-view-h.md) structure

   RESULT
	[View](autodocs-3.5/include-graphics-view-h.md) structure set to all 0's. (1.0,1.1.1.2)
	Then values are put in DxOffset,DyOffset to properly position
	default display about .5 inches from top and left on monitor.
	InitView pays no attention to previous contents of view.

   BUGS

   SEE ALSO
 	[MakeVPort](autodocs-3.5/graphics-library-makevport-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)


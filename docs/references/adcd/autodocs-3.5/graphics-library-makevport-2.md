---
title: graphics.library/MakeVPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-makevport-2
functions: [InitVPort, MakeScreen, MrgCop, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# graphics.library/MakeVPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MakeVPort -- generate display copper list for a viewport.

   SYNOPSIS
	error =  MakeVPort( view, viewport )
	 d0                   a0     a1

	ULONG MakeVPort( struct [View](autodocs-3.5/include-graphics-view-h.md) *, struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) * );

   FUNCTION
	Uses information in the [View](autodocs-3.5/include-graphics-view-h.md), [ViewPort](autodocs-3.5/include-graphics-view-h.md), ViewPort->RasInfo to
	construct and intermediate copper list for this [ViewPort](autodocs-3.5/include-graphics-view-h.md).

   INPUTS
	view - pointer to a [View](autodocs-3.5/include-graphics-view-h.md) structure
	viewport - pointer to a [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure
		 The viewport must have valid pointer to a RasInfo.

   RESULTS
	constructs intermediate copper list and puts pointers in
	viewport.DspIns
	If the [ColorMap](autodocs-3.5/include-graphics-view-h.md) ptr in [ViewPort](autodocs-3.5/include-graphics-view-h.md) is NULL then it uses colors
	from the default color table.
	If DUALPF in Modes then there must be a second RasInfo pointed
	to by the first RasInfo

	From V39, MakeVPort can return a ULONG error value (previous versions
	returned void), to indicate that either not enough memory could be
	allocated for MakeVPort's use, or that the [ViewPort](autodocs-3.5/include-graphics-view-h.md) mode
	and bitplane alignments are incorrect for the bitplane's depth.

	You should check for these error values - they are defined in
	[<graphics/view.h>](autodocs-3.5/include-graphics-view-h.md).


   BUGS
	In V37 and earlier, narrow Viewports (whose righthand edge is
	less than 3/4 of the way across the display) do not work properly.

   SEE ALSO
	[InitVPort()](autodocs-3.5/graphics-library-initvport-2.md) [MrgCop()](autodocs-3.5/graphics-library-mrgcop-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md) [intuition.library/MakeScreen()](autodocs-3.5/intuition-library-makescreen-2.md)
	[intuition.library/RemakeDisplay()](autodocs-3.5/intuition-library-remakedisplay-2.md) [intuition.library/RethinkDisplay()](autodocs-3.5/intuition-library-rethinkdisplay-2.md)

---

## See Also

- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)

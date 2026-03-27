---
title: graphics.library/CalcIVG
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-calcivg
functions: [CalcIVG, GfxNew, VideoControl]
libraries: [graphics.library]
---

# graphics.library/CalcIVG

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CalcIVG -- Calculate the number of blank lines above a [ViewPort](autodocs-3.5/include-graphics-view-h.md) (V39)

   SYNOPSIS
	count = CalcIVG(View, ViewPort)
	 d0.w           a0    a1

	[UWORD](autodocs-3.5/include-exec-types-h.md) CalcIVG(struct [View](autodocs-3.5/include-graphics-view-h.md) *, struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION
	To calculate the maximum number of blank lines above a viewport needed to
	load all the copper instructions, after accounting for the viewport
	bandwidth and size.

   INPUTS
	[View](autodocs-3.5/include-graphics-view-h.md)       - pointer to the [View](autodocs-3.5/include-graphics-view-h.md)
	[ViewPort](autodocs-3.5/include-graphics-view-h.md)   - pointer to the [ViewPort](autodocs-3.5/include-graphics-view-h.md) you are interested in.

   RESULT
	count      - the number of [ViewPort](autodocs-3.5/include-graphics-view-h.md) resolution scan lines needed to
	             execute all the copper instructions for [ViewPort](autodocs-3.5/include-graphics-view-h.md),
	             or 0 if any error.

   NOTES
	The number of copper instructions comes from the vp->vp_DspIns list.
	Although there may be other copper instructions in the final list (from
	UCopIns, SprIns and ClrIns) they are currently ignored for this
	function. This also means that if the [ViewPort](autodocs-3.5/include-graphics-view-h.md) has never been made
	(for example, the [ViewPort](autodocs-3.5/include-graphics-view-h.md) of an intuition screen was opened behind)
	then vp->vp_DspIns is NULL.

	Although CalcIVG() returns the true number of lines needed by the
	copper, intuition still maintains an inter-screen gap of 3 non-laced
	lines (6 interlaced). Therefore, for intuition screens use:
	MAX(CalcIVG(v, vp), (islaced ? 6 : 3))


   SEE ALSO
	[GfxNew()](autodocs-3.5/graphics-library-gfxnew-2.md)  [VideoControl()](autodocs-3.5/graphics-library-videocontrol-2.md)  [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [CalcIVG — graphics.library](../autodocs/graphics.library.md#calcivg)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)

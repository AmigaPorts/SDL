---
title: graphics.library/DrawGList
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-drawglist-2
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/DrawGList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DrawGList -- [Process](autodocs-3.5/include-dos-dosextens-h.md) the gel list, queueing VSprites, drawing Bobs.

   SYNOPSIS
	DrawGList(rp, vp)
	          A1  A0

	void DrawGList(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION
	Performs one pass of the current gel list.
	   - If nextLine and lastColor are defined, these are
	     initialized for each gel.
```c
          - If it's a [VSprite](autodocs-3.5/include-graphics-gels-h.md), build it into the copper list.
          - If it's a [Bob](autodocs-3.5/include-graphics-gels-h.md), draw it into the current raster.
          - Copy the save values into the "old" variables,
```
	     double-buffering if required.

   INPUTS
	rp = pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) where Bobs will be drawn
	vp = pointer to the [ViewPort](autodocs-3.5/include-graphics-view-h.md) for which VSprites will be created

   RESULT

   BUGS
	MUSTDRAW isn't implemented yet.

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)  [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)

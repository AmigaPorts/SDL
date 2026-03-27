---
title: layers.library/BeginUpdate
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-beginupdate-2
functions: [EndUpdate]
libraries: [layers.library]
---

# layers.library/BeginUpdate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	BeginUpdate -- Prepare to repair damaged layer.

    SYNOPSIS
	result = BeginUpdate( l )
	d0                    a0

	[LONG](autodocs-3.5/include-exec-types-h.md) BeginUpdate( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

    FUNCTION
	Convert damage list to [ClipRect](autodocs-3.5/include-graphics-clip-h.md) list and swap in for
	programmer to redraw through. This routine simulates
	the ROM library environment. The idea is to only render in the
	"damaged" areas, saving time over redrawing all of the layer.
	The layer is locked against changes made by the layer library.

    INPUTS
	l - pointer to a layer

    RESULTS
	result - TRUE if damage list converted to [ClipRect](autodocs-3.5/include-graphics-clip-h.md) list successfully.
	         FALSE if list conversion aborted. (probably out of memory)

    BUGS
	If BeginUpdate returns FALSE, programmer must abort the attempt to
	refresh this layer and instead call EndUpdate( l, FALSE ) to restore
	original [ClipRect](autodocs-3.5/include-graphics-clip-h.md) and damage list.

    SEE ALSO
	[EndUpdate()](autodocs-3.5/layers-library-endupdate-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

---

## See Also

- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)

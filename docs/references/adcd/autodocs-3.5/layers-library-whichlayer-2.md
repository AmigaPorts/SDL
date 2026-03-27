---
title: layers.library/WhichLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-whichlayer-2
functions: []
libraries: []
---

# layers.library/WhichLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	WhichLayer -- Which [Layer](autodocs-3.5/include-graphics-clip-h.md) is this point in?

    SYNOPSIS
	layer = WhichLayer( li, x, y )
	d0                  a0  d0 d1

	struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *WhichLayer(struct Layer_Info*, WORD, WORD);

    FUNCTION
	Starting at the topmost layer check to see if this point (x,y)
	    occurs in this layer.  If it does return the pointer to this
	    layer. Return NULL if there is no layer at this point.

    INPUTS
	li  = pointer to LayerInfo structure
	(x,y) = coordinate in the [BitMap](autodocs-3.5/include-graphics-gfx-h.md)

    RESULTS
	layer - pointer to the topmost layer that this point is in
	        NULL if this point is not in a layer

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)


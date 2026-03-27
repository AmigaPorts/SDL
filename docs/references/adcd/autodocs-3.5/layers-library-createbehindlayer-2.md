---
title: layers.library/CreateBehindLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-createbehindlayer-2
functions: [DeleteLayer]
libraries: [layers.library]
---

# layers.library/CreateBehindLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CreateBehindLayer -- Create a new layer behind all existing layers.

    SYNOPSIS
	result = CreateBehindLayer(li,bm,x0,y0,x1,y1,flags [,bm2])
	d0                         a0 a1 d0 d1 d2 d3   d4  [ a2 ]

	struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *CreateBehindLayer(struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *, struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *,
	    [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), ... );

    FUNCTION
	Create a new [Layer](autodocs-3.5/include-graphics-clip-h.md) of position and size (x0,y0)->(x1,y1)
	Make this layer of type found in flags.
	If SuperBitMap, use bm2 as pointer to real SuperBitMap,
	and copy contents of Superbitmap into display layer.
	If this layer is a backdrop layer then place it behind all
	other layers including other backdrop layers. If this is
	not a backdrop layer then place it behind all nonbackdrop
	layers.

	Note: when using SUPERBITMAP, you should also set LAYERSMART flag.

    INPUTS
	li - pointer to LayerInfo structure
	bm - pointer to common [BitMap](autodocs-3.5/include-graphics-gfx-h.md) used by all Layers
	x0,y0 - upper left hand corner of layer
	x1,y1 - lower right hand corner of layer
	flags - various types of layers supported as bit sets.
	        (for bit definitions, see [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md) )
	bm2 - pointer to optional Super [BitMap](autodocs-3.5/include-graphics-gfx-h.md)

    RESULTS
	result - pointer to [Layer](autodocs-3.5/include-graphics-clip-h.md) structure if successful
	         NULL if not successful

    BUGS

    SEE ALSO
	[DeleteLayer()](autodocs-3.5/layers-library-deletelayer-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md), [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

---

## See Also

- [DeleteLayer — layers.library](../autodocs/layers.library.md#deletelayer)

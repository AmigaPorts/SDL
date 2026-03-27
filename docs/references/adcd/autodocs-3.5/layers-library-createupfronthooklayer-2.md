---
title: layers.library/CreateUpfrontHookLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-createupfronthooklayer-2
functions: [DeleteLayer, InstallLayerHook]
libraries: [layers.library]
---

# layers.library/CreateUpfrontHookLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME                                                              (V36)
```
	CreateUpfrontHookLayer -- Create a new layer on top of existing layers,
	                          using supplied callback BackFill hook.

    SYNOPSIS
	result = CreateUpfrontHookLayer(li,bm,x0,y0,x1,y1,flags,hook,[,bm2])
	d0                              a0 a1 d0 d1 d2 d3   d4  a3   [ a2 ]

	struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *CreateUpfrontHookLayer(struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *, struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *,
	    [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *, ... );

    FUNCTION
	Create a new [Layer](autodocs-3.5/include-graphics-clip-h.md) of position and size (x0,y0)->(x1,y1)
	and place it on top of all other layers.
	Make this layer of type found in flags
	Install Layer->BackFill callback hook.
	if SuperBitMap, use bm2 as pointer to real SuperBitMap.
	and copy contents of Superbitmap into display layer.

	Note: when using SUPERBITMAP, you should also set LAYERSMART flag.

    INPUTS
	li - pointer to LayerInfo structure
	bm - pointer to common [BitMap](autodocs-3.5/include-graphics-gfx-h.md) used by all Layers
	x0,y0 - upper left hand corner of layer
	x1,y1 - lower right hand corner of layer
	flags - various types of layers supported as bit sets.
	hook -  Layer->BackFill callback [Hook](autodocs-3.5/include-utility-hooks-h.md) (see [InstallLayerHook()](autodocs-3.5/layers-library-installlayerhook-2.md))

	        If hook is LAYERS_BACKFILL, the default backfill is
	        used for the layer.  (Same as pre-2.0)

	        As of V39:
		If hook is LAYERS_NOBACKFILL, the layer will not be
	        backfilled (NO-OP).

	bm2 - pointer to optional Super [BitMap](autodocs-3.5/include-graphics-gfx-h.md)

    RESULTS
	result - pointer to [Layer](autodocs-3.5/include-graphics-clip-h.md) structure if successful
	         NULL if not successful

    BUGS

    SEE ALSO
	[InstallLayerHook()](autodocs-3.5/layers-library-installlayerhook-2.md), [DeleteLayer()](autodocs-3.5/layers-library-deletelayer-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md),
	[graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md), [utility/hooks.h](autodocs-3.5/include-utility-hooks-h.md)

---

## See Also

- [DeleteLayer — layers.library](../autodocs/layers.library.md#deletelayer)
- [InstallLayerHook — layers.library](../autodocs/layers.library.md#installlayerhook)

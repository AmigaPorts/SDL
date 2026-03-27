---
title: layers.library/LockLayers
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-locklayers-2
functions: [LockLayer, LockLayerInfo]
libraries: [layers.library]
---

# layers.library/LockLayers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LockLayers -- lock all layers from graphics output.

    SYNOPSIS
	LockLayers( li )
	            a0

	void LockLayers( struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *);

    FUNCTION
	First calls [LockLayerInfo()](autodocs-3.5/layers-library-locklayerinfo-2.md)
	Make all layers in this layer list locked.

    INPUTS
	li - pointer to [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure

    BUGS

    SEE ALSO
	[LockLayer()](autodocs-3.5/layers-library-locklayer-2.md), [LockLayerInfo()](autodocs-3.5/layers-library-locklayerinfo-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [LockLayer — layers.library](../autodocs/layers.library.md#locklayer)
- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)

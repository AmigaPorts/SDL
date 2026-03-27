---
title: layers.library/InitLayers
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-initlayers-2
functions: [DisposeLayerInfo, NewLayerInfo]
libraries: [layers.library]
---

# layers.library/InitLayers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	InitLayers -- Initialize [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    SYNOPSIS
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
	InitLayers( li )
	            a0

	void InitLayers( struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *);
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    FUNCTION
	Initialize [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure in preparation to use
	other layer operations on this list of layers.
	Make the Layers unlocked (open), available to layer operations.

    INPUTS
	li - pointer to LayerInfo structure

    BUGS

    SEE ALSO
	[NewLayerInfo()](autodocs-3.5/layers-library-newlayerinfo-2.md), [DisposeLayerInfo()](autodocs-3.5/layers-library-disposelayerinfo-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [DisposeLayerInfo — layers.library](../autodocs/layers.library.md#disposelayerinfo)
- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)

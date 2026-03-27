---
title: layers.library/UnlockLayers
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-unlocklayers-2
functions: [LockLayers, UnlockLayer]
libraries: [layers.library]
---

# layers.library/UnlockLayers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnlockLayers -- Unlock all layers from graphics output.
	                Restart graphics output to layers that have been waiting

    SYNOPSIS
	UnlockLayers( li )
	              a0

	void UnlockLayers( struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *);

    FUNCTION
	Make all layers in this layer list unlocked.
	Then call [UnlockLayerInfo](autodocs-3.5/layers-library-unlocklayerinfo-2.md)

    INPUTS
	li - pointer to the [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure

    BUGS

    SEE ALSO
	[LockLayers()](autodocs-3.5/layers-library-locklayers-2.md), [UnlockLayer()](autodocs-3.5/layers-library-unlocklayer-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [LockLayers — layers.library](../autodocs/layers.library.md#locklayers)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)

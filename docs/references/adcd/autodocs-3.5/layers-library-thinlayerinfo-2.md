---
title: layers.library/ThinLayerInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-thinlayerinfo-2
functions: [DisposeLayerInfo]
libraries: [layers.library]
---

# layers.library/ThinLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ThinLayerInfo -- convert 1.1 LayerInfo to 1.0 LayerInfo.
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    SYNOPSIS
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
	ThinLayerInfo( li )
	               a0

	void ThinLayerInfo( struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *);
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    FUNCTION
	return the extra memory needed that was allocated with
	[FattenLayerInfo](autodocs-3.5/layers-library-fattenlayerinfo-2.md). This is must be done prior to freeing
	the [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure itself. V1.1 software should be
	using [DisposeLayerInfo](autodocs-3.5/layers-library-disposelayerinfo-2.md).

    INPUTS
	li - pointer to LayerInfo structure

    BUGS

    SEE ALSO
	[DisposeLayerInfo()](autodocs-3.5/layers-library-disposelayerinfo-2.md), [FattenLayerInfo()](autodocs-3.5/layers-library-fattenlayerinfo-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [DisposeLayerInfo — layers.library](../autodocs/layers.library.md#disposelayerinfo)

---
title: layers.library/FattenLayerInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-fattenlayerinfo-2
functions: [DisposeLayerInfo, NewLayerInfo]
libraries: [layers.library]
---

# layers.library/FattenLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	FattenLayerInfo -- convert 1.0 LayerInfo to 1.1 LayerInfo
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    SYNOPSIS
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
	FattenLayerInfo( li )
	                 a0

	[LONG](autodocs-3.5/include-exec-types-h.md) FattenLayerInfo( struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *);
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    FUNCTION
	V1.1 software and any later releases need to have more info in the
	[Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure. To do this in a 1.0 supportable manner requires
	allocation and deallocation of the memory whenever most
	layer library functions are called.  To prevent unnecessary
	allocation/deallocation FattenLayerInfo will preallocate the
	necessary data structures and fake out the layer library into
	thinking it has a LayerInfo gotten from [NewLayerInfo](autodocs-3.5/layers-library-newlayerinfo-2.md).
	[NewLayerInfo](autodocs-3.5/layers-library-newlayerinfo-2.md) is the approved method for getting this structure.
	When a program needs to give up the LayerInfo structure it
	must call [ThinLayerInfo](autodocs-3.5/layers-library-thinlayerinfo-2.md) before freeing the memory. [ThinLayerInfo](autodocs-3.5/layers-library-thinlayerinfo-2.md)
	is not necessary if [New/DisposeLayerInfo](autodocs-3.5/layers-library-disposelayerinfo-2.md) are used however.

    INPUTS
	li - pointer to LayerInfo structure


    BUGS

    SEE ALSO
	[NewLayerInfo()](autodocs-3.5/layers-library-newlayerinfo-2.md), [ThinLayerInfo()](autodocs-3.5/layers-library-thinlayerinfo-2.md), [DisposeLayerInfo()](autodocs-3.5/layers-library-disposelayerinfo-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [DisposeLayerInfo — layers.library](../autodocs/layers.library.md#disposelayerinfo)
- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)

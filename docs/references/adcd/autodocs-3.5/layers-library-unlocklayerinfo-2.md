---
title: layers.library/UnlockLayerInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-unlocklayerinfo-2
functions: [LockLayerInfo]
libraries: [layers.library]
---

# layers.library/UnlockLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnlockLayerInfo -- Unlock the LayerInfo structure.

    SYNOPSIS
	UnlockLayerInfo( li )
	                 a0

	void UnlockLayerInfo( struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *);

    FUNCTION
	After the operation is complete that required a [LockLayerInfo](autodocs-3.5/layers-library-locklayerinfo-2.md),
	unlock the LayerInfo structure so that  other tasks may
	affect the layers.

    INPUTS
	li - pointer to the [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure

     BUGS

     SEE ALSO
	[LockLayerInfo()](autodocs-3.5/layers-library-locklayerinfo-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)

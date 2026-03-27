---
title: graphics.library/LockLayerRom
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-locklayerrom-2
functions: [LockLayer, UnlockLayerRom]
libraries: [graphics.library, layers.library]
---

# graphics.library/LockLayerRom

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LockLayerRom -- [Lock](autodocs-3.5/dos-library-lock-2.md) [Layer](autodocs-3.5/include-graphics-clip-h.md) structure by ROM(gfx lib) code.

   SYNOPSIS
	LockLayerRom( layer )
		       a5

	void LockLayerRom( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) * );

   FUNCTION
	Return when the layer is locked and no other task may
	alter the [ClipRect](autodocs-3.5/include-graphics-clip-h.md) structure in the [Layer](autodocs-3.5/include-graphics-clip-h.md) structure.
	This call does not destroy any registers.
	This call nests so that callers in this chain will not lock
	themselves out.
	Do not have the [Layer](autodocs-3.5/include-graphics-clip-h.md) locked during a call to intuition.
	There is a potential deadlock problem here, if intuition
	needs to get other locks as well.
	Having the layer locked prevents other tasks from using the
	layer library functions, most notably intuition itself. So
	be brief.
	layers.library's [LockLayer](autodocs-3.5/layers-library-locklayer-2.md) is identical to LockLayerRom.

   INPUTS
	layer - pointer to [Layer](autodocs-3.5/include-graphics-clip-h.md) structure

   RESULTS
	The layer is locked and the task can render assuming the
	ClipRects will not change out from underneath it until
	an [UnlockLayerRom](autodocs-3.5/graphics-library-unlocklayerrom-2.md) is called.

   SEE ALSO
	[UnlockLayerRom()](autodocs-3.5/graphics-library-unlocklayerrom-2.md) [layers.library/LockLayer()](autodocs-3.5/layers-library-locklayer-2.md) [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

---

## See Also

- [LockLayer — layers.library](../autodocs/layers.library.md#locklayer)
- [UnlockLayerRom — graphics.library](../autodocs/graphics.library.md#unlocklayerrom)

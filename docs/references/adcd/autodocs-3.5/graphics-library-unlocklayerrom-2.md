---
title: graphics.library/UnlockLayerRom
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-unlocklayerrom-2
functions: [LockLayerRom, UnlockLayer]
libraries: [graphics.library, layers.library]
---

# graphics.library/UnlockLayerRom

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UnlockLayerRom -- Unlock [Layer](autodocs-3.5/include-graphics-clip-h.md) structure by ROM(gfx lib) code.

   SYNOPSIS
	UnlockLayerRom( layer )
			 a5

	void UnlockLayerRom( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) * );

   FUNCTION
	Release the lock on this layer. If the same task has called
	[LockLayerRom](autodocs-3.5/graphics-library-locklayerrom-2.md) more than once than the same number of calls to
	UnlockLayerRom must happen before the layer is actually freed
	so that other tasks may use it.
	This call does destroy scratch registers.
	This call is identical to [UnlockLayer](autodocs-3.5/layers-library-unlocklayer-2.md) (layers.library).

   INPUTS
	layer - pointer to [Layer](autodocs-3.5/include-graphics-clip-h.md) structure

   BUGS

   SEE ALSO
	[LockLayerRom()](autodocs-3.5/graphics-library-locklayerrom-2.md) [layers.library/UnlockLayer()](autodocs-3.5/layers-library-unlocklayer-2.md) [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

---

## See Also

- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)

---
title: layers.library/LockLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-locklayer-2
functions: [LockLayerInfo, LockLayerRom, UnlockLayer, UnlockLayerInfo]
libraries: [graphics.library, layers.library]
---

# layers.library/LockLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LockLayer -- [Lock](autodocs-3.5/dos-library-lock-2.md) layer to make changes to ClipRects.

    SYNOPSIS
	LockLayer( dummy, l )
	           a0     a1

	void LockLayer( [LONG](autodocs-3.5/include-exec-types-h.md), struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

    FUNCTION
	Make this layer unavailable for other tasks to use.
	If another task is already using this layer then wait for
	it to complete and then reserve the layer for your own use.
	(this function does the same thing as graphics.library/LockLayerRom)

	Note: if you wish to lock MORE THAN ONE layer at a time, you
	    must call [LockLayerInfo()](autodocs-3.5/layers-library-locklayerinfo-2.md) before locking those layers and
	    then call [UnlockLayerInfo()](autodocs-3.5/layers-library-unlocklayerinfo-2.md) when you have finished. This
	    is to prevent system "deadlocks".

	Further Note: while you hold the lock on a layer, Intuition will block
	    on operations such as windowsizing, dragging, menus, and depth
	    arranging windows in this layer's screen.  It is recommended that
	    YOU do not make Intuition function calls while the layer is locked.

    INPUTS
	dummy - unused
	l - pointer to a layer

    BUGS

    SEE ALSO
	[UnlockLayer()](autodocs-3.5/layers-library-unlocklayer-2.md), [LockLayerInfo()](autodocs-3.5/layers-library-locklayerinfo-2.md), [UnlockLayerInfo()](autodocs-3.5/layers-library-unlocklayerinfo-2.md),
	[graphics.library/LockLayerRom()](autodocs-3.5/graphics-library-locklayerrom-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)

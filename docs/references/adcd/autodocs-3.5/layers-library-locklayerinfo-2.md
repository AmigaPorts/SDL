---
title: layers.library/LockLayerInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-locklayerinfo-2
functions: [LockLayerInfo, UnlockLayerInfo]
libraries: [layers.library]
---

# layers.library/LockLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LockLayerInfo -- [Lock](autodocs-3.5/dos-library-lock-2.md) the LayerInfo structure.

    SYNOPSIS
	LockLayerInfo( li )
	               a0

	void LockLayerInfo( struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *);

    FUNCTION
	Before doing an operation that requires the LayerInfo
	structure, make sure that no other task is also using the
	LayerInfo structure.  LockLayerInfo() returns when the
	LayerInfo belongs to this task.  There should be
	an [UnlockLayerInfo](autodocs-3.5/layers-library-unlocklayerinfo-2.md) for every LockLayerInfo.

	Note: All layer routines presently LockLayerInfo() when they
	start up and [UnlockLayerInfo()](autodocs-3.5/layers-library-unlocklayerinfo-2.md) as they exit.  Programmers
	will need to use these Lock/Unlock routines if they wish
	to do something with the LayerStructure that is not
	supported by the layer library.

    INPUTS
	li - pointer to [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure

    BUGS

    SEE ALSO
	[UnlockLayerInfo()](autodocs-3.5/layers-library-unlocklayerinfo-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)

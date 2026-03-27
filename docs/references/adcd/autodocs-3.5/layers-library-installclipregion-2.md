---
title: layers.library/InstallClipRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-installclipregion-2
functions: [BeginUpdate, CloseWindow, EndUpdate]
libraries: [intuition.library, layers.library]
---

# layers.library/InstallClipRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	InstallClipRegion -- Install clip region in layer

    SYNOPSIS
	oldclipregion = InstallClipRegion( l,  region )
	d0                                 a0  a1

	struct [Region](autodocs-3.5/include-graphics-regions-h.md) *InstallClipRegion( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *, struct [Region](autodocs-3.5/include-graphics-regions-h.md) *);

    FUNCTION
	Installs a transparent Clip region in the layer. All
	subsequent graphics calls will be clipped to this region.
	You MUST remember to call InstallClipRegion(l,NULL) before
	calling DeleteLayer(l) or the Intuition function [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)
 	if you have installed a non-NULL ClipRegion in l.

    INPUTS
	l - pointer to a layer
	region - pointer to a region

    RESULTS
	oldclipregion - The pointer to the previous ClipRegion that
	    was installed. Returns NULL if no previous ClipRegion installed.

	    Note: If the system runs out of memory while computing the
	        resulting ClipRects the LAYERS_CLIPRECTS_LOST bit will
	        be set in l->Flags.

    BUGS
	If the system runs out of memory during normal layer operations,
	the [ClipRect](autodocs-3.5/include-graphics-clip-h.md) list may get swept away and not restored.
	As soon as there is enough memory and the layer library
	gets called again the [ClipRect](autodocs-3.5/include-graphics-clip-h.md) list will be rebuilt.

    SEE ALSO
	[BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md) [EndUpdate()](autodocs-3.5/layers-library-endupdate-2.md),
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md), [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)

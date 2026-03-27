---
title: layers.library/NewLayerInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-newlayerinfo-2
functions: [NewLayerInfo]
libraries: [layers.library]
---

# layers.library/NewLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	NewLayerInfo -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) and Initialize full [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure.

    SYNOPSIS
	result = NewLayerInfo()
	d0

	struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *NewLayerInfo( void );

    FUNCTION
	[Allocate](autodocs-3.5/exec-library-allocate-2.md) memory required for full [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure.
	Initialize [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure in preparation to use
	other layer operations on this list of layers.
	Make the [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) unlocked (open).

    INPUTS
	None

    RESULT
	result- pointer to [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure if successful
	        NULL if not enough memory

    BUGS

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)

---

## See Also

- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)

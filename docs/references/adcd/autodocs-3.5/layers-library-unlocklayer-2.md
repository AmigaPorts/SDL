---
title: layers.library/UnlockLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-unlocklayer-2
functions: [UnlockLayer]
libraries: [layers.library]
---

# layers.library/UnlockLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UnlockLayer -- Unlock layer and allow graphics routines to use it.

    SYNOPSIS
	UnlockLayer( l )
	             a0

	void UnlockLayer( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

    FUNCTION
	When finished changing the ClipRects or whatever you were
	doing with this layer you must call UnlockLayer() to allow
	other tasks to proceed with graphic output to the layer.

    INPUTS
	l - pointer to a layer

    BUGS

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

---

## See Also

- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)

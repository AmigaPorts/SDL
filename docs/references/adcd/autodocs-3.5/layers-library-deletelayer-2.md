---
title: layers.library/DeleteLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-deletelayer-2
functions: []
libraries: []
---

# layers.library/DeleteLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DeleteLayer -- delete layer from layer list.

    SYNOPSIS
	result = DeleteLayer( dummy, l )
	d0                    a0,    a1

	[LONG](autodocs-3.5/include-exec-types-h.md) DeleteLayer( [LONG](autodocs-3.5/include-exec-types-h.md), struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

    FUNCTION
	[Remove](autodocs-3.5/exec-library-remove-2.md) this layer from the list of layers.  Release memory
	associated with it.  Restore other layers that may have been
	obscured by it.  Trigger refresh in those that may need it.
	If this is a superbitmap layer make sure SuperBitMap is current.
	The SuperBitMap is not removed from the system but is available
	for program use even though the rest of the layer information has
	been deallocated.

    INPUTS
	dummy - unused
	l - pointer to a layer

    RESULTS
	result - TRUE if this layer successfully deleted from the system
	         FALSE if layer not deleted. (probably out of memory )

    BUGS

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)


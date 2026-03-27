---
title: layers.library/MoveLayerInFrontOf
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-movelayerinfrontof-2
functions: []
libraries: []
---

# layers.library/MoveLayerInFrontOf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	MoveLayerInFrontOf -- Put layer in front of another layer.

    SYNOPSIS
	result = MoveLayerInFrontOf( layertomove, targetlayer )

                                    a0           a1
	[LONG](autodocs-3.5/include-exec-types-h.md) MoveLayerInFrontOf( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *, struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

    FUNCTION
	[Move](autodocs-3.5/graphics-library-move-2.md) this layer in front of target layer, swapping bits
	in and out of the display with other layers.
	If this is a refresh layer then collect damage list and
	set the LAYERREFRESH bit in layer->Flags if redraw required.

	Note: this operation may generate refresh events in other layers
	    associated with this layer's [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure.

    INPUTS
	layertomove - pointer to layer which should be moved
	targetlayer - pointer to target layer in front of which to move layer

    RESULTS
	result = TRUE    if operation successful
	         FALSE   if operation unsuccessful (probably out of memory)

    BUGS

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)


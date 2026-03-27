---
title: layers.library/UpfrontLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-upfrontlayer-2
functions: []
libraries: []
---

# layers.library/UpfrontLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	UpfrontLayer -- Put layer in front of all other layers.

    SYNOPSIS
	result = UpfrontLayer( dummy, l )
	d0                     a0     a1

	[LONG](autodocs-3.5/include-exec-types-h.md) UpfrontLayer( [LONG](autodocs-3.5/include-exec-types-h.md), struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

    FUNCTION
	[Move](autodocs-3.5/graphics-library-move-2.md) this layer to the most upfront position swapping bits
	in and out of the display with other layers.
	If this is a refresh layer then collect damage list and
	set the LAYERREFRESH bit in layer->Flags if redraw required.
	By clearing the BACKDROP bit in the layers Flags you may
	bring a Backdrop layer up to the front of all other layers.

	Note: this operation may generate refresh events in other layers
	   associated with this layer's [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure.

    INPUTS
	dummy - unused
	l - pointer to a nonbackdrop layer

    RESULTS
	result - TRUE   if operation successful
	         FALSE  if operation unsuccessful (probably out of memory)

    BUGS

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md)


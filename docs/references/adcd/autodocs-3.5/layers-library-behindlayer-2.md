---
title: layers.library/BehindLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-behindlayer-2
functions: []
libraries: []
---

# layers.library/BehindLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	BehindLayer -- Put layer behind other layers.

    SYNOPSIS
	result = BehindLayer( dummy, l )
	d0                    a0     a1

	[LONG](autodocs-3.5/include-exec-types-h.md) BehindLayer( [LONG](autodocs-3.5/include-exec-types-h.md), struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *);

    FUNCTION
	[Move](autodocs-3.5/graphics-library-move-2.md) this layer to the most behind position swapping bits
	in and out of the display with other layers.
	If other layers are REFRESH then collect their damage lists and
	set the LAYERREFRESH bit in the Flags fields of those layers that
	may be revealed.  If this layer is a backdrop layer then
	put this layer behind all other backdrop layers.
	If this layer is NOT a backdrop layer then put in front of the
	top backdrop layer and behind all other layers.

	Note: this operation may generate refresh events in other layers
	   associated with this layer's [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) structure.

    INPUTS
	dummy - unused
	l - pointer to a layer

    RESULTS
	result - TRUE    if operation successful
	         FALSE   if operation unsuccessful (probably out of memory)


```c
    BUGS

    SEE ALSO
       [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)
```

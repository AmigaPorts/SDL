---
title: layers.library/MoveLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-movelayer-2
functions: []
libraries: []
---

# layers.library/MoveLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	MoveLayer -- [Move](autodocs-3.5/graphics-library-move-2.md) layer to new position in [BitMap](autodocs-3.5/include-graphics-gfx-h.md).

    SYNOPSIS
	result = MoveLayer( dummy, l, dx, dy )
	d0                  a0     a1 d0  d1

	[LONG](autodocs-3.5/include-exec-types-h.md) MoveLayer( [LONG](autodocs-3.5/include-exec-types-h.md), struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

    FUNCTION
	[Move](autodocs-3.5/graphics-library-move-2.md) this layer to new position in shared [BitMap](autodocs-3.5/include-graphics-gfx-h.md).
	If any refresh layers become revealed, collect damage and
	set REFRESH bit in layer Flags.

    INPUTS
	dummy - unused
	l - pointer to a nonbackdrop layer
	dx - delta to add to current x position
	dy - delta to add to current y position

    RETURNS
	result - TRUE if operation successful
	         FALSE if failed (out of memory)

    BUGS
	May not handle (dx,dy) which attempts to move the layer outside the
	layer's RastPort->BitMap bounds .

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)


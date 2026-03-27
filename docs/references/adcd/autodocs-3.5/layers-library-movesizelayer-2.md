---
title: layers.library/MoveSizeLayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-movesizelayer-2
functions: []
libraries: []
---

# layers.library/MoveSizeLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME                                                              (V36)
```
	MoveSizeLayer -- Position/Size layer

    SYNOPSIS
	result = MoveSizeLayer( layer, dx, dy, dw, dh )
	d0                      a0     d0  d1  d2  d3

	[LONG](autodocs-3.5/include-exec-types-h.md) MoveSizeLayer( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

    FUNCTION
	Change upperleft and lower right position of [Layer](autodocs-3.5/include-graphics-clip-h.md).

    INPUTS
	dummy - unused
	l - pointer to a nonbackdrop layer
	dx,dy - change upper left corner by (dx,dy)
	dw,dy - change size by (dw,dh)

    RETURNS
	result - TRUE if operation successful
	         FALSE if failed (due to out of memory)
	         FALSE if failed (due to illegal layer->bounds)

    BUGS

    SEE ALSO
	[graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)


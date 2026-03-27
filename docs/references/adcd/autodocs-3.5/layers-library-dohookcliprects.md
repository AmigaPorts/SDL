---
title: layers.library/DoHookClipRects
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-dohookcliprects
functions: [BltBitMap]
libraries: [graphics.library]
---

# layers.library/DoHookClipRects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DoHookClipRects - Do the given hook for each of the ClipRects    (V39)

    SYNOPSIS
	DoHookClipRects(hook,rport,rect)
	                a0   a1    a2

	void DoHookClipRects(struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *,struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *,struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) *);

    FUNCTION
	This function will call the given hook for each cliprect in the
	layer that can be rendered into.  This is how the backfill hook
	in Layers is implemented.  This means that hidden simple-refresh
	cliprects will be ignored.  It will call the SuperBitMap cliprects,
	smart refresh off-screen cliprects, and all on screen cliprects.
	If the rect parameter is not NULL, the cliprects are bounded to
	the rectangle given.

    INPUTS
	hook - pointer to layer callback [Hook](autodocs-3.5/include-utility-hooks-h.md) which will be called
	       with object == (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *) result->RastPort
	       and message == [ (Layer *) layer, (struct Rectangle) bounds,
	                        (LONG) offsetx, (LONG) offsety ]

	       This hook should fill the [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	       with the BackFill pattern appropriate for offset x/y.

	       If hook is LAYERS_BACKFILL, the default backfill is
	       used for the layer.

	       If hook is LAYERS_NOBACKFILL, the layer will not be
	       backfilled (NO-OP).

	rport- A pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) that is to be operated on.
	       This function will lock the layer if the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) is
	       layered...
	       If the rport is non-layered your hook will be called with
	       the rectangle as passed, the [RastPort](autodocs-3.5/include-graphics-rastport-h.md), and a NULL layer...

	rect - The bounding rectangle that should be used on the layer.
	       This rectangle "clips" the cliprects to the bound given.
	       If this is NULL, no bounding will take place.
	       *MUST* not be NULL if the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) is non-layered!

    NOTES
	The [RastPort](autodocs-3.5/include-graphics-rastport-h.md) you are passed back is the same one passed to the
	function.  You should *not* use "layered" rendering functions
	on this [RastPort](autodocs-3.5/include-graphics-rastport-h.md).  Generally, you will wish to do [BitMap](autodocs-3.5/include-graphics-gfx-h.md) operations
	such as [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md).  The callback is a raw, low-level rendering
	call-back.  If you need to call a rendering operation with a
	[RastPort](autodocs-3.5/include-graphics-rastport-h.md), make sure you use a copy of the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) and NULL the
	[Layer](autodocs-3.5/include-graphics-clip-h.md) pointer.

    SEE ALSO
	[graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md) [utility/hooks.h](autodocs-3.5/include-utility-hooks-h.md)

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)

---
title: layers.library/InstallLayerInfoHook
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-installlayerinfohook
functions: [BltBitMap, InstallLayerHook]
libraries: [graphics.library, layers.library]
---

# layers.library/InstallLayerInfoHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	InstallLayerInfoHook - Install a backfill hook for non-layer      (V39)

    SYNOPSIS
	oldhook=InstallLayerInfoHook(li,hook)
	d0                           a0 a1

	struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *InstallLayerInfoHook(struct [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) *,struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *);

    FUNCTION
	This function will install a backfill hook for the [Layer_Info](autodocs-3.5/include-graphics-layers-h.md)
	structure passed.  This backfill hook will be used to clear the
	background area where no layer exists.  The hook function is
	passed the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) and the bounds just like the layer backfill
	hook.  Note that this hook could be called for any layer.

    INPUTS
	li - pointer to LayerInfo structure

	hook -  pointer to layer callback [Hook](autodocs-3.5/include-utility-hooks-h.md) which will be called
	        with object == (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *) result->RastPort
	        and message == [ (ULONG) undefined, (struct Rectangle) bounds ]

	        This hook should fill the [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	        with the BackFill pattern appropriate for rectangle given.

	        If hook is LAYERS_BACKFILL, the default backfill is
	        used.  (Same as pre-2.0)

		If hook is LAYERS_NOBACKFILL, there will be no
	        backfill.  (NO-OP).

    RESULTS
	oldhook - Returns the backfill hook that was in the [Layer_Info](autodocs-3.5/include-graphics-layers-h.md).
	          Returns LAYERS_BACKFILL if the default was installed.
	          Returns LAYERS_NOBACKFILL if there was a NO-OP hook.
	          Returns -1 if there was some failure.

    EXAMPLE
	See the example in [InstallLayerHook](autodocs-3.5/layers-library-installlayerhook-2.md).  Note that both the [Layer](autodocs-3.5/include-graphics-clip-h.md)
	pointer and the OffsetX/Y values are not available in the
	LayerInfo backfill hook.

    NOTES
	When the hook is first installed, it is *NOT* called.  It is up
	to the application to know if it is safe to fill in the area.
	Since the hook will be called when a layer is deleted, the easiest
	way to have layers call this hook is to create and delete a backdrop
	layer that is the size of the area.

	Also, note that currently the first long word of the hook message
	contains an undefined value.  This value may look like a layer pointer.
	It is *not* a layer pointer.

	The [RastPort](autodocs-3.5/include-graphics-rastport-h.md) you are passed back is the same one passed to the
	function.  You should *not* use "layered" rendering functions
	on this [RastPort](autodocs-3.5/include-graphics-rastport-h.md).  Generally, you will wish to do [BitMap](autodocs-3.5/include-graphics-gfx-h.md) operations
	such as [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md).  The callback is a raw, low-level rendering
	call-back.  If you need to call a rendering operation with a
	[RastPort](autodocs-3.5/include-graphics-rastport-h.md), make sure you use a copy of the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) and NULL the
	[Layer](autodocs-3.5/include-graphics-clip-h.md) pointer.

    SEE ALSO
	[InstallLayerHook()](autodocs-3.5/layers-library-installlayerhook-2.md)

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)
- [InstallLayerHook — layers.library](../autodocs/layers.library.md#installlayerhook)

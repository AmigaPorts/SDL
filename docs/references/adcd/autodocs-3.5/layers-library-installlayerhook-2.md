---
title: layers.library/InstallLayerHook
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-installlayerhook-2
functions: [BltBitMap]
libraries: [graphics.library]
---

# layers.library/InstallLayerHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	InstallLayerHook -- safely install a new Layer->BackFill hook.    (V36)

    SYNOPSIS
	oldhook = InstallLayerHook( layer, hook )
	d0                          a0     a1

	struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *InstallLayerHook( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *, struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *);

    FUNCTION
	Installs a new Layer->Backfill [Hook](autodocs-3.5/include-utility-hooks-h.md), waiting until it is safe to do
	so. Locks the layer while substituting the new [Hook](autodocs-3.5/include-utility-hooks-h.md) and removing the
	old one. If a new [Hook](autodocs-3.5/include-utility-hooks-h.md) is not provided, will install the default layer
	BackFill [Hook](autodocs-3.5/include-utility-hooks-h.md).

    INPUTS
	layer - pointer to the layer in which to install the Backfill [Hook](autodocs-3.5/include-utility-hooks-h.md).
	hook -  pointer to layer callback [Hook](autodocs-3.5/include-utility-hooks-h.md) which will be called
	        with object == (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *) result->RastPort
	        and message == [ (Layer *) layer, (struct Rectangle) bounds,
	                         (LONG) offsetx, (LONG) offsety ]

	        This hook should fill the [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	        with the BackFill pattern appropriate for offset x/y.

	        If hook is LAYERS_BACKFILL, the default backfill is
	        used for the layer.  (Same as pre-2.0)

	        As of V39:
		If hook is LAYERS_NOBACKFILL, the layer will not be
	        backfilled (NO-OP).

    RESULTS
	oldhook - pointer to the Layer->BackFill [Hook](autodocs-3.5/include-utility-hooks-h.md) that was previously
	          active.  Returns NULL if it was the default hook.
		  In V39, it could return 1 if there was no hook.

    EXAMPLE
	The following hook is a very simple example that does rather little
	but gives the basis idea of what is going on.

	*
	* This is the code called by the layer hook...
	* Note that some other setup is required for this to work, including
	* the definition of the PrivateData structure (pd_...) and the
	* definition of the BitMapPattern structure (bmp_...)
	*
	CoolHook:	xdef	CoolHook
			movem.l	d2-d7/a3-a6,-(sp)	; Save these...
			move.l	h_SubEntry(a0),a4	; (my private data #1 here)
			move.l	h_Data(a0),a5		; Put data into address reg
	*
	* Now, we do the rendering...
	* Note that the layer may not be important...  But it is here...
	*
			move.l	(a1)+,a0		; Get the layer...
	*
	* a1 now points at the rectangle...
	*
			move.l	pd_GfxBase(a4),a6	; Point at [GfxBase](autodocs-3.5/include-graphics-gfxbase-h.md)
			move.l	bmp_Pattern(a5),d0	; Get PatternBitMap
			beq	SimpleCase		; None?  Simple (0) case
	*
	* Now do the complex case of a pattern...
	*
			move.l	a1,a3			; Pointer to rectangle
			addq.l	#8,a1			; Get past rectangle
			move.l	(a1)+,d2		; X Offset (For pattern)
			move.l	(a1)+,d3		; Y Offset
		;
		; Whatever complex blitting you would do in the complex case
		; goes here
		;
	*
	* No bitmap, so just do the simple (0) minterm case...
	*
	SimpleCase:	moveq.l	#0,d2			; Clear d2
			move.w	ra_MinX(a1),d2		; Get X pos
	*
			moveq.l	#0,d3
			move.w	ra_MinY(a1),d3		; Get Y pos
	*
			moveq.l	#0,d4
			move.w	ra_MaxX(a1),d4
			sub.l	d2,d4
			addq.l	#1,d4			; Get X size
	*
			moveq.l	#0,d5
			move.w	ra_MaxY(a1),d5
			sub.l	d3,d5
			addq.l	#1,d5			; Get Y size
	*
			move.l	d2,d0			; X Source
			move.l	d3,d1			; Y Source
			moveq.l	#0,d6			; NULL minterm
			moveq.l	#-1,d7			; FF mask
	*
			move.l	rp_BitMap(a2),a1	; Get bitmap
			move.l	a1,a0
			CALLSYS	[BltBitMap](autodocs-3.5/graphics-library-bltbitmap-2.md)		; Do the backfill-0
	*
	HookDone:	movem.l	(sp)+,d2-d7/a3-a6	; Restore
			rts

    NOTES
	The [RastPort](autodocs-3.5/include-graphics-rastport-h.md) you are passed back is the same one passed to the
	function.  You should *not* use "layered" rendering functions
	on this [RastPort](autodocs-3.5/include-graphics-rastport-h.md).  Generally, you will wish to do [BitMap](autodocs-3.5/include-graphics-gfx-h.md) operations
	such as [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md).  The callback is a raw, low-level rendering
	call-back.  If you need to call a rendering operation with a
	[RastPort](autodocs-3.5/include-graphics-rastport-h.md), make sure you use a copy of the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) and NULL the
	[Layer](autodocs-3.5/include-graphics-clip-h.md) pointer.

    BUGS

    SEE ALSO
	[graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md) [utility/hooks.h](autodocs-3.5/include-utility-hooks-h.md)

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)

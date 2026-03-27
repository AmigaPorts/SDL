# layers.library/InstallLayerHook



    NAME
	InstallLayerHook -- safely install a new Layer->BackFill hook.    (V36)

    SYNOPSIS
	oldhook = InstallLayerHook( layer, hook )
	d0                          a0     a1

	struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *InstallLayerHook( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *, struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *);

    FUNCTION
	Installs a new Layer->Backfill [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27), waiting until it is safe to do
	so. Locks the layer while substituting the new [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) and removing the
	old one. If a new [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) is not provided, will install the default layer
	BackFill [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27).

    INPUTS
	layer - pointer to the layer in which to install the Backfill [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27).
	hook -  pointer to layer callback [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) which will be called
	        with object == (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *) result->RastPort
	        and message == [ (Layer *) layer, (struct Rectangle) bounds,
	                         (LONG) offsetx, (LONG) offsety ]

	        This hook should fill the [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	        with the BackFill pattern appropriate for offset x/y.

	        If hook is LAYERS_BACKFILL, the default backfill is
	        used for the layer.  (Same as pre-2.0)

	        As of V39:
		If hook is LAYERS_NOBACKFILL, the layer will not be
	        backfilled (NO-OP).

    RESULTS
	oldhook - pointer to the Layer->BackFill [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) that was previously
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
			move.l	pd_GfxBase(a4),a6	; Point at [GfxBase](../Includes_and_Autodocs_3._guide/node0612.html#line25)
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
			CALLSYS	[BltBitMap](../Includes_and_Autodocs_3._guide/node02B2.html)		; Do the backfill-0
	*
	HookDone:	movem.l	(sp)+,d2-d7/a3-a6	; Restore
			rts

    NOTES
	The [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) you are passed back is the same one passed to the
	function.  You should *not* use "layered" rendering functions
	on this [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).  Generally, you will wish to do [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) operations
	such as [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html).  The callback is a raw, low-level rendering
	call-back.  If you need to call a rendering operation with a
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), make sure you use a copy of the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) and NULL the
	[Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) pointer.

    BUGS

    SEE ALSO
	[graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html) [utility/hooks.h](../Includes_and_Autodocs_3._guide/node0617.html)


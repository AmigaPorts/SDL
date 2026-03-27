# layers.library/DoHookClipRects



    NAME
	DoHookClipRects - Do the given hook for each of the ClipRects    (V39)

    SYNOPSIS
	DoHookClipRects(hook,rport,rect)
	                a0   a1    a2

	void DoHookClipRects(struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *,struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *,struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) *);

    FUNCTION
	This function will call the given hook for each cliprect in the
	layer that can be rendered into.  This is how the backfill hook
	in Layers is implemented.  This means that hidden simple-refresh
	cliprects will be ignored.  It will call the SuperBitMap cliprects,
	smart refresh off-screen cliprects, and all on screen cliprects.
	If the rect parameter is not NULL, the cliprects are bounded to
	the rectangle given.

    INPUTS
	hook - pointer to layer callback [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) which will be called
	       with object == (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *) result->RastPort
	       and message == [ (Layer *) layer, (struct Rectangle) bounds,
	                        (LONG) offsetx, (LONG) offsety ]

	       This hook should fill the [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	       with the BackFill pattern appropriate for offset x/y.

	       If hook is LAYERS_BACKFILL, the default backfill is
	       used for the layer.

	       If hook is LAYERS_NOBACKFILL, the layer will not be
	       backfilled (NO-OP).

	rport- A pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) that is to be operated on.
	       This function will lock the layer if the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) is
	       layered...
	       If the rport is non-layered your hook will be called with
	       the rectangle as passed, the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), and a NULL layer...

	rect - The bounding rectangle that should be used on the layer.
	       This rectangle "clips" the cliprects to the bound given.
	       If this is NULL, no bounding will take place.
	       *MUST* not be NULL if the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) is non-layered!

    NOTES
	The [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) you are passed back is the same one passed to the
	function.  You should *not* use "layered" rendering functions
	on this [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).  Generally, you will wish to do [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) operations
	such as [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html).  The callback is a raw, low-level rendering
	call-back.  If you need to call a rendering operation with a
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), make sure you use a copy of the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) and NULL the
	[Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) pointer.

    SEE ALSO
	[graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html) [utility/hooks.h](../Includes_and_Autodocs_3._guide/node0617.html)


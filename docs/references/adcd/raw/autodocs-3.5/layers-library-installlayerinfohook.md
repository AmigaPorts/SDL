# layers.library/InstallLayerInfoHook



    NAME
	InstallLayerInfoHook - Install a backfill hook for non-layer      (V39)

    SYNOPSIS
	oldhook=InstallLayerInfoHook(li,hook)
	d0                           a0 a1

	struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *InstallLayerInfoHook(struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *,struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *);

    FUNCTION
	This function will install a backfill hook for the [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30)
	structure passed.  This backfill hook will be used to clear the
	background area where no layer exists.  The hook function is
	passed the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) and the bounds just like the layer backfill
	hook.  Note that this hook could be called for any layer.

    INPUTS
	li - pointer to LayerInfo structure

	hook -  pointer to layer callback [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) which will be called
	        with object == (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *) result->RastPort
	        and message == [ (ULONG) undefined, (struct Rectangle) bounds ]

	        This hook should fill the [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	        with the BackFill pattern appropriate for rectangle given.

	        If hook is LAYERS_BACKFILL, the default backfill is
	        used.  (Same as pre-2.0)

		If hook is LAYERS_NOBACKFILL, there will be no
	        backfill.  (NO-OP).

    RESULTS
	oldhook - Returns the backfill hook that was in the [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30).
	          Returns LAYERS_BACKFILL if the default was installed.
	          Returns LAYERS_NOBACKFILL if there was a NO-OP hook.
	          Returns -1 if there was some failure.

    EXAMPLE
	See the example in [InstallLayerHook](../Includes_and_Autodocs_3._guide/node0425.html).  Note that both the [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26)
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

	The [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) you are passed back is the same one passed to the
	function.  You should *not* use "layered" rendering functions
	on this [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).  Generally, you will wish to do [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) operations
	such as [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html).  The callback is a raw, low-level rendering
	call-back.  If you need to call a rendering operation with a
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), make sure you use a copy of the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) and NULL the
	[Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) pointer.

    SEE ALSO
	[InstallLayerHook()](../Includes_and_Autodocs_3._guide/node0425.html)


# layers.library/EndUpdate



    NAME
	EndUpdate -- remove damage list and restore state of layer to normal.

    SYNOPSIS
	EndUpdate( l, flag )
	           a0  d0

	void EndUpdate( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *, UWORD);

    FUNCTION
	After the programmer has redrawn his picture he calls this
	routine to restore the ClipRects to point to his standard
	layer tiling. The layer is then unlocked for access by the
	layer library.

	Note: use flag = FALSE if you are only making a partial update.
	    You may use the other region functions (graphics functions such as
	    [OrRectRegion](../Includes_and_Autodocs_3._guide/node030A.html), [AndRectRegion](../Includes_and_Autodocs_3._guide/node02A4.html), and [XorRectRegion](../Includes_and_Autodocs_3._guide/node0340.html) ) to clip adjust
	    the DamageList to reflect a partial update.

    INPUTS
	l - pointer to a layer
	flag - use TRUE if update was completed. The damage list is cleared.
	       use FALSE if update not complete. The damage list is retained.


    EXAMPLE
	-- begin update for first part of two-part refresh --
	BeginUpdate(my_layer);

	-- do some refresh, but not all --
	my_partial_refresh_routine(my_layer);

	-- end update, false (not completely done refreshing yet) --
	EndUpdate(my_layer, FALSE);

	-- begin update for last part of refresh --
	BeginUpdate(my_layer);

	-- do rest of refresh --
	my_complete_refresh_routine(my_layer);

	-- end update, true (completely done refreshing now) --
	EndUpdate(my_layer, TRUE);

    BUGS

    SEE ALSO
	[BeginUpdate()](../Includes_and_Autodocs_3._guide/node0418.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


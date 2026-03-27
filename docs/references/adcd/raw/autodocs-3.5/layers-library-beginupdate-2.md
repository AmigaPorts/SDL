# layers.library/BeginUpdate



    NAME
	BeginUpdate -- Prepare to repair damaged layer.

    SYNOPSIS
	result = BeginUpdate( l )
	d0                    a0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) BeginUpdate( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

    FUNCTION
	Convert damage list to [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) list and swap in for
	programmer to redraw through. This routine simulates
	the ROM library environment. The idea is to only render in the
	"damaged" areas, saving time over redrawing all of the layer.
	The layer is locked against changes made by the layer library.

    INPUTS
	l - pointer to a layer

    RESULTS
	result - TRUE if damage list converted to [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) list successfully.
	         FALSE if list conversion aborted. (probably out of memory)

    BUGS
	If BeginUpdate returns FALSE, programmer must abort the attempt to
	refresh this layer and instead call EndUpdate( l, FALSE ) to restore
	original [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) and damage list.

    SEE ALSO
	[EndUpdate()](../Includes_and_Autodocs_3._guide/node0421.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


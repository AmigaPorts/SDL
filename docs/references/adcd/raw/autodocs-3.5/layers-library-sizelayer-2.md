# layers.library/SizeLayer



    NAME
	SizeLayer -- Change the size of this nonbackdrop layer.

    SYNOPSIS
	result = SizeLayer( dummy, l, dx, dy )
	d0                  a0     a1 d0  d1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SizeLayer( [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

    FUNCTION
	Change the size of this layer by (dx,dy). The lower right hand
	corner is extended to make room for the larger layer.
	If there is SuperBitMap for this layer then copy pixels into
	or out of the layer depending on whether the layer increases or
	decreases in size.  Collect damage list for those layers that may
	need to be refreshed if damage occurred.

    INPUTS
	dummy - unused
	l - pointer to a nonbackdrop layer
	dx - delta to add to current x size
	dy - delta to add to current y size

    RESULTS
	result - TRUE if operation successful
	         FALSE if failed (out of memory)

    BUGS

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


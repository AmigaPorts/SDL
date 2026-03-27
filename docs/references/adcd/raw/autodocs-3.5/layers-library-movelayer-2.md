# layers.library/MoveLayer



    NAME
	MoveLayer -- [Move](../Includes_and_Autodocs_3._guide/node0301.html) layer to new position in [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).

    SYNOPSIS
	result = MoveLayer( dummy, l, dx, dy )
	d0                  a0     a1 d0  d1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) MoveLayer( [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

    FUNCTION
	[Move](../Includes_and_Autodocs_3._guide/node0301.html) this layer to new position in shared [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).
	If any refresh layers become revealed, collect damage and
	set REFRESH bit in layer Flags.

    INPUTS
	dummy - unused
	l - pointer to a nonbackdrop layer
	dx - delta to add to current x position
	dy - delta to add to current y position

    RETURNS
	result - TRUE if operation successful
	         FALSE if failed (out of memory)

    BUGS
	May not handle (dx,dy) which attempts to move the layer outside the
	layer's RastPort->BitMap bounds .

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


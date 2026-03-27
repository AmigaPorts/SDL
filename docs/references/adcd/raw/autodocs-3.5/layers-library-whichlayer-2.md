# layers.library/WhichLayer



    NAME
	WhichLayer -- Which [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) is this point in?

    SYNOPSIS
	layer = WhichLayer( li, x, y )
	d0                  a0  d0 d1

	struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *WhichLayer(struct Layer_Info*, WORD, WORD);

    FUNCTION
	Starting at the topmost layer check to see if this point (x,y)
	    occurs in this layer.  If it does return the pointer to this
	    layer. Return NULL if there is no layer at this point.

    INPUTS
	li  = pointer to LayerInfo structure
	(x,y) = coordinate in the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45)

    RESULTS
	layer - pointer to the topmost layer that this point is in
	        NULL if this point is not in a layer

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


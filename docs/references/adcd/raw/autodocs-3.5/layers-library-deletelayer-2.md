# layers.library/DeleteLayer



    NAME
	DeleteLayer -- delete layer from layer list.

    SYNOPSIS
	result = DeleteLayer( dummy, l )
	d0                    a0,    a1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) DeleteLayer( [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

    FUNCTION
	[Remove](../Includes_and_Autodocs_3._guide/node022F.html) this layer from the list of layers.  Release memory
	associated with it.  Restore other layers that may have been
	obscured by it.  Trigger refresh in those that may need it.
	If this is a superbitmap layer make sure SuperBitMap is current.
	The SuperBitMap is not removed from the system but is available
	for program use even though the rest of the layer information has
	been deallocated.

    INPUTS
	dummy - unused
	l - pointer to a layer

    RESULTS
	result - TRUE if this layer successfully deleted from the system
	         FALSE if layer not deleted. (probably out of memory )

    BUGS

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


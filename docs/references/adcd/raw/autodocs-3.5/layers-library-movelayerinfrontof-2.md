# layers.library/MoveLayerInFrontOf



    NAME
	MoveLayerInFrontOf -- Put layer in front of another layer.

    SYNOPSIS
	result = MoveLayerInFrontOf( layertomove, targetlayer )

                                    a0           a1
	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) MoveLayerInFrontOf( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *, struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

    FUNCTION
	[Move](../Includes_and_Autodocs_3._guide/node0301.html) this layer in front of target layer, swapping bits
	in and out of the display with other layers.
	If this is a refresh layer then collect damage list and
	set the LAYERREFRESH bit in layer->Flags if redraw required.

	Note: this operation may generate refresh events in other layers
	    associated with this layer's [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure.

    INPUTS
	layertomove - pointer to layer which should be moved
	targetlayer - pointer to target layer in front of which to move layer

    RESULTS
	result = TRUE    if operation successful
	         FALSE   if operation unsuccessful (probably out of memory)

    BUGS

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


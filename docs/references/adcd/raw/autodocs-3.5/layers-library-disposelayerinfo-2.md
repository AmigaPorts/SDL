# layers.library/DisposeLayerInfo



    NAME
	DisposeLayerInfo -- Return all memory for LayerInfo to memory pool

    SYNOPSIS
	DisposeLayerInfo( li )
	                  a0

	void DisposeLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);

    FUNCTION
	return LayerInfo and any other memory attached to this LayerInfo
	to memory allocator.

	Note: if you wish to delete the layers associated with this [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30)
	    structure, remember to call [DeleteLayer()](../Includes_and_Autodocs_3._guide/node041E.html) for each of the layers
	    before calling DisposeLayerInfo().

    INPUTS
	li - pointer to LayerInfo structure


    EXAMPLE
	-- delete the layers associated this [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure --

	DeleteLayer(li,simple_layer);
	DeleteLayer(li,smart_layer);

	-- see documentation on [DeleteLayer](../Includes_and_Autodocs_3._guide/node041E.html) about deleting SuperBitMap layers --
	my_super_bitmap_ptr = super_layer->SuperBitMap;
	DeleteLayer(li,super_layer);

	-- now dispose of the [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure itself --
	DisposeLayerInfo(li);


    BUGS

    SEE ALSO
	[DeleteLayer()](../Includes_and_Autodocs_3._guide/node041E.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


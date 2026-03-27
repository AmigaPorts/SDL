# layers.library/UnlockLayers



    NAME
	UnlockLayers -- Unlock all layers from graphics output.
	                Restart graphics output to layers that have been waiting

    SYNOPSIS
	UnlockLayers( li )
	              a0

	void UnlockLayers( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);

    FUNCTION
	Make all layers in this layer list unlocked.
	Then call [UnlockLayerInfo](../Includes_and_Autodocs_3._guide/node0433.html)

    INPUTS
	li - pointer to the [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure

    BUGS

    SEE ALSO
	[LockLayers()](../Includes_and_Autodocs_3._guide/node0429.html), [UnlockLayer()](../Includes_and_Autodocs_3._guide/node0432.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


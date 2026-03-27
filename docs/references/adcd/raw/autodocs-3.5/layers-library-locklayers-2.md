# layers.library/LockLayers



    NAME
	LockLayers -- lock all layers from graphics output.

    SYNOPSIS
	LockLayers( li )
	            a0

	void LockLayers( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);

    FUNCTION
	First calls [LockLayerInfo()](../Includes_and_Autodocs_3._guide/node0428.html)
	Make all layers in this layer list locked.

    INPUTS
	li - pointer to [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure

    BUGS

    SEE ALSO
	[LockLayer()](../Includes_and_Autodocs_3._guide/node0427.html), [LockLayerInfo()](../Includes_and_Autodocs_3._guide/node0428.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


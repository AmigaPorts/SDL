# layers.library/UnlockLayerInfo



    NAME
	UnlockLayerInfo -- Unlock the LayerInfo structure.

    SYNOPSIS
	UnlockLayerInfo( li )
	                 a0

	void UnlockLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);

    FUNCTION
	After the operation is complete that required a [LockLayerInfo](../Includes_and_Autodocs_3._guide/node0428.html),
	unlock the LayerInfo structure so that  other tasks may
	affect the layers.

    INPUTS
	li - pointer to the [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure

     BUGS

     SEE ALSO
	[LockLayerInfo()](../Includes_and_Autodocs_3._guide/node0428.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


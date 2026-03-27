# layers.library/InitLayers



    NAME
	InitLayers -- Initialize [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    SYNOPSIS
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
	InitLayers( li )
	            a0

	void InitLayers( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    FUNCTION
	Initialize [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure in preparation to use
	other layer operations on this list of layers.
	Make the Layers unlocked (open), available to layer operations.

    INPUTS
	li - pointer to LayerInfo structure

    BUGS

    SEE ALSO
	[NewLayerInfo()](../Includes_and_Autodocs_3._guide/node042D.html), [DisposeLayerInfo()](../Includes_and_Autodocs_3._guide/node041F.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


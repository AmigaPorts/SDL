# layers.library/ThinLayerInfo



    NAME
	ThinLayerInfo -- convert 1.1 LayerInfo to 1.0 LayerInfo.
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    SYNOPSIS
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
	ThinLayerInfo( li )
	               a0

	void ThinLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    FUNCTION
	return the extra memory needed that was allocated with
	[FattenLayerInfo](../Includes_and_Autodocs_3._guide/node0422.html). This is must be done prior to freeing
	the [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure itself. V1.1 software should be
	using [DisposeLayerInfo](../Includes_and_Autodocs_3._guide/node041F.html).

    INPUTS
	li - pointer to LayerInfo structure

    BUGS

    SEE ALSO
	[DisposeLayerInfo()](../Includes_and_Autodocs_3._guide/node041F.html), [FattenLayerInfo()](../Includes_and_Autodocs_3._guide/node0422.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


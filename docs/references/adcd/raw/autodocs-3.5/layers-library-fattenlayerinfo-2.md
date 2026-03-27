# layers.library/FattenLayerInfo



    NAME
	FattenLayerInfo -- convert 1.0 LayerInfo to 1.1 LayerInfo
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    SYNOPSIS
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
	FattenLayerInfo( li )
	                 a0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FattenLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);
	OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE

    FUNCTION
	V1.1 software and any later releases need to have more info in the
	[Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure. To do this in a 1.0 supportable manner requires
	allocation and deallocation of the memory whenever most
	layer library functions are called.  To prevent unnecessary
	allocation/deallocation FattenLayerInfo will preallocate the
	necessary data structures and fake out the layer library into
	thinking it has a LayerInfo gotten from [NewLayerInfo](../Includes_and_Autodocs_3._guide/node042D.html).
	[NewLayerInfo](../Includes_and_Autodocs_3._guide/node042D.html) is the approved method for getting this structure.
	When a program needs to give up the LayerInfo structure it
	must call [ThinLayerInfo](../Includes_and_Autodocs_3._guide/node0431.html) before freeing the memory. [ThinLayerInfo](../Includes_and_Autodocs_3._guide/node0431.html)
	is not necessary if [New/DisposeLayerInfo](../Includes_and_Autodocs_3._guide/node041F.html) are used however.

    INPUTS
	li - pointer to LayerInfo structure


    BUGS

    SEE ALSO
	[NewLayerInfo()](../Includes_and_Autodocs_3._guide/node042D.html), [ThinLayerInfo()](../Includes_and_Autodocs_3._guide/node0431.html), [DisposeLayerInfo()](../Includes_and_Autodocs_3._guide/node041F.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


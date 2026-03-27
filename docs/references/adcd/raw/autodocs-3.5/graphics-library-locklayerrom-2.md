# graphics.library/LockLayerRom



   NAME
	LockLayerRom -- [Lock](../Includes_and_Autodocs_3._guide/node0186.html) [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure by ROM(gfx lib) code.

   SYNOPSIS
	LockLayerRom( layer )
		       a5

	void LockLayerRom( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) * );

   FUNCTION
	Return when the layer is locked and no other task may
	alter the [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) structure in the [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure.
	This call does not destroy any registers.
	This call nests so that callers in this chain will not lock
	themselves out.
	Do not have the [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) locked during a call to intuition.
	There is a potential deadlock problem here, if intuition
	needs to get other locks as well.
	Having the layer locked prevents other tasks from using the
	layer library functions, most notably intuition itself. So
	be brief.
	layers.library's [LockLayer](../Includes_and_Autodocs_3._guide/node0427.html) is identical to LockLayerRom.

   INPUTS
	layer - pointer to [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure

   RESULTS
	The layer is locked and the task can render assuming the
	ClipRects will not change out from underneath it until
	an [UnlockLayerRom](../Includes_and_Autodocs_3._guide/node0336.html) is called.

   SEE ALSO
	[UnlockLayerRom()](../Includes_and_Autodocs_3._guide/node0336.html) [layers.library/LockLayer()](../Includes_and_Autodocs_3._guide/node0427.html) [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


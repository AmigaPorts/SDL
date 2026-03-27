# graphics.library/UnlockLayerRom



   NAME
	UnlockLayerRom -- Unlock [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure by ROM(gfx lib) code.

   SYNOPSIS
	UnlockLayerRom( layer )
			 a5

	void UnlockLayerRom( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) * );

   FUNCTION
	Release the lock on this layer. If the same task has called
	[LockLayerRom](../Includes_and_Autodocs_3._guide/node02FE.html) more than once than the same number of calls to
	UnlockLayerRom must happen before the layer is actually freed
	so that other tasks may use it.
	This call does destroy scratch registers.
	This call is identical to [UnlockLayer](../Includes_and_Autodocs_3._guide/node0432.html) (layers.library).

   INPUTS
	layer - pointer to [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure

   BUGS

   SEE ALSO
	[LockLayerRom()](../Includes_and_Autodocs_3._guide/node02FE.html) [layers.library/UnlockLayer()](../Includes_and_Autodocs_3._guide/node0432.html) [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


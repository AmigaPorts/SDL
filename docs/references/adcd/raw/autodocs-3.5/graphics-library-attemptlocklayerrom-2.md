# graphics.library/AttemptLockLayerRom


                           *
   NAME
	AttemptLockLayerRom -- Attempt to [Lock](../Includes_and_Autodocs_3._guide/node0186.html) [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure
					 by ROM(gfx lib) code

   SYNOPSIS
	gotit = AttemptLockLayerRom( layer )
	 d0			      a5

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AttempLockLayerRom( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) * );

   FUNCTION
	Query the current state of the lock on this [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26). If it is
	already locked then return FALSE, could not lock. If the
	[Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) was not locked then lock it and return TRUE.
	This call does not destroy any registers.
	This call nests so that callers in this chain will not lock
	themselves out.

   INPUTS
	layer - pointer to [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure

   RESULT
	gotit - TRUE or FALSE depending on whether the [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) was
		successfully locked by the caller.

   SEE ALSO
	[LockLayerRom()](../Includes_and_Autodocs_3._guide/node02FE.html) [UnlockLayerRom()](../Includes_and_Autodocs_3._guide/node0336.html)


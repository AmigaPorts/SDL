# layers.library/LockLayerInfo



    NAME
	LockLayerInfo -- [Lock](../Includes_and_Autodocs_3._guide/node0186.html) the LayerInfo structure.

    SYNOPSIS
	LockLayerInfo( li )
	               a0

	void LockLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *);

    FUNCTION
	Before doing an operation that requires the LayerInfo
	structure, make sure that no other task is also using the
	LayerInfo structure.  LockLayerInfo() returns when the
	LayerInfo belongs to this task.  There should be
	an [UnlockLayerInfo](../Includes_and_Autodocs_3._guide/node0433.html) for every LockLayerInfo.

	Note: All layer routines presently LockLayerInfo() when they
	start up and [UnlockLayerInfo()](../Includes_and_Autodocs_3._guide/node0433.html) as they exit.  Programmers
	will need to use these Lock/Unlock routines if they wish
	to do something with the LayerStructure that is not
	supported by the layer library.

    INPUTS
	li - pointer to [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure

    BUGS

    SEE ALSO
	[UnlockLayerInfo()](../Includes_and_Autodocs_3._guide/node0433.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


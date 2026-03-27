# layers.library/LockLayer



    NAME
	LockLayer -- [Lock](../Includes_and_Autodocs_3._guide/node0186.html) layer to make changes to ClipRects.

    SYNOPSIS
	LockLayer( dummy, l )
	           a0     a1

	void LockLayer( [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

    FUNCTION
	Make this layer unavailable for other tasks to use.
	If another task is already using this layer then wait for
	it to complete and then reserve the layer for your own use.
	(this function does the same thing as graphics.library/LockLayerRom)

	Note: if you wish to lock MORE THAN ONE layer at a time, you
	    must call [LockLayerInfo()](../Includes_and_Autodocs_3._guide/node0428.html) before locking those layers and
	    then call [UnlockLayerInfo()](../Includes_and_Autodocs_3._guide/node0433.html) when you have finished. This
	    is to prevent system "deadlocks".

	Further Note: while you hold the lock on a layer, Intuition will block
	    on operations such as windowsizing, dragging, menus, and depth
	    arranging windows in this layer's screen.  It is recommended that
	    YOU do not make Intuition function calls while the layer is locked.

    INPUTS
	dummy - unused
	l - pointer to a layer

    BUGS

    SEE ALSO
	[UnlockLayer()](../Includes_and_Autodocs_3._guide/node0432.html), [LockLayerInfo()](../Includes_and_Autodocs_3._guide/node0428.html), [UnlockLayerInfo()](../Includes_and_Autodocs_3._guide/node0433.html),
	[graphics.library/LockLayerRom()](../Includes_and_Autodocs_3._guide/node02FE.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


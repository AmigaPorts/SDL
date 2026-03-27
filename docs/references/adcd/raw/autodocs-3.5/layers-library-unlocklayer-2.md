# layers.library/UnlockLayer



    NAME
	UnlockLayer -- Unlock layer and allow graphics routines to use it.

    SYNOPSIS
	UnlockLayer( l )
	             a0

	void UnlockLayer( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

    FUNCTION
	When finished changing the ClipRects or whatever you were
	doing with this layer you must call UnlockLayer() to allow
	other tasks to proceed with graphic output to the layer.

    INPUTS
	l - pointer to a layer

    BUGS

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


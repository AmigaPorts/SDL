# layers.library/NewLayerInfo



    NAME
	NewLayerInfo -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) and Initialize full [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure.

    SYNOPSIS
	result = NewLayerInfo()
	d0

	struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *NewLayerInfo( void );

    FUNCTION
	[Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) memory required for full [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure.
	Initialize [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure in preparation to use
	other layer operations on this list of layers.
	Make the [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) unlocked (open).

    INPUTS
	None

    RESULT
	result- pointer to [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure if successful
	        NULL if not enough memory

    BUGS

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


# layers.library/UpfrontLayer



    NAME
	UpfrontLayer -- Put layer in front of all other layers.

    SYNOPSIS
	result = UpfrontLayer( dummy, l )
	d0                     a0     a1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) UpfrontLayer( [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

    FUNCTION
	[Move](../Includes_and_Autodocs_3._guide/node0301.html) this layer to the most upfront position swapping bits
	in and out of the display with other layers.
	If this is a refresh layer then collect damage list and
	set the LAYERREFRESH bit in layer->Flags if redraw required.
	By clearing the BACKDROP bit in the layers Flags you may
	bring a Backdrop layer up to the front of all other layers.

	Note: this operation may generate refresh events in other layers
	   associated with this layer's [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure.

    INPUTS
	dummy - unused
	l - pointer to a nonbackdrop layer

    RESULTS
	result - TRUE   if operation successful
	         FALSE  if operation unsuccessful (probably out of memory)

    BUGS

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html)


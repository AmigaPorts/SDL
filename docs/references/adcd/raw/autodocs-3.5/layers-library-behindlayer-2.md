# layers.library/BehindLayer



    NAME
	BehindLayer -- Put layer behind other layers.

    SYNOPSIS
	result = BehindLayer( dummy, l )
	d0                    a0     a1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) BehindLayer( [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

    FUNCTION
	[Move](../Includes_and_Autodocs_3._guide/node0301.html) this layer to the most behind position swapping bits
	in and out of the display with other layers.
	If other layers are REFRESH then collect their damage lists and
	set the LAYERREFRESH bit in the Flags fields of those layers that
	may be revealed.  If this layer is a backdrop layer then
	put this layer behind all other backdrop layers.
	If this layer is NOT a backdrop layer then put in front of the
	top backdrop layer and behind all other layers.

	Note: this operation may generate refresh events in other layers
	   associated with this layer's [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) structure.

    INPUTS
	dummy - unused
	l - pointer to a layer

    RESULTS
	result - TRUE    if operation successful
	         FALSE   if operation unsuccessful (probably out of memory)


```c
    BUGS

    SEE ALSO
       [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)
```

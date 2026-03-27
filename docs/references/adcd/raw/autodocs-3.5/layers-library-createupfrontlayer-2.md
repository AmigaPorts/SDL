# layers.library/CreateUpfrontLayer



    NAME
	CreateUpfrontLayer -- Create a new layer on top of existing layers.

    SYNOPSIS
	result = CreateUpfrontLayer(li,bm,x0,y0,x1,y1,flags [,bm2])
	d0                          a0 a1 d0 d1 d2 d3   d4  [ a2 ]

	struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *CreateUpfrontLayer(struct [Layer_Info](../Includes_and_Autodocs_3._guide/node0625.html#line30) *, struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *,
	    [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), ... );

    FUNCTION
	Create a new [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) of position and size (x0,y0)->(x1,y1)
	and place it on top of all other layers.
	Make this layer of type found in flags
	if SuperBitMap, use bm2 as pointer to real SuperBitMap.
	and copy contents of Superbitmap into display layer.

	Note: when using SUPERBITMAP, you should also set LAYERSMART flag.

    INPUTS
	li - pointer to LayerInfo structure
	bm - pointer to common [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) used by all Layers
	x0,y0 - upper left hand corner of layer
	x1,y1 - lower right hand corner of layer
	flags - various types of layers supported as bit sets.
	bm2 - pointer to optional Super [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45)

    RESULTS
	result - pointer to [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) structure if successful
	         NULL if not successful


```c
    BUGS

    SEE ALSO
       [DeleteLayer()](../Includes_and_Autodocs_3._guide/node041E.html), [graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html), [graphics/gfx.h](../Includes_and_Autodocs_3._guide/node05DC.html)
```

# layers.library/MoveSizeLayer



```c
    NAME                                                              (V36)
```
	MoveSizeLayer -- Position/Size layer

    SYNOPSIS
	result = MoveSizeLayer( layer, dx, dy, dw, dh )
	d0                      a0     d0  d1  d2  d3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) MoveSizeLayer( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

    FUNCTION
	Change upperleft and lower right position of [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26).

    INPUTS
	dummy - unused
	l - pointer to a nonbackdrop layer
	dx,dy - change upper left corner by (dx,dy)
	dw,dy - change size by (dw,dh)

    RETURNS
	result - TRUE if operation successful
	         FALSE if failed (due to out of memory)
	         FALSE if failed (due to illegal layer->bounds)

    BUGS

    SEE ALSO
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


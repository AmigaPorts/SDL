# graphics.library/Move



   NAME
	Move -- Move graphics pen position.

   SYNOPSIS
	Move( rp,   x,    y)
	      a1  d0:16 d1:16

	void Move( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63) );

   FUNCTION
	Move graphics pen position to (x,y) relative to upper left (0,0)
	of [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53). This sets the starting point for subsequent [Draw()](../Includes_and_Autodocs_3._guide/node02CD.html)
	and [Text()](../Includes_and_Autodocs_3._guide/node0332.html) calls.

   INPUTS
	rp - pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	x,y - point in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   RESULTS

   BUGS

   SEE ALSO
	[Draw()](../Includes_and_Autodocs_3._guide/node02CD.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


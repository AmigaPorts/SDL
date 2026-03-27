# graphics.library/AreaMove



   NAME
	AreaMove -- Define a new starting point for a new
	            shape in the vector list.


   SYNOPSIS
	error =  AreaMove( rp,   x,     y)
	 d0                a1  d0:16  d1:16

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AreaMove( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63) );

   FUNCTION
	[Close](../Includes_and_Autodocs_3._guide/node0149.html)  the last polygon and start another polygon
	at  (x,y). Add the necessary  points  to  vector
	buffer. Closing a polygon may result in the generation
	of another [AreaDraw()](../Includes_and_Autodocs_3._guide/node02A8.html) to close previous polygon.
	[Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) to have an initialized [AreaInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line20) structure attached
	to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   INPUTS
	rp  - points to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	x,y - positions in the raster

   RETURNS
	error - zero for success, or -1 if there is no space left in the
	vector list

   BUGS

   SEE ALSO
	[InitArea()](../Includes_and_Autodocs_3._guide/node02F2.html) [AreaDraw()](../Includes_and_Autodocs_3._guide/node02A8.html) [AreaEllipse()](../Includes_and_Autodocs_3._guide/node02A9.html) [AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


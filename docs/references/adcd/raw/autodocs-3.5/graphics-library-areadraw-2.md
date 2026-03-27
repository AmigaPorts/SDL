# graphics.library/AreaDraw



   NAME
	AreaDraw -- Add a point to a list of end points for areafill.


   SYNOPSIS
	error = AreaDraw( rp,  x,     y)
	  d0	          A1 D0:16 D1:16

	ULONG AreaDraw( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), SHORT);

   FUNCTION
	Add point to the vector buffer.


   INPUTS
	rp	- points to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
	x,y	- are coordinates of a point in the raster.

   RESULT
	error	- zero for success, else -1 if no there was no space
		  left in the vector list.

   BUGS

   SEE ALSO
	[AreaMove()](../Includes_and_Autodocs_3._guide/node02AB.html) [InitArea()](../Includes_and_Autodocs_3._guide/node02F2.html) [AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


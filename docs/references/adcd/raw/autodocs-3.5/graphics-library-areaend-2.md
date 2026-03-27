# graphics.library/AreaEnd



   NAME
	AreaEnd -- [Process](../Includes_and_Autodocs_3._guide/node05D9.html#line36) table of vectors and ellipses and produce areafill.


   SYNOPSIS
	error = AreaEnd(rp)
	  d0  	        A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AreaEnd( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) * );

   FUNCTION
	Trigger the filling operation.
	[Process](../Includes_and_Autodocs_3._guide/node05D9.html#line36) the vector buffer and generate required
	fill into the raster planes. After the fill is complete, reinitialize
	for the next [AreaMove](../Includes_and_Autodocs_3._guide/node02AB.html) or [AreaEllipse](../Includes_and_Autodocs_3._guide/node02A9.html). Use the raster set up by
	[InitTmpRas](../Includes_and_Autodocs_3._guide/node02F8.html) when generating an areafill mask.

   RESULT
	error - zero for success, or -1 if an error occurred anywhere.

   INPUTS
	rp - pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure which specifies where the filled
	     regions will be rendered to.

   BUGS

   SEE ALSO
	[InitArea()](../Includes_and_Autodocs_3._guide/node02F2.html) [AreaMove()](../Includes_and_Autodocs_3._guide/node02AB.html) [AreaDraw()](../Includes_and_Autodocs_3._guide/node02A8.html) [AreaEllipse()](../Includes_and_Autodocs_3._guide/node02A9.html)  [InitTmpRas()](../Includes_and_Autodocs_3._guide/node02F8.html)
	[graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


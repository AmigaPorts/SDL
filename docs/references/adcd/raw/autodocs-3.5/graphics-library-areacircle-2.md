# graphics.library/AreaCircle



    NAME
	AreaCircle -- add a circle to areainfo list for areafill.


    SYNOPSIS
	error = (int) AreaCircle( rp,  cx,  cy, radius)
	D0			  A1   D0   D1	D2

	ULONG AreaCircle(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD, UWORD);

    FUNCTION
	Add circle to the vector buffer. It will be drawn to the rastport when
	[AreaEnd](../Includes_and_Autodocs_3._guide/node02AA.html) is executed.

    INPUTS
	rp	 - pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure

	cx, cy   - the coordinates of the center of the desired circle.

	radius	 - is the radius of the circle to draw around the centerpoint.

    RESULTS
	0 if no error
	-1 if no space left in vector list

    NOTES
	This function is actually a macro which calls
	    AreaEllipse(rp,cx,cy,radius,radius).

    SEE ALSO
	[AreaMove()](../Includes_and_Autodocs_3._guide/node02AB.html) [AreaDraw()](../Includes_and_Autodocs_3._guide/node02A8.html) AreaCircle() [InitArea()](../Includes_and_Autodocs_3._guide/node02F2.html) [AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html)
	[graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html) [graphics/gfxmacros.h](../Includes_and_Autodocs_3._guide/node0660.html)


# graphics.library/AreaEllipse



    NAME
	AreaEllipse -- add a ellipse to areainfo list for areafill.


    SYNOPSIS
	error = AreaEllipse( rp, cx,   cy,   a,    b    )
	d0		     a1  d0:16 d1:16 d2:16 d3:16

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AreaEllipse( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), SHORT)

    FUNCTION
	Add an ellipse to the vector buffer. It will be draw when [AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) is
	called.

    INPUTS
	rp - pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	cx - x coordinate of the centerpoint relative to the rastport.
	cy - y coordinate of the centerpoint relative to the rastport.
	a  - the horizontal radius of the ellipse (note: a must be > 0)
	b  - the vertical radius of the ellipse (note: b must be > 0)

    RESULT
	error - zero for success, or -1 if there is no space left in the
		vector list

    SEE ALSO
	[AreaMove()](../Includes_and_Autodocs_3._guide/node02AB.html) [AreaDraw()](../Includes_and_Autodocs_3._guide/node02A8.html) [AreaCircle()](../Includes_and_Autodocs_3._guide/node02A7.html) [InitArea()](../Includes_and_Autodocs_3._guide/node02F2.html) [AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html)
	[graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


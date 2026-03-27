# graphics.library/DrawEllipse



    NAME
	DrawEllipse -- [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) an ellipse centered at cx,cy with vertical
	   and horizontal radii of a,b respectively.

    SYNOPSIS
	DrawEllipse( rp, cx, cy, a, b )
		     a1  d0  d1  d2 d3

	void DrawEllipse( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), SHORT);

    FUNCTION
       Creates an elliptical outline within the rectangular region
	specified by the parameters, using the current foreground pen color.

    INPUTS
	rp - pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) into which the ellipse will be drawn.
	cx - x coordinate of the centerpoint relative to the rastport.
	cy - y coordinate of the centerpoint relative to the rastport.
	a - the horizontal radius of the ellipse (note: a must be > 0)
	b - the vertical radius of the ellipse (note: b must be > 0)

    BUGS

    NOTES
	this routine does not clip the ellipse to a non-layered rastport.

    SEE ALSO
	DrawCircle macro
	[graphics/gfxmacros.h](../Includes_and_Autodocs_3._guide/node0660.html)
	[graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


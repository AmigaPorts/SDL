# graphics.library/RectFill



   NAME

```c
       RectFill -- Fill a rectangular region in a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).
```
   SYNOPSIS

	RectFill( rp, xmin, ymin, xmax, ymax)

                 a1  d0:16 d1:16 d2:16 d3:16
	void RectFill( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63) );

   FUNCTION
	Fills  the  rectangular  region  specified  by  the
	parameters  with the chosen pen  colors,  areafill
	pattern, and drawing mode. If no areafill pattern is
	specified, fill the rectangular region with the FgPen
	color, taking into account the drawing mode.

   INPUTS
	rp - pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	(xmin,ymin) (xmax,ymax) are the coordinates of the upper
		left corner and the lower right corner, respectively, of the
	        rectangle.
   NOTE

	The following relation MUST be true:
		(xmax >= xmin) and (ymax >= ymin)

   BUGS
	Complement mode with FgPen complements all bitplanes.

   SEE ALSO
	[AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


# graphics.library/EraseRect



   NAME

       EraseRect -- Fill a defined rectangular area using the current
		     	BackFill hook. (V36)

   SYNOPSIS
	EraseRect( rp, xmin, ymin, xmax, ymax)

                  a1  d0:16 d1:16 d2:16 d3:16
	void EraseRect(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), SHORT);

   FUNCTION
	Fill the rectangular region specified by the parameters with the
	BackFill hook. If non-layered, the rectangular region specified by
	the parameters is cleared. If layered the Layer->BackFill [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) is used.

   INPUTS
	rp	- pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	xmin	- x coordinate of the upper left corner of the region to fill.
	ymin	- y coordinate of the upper left corner of the region to fill.
	xmax	- x coordinate of the lower right corner of the region to fill.
	ymax	- y coordinate of the lower right corner of the region to fill.

   BUGS

   NOTES
	The following relation MUST be true:
	(xmax >= xmin) and (ymax >= ymin)

   SEE ALSO
	[graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html) [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)


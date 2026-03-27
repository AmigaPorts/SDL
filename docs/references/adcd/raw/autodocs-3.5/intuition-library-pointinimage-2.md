# intuition.library/PointInImage



   NAME	
	PointInImage -- Tests whether an image "contains" a point. (V36)

   SYNOPSIS
	DoesContain = PointInImage( Point, [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) )
	D0	  		    D0     A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) PointInImage( struct Point, struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) * );

   FUNCTION
	Tests whether a point is properly contained in an image.
	The intention of this is to provide custom gadgets a means
	to delegate "image mask" processing to the [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704), where
	it belongs (superseding things like BOOLMASK).  After all,
	a rounded rect image with a drop shadow knows more about
	what points are inside it than anybody else should.

	For traditional Intuition Images, this routine checks if
	the point is in the [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) box (LeftEdge/RightEdge/Width/Height).

   INPUTS
 	Point	- Two words, X/Y packed into a [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), with high word
		containing 'X'.  This is what you get if you pass
		a Point structure (not a pointer!) using common
		C language parameter conventions.
	[Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) - a pointer to a standard or custom [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) data object.
	    NOTE: If 'Image' is NULL, this function returns TRUE.

   RESULT
 	DoesContain - Boolean result of the test.

   EXAMPLE


   NOTES


   BUGS
	Only applies to the first image, does not follow NextImage
	linked list.  This might be preferred.

   SEE ALSO


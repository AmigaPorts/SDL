# graphics.library/PolyDraw



   NAME
	PolyDraw -- [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) lines from table of (x,y) values.

   SYNOPSIS
	PolyDraw( rp, count , array )
		  a1   d0      a0

	void PolyDraw( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD * );

   FUNCTION
	starting with the first pair in the array, draw connected lines to
	it and every successive pair.

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	count -  number of (x,y) pairs in the array
	array - pointer to first (x,y) pair

   BUGS

   SEE ALSO
	[Draw()](../Includes_and_Autodocs_3._guide/node02CD.html) [Move()](../Includes_and_Autodocs_3._guide/node0301.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


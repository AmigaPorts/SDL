# graphics.library/Flood



   NAME
	Flood -- Flood rastport like areafill.

   SYNOPSIS
	error = Flood( rp, mode, x, y)

        d0            a1   d2  d0  d1
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) Flood(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, ULONG, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), SHORT);

   FUNCTION
	Search the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) starting at (x,y).
	Fill all adjacent pixels if they are:
	    Mode 0: not the same color as AOLPen
	    Mode 1: the same color as the pixel at (x,y)

	When actually doing the fill use the modes that apply to
	standard areafill routine such as drawmodes and patterns.

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	(x,y) - coordinate in [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) to start the flood fill at.
	mode -  0 fill all adjacent pixels searching for border.
		1 fill all adjacent pixels that have same pen number
		as the one at (x,y).

   NOTES
	In order to use Flood, the destination [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) must
	have a valid [TmpRas](../Includes_and_Autodocs_3._guide/node05D7.html#line31) raster whose size is as large as
	that of the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   SEE ALSO
	[AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) [InitTmpRas()](../Includes_and_Autodocs_3._guide/node02F8.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


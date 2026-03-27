# graphics.library/BltBitMapRastPort



   NAME
	BltBitMapRastPort -- Blit from source bitmap to destination rastport.

   SYNOPSIS
	error = BltBitMapRastPort
	        (srcbm, srcx, srcy, destrp, destX, destY, sizeX, sizeY, minterm)
	 D0      A0     D0    D1    A1      D2     D3     D4     D5     D6

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) BltBitMapRastPort
	     (struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *, WORD, WORD, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD,
	      WORD, WORD, UBYTE);

   FUNCTION
	Blits from source bitmap to position specified in destination rastport
	using minterm.

   INPUTS
	srcbm   - a pointer to the source bitmap
	srcx    - x offset into source bitmap
	srcy    - y offset into source bitmap
	destrp  - a pointer to the destination rastport
	destX   - x offset into dest rastport
	destY   - y offset into dest rastport
	sizeX   - width of blit in pixels
	sizeY   - height of blit in rows
	minterm - minterm to use for this blit

   RESULT
	TRUE

   BUGS

   SEE ALSO
	[BltMaskBitMapRastPort()](../Includes_and_Autodocs_3._guide/node02B5.html) [graphics/gfx.h](../Includes_and_Autodocs_3._guide/node05DC.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


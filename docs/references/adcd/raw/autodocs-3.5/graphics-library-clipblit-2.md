# graphics.library/ClipBlit



   NAME
	ClipBlit  --  Calls [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html) after accounting for windows

   SYNOPSIS
	ClipBlit(Src, SrcX, SrcY, Dest, DestX, DestY, XSize, YSize, Minterm)
	         A0   D0    D1    A1    D2     D3     D4     D5     D6

	void ClipBlit
	     (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD,
	      WORD, WORD, UBYTE);

   FUNCTION
	Performs the same function as [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html), except that it
	takes into account the Layers and ClipRects of the layer library,
	all of which are (and should be) transparent to you.  So, whereas
	[BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html) requires pointers to BitMaps, ClipBlit requires pointers to
	the RastPorts that contain the Bitmaps, Layers, etcetera.

	If you are going to blit blocks of data around via the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) of your
	Intuition [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), you must call this routine (rather than [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html)).

	Either the Src [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), the Dest [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), both, or neither, can have
	Layers. This routine takes care of all cases.

	See [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html) for a thorough explanation.

   INPUTS
	Src          = pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) of the source for your blit
	SrcX, SrcY   = the topleft offset into Src for your data
	Dest         = pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to receive the blitted data
	DestX, DestY = the topleft offset into the destination [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	XSize        = the width of the blit (must be ta least 1)
	YSize        = the height of the blit (must be at least 1)
	Minterm      = the boolean blitter function, where SRCB is associated
	               with the Src [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) and SRCC goes to the Dest [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   RESULT

   BUGS

   SEE ALSO
	[BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html)


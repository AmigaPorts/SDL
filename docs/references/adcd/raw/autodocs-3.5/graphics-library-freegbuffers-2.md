# graphics.library/FreeGBuffers



   NAME
	FreeGBuffers -- [Deallocate](../Includes_and_Autodocs_3._guide/node01FE.html) memory obtained by GetGBufers.

   SYNOPSIS
	FreeGBuffers(anOb, rp, db)
	             A0    A1  D0

	void FreeGBuffers(struct [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, BOOL);

   FUNCTION
	For each sequence of each component of the [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203),
	deallocate memory for:
	    SaveBuffer
	    BorderLine
	    CollMask and ImageShadow (point to same buffer)
	    if db is set (user had used double-buffering) deallocate:
	        [DBufPacket](../Includes_and_Autodocs_3._guide/node05D4.html#line234)
	        BufBuffer

   INPUTS
	anOb = pointer to the [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) structure
	rp   = pointer to the current [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	db   = double-buffer indicator (set TRUE for double-buffering)

   RESULT

   BUGS

   SEE ALSO
	[GetGBuffers()](../Includes_and_Autodocs_3._guide/node02E7.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)


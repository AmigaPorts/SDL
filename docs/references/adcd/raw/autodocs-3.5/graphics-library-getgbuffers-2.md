# graphics.library/GetGBuffers



   NAME
	GetGBuffers -- Attempt to allocate ALL buffers of an entire [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203).

   SYNOPSIS
	status = GetGBuffers(anOb, rp, db)
	D0                   A0    A1  D0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) GetGBuffers(struct [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, BOOL);

   FUNCTION
	For each sequence of each component of the [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203), allocate memory for:
	    SaveBuffer
	    BorderLine
	    CollMask and ImageShadow (point to same buffer)
	    if db is set TRUE (user wants double-buffering) allocate:
	        [DBufPacket](../Includes_and_Autodocs_3._guide/node05D4.html#line234)
	        BufBuffer

   INPUTS
	anOb = pointer to the [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) structure
	rp   = pointer to the current [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	db   = double-buffer indicator (set TRUE for double-buffering)

   RESULT
	status = TRUE if the memory allocations were all successful, else FALSE

   BUGS
	If any of the memory allocations fail it does not free the partial
	allocations that did succeed.

   SEE ALSO
	[FreeGBuffers()](../Includes_and_Autodocs_3._guide/node02DB.html) [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)


# iffparse.library/GoodID



   NAME
	GoodID -- test if an identifier follows the IFF 85 specification. (V36)

   SYNOPSIS
	isok = GoodID(id);
	D0            D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) GoodID(LONG);

   FUNCTION
	Tests the given longword identifier to see if it meets all the EA IFF
	85 specifications for a chunk ID. If so, it returns non-zero,
	otherwise 0.

   INPUTS
	id - potential 32 bit identifier.

   RESULT
	isok - non-zero if this is a valid ID, 0 otherwise.

   SEE ALSO
	[GoodType()](../Includes_and_Autodocs_3._guide/node0369.html)


# iffparse.library/PropChunks



   NAME
	PropChunks -- declare many property chunks at once. (V36)

   SYNOPSIS
	error = PropChunks(iff, propArray, numPairs);
	D0                 A0   A1         D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PropChunks(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *, LONG);

   FUNCTION
	Declares multiple property chunks from a list. The propArray argument
	if a pointer to an array of longwords arranged in pairs, and has the
	following format:

		TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

	The argument numPairs is the number of pairs. PropChunks() just calls
	[PropChunk()](../Includes_and_Autodocs_3._guide/node0374.html) numPairs times.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	propArray - pointer to array of longword chunk types and identifiers.
	numPairs - number of pairs in the array.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PropChunk()](../Includes_and_Autodocs_3._guide/node0374.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


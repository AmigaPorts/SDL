# iffparse.library/CollectionChunks



   NAME
	CollectionChunks -- declare many collection chunks at once. (V36)

   SYNOPSIS
	error = CollectionChunks(iff, propArray, numPairs);
	D0                       A0   A1         D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CollectionChunks(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *, LONG);

   FUNCTION
	Declares multiple collection chunks from a list. The propArray argument
	is a pointer to an array of longwords arranged in pairs. The format
	for the list is as follows:

		TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

	The argument numPairs is the number of pairs. CollectionChunks() just calls
	[CollectionChunk()](../Includes_and_Autodocs_3._guide/node035D.html) numPairs times.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure (does not need to be open)
	propArray - pointer to array of longword chunk types and identifiers
	numPairs - number of pairs in array.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful

   SEE ALSO
	[CollectionChunk()](../Includes_and_Autodocs_3._guide/node035D.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


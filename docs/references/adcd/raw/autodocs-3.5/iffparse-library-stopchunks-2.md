# iffparse.library/StopChunks



   NAME
	StopChunks -- declare many stop chunks at once. (V36)

   SYNOPSIS
	error = StopChunks(iff, propArray, numPairs);
	D0                 A0   A1         D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) StopChunks(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *, LONG);

   FUNCTION
	(is to [StopChunk()](../Includes_and_Autodocs_3._guide/node037A.html) as [PropChunks()](../Includes_and_Autodocs_3._guide/node0375.html) is to PropChunk().)

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	propArray - pointer to array of longword chunk types and identifiers.
	numPairs - number of pairs in the array.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[StopChunk()](../Includes_and_Autodocs_3._guide/node037A.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


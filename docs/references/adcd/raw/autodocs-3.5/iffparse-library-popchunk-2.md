# iffparse.library/PopChunk



   NAME
	PopChunk -- pop top context node off context stack. (V36)

   SYNOPSIS
	error = PopChunk(iff);
	D0               A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PopChunk(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *);

   FUNCTION
	Pops top context chunk and frees all associated local context items.
	The function is normally called only for writing files and signals
	the end of a chunk.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PushChunk()](../Includes_and_Autodocs_3._guide/node0376.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


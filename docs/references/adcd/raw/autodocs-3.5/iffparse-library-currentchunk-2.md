# iffparse.library/CurrentChunk



   NAME
	CurrentChunk -- get context node for current chunk. (V36)

   SYNOPSIS
	top = CurrentChunk(iff);
	D0                 A0

	struct [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) *CurrentChunk(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *);

   FUNCTION
	Returns the top context node for the given [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure. The top
	context node corresponds to the chunk most recently pushed on the
	stack, which is the chunk where the stream is currently positioned.
	The [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) structure contains information on the type of chunk
	currently being parsed (or written), its size and the current
	position within the chunk.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure

   RESULT
	top - pointer to top context node or NULL if none

   SEE ALSO
	[PushChunk()](../Includes_and_Autodocs_3._guide/node0376.html), [PopChunk()](../Includes_and_Autodocs_3._guide/node0373.html), [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html), [ParentChunk()](../Includes_and_Autodocs_3._guide/node0371.html),
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


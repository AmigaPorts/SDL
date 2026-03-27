# iffparse.library/ParentChunk



   NAME
	ParentChunk -- get the nesting context node for the given chunk. (V36)

   SYNOPSIS
	parent = ParentChunk(contextNode);
	D0                   A0

	struct [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) *ParentChunk(struct [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) *);

   FUNCTION
	Returns a context node for the chunk containing the chunk for the
	given context node. This function effectively moves down the context
	stack into previously pushed contexts. For example, to get a
	[ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) pointer for the enclosing FORM chunk while reading a data
	chunk, use: ParentChunk(CurrentChunk(iff)) to find this pointer.
	The [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) structure contains information on the type of chunk
	and its size.

   INPUTS
	contextNode - pointer to a context node.

   RESULT
	parent - pointer to the enclosing context node or NULL if none.

   SEE ALSO
	[CurrentChunk()](../Includes_and_Autodocs_3._guide/node035F.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


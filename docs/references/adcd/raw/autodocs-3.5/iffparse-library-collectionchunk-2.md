# iffparse.library/CollectionChunk



   NAME
	CollectionChunk -- declare a chunk type for collection. (V36)

   SYNOPSIS
	error = CollectionChunk(iff, type, id);
	D0                      A0   D0    D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CollectionChunk(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Installs an entry handler for chunks with the given type and id so
	that the contents of those chunks will be stored as they are
	encountered. This is like [PropChunk()](../Includes_and_Autodocs_3._guide/node0374.html) except that more than one
	chunk of this type can be stored in lists which can be returned by
	[FindCollection()](../Includes_and_Autodocs_3._guide/node0362.html). The storage of these chunks still follows the
	property chunk scoping rules for IFF files so that at any given
	point, stored collection chunks will be valid in the current context.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure (does not need to be open)
	type - type code for the chunk to declare (ex. "ILBM")
	id - identifier for the chunk to declare (ex. "CRNG")

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[CollectionChunks()](../Includes_and_Autodocs_3._guide/node035E.html), [FindCollection()](../Includes_and_Autodocs_3._guide/node0362.html), [PropChunk()](../Includes_and_Autodocs_3._guide/node0374.html),
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


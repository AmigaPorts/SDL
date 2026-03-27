# iffparse.library/FindProp



   NAME
	FindProp -- search for a stored property chunk. (V36)

   SYNOPSIS
	sp = FindProp(iff, type, id);
	D0            A0   D0    D1

	struct [StoredProperty](../Includes_and_Autodocs_3._guide/node05E8.html#line118) *FindProp(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Searches for the stored property which is valid in the given context.
	Property chunks are automatically stored by [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html) when
	pre-declared by [PropChunk()](../Includes_and_Autodocs_3._guide/node0374.html) or [PropChunks()](../Includes_and_Autodocs_3._guide/node0375.html). The [StoredProperty](../Includes_and_Autodocs_3._guide/node05E8.html#line118)
	struct, if found, contains a pointer to a data buffer containing the
	contents of the stored property.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	type - type code for chunk to search for (ex. "ILBM").
	id - identifier code for chunk to search for (ex. "CMAP").

   RESULT
	sp - pointer to stored property, or NULL if none found.

   SEE ALSO
	[PropChunk()](../Includes_and_Autodocs_3._guide/node0374.html), [PropChunks()](../Includes_and_Autodocs_3._guide/node0375.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


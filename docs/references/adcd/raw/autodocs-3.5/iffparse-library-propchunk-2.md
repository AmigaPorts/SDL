# iffparse.library/PropChunk



   NAME
	PropChunk -- specify a property chunk to store. (V36)

   SYNOPSIS
	error = PropChunk(iff, type, id);
	D0                A0   D0    D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PropChunk(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Installs an entry handler for chunks with the given type and ID so
	that the contents of those chunks will be stored as they are
	encountered. The storage of these chunks follows the property chunk
	scoping rules for IFF files so that at any given point, a stored
	property chunk returned by [FindProp()](../Includes_and_Autodocs_3._guide/node0364.html) will be the valid property for
	the current context.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure (does not need to be open).
	type - type code for the chunk to declare (ex. "ILBM").
	id - identifier for the chunk to declare (ex. "CMAP").

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PropChunks()](../Includes_and_Autodocs_3._guide/node0375.html), [FindProp()](../Includes_and_Autodocs_3._guide/node0364.html), [CollectionChunk()](../Includes_and_Autodocs_3._guide/node035D.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


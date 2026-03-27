# iffparse.library/FindCollection



   NAME
	FindCollection -- get a pointer to the current list of collection
			  items. (V36)

   SYNOPSIS
	ci = FindCollection(iff, type, id);
	D0                  A0   D0    D1

	struct [CollectionItem](../Includes_and_Autodocs_3._guide/node05E8.html#line132) *FindCollection(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Returns a pointer to a list of [CollectionItem](../Includes_and_Autodocs_3._guide/node05E8.html#line132) structures for each of
	the collection chunks of the given type encountered so far in the
	course of parsing this IFF file. The items appearing first in the
	list will be the ones encountered most recently.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	type - type code to search for.
	id - identifier code to search for.

   RESULT
	ci - pointer to last collection chunk encountered with
	     links to previous ones.

   SEE ALSO
	[CollectionChunk()](../Includes_and_Autodocs_3._guide/node035D.html), [CollectionChunks()](../Includes_and_Autodocs_3._guide/node035E.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


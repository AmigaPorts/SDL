# iffparse.library/FindLocalItem



   NAME
	FindLocalItem -- return a local context item from the context stack.
	                 (V36)

   SYNOPSIS
	lci = FindLocalItem(iff, type, id, ident);
	D0                  A0   D0    D1  D2

	struct [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103)	*FindLocalItem(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43)	*,
	                                       [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Searches the context stack of the given [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure for a
	local context item which matches the given ident, type and id. This
	function searches the context stack from the most current context
	backwards, so that the item found (if any) will be the one with
	greatest precedence in the context stack.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	type - type code to search for.
	id - ID code to search for.
	ident - ident code for the class of context item to search for
		(ex. "exhd" -- exit handler).

   RESULT
	lci - pointer to local context item, or NULL if nothing matched.

   SEE ALSO
	[StoreLocalItem()](../Includes_and_Autodocs_3._guide/node037E.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


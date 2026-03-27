# iffparse.library/FindPropContext



   NAME
	FindPropContext -- get the property context for the current state.
	                   (V36)

   SYNOPSIS
	cn = FindPropContext(iff);
	D0                   A0

	struct [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) *FindPropContext(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *);

   FUNCTION
	Locates the context node which would be the scoping chunk for
	properties in the current parsing state. (Huh?)  This is used for
	locating the proper scoping context for property chunks i.e. the
	scope from which a property would apply. This is usually the FORM
	or LIST with the highest precedence in the context stack.

	If you don't understand this, read the IFF spec a couple more times.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.

   RESULT
	cn - [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) of property scoping chunk.

   SEE ALSO
	[CurrentChunk()](../Includes_and_Autodocs_3._guide/node035F.html), [ParentChunk()](../Includes_and_Autodocs_3._guide/node0371.html), [StoreItemInContext()](../Includes_and_Autodocs_3._guide/node037D.html),
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


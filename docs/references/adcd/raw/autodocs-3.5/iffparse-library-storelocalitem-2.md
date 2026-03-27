# iffparse.library/StoreLocalItem



   NAME
	StoreLocalItem -- insert a local context item into the context stack.
	                  (V36)

   SYNOPSIS
	error = StoreLocalItem(iff, localItem, position);
	D0                     A0   A1         D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) StoreLocalItem(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, struct [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103)	*,
	                    LONG);

   FUNCTION
	Adds the local context item to the list of items for one of the
	context nodes on the context stack and purges any other item in the
	same context with the same ident, type and id. The position argument
	determines where in the stack to add the item:

	IFFSLI_ROOT:
		Add item to list at root (default) stack position.
	IFFSLI_TOP:
		Add item to the top (current) context node.
	IFFSLI_PROP:
		Add element in top property context. Top property context is
		either the top FORM chunk, or the top LIST chunk, whichever
		is closer to the top of the stack.

	Items added to the root context, or added to the top context before
	the [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) has been opened or after it has been closed, are put in
	the default context. That is, they will be the local items found
	only after all other context nodes have been searched. Items in the
	default context are also immune to being purged until the [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43)
	structure itself is deleted with [FreeIFF()](../Includes_and_Autodocs_3._guide/node0366.html). This means that handlers
	installed in the root context will still be there after an [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43)
	structure has been opened and closed. (Note that this implies that
	items stored in a higher context will be deleted when that context
	ends.)

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	localItem - pointer to [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) struct to insert.
	position - where to store the item (IFFSLI_ROOT, _TOP or _PROP).

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[FindLocalItem()](../Includes_and_Autodocs_3._guide/node0363.html), [StoreItemInContext()](../Includes_and_Autodocs_3._guide/node037D.html), [EntryHandler()](../Includes_and_Autodocs_3._guide/node0360.html), [ExitHandler()](../Includes_and_Autodocs_3._guide/node0361.html),
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


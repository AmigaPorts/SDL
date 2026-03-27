# iffparse.library/AllocLocalItem



   NAME
	AllocLocalItem -- create a local context item structure. (V36)

   SYNOPSIS
	item = AllocLocalItem(type, id, ident, dataSize);
	D0                    D0    D1  D2     D3

	struct [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) *AllocLocalItem(LONG, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Allocates and initializes a [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) structure with "dataSize"
	bytes of associated user data. This is the only supported way to
	create such an item. The user data can be accessed with the
	[LocalItemData()](../Includes_and_Autodocs_3._guide/node036E.html) function. An item created with this function
	automatically has its purge vectors set up correctly to dispose of
	itself and its associated user data area. Any additional cleanup
	should be done with a user-supplied purge vector.

   INPUTS
	type,id - additional longword identification values
	ident - longword identifier for class of context item
	dataSize - number of bytes of user data to allocate for this item

   RESULT
	item - pointer to initialized [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) or NULL if the
	       allocation failed.

   SEE ALSO
	[FreeLocalItem()](../Includes_and_Autodocs_3._guide/node0367.html), [LocalItemData()](../Includes_and_Autodocs_3._guide/node036E.html), [StoreLocalItem()](../Includes_and_Autodocs_3._guide/node037E.html),
	[StoreItemInContext()](../Includes_and_Autodocs_3._guide/node037D.html), [SetLocalItemPurge()](../Includes_and_Autodocs_3._guide/node0379.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


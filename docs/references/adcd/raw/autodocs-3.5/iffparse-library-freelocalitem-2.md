# iffparse.library/FreeLocalItem



   NAME
	FreeLocalItem -- deallocate a local context item structure. (V36)

   SYNOPSIS
	FreeLocalItem(localItem);
	              A0

	VOID FreeLocalItem(struct [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) *);

   FUNCTION
	Frees the memory for the local context item and any associated user
	memory as allocated with [AllocLocalItem()](../Includes_and_Autodocs_3._guide/node035A.html). User purge vectors should
	call this function after they have freed any other resources
	associated with this item.

	Note that FreeLocalItem() does NOT call the custom purge vector set
	up through SetLocalItemPurge(); all it does is free the local context
	item. (This implies that your custom purge vector would want to call
	this to ultimately free the LocalContextItem.)

   INPUTS
	localItem - pointer to [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) created with [AllocLocalItem](../Includes_and_Autodocs_3._guide/node035A.html).
	            Starting with V39, this may be NULL.

   SEE ALSO
	[AllocLocalItem()](../Includes_and_Autodocs_3._guide/node035A.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


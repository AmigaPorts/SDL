# iffparse.library/LocalItemData



   NAME
	LocalItemData -- get pointer to user data for local context item. (V36)

   SYNOPSIS
	data = LocalItemData(localItem);
	D0                   A0

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) LocalItemData(struct [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) *);

   FUNCTION
	Returns pointer to the user data associated with the given local
	context item. The size of the data area depends on the "dataSize"
	argument used when allocating this item. If the pointer to the item
	given (localItem) is NULL, this function returns NULL.

   INPUTS
	localItem - pointer to local context item or NULL.

   RESULT
	data - pointer to user data area or NULL if localItem is NULL.

   BUGS
	Currently, there is no way to determine the size of the user data
	area; you have to 'know'.

   SEE ALSO
	[AllocLocalItem()](../Includes_and_Autodocs_3._guide/node035A.html), [FreeLocalItem()](../Includes_and_Autodocs_3._guide/node0367.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


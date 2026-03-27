# utility.library/FreeTagItems



   NAME
	FreeTagItems -- free an allocated tag list. (V36)

   SYNOPSIS
	FreeTagItems(tagList);
		     A0

	VOID FreeTagItems(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	Frees the memory of a [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) list allocated either by
	[AllocateTagItems()](../Includes_and_Autodocs_3._guide/node0594.html) or [CloneTagItems()](../Includes_and_Autodocs_3._guide/node059B.html).

   INPUTS
	tagList - list to free, must have been obtained from
		  [AllocateTagItems()](../Includes_and_Autodocs_3._guide/node0594.html) or [CloneTagItems()](../Includes_and_Autodocs_3._guide/node059B.html) (may be NULL)

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [AllocateTagItems()](../Includes_and_Autodocs_3._guide/node0594.html), [CloneTagItems()](../Includes_and_Autodocs_3._guide/node059B.html)


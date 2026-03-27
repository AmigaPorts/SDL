# utility.library/AllocateTagItems



   NAME
	AllocateTagItems -- allocate a tag list. (V36)

   SYNOPSIS
	tagList = AllocateTagItems(numTags);
	D0		           D0

	struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *AllocateTagItems(ULONG);

   FUNCTION
	Allocates the specified number of usable TagItems slots.

	Note that to access the TagItems in 'tagList', you should use
	the function [NextTagItem()](../Includes_and_Autodocs_3._guide/node05A7.html). This will insure you respect any
	chaining (TAG_MORE) and secret hiding places (TAG_IGNORE) that
	this function might generate.

   INPUTS
	numTags - the number of [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) slots you want to allocate.

   RESULTS
	tagList	- the allocated chain of [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) structures, or NULL if
	          there was not enough memory. An allocated tag list must
	          eventually be freed using [FreeTagItems()](../Includes_and_Autodocs_3._guide/node05A2.html).

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [FreeTagItems()](../Includes_and_Autodocs_3._guide/node05A2.html), [CloneTagItems()](../Includes_and_Autodocs_3._guide/node059B.html)


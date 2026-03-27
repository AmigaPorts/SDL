# utility.library/FindTagItem



   NAME
	FindTagItem -- scan a tag list for a specific tag. (V36)

   SYNOPSIS
	tag = FindTagItem(tagValue,tagList);
	D0		  D0	   A0

	struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *FindTagItem(Tag,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	Scans a tag list and returns a pointer to the first item with
	ti_Tag matching the 'tagValue' parameter.

   INPUTS
	tagValue - tag value to search for
	tagList	- tag item list to search (may be NULL)

   RESULTS
	tag - a pointer to the item with ti_Tag matching 'tagValue' or NULL
	      if no match was found.

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [GetTagData()](../Includes_and_Autodocs_3._guide/node05A3.html), [PackBoolTags()](../Includes_and_Autodocs_3._guide/node05A8.html), [NextTagItem()](../Includes_and_Autodocs_3._guide/node05A7.html)


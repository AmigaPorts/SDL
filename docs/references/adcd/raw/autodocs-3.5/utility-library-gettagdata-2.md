# utility.library/GetTagData



   NAME
	GetTagData -- obtain the data corresponding to a tag. (V36)

   SYNOPSIS
	value = GetTagData(tagValue,defaultVal,tagList);
	D0		   D0	    D1	       A0

	ULONG GetTagData(Tag,ULONG,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	Searches a tag list for a matching tag, and returns the
	corresponding ti_Data value for the [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) found. If no match is
	found, this function returns the value passed in as 'default'.

   INPUTS
	tagValue - tag value to search for.
	defaultVal - value to be returned if tagValue is not found.
	tagList - the tag list to search.

   RESULTS
	value - the ti_Data value for the first matching [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31), or 'default'
		if a ti_Tag matching 'Tag' is not found.

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [FindTagItem()](../Includes_and_Autodocs_3._guide/node05A0.html), [PackBoolTags()](../Includes_and_Autodocs_3._guide/node05A8.html), [NextTagItem()](../Includes_and_Autodocs_3._guide/node05A7.html)


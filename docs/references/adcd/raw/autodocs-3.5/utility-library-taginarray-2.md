# utility.library/TagInArray



   NAME
	TagInArray -- check if a tag value appears in an array of tag values.
		      (V36)

   SYNOPSIS
	result = TagInArray(tagValue,tagArray);
	D0	            D0	     A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) TagInArray(Tag,[Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) *);

   FUNCTION
	Performs a quick scan to see if a tag value appears in an array
	terminated with TAG_DONE. Returns TRUE if the value is found.

	The 'tagArray' must be terminated by TAG_DONE. Note that this is an
	array of tag values, NOT an array of TagItems.

   INPUTS
	tagValue - tag value to search array for in array.
	tagArray - a simple array of tag values terminated by TAG_DONE.

   RESULTS
	result - TRUE if tagValue was found in tagArray.

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [FilterTagItems()](../Includes_and_Autodocs_3._guide/node059E.html)


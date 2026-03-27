# utility.library/FilterTagItems



   NAME
	FilterTagItems -- remove selected items from a tag list. (V36)

   SYNOPSIS
	numValid = FilterTagItems(tagList,filterArray,logic);
	D0		          A0	  A1	      D0

	ULONG FilterTagItems(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *,[Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) *,ULONG);

   FUNCTION
	Removes tag items from a tag list (by changing ti_Tag to
	TAG_IGNORE) depending on whether its ti_Tag value is
	found in an array of tag values.

	If the 'logic' parameter is TAGFILTER_AND, then all items
	not appearing in 'tagArray' are excluded from 'tagList'.

	If 'logic' is TAGFILTER_NOT, then items not found in 'tagArray'
	are preserved, and the ones in the array are cast out.

   INPUTS
	tagList	- input list of tag items which is to be filtered by having
		  selected items changed to TAG_IGNORE.
	filterArray - an array of tag values, terminated by TAG_DONE, as
		      specified in the documentation for [TagInArray()](../Includes_and_Autodocs_3._guide/node05B2.html).
	logic - specification whether items in 'tagArray' are to be included
		or excluded in the filtered result.

   RESULTS
	numValid - number of valid items left in resulting filtered list.

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [TagInArray()](../Includes_and_Autodocs_3._guide/node05B2.html)


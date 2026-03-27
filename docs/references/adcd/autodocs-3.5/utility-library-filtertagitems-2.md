---
title: utility.library/FilterTagItems
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-filtertagitems-2
functions: [TagInArray]
libraries: [utility.library]
---

# utility.library/FilterTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FilterTagItems -- remove selected items from a tag list. (V36)

   SYNOPSIS
	numValid = FilterTagItems(tagList,filterArray,logic);
	D0		          A0	  A1	      D0

	ULONG FilterTagItems(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *,[Tag](autodocs-3.5/include-utility-tagitem-h.md) *,ULONG);

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
		      specified in the documentation for [TagInArray()](autodocs-3.5/utility-library-taginarray-2.md).
	logic - specification whether items in 'tagArray' are to be included
		or excluded in the filtered result.

   RESULTS
	numValid - number of valid items left in resulting filtered list.

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [TagInArray()](autodocs-3.5/utility-library-taginarray-2.md)

---

## See Also

- [TagInArray — utility.library](../autodocs/utility.library.md#taginarray)

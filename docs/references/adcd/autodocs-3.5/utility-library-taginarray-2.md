---
title: utility.library/TagInArray
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-taginarray-2
functions: [FilterTagItems]
libraries: [utility.library]
---

# utility.library/TagInArray

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TagInArray -- check if a tag value appears in an array of tag values.
		      (V36)

   SYNOPSIS
	result = TagInArray(tagValue,tagArray);
	D0	            D0	     A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) TagInArray(Tag,[Tag](autodocs-3.5/include-utility-tagitem-h.md) *);

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
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [FilterTagItems()](autodocs-3.5/utility-library-filtertagitems-2.md)

---

## See Also

- [FilterTagItems — utility.library](../autodocs/utility.library.md#filtertagitems)

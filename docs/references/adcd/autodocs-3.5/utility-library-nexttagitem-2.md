---
title: utility.library/NextTagItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-nexttagitem-2
functions: [FindTagItem, GetTagData, NextTagItem, PackBoolTags]
libraries: [utility.library]
---

# utility.library/NextTagItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NextTagItem -- iterate through a tag list. (V36)

   SYNOPSIS
	tag = NextTagItem(tagItemPtr);
	D0		  A0

	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *NextTagItem(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) **);

   FUNCTION
	Iterates through a tag list, skipping and chaining as dictated by
	system tags. TAG_SKIP will cause it to skip the entry and a number
	of following tags as specified in ti_Data. TAG_IGNORE ignores that
	single entry, and TAG_MORE has a pointer to another array of tags (and
	terminates the current array!). TAG_DONE also terminates the current
	array. Each call returns either the next tagitem you should examine,
	or NULL when the end of the list has been reached.

   INPUTS
	tagItemPtr - doubly-indirect reference to a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) structure.
		     The pointer will be changed to keep track of the
		     iteration.

   RESULTS
	nextTag	- each [TagItem](autodocs-3.5/include-utility-tagitem-h.md) in the array or chain of arrays that should be
		  processed according to system tag values defined in
		  [<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md)) is returned in turn with successive
		  calls.

   EXAMPLE
	Iterate(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);
	{
	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tstate;
	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tag;

	    tstate = tags;
	    while (tag = NextTagItem(&tstate))
	    {
		switch (tag->ti_Tag)
		{
 		    case TAG1: ...
			       break;

 		    case TAG2: ...
			       break;

		    ...
		}
	    }
   	}

   WARNING
	Do NOT use the value of *tagItemPtr, but rather use the pointer
	returned by NextTagItem().

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [GetTagData()](autodocs-3.5/utility-library-gettagdata-2.md), [PackBoolTags()](autodocs-3.5/utility-library-packbooltags-2.md), [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md)

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)

---
title: utility.library/FindTagItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-findtagitem-2
functions: [GetTagData, NextTagItem, PackBoolTags]
libraries: [utility.library]
---

# utility.library/FindTagItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindTagItem -- scan a tag list for a specific tag. (V36)

   SYNOPSIS
	tag = FindTagItem(tagValue,tagList);
	D0		  D0	   A0

	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *FindTagItem(Tag,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

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
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [GetTagData()](autodocs-3.5/utility-library-gettagdata-2.md), [PackBoolTags()](autodocs-3.5/utility-library-packbooltags-2.md), [NextTagItem()](autodocs-3.5/utility-library-nexttagitem-2.md)

---

## See Also

- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)

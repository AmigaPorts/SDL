---
title: utility.library/GetTagData
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-gettagdata-2
functions: [FindTagItem, NextTagItem, PackBoolTags]
libraries: [utility.library]
---

# utility.library/GetTagData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetTagData -- obtain the data corresponding to a tag. (V36)

   SYNOPSIS
	value = GetTagData(tagValue,defaultVal,tagList);
	D0		   D0	    D1	       A0

	ULONG GetTagData(Tag,ULONG,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	Searches a tag list for a matching tag, and returns the
	corresponding ti_Data value for the [TagItem](autodocs-3.5/include-utility-tagitem-h.md) found. If no match is
	found, this function returns the value passed in as 'default'.

   INPUTS
	tagValue - tag value to search for.
	defaultVal - value to be returned if tagValue is not found.
	tagList - the tag list to search.

   RESULTS
	value - the ti_Data value for the first matching [TagItem](autodocs-3.5/include-utility-tagitem-h.md), or 'default'
		if a ti_Tag matching 'Tag' is not found.

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md), [PackBoolTags()](autodocs-3.5/utility-library-packbooltags-2.md), [NextTagItem()](autodocs-3.5/utility-library-nexttagitem-2.md)

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)

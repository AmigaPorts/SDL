---
title: utility.library/AllocateTagItems
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-allocatetagitems-2
functions: [CloneTagItems, FreeTagItems, NextTagItem]
libraries: [utility.library]
---

# utility.library/AllocateTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocateTagItems -- allocate a tag list. (V36)

   SYNOPSIS
	tagList = AllocateTagItems(numTags);
	D0		           D0

	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *AllocateTagItems(ULONG);

   FUNCTION
	Allocates the specified number of usable TagItems slots.

	Note that to access the TagItems in 'tagList', you should use
	the function [NextTagItem()](autodocs-3.5/utility-library-nexttagitem-2.md). This will insure you respect any
	chaining (TAG_MORE) and secret hiding places (TAG_IGNORE) that
	this function might generate.

   INPUTS
	numTags - the number of [TagItem](autodocs-3.5/include-utility-tagitem-h.md) slots you want to allocate.

   RESULTS
	tagList	- the allocated chain of [TagItem](autodocs-3.5/include-utility-tagitem-h.md) structures, or NULL if
	          there was not enough memory. An allocated tag list must
	          eventually be freed using [FreeTagItems()](autodocs-3.5/utility-library-freetagitems-2.md).

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [FreeTagItems()](autodocs-3.5/utility-library-freetagitems-2.md), [CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md)

---

## See Also

- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)

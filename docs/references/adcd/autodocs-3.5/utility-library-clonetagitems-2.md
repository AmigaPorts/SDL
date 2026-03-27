---
title: utility.library/CloneTagItems
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-clonetagitems-2
functions: [AllocateTagItems, FindTagItem, FreeTagItems, RefreshTagItemClones]
libraries: [utility.library]
---

# utility.library/CloneTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloneTagItems -- copy a tag list. (V36)

   SYNOPSIS
	clone = CloneTagItems(original);
	D0		      A0

	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *CloneTagItems(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	Copies the essential contents of a tag list into a new tag list.

	The cloning is such that calling [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md) with a given tag on
	the original or cloned tag lists will always return the same
	tag value. That is, the ordering of the tags is maintained.

   INPUTS
	original - tag list to clone. May be NULL, in which case an
		   empty tag list is returned.

   RESULTS
	clone - copy of the original tag list, or NULL if there was not enough
		memory. This tag list must eventually by freed by calling
		[FreeTagItems()](autodocs-3.5/utility-library-freetagitems-2.md).

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [AllocateTagItems()](autodocs-3.5/utility-library-allocatetagitems-2.md), [FreeTagItems()](autodocs-3.5/utility-library-freetagitems-2.md),
	[RefreshTagItemClones()](autodocs-3.5/utility-library-refreshtagitemclones-2.md)

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)
- [RefreshTagItemClones — utility.library](../autodocs/utility.library.md#refreshtagitemclones)

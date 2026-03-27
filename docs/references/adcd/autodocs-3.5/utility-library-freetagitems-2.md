---
title: utility.library/FreeTagItems
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-freetagitems-2
functions: [AllocateTagItems, CloneTagItems]
libraries: [utility.library]
---

# utility.library/FreeTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeTagItems -- free an allocated tag list. (V36)

   SYNOPSIS
	FreeTagItems(tagList);
		     A0

	VOID FreeTagItems(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	Frees the memory of a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) list allocated either by
	[AllocateTagItems()](autodocs-3.5/utility-library-allocatetagitems-2.md) or [CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md).

   INPUTS
	tagList - list to free, must have been obtained from
		  [AllocateTagItems()](autodocs-3.5/utility-library-allocatetagitems-2.md) or [CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md) (may be NULL)

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [AllocateTagItems()](autodocs-3.5/utility-library-allocatetagitems-2.md), [CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md)

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)

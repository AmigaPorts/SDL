---
title: utility.library/RefreshTagItemClones
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-refreshtagitemclones-2
functions: [AllocateTagItems, ApplyTagChanges, CloneTagItems, FreeTagItems]
libraries: [utility.library]
---

# utility.library/RefreshTagItemClones

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RefreshTagItemClones -- rejuvenate a clone from the original. (V36)

   SYNOPSIS
	RefreshTagItemClones(clone,original)
			     A0	   A1

	VOID RefreshTagItemClones(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	If (and only if) the tag list 'clone' was created from 'original' by
	[CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md), and if 'original' has not been changed in any way,
	you can reset the clone list to its original state by using this
	function.

   INPUTS
	clone - return value from CloneTagItems(original)
	original - a tag list that hasn't changed since [CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md)

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md), [AllocateTagItems()](autodocs-3.5/utility-library-allocatetagitems-2.md),
	[FreeTagItems()](autodocs-3.5/utility-library-freetagitems-2.md), [ApplyTagChanges()](autodocs-3.5/utility-library-applytagchanges.md)

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [ApplyTagChanges — utility.library](../autodocs/utility.library.md#applytagchanges)
- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)

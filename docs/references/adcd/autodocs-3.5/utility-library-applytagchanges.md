---
title: utility.library/ApplyTagChanges
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-applytagchanges
functions: [FilterTagChanges]
libraries: [utility.library]
---

# utility.library/ApplyTagChanges

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ApplyTagChanges -- change a tag list based on a second tag list. (V39)

   SYNOPSIS
	ApplyTagChanges(list,changeList);
			A0   A1

	VOID ApplyTagChanges(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	For any tag that appears in both 'list' and 'changeList', this
	function will change the ti_Data field of the tag in 'list' to
	match the ti_Data field of the tag in 'changeList'. In effect,
	'changeList' contains a series of new values for tags already in
	'list'. Any tag in 'changeList' that is not in 'list' is ignored.

   INPUTS
	list - a list of existing tags (may be NULL)
	changeList - a list of tags to modify 'list' with (may be NULL)

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [FilterTagChanges()](autodocs-3.5/utility-library-filtertagchanges-2.md)

---

## See Also

- [FilterTagChanges — utility.library](../autodocs/utility.library.md#filtertagchanges)

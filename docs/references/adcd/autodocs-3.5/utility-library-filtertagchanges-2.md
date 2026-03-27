---
title: utility.library/FilterTagChanges
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-filtertagchanges-2
functions: [ApplyTagChanges, FilterTagChanges]
libraries: [utility.library]
---

# utility.library/FilterTagChanges

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FilterTagChanges -- eliminate tags which specify no change. (V36)

   SYNOPSIS
	FilterTagChanges(changeList,originalList,apply);
			 A0	    A1           D0

	VOID FilterTagChanges(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *, ULONG);

   FUNCTION
	This function goes through changeList. For each item found in
	changeList, if the item is also present in originalList, and their
	data values are identical, then the tag is removed from changeList.
	If the two tag's data values are different and the 'apply' value is
	non-zero, then the tag data in originalList will be updated to match
	the value from changeList.

   INPUTS
	changeList - list of new tags (may be NULL)
	originalList - a list of existing tags (may be NULL)
	apply - boolean specification as to whether the data values in
		originalList are to be updated to the data values in
		changeList.

   EXAMPLE
	Assume you have an attribute list for an object (originalList)
	which looks like this:

		{ATTR_Size,  "large"},
		{ATTR_Color, "orange"},
		{ATTR_Shape, "square"}

	If you receive a new tag list containing some changes (changeList),
	which looks like this:

		{ATTR_Size,  "large"},
		{ATTR_Shape, "triangle"}

	If you call FilterTagChanges(), changeList will be modified to
	contain only those attributes which are different from those
	in originalList. All other items will have their tag values set to
	TAG_IGNORE. The resulting changeList will become:

		{TAG_IGNORE, "large"},
		{ATTR_Shape, "triangle"}

	If 'apply' was set to 0, originalList would be unchanged. If 'apply'
	was non-zero, originalList would be changed to:

		{ATTR_Size,  "large"},
		{ATTR_Color, "orange"},
		{ATTR_Shape, "triangle"}

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [ApplyTagChanges()](autodocs-3.5/utility-library-applytagchanges.md)

---

## See Also

- [ApplyTagChanges — utility.library](../autodocs/utility.library.md#applytagchanges)
- [FilterTagChanges — utility.library](../autodocs/utility.library.md#filtertagchanges)

---
title: utility.library/PackBoolTags
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-packbooltags-2
functions: [FindTagItem, GetTagData, NextTagItem]
libraries: [utility.library]
---

# utility.library/PackBoolTags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PackBoolTags -- builds a "flag" word from a tag list. (V36)

   SYNOPSIS
	flags = PackBoolTags(initialFlags,tagList,boolMap);
	D0		     D0		  A0      A1

	ULONG PackBoolTags(ULONG,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	Picks out the boolean tag items in a tag list and converts
	them into bit-flag representations according to a correspondence
	defined by the tag list 'boolMap'.

	A boolean tag item is one where only the logical value of
	the ti_Data is relevant. If this field is 0, the value is
	FALSE, otherwise TRUE.

   INPUTS
	initialFlags - a starting set of bit-flags which will be changed
		       by the processing of TRUE and FALSE boolean tags
		       in tagList.
	tagList	- a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) list which may contain several tag items defined to
		  be boolean by their presence in boolMap. The logical value of
		  ti_Data determines whether a tag item causes the bit-flag
		  value related by boolMap to be set or cleared in the returned
		  flag longword.
	boolMap	- a tag list defining the boolean tags to be recognized, and
		  the bit (or bits) in the returned longword that are to be set
		  or cleared when a boolean [Tag](autodocs-3.5/include-utility-tagitem-h.md) is found to be TRUE or FALSE in
		  tagList.

   RESULTS
	flags - the accumulated longword of bit-flags, starting with
		initialFlags and modified by each boolean tag item
		encountered.

   EXAMPLE
	/* define some nice user tag values ... */
	enum mytags { tag1 = TAG_USER+1, tag2, tag3, tag4, tag5 };

	/* this [TagItem](autodocs-3.5/include-utility-tagitem-h.md) list defines the correspondence between boolean tags
	 * and bit-flag values.
	 */
	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) boolMap[] =
	{
	    {tag1,     0x0001},
	    {tag2,     0x0002},
	    {tag3,     0x0004},
	    {tag4,     0x0008},
	    {TAG_DONE, }
	};

	/* You are probably passed these by some client, and you want
	 * to "collapse" the boolean content into a single longword.
	 */

	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) boolExample[] =
	{
	    {tag1,     TRUE},
	    {tag2,     FALSE},
	    {tag5,     Irrelevant},
	    {tag3,     TRUE},
	    {TAG_DONE, }
	};

	/* Perhaps 'boolFlags' already has a current value of 0x800002. */
	boolFlags = PackBoolTags(boolFlags,boolExample,boolMap);

	/* The resulting new value of 'boolFlags' will be 0x80005. /*

   WARNING
	In a case where there is duplication of a tag in tagList, the
	last of the identical tags will hold sway.

   SEE ALSO
	[<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md), [GetTagData()](autodocs-3.5/utility-library-gettagdata-2.md), [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md), [NextTagItem()](autodocs-3.5/utility-library-nexttagitem-2.md)

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)

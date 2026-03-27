---
title: utility.library/UnpackStructureTags
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-unpackstructuretags
functions: [FindTagItem, PackStructureTags]
libraries: [utility.library]
---

# utility.library/UnpackStructureTags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UnpackStructureTags -- unpack a structure to values in taglist. (V39)

   SYNOPSIS
	num = UnpackStructureTags(pack,packTable,tagList);
	D0                        A0   A1        A2

	ULONG UnpackStructureTags(APTR,ULONG *,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	For each table entry, a [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md) will be done and if the
	matching tag is found in the taglist, the data in the structure
	will be placed into the memory pointed to by the tag's ti_Data.
	ti_Data *must* point to a LONGWORD.

   INPUTS
	pack - a pointer to the data area to be unpacked
	packTable - a pointer to the packing information table.
		    See [<utility/pack.h>](autodocs-3.5/include-utility-pack-h.md) for definition and macros
	tagList - a pointer to the taglist to unpack into

   RESULTS
	num - the number of tag items unpacked

   SEE ALSO
	[<utility/pack.h>](autodocs-3.5/include-utility-pack-h.md), [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md), [PackStructureTags()](autodocs-3.5/utility-library-packstructuretags.md)

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [PackStructureTags — utility.library](../autodocs/utility.library.md#packstructuretags)

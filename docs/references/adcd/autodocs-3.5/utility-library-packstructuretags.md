---
title: utility.library/PackStructureTags
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-packstructuretags
functions: [FindTagItem, UnpackStructureTags]
libraries: [utility.library]
---

# utility.library/PackStructureTags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PackStructureTags -- pack a structure with values from taglist. (V39)

   SYNOPSIS
	num = PackStructureTags(pack,packTable,tagList);
	D0                      A0   A1        A2

	ULONG PackStructureTags(APTR,ULONG *,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	For each table entry, a [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md) will be done and if the
	matching tag is found in the taglist, the data field will be
	packed into the given structure based on the packtable
	definition.

   INPUTS
	pack - a pointer to the data area to fill in.
	packTable - a pointer to the packing information table.
		    See [<utility/pack.h>](autodocs-3.5/include-utility-pack-h.md) for definition and macros.
	tagList - a pointer to the taglist to pack into the structure

   RESULTS
	num - the number of tag items packed

   SEE ALSO
	[<utility/pack.h>](autodocs-3.5/include-utility-pack-h.md), [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md), [UnpackStructureTags()](autodocs-3.5/utility-library-unpackstructuretags.md)

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [UnpackStructureTags — utility.library](../autodocs/utility.library.md#unpackstructuretags)

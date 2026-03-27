---
title: iffparse.library/AllocLocalItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-alloclocalitem-2
functions: [FreeLocalItem, LocalItemData, SetLocalItemPurge, StoreItemInContext, StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/AllocLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocLocalItem -- create a local context item structure. (V36)

   SYNOPSIS
	item = AllocLocalItem(type, id, ident, dataSize);
	D0                    D0    D1  D2     D3

	struct [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) *AllocLocalItem(LONG, [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Allocates and initializes a [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) structure with "dataSize"
	bytes of associated user data. This is the only supported way to
	create such an item. The user data can be accessed with the
	[LocalItemData()](autodocs-3.5/iffparse-library-localitemdata-2.md) function. An item created with this function
	automatically has its purge vectors set up correctly to dispose of
	itself and its associated user data area. Any additional cleanup
	should be done with a user-supplied purge vector.

   INPUTS
	type,id - additional longword identification values
	ident - longword identifier for class of context item
	dataSize - number of bytes of user data to allocate for this item

   RESULT
	item - pointer to initialized [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) or NULL if the
	       allocation failed.

   SEE ALSO
	[FreeLocalItem()](autodocs-3.5/iffparse-library-freelocalitem-2.md), [LocalItemData()](autodocs-3.5/iffparse-library-localitemdata-2.md), [StoreLocalItem()](autodocs-3.5/iffparse-library-storelocalitem-2.md),
	[StoreItemInContext()](autodocs-3.5/iffparse-library-storeitemincontext-2.md), [SetLocalItemPurge()](autodocs-3.5/iffparse-library-setlocalitempurge-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)
- [LocalItemData — iffparse.library](../autodocs/iffparse.library.md#localitemdata)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)

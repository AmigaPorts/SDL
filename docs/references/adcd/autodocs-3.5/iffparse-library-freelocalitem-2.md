---
title: iffparse.library/FreeLocalItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-freelocalitem-2
functions: [AllocLocalItem, FreeLocalItem, SetLocalItemPurge]
libraries: [iffparse.library]
---

# iffparse.library/FreeLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeLocalItem -- deallocate a local context item structure. (V36)

   SYNOPSIS
	FreeLocalItem(localItem);
	              A0

	VOID FreeLocalItem(struct [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Frees the memory for the local context item and any associated user
	memory as allocated with [AllocLocalItem()](autodocs-3.5/iffparse-library-alloclocalitem-2.md). User purge vectors should
	call this function after they have freed any other resources
	associated with this item.

	Note that FreeLocalItem() does NOT call the custom purge vector set
	up through SetLocalItemPurge(); all it does is free the local context
	item. (This implies that your custom purge vector would want to call
	this to ultimately free the LocalContextItem.)

   INPUTS
	localItem - pointer to [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) created with [AllocLocalItem](autodocs-3.5/iffparse-library-alloclocalitem-2.md).
	            Starting with V39, this may be NULL.

   SEE ALSO
	[AllocLocalItem()](autodocs-3.5/iffparse-library-alloclocalitem-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)

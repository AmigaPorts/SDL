---
title: iffparse.library/SetLocalItemPurge
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-setlocalitempurge-2
functions: [AllocLocalItem, FreeLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/SetLocalItemPurge

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetLocalItemPurge -- set purge vector for a local context item. (V36)

   SYNOPSIS
	SetLocalItemPurge(localItem, purgeHook);
	                  A0         A1

	VOID SetLocalItemPurge(struct [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) *, struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *);

   FUNCTION
	Sets a local context item to use a client-supplied cleanup (purge)
	vector for disposal when its context is popped. The purge vector
	will be called when the [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) containing this local item is
	popped off the context stack and is about to be deleted itself. If
	the purge vector has not been set, the parser will use [FreeLocalItem()](autodocs-3.5/iffparse-library-freelocalitem-2.md)
	to delete the item, but if this function is used to set the purge
	vector, the supplied vector will be called with the following
	arguments:

		A0:	pointer to purgeHook.
		A2:	pointer to [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) to be freed.
		A1:	pointer to a [LONG](autodocs-3.5/include-exec-types-h.md) containing the value
			IFFCMD_PURGELCI.

	The user purge vector is then responsible for calling [FreeLocalItem()](autodocs-3.5/iffparse-library-freelocalitem-2.md)
	as part of its own cleanup. Although the purge vector can return a
	value, it will be ignored -- purge vectors must always work (best to
	return 0, though).

   INPUTS
	localItem - pointer to a local context item.
	purgeHook - pointer to a [Hook](autodocs-3.5/include-utility-hooks-h.md) structure.

   SEE ALSO
	[AllocLocalItem()](autodocs-3.5/iffparse-library-alloclocalitem-2.md), [FreeLocalItem()](autodocs-3.5/iffparse-library-freelocalitem-2.md), [<utility/hooks.h>](autodocs-3.5/include-utility-hooks-h.md)
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)

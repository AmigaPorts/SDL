---
title: iffparse.library/LocalItemData
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-localitemdata-2
functions: [AllocLocalItem, FreeLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/LocalItemData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LocalItemData -- get pointer to user data for local context item. (V36)

   SYNOPSIS
	data = LocalItemData(localItem);
	D0                   A0

	[APTR](autodocs-3.5/include-exec-types-h.md) LocalItemData(struct [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Returns pointer to the user data associated with the given local
	context item. The size of the data area depends on the "dataSize"
	argument used when allocating this item. If the pointer to the item
	given (localItem) is NULL, this function returns NULL.

   INPUTS
	localItem - pointer to local context item or NULL.

   RESULT
	data - pointer to user data area or NULL if localItem is NULL.

   BUGS
	Currently, there is no way to determine the size of the user data
	area; you have to 'know'.

   SEE ALSO
	[AllocLocalItem()](autodocs-3.5/iffparse-library-alloclocalitem-2.md), [FreeLocalItem()](autodocs-3.5/iffparse-library-freelocalitem-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)

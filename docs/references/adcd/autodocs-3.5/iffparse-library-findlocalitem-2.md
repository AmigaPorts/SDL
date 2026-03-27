---
title: iffparse.library/FindLocalItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-findlocalitem-2
functions: [StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/FindLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindLocalItem -- return a local context item from the context stack.
	                 (V36)

   SYNOPSIS
	lci = FindLocalItem(iff, type, id, ident);
	D0                  A0   D0    D1  D2

	struct [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md)	*FindLocalItem(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md)	*,
	                                       [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Searches the context stack of the given [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure for a
	local context item which matches the given ident, type and id. This
	function searches the context stack from the most current context
	backwards, so that the item found (if any) will be the one with
	greatest precedence in the context stack.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	type - type code to search for.
	id - ID code to search for.
	ident - ident code for the class of context item to search for
		(ex. "exhd" -- exit handler).

   RESULT
	lci - pointer to local context item, or NULL if nothing matched.

   SEE ALSO
	[StoreLocalItem()](autodocs-3.5/iffparse-library-storelocalitem-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)

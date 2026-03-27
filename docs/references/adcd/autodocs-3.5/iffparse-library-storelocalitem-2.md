---
title: iffparse.library/StoreLocalItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-storelocalitem-2
functions: [EntryHandler, ExitHandler, FindLocalItem, FreeIFF, StoreItemInContext]
libraries: [iffparse.library]
---

# iffparse.library/StoreLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StoreLocalItem -- insert a local context item into the context stack.
	                  (V36)

   SYNOPSIS
	error = StoreLocalItem(iff, localItem, position);
	D0                     A0   A1         D0

	[LONG](autodocs-3.5/include-exec-types-h.md) StoreLocalItem(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, struct [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md)	*,
	                    LONG);

   FUNCTION
	Adds the local context item to the list of items for one of the
	context nodes on the context stack and purges any other item in the
	same context with the same ident, type and id. The position argument
	determines where in the stack to add the item:

	IFFSLI_ROOT:
		Add item to list at root (default) stack position.
	IFFSLI_TOP:
		Add item to the top (current) context node.
	IFFSLI_PROP:
		Add element in top property context. Top property context is
		either the top FORM chunk, or the top LIST chunk, whichever
		is closer to the top of the stack.

	Items added to the root context, or added to the top context before
	the [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) has been opened or after it has been closed, are put in
	the default context. That is, they will be the local items found
	only after all other context nodes have been searched. Items in the
	default context are also immune to being purged until the [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md)
	structure itself is deleted with [FreeIFF()](autodocs-3.5/iffparse-library-freeiff-2.md). This means that handlers
	installed in the root context will still be there after an [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md)
	structure has been opened and closed. (Note that this implies that
	items stored in a higher context will be deleted when that context
	ends.)

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	localItem - pointer to [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) struct to insert.
	position - where to store the item (IFFSLI_ROOT, _TOP or _PROP).

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[FindLocalItem()](autodocs-3.5/iffparse-library-findlocalitem-2.md), [StoreItemInContext()](autodocs-3.5/iffparse-library-storeitemincontext-2.md), [EntryHandler()](autodocs-3.5/iffparse-library-entryhandler-2.md), [ExitHandler()](autodocs-3.5/iffparse-library-exithandler-2.md),
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [FindLocalItem — iffparse.library](../autodocs/iffparse.library.md#findlocalitem)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)

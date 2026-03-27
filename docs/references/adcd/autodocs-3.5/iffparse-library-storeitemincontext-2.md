---
title: iffparse.library/StoreItemInContext
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-storeitemincontext-2
functions: [StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/StoreItemInContext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StoreItemInContext -- store local context item in given context node.
	                      (V36)

   SYNOPSIS
	StoreItemInContext(iff, localItem, contextNode);
	                   A0   A1         A2

	VOID StoreItemInContext(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, struct [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) *,

```c
                               struct [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) *);
```
   FUNCTION
	Adds the [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) to the list of items for the given context
	node. If an LCI with the same Type, ID, and Ident is already
	present in the [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md), it will be purged and replaced with the
	new one. This is a raw form of [StoreLocalItem()](autodocs-3.5/iffparse-library-storelocalitem-2.md).

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure for this context.
	localItem - pointer to a [LocalContextItem](autodocs-3.5/include-libraries-iffparse-h.md) to be stored.
	contextNode - pointer to context node in which to store item.

   SEE ALSO
	[StoreLocalItem()](autodocs-3.5/iffparse-library-storelocalitem-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)

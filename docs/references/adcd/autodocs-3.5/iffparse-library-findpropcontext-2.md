---
title: iffparse.library/FindPropContext
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-findpropcontext-2
functions: [CurrentChunk, ParentChunk, StoreItemInContext]
libraries: [iffparse.library]
---

# iffparse.library/FindPropContext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindPropContext -- get the property context for the current state.
	                   (V36)

   SYNOPSIS
	cn = FindPropContext(iff);
	D0                   A0

	struct [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) *FindPropContext(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Locates the context node which would be the scoping chunk for
	properties in the current parsing state. (Huh?)  This is used for
	locating the proper scoping context for property chunks i.e. the
	scope from which a property would apply. This is usually the FORM
	or LIST with the highest precedence in the context stack.

	If you don't understand this, read the IFF spec a couple more times.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.

   RESULT
	cn - [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) of property scoping chunk.

   SEE ALSO
	[CurrentChunk()](autodocs-3.5/iffparse-library-currentchunk-2.md), [ParentChunk()](autodocs-3.5/iffparse-library-parentchunk-2.md), [StoreItemInContext()](autodocs-3.5/iffparse-library-storeitemincontext-2.md),
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)

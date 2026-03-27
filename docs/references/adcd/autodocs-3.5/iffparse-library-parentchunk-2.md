---
title: iffparse.library/ParentChunk
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-parentchunk-2
functions: [CurrentChunk]
libraries: [iffparse.library]
---

# iffparse.library/ParentChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ParentChunk -- get the nesting context node for the given chunk. (V36)

   SYNOPSIS
	parent = ParentChunk(contextNode);
	D0                   A0

	struct [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) *ParentChunk(struct [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Returns a context node for the chunk containing the chunk for the
	given context node. This function effectively moves down the context
	stack into previously pushed contexts. For example, to get a
	[ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) pointer for the enclosing FORM chunk while reading a data
	chunk, use: ParentChunk(CurrentChunk(iff)) to find this pointer.
	The [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) structure contains information on the type of chunk
	and its size.

   INPUTS
	contextNode - pointer to a context node.

   RESULT
	parent - pointer to the enclosing context node or NULL if none.

   SEE ALSO
	[CurrentChunk()](autodocs-3.5/iffparse-library-currentchunk-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)

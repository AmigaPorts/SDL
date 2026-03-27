---
title: iffparse.library/CurrentChunk
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-currentchunk-2
functions: [ParentChunk, ParseIFF, PopChunk, PushChunk]
libraries: [iffparse.library]
---

# iffparse.library/CurrentChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CurrentChunk -- get context node for current chunk. (V36)

   SYNOPSIS
	top = CurrentChunk(iff);
	D0                 A0

	struct [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) *CurrentChunk(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Returns the top context node for the given [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure. The top
	context node corresponds to the chunk most recently pushed on the
	stack, which is the chunk where the stream is currently positioned.
	The [ContextNode](autodocs-3.5/include-libraries-iffparse-h.md) structure contains information on the type of chunk
	currently being parsed (or written), its size and the current
	position within the chunk.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure

   RESULT
	top - pointer to top context node or NULL if none

   SEE ALSO
	[PushChunk()](autodocs-3.5/iffparse-library-pushchunk-2.md), [PopChunk()](autodocs-3.5/iffparse-library-popchunk-2.md), [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md), [ParentChunk()](autodocs-3.5/iffparse-library-parentchunk-2.md),
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

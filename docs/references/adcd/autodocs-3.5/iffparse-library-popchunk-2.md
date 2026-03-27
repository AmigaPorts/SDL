---
title: iffparse.library/PopChunk
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-popchunk-2
functions: [PushChunk]
libraries: [iffparse.library]
---

# iffparse.library/PopChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PopChunk -- pop top context node off context stack. (V36)

   SYNOPSIS
	error = PopChunk(iff);
	D0               A0

	[LONG](autodocs-3.5/include-exec-types-h.md) PopChunk(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Pops top context chunk and frees all associated local context items.
	The function is normally called only for writing files and signals
	the end of a chunk.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PushChunk()](autodocs-3.5/iffparse-library-pushchunk-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

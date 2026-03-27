---
title: iffparse.library/StopChunks
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-stopchunks-2
functions: [PropChunk, PropChunks, StopChunk]
libraries: [iffparse.library]
---

# iffparse.library/StopChunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StopChunks -- declare many stop chunks at once. (V36)

   SYNOPSIS
	error = StopChunks(iff, propArray, numPairs);
	D0                 A0   A1         D0

	[LONG](autodocs-3.5/include-exec-types-h.md) StopChunks(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md) *, LONG);

   FUNCTION
	(is to [StopChunk()](autodocs-3.5/iffparse-library-stopchunk-2.md) as [PropChunks()](autodocs-3.5/iffparse-library-propchunks-2.md) is to PropChunk().)

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	propArray - pointer to array of longword chunk types and identifiers.
	numPairs - number of pairs in the array.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[StopChunk()](autodocs-3.5/iffparse-library-stopchunk-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)

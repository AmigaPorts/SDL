---
title: iffparse.library/PropChunks
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-propchunks-2
functions: [PropChunk, PropChunks]
libraries: [iffparse.library]
---

# iffparse.library/PropChunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PropChunks -- declare many property chunks at once. (V36)

   SYNOPSIS
	error = PropChunks(iff, propArray, numPairs);
	D0                 A0   A1         D0

	[LONG](autodocs-3.5/include-exec-types-h.md) PropChunks(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md) *, LONG);

   FUNCTION
	Declares multiple property chunks from a list. The propArray argument
	if a pointer to an array of longwords arranged in pairs, and has the
	following format:

		TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

	The argument numPairs is the number of pairs. PropChunks() just calls
	[PropChunk()](autodocs-3.5/iffparse-library-propchunk-2.md) numPairs times.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	propArray - pointer to array of longword chunk types and identifiers.
	numPairs - number of pairs in the array.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PropChunk()](autodocs-3.5/iffparse-library-propchunk-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)

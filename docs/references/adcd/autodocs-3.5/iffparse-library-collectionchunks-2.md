---
title: iffparse.library/CollectionChunks
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-collectionchunks-2
functions: [CollectionChunk, CollectionChunks]
libraries: [iffparse.library]
---

# iffparse.library/CollectionChunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CollectionChunks -- declare many collection chunks at once. (V36)

   SYNOPSIS
	error = CollectionChunks(iff, propArray, numPairs);
	D0                       A0   A1         D0

	[LONG](autodocs-3.5/include-exec-types-h.md) CollectionChunks(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md) *, LONG);

   FUNCTION
	Declares multiple collection chunks from a list. The propArray argument
	is a pointer to an array of longwords arranged in pairs. The format
	for the list is as follows:

		TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

	The argument numPairs is the number of pairs. CollectionChunks() just calls
	[CollectionChunk()](autodocs-3.5/iffparse-library-collectionchunk-2.md) numPairs times.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure (does not need to be open)
	propArray - pointer to array of longword chunk types and identifiers
	numPairs - number of pairs in array.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful

   SEE ALSO
	[CollectionChunk()](autodocs-3.5/iffparse-library-collectionchunk-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [CollectionChunks — iffparse.library](../autodocs/iffparse.library.md#collectionchunks)

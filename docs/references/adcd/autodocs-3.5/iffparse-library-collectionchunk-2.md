---
title: iffparse.library/CollectionChunk
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-collectionchunk-2
functions: [CollectionChunks, FindCollection, PropChunk]
libraries: [iffparse.library]
---

# iffparse.library/CollectionChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CollectionChunk -- declare a chunk type for collection. (V36)

   SYNOPSIS
	error = CollectionChunk(iff, type, id);
	D0                      A0   D0    D1

	[LONG](autodocs-3.5/include-exec-types-h.md) CollectionChunk(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Installs an entry handler for chunks with the given type and id so
	that the contents of those chunks will be stored as they are
	encountered. This is like [PropChunk()](autodocs-3.5/iffparse-library-propchunk-2.md) except that more than one
	chunk of this type can be stored in lists which can be returned by
	[FindCollection()](autodocs-3.5/iffparse-library-findcollection-2.md). The storage of these chunks still follows the
	property chunk scoping rules for IFF files so that at any given
	point, stored collection chunks will be valid in the current context.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure (does not need to be open)
	type - type code for the chunk to declare (ex. "ILBM")
	id - identifier for the chunk to declare (ex. "CRNG")

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[CollectionChunks()](autodocs-3.5/iffparse-library-collectionchunks-2.md), [FindCollection()](autodocs-3.5/iffparse-library-findcollection-2.md), [PropChunk()](autodocs-3.5/iffparse-library-propchunk-2.md),
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CollectionChunks — iffparse.library](../autodocs/iffparse.library.md#collectionchunks)
- [FindCollection — iffparse.library](../autodocs/iffparse.library.md#findcollection)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)

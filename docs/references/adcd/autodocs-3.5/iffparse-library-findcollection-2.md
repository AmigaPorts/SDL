---
title: iffparse.library/FindCollection
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-findcollection-2
functions: [CollectionChunk, CollectionChunks]
libraries: [iffparse.library]
---

# iffparse.library/FindCollection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindCollection -- get a pointer to the current list of collection
			  items. (V36)

   SYNOPSIS
	ci = FindCollection(iff, type, id);
	D0                  A0   D0    D1

	struct [CollectionItem](autodocs-3.5/include-libraries-iffparse-h.md) *FindCollection(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Returns a pointer to a list of [CollectionItem](autodocs-3.5/include-libraries-iffparse-h.md) structures for each of
	the collection chunks of the given type encountered so far in the
	course of parsing this IFF file. The items appearing first in the
	list will be the ones encountered most recently.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	type - type code to search for.
	id - identifier code to search for.

   RESULT
	ci - pointer to last collection chunk encountered with
	     links to previous ones.

   SEE ALSO
	[CollectionChunk()](autodocs-3.5/iffparse-library-collectionchunk-2.md), [CollectionChunks()](autodocs-3.5/iffparse-library-collectionchunks-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [CollectionChunks — iffparse.library](../autodocs/iffparse.library.md#collectionchunks)

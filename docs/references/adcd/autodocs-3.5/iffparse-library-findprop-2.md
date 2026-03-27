---
title: iffparse.library/FindProp
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-findprop-2
functions: [ParseIFF, PropChunk, PropChunks]
libraries: [iffparse.library]
---

# iffparse.library/FindProp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindProp -- search for a stored property chunk. (V36)

   SYNOPSIS
	sp = FindProp(iff, type, id);
	D0            A0   D0    D1

	struct [StoredProperty](autodocs-3.5/include-libraries-iffparse-h.md) *FindProp(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Searches for the stored property which is valid in the given context.
	Property chunks are automatically stored by [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md) when
	pre-declared by [PropChunk()](autodocs-3.5/iffparse-library-propchunk-2.md) or [PropChunks()](autodocs-3.5/iffparse-library-propchunks-2.md). The [StoredProperty](autodocs-3.5/include-libraries-iffparse-h.md)
	struct, if found, contains a pointer to a data buffer containing the
	contents of the stored property.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	type - type code for chunk to search for (ex. "ILBM").
	id - identifier code for chunk to search for (ex. "CMAP").

   RESULT
	sp - pointer to stored property, or NULL if none found.

   SEE ALSO
	[PropChunk()](autodocs-3.5/iffparse-library-propchunk-2.md), [PropChunks()](autodocs-3.5/iffparse-library-propchunks-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)

---
title: iffparse.library/PropChunk
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-propchunk-2
functions: [CollectionChunk, FindProp, PropChunks]
libraries: [iffparse.library]
---

# iffparse.library/PropChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PropChunk -- specify a property chunk to store. (V36)

   SYNOPSIS
	error = PropChunk(iff, type, id);
	D0                A0   D0    D1

	[LONG](autodocs-3.5/include-exec-types-h.md) PropChunk(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Installs an entry handler for chunks with the given type and ID so
	that the contents of those chunks will be stored as they are
	encountered. The storage of these chunks follows the property chunk
	scoping rules for IFF files so that at any given point, a stored
	property chunk returned by [FindProp()](autodocs-3.5/iffparse-library-findprop-2.md) will be the valid property for
	the current context.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure (does not need to be open).
	type - type code for the chunk to declare (ex. "ILBM").
	id - identifier for the chunk to declare (ex. "CMAP").

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PropChunks()](autodocs-3.5/iffparse-library-propchunks-2.md), [FindProp()](autodocs-3.5/iffparse-library-findprop-2.md), [CollectionChunk()](autodocs-3.5/iffparse-library-collectionchunk-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)

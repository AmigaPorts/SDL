---
title: iffparse.library/GoodID
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-goodid-2
functions: [GoodType]
libraries: [iffparse.library]
---

# iffparse.library/GoodID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GoodID -- test if an identifier follows the IFF 85 specification. (V36)

   SYNOPSIS
	isok = GoodID(id);
	D0            D0

	[LONG](autodocs-3.5/include-exec-types-h.md) GoodID(LONG);

   FUNCTION
	Tests the given longword identifier to see if it meets all the EA IFF
	85 specifications for a chunk ID. If so, it returns non-zero,
	otherwise 0.

   INPUTS
	id - potential 32 bit identifier.

   RESULT
	isok - non-zero if this is a valid ID, 0 otherwise.

   SEE ALSO
	[GoodType()](autodocs-3.5/iffparse-library-goodtype-2.md)

---

## See Also

- [GoodType — iffparse.library](../autodocs/iffparse.library.md#goodtype)

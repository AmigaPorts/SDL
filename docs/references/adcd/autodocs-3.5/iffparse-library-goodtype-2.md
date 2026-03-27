---
title: iffparse.library/GoodType
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-goodtype-2
functions: [GoodID, GoodType]
libraries: [iffparse.library]
---

# iffparse.library/GoodType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GoodType -- test if a type follows the IFF 85 specification. (V36)

   SYNOPSIS
	isok = GoodType(type)
	D0              D0

	[LONG](autodocs-3.5/include-exec-types-h.md) GoodType(LONG);

   FUNCTION
	Tests the given longword type identifier to see if it meets all the
	EA IFF 85 specifications for a FORM type (requirements for a FORM
	type are more stringent than those for a simple chunk ID). If it
	complies, GoodType() returns non-zero, otherwise 0.

   INPUTS
	type - potential 32 bit format type identifier.

   RESULT
	isok - non-zero if this is a valid type id, 0 otherwise.

   SEE ALSO
	[GoodID()](autodocs-3.5/iffparse-library-goodid-2.md)

---

## See Also

- [GoodID — iffparse.library](../autodocs/iffparse.library.md#goodid)
- [GoodType — iffparse.library](../autodocs/iffparse.library.md#goodtype)

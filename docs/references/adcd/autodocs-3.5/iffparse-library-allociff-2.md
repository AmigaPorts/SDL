---
title: iffparse.library/AllocIFF
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-allociff-2
functions: [AllocIFF, FreeIFF]
libraries: [iffparse.library]
---

# iffparse.library/AllocIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocIFF -- create a new [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure. (V36)

   SYNOPSIS
	iff = AllocIFF()
	D0

	struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *AllocIFF(VOID);

   FUNCTION
	Allocates and initializes a new [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	This function is the only supported way to create an [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md)
	structure since there are private fields that need to be initialized.

   RESULT
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure or NULL if the allocation failed.

   SEE ALSO
	[FreeIFF()](autodocs-3.5/iffparse-library-freeiff-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)

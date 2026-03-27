---
title: iffparse.library/FreeIFF
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-freeiff-2
functions: [AllocIFF, CloseIFF]
libraries: [iffparse.library]
---

# iffparse.library/FreeIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeIFF -- deallocate an [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure. (V36)

   SYNOPSIS
	FreeIFF(iff);
	        A0

	VOID FreeIFF(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Deallocates all resources associated with this [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	The structure MUST have already been closed with [CloseIFF()](autodocs-3.5/iffparse-library-closeiff-2.md).

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure to free. Starting with V39,
	      this may be NULL.

   SEE ALSO
	[AllocIFF()](autodocs-3.5/iffparse-library-allociff-2.md), [CloseIFF()](autodocs-3.5/iffparse-library-closeiff-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)

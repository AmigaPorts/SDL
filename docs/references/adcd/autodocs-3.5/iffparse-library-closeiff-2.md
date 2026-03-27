---
title: iffparse.library/CloseIFF
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-closeiff-2
functions: [CloseIFF, InitIFF, OpenIFF]
libraries: [iffparse.library]
---

# iffparse.library/CloseIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseIFF -- close an IFF context. (V36)

   SYNOPSIS
	CloseIFF(iff);
	         A0

	VOID CloseIFF(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Completes an IFF read or write operation by closing the IFF context
	established for this [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure. The [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure
	itself is left ready for re-use and a new context can be opened with
	[OpenIFF()](autodocs-3.5/iffparse-library-openiff-2.md). This function can be used for cleanup if a read or write
	fails partway through.

	As part of its cleanup operation, CloseIFF() calls the client-
	supplied stream hook vector. The [IFFStreamCmd](autodocs-3.5/include-libraries-iffparse-h.md) packet will be set
	as follows:

		sc_Command:	IFFCMD_CLEANUP
		sc_Buf:		(Not applicable)
		sc_NBytes:	(Not applicable)

	This operation is NOT permitted to fail;  any error code returned
	will be ignored (best to return 0, though). DO NOT write to this
	structure.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure previously opened with
	      [OpenIFF()](autodocs-3.5/iffparse-library-openiff-2.md). Starting with V39, this may be NULL.

   SEE ALSO
	[OpenIFF()](autodocs-3.5/iffparse-library-openiff-2.md), [InitIFF()](autodocs-3.5/iffparse-library-initiff-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)

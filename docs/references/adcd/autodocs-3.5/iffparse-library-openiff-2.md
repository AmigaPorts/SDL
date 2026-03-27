---
title: iffparse.library/OpenIFF
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-openiff-2
functions: [CloseIFF, InitIFF, OpenIFF]
libraries: [iffparse.library]
---

# iffparse.library/OpenIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenIFF -- prepare an [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) to read or write a new IFF stream.
	           (V36)

   SYNOPSIS
	error = OpenIFF(iff, rwMode);
	D0              A0   D0

	[LONG](autodocs-3.5/include-exec-types-h.md) OpenIFF(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, LONG);

   FUNCTION
	Initializes an [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure for a new read or write. The
	direction of the I/O is given by the value of rwMode, which can be
	either IFFF_READ or IFFF_WRITE.

	As part of its initialization procedure, OpenIFF() calls the client-
	supplied stream hook vector. The [IFFStreamCmd](autodocs-3.5/include-libraries-iffparse-h.md) packet will contain
	the following:

		sc_Command:	IFFCMD_INIT
		sc_Buf:		(Not applicable)
		sc_NBytes:	(Not applicable)

	This operation is permitted to fail. DO NOT write to this structure.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure. Starting with V39, this may be
	      NULL, in which case IFFERR_NOMEM is returned.
	rwMode - IFFF_READ or IFFF_WRITE

   RESULT
	error - contains an error code or 0 if successful

   SEE ALSO
	[CloseIFF()](autodocs-3.5/iffparse-library-closeiff-2.md), [InitIFF()](autodocs-3.5/iffparse-library-initiff-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)

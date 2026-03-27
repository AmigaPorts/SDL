---
title: iffparse.library/StopChunk
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-stopchunk-2
functions: [ParseIFF, StopChunks]
libraries: [iffparse.library]
---

# iffparse.library/StopChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StopChunk -- declare a chunk which should cause [ParseIFF](autodocs-3.5/iffparse-library-parseiff-2.md) to return.
	             (V36)

   SYNOPSIS
	error = StopChunk(iff, type, id);
	D0                A0   D0    D1

	[LONG](autodocs-3.5/include-exec-types-h.md) StopChunk(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG);		 type;

   FUNCTION
	Installs an entry handler for the specified chunk which will cause
	the [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md) function to return control to the caller when this
	chunk is encountered. This is only of value when [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md) is
	called with the IFFPARSE_SCAN control code.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure (need not be open).
	type - type code for chunk to declare (ex. "ILBM").
	id - identifier for chunk to declare (ex. "BODY").

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[StopChunks()](autodocs-3.5/iffparse-library-stopchunks-2.md), [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [StopChunks — iffparse.library](../autodocs/iffparse.library.md#stopchunks)

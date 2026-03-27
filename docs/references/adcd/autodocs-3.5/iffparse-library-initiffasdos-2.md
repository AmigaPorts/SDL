---
title: iffparse.library/InitIFFasDOS
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-initiffasdos-2
functions: [InitIFF, Open]
libraries: [dos.library, iffparse.library]
---

# iffparse.library/InitIFFasDOS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InitIFFasDOS -- initialize an [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) as a DOS stream. (V36)

   SYNOPSIS
	InitIFFasDOS(iff)
	             A0

	InitIFFasDOS(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	The function initializes the given [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) to operate on DOS
	streams. The iff_Stream field will need to be initialized as a [BPTR](autodocs-3.5/include-dos-dos-h.md)
	returned from the DOS function [Open()](autodocs-3.5/dos-library-open-2.md).

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.

   SEE ALSO
	[InitIFF()](autodocs-3.5/iffparse-library-initiff-2.md)

---

## See Also

- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [Open — dos.library](../autodocs/dos.library.md#open)

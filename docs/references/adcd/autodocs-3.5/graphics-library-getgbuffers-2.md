---
title: graphics.library/GetGBuffers
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getgbuffers-2
functions: [FreeGBuffers]
libraries: [graphics.library]
---

# graphics.library/GetGBuffers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetGBuffers -- Attempt to allocate ALL buffers of an entire [AnimOb](autodocs-3.5/include-graphics-gels-h.md).

   SYNOPSIS
	status = GetGBuffers(anOb, rp, db)
	D0                   A0    A1  D0

	[BOOL](autodocs-3.5/include-exec-types-h.md) GetGBuffers(struct [AnimOb](autodocs-3.5/include-graphics-gels-h.md) *, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, BOOL);

   FUNCTION
	For each sequence of each component of the [AnimOb](autodocs-3.5/include-graphics-gels-h.md), allocate memory for:
	    SaveBuffer
	    BorderLine
	    CollMask and ImageShadow (point to same buffer)
	    if db is set TRUE (user wants double-buffering) allocate:
	        [DBufPacket](autodocs-3.5/include-graphics-gels-h.md)
	        BufBuffer

   INPUTS
	anOb = pointer to the [AnimOb](autodocs-3.5/include-graphics-gels-h.md) structure
	rp   = pointer to the current [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	db   = double-buffer indicator (set TRUE for double-buffering)

   RESULT
	status = TRUE if the memory allocations were all successful, else FALSE

   BUGS
	If any of the memory allocations fail it does not free the partial
	allocations that did succeed.

   SEE ALSO
	[FreeGBuffers()](autodocs-3.5/graphics-library-freegbuffers-2.md) [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [FreeGBuffers — graphics.library](../autodocs/graphics.library.md#freegbuffers)

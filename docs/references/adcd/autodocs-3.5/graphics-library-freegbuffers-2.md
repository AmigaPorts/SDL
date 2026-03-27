---
title: graphics.library/FreeGBuffers
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freegbuffers-2
functions: [GetGBuffers]
libraries: [graphics.library]
---

# graphics.library/FreeGBuffers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeGBuffers -- [Deallocate](autodocs-3.5/exec-library-deallocate-2.md) memory obtained by GetGBufers.

   SYNOPSIS
	FreeGBuffers(anOb, rp, db)
	             A0    A1  D0

	void FreeGBuffers(struct [AnimOb](autodocs-3.5/include-graphics-gels-h.md) *, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, BOOL);

   FUNCTION
	For each sequence of each component of the [AnimOb](autodocs-3.5/include-graphics-gels-h.md),
	deallocate memory for:
	    SaveBuffer
	    BorderLine
	    CollMask and ImageShadow (point to same buffer)
	    if db is set (user had used double-buffering) deallocate:
	        [DBufPacket](autodocs-3.5/include-graphics-gels-h.md)
	        BufBuffer

   INPUTS
	anOb = pointer to the [AnimOb](autodocs-3.5/include-graphics-gels-h.md) structure
	rp   = pointer to the current [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	db   = double-buffer indicator (set TRUE for double-buffering)

   RESULT

   BUGS

   SEE ALSO
	[GetGBuffers()](autodocs-3.5/graphics-library-getgbuffers-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [GetGBuffers — graphics.library](../autodocs/graphics.library.md#getgbuffers)

---
title: Includes/graphics/scale.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-graphics-scale-i
functions: [BitMapScale]
libraries: [graphics.library]
---

# Includes/graphics/scale.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	GRAPHICS_SCALE_I
GRAPHICS_SCALE_I	SET	1
**
**	$Filename: graphics/scale.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.0 $
**	$Date: 91/01/07 $
**
**	structure argument to BitMapScale()
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**	    All Rights Reserved
**


    IFND    EXEC_TYPES_I
    include 'exec/types.i'
    ENDC
 STRUCTURE	BitScaleArgs,0

```c
    UWORD   bsa_SrcX		; source origin
    UWORD   bsa_SrcY
    UWORD   bsa_SrcWidth	; source size
    UWORD   bsa_SrcHeight
    UWORD   bsa_XSrcFactor	; scale factor denominators
    UWORD   bsa_YSrcFactor
    UWORD   bsa_DestX		; destination origin
    UWORD   bsa_DestY
    UWORD   bsa_DestWidth	; destination size result
    UWORD   bsa_DestHeight
    UWORD   bsa_XDestFactor	; scale factor numerators
    UWORD   bsa_YDestFactor
    APTR    bsa_SrcBitMap	; source BitMap
    APTR    bsa_DestBitMap	; destination BitMap
    ULONG   bsa_Flags		; reserved.  Must be zero!
    UWORD   bsa_XDDA		; reserved
    UWORD   bsa_YDDA
    LONG    bsa_Reserved1
    LONG    bsa_Reserved2
    LABEL   bsa_SIZEOF
```
	ENDC	; GRAPHICS_SCALE_I

---

## See Also

- [BitMapScale — graphics.library](../autodocs/graphics.library.md#bitmapscale)

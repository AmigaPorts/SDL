---
title: include/graphics/scale.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-graphics-scale-h
functions: [BitMapScale]
libraries: [graphics.library]
---

# include/graphics/scale.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	GRAPHICS_SCALE_H
#define	GRAPHICS_SCALE_H
/*
**	$VER: scale.h 39.0 (21.8.1991)
**	Includes Release 44.1
**
**	structure argument to BitMapScale()
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

struct BitScaleArgs {
```c
    UWORD   bsa_SrcX, bsa_SrcY;			/* source origin */
    UWORD   bsa_SrcWidth, bsa_SrcHeight;	/* source size */
    UWORD   bsa_XSrcFactor, bsa_YSrcFactor;	/* scale factor denominators */
    UWORD   bsa_DestX, bsa_DestY;		/* destination origin */
    UWORD   bsa_DestWidth, bsa_DestHeight;	/* destination size result */
    UWORD   bsa_XDestFactor, bsa_YDestFactor;	/* scale factor numerators */
    struct BitMap *bsa_SrcBitMap;		/* source BitMap */
    struct BitMap *bsa_DestBitMap;		/* destination BitMap */
    ULONG   bsa_Flags;				/* reserved.  Must be zero! */
    UWORD   bsa_XDDA, bsa_YDDA;			/* reserved */
    LONG    bsa_Reserved1;
    LONG    bsa_Reserved2;
```
};
#endif	/* GRAPHICS_SCALE_H */

---

## See Also

- [BitMapScale — graphics.library](../autodocs/graphics.library.md#bitmapscale)

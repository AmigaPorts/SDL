---
title: include/graphics/coerce.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-graphics-coerce-h
functions: [CoerceMode]
libraries: [graphics.library]
---

# include/graphics/coerce.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef GRAPHICS_COERCE_H
#define GRAPHICS_COERCE_H
/*
**	$VER: coerce.h 39.3 (15.2.1993)
**	Includes Release 44.1
**
**	mode coercion definitions
**
**	(C) Copyright 1992-1999 Amiga, Inc.
**	    All Rights Reserved
*/

/* These flags are passed (in combination) to CoerceMode() to determine the
 * type of coercion required.
 */

/* Ensure that the mode coerced to can display just as many colours as the
 * ViewPort being coerced.
 */
#define PRESERVE_COLORS 1

/* Ensure that the mode coerced to is not interlaced. */
#define AVOID_FLICKER 2

/* Coercion should ignore monitor compatibility issues. */
#define IGNORE_MCOMPAT 4


#define BIDTAG_COERCE 1	/* Private */

#endif

---

## See Also

- [CoerceMode — graphics.library](../autodocs/graphics.library.md#coercemode)

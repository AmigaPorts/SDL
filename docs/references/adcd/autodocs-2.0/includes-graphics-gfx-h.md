---
title: Includes/graphics/gfx.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-graphics-gfx-h
functions: []
libraries: []
---

# Includes/graphics/gfx.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	GRAPHICS_GFX_H
#define	GRAPHICS_GFX_H
/*
**	$Filename: graphics/gfx.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.0 $
**	$Date: 91/01/07 $
**
**	general include file for application programs
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#define BITSET	0x8000
#define BITCLR	0

#define AGNUS
#ifdef AGNUS
#define TOBB(a)      ((long)(a))
#else
#define TOBB(a)      ((long)(a)>>1)  /* convert Chip adr to Bread Board Adr */
#endif

struct Rectangle
{
```c
    WORD   MinX,MinY;
    WORD   MaxX,MaxY;
```
};

struct Rect32
{
```c
    LONG    MinX,MinY;
    LONG    MaxX,MaxY;
```
};

typedef struct tPoint
{
```c
    WORD x,y;
```
} Point;

typedef UBYTE *PLANEPTR;

struct BitMap
{
```c
    UWORD   BytesPerRow;
    UWORD   Rows;
    UBYTE   Flags;
    UBYTE   Depth;
    UWORD   pad;
    PLANEPTR Planes[8];
```
};

#define RASSIZE(w,h)	((h)*( ((w)+15)>>3&0xFFFE))

#endif	/* GRAPHICS_GFX_H */


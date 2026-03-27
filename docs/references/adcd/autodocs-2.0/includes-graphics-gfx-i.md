---
title: Includes/graphics/gfx.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-graphics-gfx-i
functions: []
libraries: []
---

# Includes/graphics/gfx.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	GRAPHICS_GFX_I
GRAPHICS_GFX_I	SET	1
**
**	$Filename: graphics/gfx.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.0 $
**	$Date: 91/01/07 $
**
**
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
**


    IFND    EXEC_TYPES_I
    include 'exec/types.i'
    ENDC
BITSET	    equ $8000
BITCLR	    equ 0
AGNUS	    equ 1
DENISE	    equ 1


    STRUCTURE	BitMap,0
    WORD    bm_BytesPerRow
    WORD    bm_Rows
    BYTE    bm_Flags
    BYTE    bm_Depth
    WORD    bm_Pad
    STRUCT  bm_Planes,8*4
    LABEL   bm_SIZEOF
   STRUCTURE   Rectangle,0
      WORD  ra_MinX
      WORD  ra_MinY
      WORD  ra_MaxX
      WORD  ra_MaxY
   LABEL    ra_SIZEOF

   STRUCTURE   Rect32,0
      LONG  r32_MinX
      LONG  r32_MinY
      LONG  r32_MaxX
      LONG  r32_MaxY
   LABEL    r32_SIZEOF

   STRUCTURE   tPoint,0
      WORD  tpt_x
      WORD  tpt_y
   LABEL    tpt_SIZEOF


```c
    ENDC	; GRAPHICS_GFX_I
```

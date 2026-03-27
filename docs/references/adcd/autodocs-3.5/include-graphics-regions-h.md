---
title: include/graphics/regions.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-graphics-regions-h
functions: []
libraries: []
---

# include/graphics/regions.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	GRAPHICS_REGIONS_H
#define	GRAPHICS_REGIONS_H
/*
**	$VER: regions.h 39.0 (21.8.1991)
**	Includes Release 44.1
**
**
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

struct RegionRectangle
{
```c
    struct RegionRectangle *Next,*Prev;
    struct Rectangle bounds;
```
};

struct Region
{
```c
    struct Rectangle bounds;
    struct RegionRectangle *RegionRectangle;
```
};

#endif	/* GRAPHICS_REGIONS_H */


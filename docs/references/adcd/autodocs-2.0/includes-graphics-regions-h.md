---
title: Includes/graphics/regions.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-graphics-regions-h
functions: []
libraries: []
---

# Includes/graphics/regions.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	GRAPHICS_REGIONS_H
#define	GRAPHICS_REGIONS_H
/*
**	$Filename: graphics/regions.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.0 $
**	$Date: 91/01/07 $
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


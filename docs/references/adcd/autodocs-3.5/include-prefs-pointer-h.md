---
title: include/prefs/pointer.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-prefs-pointer-h
functions: []
libraries: []
---

# include/prefs/pointer.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef PREFS_POINTER_H
#define PREFS_POINTER_H
/*
**	$VER: pointer.h 39.2 (9.6.1992)
**	Includes Release 44.1
**
**	File format for pointer preferences
**
**	(C) Copyright 1991-1999 Amiga, Inc.
**	All Rights Reserved
*/

/*****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

/*****************************************************************************/

#define ID_PNTR MAKE_ID('P','N','T','R')

/*****************************************************************************/

struct PointerPrefs
{
```c
    ULONG pp_Reserved[4];
    UWORD pp_Which;				/* 0=NORMAL, 1=BUSY */
    UWORD pp_Size;				/* see <intuition/pointerclass.h> */
    UWORD pp_Width;				/* Width in pixels */
    UWORD pp_Height;				/* Height in pixels */
    UWORD pp_Depth;				/* Depth */
    UWORD pp_YSize;				/* YSize */
    UWORD pp_X, pp_Y;				/* Hotspot */

    /* Color Table:  numEntries = (1 << pp_Depth) - 1 */

    /* Data follows */
```
};

/*****************************************************************************/

/* constants for PointerPrefs.pp_Which */
#define	WBP_NORMAL	0
#define	WBP_BUSY	1

/*****************************************************************************/

struct RGBTable
{
```c
    UBYTE t_Red;
    UBYTE t_Green;
    UBYTE t_Blue;
```
};

/*****************************************************************************/

#endif /* PREFS_POINTER_H */


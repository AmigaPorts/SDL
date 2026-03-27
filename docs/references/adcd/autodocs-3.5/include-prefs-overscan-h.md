---
title: include/prefs/overscan.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-prefs-overscan-h
functions: []
libraries: []
---

# include/prefs/overscan.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef PREFS_OVERSCAN_H
#define PREFS_OVERSCAN_H
/*
**	$VER: overscan.h 38.4 (22.10.1992)
**	Includes Release 44.1
**
**	File format for overscan preferences
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

#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif


/*****************************************************************************/


#define ID_OSCN MAKE_ID('O','S','C','N')

#define OSCAN_MAGIC  0xFEDCBA89


struct OverscanPrefs
{
```c
    ULONG	     os_Reserved;
    ULONG	     os_Magic;
    UWORD	     os_HStart;
    UWORD	     os_HStop;
    UWORD	     os_VStart;
    UWORD	     os_VStop;
    ULONG	     os_DisplayID;
    Point	     os_ViewPos;
    Point	     os_Text;
    struct Rectangle os_Standard;
```
};

/* os_HStart, os_HStop, os_VStart, os_VStop can only be looked at if
 * os_Magic equals OSCAN_MAGIC. If os_Magic is set to any other value,
 * these four fields are undefined
 */


/*****************************************************************************/


#endif /* PREFS_OVERSCAN_H */


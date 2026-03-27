---
title: include/prefs/screenmode.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-prefs-screenmode-h
functions: []
libraries: []
---

# include/prefs/screenmode.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef PREFS_SCREENMODE_H
#define PREFS_SCREENMODE_H
/*
**	$VER: screenmode.h 38.4 (25.6.1992)
**	Includes Release 44.1
**
**	File format for screen mode preferences
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


#define ID_SCRM MAKE_ID('S','C','R','M')


struct ScreenModePrefs
{
```c
    ULONG smp_Reserved[4];
    ULONG smp_DisplayID;
    UWORD smp_Width;
    UWORD smp_Height;
    UWORD smp_Depth;
    UWORD smp_Control;
```
};

/* flags for ScreenModePrefs.smp_Control */
#define SMB_AUTOSCROLL 1

#define SMF_AUTOSCROLL (1<<0)


/*****************************************************************************/


#endif /* PREFS_SCREENMODE_H */


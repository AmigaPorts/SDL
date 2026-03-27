---
title: include/prefs/workbench.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-prefs-workbench-h
functions: []
libraries: []
---

# include/prefs/workbench.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef PREFS_WORKBENCH_H
#define PREFS_WORKBENCH_H
/*
**	$VER: workbench.h 44.1 (19.10.1999)
**	Includes Release 44.1
**
**	Workbench preferences file definitions
**
**	(C) Copyright 1987-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

/*****************************************************************************/

#define ID_WBNC MAKE_ID('W','B','N','C')

struct WorkbenchPrefs
{
```c
    /* settings from workbench.library */
    ULONG		wbp_DefaultStackSize;	/* in bytes */
    ULONG		wbp_TypeRestartTime;	/* in seconds */
    /* settings from icon.library */
    ULONG		wbp_IconPrecision;	/* PRECISION_#? values */
    struct Rectangle	wbp_EmbossRect;
    BOOL		wbp_Borderless;
    LONG		wbp_MaxNameLength;
    BOOL		wbp_NewIconsSupport;
    BOOL		wbp_ColorIconSupport;
```
};

#define ID_WBHD MAKE_ID('W','B','H','D')

struct WorkbenchHiddenDevicePrefs
{
```c
    UBYTE		whdp_Name[0];	/* C String including NUL char */
```
};

/*****************************************************************************/

#endif /* PREFS_WORKBENCH_H */


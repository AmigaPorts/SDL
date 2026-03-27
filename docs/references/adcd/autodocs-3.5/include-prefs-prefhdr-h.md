---
title: include/prefs/prefhdr.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-prefs-prefhdr-h
functions: []
libraries: []
---

# include/prefs/prefhdr.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef PREFS_PREFHDR_H
#define PREFS_PREFHDR_H
/*
**	$VER: prefhdr.h 38.1 (19.6.1991)
**	Includes Release 44.1
**
**	File format for preferences header
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


#define ID_PREF	 MAKE_ID('P','R','E','F')
#define ID_PRHD	 MAKE_ID('P','R','H','D')


struct PrefHeader
{
```c
    UBYTE ph_Version;	/* version of following data */
    UBYTE ph_Type;	/* type of following data    */
    ULONG ph_Flags;	/* always set to 0 for now   */
```
};


/*****************************************************************************/


#endif /* PREFS_PREFHDR_H */


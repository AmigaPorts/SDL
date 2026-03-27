---
title: Includes/clib/diskfont_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-diskfont-protos-h
functions: []
libraries: []
---

# Includes/clib/diskfont_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_DISKFONT_PROTOS_H
#define  CLIB_DISKFONT_PROTOS_H
/*
**	$Filename: clib/diskfont_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.2 $
**	$Date: 90/07/19 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  LIBRARIES_DISKFONT_H
#include <libraries/diskfont.h>
#endif
struct TextFont *OpenDiskFont( struct TextAttr *textAttr );
LONG AvailFonts( STRPTR buffer, long bufBytes, long flags );
/*--- functions in V34 or higher (distributed as Release 1.3) ---*/
struct FontContentsHeader *NewFontContents( BPTR fontsLock, STRPTR fontName );
void DisposeFontContents( struct FontContentsHeader *fontContentsHeader );
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
struct DiskFontHeader *NewScaledDiskFont( struct TextFont *sourceFont,
	struct TextAttr *destTextAttr );
#endif	 /* CLIB_DISKFONT_PROTOS_H */


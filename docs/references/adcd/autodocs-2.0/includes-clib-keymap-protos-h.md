---
title: Includes/clib/keymap_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-keymap-protos-h
functions: []
libraries: []
---

# Includes/clib/keymap_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_KEYMAP_PROTOS_H
#define  CLIB_KEYMAP_PROTOS_H
/*
**	$Filename: clib/keymap_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.4 $
**	$Date: 90/07/19 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef  DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
void SetKeyMapDefault( struct KeyMap *keyMap );
struct KeyMap *AskKeyMapDefault( void );
WORD MapRawKey( struct InputEvent *event, STRPTR buffer, long length,
	struct KeyMap *keyMap );
LONG MapANSI( STRPTR string, long count, STRPTR buffer, long length,
	struct KeyMap *keyMap );
#endif	 /* CLIB_KEYMAP_PROTOS_H */


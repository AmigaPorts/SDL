---
title: Includes/clib/misc_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-misc-protos-h
functions: []
libraries: []
---

# Includes/clib/misc_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_MISC_PROTOS_H
#define  CLIB_MISC_PROTOS_H
/*
**	$Filename: clib/misc_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.2 $
**	$Date: 90/11/07 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
UBYTE *AllocMiscResource( unsigned long unitNum, UBYTE *name );
void FreeMiscResource( unsigned long unitNum );
#endif	 /* CLIB_MISC_PROTOS_H */


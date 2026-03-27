---
title: Includes/clib/ramdrive_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-ramdrive-protos-h
functions: []
libraries: []
---

# Includes/clib/ramdrive_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_RAMDRIVE_PROTOS_H
#define  CLIB_RAMDRIVE_PROTOS_H
/*
**	$Filename: clib/ramdrive_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.3 $
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
/*--- functions in V34 or higher (distributed as Release 1.3) ---*/
STRPTR KillRAD0( void );
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
STRPTR KillRAD( unsigned long unit );
#endif	 /* CLIB_RAMDRIVE_PROTOS_H */


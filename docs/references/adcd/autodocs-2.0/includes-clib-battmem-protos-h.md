---
title: Includes/clib/battmem_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-battmem-protos-h
functions: []
libraries: []
---

# Includes/clib/battmem_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_BATTMEM_PROTOS_H
#define  CLIB_BATTMEM_PROTOS_H
/*
**	$Filename: clib/battmem_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.5 $
**	$Date: 91/03/04 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
void ObtainBattSemaphore( void );
void ReleaseBattSemaphore( void );
ULONG ReadBattMem( APTR buffer, unsigned long offset, unsigned long length );
ULONG WriteBattMem( APTR buffer, unsigned long offset, unsigned long length );
#endif	 /* CLIB_BATTMEM_PROTOS_H */


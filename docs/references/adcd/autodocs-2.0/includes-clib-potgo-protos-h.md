---
title: Includes/clib/potgo_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-potgo-protos-h
functions: []
libraries: []
---

# Includes/clib/potgo_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_POTGO_PROTOS_H
#define  CLIB_POTGO_PROTOS_H
/*
**	$Filename: clib/potgo_protos.h $
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
UWORD AllocPotBits( unsigned long bits );
void FreePotBits( unsigned long bits );
void WritePotgo( unsigned long word, unsigned long mask );
#endif	 /* CLIB_POTGO_PROTOS_H */


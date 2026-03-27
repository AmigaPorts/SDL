---
title: Includes/clib/cia_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-cia-protos-h
functions: []
libraries: []
---

# Includes/clib/cia_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_CIA_PROTOS_H
#define  CLIB_CIA_PROTOS_H
/*
**	$Filename: clib/cia_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.7 $
**	$Date: 90/07/19 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
struct Interrupt *AddICRVector( struct Library *resource, long iCRBit,
	struct Interrupt *interrupt );
void RemICRVector( struct Library *resource, long iCRBit,
	struct Interrupt *interrupt );
WORD AbleICR( struct Library *resource, long mask );
WORD SetICR( struct Library *resource, long mask );
#endif	 /* CLIB_CIA_PROTOS_H */


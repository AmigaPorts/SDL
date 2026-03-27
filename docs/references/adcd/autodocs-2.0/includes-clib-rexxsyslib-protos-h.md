---
title: Includes/clib/rexxsyslib_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-rexxsyslib-protos-h
functions: []
libraries: []
---

# Includes/clib/rexxsyslib_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_REXXSYSLIB_PROTOS_H
#define  CLIB_REXXSYSLIB_PROTOS_H
/*
**	$Filename: clib/rexxsyslib_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.3 $
**	$Date: 91/02/19 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
/*--- functions in V33 or higher (distributed as Release 1.2) ---*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  REXX_RXSLIB_H
#include <rexx/rxslib.h>
#endif
#ifndef  REXX_REXXIO_H
#include <rexx/rexxio.h>
#endif

UBYTE *CreateArgstring( UBYTE *string, unsigned long length );
void DeleteArgstring( UBYTE *argstring );
ULONG LengthArgstring( UBYTE *argstring );
struct RexxMsg *CreateRexxMsg( struct MsgPort *port, UBYTE *extension,
	UBYTE *host );
void DeleteRexxMsg( struct RexxMsg *packet );
void ClearRexxMsg( struct RexxMsg *msgptr, unsigned long count );
BOOL FillRexxMsg( struct RexxMsg *msgptr, unsigned long count,
	unsigned long mask );
BOOL IsRexxMsg( struct RexxMsg *msgptr );


void LockRexxBase( unsigned long resource );
void UnlockRexxBase( unsigned long resource );

#endif	 /* CLIB_REXXSYSLIB_PROTOS_H */


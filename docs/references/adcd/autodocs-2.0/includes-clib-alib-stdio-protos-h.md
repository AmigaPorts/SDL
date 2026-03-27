---
title: Includes/clib/alib_stdio_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-alib-stdio-protos-h
functions: []
libraries: []
---

# Includes/clib/alib_stdio_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_ALIB_STDIO_PROTOS_H
#define  CLIB_ALIB_STDIO_PROTOS_H
/*
**	$Filename: clib/alib_stdio_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.1 $
**	$Date: 91/11/04 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
/* functions that duplicate those in a typical C library */
LONG printf( STRPTR fmt, ... );
LONG sprintf( STRPTR buffer, STRPTR fmt, ... );
LONG fclose( long stream );
LONG fgetc( long stream );
LONG fprintf( long stream, STRPTR fmt, ... );
LONG fputc( long c, long stream );
LONG fputs( UBYTE *s, long stream );
LONG getchar( void );
LONG putchar( long c );
LONG puts( BYTE *s );
ULONG FastRand( unsigned long seed );
UWORD RangeRand( unsigned long maxValue );
#endif	 /* CLIB_ALIB_STDIO_PROTOS_H */


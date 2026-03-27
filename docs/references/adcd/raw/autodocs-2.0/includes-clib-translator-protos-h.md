# Includes/clib/translator_protos.h


#ifndef  CLIB_TRANSLATOR_PROTOS_H
#define  CLIB_TRANSLATOR_PROTOS_H
/*
**	$Filename: clib/translator_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.1 $
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
LONG Translate( STRPTR inputString, long inputLength, STRPTR outputBuffer,
	long bufferSize );
#endif	 /* CLIB_TRANSLATOR_PROTOS_H */


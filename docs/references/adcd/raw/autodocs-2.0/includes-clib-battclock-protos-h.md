# Includes/clib/battclock_protos.h


#ifndef  CLIB_BATTCLOCK_PROTOS_H
#define  CLIB_BATTCLOCK_PROTOS_H
/*
**	$Filename: clib/battclock_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.3 $
**	$Date: 90/05/03 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
void ResetBattClock( void );
ULONG ReadBattClock( void );
void WriteBattClock( unsigned long time );
#endif	 /* CLIB_BATTCLOCK_PROTOS_H */


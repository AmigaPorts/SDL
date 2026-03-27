---
title: Includes/clib/timer_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-timer-protos-h
functions: []
libraries: []
---

# Includes/clib/timer_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_TIMER_PROTOS_H
#define  CLIB_TIMER_PROTOS_H
/*
**	$Filename: clib/timer_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.6 $
**	$Date: 91/01/25 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif
void AddTime( struct timeval *dest, struct timeval *src );
void SubTime( struct timeval *dest, struct timeval *src );
LONG CmpTime( struct timeval *dest, struct timeval *src );
ULONG ReadEClock( struct EClockVal *dest );
void GetSysTime( struct timeval *dest );
#endif	 /* CLIB_TIMER_PROTOS_H */


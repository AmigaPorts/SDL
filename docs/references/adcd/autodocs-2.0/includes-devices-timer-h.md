---
title: Includes/devices/timer.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-devices-timer-h
functions: []
libraries: []
---

# Includes/devices/timer.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H 1
/*
**	$Filename: devices/timer.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.16 $
**	$Date: 91/01/25 $
**
**	Timer device name and useful definitions.
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**		All Rights Reserved
*/

#include <exec/types.h>
#include <exec/io.h>

/* unit defintions */
#define UNIT_MICROHZ	0
#define UNIT_VBLANK	1
#define UNIT_ECLOCK	2
#define UNIT_WAITUNTIL	3
#define	UNIT_WAITECLOCK	4

#define TIMERNAME	"timer.device"

struct timeval {
```c
    ULONG tv_secs;
    ULONG tv_micro;
```
};

struct EClockVal {
```c
    ULONG ev_hi;
    ULONG ev_lo;
```
};

struct timerequest {
```c
    struct IORequest tr_node;
    struct timeval tr_time;
```
};

/* IO_COMMAND to use for adding a timer */
#define TR_ADDREQUEST	CMD_NONSTD
#define TR_GETSYSTIME	(CMD_NONSTD+1)
#define TR_SETSYSTIME	(CMD_NONSTD+2)

#endif /* DEVICES_TIMER_H */


---
title: include/devices/timer.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-devices-timer-h
functions: []
libraries: []
---

# include/devices/timer.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H 1
/*
**	$VER: timer.h 36.16 (25.1.1991)
**	Includes Release 44.1
**
**	Timer device name and useful definitions.
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**		All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_IO_H
#include <exec/io.h>
#endif

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


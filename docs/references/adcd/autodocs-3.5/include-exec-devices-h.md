---
title: include/exec/devices.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-exec-devices-h
functions: []
libraries: []
---

# include/exec/devices.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	EXEC_DEVICES_H
#define	EXEC_DEVICES_H
/*
**	$VER: devices.h 39.0 (15.10.1991)
**	Includes Release 44.1
**
**	Include file for use by Exec device drivers
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif /* EXEC_LIBRARIES_H */

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif /* EXEC_PORTS_H */


/****** Device ******************************************************/

struct Device {
```c
    struct  Library dd_Library;
```
};


/****** Unit ********************************************************/

struct Unit {
```c
    struct  MsgPort unit_MsgPort;	/* queue for unprocessed messages */
```
					/* instance of msgport is recommended */
```c
    UBYTE   unit_flags;
    UBYTE   unit_pad;
    UWORD   unit_OpenCnt;		/* number of active opens */
```
};


#define UNITF_ACTIVE	(1<<0)
#define UNITF_INTASK	(1<<1)

#endif	/* EXEC_DEVICES_H */


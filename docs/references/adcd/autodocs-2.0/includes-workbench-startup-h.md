---
title: Includes/workbench/startup.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-workbench-startup-h
functions: []
libraries: []
---

# Includes/workbench/startup.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef WORKBENCH_STARTUP_H
#define WORKBENCH_STARTUP_H
/*
**	$Filename: workbench/startup.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.3 $
**	$Date: 90/07/11 $
**
**	workbench startup definitions
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include "exec/types.h"
#endif

#ifndef EXEC_PORTS_H
#include "exec/ports.h"
#endif

#ifndef LIBRARIES_DOS_H
#include "libraries/dos.h"
#endif

struct WBStartup {
```c
    struct Message	sm_Message;	/* a standard message structure */
    struct MsgPort *	sm_Process;	/* the process descriptor for you */
    BPTR		sm_Segment;	/* a descriptor for your code */
    LONG		sm_NumArgs;	/* the number of elements in ArgList */
    char *		sm_ToolWindow;	/* description of window */
    struct WBArg *	sm_ArgList;	/* the arguments themselves */
```
};

struct WBArg {
```c
    BPTR		wa_Lock;	/* a lock descriptor */
    BYTE *		wa_Name;	/* a string relative to that lock */
```
};

#endif	/* !WORKBENCH_STARTUP_H */


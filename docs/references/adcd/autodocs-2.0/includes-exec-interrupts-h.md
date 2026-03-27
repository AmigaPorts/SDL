---
title: Includes/exec/interrupts.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-exec-interrupts-h
functions: []
libraries: []
---

# Includes/exec/interrupts.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	EXEC_INTERRUPTS_H
#define	EXEC_INTERRUPTS_H
/*
**	$Filename: exec/interrupts.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.4 $
**	$Date: 90/05/10 $
**
**	Callback structures used by hardware & software interrupts
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_NODES_H
#include "exec/nodes.h"
#endif /* EXEC_NODES_H */

#ifndef EXEC_LISTS_H
#include "exec/lists.h"
#endif /* EXEC_LISTS_H */


struct Interrupt {
```c
    struct  Node is_Node;
    APTR    is_Data;		    /* server data segment  */
    VOID    (*is_Code)();	    /* server code entry    */
```
};


struct IntVector {		/* For EXEC use ONLY! */
```c
    APTR    iv_Data;
    VOID    (*iv_Code)();
    struct  Node *iv_Node;
```
};


struct SoftIntList {		/* For EXEC use ONLY! */
```c
    struct List sh_List;
    UWORD  sh_Pad;
```
};

#define SIH_PRIMASK (0xf0)

/* this is a fake INT definition, used only for AddIntServer and the like */
#define INTB_NMI	15
#define INTF_NMI	(1<<15)

#endif	/* EXEC_INTERRUPTS_H */


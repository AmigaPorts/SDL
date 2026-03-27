---
title: include/exec/interrupts.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-exec-interrupts-h
functions: []
libraries: []
---

# include/exec/interrupts.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	EXEC_INTERRUPTS_H
#define	EXEC_INTERRUPTS_H
/*
**	$VER: interrupts.h 39.1 (18.9.1992)
**	Includes Release 44.1
**
**	Callback structures used by hardware & software interrupts
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif /* EXEC_NODES_H */

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
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
#define INTF_NMI	(1L<<15)

#endif	/* EXEC_INTERRUPTS_H */


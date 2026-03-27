---
title: 21 Exec Tasks / Task Structure
manual: libraries
chapter: libraries
section: 21-exec-tasks-task-structure
functions: []
libraries: []
---

# 21 Exec Tasks / Task Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec maintains task context and state information in a task-control data
structure. Like most Exec structures, Task structures are dynamically
linked onto various task queues through the use of an embedded Exec list
[Node](libraries/23-list-structure-node-structure-definition.md) structure (see the "[Exec Lists and Queues](libraries/23-list-structure-node-structure-definition.md)" chapter).  Any task can
find its own task structure by calling [FindTask](libraries/21-exec-tasks-function-reference.md)(NULL).  The C-language
form of this structure is defined in the <exec/[tasks.h](autodocs-2.0/includes-exec-tasks-h.md)> include file:


```c
    struct Task  {
        struct Node tc_Node;
        UBYTE       tc_Flags;
        UBYTE       tc_State;
        BYTE        tc_IDNestCnt;   /* intr disabled nesting */
        BYTE        tc_TDNestCnt;   /* task disabled nesting */
        ULONG       tc_SigAlloc;    /* sigs allocated */
        ULONG       tc_SigWait;     /* sigs we are waiting for */
        ULONG       tc_SigRecvd;    /* sigs we have received */
        ULONG       tc_SigExcept;   /* sigs we will take excepts for */
        UWORD       tc_TrapAlloc;   /* traps allocated */
        UWORD       tc_TrapAble;    /* traps enabled */
        APTR        tc_ExceptData;  /* points to except data */
        APTR        tc_ExceptCode;  /* points to except code */
        APTR        tc_TrapData;    /* points to trap code */
        APTR        tc_TrapCode;    /* points to trap data */
        APTR        tc_SPReg;       /* stack pointer */
        APTR        tc_SPLower;     /* stack lower bound */
        APTR        tc_SPUpper;     /* stack upper bound + 2*/
        VOID      (*tc_Switch)();   /* task losing CPU */
        VOID      (*tc_Launch)();   /* task getting CPU */
        struct List tc_MemEntry;    /* allocated memory */
        APTR        tc_UserData;    /* per task data */
    };
```
A similar assembly code structure is available in the <exec/[tasks.i](autodocs-2.0/includes-exec-tasks-i.md)>
include file.

Most of these fields are not relevant for simple tasks; they are used by
Exec for state and administrative purposes.  A few fields, however, are
provided for the advanced programs that support higher level environments
(as in the case of processes) or require precise control (as in devices).
The following sections explain these fields in more detail.


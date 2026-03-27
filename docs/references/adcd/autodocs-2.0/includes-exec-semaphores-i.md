---
title: Includes/exec/semaphores.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-exec-semaphores-i
functions: [ObtainSemaphore]
libraries: [exec.library]
---

# Includes/exec/semaphores.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	EXEC_SEMAPHORES_I
EXEC_SEMAPHORES_I	SET	1
**
**	$Filename: exec/semaphores.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.6 $
**	$Date: 90/05/10 $
**
**	Definitions for locking functions.
**
**	(C) Copyright 1986-1999 Amiga, Inc.
**	    All Rights Reserved
**



```c
    IFND EXEC_NODES_I
    INCLUDE "exec/nodes.i"
    ENDC	; EXEC_NODES_I

    IFND EXEC_LISTS_I
    INCLUDE "exec/lists.i"
    ENDC	; EXEC_LISTS_I

    IFND EXEC_PORTS_I
    INCLUDE "exec/ports.i"
    ENDC	; EXEC_PORTS_I
```
*----------------------------------------------------------------
*
*   Signal Semaphore Structure
*
*----------------------------------------------------------------

** Private structure used by ObtainSemaphore()
 STRUCTURE  SSR,MLN_SIZE

    APTR    SSR_WAITER
    LABEL   SSR_SIZE
** Signal Semaphore data structure
 STRUCTURE  SS,LN_SIZE


    WORD    SS_NESTCOUNT
    STRUCT  SS_WAITQUEUE,MLH_SIZE
    STRUCT  SS_MULTIPLELINK,SSR_SIZE
    APTR    SS_OWNER
    WORD    SS_QUEUECOUNT
    LABEL   SS_SIZE
*----------------------------------------------------------------
*
*   Semaphore Structure (Procure/Vacate type)
*
*----------------------------------------------------------------


 STRUCTURE  SM,MP_SIZE

```c
    WORD    SM_BIDS	      ; number of bids for lock
    LABEL   SM_SIZE
```
*------ unions:

SM_LOCKMSG    EQU  MP_SIGTASK


	ENDC	; EXEC_SEMAPHORES_I

---

## See Also

- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)

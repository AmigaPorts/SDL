---
title: Includes/utility/hooks.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-utility-hooks-i
functions: []
libraries: []
---

# Includes/utility/hooks.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    IFND UTILITY_HOOKS_I
UTILITY_HOOKS_I SET 1
**
**	$Filename: utility/hooks.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.1 $
**	$Date: 90/07/12 $
**
**	callback hooks
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**		All Rights Reserved
**



    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

    IFND EXEC_NODES_I
    INCLUDE "exec/nodes.i"
    ENDC
; New Hook conventions
; A0 - pointer to hook itself
; A1 - pointer to parameter packed ("message")
; A2 - Hook specific address data ("object," e.g, gadget )

 STRUCTURE HOOK,MLN_SIZE
```c
    APTR	h_Entry			; assembler entry point
    APTR	h_SubEntry		; optional HLL entry point
    APTR	h_Data			; owner specific
```
 LABEL		h_SIZEOF


 ENDC


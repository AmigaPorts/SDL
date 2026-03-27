---
title: Includes/exec/devices.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-exec-devices-i
functions: []
libraries: []
---

# Includes/exec/devices.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	EXEC_DEVICES_I
EXEC_DEVICES_I	SET	1
**
**	$Filename: exec/devices.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.4 $
**	$Date: 90/05/10 $
**
**	Include file for use by Exec device drivers
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
**



```c
    IFND EXEC_LIBRARIES_I
    INCLUDE "exec/libraries.i"
    ENDC	; EXEC_LIBRARIES_I

    IFND EXEC_PORTS_I
    INCLUDE "exec/ports.i"
    ENDC	; EXEC_PORTS_I
```
*----------------------------------------------------------------
*
*   Device Data Structure
*
*----------------------------------------------------------------

 STRUCTURE  DD,LIB_SIZE


```c
    LABEL   DD_SIZE			; identical to library
```
*----------------------------------------------------------------
*
*   Suggested Unit Structure
*
*----------------------------------------------------------------

 STRUCTURE  UNIT,MP_SIZE		; queue for requests


    UBYTE   UNIT_FLAGS
    UBYTE   UNIT_pad
    UWORD   UNIT_OPENCNT
    LABEL   UNIT_SIZE
*------ UNIT_FLAG definitions:


```c
    BITDEF  UNIT,ACTIVE,0		; driver is active
    BITDEF  UNIT,INTASK,1		; running in driver's task
```
	ENDC	; EXEC_DEVICES_I


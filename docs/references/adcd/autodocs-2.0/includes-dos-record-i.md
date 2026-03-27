---
title: Includes/dos/record.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-dos-record-i
functions: [LockRecords, UnLockRecords]
libraries: [dos.library]
---

# Includes/dos/record.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND DOS_RECORD_I
DOS_RECORD_I SET 1
**
**	$Filename: dos/record.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.5 $
**	$Date: 90/07/12 $
**
**	include file for record locking
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**	    All Rights Reserved
**


     IFND  DOS_DOS_I
     INCLUDE "dos/dos.i"
     ENDC
* Modes for LockRecord/LockRecords()
REC_EXCLUSIVE		EQU	0
REC_EXCLUSIVE_IMMED	EQU	1
REC_SHARED		EQU	2
REC_SHARED_IMMED	EQU	3

* struct to be passed to LockRecords()/UnLockRecords()

 STRUCTURE RecordLock,0
	BPTR	rec_FH		; filehandle
	ULONG	rec_Offset	; offset in file
	ULONG	rec_Length	; length of file to be locked
	ULONG	rec_Mode	; Type of lock
 LABEL RecordLock_SIZEOF

	ENDC	; DOS_RECORD_I

---

## See Also

- [LockRecords — dos.library](../autodocs/dos.library.md#lockrecords)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

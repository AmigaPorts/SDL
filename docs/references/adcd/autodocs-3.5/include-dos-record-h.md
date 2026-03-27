---
title: include/dos/record.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-dos-record-h
functions: [LockRecords, UnLockRecords]
libraries: [dos.library]
---

# include/dos/record.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef DOS_RECORD_H
#define DOS_RECORD_H
/*
**
**	$VER: record.h 36.5 (12.7.1990)
**	Includes Release 44.1
**
**	include file for record locking
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**	    All Rights Reserved
**
*/

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

/* Modes for LockRecord/LockRecords() */
#define REC_EXCLUSIVE		0
#define REC_EXCLUSIVE_IMMED	1
#define REC_SHARED		2
#define REC_SHARED_IMMED	3

/* struct to be passed to LockRecords()/UnLockRecords() */

struct RecordLock {
	BPTR	rec_FH;		/* filehandle */
	ULONG	rec_Offset;	/* offset in file */
	ULONG	rec_Length;	/* length of file to be locked */
	ULONG	rec_Mode;	/* Type of lock */
};

#endif /* DOS_RECORD_H */

---

## See Also

- [LockRecords — dos.library](../autodocs/dos.library.md#lockrecords)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

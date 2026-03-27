---
title: dos.library/UnLockRecord
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-unlockrecord-2
functions: [LockRecord, LockRecords, UnLockRecord, UnLockRecords]
libraries: [dos.library]
---

# dos.library/UnLockRecord

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UnLockRecord -- Unlock a record (V36)

   SYNOPSIS
	success = UnLockRecord(fh,offset,length)
	D0		       D1   D2     D3

	[BOOL](autodocs-3.5/include-exec-types-h.md) UnLockRecord(BPTR,ULONG,ULONG)

   FUNCTION
	This releases the specified lock on a file.  Note that you must use
	the same filehandle you used to lock the record, and offset and length
	must be the same values used to lock it.  Every [LockRecord()](autodocs-3.5/dos-library-lockrecord-2.md) call must
	be balanced with an UnLockRecord() call.

   INPUTS
	fh      - File handle of locked file
	offset  - Record start position
	length  - Length of record in bytes

   RESULT
	success - Success or failure.

   BUGS
	See [LockRecord()](autodocs-3.5/dos-library-lockrecord-2.md)

   SEE ALSO
	[LockRecords()](autodocs-3.5/dos-library-lockrecords-2.md), [LockRecord()](autodocs-3.5/dos-library-lockrecord-2.md), [UnLockRecords()](autodocs-3.5/dos-library-unlockrecords-2.md)

---

## See Also

- [LockRecord — dos.library](../autodocs/dos.library.md#lockrecord)
- [LockRecords — dos.library](../autodocs/dos.library.md#lockrecords)
- [UnLockRecord — dos.library](../autodocs/dos.library.md#unlockrecord)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

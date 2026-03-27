---
title: dos.library/LockRecords
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-lockrecords-2
functions: [LockRecord, UnLockRecord, UnLockRecords]
libraries: [dos.library]
---

# dos.library/LockRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LockRecords -- [Lock](autodocs-3.5/dos-library-lock-2.md) a series of records (V36)

   SYNOPSIS
	success = LockRecords(record_array,timeout)
	D0                       D1           D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) LockRecords(struct [RecordLock](autodocs-3.5/include-dos-record-h.md) *,ULONG)

   FUNCTION
	This locks several records within a file for exclusive access.
	Timeout is how long to wait in ticks for the records to be available.
	The wait is applied to each attempt to lock each record in the list.
	It is recommended that you always lock a set of records in the same
	order to reduce possibilities of deadlock.

	The array of [RecordLock](autodocs-3.5/include-dos-record-h.md) structures is terminated by an entry with
	rec_FH of NULL.

   INPUTS
	record_array - [List](autodocs-3.5/include-exec-lists-h.md) of records to be locked
	timeout      - Timeout interval.  0 is legal

   RESULT
	success      - Success or failure

   BUGS
	See [LockRecord()](autodocs-3.5/dos-library-lockrecord-2.md)

   SEE ALSO
	[LockRecord()](autodocs-3.5/dos-library-lockrecord-2.md), [UnLockRecord()](autodocs-3.5/dos-library-unlockrecord-2.md), [UnLockRecords()](autodocs-3.5/dos-library-unlockrecords-2.md)

---

## See Also

- [LockRecord — dos.library](../autodocs/dos.library.md#lockrecord)
- [UnLockRecord — dos.library](../autodocs/dos.library.md#unlockrecord)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

---
title: dos.library/UnLockRecords
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-unlockrecords-2
functions: [LockRecord, LockRecords, UnLockRecord, UnLockRecords]
libraries: [dos.library]
---

# dos.library/UnLockRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UnLockRecords -- Unlock a list of records (V36)

   SYNOPSIS
	success = UnLockRecords(record_array)
	D0		             D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) UnLockRecords(struct [RecordLock](autodocs-3.5/include-dos-record-h.md) *)

   FUNCTION
	This releases an array of record locks obtained using [LockRecords](autodocs-3.5/dos-library-lockrecords-2.md).
	You should NOT modify the record_array while you have the records
	locked.  Every [LockRecords()](autodocs-3.5/dos-library-lockrecords-2.md) call must be balanced with an
	UnLockRecords() call.

   INPUTS
	record_array - [List](autodocs-3.5/include-exec-lists-h.md) of records to be unlocked

   RESULT
	success      - Success or failure.

   BUGS
	See [LockRecord()](autodocs-3.5/dos-library-lockrecord-2.md)

   SEE ALSO
	[LockRecords()](autodocs-3.5/dos-library-lockrecords-2.md), [LockRecord()](autodocs-3.5/dos-library-lockrecord-2.md), [UnLockRecord()](autodocs-3.5/dos-library-unlockrecord-2.md)

---

## See Also

- [LockRecord — dos.library](../autodocs/dos.library.md#lockrecord)
- [LockRecords — dos.library](../autodocs/dos.library.md#lockrecords)
- [UnLockRecord — dos.library](../autodocs/dos.library.md#unlockrecord)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

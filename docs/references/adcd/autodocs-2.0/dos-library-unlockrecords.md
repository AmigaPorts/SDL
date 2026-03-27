---
title: dos.library/UnLockRecords
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-unlockrecords
functions: [LockRecord, LockRecords, UnLockRecord, UnLockRecords]
libraries: [dos.library]
---

# dos.library/UnLockRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UnLockRecords -- Unlock a list of records (V36)
```
SYNOPSIS

```c
    success = UnLockRecords(record_array)
    D0                           D1

    BOOL UnLockRecords(struct [RecordLock](autodocs-2.0/includes-dos-record-h.md) *)
```
FUNCTION

```c
    This releases an array of record locks obtained using [LockRecords](autodocs-2.0/dos-library-lockrecords.md).
    You should NOT modify the record_array while you have the records
    locked.  Every [LockRecords()](autodocs-2.0/dos-library-lockrecords.md) call must be balanced with an
    UnLockRecords() call.
```
INPUTS

```c
    record_array - [List](autodocs-2.0/includes-exec-lists-h.md) of records to be unlocked
```
RESULT

    success      - Success or failure.
BUGS

```c
    See [LockRecord()](autodocs-2.0/dos-library-lockrecord.md)
```
SEE ALSO

```c
    [LockRecords()](autodocs-2.0/dos-library-lockrecords.md), [LockRecord()](autodocs-2.0/dos-library-lockrecord.md), [UnLockRecord()](autodocs-2.0/dos-library-unlockrecord.md)
```

---

## See Also

- [LockRecord — dos.library](../autodocs/dos.library.md#lockrecord)
- [LockRecords — dos.library](../autodocs/dos.library.md#lockrecords)
- [UnLockRecord — dos.library](../autodocs/dos.library.md#unlockrecord)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

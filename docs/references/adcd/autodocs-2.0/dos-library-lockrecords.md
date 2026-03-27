---
title: dos.library/LockRecords
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-lockrecords
functions: [LockRecord, UnLockRecord, UnLockRecords]
libraries: [dos.library]
---

# dos.library/LockRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LockRecords -- Lock a series of records (V36)
```
SYNOPSIS

```c
    success = LockRecords(record_array,timeout)
    D0                       D1           D2

    BOOL LockRecords(struct [RecordLock](autodocs-2.0/includes-dos-record-h.md) *,ULONG)
```
FUNCTION

```c
    This locks several records within a file for exclusive access.
    Timeout is how long to wait in ticks for the records to be available.
    The wait is applied to each attempt to lock each record in the list.
    It is recommended that you always lock a set of records in the same
    order to reduce possibilities of deadlock.

    The array of [RecordLock](autodocs-2.0/includes-dos-record-h.md) structures is terminated by an entry with
    rec_FH of NULL.
```
INPUTS

```c
    record_array - [List](autodocs-2.0/includes-exec-lists-h.md) of records to be locked
    timeout      - Timeout interval.  0 is legal
```
RESULT

    success      - Success or failure
BUGS

```c
    See [LockRecord()](autodocs-2.0/dos-library-lockrecord.md)
```
SEE ALSO

```c
    [LockRecord()](autodocs-2.0/dos-library-lockrecord.md), [UnLockRecord()](autodocs-2.0/dos-library-unlockrecord.md), [UnLockRecords()](autodocs-2.0/dos-library-unlockrecords.md)
```

---

## See Also

- [LockRecord — dos.library](../autodocs/dos.library.md#lockrecord)
- [UnLockRecord — dos.library](../autodocs/dos.library.md#unlockrecord)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

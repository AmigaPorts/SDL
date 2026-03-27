---
title: dos.library/LockRecord
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-lockrecord
functions: [LockRecord, LockRecords, UnLockRecord, UnLockRecords]
libraries: [dos.library]
---

# dos.library/LockRecord

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LockRecord -- Locks a portion of a file (V36)
```
SYNOPSIS

```c
    success = LockRecord(fh,offset,length,mode,timeout)
    D0                   D1   D2     D3    D4    D5

    ULONG LockRecord(BPTR,ULONG,ULONG,ULONG,ULONG)
```
FUNCTION

```c
    This locks a portion of a file for exclusive access.  Timeout is how
    long to wait in ticks (1/50 sec) for the record to be available.

    Valid modes are:
            REC_EXCLUSIVE
            REC_EXCLUSIVE_IMMED
            REC_SHARED
            REC_SHARED_IMMED
    For the IMMED modes, the timeout is ignored.

    Record locks are tied to the filehandle used to create them.  The
    same filehandle can get any number of exclusive locks on the same
    record, for example.  These are cooperative locks, they only
    affect other people calling LockRecord().
```
INPUTS

    fh      - File handle for which to lock the record
    offset  - Record start position
    length  - Length of record in bytes
    mode    - Type of lock requester
    timeout - Timeout interval in ticks.  0 is legal.
RESULT

    success - Success or failure
BUGS

```c
    In 2.0 through 2.02 (V36), LockRecord() only worked in the ramdisk.
    Attempting to lock records on the disk filesystem causes a crash.
    This was fixed for V37.
```
SEE ALSO

```c
    [LockRecords()](autodocs-2.0/dos-library-lockrecords.md), [UnLockRecord()](autodocs-2.0/dos-library-unlockrecord.md), [UnLockRecords()](autodocs-2.0/dos-library-unlockrecords.md)
```

---

## See Also

- [LockRecord — dos.library](../autodocs/dos.library.md#lockrecord)
- [LockRecords — dos.library](../autodocs/dos.library.md#lockrecords)
- [UnLockRecord — dos.library](../autodocs/dos.library.md#unlockrecord)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

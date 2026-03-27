---
title: dos.library/UnLockRecord
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-unlockrecord
functions: [LockRecord, LockRecords, UnLockRecord, UnLockRecords]
libraries: [dos.library]
---

# dos.library/UnLockRecord

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UnLockRecord -- Unlock a record (V36)
```
SYNOPSIS

```c
    success = UnLockRecord(fh,offset,length)
    D0                     D1   D2     D3

    BOOL UnLockRecord(BPTR,ULONG,ULONG)
```
FUNCTION

```c
    This releases the specified lock on a file.  Note that you must use
    the same filehandle you used to lock the record, and offset and length
    must be the same values used to lock it.  Every [LockRecord()](autodocs-2.0/dos-library-lockrecord.md) call must
    be balanced with an UnLockRecord() call.
```
INPUTS

    fh      - File handle of locked file
    offset  - Record start position
    length  - Length of record in bytes
RESULT

    success - Success or failure.
BUGS

```c
    See [LockRecord()](autodocs-2.0/dos-library-lockrecord.md)
```
SEE ALSO

```c
    [LockRecords()](autodocs-2.0/dos-library-lockrecords.md), [LockRecord()](autodocs-2.0/dos-library-lockrecord.md), [UnLockRecords()](autodocs-2.0/dos-library-unlockrecords.md)
```

---

## See Also

- [LockRecord — dos.library](../autodocs/dos.library.md#lockrecord)
- [LockRecords — dos.library](../autodocs/dos.library.md#lockrecords)
- [UnLockRecord — dos.library](../autodocs/dos.library.md#unlockrecord)
- [UnLockRecords — dos.library](../autodocs/dos.library.md#unlockrecords)

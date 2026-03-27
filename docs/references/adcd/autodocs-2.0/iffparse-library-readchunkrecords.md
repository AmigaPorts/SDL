---
title: iffparse.library/ReadChunkRecords
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-readchunkrecords
functions: [ParseIFF, ReadChunkBytes, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.library/ReadChunkRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReadChunkRecords -- Read record elements from the current chunk into
                        a buffer.
SYNOPSIS

```c
    actual = ReadChunkRecords (iff, buf, recsize, numrec)
      d0                       a0   a1     d0       d1

    LONG             actual;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    UBYTE            *buf;
    LONG             recsize, numrec;
```
FUNCTION

```c
    Reads records from the current chunk into buffer.  Truncates attempts
    to read past end of chunk (only whole records are read; remaining
    bytes that are not of a whole record size are left unread and
    available for [ReadChunkBytes()](autodocs-2.0/iffparse-library-readchunkbytes.md)).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    buf     - pointer to buffer area to receive data.
    recsize - size of data records to read.
    numrec  - number of data records to read.
```
RESULT

```c
    actual  - (positive) number of whole records read if successful or a
              (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [ReadChunkBytes()](autodocs-2.0/iffparse-library-readchunkbytes.md), [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md), [WriteChunkRecords()](autodocs-2.0/iffparse-library-writechunkrecords.md)
```

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)

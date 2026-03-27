---
title: iffparse.library/WriteChunkRecords
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-writechunkrecords
functions: [ReadChunkBytes, WriteChunkBytes]
libraries: [iffparse.library]
---

# iffparse.library/WriteChunkRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WriteChunkRecords -- Write records from a buffer to the current
                         chunk.
SYNOPSIS

```c
    error = WriteChunkRecords (iff, buf, recsize, numrec)
     d0                        a0   a1     d0      d1

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    UBYTE            *buf;
    LONG             recsize, numrec;
```
FUNCTION

```c
    Writes record elements from the buffer into the top chunk.  This
    function operates much like [ReadChunkBytes()](autodocs-2.0/iffparse-library-readchunkbytes.md).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    buf     - pointer to buffer area containing data.
    recsize - size of data records to write.
    numrec  - number of data records to write.
```
RESULT

```c
    error   - (positive) number of whole records written if successful
              or a (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [WriteChunkBytes()](autodocs-2.0/iffparse-library-writechunkbytes.md)
```

---

## See Also

- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)

---
title: iffparse.library/ReadChunkBytes
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-readchunkbytes
functions: [ParseIFF, ReadChunkRecords, WriteChunkBytes]
libraries: [iffparse.library]
---

# iffparse.library/ReadChunkBytes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReadChunkBytes -- Read bytes from the current chunk into a buffer.
SYNOPSIS

```c
    actual = ReadChunkBytes (iff, buf, size)
      d0                     a0   a1    d0

    LONG             actual;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    UBYTE            *buf;
    LONG             size;
```
FUNCTION

```c
    Reads the [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) stream into the buffer for the specified number
    of bytes.  Reads are limited to the size of the current chunk and
    attempts to read past the end of the chunk will truncate.  Function
    returns positive number of bytes read or a negative error code.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    buf     - pointer to buffer area to receive data.
    size    - number of bytes to read.
```
RESULT

```c
    actual  - (positive) number of bytes read if successful or a
              (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [ReadChunkRecords()](autodocs-2.0/iffparse-library-readchunkrecords.md), [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md), [WriteChunkBytes()](autodocs-2.0/iffparse-library-writechunkbytes.md)
```

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [ReadChunkRecords — iffparse.library](../autodocs/iffparse.library.md#readchunkrecords)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)

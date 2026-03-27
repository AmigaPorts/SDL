---
title: iffparse.library/WriteChunkBytes
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-writechunkbytes
functions: [PopChunk, PushChunk, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.library/WriteChunkBytes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WriteChunkBytes -- Write data from a buffer into the current chunk.
SYNOPSIS

```c
    error = WriteChunkBytes (iff, buf, size)
     d0                      a0   a1    d0

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    UBYTE            *buf;
    LONG             size;
```
FUNCTION

    Writes "size" bytes from the specified buffer into the current chunk.
    If the current chunk was pushed with IFFSIZE_UNKNOWN, the size of the
    chunk gets increased by the size of the buffer written.  If the size
    was specified for this chunk, attempts to write past the end of the
    chunk will be truncated.
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    buf     - pointer to buffer area with bytes to be written.
    size    - number of bytes to write.
```
RESULT

```c
    error   - (positive) number of bytes written if successful or a
              (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PushChunk()](autodocs-2.0/iffparse-library-pushchunk.md), [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md), [WriteChunkRecords()](autodocs-2.0/iffparse-library-writechunkrecords.md)
```

---

## See Also

- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)

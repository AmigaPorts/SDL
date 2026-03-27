---
title: iffparse.library/PushChunk
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-pushchunk
functions: [PopChunk, WriteChunkBytes, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.library/PushChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    PushChunk -- Push a new context node on the context stack.
SYNOPSIS

```c
    error = PushChunk (iff, type, id, size)
     d0                a0    d0   d1   d2

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             type, id, size;
```
FUNCTION

    Pushes a new context node on the context stack by reading it from the
    stream if this is a read file, or by creating it from the passed
    parameters if this is a write file.  Normally this function is only
    called in write mode, where the type and id codes specify the new
    chunk to create.  If this is a leaf chunk, i.e. a local chunk inside
    a FORM or PROP chunk, then the type argument is ignored.  If the size
    is specified then the chunk writing functions will enforce this size.
    If the size is given as IFFSIZE_UNKNOWN, the chunk will expand to
    accommodate whatever is written into it.
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    type    - chunk type specifier (ex. ILBM) (ignored for read mode or
              leaf chunks).
    id      - chunk id specifier (ex. CMAP) (ignored for read mode).
    size    - size of the chunk to create or IFFSIZE_UNKNOWN (ignored for
              read mode).
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md), [WriteChunkRecords()](autodocs-2.0/iffparse-library-writechunkrecords.md), [WriteChunkBytes()](autodocs-2.0/iffparse-library-writechunkbytes.md)
```

---

## See Also

- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)

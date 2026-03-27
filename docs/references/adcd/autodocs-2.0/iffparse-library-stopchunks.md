---
title: iffparse.library/StopChunks
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-stopchunks
functions: [PropChunk, PropChunks, StopChunk]
libraries: [iffparse.library]
---

# iffparse.library/StopChunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    StopChunks -- Declare many stop chunks at once.
SYNOPSIS

```c
    error = StopChunks (iff, list, n)
     d0                 a0    a1  d0

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             *list;
    LONG             n;
```
FUNCTION

```c
    (is to [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md) as [PropChunks()](autodocs-2.0/iffparse-library-propchunks.md) is to PropChunk().)
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    list    - pointer to array of longword chunk types and identifiers.
    n       - number of chunks to declare.
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md)
```

---

## See Also

- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)

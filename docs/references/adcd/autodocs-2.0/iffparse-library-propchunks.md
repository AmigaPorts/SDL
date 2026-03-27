---
title: iffparse.library/PropChunks
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-propchunks
functions: [PropChunk, PropChunks]
libraries: [iffparse.library]
---

# iffparse.library/PropChunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    PropChunks -- Declare many property chunks at once.
SYNOPSIS

```c
    error = PropChunks (iff, list, n)
     d0                 a0    a1  d0

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             *list;
    LONG             n;
```
FUNCTION

```c
    Declares multiple property chunks from a list.  The list argument is
    a pointer to an array of long words arranged in pairs, and has the
    following format:

            TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

    The argument n is the number of pairs.  PropChunks() just calls
    [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md) n times.
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
    [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md)
```

---

## See Also

- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)

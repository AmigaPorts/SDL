---
title: iffparse.library/CollectionChunks
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-collectionchunks
functions: [CollectionChunk, CollectionChunks]
libraries: [iffparse.library]
---

# iffparse.library/CollectionChunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CollectionChunks -- Declare many collection chunks at once.
SYNOPSIS

```c
    error = CollectionChunks (iff, list, n)
     d0                       a0    a1  d0

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             *list;
    LONG             n;
```
FUNCTION

```c
    Declares multiple collection chunks from a list.  The list argument
    is a pointer to an array of long words arranged in pairs.  The format
    for the list is as follows:

            TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

    The argument n is the number of pairs.  CollectionChunks() just calls
    [CollectionChunk()](autodocs-2.0/iffparse-library-collectionchunk.md) n times.
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
    [CollectionChunk()](autodocs-2.0/iffparse-library-collectionchunk.md)
```

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [CollectionChunks — iffparse.library](../autodocs/iffparse.library.md#collectionchunks)

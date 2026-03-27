---
title: iffparse.library/CollectionChunk
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-collectionchunk
functions: [CollectionChunks, FindCollection, PropChunk]
libraries: [iffparse.library]
---

# iffparse.library/CollectionChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CollectionChunk -- declare a chunk type for collection.
SYNOPSIS

```c
    error = CollectionChunk (iff, type, id)
     d0                      a0    d0   d1

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             type;
    LONG             id;
```
FUNCTION

```c
    Installs an entry handler for chunks with the given type and id so
    that the contents of those chunks will be stored as they are
    encountered.  This is like [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md) except that more than one
    chunk of this type can be stored in lists which can be returned by
    [FindCollection()](autodocs-2.0/iffparse-library-findcollection.md).  The storage of these chunks still follows the
    property chunk scoping rules for IFF files so that at any given
    point, stored collection chunks will be valid in the current context.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct (does not need to be open).
    type    - type code for the chunk to declare (ex. "ILBM").
    id      - identifier for the chunk to declare (ex. "CRNG").
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CollectionChunks()](autodocs-2.0/iffparse-library-collectionchunks.md), [FindCollection()](autodocs-2.0/iffparse-library-findcollection.md), [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md)
```

---

## See Also

- [CollectionChunks — iffparse.library](../autodocs/iffparse.library.md#collectionchunks)
- [FindCollection — iffparse.library](../autodocs/iffparse.library.md#findcollection)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)

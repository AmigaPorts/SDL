---
title: iffparse.library/FindCollection
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-findcollection
functions: [CollectionChunk, CollectionChunks]
libraries: [iffparse.library]
---

# iffparse.library/FindCollection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindCollection -- Get a pointer to the current list of collection
                      items.
SYNOPSIS

```c
    ci = FindCollection (iff, type, id)
    d0                   a0    d0   d1

    struct [CollectionItem](autodocs-2.0/includes-libraries-iffparse-h.md)    *ci;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)  *iff;
    LONG                    type, id;
```
FUNCTION

```c
    Returns a pointer to a list of [CollectionItem](autodocs-2.0/includes-libraries-iffparse-h.md) structures for each of
    the collection chunks of the given type encountered so far in the
    course of parsing this IFF file.  The items appearing first in the
    list will be the ones encountered most recently.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    type    - type code to search for.
    id      - identifier code to search for.
```
RESULT

    ci      - pointer to last collection chunk encountered with
              links to previous ones.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CollectionChunk()](autodocs-2.0/iffparse-library-collectionchunk.md), [CollectionChunks()](autodocs-2.0/iffparse-library-collectionchunks.md)
```

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [CollectionChunks — iffparse.library](../autodocs/iffparse.library.md#collectionchunks)

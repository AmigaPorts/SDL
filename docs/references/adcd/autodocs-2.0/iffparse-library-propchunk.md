---
title: iffparse.library/PropChunk
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-propchunk
functions: [CollectionChunk, FindProp, PropChunks]
libraries: [iffparse.library]
---

# iffparse.library/PropChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    PropChunk -- Specify a property chunk to store.
SYNOPSIS

```c
    error = PropChunk (iff, type, id)
     d0                a0    d0   d1

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             type;
    LONG             id;
```
FUNCTION

```c
    Installs an entry handler for chunks with the given type and ID so
    that the contents of those chunks will be stored as they are
    encountered.  The storage of these chunks follows the property chunk
    scoping rules for IFF files so that at any given point, a stored
    property chunk returned by [FindProp()](autodocs-2.0/iffparse-library-findprop.md) will be the valid property for
    the current context.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct (does not need to be open).
    type    - type code for the chunk to declare (ex. "ILBM").
    id      - identifier for the chunk to declare (ex. "CMAP").
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PropChunks()](autodocs-2.0/iffparse-library-propchunks.md), [FindProp()](autodocs-2.0/iffparse-library-findprop.md), [CollectionChunk()](autodocs-2.0/iffparse-library-collectionchunk.md)
```

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)

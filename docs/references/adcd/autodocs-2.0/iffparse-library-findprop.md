---
title: iffparse.library/FindProp
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-findprop
functions: [ParseIFF, PropChunk, PropChunks]
libraries: [iffparse.library]
---

# iffparse.library/FindProp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindProp -- Search for a stored property chunk.
SYNOPSIS

```c
    sp = FindProp (iff, type, id)
    d0             a0    d0   d1

    struct [StoredProperty](autodocs-2.0/includes-libraries-iffparse-h.md)     *sp;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)  *iff;
    LONG                    type, id;
```
FUNCTION

```c
    Searches for the stored property which is valid in the given context.
    Property chunks are automatically stored by [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) when
    pre-declared by [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md) or [PropChunks()](autodocs-2.0/iffparse-library-propchunks.md).  The [StoredProperty](autodocs-2.0/includes-libraries-iffparse-h.md)
    struct, if found, contains a pointer to a data buffer containing the
    contents of the stored property.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    type    - type code for chunk to search for (ex. "ILBM").
    id      - identifier code for chunk to search for (ex. "CMAP").
```
RESULT

    sp      - pointer to stored property, if found, or NULL if none
              found.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md), [PropChunks()](autodocs-2.0/iffparse-library-propchunks.md)
```

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)

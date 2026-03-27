---
title: iffparse.library/ParentChunk
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-parentchunk
functions: [CurrentChunk]
libraries: [iffparse.library]
---

# iffparse.library/ParentChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ParentChunk -- Get the nesting context node for the given chunk.
SYNOPSIS

```c
    parent = ParentChunk (cn)
      d0                  a0

    struct [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md) *parent, *cn;
```
FUNCTION

```c
    Returns a context node for the chunk containing the chunk for the
    given context node.  This function effectively moves down the context
    stack into previously pushed contexts.  For example, to get a
    [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md) pointer for the enclosing FORM chunk while reading a data
    chunk, use: ParentChunk (CurrentChunk (iff)) to find this pointer.
    The [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md) structure contains information on the type of chunk
    and its size.
```
INPUTS

    cn      - pointer to a context node.
RESULT

    parent  - pointer to the enclosing context node or NULL if none.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CurrentChunk()](autodocs-2.0/iffparse-library-currentchunk.md)
```

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)

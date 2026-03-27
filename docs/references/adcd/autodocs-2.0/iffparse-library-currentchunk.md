---
title: iffparse.library/CurrentChunk
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-currentchunk
functions: [ParentChunk, ParseIFF, PopChunk, PushChunk]
libraries: [iffparse.library]
---

# iffparse.library/CurrentChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CurrentChunk -- Get context node for current chunk.
SYNOPSIS

```c
    top = CurrentChunk (iff)
    d0                  a0

    struct [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md)        *top;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)  *iff;
```
FUNCTION

```c
    Returns top context node for the given [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.  The top
    context node corresponds to the chunk most recently pushed on the
    stack, which is the chunk where the stream is currently positioned.
    The [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md) structure contains information on the type of chunk
    currently being parsed (or written), its size and the current
    position within the chunk.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
```
RESULT

    top     - pointer to top context node or NULL if none.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PushChunk()](autodocs-2.0/iffparse-library-pushchunk.md), [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md), [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md), [ParentChunk()](autodocs-2.0/iffparse-library-parentchunk.md)
```

---

## See Also

- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

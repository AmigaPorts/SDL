---
title: iffparse.library/PopChunk
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-popchunk
functions: [PushChunk]
libraries: [iffparse.library]
---

# iffparse.library/PopChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    PopChunk -- Pop top context node off context stack.
SYNOPSIS

```c
    error = PopChunk (iff)
     d0               a0

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
```
FUNCTION

    Pops top context chunk and frees all associated local context items.
    The function is normally called only for writing files and signals
    the end of a chunk.
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PushChunk()](autodocs-2.0/iffparse-library-pushchunk.md)
```

---

## See Also

- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

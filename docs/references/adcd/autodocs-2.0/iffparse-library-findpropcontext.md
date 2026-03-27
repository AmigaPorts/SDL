---
title: iffparse.library/FindPropContext
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-findpropcontext
functions: [CurrentChunk, ParentChunk, StoreItemInContext]
libraries: [iffparse.library]
---

# iffparse.library/FindPropContext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindPropContext -- Get the property context for the current state.
SYNOPSIS

```c
    cn = FindPropContext (iff)
    d0                    a0

    struct [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md)        *cn;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)  *iff;
```
FUNCTION

```c
    Locates the context node which would be the scoping chunk for
    properties in the current parsing state.  (Huh?)  This is used for
    locating the proper scoping context for property chunks i.e. the
    scope from which a property would apply.  This is usually the FORM
    or LIST with the highest precedence in the context stack.

    If you don't understand this, read the IFF spec a couple more times.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
```
RESULT

```c
    cn      - [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md) of property scoping chunk.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CurrentChunk()](autodocs-2.0/iffparse-library-currentchunk.md), [ParentChunk()](autodocs-2.0/iffparse-library-parentchunk.md), [StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md)
```

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)

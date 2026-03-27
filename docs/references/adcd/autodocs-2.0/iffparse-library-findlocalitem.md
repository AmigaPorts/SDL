---
title: iffparse.library/FindLocalItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-findlocalitem
functions: [StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/FindLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindLocalItem -- Return a local context item from the context stack.
SYNOPSIS

```c
    lci = FindLocalItem (iff, type, id, ident)
    d0                   a0    d0   d1   d2

    struct [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md)   *lci;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)  *iff;
    LONG                    type, id, ident;
```
FUNCTION

```c
    Searches the context stack of the given [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct for a local
    context item which matches the given ident, type and id.  This
    function searches the context stack from the most current context
    backwards, so that the item found (if any) will be the one with
    greatest precedence in the context stack.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    type    - type code to search for.
    id      - ID code to search for.
    ident   - ident code for the class of context item to search for
              (ex. "exhd" -- exit handler).
```
RESULT

    lci     - pointer local context item if found, or NULL if nothing
              matched.
EXAMPLE

NOTES

BUGS

    It really should have some sort of wildcarding capability.
SEE ALSO

```c
    [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md)
```

---

## See Also

- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)

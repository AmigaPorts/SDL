---
title: iffparse.library/StoreItemInContext
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-storeitemincontext
functions: [StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/StoreItemInContext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    StoreItemInContext -- Store local context item in given context node.
SYNOPSIS

```c
    StoreItemInContext (iff, item, cn)
                        a0    a1   a2

    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)  *iff;
    struct [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md)   *item;
    struct [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md)        *cn;
```
FUNCTION

```c
    Adds the [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) to the list of items for the given context
    node.  If an LCI with the same Type, ID, and Ident is already
    present in the [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md), it will be purged and replaced with the
    new one.  This is a raw form of [StoreLocalItem](autodocs-2.0/iffparse-library-storelocalitem.md).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct for this context.
    item    - pointer to a [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) to be stored.
    cn      - pointer to context node in which to store item.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md)
```

---

## See Also

- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)

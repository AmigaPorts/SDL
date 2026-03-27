---
title: iffparse.library/AllocLocalItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-alloclocalitem
functions: [FreeLocalItem, LocalItemData, SetLocalItemPurge, StoreItemInContext, StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/AllocLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AllocLocalItem -- Create a local context item structure.
SYNOPSIS

```c
    item = AllocLocalItem (type, id, ident, usize)
     d0                     d0   d1   d2     d3

    struct [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) *item;
    LONG                    type, id, ident, usize;
```
FUNCTION

```c
    Allocates and initializes a [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) structure with "usize"
    bytes of associated user data.  This is the only supported way to
    create such an item.  The user data can be accessed with the
    [LocalItemData](autodocs-2.0/iffparse-library-localitemdata.md) function.  An item created with this function
    automatically has its purge vectors set up correctly to dispose of
    itself and its associated user data area.  Any additional cleanup
    should be done with a user-supplied purge vector.
```
INPUTS

    type,id - additional longword identification values.
    ident   - longword identifier for class of context item.
    usize   - number of bytes of user data to allocate for this item.
RESULT

```c
    item    - pointer to initialized [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) or NULL if the
              allocation failed.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md), [LocalItemData()](autodocs-2.0/iffparse-library-localitemdata.md), [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md),
    [StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md), [SetLocalItemPurge()](autodocs-2.0/iffparse-library-setlocalitempurge.md)
```

---

## See Also

- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)
- [LocalItemData — iffparse.library](../autodocs/iffparse.library.md#localitemdata)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)

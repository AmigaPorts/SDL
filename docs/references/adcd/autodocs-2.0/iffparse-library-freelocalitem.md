---
title: iffparse.library/FreeLocalItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-freelocalitem
functions: [AllocLocalItem, FreeLocalItem, SetLocalItemPurge]
libraries: [iffparse.library]
---

# iffparse.library/FreeLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeLocalItem -- Deallocate a local context item structure.
SYNOPSIS

```c
    FreeLocalItem (lci)
                   a0

    struct [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) *lci;
```
FUNCTION

```c
    Frees the memory for the local context item and any associated user
    memory as allocated with [AllocLocalItem](autodocs-2.0/iffparse-library-alloclocalitem.md).  User purge vectors should
    call this function after they have freed any other resources
    associated with this item.

    Note that FreeLocalItem() does NOT call the custom purge vector set
    up through SetLocalItemPurge(); all it does is free the local context
    item.  (This implies that your custom purge vector would want to call
    this to ultimately free the LocalContextItem.)  (This description
    still seems muddy; how to clear it up?)
```
INPUTS

```c
    lci     - pointer to [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) created with [AllocLocalItem](autodocs-2.0/iffparse-library-alloclocalitem.md).
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [AllocLocalItem()](autodocs-2.0/iffparse-library-alloclocalitem.md)
```

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)

---
title: iffparse.library/SetLocalItemPurge
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-setlocalitempurge
functions: [AllocLocalItem, FreeLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/SetLocalItemPurge

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetLocalItemPurge -- Set purge vector for a local context item.
SYNOPSIS

```c
    SetLocalItemPurge (item, purgehook)
                        a0      a1

    struct [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md)   *item;
    struct [Hook](autodocs-2.0/includes-utility-hooks-h.md)            *purgehook;
```
FUNCTION

```c
    Sets a local context item to use a client-supplied cleanup (purge)
    vector for disposal when its context is popped.  The purge vector
    will be called when the [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md) containing this local item is
    popped off the context stack and is about to be deleted itself.  If
    the purge vector has not been set, the parser will use [FreeLocalItem](autodocs-2.0/iffparse-library-freelocalitem.md)
    to delete the item, but if this function is used to set the purge
    vector, the supplied vector will be called with the following
    arguments:

            A0:     pointer to purgehook.
            A2:     pointer to [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) to be freed.
            A1:     pointer to a LONG containing the value
                    IFFCMD_PURGELCI.

    The user purge vector is then responsible for calling [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md)
    as part of its own cleanup.  Although the purge vector can return a
    value, it will be ignored -- purge vectors must always work (best to
    return 0, though).
```
INPUTS

```c
    item      - pointer to local context item.
    purgehook - pointer to a [Hook](autodocs-2.0/includes-utility-hooks-h.md) structure.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [AllocLocalItem()](autodocs-2.0/iffparse-library-alloclocalitem.md), [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md), [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md)
```

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)

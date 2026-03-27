---
title: iffparse.library/StoreLocalItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-storelocalitem
functions: [EntryHandler, ExitHandler, FindLocalItem, FreeIFF, StoreItemInContext]
libraries: [iffparse.library]
---

# iffparse.library/StoreLocalItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    StoreLocalItem -- Insert a local context item into the context stack.
SYNOPSIS

```c
    error = StoreLocalItem (iff, item, position)
     d0                     a0    a1      d0

    LONG                    error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)  *iff;
    struct [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md)   *item;
    LONG                    position;
```
FUNCTION

```c
    Adds the local context item to the list of items for one of the
    context nodes on the context stack and purges any other item in the
    same context with the same ident, type and id.  The position argument
    determines where in the stack to add the item:

    IFFSLI_ROOT:
            Add item to list at root (default) stack position.
    IFFSLI_TOP:
            Add item to the top (current) context node.
    IFFSLI_PROP:
            Add element in top property context.  Top property context is
            either the top FORM chunk, or the top LIST chunk, whichever
            is closer to the top of the stack.

    Items added to the root context, or added to the top context before
    the [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) has been opened or after it has been closed, are put in
    the default context.  That is, they will be the local items found
    only after all other context nodes have been searched.  Items in the
    default context are also immune to being purged until the [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)
    struct itself is deleted with [FreeIFF()](autodocs-2.0/iffparse-library-freeiff.md).  This means that handlers
    installed in the root context will still be there after an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)
    struct has been opened and closed.  (Note that this implies that
    items stored in a higher context will be deleted when that context
    ends.)
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    item    - pointer to [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md) struct to insert.
    position- where to store the item (IFFSLI_ROOT, _TOP or _PROP).
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FindLocalItem()](autodocs-2.0/iffparse-library-findlocalitem.md), [StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md), [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md), [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md)
```

---

## See Also

- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [FindLocalItem — iffparse.library](../autodocs/iffparse.library.md#findlocalitem)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)

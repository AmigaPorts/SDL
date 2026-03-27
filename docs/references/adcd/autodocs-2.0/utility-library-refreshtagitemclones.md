---
title: utility.library/RefreshTagItemClones
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-refreshtagitemclones
functions: [AllocateTagItems, CloneTagItems, FreeTagItems]
libraries: [utility.library]
---

# utility.library/RefreshTagItemClones

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RefreshTagItemClones -- Rejuvenates a clone from the original. (V36)
```
SYNOPSIS

```c
    RefreshTagItemClones( cloneTagItems, originalTagItems )
                          A0             A1

    void RefreshTagItemClones( struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *cloneTagItems,
                              struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *originalTagItems );
```
FUNCTION

```c
    If (and only if) the tag items 'cloneTagItems' were created
    from 'originalTagItems' by [CloneTagItems()](autodocs-2.0/utility-library-clonetagitems.md), and if originalTagItems
    has not been changed in any way, you can reset the clone list
    to its original state by using this function.
```
INPUTS

```c
    [CloneTagItems](autodocs-2.0/utility-library-clonetagitems.md)    - return value from CloneTagItems(originalTagItems).
    OriginalTagItems - a tag list that hasn't changed.
```
RESULT

    None.
EXAMPLE

BUGS

SEE ALSO

```c
    [CloneTagItems()](autodocs-2.0/utility-library-clonetagitems.md), [AllocateTagItems()](autodocs-2.0/utility-library-allocatetagitems.md), [FreeTagItems()](autodocs-2.0/utility-library-freetagitems.md)
```

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)

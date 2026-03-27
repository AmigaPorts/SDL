---
title: utility.library/AllocateTagItems
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-allocatetagitems
functions: [AllocateTagItems, CloneTagItems, FreeTagItems, NextTagItem]
libraries: [utility.library]
---

# utility.library/AllocateTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocateTagItems --  Allocate a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) array (or chain). (V36)
```
SYNOPSIS

```c
    tagList = AllocateTagItems( numItems )
    D0                          D0

    struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *AllocateTagItems( ULONG numItems);
```
FUNCTION

```c
    Allocates the specified number of usable TagItems slots, and does
    so in a format that the function [FreeTagItems](autodocs-2.0/utility-library-freetagitems.md) can handle.

    Note that to access the TagItems in 'tagList', you should use
    the function [NextTagItem()](autodocs-2.0/utility-library-nexttagitem.md).  This will insure you respect any
    chaining (TAG_MORE) that the list uses, and will skip any
    TAG_IGNORE items that AllocateTagItems() might use to stash
    size and other information.
```
INPUTS

```c
    numItems        - the number of [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) slots you want to allocate.
```
RESULT

```c
    tagList         - the allocated chain of [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) structures.  Will
                      return NULL if unsuccessful.
```
BUGS

SEE ALSO

```c
    [FreeTagItems()](autodocs-2.0/utility-library-freetagitems.md), [CloneTagItems()](autodocs-2.0/utility-library-clonetagitems.md)
```

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)

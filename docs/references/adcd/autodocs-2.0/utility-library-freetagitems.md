---
title: utility.library/FreeTagItems
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-freetagitems
functions: [AllocateTagItems, CloneTagItems]
libraries: [utility.library]
---

# utility.library/FreeTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeTagItems --  Frees allocated [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) lists. (V36)
```
SYNOPSIS

```c
    FreeTagItems( tagList )
                    A0

    void FreeTagItems( struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tagList );
```
FUNCTION

```c
    Frees the memory of a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list allocated either by
    [AllocateTagItems()](autodocs-2.0/utility-library-allocatetagitems.md) or [CloneTagItems()](autodocs-2.0/utility-library-clonetagitems.md).
```
INPUTS

    TagList         - list to free.  Must be created by functions
                      specified. A value of NULL for 'tagList' is safe.
RESULT

    None.
BUGS

SEE ALSO

```c
    [AllocateTagItems()](autodocs-2.0/utility-library-allocatetagitems.md), [CloneTagItems()](autodocs-2.0/utility-library-clonetagitems.md)
```

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)

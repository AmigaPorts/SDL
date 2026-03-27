---
title: utility.library/CloneTagItems
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-clonetagitems
functions: [AllocateTagItems, FreeTagItems, RefreshTagItemClones]
libraries: [utility.library]
---

# utility.library/CloneTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CloneTagItems -- Copies a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list.  (V36)
```
SYNOPSIS

```c
    newTagList = CloneTagItems( tagList )
    D0                          A0

    struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *CloneTagItems( struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tagList );
```
FUNCTION

```c
    Copies the essential contents of a tagItem list.  Internally,
    it uses [AllocateTagItems()](autodocs-2.0/utility-library-allocatetagitems.md) so that you can use [FreeTagItems()](autodocs-2.0/utility-library-freetagitems.md).
```
INPUTS

```c
    tagList         - [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list to clone.
```
RESULT

    newTagList      - resultant copy.
BUGS

SEE ALSO

```c
    [AllocateTagItems()](autodocs-2.0/utility-library-allocatetagitems.md), [FreeTagItems()](autodocs-2.0/utility-library-freetagitems.md), [RefreshTagItemClones()](autodocs-2.0/utility-library-refreshtagitemclones.md)
```

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)
- [RefreshTagItemClones — utility.library](../autodocs/utility.library.md#refreshtagitemclones)

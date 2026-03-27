---
title: utility.library/FindTagItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-findtagitem
functions: [GetTagData, NextTagItem, PackBoolTags]
libraries: [utility.library]
---

# utility.library/FindTagItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FindTagItem -- Scans [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list for a Tag. (V36)
```
SYNOPSIS

```c
    tag = FindTagItem( tagVal, tagList)
    D0                 D0      A0

    struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *FindTagItem( Tag tagVal, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tagList );
```
FUNCTION

```c
    Scans a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) "List", which is in fact a chain of arrays
    of [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) structures as defined in [utility/tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md).
    Returns a pointer to the FIRST item with ti_Tag matching the
    'TagVal' parameter.
```
INPUTS

```c
    tagVal          - Tag value to search for.
    tagList         - beginning of [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list to scan.
```
RESULT

    Returns a pointer to the item with ti_Tag matching 'TagVal'.
    Returns NULL if there is no match or if TagList is NULL.
BUGS

SEE ALSO

```c
    [utility/tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md), [GetTagData()](autodocs-2.0/utility-library-gettagdata.md), [PackBoolTags()](autodocs-2.0/utility-library-packbooltags.md), [NextTagItem()](autodocs-2.0/utility-library-nexttagitem.md)
```

---

## See Also

- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)

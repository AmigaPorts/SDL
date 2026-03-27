---
title: utility.library/GetTagData
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-gettagdata
functions: [FindTagItem, NextTagItem, PackBoolTags]
libraries: [utility.library]
---

# utility.library/GetTagData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetTagData -- Obtain data corresponding to Tag. (V36)
```
SYNOPSIS

```c
    value = GetTagData(tagVal, default, tagList)
    D0                 D0      D1       A0

    ULONG GetTagData(Tag TagVal, ULONG Default, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *TagList)
```
FUNCTION

```c
    Searches a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list for a matching Tag value, and returns the
    corresponding ti_Data value for the [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) found.  If none
    found, will return the value passed it as 'default'.
```
INPUTS

```c
    tagVal          - Tag value to search for.
    default         - value to be returned if tagVal is not found.
    tagList         - the [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list to search.
```
RESULT

```c
    value           - The ti_Data value for first matching [TagItem](autodocs-2.0/includes-utility-tagitem-h.md), or
                      'default' if a ti_Tag matching 'Tag' is not found.
```
BUGS

SEE ALSO

```c
    [utility/tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md), [FindTagItem()](autodocs-2.0/utility-library-findtagitem.md), [PackBoolTags()](autodocs-2.0/utility-library-packbooltags.md), [NextTagItem()](autodocs-2.0/utility-library-nexttagitem.md)
```

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)

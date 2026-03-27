---
title: utility.library/FilterTagItems
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-filtertagitems
functions: [TagInArray]
libraries: [utility.library]
---

# utility.library/FilterTagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FilterTagItems - Remove selected items from a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list. (V36)
```
SYNOPSIS

```c
    nvalid = FilterTagItems(tagList, tagArray, logic)
    D0                     A0       A1        D0

    ULONG FilterTagItems(struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tagList, Tag *tagArray,
                         LONG logic);
```
FUNCTION

```c
    Removes TagItems from a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list (by changing ti_Tag to
    TAG_IGNORE) depending on whether its ti_Tag value is
    found in an array of TagValues.

    If the 'logic' parameter is TAGFILTER_AND, then all items
    not appearing in the list are excluded.

    If 'logic' is TAGFILTER_NOT, then items not found in the
    array are preserved, and the ones in the array are cast out.
```
INPUTS

```c
    tagList         - input list of tag items which is to be filtered
                      by having selected items changed to TAG_IGNORE.
    tagArray        - an array of Tag values, terminated by TAG_END,
                      as specified in the notes on [TagInArray()](autodocs-2.0/utility-library-taginarray.md).
    logic           - specification whether items in TagArray are to
                      be included or excluded in the filtered result.
```
RESULT

    nvalid          - number of valid items left in resulting filtered
                      list.
BUGS

SEE ALSO

```c
    [TagInArray()](autodocs-2.0/utility-library-taginarray.md)
```

---

## See Also

- [TagInArray — utility.library](../autodocs/utility.library.md#taginarray)

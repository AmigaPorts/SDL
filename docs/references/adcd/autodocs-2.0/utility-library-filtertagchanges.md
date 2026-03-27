---
title: utility.library/FilterTagChanges
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-filtertagchanges
functions: [FilterTagChanges]
libraries: [utility.library]
---

# utility.library/FilterTagChanges

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FilterTagChanges -- Eliminate TagItems which specify no change. (V36)
```
SYNOPSIS

```c
    FilterTagChanges( changeList, oldValues, apply)
                      A0          A1         D0

    void FilterTagChanges( struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *changeList,
                           struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *oldValues, LONG apply );
```
FUNCTION

```c
    Eliminate items from a "change list" that specify values already
    in effect in existing list.  Optionally update the existing list
    if the Boolean 'Apply' is true.

    The elimination is done by changing the ti_Tag field to TAG_IGNORE.
    So, this function may change the input tag list(s).
```
INPUTS

    changeList      - specification of new tag-value pairs.
    oldValues       - a list of existing tag item pairs.
    apply           - Boolean specification as to whether the values in
                      oldValues are to be updated to the values in
                      changeList.
RESULT

    None.
EXAMPLE

```c
    Assume you have an attribute list for an object (oldValues)
    which looks like this:

            ATTR_Size,  "large",
            ATTR_Color, "orange",
            ATTR_Shape, "square",

    If you receive a new TagList containing some changes (changeList),
    which looks like this:

            ATTR_Size,  "large",
            ATTR_Shape, "triangle"

    If you call FilterTagChanges(), changeList will be modified to
    contain only those attributes which are different from the
    oldValues.  All other tagitems will have their tag-values set to
    TAG_IGNORE.  The resulting changeList will become:

            TAG_IGNORE, "large",
            ATTR_Shape, "triangle"

    If apply was set to TRUE, oldValues would be:

            ATTR_Size,  "large"
            ATTR_Color, "orange"
            ATTR_Shape, "triangle"
```
BUGS

SEE ALSO

---

## See Also

- [FilterTagChanges — utility.library](../autodocs/utility.library.md#filtertagchanges)

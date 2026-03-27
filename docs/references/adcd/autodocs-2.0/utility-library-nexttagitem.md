---
title: utility.library/NextTagItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-nexttagitem
functions: [FindTagItem, GetTagData, NextTagItem, PackBoolTags]
libraries: [utility.library]
---

# utility.library/NextTagItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NextTagItem -- Iterate [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) lists. (V36)
```
SYNOPSIS

```c
    next_tag = NextTagItem( tagItemPtr )
    D0                      A0

    struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *NextTagItem( struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) **tagItemPtr );
```
FUNCTION

```c
    Iterates through a (chained) array of [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) structures,
    skipping and chaining as dictated by system tags.  TAG_SKIP
    will cause it to skip the entry and the next, TAG_IGNORE ignores
    that single entry, and TAG_MORE has a pointer to another array
    of tags (and terminates the current array!)  TAG_DONE also
    terminates the current array.  Each call returns either the next
    tagitem you should examine, or NULL at the end.
```
INPUTS

```c
    tagItemPtr      - doubly-indirect reference to a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) structure.
                      The pointer will be changed to keep track of the
                      iteration.
```
RESULT

```c
    next_tag        - Each [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) in the array or chain of arrays that
                      should be processed according to system Tag values
                      (in [utility/tagitem.h)](autodocs-2.0/includes-utility-tagitem-h.md) is returned in turn with
                      successive calls.
```
EXAMPLE

```c
    Iterate( struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tags );
    {
            struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tstate;
            struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tag;

            tstate = tags;
            while ( tag = NextTagItem( &tstate ) )
            {
                    switch ( tag->ti_Tag )
                    {
                    case TAG1:
                        ...
                        break;
                    case TAG2:
                        ...
                        break;
                    ...
                    }
            }
    }
```
NOTES


```c
    Do NOT use the value of *tagItemPtr, but rather use the pointer
    returned by NextTagItem().
```
BUGS

SEE ALSO

```c
    [utility/tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md), [GetTagData()](autodocs-2.0/utility-library-gettagdata.md), [PackBoolTags()](autodocs-2.0/utility-library-packbooltags.md), [FindTagItem()](autodocs-2.0/utility-library-findtagitem.md)
```

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)

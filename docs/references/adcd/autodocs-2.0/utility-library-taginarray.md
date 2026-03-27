---
title: utility.library/TagInArray
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-taginarray
functions: [FilterTagItems]
libraries: [utility.library]
---

# utility.library/TagInArray

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    TagInArray  -- Check if a Tag value appears in a Tag array. (V36)
```
SYNOPSIS

```c
    BOOL TagInArray( tag, tagArray )
    D0               D0   A0

    BOOL TagInArray( Tag tag, Tag *tagArray);
```
FUNCTION

```c
    Perform a quick scan to see if a tag value appears in
    an array terminated with TAG_END.  Returns TRUE if
    the value is found.

    The 'tagArray' must be terminated by TAG_END.  It should
    NOT contain other system tag values, such as TAG_MORE
    or TAG_IGNORE.  Note that this is an array of Tag values, NOT
    an array of TagItems.

    This is sort of a "one shot" version of [FilterTagItems()](autodocs-2.0/utility-library-filtertagitems.md).
```
INPUTS

    tag             - Tag value to search array for.
    tagArray        - a simple array terminated by TAG_END.
RESULT

    Boolean success of search.
BUGS

SEE ALSO

```c
    [FilterTagItems()](autodocs-2.0/utility-library-filtertagitems.md)
```

---

## See Also

- [FilterTagItems — utility.library](../autodocs/utility.library.md#filtertagitems)

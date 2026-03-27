---
title: utility.library/MapTags
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-maptags
functions: []
libraries: []
---

# utility.library/MapTags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MapTags -- Convert ti_Tag values in a list via map pairing. (V36)
```
SYNOPSIS

```c
    MapTags(tagList, mapList, includeMiss)
            A0       A1       D0

    void MapTags(struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *tagList, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) mapList,
                 LONG includeMiss);
```
FUNCTION

```c
    Apply a "mapping list" mapList to tagList:

    If the ti_Tag field of an item in tagList appears as ti_Tag in some
    item in mapList, overwrite ti_Tag with the corresponding ti_Data
    from the map list.

    If a tag in tagList does not appear in the mapList, you can choose
    to have it removed by changing it to TAG_IGNORE. Do this by setting
    includeMiss to FALSE.

    If you want to have items which do not appear in the mapList
    survive the mapping as-is, set includeMiss to 1.

    This is central to gadget interconnections where you want
    to convert the tag values from one space (the sender) to
    another (the receiver).
```
INPUTS

    tagList         - Input list of tag items which is to be mapped
                      to Tag values as specified in mapList.
    mapList         - a "mapping list" tagItem list which pairs Tag
                      values expected to appear in tagList with new
                      values to be substituted in the ti_Tag fields of
                      tagList.  May be NULL, which means that all items
                      in tagList will be eliminated.
    includeMiss     - 0 to remove tags from tagList not in mapList,
                      1 to remove
RESULT

    None.
EXAMPLE

```c
    /* Consider this source list: */
        struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list[] = {
            { MY_SIZE,      71 },
            { MY_WEIGHT,    200 },
            { TAG_END,      } };

    /* And the mapping list: */
        struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) map[] = {
            { MY_SIZE,      HIS_TALL },
            { TAG_END,      } };

    /* Then after MapTags( list, map, 0 ), 'list' will become: */
            { HIS_TALL, 71 },
            { TAG_IGNORE, },
            { TAG_END, }

    /* Then after MapTags( list, map, 1 ), 'list' will become: */
            { HIS_TALL, 71 },
            { MY_WEIGHT, 200 },
            { TAG_END, }
```
NOTES

```c
    The procedure will change the values of the input tag list
    tagList (but not mapList).

    You can "filter" a list by passing includeMiss as 0, and having the
    data items in the map list equal the corresponding tags.

    You can perform the inverse filter ("everything but") by passing
    includeMiss equal to 1, and creating a map item for every tag you
    want to filter out, pairing it with a mapped data value of
    TAG_IGNORE.

    For safety and "order independence" of tag item arrays, if you
    attempt to map some tag to the value TAG_END, the value TAG_IGNORE
    will be substituted instead.
```
BUGS

SEE ALSO


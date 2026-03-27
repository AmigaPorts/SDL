---
title: 37 / Tags / Tag Functions and Structures
manual: libraries
chapter: libraries
section: 37-tags-tag-functions-and-structures
functions: [AllocateTagItems, CloneTagItems, FilterTagChanges, FilterTagItems, FindTagItem, FreeTagItems, GetTagData, MapTags, NextTagItem, PackBoolTags, RefreshTagItemClones, TagInArray]
libraries: [utility.library]
---

# 37 / Tags / Tag Functions and Structures

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A tag is made up of an attribute/value pair as defined below (from
<utility/[tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md)>):


```c
    struct TagItem
    {
        ULONG  ti_Tag;    /* identifies the type of this item */
        ULONG  ti_Data;   /* type-specific data, can be a pointer */
    };
```
The ti_Tag field specifies an attribute to set.  The possible values of
ti_Tag are implementation specific.  System tags are defined in the
include files.  The value the attribute is set to is specified in ti_Data.
An example of the attribute/value pair that will specify a window's name
is:


```c
    ti_Tag  = WA_Title;
    ti_Data = "My Window's Name";
```
The ti_Data field often contains 32-bit data as well as pointers.

These are brief descriptions of the utility functions you can use to
manipulate and access tags.  For complete descriptions, see the
"[Simple Tag Usage](libraries/37-tags-simple-tag-usage.md)" and "[Advanced Tag Usage](libraries/37-tags-advanced-tag-usage.md)" sections.

The following utility library calls are for supporting tags:


                Table 37-1: Utility Library Tag Functions
  ______________________________________________________________________
 |                                                                      |
 |     [AllocateTagItems()](libraries/37-advanced-tag-usage-creating-a-new-tag-list.md)  Allocate a TagItem array (or chain).         |
 |         [FreeTagItems()](libraries/37-advanced-tag-usage-creating-a-new-tag-list.md)  Frees allocated TagItem lists.               |
 |----------------------------------------------------------------------|
 |        [CloneTagItems()](libraries/37-advanced-tag-usage-copying-an-existing-tag-list.md)  Copies a TagItem list.                       |
 | [RefreshTagItemClones()](libraries/37-advanced-tag-usage-filtering-an-existing-tag-list.md)  Rejuvenates a clone from the original.       |
 |----------------------------------------------------------------------|
 |          [FindTagItem()](libraries/37-advanced-tag-usage-locating-an-attribute.md)  Scans TagItem list for a tag.                |
 |           [GetTagData()](libraries/37-advanced-tag-usage-random-access-of-tag-lists.md)  Obtain data corresponding to tag.            |
 |          [NextTagItem()](libraries/37-advanced-tag-usage-sequential-access-of-tag-lists.md)  Iterate TagItem lists.                       |
 |           [TagInArray()](libraries/37-advanced-tag-usage-locating-an-attribute.md)  Check if a tag value appears in a Tag array. |
 |----------------------------------------------------------------------|
 |     [FilterTagChanges()](libraries/37-advanced-tag-usage-filtering-an-existing-tag-list.md)  Eliminate TagItems which specify no change.  |
 |       [FilterTagItems()](libraries/37-advanced-tag-usage-filtering-an-existing-tag-list.md)  Remove selected items from a TagItem list.   |
 |              [MapTags()](libraries/37-advanced-tag-usage-mapping-tag-attributes.md)  Convert ti_Tag values in a list via map      |
 |                         pairing.                                     |
 |         [PackBoolTags()](libraries/37-advanced-tag-usage-obtaining-boolean-values.md)  Builds a "Flag" word from a TagItem list.    |
 |______________________________________________________________________|

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)
- [FilterTagChanges — utility.library](../autodocs/utility.library.md#filtertagchanges)
- [FilterTagItems — utility.library](../autodocs/utility.library.md#filtertagitems)
- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)
- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
- [MapTags — utility.library](../autodocs/utility.library.md#maptags)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)
- [RefreshTagItemClones — utility.library](../autodocs/utility.library.md#refreshtagitemclones)
- [TagInArray — utility.library](../autodocs/utility.library.md#taginarray)

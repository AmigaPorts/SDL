---
title: 37 / Function Reference / Tag Function Reference
manual: libraries
chapter: libraries
section: 37-function-reference-tag-function-reference
functions: [AllocateTagItems, CloneTagItems, FilterTagChanges, FilterTagItems, FindTagItem, FreeTagItems, GetTagData, MapTags, NextTagItem, PackBoolTags, RefreshTagItemClones, TagInArray]
libraries: [utility.library]
---

# 37 / Function Reference / Tag Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the utility library functions
which pertain to tags and tag lusts.


                    Table 37-6: Utility Tag Functions
  ______________________________________________________________________
 |                                                                      |
 |           Function                 Description                       |
 |======================================================================|
 |     [AllocateTagItems()](autodocs-2.0/utility-library-allocatetagitems.md)  Allocate a [TagItem](libraries/37-tags-tag-functions-and-structures.md) array (or chain).         |
 |         [FreeTagItems()](autodocs-2.0/utility-library-freetagitems.md)  Frees allocated TagItem lists.               |
 |----------------------------------------------------------------------|
 |        [CloneTagItems()](autodocs-2.0/utility-library-clonetagitems.md)  Copies a [TagItem](libraries/37-tags-tag-functions-and-structures.md) list.                       |
 | [RefreshTagItemClones()](autodocs-2.0/utility-library-refreshtagitemclones.md)  Rejuvenates a clone from the original.       |
 |----------------------------------------------------------------------|
 |          [FindTagItem()](autodocs-2.0/utility-library-findtagitem.md)  Scans [TagItem](libraries/37-tags-tag-functions-and-structures.md) list for a tag.                |
 |           [GetTagData()](autodocs-2.0/utility-library-gettagdata.md)  Obtain data corresponding to tag.            |
 |          [NextTagItem()](autodocs-2.0/utility-library-nexttagitem.md)  Iterate TagItem lists.                       |
 |           [TagInArray()](autodocs-2.0/utility-library-taginarray.md)  Check if a tag value appears in a Tag array. |
 |----------------------------------------------------------------------|
 |     [FilterTagChanges()](autodocs-2.0/utility-library-filtertagchanges.md)  Eliminate [TagItem](libraries/37-tags-tag-functions-and-structures.md)s which specify no change.  |
 |       [FilterTagItems()](autodocs-2.0/utility-library-filtertagitems.md)  Remove selected items from a TagItem list.   |
 |              [MapTags()](autodocs-2.0/utility-library-maptags.md)  Convert [ti_Tag](libraries/37-tags-tag-functions-and-structures.md) values in a list via map      |
 |----------------------------------------------------------------------|
 |         [PackBoolTags()](autodocs-2.0/utility-library-packbooltags.md)  Builds a "Flag" word from a [TagItem](libraries/37-tags-tag-functions-and-structures.md) list.    |
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

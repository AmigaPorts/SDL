---
title: utility.doc
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-doc-2
functions: [AddNamedObject, AllocateTagItems, Amiga2Date, ApplyTagChanges, AttemptRemNamedObject, CallHookPkt, CheckDate, CloneTagItems, Date2Amiga, FilterTagChanges, FilterTagItems, FindNamedObject, FindTagItem, FreeNamedObject, FreeTagItems, GetTagData, GetUniqueID, MapTags, NamedObjectName, NextTagItem, PackBoolTags, PackStructureTags, RefreshTagItemClones, ReleaseNamedObject, RemNamedObject, Stricmp, Strnicmp, TagInArray, ToLower, ToUpper, UnpackStructureTags]
libraries: [utility.library]
---

# utility.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
     [AddNamedObject()](autodocs-3.5/utility-library-addnamedobject.md) 
     [AllocateTagItems()](autodocs-3.5/utility-library-allocatetagitems-2.md) 
     [AllocNamedObjectA()](autodocs-3.5/utility-library-allocnamedobjecta.md) 
     [Amiga2Date()](autodocs-3.5/utility-library-amiga2date-2.md) 
     [ApplyTagChanges()](autodocs-3.5/utility-library-applytagchanges.md) 
     [AttemptRemNamedObject()](autodocs-3.5/utility-library-attemptremnamedobject.md) 
     [CallHookPkt()](autodocs-3.5/utility-library-callhookpkt-2.md) 
     [CheckDate()](autodocs-3.5/utility-library-checkdate-2.md) 
     [CloneTagItems()](autodocs-3.5/utility-library-clonetagitems-2.md) 
     [Date2Amiga()](autodocs-3.5/utility-library-date2amiga-2.md) 
     [FilterTagChanges()](autodocs-3.5/utility-library-filtertagchanges-2.md) 
     [FilterTagItems()](autodocs-3.5/utility-library-filtertagitems-2.md) 
     [FindNamedObject()](autodocs-3.5/utility-library-findnamedobject.md) 
     [FindTagItem()](autodocs-3.5/utility-library-findtagitem-2.md) 
     [FreeNamedObject()](autodocs-3.5/utility-library-freenamedobject.md) 
     [FreeTagItems()](autodocs-3.5/utility-library-freetagitems-2.md) 
     [GetTagData()](autodocs-3.5/utility-library-gettagdata-2.md) 
     [GetUniqueID()](autodocs-3.5/utility-library-getuniqueid.md) 
     [MapTags()](autodocs-3.5/utility-library-maptags-2.md) 
     [NamedObjectName()](autodocs-3.5/utility-library-namedobjectname.md) 
     [NextTagItem()](autodocs-3.5/utility-library-nexttagitem-2.md) 
     [PackBoolTags()](autodocs-3.5/utility-library-packbooltags-2.md) 
     [PackStructureTags()](autodocs-3.5/utility-library-packstructuretags.md) 
     [RefreshTagItemClones()](autodocs-3.5/utility-library-refreshtagitemclones-2.md) 
     [ReleaseNamedObject()](autodocs-3.5/utility-library-releasenamedobject.md) 
     [RemNamedObject()](autodocs-3.5/utility-library-remnamedobject.md) 
     [SDivMod32()](autodocs-3.5/utility-library-sdivmod32-2.md) 
     [SMult32()](autodocs-3.5/utility-library-smult32-2.md) 
     [SMult64()](autodocs-3.5/utility-library-smult64.md) 
     [Stricmp()](autodocs-3.5/utility-library-stricmp-2.md) 
     [Strnicmp()](autodocs-3.5/utility-library-strnicmp-2.md) 
     [TagInArray()](autodocs-3.5/utility-library-taginarray-2.md) 
     [ToLower()](autodocs-3.5/utility-library-tolower-2.md) 
     [ToUpper()](autodocs-3.5/utility-library-toupper-2.md) 
     [UDivMod32()](autodocs-3.5/utility-library-udivmod32-2.md) 
     [UMult32()](autodocs-3.5/utility-library-umult32-2.md) 
     [UMult64()](autodocs-3.5/utility-library-umult64.md) 
     [UnpackStructureTags()](autodocs-3.5/utility-library-unpackstructuretags.md) 
```

---

## See Also

- [AddNamedObject — utility.library](../autodocs/utility.library.md#addnamedobject)
- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
- [ApplyTagChanges — utility.library](../autodocs/utility.library.md#applytagchanges)
- [AttemptRemNamedObject — utility.library](../autodocs/utility.library.md#attemptremnamedobject)
- [CallHookPkt — utility.library](../autodocs/utility.library.md#callhookpkt)
- [CheckDate — utility.library](../autodocs/utility.library.md#checkdate)
- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)
- [Date2Amiga — utility.library](../autodocs/utility.library.md#date2amiga)
- [FilterTagChanges — utility.library](../autodocs/utility.library.md#filtertagchanges)
- [FilterTagItems — utility.library](../autodocs/utility.library.md#filtertagitems)
- [FindNamedObject — utility.library](../autodocs/utility.library.md#findnamedobject)
- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [FreeNamedObject — utility.library](../autodocs/utility.library.md#freenamedobject)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)
- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
- [GetUniqueID — utility.library](../autodocs/utility.library.md#getuniqueid)
- [MapTags — utility.library](../autodocs/utility.library.md#maptags)
- [NamedObjectName — utility.library](../autodocs/utility.library.md#namedobjectname)
- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)
- [PackStructureTags — utility.library](../autodocs/utility.library.md#packstructuretags)
- [RefreshTagItemClones — utility.library](../autodocs/utility.library.md#refreshtagitemclones)
- [ReleaseNamedObject — utility.library](../autodocs/utility.library.md#releasenamedobject)
- [RemNamedObject — utility.library](../autodocs/utility.library.md#remnamedobject)
- [Stricmp — utility.library](../autodocs/utility.library.md#stricmp)
- [Strnicmp — utility.library](../autodocs/utility.library.md#strnicmp)
- [TagInArray — utility.library](../autodocs/utility.library.md#taginarray)
- [ToLower — utility.library](../autodocs/utility.library.md#tolower)
- [ToUpper — utility.library](../autodocs/utility.library.md#toupper)
- [UnpackStructureTags — utility.library](../autodocs/utility.library.md#unpackstructuretags)

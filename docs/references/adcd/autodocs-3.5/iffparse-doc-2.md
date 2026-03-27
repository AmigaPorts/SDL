---
title: iffparse.doc
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-doc-2
functions: [AllocIFF, AllocLocalItem, CloseClipboard, CloseIFF, CollectionChunk, CollectionChunks, CurrentChunk, EntryHandler, ExitHandler, FindCollection, FindLocalItem, FindProp, FindPropContext, FreeIFF, FreeLocalItem, GoodID, GoodType, IDtoStr, InitIFF, InitIFFasClip, InitIFFasDOS, LocalItemData, OpenClipboard, OpenIFF, ParentChunk, ParseIFF, PopChunk, PropChunk, PropChunks, PushChunk, ReadChunkBytes, ReadChunkRecords, SetLocalItemPurge, StopChunk, StopChunks, StopOnExit, StoreItemInContext, StoreLocalItem, WriteChunkBytes, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
     [AllocIFF()](autodocs-3.5/iffparse-library-allociff-2.md) 
     [AllocLocalItem()](autodocs-3.5/iffparse-library-alloclocalitem-2.md) 
     [CloseClipboard()](autodocs-3.5/iffparse-library-closeclipboard-2.md) 
     [CloseIFF()](autodocs-3.5/iffparse-library-closeiff-2.md) 
     [CollectionChunk()](autodocs-3.5/iffparse-library-collectionchunk-2.md) 
     [CollectionChunks()](autodocs-3.5/iffparse-library-collectionchunks-2.md) 
     [CurrentChunk()](autodocs-3.5/iffparse-library-currentchunk-2.md) 
     [EntryHandler()](autodocs-3.5/iffparse-library-entryhandler-2.md) 
     [ExitHandler()](autodocs-3.5/iffparse-library-exithandler-2.md) 
     [FindCollection()](autodocs-3.5/iffparse-library-findcollection-2.md) 
     [FindLocalItem()](autodocs-3.5/iffparse-library-findlocalitem-2.md) 
     [FindProp()](autodocs-3.5/iffparse-library-findprop-2.md) 
     [FindPropContext()](autodocs-3.5/iffparse-library-findpropcontext-2.md) 
     [FreeIFF()](autodocs-3.5/iffparse-library-freeiff-2.md) 
     [FreeLocalItem()](autodocs-3.5/iffparse-library-freelocalitem-2.md) 
     [GoodID()](autodocs-3.5/iffparse-library-goodid-2.md) 
     [GoodType()](autodocs-3.5/iffparse-library-goodtype-2.md) 
     [IDtoStr()](autodocs-3.5/iffparse-library-idtostr-2.md) 
     [InitIFF()](autodocs-3.5/iffparse-library-initiff-2.md) 
     [InitIFFasClip()](autodocs-3.5/iffparse-library-initiffasclip-2.md) 
     [InitIFFasDOS()](autodocs-3.5/iffparse-library-initiffasdos-2.md) 
     [LocalItemData()](autodocs-3.5/iffparse-library-localitemdata-2.md) 
     [OpenClipboard()](autodocs-3.5/iffparse-library-openclipboard-2.md) 
     [OpenIFF()](autodocs-3.5/iffparse-library-openiff-2.md) 
     [ParentChunk()](autodocs-3.5/iffparse-library-parentchunk-2.md) 
     [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md) 
     [PopChunk()](autodocs-3.5/iffparse-library-popchunk-2.md) 
     [PropChunk()](autodocs-3.5/iffparse-library-propchunk-2.md) 
     [PropChunks()](autodocs-3.5/iffparse-library-propchunks-2.md) 
     [PushChunk()](autodocs-3.5/iffparse-library-pushchunk-2.md) 
     [ReadChunkBytes()](autodocs-3.5/iffparse-library-readchunkbytes-2.md) 
     [ReadChunkRecords()](autodocs-3.5/iffparse-library-readchunkrecords-2.md) 
     [SetLocalItemPurge()](autodocs-3.5/iffparse-library-setlocalitempurge-2.md) 
     [StopChunk()](autodocs-3.5/iffparse-library-stopchunk-2.md) 
     [StopChunks()](autodocs-3.5/iffparse-library-stopchunks-2.md) 
     [StopOnExit()](autodocs-3.5/iffparse-library-stoponexit-2.md) 
     [StoreItemInContext()](autodocs-3.5/iffparse-library-storeitemincontext-2.md) 
     [StoreLocalItem()](autodocs-3.5/iffparse-library-storelocalitem-2.md) 
     [WriteChunkBytes()](autodocs-3.5/iffparse-library-writechunkbytes-2.md) 
     [WriteChunkRecords()](autodocs-3.5/iffparse-library-writechunkrecords-2.md) 
```

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [CloseClipboard — iffparse.library](../autodocs/iffparse.library.md#closeclipboard)
- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [CollectionChunks — iffparse.library](../autodocs/iffparse.library.md#collectionchunks)
- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [FindCollection — iffparse.library](../autodocs/iffparse.library.md#findcollection)
- [FindLocalItem — iffparse.library](../autodocs/iffparse.library.md#findlocalitem)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [FindPropContext — iffparse.library](../autodocs/iffparse.library.md#findpropcontext)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)
- [GoodID — iffparse.library](../autodocs/iffparse.library.md#goodid)
- [GoodType — iffparse.library](../autodocs/iffparse.library.md#goodtype)
- [IDtoStr — iffparse.library](../autodocs/iffparse.library.md#idtostr)
- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [InitIFFasClip — iffparse.library](../autodocs/iffparse.library.md#initiffasclip)
- [InitIFFasDOS — iffparse.library](../autodocs/iffparse.library.md#initiffasdos)
- [LocalItemData — iffparse.library](../autodocs/iffparse.library.md#localitemdata)
- [OpenClipboard — iffparse.library](../autodocs/iffparse.library.md#openclipboard)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)
- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [PropChunks — iffparse.library](../autodocs/iffparse.library.md#propchunks)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)
- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [ReadChunkRecords — iffparse.library](../autodocs/iffparse.library.md#readchunkrecords)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
- [StopChunks — iffparse.library](../autodocs/iffparse.library.md#stopchunks)
- [StopOnExit — iffparse.library](../autodocs/iffparse.library.md#stoponexit)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)

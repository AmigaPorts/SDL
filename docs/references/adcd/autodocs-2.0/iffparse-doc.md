---
title: iffparse.doc
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-doc
functions: [AllocIFF, AllocLocalItem, CloseClipboard, CloseIFF, CollectionChunk, CollectionChunks, CurrentChunk, EntryHandler, ExitHandler, FindCollection, FindLocalItem, FindProp, FindPropContext, FreeIFF, FreeLocalItem, GoodID, GoodType, IDtoStr, InitIFF, InitIFFasClip, InitIFFasDOS, LocalItemData, OpenClipboard, OpenIFF, ParentChunk, ParseIFF, PopChunk, PropChunk, PropChunks, PushChunk, ReadChunkBytes, ReadChunkRecords, SetLocalItemPurge, StopChunk, StopChunks, StopOnExit, StoreItemInContext, StoreLocalItem, WriteChunkBytes, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 [HookEntry()](autodocs-2.0/hookentry.md)             [FreeIFF()](autodocs-2.0/iffparse-library-freeiff.md)            [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md) 
 [AllocIFF()](autodocs-2.0/iffparse-library-allociff.md)              [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md)      [PropChunks()](autodocs-2.0/iffparse-library-propchunks.md) 
 [AllocLocalItem()](autodocs-2.0/iffparse-library-alloclocalitem.md)        [GoodID()](autodocs-2.0/iffparse-library-goodid.md)             [PushChunk()](autodocs-2.0/iffparse-library-pushchunk.md) 
 [CloseClipboard()](autodocs-2.0/iffparse-library-closeclipboard.md)        [GoodType()](autodocs-2.0/iffparse-library-goodtype.md)           [ReadChunkBytes()](autodocs-2.0/iffparse-library-readchunkbytes.md) 
 [CloseIFF()](autodocs-2.0/iffparse-library-closeiff.md)              [IDtoStr()](autodocs-2.0/iffparse-library-idtostr.md)            [ReadChunkRecords()](autodocs-2.0/iffparse-library-readchunkrecords.md) 
 [CollectionChunk()](autodocs-2.0/iffparse-library-collectionchunk.md)       [InitIFF()](autodocs-2.0/iffparse-library-initiff.md)            [SetLocalItemPurge()](autodocs-2.0/iffparse-library-setlocalitempurge.md) 
 [CollectionChunks()](autodocs-2.0/iffparse-library-collectionchunks.md)      [InitIFFasClip()](autodocs-2.0/iffparse-library-initiffasclip.md)      [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md) 
 [CurrentChunk()](autodocs-2.0/iffparse-library-currentchunk.md)          [InitIFFasDOS()](autodocs-2.0/iffparse-library-initiffasdos.md)       [StopChunks()](autodocs-2.0/iffparse-library-stopchunks.md) 
 [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md)          [LocalItemData()](autodocs-2.0/iffparse-library-localitemdata.md)      [StopOnExit()](autodocs-2.0/iffparse-library-stoponexit.md) 
 [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md)           [OpenClipboard()](autodocs-2.0/iffparse-library-openclipboard.md)      [StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md) 
 [FindCollection()](autodocs-2.0/iffparse-library-findcollection.md)        [OpenIFF()](autodocs-2.0/iffparse-library-openiff.md)            [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md) 
 [FindLocalItem()](autodocs-2.0/iffparse-library-findlocalitem.md)         [ParentChunk()](autodocs-2.0/iffparse-library-parentchunk.md)        [WriteChunkBytes()](autodocs-2.0/iffparse-library-writechunkbytes.md) 
 [FindProp()](autodocs-2.0/iffparse-library-findprop.md)              [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md)           [WriteChunkRecords()](autodocs-2.0/iffparse-library-writechunkrecords.md) 
 [FindPropContext()](autodocs-2.0/iffparse-library-findpropcontext.md)       [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md) 

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

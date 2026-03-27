---
title: 33 IFFParse Library / Function Reference
manual: libraries
chapter: libraries
section: 33-iffparse-library-function-reference
functions: [AllocIFF, AllocLocalItem, CloseIFF, CollectionChunk, CurrentChunk, EntryHandler, ExitHandler, FindCollection, FindLocalItem, FindProp, FindPropContext, FreeIFF, FreeLocalItem, InitIFF, InitIFFasClip, InitIFFasDOS, LocalItemData, OpenClipboard, OpenIFF, ParentChunk, ParseIFF, PopChunk, PropChunk, PushChunk, ReadChunkBytes, ReadChunkRecords, SetLocalItemPurge, StopChunk, StopOnExit, StoreItemInContext, StoreLocalItem]
libraries: [iffparse.library]
---

# 33 IFFParse Library / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the IFFParse functions discussed
in this chapter.  IFFParse library functions are avialable in Release 2 of
the Amiga OS and are backward compatible with older versions of the
system.  Further information about these and other IFFParse functions can
be found in the 3rd edition of the Amiga ROM Kernel Reference Manual:
Includes and Autodocs, also from Addison-Wesley.


                  Table 33-2: IFFParse Library Functions
  _______________________________________________________________________
 |                                                                       |
 |            Function              Description                          |
 |=======================================================================|
 |            [AllocIFF()](autodocs-2.0/iffparse-library-allociff.md)  Creates an [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) structure.                |
 |             [FreeIFF()](autodocs-2.0/iffparse-library-freeiff.md)  Frees the IFFHandle structure created with     |
 |                        AllocIFF().                                    |
 |             [OpenIFF()](autodocs-2.0/iffparse-library-openiff.md)  Initialize an IFFHandle structure to read or   |
 |                        write an [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) stream.                           |
 |            [CloseIFF()](autodocs-2.0/iffparse-library-closeiff.md)  Closes an IFF context.                         |
 |-----------------------------------------------------------------------|
 |             [InitIFF()](autodocs-2.0/iffparse-library-initiff.md)  Initialize an [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) as a user-defined      |
 |                        stream.                                        |
 |        [InitIFFasDOS()](autodocs-2.0/iffparse-library-initiffasdos.md)  Initialize an IFFHandle as an AmigaDOS stream. |
 |       [InitIFFasClip()](autodocs-2.0/iffparse-library-initiffasclip.md)  Initialize an IFFHandle as a clipboard stream. |
 |-----------------------------------------------------------------------|
 |       [OpenClipboard()](autodocs-2.0/iffparse-library-openclipboard.md)  Create a handle on a clipboard unit for        |
 |                        InitIFFasClip().                               |
 |            [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md)  Parse an [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) file from an [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) stream.    |
 |      [ReadChunkBytes()](autodocs-2.0/iffparse-library-readchunkbytes.md)  Read bytes from current chunk into a buffer.   |
 |    [ReadChunkRecords()](autodocs-2.0/iffparse-library-readchunkrecords.md)  Read record elements from the current chunk    |
 |                        into a buffer.                                 |
 |           [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md)  Declare a chunk that should cause ParseIFF()   |
 |                        to return.                                     |
 |        [CurrentChunk()](autodocs-2.0/iffparse-library-currentchunk.md)  Get the context node for the current chunk.    |
 |           [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md)  Specify a property chunk to store.             |
 |            [FindProp()](autodocs-2.0/iffparse-library-findprop.md)  Search for a stored property in a given        |
 |                        context.                                       |
 |     [CollectionChunk()](autodocs-2.0/iffparse-library-collectionchunk.md)  Declare a chunk type for collection.           |
 |      [FindCollection()](autodocs-2.0/iffparse-library-findcollection.md)  Get a pointer to the current list of           |
 |                        collection items.                              |
 |          [StopOnExit()](autodocs-2.0/iffparse-library-stoponexit.md)  Declare a stop condition for exiting a chunk.  |
 |        [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md)  Add an entry handler to the IFFHandle context. |
 |         [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md)  Add an exit handler to the IFFHandle context.  |
 |-----------------------------------------------------------------------|
 |           [PushChunk()](autodocs-2.0/iffparse-library-pushchunk.md)  Push a given context node onto the top of the  |
 |                        context stack.                                 |
 |            [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md)  Pop the top context node off of the context    |
 |                        stack.                                         |
 |        [CurrentChunk()](autodocs-2.0/iffparse-library-currentchunk.md)  Get the top context node for the current chunk.|
 |         [ParentChunk()](autodocs-2.0/iffparse-library-parentchunk.md)  Get the nesting context node for a given chunk.|
 |-----------------------------------------------------------------------|
 |      [AllocLocalItem()](autodocs-2.0/iffparse-library-alloclocalitem.md)  Create a [LocalContextItem](libraries/33-context-functions-context-specific-data-localcontextitems.md) (LCI) structure.     |
 |       [LocalItemData()](autodocs-2.0/iffparse-library-localitemdata.md)  Returns a pointer to the user data of a        |
 |                        LocalContextItem (LCI).                        |
 |      [StoreLocalItem()](autodocs-2.0/iffparse-library-storelocalitem.md)  Insert a LocalContextItem (LCI).               |
 |  [StoreItemInContext()](autodocs-2.0/iffparse-library-storeitemincontext.md)  Store a LocalContextItem in a given context    |
 |                        node.                                          |
 |     [FindPropContext()](autodocs-2.0/iffparse-library-findpropcontext.md)  Find the property context for the current      |
 |                        state.                                         |
 |       [FindLocalItem()](autodocs-2.0/iffparse-library-findlocalitem.md)  Return a LocalContextItem from the context     |
 |                        stack.                                         |
 |       [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md)  Free a LocalContextItem (LCI) created with     |
 |                        AllocLocalItem().                              |
 |   [SetLocalItemPurge()](autodocs-2.0/iffparse-library-setlocalitempurge.md)  Set purge vector for a local context item.     |
 |_______________________________________________________________________|

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [FindCollection — iffparse.library](../autodocs/iffparse.library.md#findcollection)
- [FindLocalItem — iffparse.library](../autodocs/iffparse.library.md#findlocalitem)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [FindPropContext — iffparse.library](../autodocs/iffparse.library.md#findpropcontext)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)
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
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)
- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [ReadChunkRecords — iffparse.library](../autodocs/iffparse.library.md#readchunkrecords)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
- [StopOnExit — iffparse.library](../autodocs/iffparse.library.md#stoponexit)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)

---
title: iffparse.library (basename: _IFFParseBase)  V36
manual: amiga-mail
chapter: amiga-mail
section: iffparse-library-basename-iffparsebase-v36
functions: [AllocIFF]
libraries: [iffparse.library]
---

# iffparse.library (basename: _IFFParseBase)  V36

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AllocIFF()()                            - Create a new IFFHandle
                                          structure.
AllocLocalItem(type,id,ident,dataSize)(d0/d1/d2/d3)
                                        - Create a local context item
                                          structure.
CloseClipboard(clipboard)(a0)           - Close and free an open
                                          ClipboardHandle.
CloseIFF(iff)(a0)                       - Close an IFF context.
CollectionChunk(iff,type,id)(a0,d0/d1)  - Declare a chunk type for
                                          collection.
CollectionChunks(iff,propArray,nProps)(a0/a1,d0)
                                        - Declare many collection chunks
                                          at once.
CurrentChunk(iff)(a0)                   - Get context node for current
                                          chunk.
EntryHandler(iff,type,id,position,handler,object)(a0,d0/d1/d2/a1/a2)
                                        - Add an entry handler to the
                                          IFFHandle context.
ExitHandler(iff,type,id,position,handler,object)(a0,d0/d1/d2/a1/a2)
                                        - Add an exit handler to the
                                          IFFHandle context.
FindCollection(iff,type,id)(a0,d0/d1)   - Get a pointer to the current
                                          list of collection
FindLocalItem(iff,type,id,ident)(a0,d0/d1/d2)
                                        - Return a local context item from
                                          the context stack.
FindProp(iff,type,id)(a0,d0/d1)         - Search for a stored property
                                          chunk.
FindPropContext(iff)(a0)                - Get the property context for the
                                          current state.
FreeIFF(iff)(a0)                        - Deallocate an IFFHandle struct.
FreeLocalItem(localItem)(a0)            - Deallocate a local context item
                                          structure.
GoodID(id)(d0)                          - Test if an identifier follows
                                          the IFF 85 specification.
GoodType(type)(d0)                      - Test if a type follows the IFF
                                          85 specification.
IDtoStr(id,buf)(d0/a0)                  - Convert a longword identifier to
                                          a null-terminated string.
InitIFF(iff,flags,streamHook)(a0,d0/a1) - Initialize an IFFHandle struct
                                          as a user stream.
InitIFFasClip(iff)(a0)                  - Initialize an IFFHandle as a
                                          clipboard stream.
InitIFFasDOS(iff)(a0)                   - Initialize an IFFHandle as a DOS
                                          stream.
LocalItemData(localItem)(a0)            - Get pointer to user data for
                                          local context item.
OpenClipboard(unitNum)(d0)              - Create a handle on a clipboard
                                          unit.
OpenIFF(iff,rwMode)(a0,d0)              - Prepare an IFFHandle to read or
                                          write a new IFF stream.
ParentChunk(contextNode)(a0)            - Get the nesting context node for
                                          the given chunk.
ParseIFF(iff,control)(a0,d0)            - Parse an IFF file from an
                                          IFFHandle struct stream.
PopChunk(iff)(a0)                       - Pop top context node off context
                                          stack.
PropChunk(iff,type,id)(a0,d0/d1)        - Specify a property chunk to
                                          store.
PropChunks(iff,propArray,nProps)(a0/a1,d0)
                                        - Declare many property chunks at
                                          once.
PushChunk(iff,type,id,size)(a0,d0/d1/d2)- Push a new context node on the
                                          context stack.
ReadChunkBytes(iff,buf,size)(a0/a1,d0)  - Read bytes from the current
                                          chunk into a buffer.
ReadChunkRecords(iff,buf,bytesPerRecord,nRecords)(a0/a1,d0/d1)
                                        - Read record elements from the
                                          current chunk into
SetLocalItemPurge(localItem,purgeHook)(a0/a1)
                                        - Set purge vector for a local
                                          context item.
StopChunk(iff,type,id)(a0,d0/d1)        - Declare a chunk which should
                                          cause ParseIFF to return.
StopChunks(iff,propArray,nProps)(a0/a1,d0)
                                        - Declare many stop chunks at
                                          once.
StopOnExit(iff,type,id)(a0,d0/d1)       - Declare a stop condition for
                                          exiting a chunk.
StoreItemInContext(iff,localItem,contextNode)(a0/a1/a2)
                                        - Store local context item in
                                          given context node.
StoreLocalItem(iff,localItem,position)(a0/a1,d0)
                                        - Insert a local context item into
                                          the context stack.
WriteChunkBytes(iff,buf,size)(a0/a1,d0) - Write data from a buffer into
                                          the current chunk.
WriteChunkRecords(iff,buf,bytesPerRecord,nRecords)(a0/a1,d0/d1)

                                        - Write records from a buffer to
                                          the current

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)

# 33 IFFParse Library / Function Reference


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
 |            [AllocIFF()](../Includes_and_Autodocs_2._guide/node01B8.html)  Creates an [IFFHandle](../Libraries_Manual_guide/node042C.html) structure.                |
 |             [FreeIFF()](../Includes_and_Autodocs_2._guide/node01C5.html)  Frees the IFFHandle structure created with     |
 |                        AllocIFF().                                    |
 |             [OpenIFF()](../Includes_and_Autodocs_2._guide/node01CF.html)  Initialize an IFFHandle structure to read or   |
 |                        write an [IFF](../Libraries_Manual_guide/node0428.html) stream.                           |
 |            [CloseIFF()](../Includes_and_Autodocs_2._guide/node01BB.html)  Closes an IFF context.                         |
 |-----------------------------------------------------------------------|
 |             [InitIFF()](../Includes_and_Autodocs_2._guide/node01CA.html)  Initialize an [IFFHandle](../Libraries_Manual_guide/node042C.html) as a user-defined      |
 |                        stream.                                        |
 |        [InitIFFasDOS()](../Includes_and_Autodocs_2._guide/node01CC.html)  Initialize an IFFHandle as an AmigaDOS stream. |
 |       [InitIFFasClip()](../Includes_and_Autodocs_2._guide/node01CB.html)  Initialize an IFFHandle as a clipboard stream. |
 |-----------------------------------------------------------------------|
 |       [OpenClipboard()](../Includes_and_Autodocs_2._guide/node01CE.html)  Create a handle on a clipboard unit for        |
 |                        InitIFFasClip().                               |
 |            [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html)  Parse an [IFF](../Libraries_Manual_guide/node0428.html) file from an [IFFHandle](../Libraries_Manual_guide/node042C.html) stream.    |
 |      [ReadChunkBytes()](../Includes_and_Autodocs_2._guide/node01D6.html)  Read bytes from current chunk into a buffer.   |
 |    [ReadChunkRecords()](../Includes_and_Autodocs_2._guide/node01D7.html)  Read record elements from the current chunk    |
 |                        into a buffer.                                 |
 |           [StopChunk()](../Includes_and_Autodocs_2._guide/node01D9.html)  Declare a chunk that should cause ParseIFF()   |
 |                        to return.                                     |
 |        [CurrentChunk()](../Includes_and_Autodocs_2._guide/node01BE.html)  Get the context node for the current chunk.    |
 |           [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html)  Specify a property chunk to store.             |
 |            [FindProp()](../Includes_and_Autodocs_2._guide/node01C3.html)  Search for a stored property in a given        |
 |                        context.                                       |
 |     [CollectionChunk()](../Includes_and_Autodocs_2._guide/node01BC.html)  Declare a chunk type for collection.           |
 |      [FindCollection()](../Includes_and_Autodocs_2._guide/node01C1.html)  Get a pointer to the current list of           |
 |                        collection items.                              |
 |          [StopOnExit()](../Includes_and_Autodocs_2._guide/node01DB.html)  Declare a stop condition for exiting a chunk.  |
 |        [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html)  Add an entry handler to the IFFHandle context. |
 |         [ExitHandler()](../Includes_and_Autodocs_2._guide/node01C0.html)  Add an exit handler to the IFFHandle context.  |
 |-----------------------------------------------------------------------|
 |           [PushChunk()](../Includes_and_Autodocs_2._guide/node01D5.html)  Push a given context node onto the top of the  |
 |                        context stack.                                 |
 |            [PopChunk()](../Includes_and_Autodocs_2._guide/node01D2.html)  Pop the top context node off of the context    |
 |                        stack.                                         |
 |        [CurrentChunk()](../Includes_and_Autodocs_2._guide/node01BE.html)  Get the top context node for the current chunk.|
 |         [ParentChunk()](../Includes_and_Autodocs_2._guide/node01D0.html)  Get the nesting context node for a given chunk.|
 |-----------------------------------------------------------------------|
 |      [AllocLocalItem()](../Includes_and_Autodocs_2._guide/node01B9.html)  Create a [LocalContextItem](../Libraries_Manual_guide/node044A.html) (LCI) structure.     |
 |       [LocalItemData()](../Includes_and_Autodocs_2._guide/node01CD.html)  Returns a pointer to the user data of a        |
 |                        LocalContextItem (LCI).                        |
 |      [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html)  Insert a LocalContextItem (LCI).               |
 |  [StoreItemInContext()](../Includes_and_Autodocs_2._guide/node01DC.html)  Store a LocalContextItem in a given context    |
 |                        node.                                          |
 |     [FindPropContext()](../Includes_and_Autodocs_2._guide/node01C4.html)  Find the property context for the current      |
 |                        state.                                         |
 |       [FindLocalItem()](../Includes_and_Autodocs_2._guide/node01C2.html)  Return a LocalContextItem from the context     |
 |                        stack.                                         |
 |       [FreeLocalItem()](../Includes_and_Autodocs_2._guide/node01C6.html)  Free a LocalContextItem (LCI) created with     |
 |                        AllocLocalItem().                              |
 |   [SetLocalItemPurge()](../Includes_and_Autodocs_2._guide/node01D8.html)  Set purge vector for a local context item.     |
 |_______________________________________________________________________|


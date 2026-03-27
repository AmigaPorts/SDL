# 33 / / Custom Chunk Handlers / The Object Parameter


The object parameter supplied to [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html) and [ExitHandler()](../Includes_and_Autodocs_2._guide/node01C0.html) is a
pointer which will be passed to your handler when invoked.  This pointer
can be anything; the parser doesn't use it directly.  As an example, you
might pass the pointer to the [IFFHandle](../Libraries_Manual_guide/node042C.html).  This way, when your handler is
called, you'll be able to easily perform operations on the IFFHandle
within your handler.  Such code might appear as follows:


```c
    error = EntryHandler (iff, ID_ILBM, ID_BMHD, IFFSLI_ROOT, hook, iff);
```
And your handler would be declared as follows:


```c
    /* Registerized handler hook h_Entry using */
    /* SAS C registerized parameters           */
    LONG __asm MyHandler (register __a0 struct Hook      *hook,
                          register __a1 LONG             *cmd,
                          register __a2 struct IFFHandle *iff)

    /* Standard args handler hook h_SubEntry using */
    /* HookEntry.asm as Hook h_Entry               */
    LONG MyHandler ( struct Hook      *hook,
                     LONG             *cmd,
                     struct IFFHandle *iff )
```
From within your handler, you could then call [CurrentChunk()](../Libraries_Manual_guide/node0447.html),
[ReadChunkBytes()](../Libraries_Manual_guide/node043B.html), or nearly any other operation on the [IFFHandle](../Libraries_Manual_guide/node042C.html). Please
refer to the [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html) and [ExitHandler()](../Includes_and_Autodocs_2._guide/node01C0.html) Autodocs for additional
information on the use of chunk handlers.


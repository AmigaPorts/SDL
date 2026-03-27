---
title: 33 / / Custom Chunk Handlers / The Object Parameter
manual: libraries
chapter: libraries
section: 33-custom-chunk-handlers-the-object-parameter
functions: [CurrentChunk, EntryHandler, ExitHandler, ReadChunkBytes]
libraries: [iffparse.library]
---

# 33 / / Custom Chunk Handlers / The Object Parameter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The object parameter supplied to [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md) and [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md) is a
pointer which will be passed to your handler when invoked.  This pointer
can be anything; the parser doesn't use it directly.  As an example, you
might pass the pointer to the [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md).  This way, when your handler is
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
From within your handler, you could then call [CurrentChunk()](libraries/33-context-nodes-currentchunk.md),
[ReadChunkBytes()](libraries/33-parsing-reading-chunk-data.md), or nearly any other operation on the [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md). Please
refer to the [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md) and [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md) Autodocs for additional
information on the use of chunk handlers.

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)

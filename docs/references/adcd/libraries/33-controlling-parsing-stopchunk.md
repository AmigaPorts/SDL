---
title: 33 / / Controlling Parsing / StopChunk()
manual: libraries
chapter: libraries
section: 33-controlling-parsing-stopchunk
functions: [CurrentChunk, ParseIFF, ReadChunkBytes, ReadChunkRecords, StopChunk]
libraries: [iffparse.library]
---

# 33 / / Controlling Parsing / StopChunk()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can instruct the parser to stop when it encounters a specific [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md)
chunk by using the function [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md):


```c
    error = StopChunk (iff, ID_ILBM, ID_BODY);
```
When the parser encounters the requested chunk, parsing will stop, and
[ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) will return the value zero.  The stream will be positioned
ready to read the first data byte in the chunk.  You may then call
[ReadChunkBytes()](libraries/33-parsing-reading-chunk-data.md) or [ReadChunkRecords()](libraries/33-parsing-reading-chunk-data.md) to pull the data out of the chunk.

You may call [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md) any number of times for any number of different
chunk types.  If you wish to identify the chunk on which you've stopped,
you may call [CurrentChunk()](libraries/33-context-nodes-currentchunk.md) to get a pointer to the current [ContextNode](libraries/33-context-functions-context-nodes.md),
and examine the cn_Type and cn_ID fields.

Using [StopChunk()](autodocs-2.0/iffparse-library-stopchunk.md) for every chunk, you can parse [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) files in a manner
very similar to the way you're probably doing it now, using a state
machine.  However, this would be a terrible underuse of IFFParse.

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [ReadChunkRecords — iffparse.library](../autodocs/iffparse.library.md#readchunkrecords)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)

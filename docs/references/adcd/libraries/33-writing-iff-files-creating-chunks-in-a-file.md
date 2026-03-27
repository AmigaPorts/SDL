---
title: 33 / Writing IFF Files / Creating Chunks In a File
manual: libraries
chapter: libraries
section: 33-writing-iff-files-creating-chunks-in-a-file
functions: [PopChunk, PushChunk]
libraries: [iffparse.library]
---

# 33 / Writing IFF Files / Creating Chunks In a File

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Because the [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) specification has nesting and scoping rules, you can nest
chunks inside one another.  One instance is the [BMHD](libraries/33-form-ilbm-interpreting-ilbms.md) chunk, which is
commonly nested inside a [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md) chunk.  Thus, it is necessary for you to
inform IFFParse when you are starting and ending chunks.

 [PushChunk()](libraries/33-creating-chunks-in-a-file-pushchunk.md)    [PopChunk()](libraries/33-creating-chunks-in-a-file-popchunk.md) 

---

## See Also

- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

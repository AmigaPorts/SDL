---
title: 33 / Parsing / Reading Chunk Data
manual: libraries
chapter: libraries
section: 33-parsing-reading-chunk-data
functions: [CollectionChunk, FindCollection, FindProp, PropChunk, ReadChunkBytes, ReadChunkRecords]
libraries: [iffparse.library]
---

# 33 / Parsing / Reading Chunk Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To read data from a chunk, use the functions [ReadChunkBytes()](autodocs-2.0/iffparse-library-readchunkbytes.md) and
[ReadChunkRecords()](autodocs-2.0/iffparse-library-readchunkrecords.md).  Both calls truncate attempts to read past the end of
a chunk.  For odd-length chunks, the parser will skip over the pad bytes
for you.  Remember that for chunks which have been gathered using
[PropChunk()](libraries/33-controlling-parsing-propchunk-findprop.md) (or [CollectionChunk()](libraries/33-management-functions-collectionchunk-and-findcollection.md) ), you may directly reference the data
by using [FindProp()](libraries/33-controlling-parsing-propchunk-findprop.md) (or [FindCollection()](libraries/33-management-functions-collectionchunk-and-findcollection.md) ) to get a pointer to the data.
ReadChunkBytes() is commonly used when loading and decompressing bitmap
and sound sample data or sequentially reading in data chunks such as [FTXT](libraries/33-iffparse-library-iff-form-specifications.md)
[CHRS](libraries/33-iff-form-specifications-form-ftxt.md) text chunks.  See the code listing [ClipFTXT.c](libraries/lib-examples-clipftxt-c.md) for an example usage of
ReadChunkBytes().

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [FindCollection — iffparse.library](../autodocs/iffparse.library.md#findcollection)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [ReadChunkRecords — iffparse.library](../autodocs/iffparse.library.md#readchunkrecords)

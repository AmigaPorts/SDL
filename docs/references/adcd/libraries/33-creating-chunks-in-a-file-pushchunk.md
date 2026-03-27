---
title: 33 / / Creating Chunks In a File / PushChunk()
manual: libraries
chapter: libraries
section: 33-creating-chunks-in-a-file-pushchunk
functions: [PushChunk]
libraries: [iffparse.library]
---

# 33 / / Creating Chunks In a File / PushChunk()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To tell IFFParse you are about to begin writing a new chunk, you use the
function [PushChunk()](autodocs-2.0/iffparse-library-pushchunk.md):


```c
    error = PushChunk (iff, ID_ILBM, ID_BMHD,chunksize);
```
The chunk ID and size are written to the stream.  IFFParse will enforce
the chunk size you specified; attempts to write past the end of the chunk
will be truncated.  If, as a chunk size argument, you pass IFFSIZE_UNKNOWN,
the chunk will be expanded in size as you write data to it.

---

## See Also

- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

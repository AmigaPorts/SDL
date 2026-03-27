---
title: 33 / / Creating Chunks In a File / PopChunk()
manual: libraries
chapter: libraries
section: 33-creating-chunks-in-a-file-popchunk
functions: [PopChunk, PushChunk]
libraries: [iffparse.library]
---

# 33 / / Creating Chunks In a File / PopChunk()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you are through writing data to a chunk, you complete the write by
calling [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md):


```c
    error = PopChunk (iff);
```
If you wrote fewer bytes than you declared with [PushChunk()](libraries/33-creating-chunks-in-a-file-pushchunk.md), [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md)
will return an error.  If you specified IFFSIZE_UNKNOWN, PopChunk() will
seek backward on the stream and write the final size.  If you specified a
chunk size that was odd, PopChunk() will write the pad byte automatically.

[PushChunk()](libraries/33-creating-chunks-in-a-file-pushchunk.md) and [PopChunk()](autodocs-2.0/iffparse-library-popchunk.md) nest; every call to PushChunk() must have a
corresponding call to PopChunk().

---

## See Also

- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

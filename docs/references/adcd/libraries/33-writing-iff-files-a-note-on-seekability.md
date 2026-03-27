---
title: 33 / Writing IFF Files / A Note On Seekability
manual: libraries
chapter: libraries
section: 33-writing-iff-files-a-note-on-seekability
functions: [CloseIFF, PopChunk, PushChunk]
libraries: [iffparse.library]
---

# 33 / Writing IFF Files / A Note On Seekability

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As you can see from the above examples, IFFParse works best with a stream
that can seek randomly.  However, it is not possible to seek on some
streams (e.g., pipes).

IFFParse will read and write streams with limited or no seek capability.
In the case of reading, only forward-seek capability is desirable.
Failing this, IFFParse will fake forward seeks with a number of short
reads.

In the case of writing, if the stream lacks random seek capability,
IFFParse will buffer the entire contents of the file until you do the
final [PopChunk()](libraries/33-creating-chunks-in-a-file-popchunk.md), or when you [CloseIFF()](libraries/33-stream-management-termination.md) the handle.  At that time, the
entire stream will be written in one go.  This buffering happens whether
or not you specify all the chunk sizes to [PushChunk()](libraries/33-creating-chunks-in-a-file-pushchunk.md).


    About the Internal Buffering.
    -----------------------------
    The current implementation of this internal buffering could be
    more efficient.  Be aware that Amiga, Inc. reserves the right to alter
    this behavior of the parser, to improve performance or reduce memory
    requirements.  We mention this behavior on the off chance it is
    important to you.

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)

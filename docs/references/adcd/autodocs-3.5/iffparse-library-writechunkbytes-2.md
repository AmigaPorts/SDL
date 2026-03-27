---
title: iffparse.library/WriteChunkBytes
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-writechunkbytes-2
functions: [PopChunk, PushChunk, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.library/WriteChunkBytes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WriteChunkBytes -- write data from a buffer into the current chunk.
	                   (V36)

   SYNOPSIS
	error = WriteChunkBytes(iff, buf, numBytes);
	D0                      A0   A1   D0

	[LONG](autodocs-3.5/include-exec-types-h.md) WriteChunkBytes(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Writes "numBytes" bytes from the specified buffer into the current
	chunk. If the current chunk was pushed with IFFSIZE_UNKNOWN, the size
	of the chunk gets increased by the size of the buffer written. If
	the size was specified for this chunk, attempts to write past the end
	of the chunk will be truncated.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	buf - pointer to buffer area with bytes to be written.
	numBytes - number of bytes to write.

   RESULT
	error - (positive) number of bytes written if successful or a
		(negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PushChunk()](autodocs-3.5/iffparse-library-pushchunk-2.md), [PopChunk()](autodocs-3.5/iffparse-library-popchunk-2.md), [WriteChunkRecords()](autodocs-3.5/iffparse-library-writechunkrecords-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)

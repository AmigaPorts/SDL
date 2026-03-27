---
title: iffparse.library/ReadChunkBytes
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-readchunkbytes-2
functions: [ParseIFF, ReadChunkRecords, WriteChunkBytes]
libraries: [iffparse.library]
---

# iffparse.library/ReadChunkBytes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadChunkBytes -- read bytes from the current chunk into a buffer.
	                  (V36)

   SYNOPSIS
	actual = ReadChunkBytes(iff, buf, numBytes);
	D0                      A0   A1   D0

	[LONG](autodocs-3.5/include-exec-types-h.md) ReadChunkBytes(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md) buf, LONG);

   FUNCTION
	Reads the [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) stream into the buffer for the specified number
	of bytes. Reads are limited to the size of the current chunk and
	attempts to read past the end of the chunk will truncate. This
	function returns positive number of bytes read or a negative error
	code.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	buf - pointer to buffer area to receive data.
	numBytes - number of bytes to read.

   RESULT
	actual - (positive) number of bytes read if successful or a
		 (negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[ReadChunkRecords()](autodocs-3.5/iffparse-library-readchunkrecords-2.md), [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md), [WriteChunkBytes()](autodocs-3.5/iffparse-library-writechunkbytes-2.md),
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [ReadChunkRecords — iffparse.library](../autodocs/iffparse.library.md#readchunkrecords)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)

---
title: iffparse.library/ReadChunkRecords
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-readchunkrecords-2
functions: [ParseIFF, ReadChunkBytes, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.library/ReadChunkRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadChunkRecords -- read record elements from the current chunk into
			    a buffer. (V36)

   SYNOPSIS
	actual = ReadChunkRecords(iff, buf, bytesPerRecord, numRecords);
	D0                        A0   A1   D0              D1

	[LONG](autodocs-3.5/include-exec-types-h.md) ReadChunkRecords(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Reads records from the current chunk into buffer. Truncates attempts
	to read past end of chunk (only whole records are read; remaining
	bytes that are not of a whole record size are left unread and
	available for [ReadChunkBytes()](autodocs-3.5/iffparse-library-readchunkbytes-2.md)).

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	buf - pointer to buffer area to receive data.
	bytesPerRecord	- size of data records to read.
	numRecords - number of data records to read.

   RESULT
	actual - (positive) number of whole records read if successful or a
		 (negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[ReadChunkBytes()](autodocs-3.5/iffparse-library-readchunkbytes-2.md), [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md), [WriteChunkRecords()](autodocs-3.5/iffparse-library-writechunkrecords-2.md),
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)

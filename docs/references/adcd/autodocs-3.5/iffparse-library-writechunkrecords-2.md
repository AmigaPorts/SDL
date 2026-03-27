---
title: iffparse.library/WriteChunkRecords
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-writechunkrecords-2
functions: [ReadChunkBytes, WriteChunkBytes]
libraries: [iffparse.library]
---

# iffparse.library/WriteChunkRecords

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WriteChunkRecords -- write records from a buffer to the current
			     chunk. (V36)

   SYNOPSIS
	error = WriteChunkRecords(iff, buf, recsize, numrec);
	D0                        A0   A1   D0       D1

	[LONG](autodocs-3.5/include-exec-types-h.md) WriteChunkRecords(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Writes record elements from the buffer into the top chunk. This
	function operates much like [ReadChunkBytes()](autodocs-3.5/iffparse-library-readchunkbytes-2.md).

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	buf - pointer to buffer area containing data.
	recsize	- size of data records to write.
	numrec - number of data records to write.

   RESULT
	error - (positive) number of whole records written if successful
		or a (negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[WriteChunkBytes()](autodocs-3.5/iffparse-library-writechunkbytes-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [ReadChunkBytes — iffparse.library](../autodocs/iffparse.library.md#readchunkbytes)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)

---
title: iffparse.library/PushChunk
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-pushchunk-2
functions: [PopChunk, WriteChunkBytes, WriteChunkRecords]
libraries: [iffparse.library]
---

# iffparse.library/PushChunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PushChunk -- push a new context node on the context stack. (V36)

   SYNOPSIS
	error = PushChunk(iff, type, id, size);
	D0                A0   D0    D1  D2

	[LONG](autodocs-3.5/include-exec-types-h.md) PushChunk(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

   FUNCTION
	Pushes a new context node on the context stack by reading it from the
	stream if this is a read file, or by creating it from the passed
	parameters if this is a write file. Normally this function is only
	called in write mode, where the type and id codes specify the new
	chunk to create. If this is a leaf chunk, i.e. a local chunk inside
	a FORM or PROP chunk, then the type argument is ignored. If the size
	is specified then the chunk writing functions will enforce this size.
	If the size is given as IFFSIZE_UNKNOWN, the chunk will expand to
	accommodate whatever is written into it.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	type - chunk type specifier (ex. ILBM) (ignored for read mode or
	       leaf chunks).
	id - chunk id specifier (ex. CMAP) (ignored for read mode).
	size - size of the chunk to create or IFFSIZE_UNKNOWN (ignored for
	       read mode).

   RESULT
	error - 0 if successful or an IFFERR_#? error code if not unsuccessful.

   SEE ALSO
	[PopChunk()](autodocs-3.5/iffparse-library-popchunk-2.md), [WriteChunkRecords()](autodocs-3.5/iffparse-library-writechunkrecords-2.md), [WriteChunkBytes()](autodocs-3.5/iffparse-library-writechunkbytes-2.md),
	[<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)

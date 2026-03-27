# iffparse.library/PushChunk



   NAME
	PushChunk -- push a new context node on the context stack. (V36)

   SYNOPSIS
	error = PushChunk(iff, type, id, size);
	D0                A0   D0    D1  D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PushChunk(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

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
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	type - chunk type specifier (ex. ILBM) (ignored for read mode or
	       leaf chunks).
	id - chunk id specifier (ex. CMAP) (ignored for read mode).
	size - size of the chunk to create or IFFSIZE_UNKNOWN (ignored for
	       read mode).

   RESULT
	error - 0 if successful or an IFFERR_#? error code if not unsuccessful.

   SEE ALSO
	[PopChunk()](../Includes_and_Autodocs_3._guide/node0373.html), [WriteChunkRecords()](../Includes_and_Autodocs_3._guide/node0380.html), [WriteChunkBytes()](../Includes_and_Autodocs_3._guide/node037F.html),
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


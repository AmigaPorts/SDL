# iffparse.library/WriteChunkBytes



   NAME
	WriteChunkBytes -- write data from a buffer into the current chunk.
	                   (V36)

   SYNOPSIS
	error = WriteChunkBytes(iff, buf, numBytes);
	D0                      A0   A1   D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) WriteChunkBytes(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), LONG);

   FUNCTION
	Writes "numBytes" bytes from the specified buffer into the current
	chunk. If the current chunk was pushed with IFFSIZE_UNKNOWN, the size
	of the chunk gets increased by the size of the buffer written. If
	the size was specified for this chunk, attempts to write past the end
	of the chunk will be truncated.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	buf - pointer to buffer area with bytes to be written.
	numBytes - number of bytes to write.

   RESULT
	error - (positive) number of bytes written if successful or a
		(negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[PushChunk()](../Includes_and_Autodocs_3._guide/node0376.html), [PopChunk()](../Includes_and_Autodocs_3._guide/node0373.html), [WriteChunkRecords()](../Includes_and_Autodocs_3._guide/node0380.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


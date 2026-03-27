# iffparse.library/ReadChunkBytes



   NAME
	ReadChunkBytes -- read bytes from the current chunk into a buffer.
	                  (V36)

   SYNOPSIS
	actual = ReadChunkBytes(iff, buf, numBytes);
	D0                      A0   A1   D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ReadChunkBytes(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) buf, LONG);

   FUNCTION
	Reads the [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) stream into the buffer for the specified number
	of bytes. Reads are limited to the size of the current chunk and
	attempts to read past the end of the chunk will truncate. This
	function returns positive number of bytes read or a negative error
	code.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	buf - pointer to buffer area to receive data.
	numBytes - number of bytes to read.

   RESULT
	actual - (positive) number of bytes read if successful or a
		 (negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[ReadChunkRecords()](../Includes_and_Autodocs_3._guide/node0378.html), [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html), [WriteChunkBytes()](../Includes_and_Autodocs_3._guide/node037F.html),
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


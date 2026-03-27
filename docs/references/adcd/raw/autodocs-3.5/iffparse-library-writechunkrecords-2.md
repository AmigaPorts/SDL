# iffparse.library/WriteChunkRecords



   NAME
	WriteChunkRecords -- write records from a buffer to the current
			     chunk. (V36)

   SYNOPSIS
	error = WriteChunkRecords(iff, buf, recsize, numrec);
	D0                        A0   A1   D0       D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) WriteChunkRecords(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Writes record elements from the buffer into the top chunk. This
	function operates much like [ReadChunkBytes()](../Includes_and_Autodocs_3._guide/node0377.html).

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	buf - pointer to buffer area containing data.
	recsize	- size of data records to write.
	numrec - number of data records to write.

   RESULT
	error - (positive) number of whole records written if successful
		or a (negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[WriteChunkBytes()](../Includes_and_Autodocs_3._guide/node037F.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


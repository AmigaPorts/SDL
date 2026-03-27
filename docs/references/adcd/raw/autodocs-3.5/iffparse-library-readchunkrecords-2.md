# iffparse.library/ReadChunkRecords



   NAME
	ReadChunkRecords -- read record elements from the current chunk into
			    a buffer. (V36)

   SYNOPSIS
	actual = ReadChunkRecords(iff, buf, bytesPerRecord, numRecords);
	D0                        A0   A1   D0              D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ReadChunkRecords(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Reads records from the current chunk into buffer. Truncates attempts
	to read past end of chunk (only whole records are read; remaining
	bytes that are not of a whole record size are left unread and
	available for [ReadChunkBytes()](../Includes_and_Autodocs_3._guide/node0377.html)).

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	buf - pointer to buffer area to receive data.
	bytesPerRecord	- size of data records to read.
	numRecords - number of data records to read.

   RESULT
	actual - (positive) number of whole records read if successful or a
		 (negative) IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[ReadChunkBytes()](../Includes_and_Autodocs_3._guide/node0377.html), [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html), [WriteChunkRecords()](../Includes_and_Autodocs_3._guide/node0380.html),
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)


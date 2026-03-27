# dos.library/Write



    NAME
	Write -- Write bytes of data to a file

    SYNOPSIS
	returnedLength =  Write( file, buffer, length )
	D0			 D1    D2      D3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) Write (BPTR, void *, LONG)

    FUNCTION
	Write() writes bytes of data to the opened file 'file'. 'length'
	indicates the length of data to be transferred; 'buffer' is a
	pointer to the buffer. The value returned is the length of
	information actually written. So, when 'length' is greater than
	zero, the value of 'length' is the number of characters written.
	Errors are indicated by a value of -1.

	Note: this is an unbuffered routine (the request is passed directly
	to the filesystem.)  Buffered I/O is more efficient for small
	reads and writes; see [FPutC()](../Includes_and_Autodocs_3._guide/node016C.html).

    INPUTS
	file - BCPL pointer to a file handle
	buffer - pointer to the buffer
	length - integer

    RESULTS
	returnedLength - integer

    SEE ALSO
	[Read()](../Includes_and_Autodocs_3._guide/node01A0.html), [Seek()](../Includes_and_Autodocs_3._guide/node01AD.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html), [Close()](../Includes_and_Autodocs_3._guide/node0149.html), [FPutC](../Includes_and_Autodocs_3._guide/node016C.html)


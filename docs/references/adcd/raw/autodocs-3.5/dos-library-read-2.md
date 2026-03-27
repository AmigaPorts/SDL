# dos.library/Read



    NAME
	Read -- Read bytes of data from a file

    SYNOPSIS
	actualLength = Read( file, buffer, length )
	D0		     D1    D2	   D3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) Read(BPTR, void *, LONG)

    FUNCTION
	Data can be copied using a combination of Read() and [Write()](../Includes_and_Autodocs_3._guide/node01D1.html).
	Read() reads bytes of information from an opened file (represented
	here by the argument 'file') into the buffer given. The argument
	'length' is the length of the buffer given.

	The value returned is the length of the information actually read.
	So, when 'actualLength' is greater than zero, the value of
	'actualLength' is the the number of characters read. Usually Read
	will try to fill up your buffer before returning. A value of zero
	means that end-of-file has been reached. Errors are indicated by a
	value of -1.

	Note: this is an unbuffered routine (the request is passed directly
	to the filesystem.)  Buffered I/O is more efficient for small
	reads and writes; see [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html).

    INPUTS
	file - BCPL pointer to a file handle
	buffer - pointer to buffer
	length - integer

    RESULTS
	actualLength - integer

    SEE ALSO
	[Open()](../Includes_and_Autodocs_3._guide/node0196.html), [Close()](../Includes_and_Autodocs_3._guide/node0149.html), [Write()](../Includes_and_Autodocs_3._guide/node01D1.html), [Seek()](../Includes_and_Autodocs_3._guide/node01AD.html), [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html)


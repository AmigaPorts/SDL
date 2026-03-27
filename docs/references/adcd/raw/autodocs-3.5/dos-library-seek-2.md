# dos.library/Seek



    NAME
	Seek -- Set the current position for reading and writing

    SYNOPSIS
	oldPosition = Seek( file, position, mode )
	D0		    D1	  D2	    D3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) Seek(BPTR, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG)

    FUNCTION
	Seek() sets the read/write cursor for the file 'file' to the
	position 'position'. This position is used by both [Read()](../Includes_and_Autodocs_3._guide/node01A0.html) and
	[Write()](../Includes_and_Autodocs_3._guide/node01D1.html) as a place to start reading or writing. The result is the
	current absolute position in the file, or -1 if an error occurs, in
	which case [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) can be used to find more information. 'mode' can
	be OFFSET_BEGINNING, OFFSET_CURRENT or OFFSET_END. It is used to
	specify the relative start position. For example, 20 from current
	is a position 20 bytes forward from current, -20 is 20 bytes back
	from current.

	So that to find out where you are, seek zero from current. The end
	of the file is a Seek() positioned by zero from end. You cannot
	Seek() beyond the end of a file.

    INPUTS
	file - BCPL pointer to a file handle
	position - integer
	mode - integer

    RESULTS
	oldPosition - integer

    BUGS
	The V36 and V37 ROM filesystem (and V36/V37 l:fastfilesystem)
	returns the current position instead of -1 on an error.  It sets
	[IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) to 0 on success, and an error code on an error.  This bug
	was fixed in the V39 filesystem.

    SEE ALSO
	[Read()](../Includes_and_Autodocs_3._guide/node01A0.html), [Write()](../Includes_and_Autodocs_3._guide/node01D1.html), [SetFileSize()](../Includes_and_Autodocs_3._guide/node01B6.html)

